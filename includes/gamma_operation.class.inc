<?php
/**
 * @file
 * Contains GammaOperation.
 */

declare(strict_types=1);

/**
 * Class for the 'gamma' GraphicsMagick operation.
 */
class GammaOperation extends MultipleImagesOperationBase {

  /**
   * {@inheritdoc}
   */
  protected function runOperation(Gmagick &$handler, array $arguments): void {
    $handler = $handler->gammaImage($arguments['gamma']);
  }

}
