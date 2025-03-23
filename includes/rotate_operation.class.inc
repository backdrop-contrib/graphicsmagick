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
  protected function runOperation(Gmagick &$handler, array $arguments): void {
    $handler = $handler->rotateImage($arguments['background'], $arguments['degrees']);
  }

}
