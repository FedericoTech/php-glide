--TEST--
GrVertex undefined property access
--FILE--
<?php
$vertex = new GrVertex;

var_dump($vertex->missing);
?>
--EXPECTF--
Warning: Undefined property: GrVertex::$missing in %s on line %d
NULL