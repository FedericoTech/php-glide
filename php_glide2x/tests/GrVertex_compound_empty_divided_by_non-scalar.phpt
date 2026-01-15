--TEST--
GrVertex compound empty vertex divided by string scalar
--FILE--
<?php
$vertex = new GrVertex;

$vertex /= 'hello world';
?>
--EXPECTF--
Fatal error: Uncaught Exception: The scalar must be a number %s
Stack trace:
#0 {main}
  thrown in %s on line %d