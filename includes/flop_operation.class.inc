<?php
/**
 * @file
 * Contains FlopOperation.
 */

declare(strict_types=1);

/**
 * Class for the 'flop' GraphicsMagick operation.
 */
class FlopOperation extends MultipleImagesOperationBase {

  /**
   * {@inheritdoc}
   */
  protected function runOperation(Gmagick &$handler, array $arguments): void {
    $handler = $handler->flopImage();
  }

}
