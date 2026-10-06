--TEST--
GrTmuVertex property write and read
--FILE--
<?php
$grtv = new GrTmuVertex;

$grtv->sow = 1;
$grtv->tow = 2.0;
$grtv->oow = '3';

var_dump($grtv);
print_r($grtv);
testGrTmuVertex($grtv);

var_dump($grtv->sow);
echo $grtv->sow . PHP_EOL;
var_dump($grtv->tow);
echo $grtv->tow . PHP_EOL;
var_dump($grtv->oow);
echo $grtv->oow . PHP_EOL;

$grtv->sow = 2;
$grtv->tow = 4.0;
$grtv->oow = '6';

var_dump($grtv->sow);
echo $grtv->sow . PHP_EOL;
var_dump($grtv->tow);
echo $grtv->tow . PHP_EOL;
var_dump($grtv->oow);
echo $grtv->oow . PHP_EOL;

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
float(1)
1
float(2)
2
float(3)
3
float(2)
2
float(4)
4
float(6)
6
object(GrTmuVertex)#1 (3) {
  ["sow"]=>
  float(2)
  ["tow"]=>
  float(4)
  ["oow"]=>
  float(6)
}
GrTmuVertex Object
(
    [sow] => 2
    [tow] => 4
    [oow] => 6
)
referenced_mask: 0
sow: 2.000000, tow: 4.000000, oow: 6.000000