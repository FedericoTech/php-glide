--TEST--
GrVertex properties
--FILE--
<?php
$vertex = new GrVertex;

$vertex->x = 1;
$vertex->y = 2.0;
$vertex->z = '3';
$vertex->r = '4.0';
$vertex->g = 5;
$vertex->b = 6.0;
$vertex->ooz = '7';
$vertex->a = '8.0';
$vertex->oow = 9;


var_dump($vertex);
testGrVertex($vertex);
?>
--EXPECT--
object(GrVertex)#1 (10) {
  ["x"]=>
  float(1)
  ["y"]=>
  float(2)
  ["z"]=>
  float(3)
  ["r"]=>
  float(4)
  ["g"]=>
  float(5)
  ["b"]=>
  float(6)
  ["ooz"]=>
  float(7)
  ["a"]=>
  float(8)
  ["oow"]=>
  float(9)
  ["tmuvtx"]=>
  object(GrTmuVertices)#2 (2) {
    [0]=>
    object(GrTmuVertex)#3 (0) {
      ["sow"]=>
      uninitialized(float)
      ["tow"]=>
      uninitialized(float)
      ["oow"]=>
      uninitialized(float)
    }
    [1]=>
    object(GrTmuVertex)#4 (0) {
      ["sow"]=>
      uninitialized(float)
      ["tow"]=>
      uninitialized(float)
      ["oow"]=>
      uninitialized(float)
    }
  }
}
x: 1.000000, y: 2.000000, z: 3.000000, r: 4.000000, g: 5.000000, b: 6.000000, ooz: 7.000000, a: 8.000000, oow: 9.000000
[0] sow: 0.000000, tow: 0.000000, oow: 0.000000
[1] sow: 0.000000, tow: 0.000000, oow: 0.000000