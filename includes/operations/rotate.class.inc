<?php

namespace graphicsmagick\Operation;

/**
 * Class for the 'rotate' GraphicsMagick operation.
 */
class Rotate extends MultipleImagesOperationBase {

  /**
   * {@inheritdoc}
   */
  protected function runOperation(\Gmagick &$handler, array $arguments): void {
    $handler = $handler->rotateImage($arguments['background'], $arguments['degrees']);
  }

}
