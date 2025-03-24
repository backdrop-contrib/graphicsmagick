<?php
/**
 * @file
 * Contains BlurOperation.
 */

declare(strict_types=1);

/**
 * Class for the 'blur' GraphicsMagick operation.
 */
#[OperationType('multiple')]
class BlurOperation extends OperationBase {

  /**
   * {@inheritdoc}
   */
  protected function operationCallback(Gmagick &$gmagick, array $arguments): void {
    $gmagick = $gmagick->blurImage($arguments['radius'], $arguments['sigma']);
  }

}
