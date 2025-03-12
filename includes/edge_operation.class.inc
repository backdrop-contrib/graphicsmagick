<?php
/**
 * @file
 * Contains EdgeOperation.
 */

declare(strict_types=1);

/**
 * Class for the 'edge' GraphicsMagick operation.
 */
class EdgeOperation extends MultipleImagesOperationBase {

  /**
   * {@inheritdoc}
   */
  protected function runOperation(Gmagick &$handler, array $arguments): void {
    $handler = $handler->edgeImage($arguments['radius']);
  }

}
