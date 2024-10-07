<?php
/**
 * @file
 * Contains \graphicsmagick\Operation\Blur.
 */

declare(strict_types=1);

namespace graphicsmagick\Operation;

use graphicsmagick\MultipleImagesOperationBase;

/**
 * Class for the 'blur' GraphicsMagick operation.
 */
class Blur extends MultipleImagesOperationBase {

  /**
   * {@inheritdoc}
   */
  protected function runOperation(\Gmagick &$handler, array $arguments): void {
    $handler = $handler->blurImage($arguments['radius'], $arguments['sigma']);
  }

}
