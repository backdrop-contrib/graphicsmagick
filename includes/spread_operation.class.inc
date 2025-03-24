<?php
/**
 * @file
 * Contains SpreadOperation.
 */

declare(strict_types=1);

/**
 * Class for the 'spread' GraphicsMagick operation.
 */
#[OperationType('multiple')]
class SpreadOperation extends OperationBase {

  /**
   * {@inheritdoc}
   */
  protected function operationCallback(Gmagick &$gmagick, array $arguments): void {
    $gmagick = $gmagick->spreadImage($arguments['radius']);
  }

}
