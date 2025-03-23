<?php
/**
 * @file
 * Contains DesaturateOperation.
 */

declare(strict_types=1);

/**
 * Class for the 'desaturate' GraphicsMagick operation.
 */
#[OperationType('multiple')]
class DesaturateOperation extends OperationBase {

  /**
   * {@inheritdoc}
   */
  public function executeOperation(Gmagick &$handler, array $arguments): void {
    $handler = $handler->setImageType(Gmagick::IMGTYPE_GRAYSCALE);
  }

}
