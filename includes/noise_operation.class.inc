<?php
/**
 * @file
 * Contains NoiseOperation.
 */

declare(strict_types=1);

/**
 * Class for the 'noise' GraphicsMagick operation.
 */
#[OperationType('multiple_frames')]
class NoiseOperation extends OperationBase {

  /**
   * {@inheritdoc}
   */
  protected function operationCallback(Gmagick &$gmagick, array $arguments): void {
    $gmagick = $gmagick->addNoiseImage($arguments['noise']);
  }

}
