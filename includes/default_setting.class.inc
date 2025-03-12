<?php
/**
 * @file
 * Contains DefaultSetting.
 */

declare(strict_types=1);

/**
 * Implements the attribute class for the default settings.
 */
#[Attribute(Attribute::TARGET_CLASS | Attribute::IS_REPEATABLE)]
class DefaultSetting {

  public function __construct(
    public string $id,
    public mixed $value,
  ) {}

}
