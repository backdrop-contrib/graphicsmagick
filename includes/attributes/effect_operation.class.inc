<?php

namespace graphicsmagick\Attribute;

#[\Attribute(\Attribute::TARGET_CLASS | \Attribute::IS_REPEATABLE)]
class EffectOperation {

  public function __construct(
    public string $operation,
    public array $params = array(),
  ) {}

}
