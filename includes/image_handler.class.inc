<?php
/**
 * @file
 * Contains ImageHandler.
 */

declare(strict_types=1);


class ImageHandler {

  protected ?Gmagick $gmagick = NULL;

  public static function create(object $image): ?self  {
    if (isset($image->handler) && !is_a($image->handler, self::class)) {
      throw new InvalidArgumentException('The image handler must be an instance of ' . self::class . '.');
    }

    if (isset($image->handler)) {
      return $image->handler;
    }

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
    catch (FileException | GmagickException) {
      return NULL;
    }
  }

  protected function __construct(string $file) {
    $this->gmagick = new Gmagick($file);
  }

  public function __destruct() {
    $this->gmagick = NULL;
  }

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

}
