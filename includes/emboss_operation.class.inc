<?php
/**
 * @file
 * Contains EmbossOperation.
 */

declare(strict_types=1);

/**
 * Class for the 'emboss' GraphicsMagick operation.
 */
#[OperationType('multiple')]
class EmbossOperation extends OperationBase {

  /**
   * {@inheritdoc}
   */
  protected function operationCallback(Gmagick &$gmagick, array $arguments): void {
    $gmagick = $gmagick->setImageType(Gmagick::IMGTYPE_GRAYSCALE);
    $gmagick = $gmagick->embossImage($arguments['radius'], $arguments['sigma']);
  }

}
