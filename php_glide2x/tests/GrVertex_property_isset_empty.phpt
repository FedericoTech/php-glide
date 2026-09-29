--TEST--
GrVertex property isset and empty
--FILE--
<?php
$vertex = new GrVertex;
var_dump(isset($vertex->x));
var_dump(empty($vertex->x));

$vertex->x = 1;

var_dump(isset($vertex->x));
var_dump(empty($vertex->x));

unset($vertex->x);

var_dump(isset($vertex->x));
var_dump(empty($vertex->x));
?>
--EXPECT--
bool(false)
bool(true)
bool(true)
bool(false)
bool(false)
bool(true)