<?php
/**
 * @file
 * Contains RotateOperation.
 */

declare(strict_types=1);

/**
 * Class for the 'rotate' GraphicsMagick operation.
 */
#[OperationType('multiple')]
class RotateOperation extends OperationBase {

  /**
   * {@inheritdoc}
   */
  protected function operationCallback(Gmagick &$gmagick, array $arguments): void {
    $gmagick = $gmagick->rotateImage($arguments['background'], $arguments['degrees']);
  }

}
