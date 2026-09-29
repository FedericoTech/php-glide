--TEST--
GrVertex property not set, empty, exists
--FILE--
<?php
$vertex = new GrVertex;
echo 'isset: [' . isset($vertex->x) . ']' . PHP_EOL;
echo 'empty: [' . empty($vertex->x) . ']' . PHP_EOL;
echo 'prop_ext: [' . property_exists($vertex, 'x') . ']' . PHP_EOL . PHP_EOL;
?>
--EXPECT--
isset: []
empty: [1]
prop_ext: [1]