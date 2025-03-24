<?php
/**
 * @file
 * Contains SwirlOperation.
 */

declare(strict_types=1);

/**
 * Class for the 'swirl' GraphicsMagick operation.
 */
#[OperationType('multiple_frames')]
class SwirlOperation extends OperationBase {

  /**
   * {@inheritdoc}
   */
  protected function operationCallback(Gmagick &$gmagick, array $arguments): void {
    $gmagick = $gmagick->swirlImage($arguments['degrees']);
  }

}
