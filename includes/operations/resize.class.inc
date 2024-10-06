<?php

namespace graphicsmagick\Operation;

/**
 * Class for the 'resize' GraphicsMagick operation.
 */
class Resize extends MultipleImagesOperationBase {

  /**
   * {@inheritdoc}
   */
  protected function runOperation(\Gmagick &$handler, array $arguments): void {
    $handler = $handler->resizeImage(
      $arguments['width'],
      $arguments['height'],
      // Image::resize() does not pass values for the following two parameters.
      \Gmagick::FILTER_UNDEFINED,
      0.88
    );
  }

}
