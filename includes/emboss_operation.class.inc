<?php
/**
 * @file
 * Contains EmbossOperation.
 */

declare(strict_types=1);

/**
 * Class for the 'emboss' GraphicsMagick operation.
 */
class EmbossOperation extends MultipleImagesOperationBase {

  /**
   * {@inheritdoc}
   */
  protected function runOperation(Gmagick &$handler, array $arguments): void {
    $handler = $handler->setImageType(Gmagick::IMGTYPE_GRAYSCALE);
    $handler = $handler->embossImage($arguments['radius'], $arguments['sigma']);
  }

}
