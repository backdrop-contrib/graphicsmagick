<?php
/**
 * @file
 * Contains \graphicsmagick\Operation\OilPaint.
 */

declare(strict_types=1);

namespace graphicsmagick\Operation;

use graphicsmagick\MultipleImagesOperationBase;

/**
 * Class for the 'oil_paint' GraphicsMagick operation.
 */
class OilPaint extends MultipleImagesOperationBase {

  /**
   * {@inheritdoc}
   */
  protected function runOperation(\Gmagick &$handler, array $arguments): void {
    $handler = $handler->oilPaintImage($arguments['radius']);
  }

}
