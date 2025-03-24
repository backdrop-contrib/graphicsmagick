<?php
/**
 * @file
 * Contains EdgeOperation.
 */

declare(strict_types=1);

/**
 * Class for the 'edge' GraphicsMagick operation.
 */
#[OperationType('multiple_frames')]
class EdgeOperation extends OperationBase {

  /**
   * {@inheritdoc}
   */
  protected function operationCallback(Gmagick &$gmagick, array $arguments): void {
    $gmagick = $gmagick->edgeImage($arguments['radius']);
  }

}
