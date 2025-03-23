<?php
/**
 * @file
 * Contains DespeckleOperation.
 */

declare(strict_types=1);

/**
 * Class for the 'despeckle' GraphicsMagick operation.
 */
#[OperationType('multiple')]
class DespeckleOperation extends OperationBase {

  /**
   * {@inheritdoc}
   */
  protected function runOperation(Gmagick &$handler, array $arguments): void {
    $handler = $handler->despeckleImage();
  }

}
