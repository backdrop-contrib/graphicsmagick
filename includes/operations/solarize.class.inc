<?php

namespace graphicsmagick\Operation;

/**
 * Class for the 'solarize' GraphicsMagick operation.
 */
class Solarize extends MultipleImagesOperationBase {

  /**
   * {@inheritdoc}
   */
  protected function runOperation(\Gmagick &$handler, array $arguments): void {
    $handler = $handler->solarizeImage();
  }

}
