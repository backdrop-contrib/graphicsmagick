<?php
/**
 * @file
 * Contains BlurOperation.
 */

declare(strict_types=1);

/**
 * Class for the 'blur' GraphicsMagick operation.
 */
class BlurOperation extends MultipleImagesOperationBase {

  /**
   * {@inheritdoc}
   */
  protected function runOperation(Gmagick &$handler, array $arguments): void {
    $handler = $handler->blurImage($arguments['radius'], $arguments['sigma']);
  }

}
