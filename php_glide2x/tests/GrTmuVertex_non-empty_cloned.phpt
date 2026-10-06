--TEST--
GrTmuVertex non-empty cloned
--FILE--
<?php
$grtv = new GrTmuVertex;

$grtv->sow = '1';
$grtv->tow = 2;
$grtv->oow = 3.0;

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
object(GrTmuVertex)#2 (3) {
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
bool(true)
bool(false)