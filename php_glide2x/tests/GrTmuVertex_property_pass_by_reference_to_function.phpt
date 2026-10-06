--TEST--
GrTmuVertex property pass by reference to function
--FILE--
<?php

function &takes_ref(&$v) {
    $v = 42;

	return $v;
}

$grtv = new GrTmuVertex;

$grtv->sow = 3;

$v = takes_ref($grtv->sow);

var_dump($v);

var_dump($grtv);
print_r($grtv);
testGrTmuVertex($grtv);
?>
--EXPECT--
float(42)
object(GrTmuVertex)#1 (1) {
  ["sow"]=>
  float(42)
  ["tow"]=>
  uninitialized(float)
  ["oow"]=>
  uninitialized(float)
}
GrTmuVertex Object
(
    [sow] => 42
)
referenced_mask: 1
sow: 42.000000, tow: 0.000000, oow: 0.000000