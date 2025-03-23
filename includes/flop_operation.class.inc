<?php
/**
 * @file
 * Contains FlopOperation.
 */

declare(strict_types=1);

/**
 * Class for the 'flop' GraphicsMagick operation.
 */
#[OperationType('multiple')]
class FlopOperation extends OperationBase {

  /**
   * {@inheritdoc}
   */
  protected function executeOperation(Gmagick &$handler, array $arguments): void {
    $handler = $handler->flopImage();
  }

}
