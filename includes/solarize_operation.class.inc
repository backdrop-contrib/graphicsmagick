<?php
/**
 * @file
 * Contains SolarizeOperation.
 */

declare(strict_types=1);

/**
 * Class for the 'solarize' GraphicsMagick operation.
 */
#[OperationType('multiple_frames')]
class SolarizeOperation extends OperationBase {

  /**
   * {@inheritdoc}
   */
  protected function operationCallback(Gmagick &$gmagick, array $arguments): void {
    $gmagick = $gmagick->solarizeImage($arguments['threshold']);
  }

}
