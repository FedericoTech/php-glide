--TEST--
GrVertex non-scalar divided by empty vertex
--FILE--
<?php
$vertex = new GrVertex;

$vertex2 = 'hello world' / $vertex;
?>
--EXPECTF--
Fatal error: Uncaught Exception: The scalar must be a number %s
Stack trace:
#0 {main}
  thrown in %s on line %d