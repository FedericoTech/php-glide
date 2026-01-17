--TEST--
GrVertex non-empty vertex multiplied by non-empty vertex
--FILE--
<?php
$vertex = new GrVertex;

$vertex->x = 1;
$vertex->y = 1.0;
$vertex->z = '1';
$vertex->r = '1.0';
$vertex->g = 1;
$vertex->b = 1.0;
$vertex->ooz = '1';
$vertex->a = '1.0';
$vertex->oow = 1;

$vertex2 = new GrVertex;

$vertex2->x = 2;
$vertex2->y = 2.0;
$vertex2->z = '2';
$vertex2->r = '2.0';
$vertex2->g = 2;
$vertex2->b = 2.0;
$vertex2->ooz = '2';
$vertex2->a = '2.0';
$vertex2->oow = 2;

$vertex3 = $vertex * $vertex2;

var_dump($vertex3);
print_r($vertex3);
testGrVertex($vertex3);
var_dump($vertex2 == $vertex3);
var_dump($vertex2 === $vertex3);
?>
--EXPECT--
object(GrVertex)#9 (10) {
  ["x"]=>
  float(2)
  ["y"]=>
  float(2)
  ["z"]=>
  float(2)
  ["r"]=>
  float(1)
  ["g"]=>
  float(1)
  ["b"]=>
  float(1)
  ["ooz"]=>
  float(1)
  ["a"]=>
  float(1)
  ["oow"]=>
  float(1)
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
    [x] => 2
    [y] => 2
    [z] => 2
    [r] => 1
    [g] => 1
    [b] => 1
    [ooz] => 1
    [a] => 1
    [oow] => 1
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
x: 2.000000, y: 2.000000, z: 2.000000, r: 1.000000, g: 1.000000, b: 1.000000, ooz: 1.000000, a: 1.000000, oow: 1.000000
[0] sow: 0.000000, tow: 0.000000, oow: 0.000000
[1] sow: 0.000000, tow: 0.000000, oow: 0.000000
bool(false)
bool(false)