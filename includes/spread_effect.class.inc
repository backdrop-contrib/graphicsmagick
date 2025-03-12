<?php
/**
 * @file
 * Contains SpreadEffect.
 */

declare(strict_types=1);

/**
 * Image 'spread' effect class.
 */
#[DefaultSetting('radius', value: 2.0)]
#[OperationParams('spread', params: array('$radius'))]
class SpreadEffect extends EffectBase {

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
