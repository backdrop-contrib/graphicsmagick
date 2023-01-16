<?php
/**
 * @file
 * Theme functions for the GraphicsMagick Effects module.
 */

/**
 * Returns HTML for the summary of the image blur effect.
 *
 * @param array $variables
 *   An associative array containing:
 *   - data: The current configuration for the blur effect.
 *
 * @ingroup themeable
 */
function theme_graphicsmagick_effects_blur_summary(array $variables) {
  $data = $variables['data'];
  $summary = '';

  if ($data['radius']) {
    $summary = t('radius @radius', ['@radius' => $data['radius']]);
  }
  if ($data['sigma']) {
    $summary .= ' ' . t('sigma @sigma', ['@sigma' => $data['sigma']]);
  }

  return $summary;
}

/**
 * Returns HTML for the summary of the image emboss effect.
 *
 * @param array $variables
 *   An associative array containing:
 *   - data: The current configuration for the emboss effect.
 *
 * @ingroup themeable
 */
function theme_graphicsmagick_effects_emboss_summary(array $variables) {
  return theme('graphicsmagick_effects_blur_summary', $variables);
}

/**
 * Returns HTML for the summary of the image gamma effect.
 *
 * @param array $variables
 *   An associative array containing:
 *   - data: The current configuration for the gamma effect.
 *
 * @ingroup themeable
 */
function theme_graphicsmagick_effects_gamma_summary(array $variables) {
  $data = $variables['data'];
  $summary = '';

  if ($data['gamma']) {
    $summary = t('gamma @gamma', ['@gamma' => $data['gamma']]);
  }

  return $summary;
}

/**
 * Returns HTML for the summary of the image oil paint effect.
 *
 * @param array $variables
 *   An associative array containing:
 *   - data: The current configuration for the oil paint effect.
 *
 * @ingroup themeable
 */
function theme_graphicsmagick_effects_oil_paint_summary(array $variables) {
  $data = $variables['data'];
  $summary = '';

  if ($data['radius']) {
    $summary = t('radius @radius', ['@radius' => $data['radius']]);
  }

  return $summary;
}

/**
 * Returns HTML for the summary of the image solarize effect.
 *
 * @param array $variables
 *   An associative array containing:
 *   - data: The current configuration for the solarize effect.
 *
 * @ingroup themeable
 */
function theme_graphicsmagick_effects_solarize_summary(array $variables) {
  $data = $variables['data'];
  $summary = '';

  if ($data['radius']) {
    $summary = t('level @level', ['@level' => $data['level']]);
  }

  return $summary;
}

/**
 * Returns HTML for the summary of the image spread effect.
 *
 * @param array $variables
 *   An associative array containing:
 *   - data: The current configuration for the spread effect.
 *
 * @ingroup themeable
 */
function theme_graphicsmagick_effects_spread_summary(array $variables) {
  return theme('graphicsmagick_effects_oil_paint_summary', $variables);
}

/**
 * Returns HTML for the summary of the image swirl effect.
 *
 * @param array $variables
 *   An associative array containing:
 *   - data: The current configuration for the swirl effect.
 *
 * @ingroup themeable
 */
function theme_graphicsmagick_effects_swirl_summary(array $variables) {
  $data = $variables['data'];
  $summary = '';

  if ($data['degrees']) {
    $summary = t('degrees @degrees', ['@degrees' => $data['degrees']]);
  }

  return $summary;
}