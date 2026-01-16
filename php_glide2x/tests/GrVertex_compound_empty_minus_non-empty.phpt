--TEST--
GrVertex compound empty vertex minus non-empty vertex
--FILE--
<?php
$vertex = new GrVertex;

$vertex2 = new GrVertex;
$vertex2->x = 1;
$vertex2->y = 1.0;
$vertex2->z = '1';
$vertex2->r = '1.0';
$vertex2->g = 1;
$vertex2->b = 1.0;
$vertex2->ooz = '1';
$vertex2->a = '1.0';
$vertex2->oow = 1;

//they were equial though not the same
var_dump($vertex == $vertex2);
var_dump($vertex === $vertex2);

$vertex -= $vertex2;

//now they are completely different
var_dump($vertex == $vertex2);
var_dump($vertex === $vertex2);

var_dump($vertex);
print_r($vertex);
testGrVertex($vertex);
?>
--EXPECT--
bool(false)
bool(false)
bool(false)
bool(false)
object(GrVertex)#1 (4) {
  ["x"]=>
  float(-1)
  ["y"]=>
  float(-1)
  ["z"]=>
  float(-1)
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
    [x] => -1
    [y] => -1
    [z] => -1
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
x: -1.000000, y: -1.000000, z: -1.000000, r: 0.000000, g: 0.000000, b: 0.000000, ooz: 0.000000, a: 0.000000, oow: 0.000000
[0] sow: 0.000000, tow: 0.000000, oow: 0.000000
[1] sow: 0.000000, tow: 0.000000, oow: 0.000000