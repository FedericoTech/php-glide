--TEST--
GrVoodoo2Config_t
--FILE--
<?php
grGlideInit();

$gtmc = new GrVoodoo2Config_t;
var_dump($gtmc);

echo PHP_EOL;

$reflection = new ReflectionClass(GrVoodoo2Config_t::class);
var_dump($reflection->isFinal());

grGlideShutdown();
?>
--EXPECT--
object(GrVoodooConfig_t)#1 (2) {
  ["fbRam"]=>
  uninitialized(int)
  ["fbiRev"]=>
  uninitialized(int)
  ["nTexelfx"]=>
  uninitialized(int)
  ["sliDetect"]=>
  bool(false)
  ["tmuConfig"]=>
  array(0) {
  }
}

bool(true)