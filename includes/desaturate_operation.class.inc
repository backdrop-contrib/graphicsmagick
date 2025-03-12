<?php
/**
 * @file
 * Contains DesaturateOperation.
 */

declare(strict_types=1);

/**
 * Class for the 'desaturate' GraphicsMagick operation.
 */
class DesaturateOperation extends MultipleImagesOperationBase {

  /**
   * {@inheritdoc}
   */
  public function runOperation(Gmagick &$handler, array $arguments): void {
    $handler = $handler->setImageType(Gmagick::IMGTYPE_GRAYSCALE);
  }

}
