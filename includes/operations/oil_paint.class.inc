<?php

namespace graphicsmagick\Operation;

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
