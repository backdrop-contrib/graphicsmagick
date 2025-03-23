<?php
/**
 * @file
 * Contains EnhanceOperation.
 */

declare(strict_types=1);

/**
 * Class for the 'enhance' GraphicsMagick operation.
 */
#[OperationType('multiple')]
class EnhanceOperation extends OperationBase {

  /**
   * {@inheritdoc}
   */
  protected function runOperation(Gmagick &$handler, array $arguments): void {
    $handler = $handler->enhanceImage();
  }

}
