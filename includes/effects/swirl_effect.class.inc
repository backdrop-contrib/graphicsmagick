<?php

namespace graphicsmagick\Effect;

use graphicsmagick\Attribute\DefaultSetting;
use graphicsmagick\Attribute\EffectOperation;

/**
 * Image 'swirl' effect class.
 */
#[DefaultSetting('degrees', value: 10.0)]
#[EffectOperation('swirl', params: array('$degrees'))]
class SwirlEffect extends EffectBase {

  /**
   * {@inheritdoc}
   */
  public function settingsForm(): array {
    $form['degrees'] = array(
      '#type' => 'number',
      '#title' => t('Degrees'),
      '#description' => t('The sweep of the arc through which each pixel is moved.'),
      '#default_value' => $data['degrees'] ?? $this->defaultSettingValue('degrees'),
      '#required' => TRUE,
      '#min' => 0.0,
      '#max' => 360.0,
      '#step' => 2.0,
    );

    return $form;
  }

}
