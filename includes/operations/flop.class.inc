<?php

namespace graphicsmagick\Operation;

/**
 * Class for the 'flop' GraphicsMagick operation.
 */
class Flop extends MultipleImagesOperationBase {

  /**
   * {@inheritdoc}
   */
  protected function runOperation(\Gmagick &$handler, array $arguments): void {
    $handler = $handler->flopImage();
  }

}
