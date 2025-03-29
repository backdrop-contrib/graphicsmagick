<?php
/**
 * @file
 * Contains ToolkitInfo.
 */

declare(strict_types=1);

/**
 * Retrieves information about the GraphicsMagick toolkit.
 */
class ToolkitInfo implements ToolkitInfoInterface {

  /**
   * The supported extensions.
   *
   * @var string[]
   */
  protected const array EXTENSIONS = array(
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
  protected const array MIME_TYPES = array(
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
   * @var Gmagick
   */
  protected Gmagick $gmagick;

  public function __construct() {
    try {
      $this->gmagick = new Gmagick();
    }
    catch (GmagickException | Error $e) {
      throw new RuntimeException('Unable to create an instance of the Gmagick class.', $e->getCode(), $e);
    }
  }

  /**
   * {@inheritdoc}
   */
  public function isAvailable(): bool {
    return isset($this->gmagick) &&
      method_exists($this->gmagick, 'getNumberImages') &&
      method_exists($this->gmagick, 'coalesceImages') &&
      method_exists($this->gmagick, 'deconstructImages');
  }

  /**
   * @inheritdoc}
   */
  public function getQuantumLevel(): int {
    $quantum_level = 8;

    if (isset($this->gmagick)) {
      try {
        $quantum_level = $this->gmagick->getQuantumDepth()['quantumDepthLong'] ?? 8;
      } catch (GmagickException $e) {
        // As getting the quantum depth failed, assume it is 8.
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
   *   The value for the noise generation option, or Gmagick::NOISE_UNIFORM if
   *   the option is not recognized.
   */
  public static function noiseOptionToValue(string $option): int {
    $options = array(
      'uniform' => Gmagick::NOISE_UNIFORM,
      'gaussian' => Gmagick::NOISE_GAUSSIAN,
      'multiplicative' => Gmagick::NOISE_MULTIPLICATIVEGAUSSIAN,
      'impulse' => Gmagick::NOISE_IMPULSE,
      'laplacian' => Gmagick::NOISE_LAPLACIAN,
      'poisson' => Gmagick::NOISE_POISSON,
    );

    return $options[$option] ?? Gmagick::NOISE_UNIFORM;
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
    if (!isset($this->gmagick)) {
      return array();
    }

    try {
      return array_unique(array_intersect_key(
        self::EXTENSIONS, array_flip($this->gmagick->queryFormats())
      ));
    }
    catch (GmagickException) {
      return array();
    }
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
    if (isset(self::EXTENSIONS[$format]) && isset($this->gmagick)) {
      try {
        $formats = $this->gmagick->queryFormats();
        return in_array($format, $formats) ? self::EXTENSIONS[$format] : '';
      }
      catch (GmagickException) {
        return '';
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
    if (isset(self::MIME_TYPES[$format]) && isset($this->gmagick)) {
      try {
        $formats = $this->gmagick->queryFormats();
        return in_array($format, $formats) ? self::MIME_TYPES[$format] : '';
      }
      catch (GmagickException) {
        return '';
      }
    }

    return '';
  }

}
