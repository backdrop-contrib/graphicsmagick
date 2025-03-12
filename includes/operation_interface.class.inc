<?php
/**
 * @file
 * Contains OperationInterface.
 */

declare(strict_types=1);

/**
 * Interface for GraphicsMagick toolkit operations.
 */
interface OperationInterface {

  /**
   * Applies the toolkit operation to the image.
   *
   * @param object $image
   *   An image object.
   * @param ?array $arguments
   *   An associative array of settings to apply to the image.
   *
   * @return bool
   *   TRUE on success, FALSE on failure to apply the operation.
   */
  public function apply(object $image, ?array $arguments = NULL): bool;

}
