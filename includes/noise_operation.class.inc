<?php
/**
 * @file
 * Contains NoiseOperation.
 */

declare(strict_types=1);

/**
 * Class for the 'noise' GraphicsMagick operation.
 */
class NoiseOperation extends MultipleImagesOperationBase {

  /**
   * {@inheritdoc}
   */
  protected function runOperation(Gmagick &$handler, array $arguments): void {
    $handler = $handler->addNoiseImage($arguments['noise']);
  }

}
