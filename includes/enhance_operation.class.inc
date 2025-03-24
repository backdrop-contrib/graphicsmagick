<?php
/**
 * @file
 * Contains EnhanceOperation.
 */

declare(strict_types=1);

/**
 * Class for the 'enhance' GraphicsMagick operation.
 */
#[OperationType('multiple_frames')]
class EnhanceOperation extends OperationBase {

  /**
   * {@inheritdoc}
   */
  protected function operationCallback(Gmagick &$gmagick, array $arguments): void {
    $gmagick = $gmagick->enhanceImage();
  }

}
