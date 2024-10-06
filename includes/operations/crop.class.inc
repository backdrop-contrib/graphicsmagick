<?php

namespace graphicsmagick\Operation;

/**
 * Class for the 'crop' GraphicsMagick operation.
 */
class Crop extends MultipleImagesOperationBase {

  /**
   * {@inheritdoc}
   */
  public function runOperation(\Gmagick &$handler, array $arguments): void {
    $handler = $handler->cropImage(
      $arguments['width'],
      $arguments['height'],
      $arguments['x'],
      $arguments['y']
    );

    // This method is not documented on
    // https://www.php.net/manual/en/class.gmagick.php.
    // Verify it is implemented before using it.
    if (method_exists($handler, 'setImagePage')) {
      $handler = $handler->setImagePage(
        $arguments['width'],
        $arguments['height'],
        $arguments['x'],
        $arguments['y']
      );
    }
  }

}
