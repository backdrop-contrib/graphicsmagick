<?php

namespace graphicsmagick\Effect;

use graphicsmagick\Attribute\DefaultSetting;
use graphicsmagick\Attribute\EffectOperation;

/**
 * Image 'spread' effect class.
 */
#[DefaultSetting('radius', value: 2.0)]
#[EffectOperation('spread', params: array('$radius'))]
class SpreadEffect extends EffectBase {

  /**
   * {@inheritdoc}
   */
  public function settingsForm(): array {
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
