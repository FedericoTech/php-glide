--TEST--
GrVertex
--FILE--
<?php
grGlideInit();

$ello = new GrVertex;

var_dump($ello);

echo PHP_EOL;

$reflection = new ReflectionClass(GrVertex::class);
var_dump($reflection->isFinal());

grGlideShutdown();
?>
--EXPECT--
object(GrVertex)#1 (0) {
  ["x"]=>
  uninitialized(float)
  ["y"]=>
  uninitialized(float)
  ["z"]=>
  uninitialized(float)
  ["r"]=>
  uninitialized(float)
  ["g"]=>
  uninitialized(float)
  ["b"]=>
  uninitialized(float)
  ["ooz"]=>
  uninitialized(float)
  ["a"]=>
  uninitialized(float)
  ["oow"]=>
  uninitialized(float)
  ["tmuvtx"]=>
  uninitialized(array)
}

bool(false)