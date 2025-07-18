<?php
/**
 * @file
 * Contains ImageHandler.
 */

declare(strict_types=1);


class ImageHandler {

  protected ?Gmagick $gmagick = NULL;

  /**
   * Gets the absolute local path.
   *
   * @param string $source
   *   The file for which the absolute local path is requested.
   *
   * @return string
   *   The absolute local path, if the file is local.
   *
   * @throws FileException
   *   The file is not local or the local path could not be retrieved.
   */
  protected static function localFile(string $source): string {
    $scheme = file_uri_scheme($source);

    if ($scheme && file_stream_wrapper_valid_scheme($scheme)) {
      $local_stream_wrappers = file_get_stream_wrappers(STREAM_WRAPPERS_LOCAL);

      if (!isset($local_stream_wrappers[$scheme])) {
        throw new FileException("$source is not a local file.");
      }

      $class = file_stream_wrapper_get_class($scheme);

      if (!class_exists($class)) {
        throw new FileException("Cannot retrieve the local path for $source.");
      }

      /* @var BackdropStreamWrapperInterface $instance */
      $instance = new $class();
      $instance->setUri($source);

      return $instance->realpath();
    }
    else {
      throw new FileException("Cannot retrieve the local path for $source.");
    }
  }

  /**
   * Copies a file from source to destination.
   *
   * @param string $source
   *   The source file to copy from.
   * @param string $destination
   *   The destination file to copy to.
   */
  protected static function copyFile(string $source, string $destination): void {
    if (!@file_exists($source)) {
      throw new FileReadException("The source file $source does not exist.");
    }

  }

  /**
   * Creates a temporary file that can be used for image processing.
   *
   * @return string
   *   The absolute filepath of the temporary file.
   *
   * @throws FileWriteException
   *   The temporary file could not be created.
   */
  protected static function createTemporary(): string {
    if (($destination = backdrop_tempnam('temporary://', 'graphicsmagick_')) === FALSE) {
      throw new FileWriteException("The temporary file could not be created.");
    }

    return $destination;
  }

  /**
   * Creates the image handler.
   *
   * @param object $image
   *   An image object. This call will set the $image->handler value.
   *
   * @return $this|null
   *   The image handler or NULL if the image could not be loaded.
   *
   * @throws InvalidArgumentException
   *   $image->handler is not NULL nor an instance of the current class.
   *   $image->source is not a string.
   */
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
        try {
          $file = self::localFile($image->source);
        }
        catch (FileException) {
          $file = self::createTemporary();
          self::copyFile($image->source, $file);
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
    try {
      $this->gmagick->destroy();
    }
    catch (GmagickException | Error) {
      // Ignore exception.
    }

    $this->gmagick = NULL;
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
   * This method returns the format of the image as a string. If an error occurs
   * while attempting to retrieve the format, an empty string is returned.
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
   * Retrieves the height of the current image.
   *
   * @return int
   *   The height of the image, or 0 on failure.
   */
  public function imageHeight(): int {
    try {
      return $this->gmagick->getImageHeight();
    }
    catch (GmagickException | Error) {
      return 0;
    }
  }

  /**
   * Retrieves the width of the current image.
   *
   * @return int
   *   The width of the image, or 0 on failure.
   */
  public function imageWidth(): int {
    try {
      return $this->gmagick->getImageWidth();
    }
    catch (GmagickException | Error) {
      return 0;
    }
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
   *   A callback that will be called with the Gmagick instance and the
   *   settings.
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

      try {
        $destination = self::localFile($destination);
      }
      catch (FileException) {
        $permanent_destination = $destination;
        $destination = self::createTemporary();
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
