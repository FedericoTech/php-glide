--TEST--
GrTmuVertex property chain assigment from different objects
--FILE--
<?php
$grtv1 = new GrTmuVertex;
$grtv2 = new GrTmuVertex;
$grtv3 = new GrTmuVertex;

$grtv1->sow = $grtv2->sow = $grtv3->sow = 1.3;

var_dump(
	$grtv1->sow,
	$grtv2->sow,
	$grtv3->sow
);

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
float(1.3)
float(1.3)
float(1.3)
object(GrTmuVertex)#1 (1) {
  ["sow"]=>
  float(1.3)
  ["tow"]=>
  uninitialized(float)
  ["oow"]=>
  uninitialized(float)
}
GrTmuVertex Object
(
    [sow] => 1.3
)
referenced_mask: 0
sow: 1.300000, tow: 0.000000, oow: 0.000000
object(GrTmuVertex)#2 (1) {
  ["sow"]=>
  float(1.3)
  ["tow"]=>
  uninitialized(float)
  ["oow"]=>
  uninitialized(float)
}
GrTmuVertex Object
(
    [sow] => 1.3
)
referenced_mask: 0
sow: 1.300000, tow: 0.000000, oow: 0.000000
object(GrTmuVertex)#3 (1) {
  ["sow"]=>
  float(1.3)
  ["tow"]=>
  uninitialized(float)
  ["oow"]=>
  uninitialized(float)
}
GrTmuVertex Object
(
    [sow] => 1.3
)
referenced_mask: 0
sow: 1.300000, tow: 0.000000, oow: 0.000000