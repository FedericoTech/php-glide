--TEST--
GrVertex
--FILE--
<?php
grGlideInit();

$gtv = new GrTmuVertex;
$gtv->flush();

var_dump($gtv);
testGrTmuVertex($gtv);

echo PHP_EOL;

$gtv->sow = 0;
$gtv->tow = 0.1;
$gtv->oow = '0.2';
$gtv->flush();

var_dump($gtv);
testGrTmuVertex($gtv);

echo PHP_EOL;

$gtv2 = new GrTmuVertex;
$gtv2->sow = '0.3';
$gtv2->tow = 0.4;
$gtv2->oow = 0.5;


echo PHP_EOL;

$vertex = new GrVertex;

$vertex->flush();
var_dump($vertex);
testGrVertex($vertex);

echo PHP_EOL;

$vertex->x = 0;
$vertex->y = 0.1;
$vertex->z = 0.2;

$vertex->r = 0.3;
$vertex->g = 0.4;
$vertex->b = '0.5';

$vertex->ooz = 0.6;
$vertex->a = 0.7;
$vertex->oow = '0.8';

$gtv->flush();
$gtv2->flush();

$vertex->tmuvtx = [$gtv, $gtv2];
$vertex->flush();

var_dump($vertex);
testGrVertex($vertex);

echo PHP_EOL;

$reflection = new ReflectionClass(GrHwConfiguration::class);
var_dump(
	$reflection->isInternal(),
	$reflection->isFinal()
);

grGlideShutdown();
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
sow: 0.000000, tow: 0.000000, oow: 0.000000

object(GrTmuVertex)#1 (3) {
  ["sow"]=>
  float(0)
  ["tow"]=>
  float(0.1)
  ["oow"]=>
  float(0.2)
}
sow: 0.000000, tow: 0.100000, oow: 0.200000


object(GrVertex)#3 (0) {
  ["x"]=>
  uninitialized(float)
  ["y"]=>
  uninitialized(float)
  ["z"]=>
  uninitialized(float)
  ["r"]=>
  uninitialized(float)
  ["g"]=>
  uninitialized(float)
  ["b"]=>
  uninitialized(float)
  ["ooz"]=>
  uninitialized(float)
  ["a"]=>
  uninitialized(float)
  ["oow"]=>
  uninitialized(float)
  ["tmuvtx"]=>
  uninitialized(array)
}
x: 0.000000, y: 0.000000, z: 0.000000, r: 0.000000, g: 0.000000, b: 0.000000, ooz: 0.000000, a: 0.000000, oow: 0.000000
[0] sow: 0.000000, tow: 0.000000, oow: 0.000000
[1] sow: 0.000000, tow: 0.000000, oow: 0.000000

object(GrVertex)#3 (10) {
  ["x"]=>
  float(0)
  ["y"]=>
  float(0.1)
  ["z"]=>
  float(0.2)
  ["r"]=>
  float(0.3)
  ["g"]=>
  float(0.4)
  ["b"]=>
  float(0.5)
  ["ooz"]=>
  float(0.6)
  ["a"]=>
  float(0.7)
  ["oow"]=>
  float(0.8)
  ["tmuvtx"]=>
  array(2) {
    [0]=>
    object(GrTmuVertex)#1 (3) {
      ["sow"]=>
      float(0)
      ["tow"]=>
      float(0.1)
      ["oow"]=>
      float(0.2)
    }
    [1]=>
    object(GrTmuVertex)#2 (3) {
      ["sow"]=>
      float(0.3)
      ["tow"]=>
      float(0.4)
      ["oow"]=>
      float(0.5)
    }
  }
}
x: 0.000000, y: 0.100000, z: 0.200000, r: 0.300000, g: 0.400000, b: 0.500000, ooz: 0.600000, a: 0.700000, oow: 0.800000
[0] sow: 0.000000, tow: 0.100000, oow: 0.200000
[1] sow: 0.300000, tow: 0.400000, oow: 0.500000

bool(true)
bool(true)