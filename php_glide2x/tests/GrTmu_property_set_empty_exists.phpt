--TEST--
GrVertex property set, empty, exists
--FILE--
<?php
$grtv = new GrTmuVertex;

$grtv->tow = '0';

echo 'isset: [' . isset($grtv->tow) . ']' . PHP_EOL;
echo 'empty: [' . empty($grtv->tow) . ']' . PHP_EOL;
echo 'prop_ext: [' . property_exists($grtv, 'tow') . ']' . PHP_EOL . PHP_EOL;

unset($grtv->tow);
echo 'isset: [' . isset($grtv->tow) . ']' . PHP_EOL;
echo 'empty: [' . empty($grtv->tow) . ']' . PHP_EOL;
echo 'prop_ext: [' . property_exists($grtv, 'tow') . ']' . PHP_EOL . PHP_EOL;
?>
--EXPECT--
isset: [1]
empty: [1]
prop_ext: [1]

isset: []
empty: [1]
prop_ext: [1]