<?php
/**
 * @file
 * Contains OperationBase.
 */

declare(strict_types=1);

/**
 * Base class for the GraphicsMagick operations.
 */
abstract class OperationBase implements OperationInterface {

  /**
   * The operation type.
   *
   * @var string
   */
  protected string $type;

  /**
   * Creates an operation object.
   *
   * @param string $id
   *   The ID of the operation.
   *
   * @return OperationBase|null
   *   The operation object or NULL if the operation cannot be created.
   */
  public static function create(string $id): ?OperationBase {
    $class_name = str_replace('_', '', ucwords($id, '_')) . 'Operation';
    try {
      $reflection = new ReflectionClass($class_name);

      if ($reflection->isInstantiable()) {
        $instance = $reflection->newInstance();

        foreach ($reflection->getAttributes(OperationType::class) as $attribute) {
          $object = $attribute->newInstance();
          $instance->type = $object->type;
        }

        return $instance;
      }
      else {
        return NULL;
      }
    }
    catch (ReflectionException) {
      return NULL;
    }
  }

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

      $images_count = match ($this->type) {
        'multiple' => $handler->getNumberImages(),
        'single' => 1,
        default => -1
      };

      if ($images_count > 1) {
        $handler = $handler->coalesceImages();

        do {
          $this->runOperation($handler, $arguments ?? array());
        } while ($handler->nextImage());

        $handler = $handler->deconstructImages();
      }
      else {
        $this->runOperation($handler, $arguments ?? array());
      }
    }
    catch (GmagickException | Error) {
      try {
        $handler->destroy();
      }
      catch (GmagickException) {
        // Ignore the exception, as there is nothing that can be done when
        // destroying a Gmagick instance fails.
      }

      return FALSE;
    }

    $image->handler = $handler;

    return TRUE;
  }

  /**
   * The operation callback.
   *
   * @param Gmagick $handler
   *   The Gmagick object.
   * @param array $arguments
   *   An array of arguments for the operation.
   */
  abstract protected function executeOperation(Gmagick &$handler, array $arguments): void;

}
