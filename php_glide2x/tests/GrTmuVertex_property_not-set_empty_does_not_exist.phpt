--TEST--
GrTmuVertex property not set, empty, does not exist
--FILE--
<?php
$grtv = new GrTmuVertex;

echo 'isset: [' . isset($grtv->t) . ']' . PHP_EOL;
echo 'empty: [' . empty($grtv->t) . ']' . PHP_EOL;
echo 'prop_ext: [' . property_exists($grtv, 't') . ']' . PHP_EOL . PHP_EOL;
?>
--EXPECT--
isset: []
empty: [1]
prop_ext: []