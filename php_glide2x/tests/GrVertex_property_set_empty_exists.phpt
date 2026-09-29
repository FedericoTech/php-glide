--TEST--
GrVertex property set, empty, exists
--FILE--
<?php
$vertex = new GrVertex;

$vertex->x = '0';

echo 'isset: [' . isset($vertex->x) . ']' . PHP_EOL;
echo 'empty: [' . empty($vertex->x) . ']' . PHP_EOL;
echo 'prop_ext: [' . property_exists($vertex, 'x') . ']' . PHP_EOL . PHP_EOL;

unset($vertex->x);
echo 'isset: [' . isset($vertex->x) . ']' . PHP_EOL;
echo 'empty: [' . empty($vertex->x) . ']' . PHP_EOL;
echo 'prop_ext: [' . property_exists($vertex, 'x') . ']' . PHP_EOL . PHP_EOL;
?>
--EXPECT--
isset: [1]
empty: [1]
prop_ext: [1]

isset: []
empty: [1]
prop_ext: [1]