<?php
/**
 * @file
 * Contains \graphicsmagick\Operation\Flop.
 */

namespace graphicsmagick\Operation;

use graphicsmagick\MultipleImagesOperationBase;

/**
 * Class for the 'flop' GraphicsMagick operation.
 */
class Flop extends MultipleImagesOperationBase {

  /**
   * {@inheritdoc}
   */
  protected function runOperation(\Gmagick &$handler, array $arguments): void {
    $handler = $handler->flopImage();
  }

}
