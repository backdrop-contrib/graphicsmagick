<?php

namespace graphicsmagick\Effect;

use graphicsmagick\Attribute\DefaultSetting;
use graphicsmagick\Attribute\EffectOperation;

class EffectBase implements EffectInterface {

  protected array $defaultSettings = array();

  protected array $effectOperations = array();

  public static function create(string $id) {
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

  public function defaultSettings(): array {
    return $this->defaultSettings;
  }

  public function effectOperations(): array {
    return $this->effectOperations;
  }

  public function apply(object $image, array $data): bool {
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

  public function settingsForm(): array {
    return array();
  }

}
