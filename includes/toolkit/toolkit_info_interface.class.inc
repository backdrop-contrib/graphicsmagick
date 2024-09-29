<?php

namespace graphicsmagick;

interface ToolkitInfoInterface {

  /**
   * Returns whether the GraphicsMagick toolkit is available.
   *
   * The GraphicsMagick toolkit is considered available if the Gmagick class can
   * be instantiated and the following methods are implemented:
   * - getNumberImages()
   * - coalesceImages()
   * - deconstructImages()
   *
   * @return bool
   *   TRUE if the GraphicsMagick toolkit is available, FALSE otherwise.
   */
  public function isAvailable(): bool;

  /**
   * Returns the quantum level for the GraphicsMagick library.
   *
   * The quantum level is a value between 8 and 16 that specifies the maximum
   * number of significant digits for the red, green, and blue intensities that
   * are used to represent the color of each pixel in an image. The higher the
   * number, the more detailed the image, but the more memory it needs.
   *
   * @return int
   *   The quantum level.
   */
  public function getQuantumLevel(): int;

  /**
   * Returns the options for noise generation.
   *
   * @return array
   *   An associative array of noise generation options where the keys are the
   *   option names and the values are the translated names of the options.
   */
  public static function noiseOptions(): array;
}
