<?php

namespace graphicsmagick\Effect;

use graphicsmagick\Attribute\EffectOperation;
use graphicsmagick\Attribute\DefaultSetting;

/**
 * Image 'despeckle' effect class.
 */
#[DefaultSetting('radius', value: 0.0)]
#[EffectOperation('despeckle', params: array('$radius'))]
class DespeckleEffect extends EffectBase {

  /**
   * {@inheritdoc}
   */
  public function settingsForm(): array {
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

    return $form;
  }

}
