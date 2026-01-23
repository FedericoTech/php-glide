--TEST--
GrVertex property not set, empty, does not exist
--FILE--
<?php
$vertex = new GrVertex;

echo 'isset: [' . isset($vertex->t) . ']' . PHP_EOL;
echo 'empty: [' . empty($vertex->t) . ']' . PHP_EOL;
echo 'prop_ext: [' . property_exists($vertex, 't') . ']' . PHP_EOL . PHP_EOL;
?>
--EXPECT--
isset: []
empty: [1]
prop_ext: []