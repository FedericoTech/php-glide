--TEST--
GrVertex property chain assigment
--FILE--
<?php
$vertex = new GrVertex;

$vertex->x = $vertex->y = $vertex->z = 1.3;

var_dump(
	$vertex->x,
	$vertex->y,
	$vertex->z
);

var_dump($vertex);
print_r($vertex);
testGrVertex($vertex);
?>
--EXPECT--
float(1.3)
float(1.3)
float(1.3)
object(GrVertex)#1 (4) {
  ["x"]=>
  float(1.3)
  ["y"]=>
  float(1.3)
  ["z"]=>
  float(1.3)
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
GrVertex Object
(
    [x] => 1.3
    [y] => 1.3
    [z] => 1.3
    [tmuvtx] => GrTmuVertices Object
        (
            [0] => GrTmuVertex Object
                (
                )

            [1] => GrTmuVertex Object
                (
                )

        )

)
x: 1.300000, y: 1.300000, z: 1.300000, r: 0.000000, g: 0.000000, b: 0.000000, ooz: 0.000000, a: 0.000000, oow: 0.000000
[0] sow: 0.000000, tow: 0.000000, oow: 0.000000
[1] sow: 0.000000, tow: 0.000000, oow: 0.000000