--TEST--
GrTmuVertex empty
--FILE--
<?php
$grtv = new GrTmuVertex;
var_dump($grtv);
print_r($grtv);
testGrTmuVertex($grtv);
?>
--EXPECT--
object(GrTmuVertex)#1 (0) {
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