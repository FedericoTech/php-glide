--TEST--
GrVertex uninitialized property access
--FILE--
<?php
$vertex = new GrVertex;

var_dump($vertex->x);
?>
--EXPECTF--
Fatal error: Uncaught Error: Typed property GrVertex::$x must not be accessed before initialization in %s:%d
Stack trace:
#0 {main}
  thrown in %s on line %d