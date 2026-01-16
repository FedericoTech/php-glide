--TEST--
GrVertex compound non-empty vertex multiplied by non-empty vertex
--FILE--
<?php
$vertex = new GrVertex;
$vertex->x = 3;
$vertex->y = 3.0;
$vertex->z = '3';
$vertex->r = '3.0';
$vertex->g = 3;
$vertex->b = 3.0;
$vertex->ooz = '3';
$vertex->a = '3.0';
$vertex->oow = 3;

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

var_dump($vertex == $vertex2);
var_dump($vertex === $vertex2);

$vertex *= $vertex2;

var_dump($vertex);
print_r($vertex);
testGrVertex($vertex);
var_dump($vertex == $vertex2);
var_dump($vertex === $vertex2);
?>
--EXPECT--
bool(false)
bool(false)
object(GrVertex)#1 (10) {
  ["x"]=>
  float(6)
  ["y"]=>
  float(6)
  ["z"]=>
  float(6)
  ["r"]=>
  float(3)
  ["g"]=>
  float(3)
  ["b"]=>
  float(3)
  ["ooz"]=>
  float(3)
  ["a"]=>
  float(3)
  ["oow"]=>
  float(3)
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
    [x] => 6
    [y] => 6
    [z] => 6
    [r] => 3
    [g] => 3
    [b] => 3
    [ooz] => 3
    [a] => 3
    [oow] => 3
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
x: 6.000000, y: 6.000000, z: 6.000000, r: 3.000000, g: 3.000000, b: 3.000000, ooz: 3.000000, a: 3.000000, oow: 3.000000
[0] sow: 0.000000, tow: 0.000000, oow: 0.000000
[1] sow: 0.000000, tow: 0.000000, oow: 0.000000
bool(false)
bool(false)