<?php
/**
 * @file
 * Contains SwirlOperation.
 */

declare(strict_types=1);

/**
 * Class for the 'swirl' GraphicsMagick operation.
 */
#[OperationType('multiple')]
class SwirlOperation extends OperationBase {

  /**
   * {@inheritdoc}
   */
  protected function runOperation(Gmagick &$handler, array $arguments): void {
    $handler = $handler->swirlImage($arguments['degrees']);
  }

}
