--TEST--
GrVertex empty vertex divided by non-empty vertex
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

$vertex3 = $vertex / $vertex2;

var_dump($vertex3);
print_r($vertex3);
testGrVertex($vertex3);
?>
--EXPECT--
object(GrVertex)#9 (4) {
  ["x"]=>
  float(0)
  ["y"]=>
  float(0)
  ["z"]=>
  float(0)
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
    [x] => 0
    [y] => 0
    [z] => 0
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
x: 0.000000, y: 0.000000, z: 0.000000, r: 0.000000, g: 0.000000, b: 0.000000, ooz: 0.000000, a: 0.000000, oow: 0.000000
[0] sow: 0.000000, tow: 0.000000, oow: 0.000000
[1] sow: 0.000000, tow: 0.000000, oow: 0.000000