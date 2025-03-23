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
  protected function runOperation(Gmagick &$handler, array $arguments): void {
    $handler = $handler->spreadImage($arguments['radius']);
  }

}
