<?php
/**
 * @file
 * Contains CropOperation.
 */

declare(strict_types=1);

/**
 * Class for the 'crop' GraphicsMagick operation.
 */
#[OperationType('multiple_frames')]
class CropOperation extends OperationBase {

  /**
   * {@inheritdoc}
   */
  public function apply(object $image, ?array $arguments = NULL): bool {
    if (parent::apply($image, $arguments)) {
      try {
        // The following methods could throw an exception. In the case they do, use
        // the width and height values passed to the method.
        $new_width = $image->handler->getImageWidth();
        $new_height = $image->handler->getImageHeight();
      }
      catch (GmagickException) {
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
  public function operationCallback(Gmagick &$gmagick, array $arguments): void {
    $gmagick = $gmagick->cropImage(
      $arguments['width'],
      $arguments['height'],
      $arguments['x'],
      $arguments['y']
    );

    // This method is not documented on
    // https://www.php.net/manual/en/class.gmagick.php.
    // Verify it is implemented before using it.
    if (method_exists($gmagick, 'setImagePage')) {
      $gmagick = $gmagick->setImagePage(
        $arguments['width'],
        $arguments['height'],
        $arguments['x'],
        $arguments['y']
      );
    }
  }

}
