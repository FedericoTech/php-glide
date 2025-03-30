--TEST--
GrHwConfiguration
--FILE--
<?php
grGlideInit();

$gtmc = new GrHwConfiguration;
var_dump($gtmc);

echo PHP_EOL;

$sst = new SST_t;
$sst->type = GrSstType::GR_SSTTYPE_VOODOO;
$sst->sstBoard = new GrVoodooConfig_t;
$gtmc->SSTs[] = $sst;

$sst = new SST_t;
$sst->type = GrSstType::GR_SSTTYPE_Voodoo2;
$sst->sstBoard = new GrVoodoo2Config_t;
$gtmc->SSTs[] = $sst;

$sst = new SST_t;
$sst->type = GrSstType::GR_SSTTYPE_SST96;
$sst->sstBoard = new GrSst96Config_t;
$gtmc->SSTs[] = $sst;

$sst = new SST_t;
$sst->type = GrSstType::GR_SSTTYPE_AT3D;
$sst->sstBoard = new GrAT3DConfig_t;
$gtmc->SSTs[] = $sst;

$gtmc->num_sst = count($gtmc->SSTs);

var_dump($gtmc);

echo PHP_EOL;

$reflection = new ReflectionClass(GrHwConfiguration::class);
var_dump($reflection->isFinal());

grGlideShutdown();
?>
--EXPECT--
object(GrHwConfiguration)#1 (0) {
  ["num_sst"]=>
  uninitialized(int)
  ["SSTs"]=>
  uninitialized(array)
}

object(GrHwConfiguration)#1 (2) {
  ["num_sst"]=>
  int(4)
  ["SSTs"]=>
  array(4) {
    [0]=>
    object(SST_t)#2 (2) {
      ["type"]=>
      enum(GrSstType::GR_SSTTYPE_VOODOO)
      ["sstBoard"]=>
      object(GrVoodooConfig_t)#4 (2) {
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
    }
    [1]=>
    object(SST_t)#5 (2) {
      ["type"]=>
      enum(GrSstType::GR_SSTTYPE_Voodoo2)
      ["sstBoard"]=>
      object(GrVoodooConfig_t)#7 (2) {
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
    }
    [2]=>
    object(SST_t)#8 (2) {
      ["type"]=>
      enum(GrSstType::GR_SSTTYPE_SST96)
      ["sstBoard"]=>
      object(GrSst96Config_t)#10 (0) {
        ["fbRam"]=>
        uninitialized(int)
        ["tmuConfig"]=>
        uninitialized(GrTMUConfig_t)
      }
    }
    [3]=>
    object(SST_t)#11 (2) {
      ["type"]=>
      enum(GrSstType::GR_SSTTYPE_AT3D)
      ["sstBoard"]=>
      object(GrAT3DConfig_t)#13 (0) {
        ["rev"]=>
        uninitialized(int)
      }
    }
  }
}

bool(true)