--TEST--
GrVertex property gets referenced by a var
--FILE--
<?php
$vertex = new GrVertex;

$vertex->x = 3;

echo 'isset: [' . isset($vertex->x) . ']' . PHP_EOL;
echo 'empty: [' . empty($vertex->x) . ']' . PHP_EOL;
echo 'prop_ext: [' . property_exists($vertex, 'x') . ']' . PHP_EOL . PHP_EOL;

$ref =& $vertex->x;

var_dump($ref);

echo 'isset: [' . isset($vertex->x) . ']' . PHP_EOL;
echo 'empty: [' . empty($vertex->x) . ']' . PHP_EOL;
echo 'prop_ext: [' . property_exists($vertex, 'x') . ']' . PHP_EOL . PHP_EOL;


var_dump($vertex);
print_r($vertex);
testGrVertex($vertex);
?>
--EXPECT--
isset: [1]
empty: []
prop_ext: [1]

float(3)
isset: [1]
empty: []
prop_ext: [1]

object(GrVertex)#1 (2) {
  ["x"]=>
  float(3)
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
    [x] => 3
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
x: 3.000000, y: 0.000000, z: 0.000000, r: 0.000000, g: 0.000000, b: 0.000000, ooz: 0.000000, a: 0.000000, oow: 0.000000
[0] sow: 0.000000, tow: 0.000000, oow: 0.000000
[1] sow: 0.000000, tow: 0.000000, oow: 0.000000