<?php

namespace graphicsmagick\Attribute;

#[\Attribute(\Attribute::TARGET_CLASS | \Attribute::IS_REPEATABLE)]
class DefaultSetting {

  public function __construct(
    public string $id,
    public mixed $value,
  ) {}

}
