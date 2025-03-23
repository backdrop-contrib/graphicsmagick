<?php
/**
 * @file
 * Contains OilPaintOperation.
 */

declare(strict_types=1);

/**
 * Class for the 'oil_paint' GraphicsMagick operation.
 */
#[OperationType('multiple')]
class OilPaintOperation extends OperationBase {

  /**
   * {@inheritdoc}
   */
  protected function runOperation(Gmagick &$handler, array $arguments): void {
    $handler = $handler->oilPaintImage($arguments['radius']);
  }

}
