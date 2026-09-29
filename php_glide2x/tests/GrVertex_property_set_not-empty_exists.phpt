--TEST--
GrVertex property not set, empty, exists
--FILE--
<?php
$vertex = new GrVertex;

$vertex->x = 1;

echo 'isset: [' . isset($vertex->x) . ']' . PHP_EOL;
echo 'empty: [' . empty($vertex->x) . ']' . PHP_EOL;
echo 'prop_ext: [' . property_exists($vertex, 'x') . ']' . PHP_EOL . PHP_EOL;
?>
--EXPECT--
isset: [1]
empty: []
prop_ext: [1]