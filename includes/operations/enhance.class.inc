<?php
/**
 * @file
 * Contains \graphicsmagick\Operation\Enhance.
 */

namespace graphicsmagick\Operation;

use graphicsmagick\MultipleImagesOperationBase;

/**
 * Class for the 'enhance' GraphicsMagick operation.
 */
class Enhance extends MultipleImagesOperationBase {

  /**
   * {@inheritdoc}
   */
  protected function runOperation(\Gmagick &$handler, array $arguments): void {
    $handler = $handler->enhanceImage();
  }

}
