<?php
/**
 * @file
 * Contains DespeckleEffect.
 */

declare(strict_types=1);

/**
 * Image 'despeckle' effect class.
 */
#[DefaultSetting('radius', value: 0.0)]
#[OperationParams('despeckle', params: array('$radius'))]
class DespeckleEffect extends EffectBase {

  /**
   * {@inheritdoc}
   * @param array $data
   */
  public function settingsForm(array $data): array {
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
