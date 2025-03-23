<?php
/**
 * @file
 * Contains OperationType.
 */

declare(strict_types=1);

/**
 * Implements the attribute class for the default settings.
 */
#[Attribute(Attribute::TARGET_CLASS)]
class OperationType {

  public function __construct(
    public string $type,
  ) {}

}
