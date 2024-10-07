<?php
/**
 * @file
 * Contains \graphicsmagick\Operation\Enhance.
 */

declare(strict_types=1);

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
