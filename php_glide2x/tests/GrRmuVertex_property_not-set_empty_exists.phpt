--TEST--
GrTmuVertex property not set, empty, exists
--FILE--
<?php
$grtv = new GrTmuVertex;
echo 'isset: [' . isset($grtv->sow) . ']' . PHP_EOL;
echo 'empty: [' . empty($grtv->sow) . ']' . PHP_EOL;
echo 'prop_ext: [' . property_exists($grtv, 'sow') . ']' . PHP_EOL . PHP_EOL;
?>
--EXPECT--
isset: []
empty: [1]
prop_ext: [1]