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
class ToolkitSettings implements ToolkitSettingsInterface {

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
   * {@inheritdoc}
   */
  public function get(string $key): mixed {
    return $this->settings[$key] ?? ($this->defaultSettings[$key] ?? NULL);
  }

  /**
   * {@inheritdoc}
   */
  public function set(string $key, mixed $value): self {
    $this->settings[$key] = $value;

    return $this;
  }

  /**
   * {@inheritdoc}
   */
  public function has(string $key): bool {
    return isset($this->settings[$key]);
  }

  /**
   * {@inheritdoc}
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
