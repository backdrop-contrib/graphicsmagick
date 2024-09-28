<?php
/**
 * @file
 * Contains \graphicsmagick\Effect\EffectInterface.
 */

namespace graphicsmagick\Effect;

/**
 * Interface for image effects.
 */
interface EffectInterface {

  /**
   * Retrieves the operations for the effect.
   *
   * @return array
   *   An associative array of operations for the effect.
   */
  public function effectOperations(): array;

  /**
   * Retrieves the default settings for the effect.
   *
   * @return array
   *   An associative array of default settings for the effect.
   */
  public function defaultSettings(): array;

  /**
   * Retrieves the default value for a setting.
   *
   * @param string $id
   *   The ID of the setting.
   *
   * @return mixed
   *   The default value for the setting, or NULL if the setting does not exist.
   */
  public function defaultSettingValue(string $id): mixed;

  /**
   * Applies the effect to an image.
   *
   * @param object $image
   *   An image object.
   * @param array $data
   *   An associative array of settings to apply to the image.
   *
   * @return bool
   *   TRUE on success, FALSE on failure to apply the effect.
   */
  public function apply(object $image, array $data): bool;

  /**
   * Form structure for the settings form.
   *
   * Note that this is not a complete form; it only contains the portion of the
   * form for configuring the effect options. Therefore, it does not need to
   * include metadata about the effect, nor a submit button.
   *
   * @return array
   *   An associative array of form items.
   */
  public function settingsForm(): array;
}
