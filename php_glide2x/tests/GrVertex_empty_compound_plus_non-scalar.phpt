--TEST--
GrVertex empty vertex compound plus non-scalar
--FILE--
<?php
$vertex = new GrVertex;

$vertex += 'hello world';
?>
--EXPECTF--
Fatal error: Uncaught Exception: The scalar must be a number %s
Stack trace:
#0 {main}
  thrown in %s on line %d