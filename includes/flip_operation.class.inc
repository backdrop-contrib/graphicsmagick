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
  protected function executeOperation(Gmagick &$handler, array $arguments): void {
    $handler = $handler->flipImage();
  }

}
