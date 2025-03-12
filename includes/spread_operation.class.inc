<?php
/**
 * @file
 * Contains SpreadOperation.
 */

declare(strict_types=1);

/**
 * Class for the 'spread' GraphicsMagick operation.
 */
class SpreadOperation extends MultipleImagesOperationBase {

  /**
   * {@inheritdoc}
   */
  protected function runOperation(Gmagick &$handler, array $arguments): void {
    $handler = $handler->spreadImage($arguments['radius']);
  }

}
