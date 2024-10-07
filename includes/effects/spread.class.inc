<?php
/**
 * @file
 * Contains \graphicsmagick\Effect\Spread.
 */

declare(strict_types=1);

namespace graphicsmagick\Effect;

use graphicsmagick\Attribute\DefaultSetting;
use graphicsmagick\Attribute\EffectOperation;
use graphicsmagick\EffectBase;

/**
 * Image 'spread' effect class.
 */
#[DefaultSetting('radius', value: 2.0)]
#[EffectOperation('spread', params: array('$radius'))]
class Spread extends EffectBase {

  /**
   * {@inheritdoc}
   * @param array $data
   */
  public function settingsForm(array $data): array {
    $form['radius'] = array(
      '#type' => 'number',
      '#title' => t('Radius'),
      '#description' => t('The radius of the spread effect.'),
      '#default_value' => $data['radius'] ?? $this->defaultSettingValue('radius'),
      '#required' => TRUE,
      '#min' => 0.0,
      '#max' => 65355.0,
      '#step' => 0.5,
    );

    return $form;
  }

}
