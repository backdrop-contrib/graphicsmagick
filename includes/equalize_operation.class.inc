<?php
/**
 * @file
 * Contains EqualizeOperation.
 */

declare(strict_types=1);

/**
 * Class for the 'equalize' GraphicsMagick operation.
 */
#[OperationType('multiple')]
class EqualizeOperation extends OperationBase {

  /**
   * {@inheritdoc}
   */
  protected function executeOperation(Gmagick &$handler, array $arguments): void {
    $handler = $handler->equalizeImage();
  }

}
