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
  protected function operationCallback(Gmagick &$gmagick, array $arguments): void {
    $gmagick = $gmagick->despeckleImage();
  }

}
