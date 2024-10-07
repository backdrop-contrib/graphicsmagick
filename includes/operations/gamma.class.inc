<?php
/**
 * @file
 * Contains \graphicsmagick\Operation\Gamma.
 */

declare(strict_types=1);

namespace graphicsmagick\Operation;

use graphicsmagick\MultipleImagesOperationBase;

/**
 * Class for the 'gamma' GraphicsMagick operation.
 */
class Gamma extends MultipleImagesOperationBase {

  /**
   * {@inheritdoc}
   */
  protected function runOperation(\Gmagick &$handler, array $arguments): void {
    $handler = $handler->gammaImage($arguments['gamma']);
  }

}
