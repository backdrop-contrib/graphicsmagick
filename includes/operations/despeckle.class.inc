<?php
/**
 * @file
 * Contains \graphicsmagick\Operation\Despeckle.
 */

declare(strict_types=1);

namespace graphicsmagick\Operation;

use graphicsmagick\MultipleImagesOperationBase;

/**
 * Class for the 'despeckle' GraphicsMagick operation.
 */
class Despeckle extends MultipleImagesOperationBase {

  /**
   * {@inheritdoc}
   */
  protected function runOperation(\Gmagick &$handler, array $arguments): void {
    $handler = $handler->despeckleImage();
  }

}
