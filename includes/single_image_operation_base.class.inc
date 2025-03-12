<?php
/**
 * @file
 * Contains SingleImageOperationBase.
 */

declare(strict_types=1);

/**
 * Base class for operations that are applied once to an image.
 */
abstract class SingleImageOperationBase extends OperationBase {

  /**
   * {@inheritdoc}
   */
  public function apply(object $image, ?array $arguments = NULL): bool {
    if (isset($image->handler) && !is_a($image->handler, 'Gmagick')) {
      // $image->handler has been already set, but it is not a Gmagick instance.
      // To avoid conflicts with other modules, return FALSE.
      return FALSE;
    }

    if (!isset($image->handler)) {
      // The image has not been loaded via image_load(). Return FALSE.
      return FALSE;
    }

    try {
      // Clone the image handler and work with the clone. In case of exceptions,
      // the original image handler and its state is preserved.
      $handler = clone $image->handler;

      if (!method_exists($handler, 'getNumberImages') || !method_exists($handler, 'coalesceImages')) {
        // The required methods are not implemented by Gmagick. Return FALSE.
        return FALSE;
      }

      $this->runOperation($handler, $arguments ?? array());
    }
    catch (GmagickException | Error) {
      try {
        $handler->destroy();
      }
      catch (GmagickException) {
        // Ignore the exception, as there is not anything that can be done when
        // destroying a Gmagick instance fails.
      }

      return FALSE;
    }

    $image->handler = $handler;

    return TRUE;
  }

}
