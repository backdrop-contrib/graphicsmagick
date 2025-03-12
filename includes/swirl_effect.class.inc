<?php
/**
 * @file
 * Contains SwirlEffect.
 */

declare(strict_types=1);

/**
 * Image 'swirl' effect class.
 */
#[DefaultSetting('degrees', value: 10.0)]
#[OperationParams('swirl', params: array('$degrees'))]
class SwirlEffect extends EffectBase {

  /**
   * {@inheritdoc}
   * @param array $data
   */
  public function settingsForm(array $data): array {
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
