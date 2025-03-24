<?php
/**
 * @file
 * Contains FlipOperation.
 */

declare(strict_types=1);

/**
 * Class for the 'flip' GraphicsMagick operation.
 */
#[OperationType('multiple')]
class FlipOperation extends OperationBase {

  /**
   * {@inheritdoc}
   */
  protected function operationCallback(Gmagick &$gmagick, array $arguments): void {
    $gmagick = $gmagick->flipImage();
  }

}
