<?php
/**
 * @file
 * Contains \graphicsmagick\Attribute\DefaultSetting.
 */

declare(strict_types=1);

namespace graphicsmagick\Attribute;

/**
 * Implements the attribute class for the default settings.
 */
#[\Attribute(\Attribute::TARGET_CLASS | \Attribute::IS_REPEATABLE)]
class DefaultSetting {

  public function __construct(
    public string $id,
    public mixed $value,
  ) {}

}
