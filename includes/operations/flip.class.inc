<?php

namespace graphicsmagick\Operation;

/**
 * Class for the 'flip' GraphicsMagick operation.
 */
class Flip extends MultipleImagesOperationBase {

  /**
   * {@inheritdoc}
   */
  protected function runOperation(\Gmagick &$handler, array $arguments): void {
    $handler = $handler->flipImage();
  }

}
