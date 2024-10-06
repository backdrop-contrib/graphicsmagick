<?php

namespace graphicsmagick\Operation;

/**
 * Class for the 'equalize' GraphicsMagick operation.
 */
class Equalize extends MultipleImagesOperationBase {

  /**
   * {@inheritdoc}
   */
  protected function runOperation(\Gmagick &$handler, array $arguments): void {
    $handler = $handler->equalizeImage();
  }

}
