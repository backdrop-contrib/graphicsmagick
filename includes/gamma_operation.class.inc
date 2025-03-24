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
  protected function operationCallback(Gmagick &$gmagick, array $arguments): void {
    $gmagick = $gmagick->gammaImage($arguments['gamma']);
  }

}
