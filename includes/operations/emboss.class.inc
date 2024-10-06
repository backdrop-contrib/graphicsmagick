<?php

namespace graphicsmagick\Operation;

use graphicsmagick\MultipleImagesOperationBase;

/**
 * Class for the 'emboss' GraphicsMagick operation.
 */
class Emboss extends MultipleImagesOperationBase {

  /**
   * {@inheritdoc}
   */
  protected function runOperation(\Gmagick &$handler, array $arguments): void {
    $handler = $handler->setImageType(\Gmagick::IMGTYPE_GRAYSCALE);
    $handler = $handler->embossImage($arguments['radius'], $arguments['sigma']);
  }

}
