--TEST--
GrVertex property chain assigment
--FILE--
<?php
$grtv = new GrTmuVertex;

$grtv->sow = $grtv->tow = $grtv->oow = 1.3;

var_dump(
    $grtv->sow,
    $grtv->tow,
    $grtv->oow
);

var_dump($grtv);
print_r($grtv);
testGrTmuVertex($grtv);

//we repeat the assignment
$grtv->sow = $grtv->tow = $grtv->oow = '2.6';

var_dump(
    $grtv->sow,
    $grtv->tow,
    $grtv->oow
);

var_dump($grtv);
print_r($grtv);
testGrTmuVertex($grtv);
?>
--EXPECT--
float(1.3)
float(1.3)
float(1.3)
object(GrTmuVertex)#1 (3) {
  ["sow"]=>
  float(1.3)
  ["tow"]=>
  float(1.3)
  ["oow"]=>
  float(1.3)
}
GrTmuVertex Object
(
    [sow] => 1.3
    [tow] => 1.3
    [oow] => 1.3
)
referenced_mask: 0
sow: 1.300000, tow: 1.300000, oow: 1.300000
float(2.6)
float(2.6)
float(2.6)
object(GrTmuVertex)#1 (3) {
  ["sow"]=>
  float(2.6)
  ["tow"]=>
  float(2.6)
  ["oow"]=>
  float(2.6)
}
GrTmuVertex Object
(
    [sow] => 2.6
    [tow] => 2.6
    [oow] => 2.6
)
referenced_mask: 0
sow: 2.600000, tow: 2.600000, oow: 2.600000