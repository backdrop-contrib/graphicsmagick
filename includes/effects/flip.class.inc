<?php
/**
 * @file
 * Contains \graphicsmagick\Effect\Flip.
 */

declare(strict_types=1);

namespace graphicsmagick\Effect;

use graphicsmagick\Attribute\EffectOperation;
use graphicsmagick\EffectBase;

/**
 * Image 'flip' effect class.
 */
#[EffectOperation('flip')]
class Flip extends EffectBase {}
