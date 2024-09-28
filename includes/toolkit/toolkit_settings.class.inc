<?php
/**
 * @file
 * Contains \graphicsmagick\ToolkitSettings.
 */

namespace graphicsmagick;

use graphicsmagick\Attribute\DefaultSetting;

/**
 * Retrieves information about the toolkit settings.
 */
#[DefaultSetting('graphicsmagick_toolkit_png_compression', 99)]
#[DefaultSetting('graphicsmagick_toolkit_jpeg_quality', 80)]
class ToolkitSettings {

  /**
   * An array of default settings.
   *
   * @var array
   */
  protected array $defaultSettings = array();

  /**
   * The current settings.
   *
   * @var array
   */
  protected array $settings = array();

  public function __construct() {
    $config = config('system.core');
    $reflection = new \ReflectionClass($this);
    $attributes = $reflection->getAttributes(DefaultSetting::class);

    foreach ($attributes as $attribute) {
      $instance = $attribute->newInstance();
      $this->defaultSettings[$instance->id] = $instance->value;
      $this->settings[$instance->id] = $config->get($instance->id);
    }
  }

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
  public function get(string $key): mixed {
    return $this->settings[$key] ?? ($this->defaultSettings[$key] ?? NULL);
  }

  /**
   * Sets the value of a setting.
   *
   * @param string $key
   *   The ID of the setting to set.
   * @param mixed $value
   *   The value to set the setting to.
   */
  public function set(string $key, mixed $value): void {
    $this->settings[$key] = $value;
  }

  /**
   * Determines if a setting exists in the settings array.
   *
   * @param string $key
   *   The ID of the setting to check.
   *
   * @return bool
   *   TRUE if the setting exists, FALSE otherwise.
   */
  public function has(string $key): bool {
    return isset($this->settings[$key]);
  }

  /**
   * Returns the form items to configure the toolkit settings.
   *
   * @return array
   *   An associative array of form items.
   */
  public function settingsForm(): array {
    $form['graphicsmagick_toolkit_jpeg_quality'] = array(
      '#type' => 'number',
      '#title' => t('JPEG quality'),
      '#description' => t('The image quality for JPEG images (from 0 to 100). Higher values mean better image quality but bigger files.'),
      '#default_value' => $this->get('graphicsmagick_toolkit_jpeg_quality'),
      '#min' => 0,
      '#max' => 100,
      '#step' => 1,
    );

    $form['graphicsmagick_toolkit_png_compression'] = array(
      '#type' => 'number',
      '#title' => t('PNG compression'),
      '#description' => t('The PNG compression (from 0 to 99). Higher values do not mean better compression, although 99 usually compresses a PNG image more than other values. Verify the file size once the image has been saved.'),
      '#default_value' => $this->get('graphicsmagick_toolkit_png_compression'),
      '#min' => 0,
      '#max' => 100,
      '#step' => 1,
    );

    return $form;
  }

}
