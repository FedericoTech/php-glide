--TEST--
GrVertex add left handside non scalar to empty
--FILE--
<?php
$vertex = new GrVertex;

$vertex *= 'hello world';

var_dump($vertex2);
testGrVertex($vertex2);
?>
--EXPECTF--
Fatal error: Uncaught Exception: The scalar must be a number %s
Stack trace:
#0 {main}
  thrown in %s on line %d