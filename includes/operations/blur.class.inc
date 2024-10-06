<?php

namespace graphicsmagick\Operation;

/**
 * Class for the 'blur' GraphicsMagick operation.
 */
class Blur extends MultipleImagesOperationBase {

  /**
   * {@inheritdoc}
   */
  protected function runOperation(\Gmagick &$handler, array $arguments): void {
    $handler = $handler->blurImage($arguments['radius'], $arguments['sigma']);
  }

}
