<?php
/**
 * @file
 * Contains SolarizeOperation.
 */

declare(strict_types=1);

/**
 * Class for the 'solarize' GraphicsMagick operation.
 */
#[OperationType('multiple')]
class SolarizeOperation extends OperationBase {

  /**
   * {@inheritdoc}
   */
  protected function runOperation(Gmagick &$handler, array $arguments): void {
    $handler = $handler->solarizeImage($arguments['threshold']);
  }

}
