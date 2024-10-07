<?php
/**
 * @file
 * Contains \graphicsmagick\Operation\Swirl.
 */

declare(strict_types=1);

namespace graphicsmagick\Operation;

use graphicsmagick\MultipleImagesOperationBase;

/**
 * Class for the 'swirl' GraphicsMagick operation.
 */
class Swirl extends MultipleImagesOperationBase {

  /**
   * {@inheritdoc}
   */
  protected function runOperation(\Gmagick &$handler, array $arguments): void {
    $handler = $handler->swirlImage($arguments['degrees']);
  }

}
