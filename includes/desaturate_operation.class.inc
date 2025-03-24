<?php
/**
 * @file
 * Contains DesaturateOperation.
 */

declare(strict_types=1);

/**
 * Class for the 'desaturate' GraphicsMagick operation.
 */
#[OperationType('multiple_frames')]
class DesaturateOperation extends OperationBase {

  /**
   * {@inheritdoc}
   */
  public function operationCallback(Gmagick &$gmagick, array $arguments): void {
    $gmagick = $gmagick->setImageType(Gmagick::IMGTYPE_GRAYSCALE);
  }

}
