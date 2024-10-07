<?php
/**
 * @file
 * Contains \graphicsmagick\Operation\Edge.
 */

declare(strict_types=1);

namespace graphicsmagick\Operation;

use graphicsmagick\MultipleImagesOperationBase;

/**
 * Class for the 'edge' GraphicsMagick operation.
 */
class Edge extends MultipleImagesOperationBase {

  /**
   * {@inheritdoc}
   */
  protected function runOperation(\Gmagick &$handler, array $arguments): void {
    $handler = $handler->edgeImage($arguments['radius']);
  }

}
