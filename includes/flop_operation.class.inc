<?php
/**
 * @file
 * Contains FlopOperation.
 */

declare(strict_types=1);

/**
 * Class for the 'flop' GraphicsMagick operation.
 */
#[OperationType('multiple_frames')]
class FlopOperation extends OperationBase {

  /**
   * {@inheritdoc}
   */
  protected function operationCallback(Gmagick &$gmagick, array $arguments): void {
    $gmagick = $gmagick->flopImage();
  }

}
