<?php
/**
 * @file
 * Contains \graphicsmagick\Effect\Noise.
 */

declare(strict_types=1);

namespace graphicsmagick\Effect;

use graphicsmagick\Attribute\DefaultSetting;
use graphicsmagick\Attribute\EffectOperation;
use graphicsmagick\EffectBase;
use graphicsmagick\ToolkitInfo;

/**
 * Image 'noise' effect class.
 */
#[DefaultSetting('noise', value: 'uniform')]
#[EffectOperation('noise', params: array('$noise'))]
class Noise extends EffectBase {

  /**
   * {@inheritdoc}
   * @param array $data
   */
  public function settingsForm(array $data): array {
    $form['noise'] = array(
      '#type' => 'select',
      '#title' => t('Noise type'),
      '#description' => t('The noise type changes for which pixels the color is randomly changed.'),
      '#options' => ToolkitInfo::noiseOptions(),
      '#default_value' => $data['noise'] ?? $this->defaultSettingValue('noise'),
      '#required' => TRUE,
    );

    return $form;
  }

}
