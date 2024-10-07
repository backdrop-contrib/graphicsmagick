<?php
/**
 * @file
 * Contains \graphicsmagick\Effect\Blur.
 */

namespace graphicsmagick\Effect;

use graphicsmagick\Attribute\DefaultSetting;
use graphicsmagick\Attribute\EffectOperation;

/**
 * Image 'blur' effect class.
 */
#[DefaultSetting('radius', value: 0.0)]
#[DefaultSetting('sigma', value: 1.0)]
#[EffectOperation('blur', params: array('$radius', '$sigma'))]
class Blur extends EffectBase {
  /**
   * {@inheritdoc}
   * @param array $data
   */
  public function settingsForm(array $data): array {
    $form['radius'] = array(
      '#type' => 'number',
      '#title' => t('Radius'),
      '#description' => t('This value should typically be either 0, to let the effect choose the best value, or twice the sigma value.'),
      '#default_value' => $data['radius'] ?? $this->defaultSettingValue('radius'),
      '#required' => TRUE,
      '#min' => 0.0,
      '#max' => 65355.0,
      '#step' => 0.5,
    );
    $form['sigma'] = array(
      '#type' => 'number',
      '#title' => t('Sigma'),
      '#description' => t('A large sigma value and a smallish radius value will introduce artifacts in the resulting image; small sigma values are typically only used to fuzz lines and smooth edges on images for which no anti-aliasing was used.'),
      '#default_value' => $data['sigma'] ?? $this->defaultSettingValue('sigma'),
      '#required' => TRUE,
      '#min' => 0.0,
      '#max' => 65355.0,
      '#step' => 0.5,
    );

    return $form;
  }

}
