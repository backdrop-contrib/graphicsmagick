<?php

namespace graphicsmagick;

interface ToolkitSettingsInterface {

  /**
   * Retrieves the value of a setting.
   *
   * The value of the setting is first retrieved from the settings array. If
   * the setting does not exist in the settings array, the value is retrieved
   * from the default settings array. If the setting does not exist in the
   * default settings array, the method returns NULL.
   *
   * @param string $key
   *   The ID of the setting to retrieve.
   *
   * @return mixed
   *   The value of the setting, or NULL if the setting does not exist.
   */
  public function get(string $key): mixed;

  /**
   * Sets the value of a setting.
   *
   * @param string $key
   *   The ID of the setting to set.
   * @param mixed $value
   *   The value to set the setting to.
   *
   * @return $this
   */
  public function set(string $key, mixed $value): self;

  /**
   * Determines if a setting exists in the settings array.
   *
   * @param string $key
   *   The ID of the setting to check.
   *
   * @return bool
   *   TRUE if the setting exists, FALSE otherwise.
   */
  public function has(string $key): bool;

  /**
   * Returns the form items to configure the toolkit settings.
   *
   * @return array
   *   An associative array of form items.
   */
  public function settingsForm(): array;

}
