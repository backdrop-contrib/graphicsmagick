<?php
/**
 * @file
 * Contains GammaOperation.
 */

declare(strict_types=1);

/**
 * Class for the 'gamma' GraphicsMagick operation.
 */
#[OperationType('multiple')]
class GammaOperation extends OperationBase {

  /**
   * {@inheritdoc}
   */
  protected function executeOperation(Gmagick &$handler, array $arguments): void {
    $handler = $handler->gammaImage($arguments['gamma']);
  }

}
