--TEST--
SST_t
--FILE--
<?php
grGlideInit();

$gtmc = new SST_t;
var_dump($gtmc);

echo PHP_EOL;

$gtmc->type = GrSstType::GR_SSTTYPE_SST96;
$gtmc->sstBoard = new GrSst96Config_t;
var_dump($gtmc);

echo PHP_EOL;

$reflection = new ReflectionClass(GrSst96Config_t::class);
var_dump($reflection->isFinal());

grGlideShutdown();
?>
--EXPECT--
object(SST_t)#1 (0) {
  ["type"]=>
  uninitialized(GrSstType)
  ["sstBoard"]=>
  uninitialized(GrVoodooConfig_t|GrSst96Config_t|GrAT3DConfig_t|GrVoodoo2Config_t)
}

object(SST_t)#1 (2) {
  ["type"]=>
  enum(GrSstType::GR_SSTTYPE_SST96)
  ["sstBoard"]=>
  object(GrSst96Config_t)#3 (0) {
    ["fbRam"]=>
    uninitialized(int)
    ["tmuConfig"]=>
    uninitialized(GrTMUConfig_t)
  }
}

bool(true)