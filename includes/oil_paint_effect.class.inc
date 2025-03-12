<?php
/**
 * @file
 * Contains OilPaintEffect.
 */

declare(strict_types=1);

/**
 * Image 'oil_paint' effect class.
 */
#[DefaultSetting('radius', value: 0.8)]
#[OperationParams('radius', params: array('$radius'))]
class OilPaintEffect extends EffectBase {

  /**
   * {@inheritdoc}
   * @param array $data
   */
  public function settingsForm(array $data): array {
    $form['radius'] = array(
      '#type' => 'number',
      '#title' => t('Radius'),
      '#description' => t('Each pixel is replaced by the most frequent color occurring in a circular region defined by the radius value.'),
      '#default_value' => $data['radius'] ?? $this->defaultSettingValue('radius'),
      '#required' => TRUE,
      '#min' => 0.6,
      '#max' => 50.0,
      '#step' => 0.2,
    );

    return $form;
  }

}
