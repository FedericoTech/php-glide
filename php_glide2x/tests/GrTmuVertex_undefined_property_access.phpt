--TEST--
GrVertex undefined property access
--FILE--
<?php
$grtv = new GrTmuVertex;

var_dump($grtv->missing);
?>
--EXPECTF--
Warning: Undefined property: GrTmuVertex::$missing in %s on line %d
NULL