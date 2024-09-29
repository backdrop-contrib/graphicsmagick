<?php

namespace graphicsmagick\Effect;

use graphicsmagick\Attribute\DefaultSetting;
use graphicsmagick\Attribute\EffectOperation;
use graphicsmagick\ToolkitInfo;

/**
 * Image 'solarize' effect class.
 */
#[DefaultSetting('level', value: 8)]
#[EffectOperation('level', params: array('$level'))]
class SolarizeEffect extends EffectBase {

  /**
   * {@inheritdoc}
   */
  public function settingsForm(): array {
    try {
      $toolkit_info = new ToolkitInfo();
      $quantum_level = $toolkit_info->getQuantumLevel();
    }
    catch (\RuntimeException) {
      // As getting the quantum dept value failed, assume its value is 8.
      $quantum_level = 8;
    }

    $form['level'] = array(
      '#type' => 'number',
      '#title' => t('Level'),
      '#description' => t('The effect level.'),
      '#default_value' => $data['level'] ?? 1 << (($quantum_level / 2) - 2),
      '#required' => TRUE,
      '#min' => 0,
      '#max' => 1 << $quantum_level,
      '#step' => 1,
    );

    return $form;
  }

}
