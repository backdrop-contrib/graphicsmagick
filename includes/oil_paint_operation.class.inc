<?php
/**
 * @file
 * Contains OilPaintOperation.
 */

declare(strict_types=1);

/**
 * Class for the 'oil_paint' GraphicsMagick operation.
 */
class OilPaintOperation extends MultipleImagesOperationBase {

  /**
   * {@inheritdoc}
   */
  protected function runOperation(Gmagick &$handler, array $arguments): void {
    $handler = $handler->oilPaintImage($arguments['radius']);
  }

}
