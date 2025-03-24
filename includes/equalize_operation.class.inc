<?php
/**
 * @file
 * Contains EqualizeOperation.
 */

declare(strict_types=1);

/**
 * Class for the 'equalize' GraphicsMagick operation.
 */
#[OperationType('multiple_frames')]
class EqualizeOperation extends OperationBase {

  /**
   * {@inheritdoc}
   */
  protected function operationCallback(Gmagick &$gmagick, array $arguments): void {
    $gmagick = $gmagick->equalizeImage();
  }

}
