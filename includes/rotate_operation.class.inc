<?php
/**
 * @file
 * Contains RotateOperation.
 */

declare(strict_types=1);

/**
 * Class for the 'rotate' GraphicsMagick operation.
 */
class RotateOperation extends MultipleImagesOperationBase {

  /**
   * {@inheritdoc}
   */
  protected function runOperation(Gmagick &$handler, array $arguments): void {
    $handler = $handler->rotateImage($arguments['background'], $arguments['degrees']);
  }

}
