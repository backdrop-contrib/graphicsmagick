<?php
/**
 * @file
 * Contains \graphicsmagick\Operation\Desaturate.
 */

declare(strict_types=1);

namespace graphicsmagick\Operation;

use graphicsmagick\MultipleImagesOperationBase;

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
