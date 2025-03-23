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
  protected function runOperation(Gmagick &$handler, array $arguments): void {
    $handler = $handler->blurImage($arguments['radius'], $arguments['sigma']);
  }

}
