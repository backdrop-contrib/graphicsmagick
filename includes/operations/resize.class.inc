<?php

namespace graphicsmagick\Operation;

use graphicsmagick\MultipleImagesOperationBase;

/**
 * Class for the 'resize' GraphicsMagick operation.
 */
class Resize extends MultipleImagesOperationBase {

  /**
   * {@inheritdoc}
   */
  public function apply(object $image, ?array $arguments = NULL): bool {
    if (parent::apply($image, $arguments)) {
      try {
        // The following methods could throw an exception. In the case they do,
        // use the width and height values passed to the method.
        $new_width = $image->handler->getImageWidth();
        $new_height = $image->handler->getImageHeight();
      }
      catch (\GmagickException|\Error) {
        $new_width = $arguments['width'];
        $new_height = $arguments['height'];
      }

      $image->info['width'] = $new_width;
      $image->info['height'] = $new_height;

      return TRUE;
    }

    return FALSE;
  }

  /**
   * {@inheritdoc}
   */
  protected function runOperation(\Gmagick &$handler, array $arguments): void {
    $handler = $handler->resizeImage(
      $arguments['width'],
      $arguments['height'],
      // image_resize() does not pass values for the following two parameters.
      \Gmagick::FILTER_UNDEFINED,
      0.88
    );
  }

}
