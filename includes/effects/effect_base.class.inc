<?php
/**
 * @file
 * Contains \graphicsmagick\Effect\EffectBase.
 */

namespace graphicsmagick\Effect;

use graphicsmagick\Attribute\DefaultSetting;
use graphicsmagick\Attribute\EffectOperation;

/**
 * Base class for image effects.
 */
class EffectBase implements EffectInterface {

  /**
   * The default values for the effect settings.
   *
   * @var array
   */
  protected array $defaultSettings = array();

  /**
   * The toolkit operations called to create the effect.
   *
   * @var array
   */
  protected array $effectOperations = array();

  /**
   * Creates the effect object.
   *
   * @param string $id
   *   The ID of the effect.
   *
   * @return \graphicsmagick\Effect\EffectBase|null
   *   The effect object or NULL if the effect could not be created.
   */
  public static function create(string $id): ?EffectBase {
    $class_name = 'graphicsmagick\Effect\\' . str_replace('_', '', ucwords($id, '_')) . 'Effect';
    try {
      $reflection = new \ReflectionClass($class_name);

      if ($reflection->isInstantiable()) {
        $instance = $reflection->newInstance();

        foreach ($reflection->getAttributes(EffectOperation::class) as $attribute) {
          $object = $attribute->newInstance();
          $instance->effectOperations[$object->operation] = $object->params;
        }

        foreach ($reflection->getAttributes(DefaultSetting::class) as $attribute) {
          $object = $attribute->newInstance();
          $instance->defaultSettings[$object->id] = $object->value;
        }

        return $instance;
      }
      else {
        return NULL;
      }
    }
    catch (\ReflectionException) {
      return NULL;
    }
  }

  /**
   * {@inheritdoc}
   */
  public function defaultSettings(): array {
    return $this->defaultSettings;
  }

  /**
   * {@inheritdoc}
   */
  public function defaultSettingValue(string $id): mixed {
    return $this->defaultSettings[$id] ?? NULL;
  }

  /**
   * {@inheritdoc}
   */
  public function effectOperations(): array {
    return $this->effectOperations;
  }

  /**
   * {@inheritdoc}
   */
  public function apply(object $image, ?array $data = NULL): bool {
    foreach ($this->effectOperations as $operation => $params) {
      foreach ($params as $key => $value) {
        if (is_string($value) && $value[0] == '$') {
          $id = substr($value, 1);
          if (isset($data[$id])) {
            $params[$key] = $data[$id];
          }
        }
      }

      if (!image_toolkit_invoke($operation, $image, array_values($params))) {
        return FALSE;
      }
    }

    return TRUE;
  }

  /**
   * {@inheritdoc}
   */
  public function settingsForm(array $data): array {
    return array();
  }

}
