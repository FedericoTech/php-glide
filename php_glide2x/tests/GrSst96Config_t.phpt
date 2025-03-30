--TEST--
GrSst96Config_t
--FILE--
<?php
grGlideInit();

$gtmc = new GrSst96Config_t;
var_dump($gtmc);

echo PHP_EOL;

$gtmc->tmuConfig = new GrTMUConfig_t;

var_dump($gtmc);

echo PHP_EOL;

$reflection = new ReflectionClass(GrSst96Config_t::class);
var_dump($reflection->isFinal());

grGlideShutdown();
?>
--EXPECT--
object(GrSst96Config_t)#1 (0) {
  ["fbRam"]=>
  uninitialized(int)
  ["tmuConfig"]=>
  uninitialized(GrTMUConfig_t)
}

object(GrSst96Config_t)#1 (1) {
  ["fbRam"]=>
  uninitialized(int)
  ["tmuConfig"]=>
  object(GrTMUConfig_t)#2 (0) {
    ["tmuRev"]=>
    uninitialized(int)
    ["tmuRam"]=>
    uninitialized(int)
  }
}

bool(true)