<?php
/**
 * @file
 * Contains \graphicsmagick\ToolkitInfo.
 */

declare(strict_types=1);

namespace graphicsmagick;

/**
 * Retrieves information about the GraphicsMagick toolkit.
 */
class ToolkitInfo implements ToolkitInfoInterface {

  /**
   * The supported extensions.
   *
   * @var string[]
   */
  protected const EXTENSIONS = array(
    'BMP' => 'bmp',
    'CIN' => 'cin',
    'DCX' => 'dcx',
    'DPX' => 'dpx',
    'EPI' => 'epi',
    'EPSF' => 'eps',
    'EPSI' => 'eps',
    'EPT' => 'eps',
    'EPT2' => 'eps',
    'EPT3' => 'eps',
    'EPS' => 'eps',
    'FITS' => 'fits',
    'GIF87' => 'gif',
    'GIF' => 'gif',
    'ICB' => 'icb',
    'JPEG' => 'jpeg',
    'JPG' => 'jpg',
    'PAM' => 'pam',
    'PBM' => 'pbm',
    'EPDF' => 'pdf',
    'PDF' => 'pdf',
    'PGM' => 'pgm',
    'PNG00' => 'png',
    'PNG24' => 'png',
    'PNG32' => 'png',
    'PNG48' => 'png',
    'PNG' => 'png',
    'PNM' => 'pnm',
    'PPM' => 'ppm',
    'PS' => 'ps',
    'SGI' => 'sgi',
    'TGA' => 'tga',
    'PTIF' => 'tif',
    'BIGTIFF' => 'tif',
    'TIFF' => 'tiff',
    'VDA' => 'vda',
    'VST' => 'vst',
    'WBMP' => 'wbmp',
    'WEBP' => 'webp',
    'XBM' => 'xbm',
    'PICON' => 'xpm',
  );

  /**
   * The MIME types for the supported formats.
   *
   * @var string[]
   */
  protected const MIME_TYPES = array(
    'BIGTIFF' => 'image/tiff',
    'BMP' => 'image/x-ms-bmp',
    'CIN' => 'image/cineon',
    'DCX' => 'image/x-pc-paintbrush',
    'DPX' => 'image/x-dpx',
    'EPDF' => 'application/pdf',
    'EPI' => 'application/postscript',
    'EPS' => 'application/postscript',
    'EPSF' => 'application/postscript',
    'EPSI' => 'application/postscript',
    'EPT' => 'image/eps',
    'EPT2' => 'image/eps',
    'EPT3' => 'image/eps',
    'FITS' => 'image/fits',
    'GIF' => 'image/gif',
    'GIF87' => 'image/gif',
    'ICB' => 'image/x-tga',
    'JPEG' => 'image/jpeg',
    'JPG' => 'image/jpeg',
    'PAM' => 'image/x-portable-pixmap',
    'PBM' => 'image/x-portable-pixmap',
    'PDF' => 'application/pdf',
    'PGM' => 'image/x-portable-greymap',
    'PICON' => 'image/x-xpmi',
    'PNG' => 'image/png',
    'PNG00' => 'image/png',
    'PNG24' => 'image/png',
    'PNG32' => 'image/png',
    'PNG48' => 'image/png',
    'PNM' => 'image/x-portable-pixmap',
    'PPM' => 'image/x-portable-pixmap',
    'PS' => 'application/postscript',
    'PTIF' => 'image/tiff',
    'SGI' => 'imagine/sgi',
    'TGA' => 'image/x-tga',
    'TIFF' => 'image/tiff',
    'VDA' => 'image/x-tga',
    'VST' => 'image/x-tga',
    'WBMP' => 'image/vnd.wap.wbmp',
    'WEBP' => 'image/webp',
    'XBM' => 'image/x‑xbitmap',
  );

  /**
   * An instance of the Gmagick class.
   *
   * @var \Gmagick
   */
  protected \Gmagick $gmagick;

  public function __construct() {
    try {
      $this->gmagick = new \Gmagick();
    }
    catch (\GmagickException | \Error $e) {
      throw new \RuntimeException('Unable to create an instance of the Gmagick class.', 0, $e);
    }
  }

  /**
   * {@inheritdoc}
   */
  public function isAvailable(): bool {
    if (isset($this->gmagick)) {
      // Verify the undocumented methods used by the toolkit are implemented.
      $missing_methods = FALSE;
      $missing_methods |= !method_exists($this->gmagick, 'getNumberImages');
      $missing_methods |= !method_exists($this->gmagick, 'coalesceImages');
      $missing_methods |= !method_exists($this->gmagick, 'deconstructImages');

      return !$missing_methods;
    }

    return FALSE;
  }

  /**
   * @inheritdoc}
   */
  public function getQuantumLevel(): int {
    $quantum_level = 8;

    if (isset($this->gmagick)) {
      try {
        $quantum_level = $this->gmagick->getQuantumDepth()['quantumDepthLong'];
      }
      catch (\GmagickException) {
        // As getting the quantum dept value failed, assume its value is 8.
      }
    }

    return $quantum_level;
  }

  /**
   * @inheritdoc}
   */
  public static function noiseOptions(): array {
    return array(
      'uniform' => t('Uniform'),
      'gaussian' => t('Gaussian'),
      'multiplicative' => t('Multiplicative Gaussian'),
      'impulse' => t('Impulse'),
      'laplacian' => t('Laplacian'),
      'poisson' => t('Poisson'),
    );
  }

  /**
   * Converts a noise generation option to its value.
   *
   * @param string $option
   *   The option for noise generation.
   *
   * @return int
   *   The value for the noise generation option, or \Gmagick::NOISE_UNIFORM if
   *   the option is not recognized.
   */
  public static function noiseOptionToValue(string $option): int {
    $options = array(
      'uniform' => \Gmagick::NOISE_UNIFORM,
      'gaussian' => \Gmagick::NOISE_GAUSSIAN,
      'multiplicative' => \Gmagick::NOISE_MULTIPLICATIVEGAUSSIAN,
      'impulse' => \Gmagick::NOISE_IMPULSE,
      'laplacian' => \Gmagick::NOISE_LAPLACIAN,
      'poisson' => \Gmagick::NOISE_POISSON,
    );

    if (isset($options[$option])) {
      return $options[$option];
    }

    return \Gmagick::NOISE_UNIFORM;
  }

  /**
   * Returns the supported extensions for the GraphicsMagick toolkit.
   *
   * The following list doesn't include all the file types recognized by the
   * GraphicsMagick library; it includes most of the image types, excluding
   * the raw images and those images the Gmagick class is not able to write.
   *
   * @return array
   *   The supported extensions.
   */
  public function supportedExtensions(): array {
    $supported_extensions = array();

    if (isset($this->gmagick)) {
      try {
        foreach ($this->gmagick->queryFormats() as $format) {
          if (isset($extensions[$format])) {
            $supported_extensions[] = $extensions[$format];
          }
        }
      }
      catch (\GmagickException) {
        // Ignore the thrown exception.
      }
    }

    return array_unique($supported_extensions);
  }

  /**
   * Returns the file extension for a given Gmagick format.
   *
   * @param string $format
   *   The Gmagick format.
   *
   * @return string
   *   The file extension associated with the given format, or an empty string
   *   if the format is not supported by the GraphicsMagick toolkit.
   */
  public function extensionFromFormat(string $format): string {
    if (isset(self::EXTENSIONS[$format])) {
      if (isset($this->gmagick)) {
        try {
          $formats = $this->gmagick->queryFormats();
          if (in_array($format, $formats)) {
            return self::EXTENSIONS[$format];
          }
        }
        catch (\GmagickException) {
          // Return an empty string, which means the format is not supported.
          return '';
        }
      }
    }

    return '';
  }

  /**
   * Returns the MIME type associated with a given Gmagick format.
   *
   * @param string $format
   *   The Gmagick format.
   *
   * @return string
   *   The MIME type associated with the given format, or an empty string if the
   *   format is not supported by the GraphicsMagick toolkit.
   */
  public function mimeTypeFromFormat(string $format): string {
    if (isset(self::MIME_TYPES[$format])) {
      if (isset($this->gmagick)) {
        try {
          $formats = $this->gmagick->queryFormats();
          if (in_array($format, $formats)) {
            return self::MIME_TYPES[$format];
          }
        }
        catch (\GmagickException) {
          // Return an empty string, which means the format is not supported.
          return '';
        }
      }
    }

    return '';
  }

}
