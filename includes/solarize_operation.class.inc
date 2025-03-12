<?php
/**
 * @file
 * Contains SolarizeOperation.
 */

declare(strict_types=1);

/**
 * Class for the 'solarize' GraphicsMagick operation.
 */
class SolarizeOperation extends MultipleImagesOperationBase {

  /**
   * {@inheritdoc}
   */
  protected function runOperation(Gmagick &$handler, array $arguments): void {
    $handler = $handler->solarizeImage($arguments['threshold']);
  }

}
