--TEST--
GrVertex uninitialized property access
--FILE--
<?php
$grtv = new GrTmuVertex;

var_dump($grtv->sow);
?>
--EXPECTF--
Fatal error: Uncaught Error: Typed property GrTmuVertex::$sow must not be accessed before initialization in %s:%d
Stack trace:
#0 {main}
  thrown in %s on line %d