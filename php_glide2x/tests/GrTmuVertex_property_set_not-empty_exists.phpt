--TEST--
GrTmuVertex property not set, empty, exists
--FILE--
<?php
$grtv = new GrTmuVertex;

$grtv->tow = 1;

echo 'isset: [' . isset($grtv->tow) . ']' . PHP_EOL;
echo 'empty: [' . empty($grtv->tow) . ']' . PHP_EOL;
echo 'prop_ext: [' . property_exists($grtv, 'tow') . ']' . PHP_EOL . PHP_EOL;
?>
--EXPECT--
isset: [1]
empty: []
prop_ext: [1]