--TEST--
GrTmuVertex property compound
--FILE--
<?php
$grtv = new GrTmuVertex;

$grtv->sow = '1';
$grtv->tow = 2;
$grtv->oow = 3.0;

var_dump($grtv);
print_r($grtv);
testGrTmuVertex($grtv);

echo 'post-increment' . PHP_EOL;
$grtv->sow++;
$grtv->tow++;
$grtv->oow++;

var_dump($grtv);
print_r($grtv);
testGrTmuVertex($grtv);

echo 'addition assignment' . PHP_EOL;
$grtv->sow += 2;
$grtv->tow += 2;
$grtv->oow += 2;

var_dump($grtv);
print_r($grtv);
testGrTmuVertex($grtv);

echo 'Pre-increment' . PHP_EOL;
++$grtv->sow;
++$grtv->tow;
++$grtv->oow;

var_dump($grtv);
print_r($grtv);
testGrTmuVertex($grtv);

echo 're-assign a value to unflag the property in the mask' . PHP_EOL;

$grtv->tow = 8;

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
post-increment
object(GrTmuVertex)#1 (3) {
  ["sow"]=>
  float(2)
  ["tow"]=>
  float(3)
  ["oow"]=>
  float(4)
}
GrTmuVertex Object
(
    [sow] => 2
    [tow] => 3
    [oow] => 4
)
referenced_mask: 7
sow: 2.000000, tow: 3.000000, oow: 4.000000
addition assignment
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
referenced_mask: 7
sow: 4.000000, tow: 5.000000, oow: 6.000000
Pre-increment
object(GrTmuVertex)#1 (3) {
  ["sow"]=>
  float(5)
  ["tow"]=>
  float(6)
  ["oow"]=>
  float(7)
}
GrTmuVertex Object
(
    [sow] => 5
    [tow] => 6
    [oow] => 7
)
referenced_mask: 7
sow: 5.000000, tow: 6.000000, oow: 7.000000
re-assign a value to unflag the property in the mask
object(GrTmuVertex)#1 (3) {
  ["sow"]=>
  float(5)
  ["tow"]=>
  float(8)
  ["oow"]=>
  float(7)
}
GrTmuVertex Object
(
    [sow] => 5
    [tow] => 8
    [oow] => 7
)
referenced_mask: 5
sow: 5.000000, tow: 8.000000, oow: 7.000000