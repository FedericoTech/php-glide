--TEST--
GrVertex property references a var
--FILE--
<?php
$vertex = new GrVertex;

$vertex->x = 3;

echo 'isset: [' . isset($vertex->x) . ']' . PHP_EOL;
echo 'empty: [' . empty($vertex->x) . ']' . PHP_EOL;
echo 'prop_ext: [' . property_exists($vertex, 'x') . ']' . PHP_EOL . PHP_EOL;

$ref = 3;
$vertex->x =& $ref;
?>
--EXPECTF--
isset: [1]
empty: []
prop_ext: [1]


Warning: main(): Indirect modification of overloaded property GrVertex::$x has no effect in %s on line %d

Fatal error: Uncaught Error: Cannot assign by reference to overloaded object in %s:%d
Stack trace:
#0 {main}
  thrown in %s on line %d