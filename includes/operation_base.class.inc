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
    if (isset($image->handler) && !is_a($image->handler, ImageHandler::class)) {
      // $image->handler has been already set, but it is not the expected
      // instance. To avoid conflicts with other modules, return FALSE.
      return FALSE;
    }

    if (!isset($image->handler)) {
      // The image has not been loaded via image_load(). Return FALSE.
      return FALSE;
    }

    return $image->handler->applyOperation($this->operationCallback(...), $this->type, $arguments);

  }

  /**
   * The operation callback.
   *
   * @param Gmagick $gmagick
   *   The Gmagick object.
   * @param array $arguments
   *   An array of arguments for the operation.
   */
  abstract protected function operationCallback(Gmagick &$gmagick, array $arguments): void;

}
