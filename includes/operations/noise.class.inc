<?php

namespace graphicsmagick\Operation;

/**
 * Class for the 'noise' GraphicsMagick operation.
 */
class Noise extends MultipleImagesOperationBase {

  /**
   * {@inheritdoc}
   */
  protected function runOperation(\Gmagick &$handler, array $arguments): void {
    $handler = $handler->addNoiseImage($arguments['noise']);
  }

}
