--TEST--
GrVertex reference property denied
--FILE--
<?php
$vertex = new GrVertex;

$vertex->x = 1;

$ref =& $vertex->x;
?>
--EXPECTF--
Warning: Cannot take reference to property GrVertex::x in this context in %s on line %d