<?php
/**
 * @file
 * Contains \graphicsmagick\Operation\Noise.
 */

declare(strict_types=1);

namespace graphicsmagick\Operation;

use graphicsmagick\MultipleImagesOperationBase;

/**
 * Class for the 'noise' GraphicsMagick operation.
 */
class Noise extends MultipleImagesOperationBase {

  /**
   * {@inheritdoc}
   */
  protected function runOperation(\Gmagick &$handler, array $arguments): void {
    $handler = $handler->addNoiseImage($arguments['noise']);
  }

}
