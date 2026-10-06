--TEST--
GrTmuVertex property references
--FILE--
<?php
$grtv1 = new GrTmuVertex;
$grtv2 = new GrTmuVertex;

$grtv1->sow = 2;
$grtv1->tow =& $grtv1->sow;
$grtv2->oow =& $grtv1->tow;

$ref = 3;
$ref =& $grtv2->oow;

$grtv3 = clone $grtv2;

$ref = 10;

var_dump($ref);

var_dump($grtv1);
print_r($grtv1);
testGrTmuVertex($grtv1);

var_dump($grtv2);
print_r($grtv2);
testGrTmuVertex($grtv2);

var_dump($grtv3);
print_r($grtv3);
testGrTmuVertex($grtv3);
?>
--EXPECT--
float(10)
object(GrTmuVertex)#1 (2) {
  ["sow"]=>
  &float(10)
  ["tow"]=>
  &float(10)
  ["oow"]=>
  uninitialized(float)
}
GrTmuVertex Object
(
    [sow] => 10
    [tow] => 10
)
referenced_mask: 3
sow: 10.000000, tow: 10.000000, oow: 0.000000
object(GrTmuVertex)#2 (1) {
  ["sow"]=>
  uninitialized(float)
  ["tow"]=>
  uninitialized(float)
  ["oow"]=>
  &float(10)
}
GrTmuVertex Object
(
    [oow] => 10
)
referenced_mask: 4
sow: 0.000000, tow: 0.000000, oow: 10.000000
object(GrTmuVertex)#3 (1) {
  ["sow"]=>
  uninitialized(float)
  ["tow"]=>
  uninitialized(float)
  ["oow"]=>
  &float(10)
}
GrTmuVertex Object
(
    [oow] => 10
)
referenced_mask: 4
sow: 0.000000, tow: 0.000000, oow: 10.000000