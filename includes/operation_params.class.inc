<?php
/**
 * @file
 * Contains OperationParams.
 */

declare(strict_types=1);

/**
 * Implements the attribute class for the effect operations.
 */
#[Attribute(Attribute::TARGET_CLASS | Attribute::IS_REPEATABLE)]
class OperationParams {

  public function __construct(
    public string $operation,
    public array $params = array(),
  ) {}

}
