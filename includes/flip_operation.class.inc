<?php
/**
 * @file
 * Contains FlipOperation.
 */

declare(strict_types=1);

/**
 * Class for the 'flip' GraphicsMagick operation.
 */
class FlipOperation extends MultipleImagesOperationBase {

  /**
   * {@inheritdoc}
   */
  protected function runOperation(Gmagick &$handler, array $arguments): void {
    $handler = $handler->flipImage();
  }

}
