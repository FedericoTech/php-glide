--TEST--
GrVertex add right handside non scalar to empty
--FILE--
<?php
$vertex = new GrVertex;

$vertex2 = $vertex + 'hello world';

var_dump($vertex2);
testGrVertex($vertex2);
?>
--EXPECTF--
Fatal error: Uncaught Exception: Right operand must be a scalar in %s
Stack trace:
#0 {main}
  thrown in %s on line %d