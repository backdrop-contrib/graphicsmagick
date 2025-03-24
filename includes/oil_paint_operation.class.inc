<?php
/**
 * @file
 * Contains OilPaintOperation.
 */

declare(strict_types=1);

/**
 * Class for the 'oil_paint' GraphicsMagick operation.
 */
#[OperationType('multiple_frames')]
class OilPaintOperation extends OperationBase {

  /**
   * {@inheritdoc}
   */
  protected function operationCallback(Gmagick &$gmagick, array $arguments): void {
    $gmagick = $gmagick->oilPaintImage($arguments['radius']);
  }

}
