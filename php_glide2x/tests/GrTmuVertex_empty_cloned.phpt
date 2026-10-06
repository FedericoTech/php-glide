--TEST--
GrTmuVertex cloned empty
--FILE--
<?php
$grtv = new GrTmuVertex;
$grtv2 = clone $grtv;

var_dump($grtv2);
print_r($grtv2);
testGrTmuVertex($grtv2);
var_dump(
    $grtv2 == $grtv,
    $grtv2 === $grtv
);
?>
--EXPECT--
object(GrTmuVertex)#2 (0) {
  ["sow"]=>
  uninitialized(float)
  ["tow"]=>
  uninitialized(float)
  ["oow"]=>
  uninitialized(float)
}
GrTmuVertex Object
(
)
referenced_mask: 0
sow: 0.000000, tow: 0.000000, oow: 0.000000
bool(true)
bool(false)