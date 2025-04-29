--TEST--
GrHwConfiguration
--FILE--
<?php
grGlideInit();

$ghc = new GrHwConfiguration;
var_dump($ghc);
testGrHwConfiguration($ghc);

echo PHP_EOL;

$arr = [];

$sst = new SST_t;
$sst->type = GrSstType::GR_SSTTYPE_VOODOO;
$sst->sstBoard = new GrVoodooConfig_t;
$arr[] = $sst;

$sst = new SST_t;
$sst->type = GrSstType::GR_SSTTYPE_SST96;
$sst->sstBoard = new GrSst96Config_t;
$arr[] = $sst;

$sst = new SST_t;
$sst->type = GrSstType::GR_SSTTYPE_AT3D;
$sst->sstBoard = new GrAT3DConfig_t;
$arr[] = $sst;

$sst = new SST_t;
$sst->type = GrSstType::GR_SSTTYPE_Voodoo2;
$sst->sstBoard = new GrVoodoo2Config_t;
$arr[] = $sst;

$ghc->num_sst = count($arr);
$ghc->SSTs = $arr;

var_dump($ghc);
testGrHwConfiguration($ghc);

echo PHP_EOL;

$gtmc = new GrTMUConfig_t;
$gtmc->tmuRev = 1;
$gtmc->tmuRam = 2;

$gtmc2 = new GrTMUConfig_t;

$arr = [];

//------------------------------
$obj = new GrVoodooConfig_t;
$obj->fbiRev = 3;
$obj->fbRam = 4;
$obj->nTexelfx = 5;
$obj->sliDetect = false;
$obj->tmuConfig = [$gtmc, $gtmc2];

$sst = new SST_t;
$sst->type = GrSstType::GR_SSTTYPE_VOODOO;
$sst->sstBoard = $obj;
$arr[] = $sst;

//------------------------------

$obj = new GrSst96Config_t;
$obj->fbRam = 6;
$obj->nTexelfx = 7;
$obj->tmuConfig = $gtmc;

$sst = new SST_t;
$sst->type = GrSstType::GR_SSTTYPE_SST96;
$sst->sstBoard = $obj;
$arr[] = $sst;

//------------------------------

$obj = new GrAT3DConfig_t;
$obj->rev = 8;

$sst = new SST_t;
$sst->type = GrSstType::GR_SSTTYPE_AT3D;
$sst->sstBoard = $obj;
$arr[] = $sst;

//------------------------------

$obj = new GrVoodoo2Config_t;
$obj->fbiRev = 9;
$obj->fbRam = 10;
$obj->nTexelfx = 11;
$obj->sliDetect = false;
$obj->tmuConfig = [$gtmc, $gtmc2];

$sst = new SST_t;
$sst->type = GrSstType::GR_SSTTYPE_Voodoo2;
$sst->sstBoard = $obj;
$arr[] = $sst;

//------------------------------

$ghc->num_sst = count($arr);
$ghc->SSTs = $arr;

var_dump($ghc);
testGrHwConfiguration($ghc);

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
num_sst: 0

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
      object(GrVoodooConfig_t)#4 (1) {
        ["fbRam"]=>
        uninitialized(int)
        ["fbiRev"]=>
        uninitialized(int)
        ["nTexelfx"]=>
        uninitialized(int)
        ["sliDetect"]=>
        bool(false)
        ["tmuConfig"]=>
        uninitialized(array)
      }
    }
    [1]=>
    object(SST_t)#5 (2) {
      ["type"]=>
      enum(GrSstType::GR_SSTTYPE_SST96)
      ["sstBoard"]=>
      object(GrSst96Config_t)#7 (0) {
        ["fbRam"]=>
        uninitialized(int)
        ["nTexelfx"]=>
        uninitialized(int)
        ["tmuConfig"]=>
        uninitialized(GrTMUConfig_t)
      }
    }
    [2]=>
    object(SST_t)#8 (2) {
      ["type"]=>
      enum(GrSstType::GR_SSTTYPE_AT3D)
      ["sstBoard"]=>
      object(GrAT3DConfig_t)#10 (0) {
        ["rev"]=>
        uninitialized(int)
      }
    }
    [3]=>
    object(SST_t)#11 (2) {
      ["type"]=>
      enum(GrSstType::GR_SSTTYPE_Voodoo2)
      ["sstBoard"]=>
      object(GrVoodoo2Config_t)#13 (1) {
        ["fbRam"]=>
        uninitialized(int)
        ["fbiRev"]=>
        uninitialized(int)
        ["nTexelfx"]=>
        uninitialized(int)
        ["sliDetect"]=>
        bool(false)
        ["tmuConfig"]=>
        uninitialized(array)
      }
    }
  }
}
num_sst: 4
board n: 0, type: 0
board n: 0: [fbiRev: 0, fbRam: 0, nTexelfx: 0, sliDetect: 0, [0][tmuRev: 0, tmuRam: 0], [1][tmuRev: 0, tmuRam: 0]]

board n: 1, type: 1
board n: 1, [fbRam: 0, nTexelfx: 0, [tmuRev: 0, tmuRam: 0]]

board n: 2, type: 2
board n: 2, [rev: 0]

board n: 3, type: 3
board n: 3: [fbiRev: 0, fbRam: 0, nTexelfx: 0, sliDetect: 0, [0][tmuRev: 0, tmuRam: 0], [1][tmuRev: 0, tmuRam: 0]]


object(GrHwConfiguration)#1 (2) {
  ["num_sst"]=>
  int(4)
  ["SSTs"]=>
  array(4) {
    [0]=>
    object(SST_t)#17 (2) {
      ["type"]=>
      enum(GrSstType::GR_SSTTYPE_VOODOO)
      ["sstBoard"]=>
      object(GrVoodooConfig_t)#16 (5) {
        ["fbRam"]=>
        int(4)
        ["fbiRev"]=>
        int(3)
        ["nTexelfx"]=>
        int(5)
        ["sliDetect"]=>
        bool(false)
        ["tmuConfig"]=>
        array(2) {
          [0]=>
          object(GrTMUConfig_t)#14 (2) {
            ["tmuRev"]=>
            int(1)
            ["tmuRam"]=>
            int(2)
          }
          [1]=>
          object(GrTMUConfig_t)#15 (0) {
            ["tmuRev"]=>
            uninitialized(int)
            ["tmuRam"]=>
            uninitialized(int)
          }
        }
      }
    }
    [1]=>
    object(SST_t)#19 (2) {
      ["type"]=>
      enum(GrSstType::GR_SSTTYPE_SST96)
      ["sstBoard"]=>
      object(GrSst96Config_t)#18 (3) {
        ["fbRam"]=>
        int(6)
        ["nTexelfx"]=>
        int(7)
        ["tmuConfig"]=>
        object(GrTMUConfig_t)#14 (2) {
          ["tmuRev"]=>
          int(1)
          ["tmuRam"]=>
          int(2)
        }
      }
    }
    [2]=>
    object(SST_t)#21 (2) {
      ["type"]=>
      enum(GrSstType::GR_SSTTYPE_AT3D)
      ["sstBoard"]=>
      object(GrAT3DConfig_t)#20 (1) {
        ["rev"]=>
        int(8)
      }
    }
    [3]=>
    object(SST_t)#23 (2) {
      ["type"]=>
      enum(GrSstType::GR_SSTTYPE_Voodoo2)
      ["sstBoard"]=>
      object(GrVoodoo2Config_t)#22 (5) {
        ["fbRam"]=>
        int(10)
        ["fbiRev"]=>
        int(9)
        ["nTexelfx"]=>
        int(11)
        ["sliDetect"]=>
        bool(false)
        ["tmuConfig"]=>
        array(2) {
          [0]=>
          object(GrTMUConfig_t)#14 (2) {
            ["tmuRev"]=>
            int(1)
            ["tmuRam"]=>
            int(2)
          }
          [1]=>
          object(GrTMUConfig_t)#15 (0) {
            ["tmuRev"]=>
            uninitialized(int)
            ["tmuRam"]=>
            uninitialized(int)
          }
        }
      }
    }
  }
}
num_sst: 4
board n: 0, type: 0
board n: 0: [fbiRev: 3, fbRam: 4, nTexelfx: 5, sliDetect: 0, [0][tmuRev: 1, tmuRam: 2], [1][tmuRev: 0, tmuRam: 0]]

board n: 1, type: 1
board n: 1, [fbRam: 6, nTexelfx: 7, [tmuRev: 1, tmuRam: 2]]

board n: 2, type: 2
board n: 2, [rev: 8]

board n: 3, type: 3
board n: 3: [fbiRev: 9, fbRam: 10, nTexelfx: 11, sliDetect: 0, [0][tmuRev: 1, tmuRam: 2], [1][tmuRev: 0, tmuRam: 0]]


bool(true)