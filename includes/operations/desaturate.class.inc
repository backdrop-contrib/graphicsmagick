<?php

namespace graphicsmagick\Operation;

/**
 * Class for the 'desaturate' GraphicsMagick operation.
 */
class Desaturate extends MultipleImagesOperationBase {

  /**
   * {@inheritdoc}
   */
  public function runOperation(\Gmagick &$handler, array $arguments): void {
    $handler = $handler->setImageType(\Gmagick::IMGTYPE_GRAYSCALE);
  }

}
