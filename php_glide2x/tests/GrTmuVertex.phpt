--TEST--
GrTmuVertex
--FILE--
<?php
grGlideInit();

echo 'we create an empty object' . PHP_EOL;
$grtv = new GrTmuVertex;
$grtv->flush();

var_dump($grtv);
testGrTmuVertex($grtv);

echo 'we clone the empty object' . PHP_EOL;

$grtv2 = clone $grtv;
var_dump(
	$grtv2,
	$grtv == $grtv2,
	$grtv === $grtv2,
);
testGrTmuVertex($grtv2);

echo 'we set values in the original object' . PHP_EOL;
$grtv->sow = '1';
$grtv->tow = 2;
$grtv->oow = 3;
$grtv->flush();

var_dump($grtv);
testGrTmuVertex($grtv);

echo 'we set values in the cloned object' . PHP_EOL;
$grtv2->sow = '1.1';
$grtv2->tow = 2.2;
$grtv2->oow = 3.3;
$grtv2->flush();

var_dump($grtv2);
testGrTmuVertex($grtv2);

echo 'we clone the cloned object' . PHP_EOL;
$grtv3 = clone $grtv2;
var_dump(
	$grtv3,
	$grtv3 == $grtv2,
	$grtv3 === $grtv2
);
testGrTmuVertex($grtv3);

echo 'we modify the cloned cloned object' . PHP_EOL;
$grtv3->sow = '2.2';
$grtv3->tow = 3.3;
$grtv3->oow = 4.4;
$grtv3->flush();
var_dump($grtv3);
testGrTmuVertex($grtv3);

echo 'now copy on wirte' . PHP_EOL;
$grtv4 = $grtv5 = $grtv3;

echo '$grtv4:' . PHP_EOL;
var_dump($grtv4);
testGrTmuVertex($grtv4);

echo '$grtv5' . PHP_EOL;
var_dump($grtv5);
testGrTmuVertex($grtv5);

echo 'list $grtv5 properties' . PHP_EOL;
foreach (get_object_vars($grtv5) as $f => $v) {
    echo "{$f}: {$v}\n";
}

echo 'is the class final?' . PHP_EOL;
$reflection = new ReflectionClass(GrTmuVertex::class);
var_dump(
	$reflection->isInternal(),
	$reflection->isFinal()
);

grGlideShutdown();

echo 'done';
?>
--EXPECT--
we create an empty object
object(GrTmuVertex)#1 (0) {
  ["sow"]=>
  uninitialized(float)
  ["tow"]=>
  uninitialized(float)
  ["oow"]=>
  uninitialized(float)
}
sow: nan, tow: nan, oow: nan
we clone the empty object
object(GrTmuVertex)#2 (0) {
  ["sow"]=>
  uninitialized(float)
  ["tow"]=>
  uninitialized(float)
  ["oow"]=>
  uninitialized(float)
}
bool(true)
bool(false)
sow: nan, tow: nan, oow: nan
we set values in the original object
object(GrTmuVertex)#1 (3) {
  ["sow"]=>
  float(1)
  ["tow"]=>
  float(2)
  ["oow"]=>
  float(3)
}
sow: 1.000000, tow: 2.000000, oow: 3.000000
we set values in the cloned object
object(GrTmuVertex)#2 (3) {
  ["sow"]=>
  float(1.1)
  ["tow"]=>
  float(2.2)
  ["oow"]=>
  float(3.3)
}
sow: 1.100000, tow: 2.200000, oow: 3.300000
we clone the cloned object
object(GrTmuVertex)#3 (3) {
  ["sow"]=>
  float(1.1)
  ["tow"]=>
  float(2.2)
  ["oow"]=>
  float(3.3)
}
bool(true)
bool(false)
sow: 1.100000, tow: 2.200000, oow: 3.300000
we modify the cloned cloned object
object(GrTmuVertex)#3 (3) {
  ["sow"]=>
  float(2.2)
  ["tow"]=>
  float(3.3)
  ["oow"]=>
  float(4.4)
}
sow: 2.200000, tow: 3.300000, oow: 4.400000
now copy on wirte
$grtv4:
object(GrTmuVertex)#3 (3) {
  ["sow"]=>
  float(2.2)
  ["tow"]=>
  float(3.3)
  ["oow"]=>
  float(4.4)
}
sow: 2.200000, tow: 3.300000, oow: 4.400000
$grtv5
object(GrTmuVertex)#3 (3) {
  ["sow"]=>
  float(2.2)
  ["tow"]=>
  float(3.3)
  ["oow"]=>
  float(4.4)
}
sow: 2.200000, tow: 3.300000, oow: 4.400000
list $grtv5 properties
sow: 2.2
tow: 3.3
oow: 4.4
is the class final?
bool(true)
bool(true)
done