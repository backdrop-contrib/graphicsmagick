<?php
/**
 * @file
 * Contains \graphicsmagick\Operation\Rotate.
 */

declare(strict_types=1);

namespace graphicsmagick\Operation;

use graphicsmagick\MultipleImagesOperationBase;

/**
 * Class for the 'rotate' GraphicsMagick operation.
 */
class Rotate extends MultipleImagesOperationBase {

  /**
   * {@inheritdoc}
   */
  protected function runOperation(\Gmagick &$handler, array $arguments): void {
    $handler = $handler->rotateImage($arguments['background'], $arguments['degrees']);
  }

}
