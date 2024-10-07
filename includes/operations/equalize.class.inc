<?php
/**
 * @file
 * Contains \graphicsmagick\Operation\Equalize.
 */

declare(strict_types=1);

namespace graphicsmagick\Operation;

use graphicsmagick\MultipleImagesOperationBase;

/**
 * Class for the 'equalize' GraphicsMagick operation.
 */
class Equalize extends MultipleImagesOperationBase {

  /**
   * {@inheritdoc}
   */
  protected function runOperation(\Gmagick &$handler, array $arguments): void {
    $handler = $handler->equalizeImage();
  }

}
