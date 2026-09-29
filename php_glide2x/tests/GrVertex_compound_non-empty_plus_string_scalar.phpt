--TEST--
GrVertex compound non-empty vertex plus float scalar
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

$vertex += '3.0';

var_dump($vertex);
print_r($vertex);
testGrVertex($vertex);
?>
--EXPECT--
object(GrVertex)#1 (10) {
  ["x"]=>
  float(4)
  ["y"]=>
  float(4)
  ["z"]=>
  float(4)
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
    [x] => 4
    [y] => 4
    [z] => 4
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
x: 4.000000, y: 4.000000, z: 4.000000, r: 1.000000, g: 1.000000, b: 1.000000, ooz: 1.000000, a: 1.000000, oow: 1.000000
[0] sow: 0.000000, tow: 0.000000, oow: 0.000000
[1] sow: 0.000000, tow: 0.000000, oow: 0.000000