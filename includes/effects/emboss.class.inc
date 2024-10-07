<?php
/**
 * @file
 * Contains \graphicsmagick\Effect\Emboss.
 */

declare(strict_types=1);

namespace graphicsmagick\Effect;

use graphicsmagick\Attribute\DefaultSetting;
use graphicsmagick\Attribute\EffectOperation;
use graphicsmagick\EffectBase;

/**
 * Image 'emboss' effect class.
 */
#[DefaultSetting('radius', value: 0.0)]
#[DefaultSetting('sigma', value: 1.0)]
#[EffectOperation('emboss', params: array('$radius', '$sigma'))]
class Emboss extends EffectBase {

  /**
   * {@inheritdoc}
   * @param array $data
   */
  public function settingsForm(array $data): array {
    $form['radius'] = array(
      '#type' => 'number',
      '#title' => t('Radius'),
      '#description' => t('For reasonable results, the radius value should be higher than the sigma value. Use a value of zero to let the effect choose the best value.'),
      '#default_value' => $data['radius'] ?? $this->defaultSettingValue('radius'),
      '#required' => TRUE,
      '#min' => 0.0,
      '#max' => 65355.0,
      '#step' => 0.5,
    );
    $form['sigma'] = array(
      '#type' => 'number',
      '#title' => t('Sigma'),
      '#description' => t('A large sigma value works well also with color image. It can remove color dominance, but it could also introduce artifacts, especially in JPEG images.'),
      '#default_value' => $data['sigma'] ?? $this->defaultSettingValue('sigma'),
      '#required' => TRUE,
      '#min' => 0.0,
      '#max' => 65355.0,
      '#step' => 0.5,
    );

    return $form;
  }

}
