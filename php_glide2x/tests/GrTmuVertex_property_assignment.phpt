--TEST--
GrTmuVertex property assigment
--FILE--
<?php
$grtv = new GrTmuVertex;

$grtv->sow = '1';
$grtv->tow = 2;
$grtv->oow = 3.0;

var_dump($grtv);
print_r($grtv);
testGrTmuVertex($grtv);

//we repeat the assignment

$grtv->sow = '4';
$grtv->tow = 5;
$grtv->oow = 6.0;

var_dump($grtv);
print_r($grtv);
testGrTmuVertex($grtv);
?>
--EXPECT--
object(GrTmuVertex)#1 (3) {
  ["sow"]=>
  float(1)
  ["tow"]=>
  float(2)
  ["oow"]=>
  float(3)
}
GrTmuVertex Object
(
    [sow] => 1
    [tow] => 2
    [oow] => 3
)
referenced_mask: 0
sow: 1.000000, tow: 2.000000, oow: 3.000000
object(GrTmuVertex)#1 (3) {
  ["sow"]=>
  float(4)
  ["tow"]=>
  float(5)
  ["oow"]=>
  float(6)
}
GrTmuVertex Object
(
    [sow] => 4
    [tow] => 5
    [oow] => 6
)
referenced_mask: 0
sow: 4.000000, tow: 5.000000, oow: 6.000000