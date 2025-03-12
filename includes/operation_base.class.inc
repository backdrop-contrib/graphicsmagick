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
        return $reflection->newInstance();
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
   * The operation callback.
   *
   * @param Gmagick $handler
   *   The Gmagick object.
   * @param array $arguments
   *   An array of arguments for the operation.
   */
  abstract protected function runOperation(Gmagick &$handler, array $arguments): void;

}
