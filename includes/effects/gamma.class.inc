<?php
/**
 * @file
 * Contains \graphicsmagick\Effect\Gamma.
 */

declare(strict_types=1);

namespace graphicsmagick\Effect;

use graphicsmagick\Attribute\DefaultSetting;
use graphicsmagick\Attribute\EffectOperation;
use graphicsmagick\EffectBase;

/**
 * Image 'gamma' effect class.
 */
#[DefaultSetting('gamma', value: 0.8)]
#[EffectOperation('gamma', params: array('$gamma'))]
class Gamma extends EffectBase {

  /**
   * {@inheritdoc}
   * @param array $data
   */
  public function settingsForm(array $data): array {
    $form['gamma'] = array(
      '#type' => 'number',
      '#title' => t('Gamma'),
      '#description' => t('Values typically range from 0.8 to 2.3. Values lower than one make the image darker; values higher than one make the image lighter.'),
      '#default_value' => $data['gamma'] ?? $this->defaultSettingValue('gamma'),
      '#required' => TRUE,
      '#min' => 0.0,
      '#max' => 10.0,
      '#step' => 0.2,
    );

    return $form;
  }

}
