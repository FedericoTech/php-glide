--TEST--
GrVertex property dynamically set gets referenced by a var
--FILE--
<?php
$vertex = new GrVertex;

$vertex->q = 3;

echo 'isset: [' . isset($vertex->q) . ']' . PHP_EOL;
echo 'empty: [' . empty($vertex->q) . ']' . PHP_EOL;
echo 'prop_ext: [' . property_exists($vertex, 'q') . ']' . PHP_EOL . PHP_EOL;


$ref =& $vertex->q;

$ref = 'ello';

echo 'isset: [' . isset($vertex->q) . ']' . PHP_EOL;
echo 'empty: [' . empty($vertex->q) . ']' . PHP_EOL;
echo 'prop_ext: [' . property_exists($vertex, 'q') . ']' . PHP_EOL;
echo "q is: $vertex->q" . PHP_EOL . PHP_EOL;

var_dump($ref);

var_dump($vertex);
print_r($vertex);
testGrVertex($vertex);
?>
--EXPECTF--
Deprecated: Creation of dynamic property GrVertex::$q is deprecated in %s on line %d
isset: [1]
empty: []
prop_ext: [1]

isset: [1]
empty: []
prop_ext: [1]
q is: ello

string(4) "ello"
object(GrVertex)#1 (2) {
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
  ["q"]=>
  &string(4) "ello"
}
GrVertex Object
(
    [tmuvtx] => GrTmuVertices Object
        (
            [0] => GrTmuVertex Object
                (
                )

            [1] => GrTmuVertex Object
                (
                )

        )

    [q] => ello
)
x: 0.000000, y: 0.000000, z: 0.000000, r: 0.000000, g: 0.000000, b: 0.000000, ooz: 0.000000, a: 0.000000, oow: 0.000000
[0] sow: 0.000000, tow: 0.000000, oow: 0.000000
[1] sow: 0.000000, tow: 0.000000, oow: 0.000000