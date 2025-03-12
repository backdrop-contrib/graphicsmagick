<?php
/**
 * @file
 * Contains EqualizeOperation.
 */

declare(strict_types=1);

/**
 * Class for the 'equalize' GraphicsMagick operation.
 */
class EqualizeOperation extends MultipleImagesOperationBase {

  /**
   * {@inheritdoc}
   */
  protected function runOperation(Gmagick &$handler, array $arguments): void {
    $handler = $handler->equalizeImage();
  }

}
