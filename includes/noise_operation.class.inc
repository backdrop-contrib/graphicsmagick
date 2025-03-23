<?php
/**
 * @file
 * Contains NoiseOperation.
 */

declare(strict_types=1);

/**
 * Class for the 'noise' GraphicsMagick operation.
 */
#[OperationType('multiple')]
class NoiseOperation extends OperationBase {

  /**
   * {@inheritdoc}
   */
  protected function executeOperation(Gmagick &$handler, array $arguments): void {
    $handler = $handler->addNoiseImage($arguments['noise']);
  }

}
