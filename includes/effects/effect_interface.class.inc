<?php

namespace graphicsmagick\Effect;

interface EffectInterface {

  public function effectOperations(): array;

  public function defaultSettings(): array;

  public function defaultSettingValue(string $id): mixed;

  public function apply(object $image, array $data): bool;

  public function settingsForm(): array;
}
