<?php
/**
 * @file
 * Contains \graphicsmagick\Attribute\EffectOperation.
 */

declare(strict_types=1);

namespace graphicsmagick\Attribute;

/**
 * Implements the attribute class for the effect operations.
 */
#[\Attribute(\Attribute::TARGET_CLASS | \Attribute::IS_REPEATABLE)]
class EffectOperation {

  public function __construct(
    public string $operation,
    public array $params = array(),
  ) {}

}
