--TEST--
GrTmuVertex
--FILE--
<?php
grGlideInit();

$ello = new GrTmuVertex;

var_dump($ello);

echo PHP_EOL;

$reflection = new ReflectionClass(GrTmuVertex::class);
var_dump($reflection->isFinal());

grGlideShutdown();
?>
--EXPECT--
object(GrTmuVertex)#1 (0) {
  ["sow"]=>
  uninitialized(float)
  ["tow"]=>
  uninitialized(float)
  ["oow"]=>
  uninitialized(float)
}

bool(false)