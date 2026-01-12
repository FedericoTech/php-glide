--TEST--
GrVertex add left handside non scalar to empty
--FILE--
<?php
$vertex = new GrVertex;

$vertex2 = 'hello world' + $vertex;

var_dump($vertex2);
testGrVertex($vertex2);
?>
--EXPECTF--
Fatal error: Uncaught Exception: Left operand must be a scalar in %s
Stack trace:
#0 {main}
  thrown in %s on line %d