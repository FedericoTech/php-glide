--TEST--
GrVertex sub left handside float scalar to empty
--FILE--
<?php
$vertex = new GrVertex;

$vertex2 = 2.0 - $vertex;

var_dump($vertex2);
testGrVertex($vertex2);
?>
--EXPECT--
object(GrVertex)#5 (4) {
  ["x"]=>
  float(2)
  ["y"]=>
  float(2)
  ["z"]=>
  float(2)
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
x: 2.000000, y: 2.000000, z: 2.000000, r: 0.000000, g: 0.000000, b: 0.000000, ooz: 0.000000, a: 0.000000, oow: 0.000000
[0] sow: 0.000000, tow: 0.000000, oow: 0.000000
[1] sow: 0.000000, tow: 0.000000, oow: 0.000000