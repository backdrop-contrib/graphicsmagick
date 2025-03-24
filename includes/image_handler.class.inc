<?php
/**
 * @file
 * Contains ImageHandler.
 */

declare(strict_types=1);


class ImageHandler {

  protected ?Gmagick $gmagick = NULL;

  /**
   * Retrieves the absolute local file path.
   *
   * @param string $filename
   *   The file path.
   *
   * @return string
   *   The absolute file path.
   *
   * @throws FileException
   *   The local filepath cannot be determined.
   */
  protected static function getRealPath(string $filename): string {
    if (($realpath = backdrop_realpath($filename)) === FALSE) {
      throw new FileException("The absolute local filepath for $filename cannot be determined.");
    }

    return $realpath;
  }

  /**
   * Gets the absolute local path.
   *
   * @param string $source
   *   The file for which the absolute local path is requested.
   *
   * @return string
   *   The absolute local path, if the file is local, or an empty string.
   */
  protected static function localFile(string $source): string {
    $scheme = file_uri_scheme($source);

    if ($scheme && file_stream_wrapper_valid_scheme($scheme)) {
      $local_stream_wrappers = file_get_stream_wrappers(STREAM_WRAPPERS_LOCAL);

      if (isset($local_stream_wrappers[$scheme])) {
        return self::getRealPath($source);
      }
    }

    return '';
  }

  /**
   * Copies the file in a temporary local file.
   *
   * @param string $source
   *   The file to copy.
   *
   * @return string
   *   The absolute filepath of the temporary file.
   *
   * @throws FileWriteException
   *   The temporary file could not be created.
   */
  protected static function copyToTemporary(string $source): string {
    if (($destination = backdrop_tempnam('temporary://', 'graphicsmagick_')) === FALSE) {
      throw new FileWriteException("The temporary file could not be created.");
    }

    // Copy the remote file to the temporary local file.
    return file_unmanaged_copy($source, $destination, FILE_EXISTS_REPLACE);
  }

  public static function create(object $image): ?self  {
    if (isset($image->handler) && !is_a($image->handler, self::class)) {
      throw new InvalidArgumentException('The image handler must be an instance of ' . self::class . '.');
    }

    if (!isset($image->handler)) {
      $image->handler = NULL;

      if (!isset($image->source) || !is_string($image->source)) {
        throw new InvalidArgumentException('The image source must be a string.');
      }

      try {
        if (!$file = self::localFile($image->source)) {
          $file = self::copyToTemporary($image->source);
        }

        $handler = new static($file);
        $image->handler = $handler;

        return $handler;
      }
      catch (FileException | RuntimeException) {
        $image->handler = NULL;
      }
    }

    return $image->handler;
  }

  protected function __construct(string $file) {
    try {
      $this->gmagick = new Gmagick($file);
    }
    catch (GmagickException $e) {
      throw new RuntimeException('Unable to create an instance of the Gmagick class.', $e->getCode(), $e);
    }
  }

  public function __destruct() {
    $this->gmagick = NULL;
  }

  /**
   * Applies a GraphicsMagick operation to the image.
   *
   * The given callback will be called with a Gmagick instance as the first
   * argument and an array of settings as the second argument. The callback must
   * operate directly on the Gmagick instance.
   *
   * If the operation type is "single_frame", the callback will be called once.
   * If the operation type is "multiple_frames", the callback will be called
   * once for each frame in the Gmagick instance.
   *
   * @param \Closure $callback
   *   A callback that will be called with the Gmagick instance and the settings.
   * @param string $operation_type
   *   The operation type, either "single_frame" or "multiple_frames".
   * @param ?array $arguments
   *   An array of settings to apply to the image.
   *
   * @return bool
   *   TRUE if the operation was successful, FALSE otherwise.
   */
  public function applyOperation(Closure $callback, string $operation_type, ?array $arguments = NULL): bool {
    $gmagick = clone $this->gmagick;

    try {
      if (!method_exists($gmagick, 'getNumberImages') || !method_exists($gmagick, 'coalesceImages')) {
        // The required methods are not implemented by Gmagick. Return FALSE.
        return FALSE;
      }

      $images_count = match ($operation_type) {
        'multiple_frames' => $gmagick->getNumberImages(),
        'single_frame' => 1,
        default => -1
      };

      if ($images_count > 1) {
        $gmagick = $gmagick->coalesceImages();

        do {
          $callback($gmagick, $arguments ?? []);
        }
        while ($gmagick->nextImage());

        $gmagick = $gmagick->deconstructImages();
      }
      else {
        $callback($gmagick, $arguments ?? []);
      }
    }
    catch (GmagickException | Error) {
      try {
        $gmagick->destroy();
      }
      catch (GmagickException) {
        // Ignore the exception, as there is nothing that can be done when
        // destroying a Gmagick instance fails.
      }

      return FALSE;
    }

    $this->gmagick = $gmagick;

    return TRUE;
  }

  /**
   * Sets the compression quality for the current image.
   *
   * @param int $quality
   *   The desired compression quality level.
   */
  public function compressionQuality(int $quality): void {
    try {
      $this->gmagick->setCompressionQuality($quality);
    }
    catch (GmagickException | Error) {
      // Ignore exception.
    }
  }

  /**
   * Retrieves the format of the current image.
   *
   * This method returns the format of the image as a string. If an error
   * occurs while attempting to retrieve the format, an empty string is returned.
   *
   * @return string
   *   The format of the image, or an empty string on failure.
   */
  public function imageFormat(): string {
    try {
      return $this->gmagick->getImageFormat();
    }
    catch (GmagickException | Error) {
      return '';
    }
  }

  /**
   * Saves the current image to the specified destination.
   *
   * This method writes the image, or all frames of an image if applicable,
   * to the given destination path. It checks if the Gmagick instance supports
   * multiple frames and writes them accordingly.
   *
   * @param string $destination
   *   The file path where the image should be saved.
   *
   * @return bool
   *   TRUE if the image was successfully saved, FALSE otherwise.
   */
  public function save(string $destination): bool {
    try {
      if (method_exists($this->gmagick, 'getNumberImages')) {
        $all_frames = $this->gmagick->getNumberImages() > 1;
      }
      else {
        $all_frames = FALSE;
      }

      if (!$local_destination = self::localFile($destination)) {
        $permanent_destination = $destination;
        $destination = self::copyToTemporary($destination);
      }
      else {
        $destination = $local_destination;
      }

      $this->gmagick->writeImage($destination, $all_frames);

      if (isset($permanent_destination)) {
        file_unmanaged_move($destination, $permanent_destination);
      }

      return TRUE;
    }
    catch (Error | FileException | GmagickException) {
      return FALSE;
    }
  }

}
