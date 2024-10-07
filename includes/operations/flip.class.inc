<?php
/**
 * @file
 * Contains \graphicsmagick\Operation\Flip.
 */

declare(strict_types=1);

namespace graphicsmagick\Operation;

use graphicsmagick\MultipleImagesOperationBase;

/**
 * Class for the 'flip' GraphicsMagick operation.
 */
class Flip extends MultipleImagesOperationBase {

  /**
   * {@inheritdoc}
   */
  protected function runOperation(\Gmagick &$handler, array $arguments): void {
    $handler = $handler->flipImage();
  }

}
