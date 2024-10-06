<?php

namespace graphicsmagick\Operation;

/**
 * Class for the 'swirl' GraphicsMagick operation.
 */
class Swirl extends MultipleImagesOperationBase {

  /**
   * {@inheritdoc}
   */
  protected function runOperation(\Gmagick &$handler, array $arguments): void {
    $handler = $handler->swirlImage($arguments['degrees']);
  }

}
