<?php

namespace graphicsmagick\Operation;

/**
 * Class for the 'spread' GraphicsMagick operation.
 */
class Spread extends MultipleImagesOperationBase {

  /**
   * {@inheritdoc}
   */
  protected function runOperation(\Gmagick &$handler, array $arguments): void {
    $handler = $handler->spreadImage($arguments['radius']);
  }

}
