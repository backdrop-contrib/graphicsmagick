<?php
/**
 * @file
 * Contains \graphicsmagick\Operation\Solarize.
 */

declare(strict_types=1);

namespace graphicsmagick\Operation;

use graphicsmagick\MultipleImagesOperationBase;

/**
 * Class for the 'solarize' GraphicsMagick operation.
 */
class Solarize extends MultipleImagesOperationBase {

  /**
   * {@inheritdoc}
   */
  protected function runOperation(\Gmagick &$handler, array $arguments): void {
    $handler = $handler->solarizeImage($arguments['threshold']);
  }

}
