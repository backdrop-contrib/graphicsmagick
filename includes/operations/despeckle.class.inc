<?php

namespace graphicsmagick\Operation;

/**
 * Class for the 'despeckle' GraphicsMagick operation.
 */
class Despeckle extends MultipleImagesOperationBase {

  /**
   * {@inheritdoc}
   */
  protected function runOperation(\Gmagick &$handler, array $arguments): void {
    $handler = $handler->despeckleImage();
  }

}
