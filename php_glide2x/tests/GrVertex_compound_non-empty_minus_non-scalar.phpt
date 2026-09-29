--TEST--
GrVertex compound non-empty vertex minus non-scalar
--FILE--
<?php
$vertex = new GrVertex;

$vertex->x = 1;
$vertex->y = 1.0;
$vertex->z = '1';
$vertex->r = '1.0';
$vertex->g = 1;
$vertex->b = 1.0;
$vertex->ooz = '1';
$vertex->a = '1.0';
$vertex->oow = 1;

$vertex -= 'hello world';
?>
--EXPECTF--
Fatal error: Uncaught Exception: The scalar must be a number %s
Stack trace:
#0 {main}
  thrown in %s on line %d