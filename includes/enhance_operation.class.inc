<?php
/**
 * @file
 * Contains EnhanceOperation.
 */

declare(strict_types=1);

/**
 * Class for the 'enhance' GraphicsMagick operation.
 */
class EnhanceOperation extends MultipleImagesOperationBase {

  /**
   * {@inheritdoc}
   */
  protected function runOperation(Gmagick &$handler, array $arguments): void {
    $handler = $handler->enhanceImage();
  }

}
