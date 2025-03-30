--TEST--
GrAT3DConfig_t
--FILE--
<?php
grGlideInit();

$gtmc = new GrAT3DConfig_t;
var_dump($gtmc);

echo PHP_EOL;

$reflection = new ReflectionClass(GrSst96Config_t::class);
var_dump($reflection->isFinal());

grGlideShutdown();
?>
--EXPECT--
object(GrAT3DConfig_t)#1 (0) {
  ["rev"]=>
  uninitialized(int)
}

bool(true)