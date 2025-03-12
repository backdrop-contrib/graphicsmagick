<?php
/**
 * @file
 * Contains SwirlOperation.
 */

declare(strict_types=1);

/**
 * Class for the 'swirl' GraphicsMagick operation.
 */
class SwirlOperation extends MultipleImagesOperationBase {

  /**
   * {@inheritdoc}
   */
  protected function runOperation(Gmagick &$handler, array $arguments): void {
    $handler = $handler->swirlImage($arguments['degrees']);
  }

}
