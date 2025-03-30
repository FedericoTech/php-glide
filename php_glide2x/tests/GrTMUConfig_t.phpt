--TEST--
GrTMUConfig_t
--FILE--
<?php
grGlideInit();

$gtmc = new GrTMUConfig_t;
var_dump($gtmc);

echo PHP_EOL;

$reflection = new ReflectionClass(GrTMUConfig_t::class);
var_dump($reflection->isFinal());

grGlideShutdown();
?>
--EXPECT--
object(GrTMUConfig_t)#1 (0) {
  ["tmuRev"]=>
  uninitialized(int)
  ["tmuRam"]=>
  uninitialized(int)
}

bool(true)