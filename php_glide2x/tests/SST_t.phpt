--TEST--
SST_t
--FILE--
<?php
grGlideInit();

$sst = new SST_t;
$sst->flush();

var_dump($sst);

try{
	echo $sst->type;	//it show throw an error for trying to read from uninitialized
} catch(Error  $e){
	var_dump($e->getMessage());
}

try{
	echo $sst->sstBoard;	//it show throw an error for trying to read from uninitialized
} catch(Error  $e){
	var_dump($e->getMessage());
}

testSST_t($sst);

echo PHP_EOL;

$gtmc = new GrTMUConfig_t;

$gtmc2 = new GrTMUConfig_t;
$gtmc2->tmuRev = 5;
$gtmc2->tmuRam = 6;

$gvc = new GrVoodooConfig_t;

$gvc->fbiRev = 1;
$gvc->fbRam = 2;
$gvc->nTexelfx = 3;
$gvc->sliDetect = 4;
$gvc->tmuConfig = [$gtmc, $gtmc2];


$sst->type = GrSstType::GR_SSTTYPE_VOODOO;
$sst->sstBoard = $gvc;
$sst->flush();

var_dump($sst);
testSST_t($sst);

echo PHP_EOL;

$gs9c = new GrSst96Config_t;
$gs9c->fbRam = 1;
$gs9c->nTexelfx = 2;
$gs9c->tmuConfig = $gtmc2;

$sst = new SST_t;
$sst->type = GrSstType::GR_SSTTYPE_SST96;
$sst->sstBoard = $gs9c;
$sst->flush();

var_dump($sst);
testSST_t($sst);

echo PHP_EOL;

$ga3c = new GrAT3DConfig_t;
$ga3c->rev = 1;

$sst = new SST_t;
$sst->type = GrSstType::GR_SSTTYPE_AT3D;
$sst->sstBoard = $ga3c;
$sst->flush();

var_dump($sst);
testSST_t($sst);

echo PHP_EOL;

$gv2c = new GrVoodoo2Config_t;

$gv2c->fbiRev = 1;
$gv2c->fbRam = 2;
$gv2c->nTexelfx = 3;
$gv2c->sliDetect = 4;
$gv2c->tmuConfig = [$gtmc, $gtmc2];

$sst = new SST_t;
$sst->type = GrSstType::GR_SSTTYPE_Voodoo2;
$sst->sstBoard = $gv2c;
$sst->flush();

var_dump($sst);
testSST_t($sst);

$sst2 = clone $sst;

var_dump(
	$sst2,
	$sst2 == $sst,
	$sst2 === $sst
);
testSST_t($sst2);

$reflection = new ReflectionClass(SST_t::class);
var_dump(
	$reflection->isInternal(),
	$reflection->isFinal()
);

grGlideShutdown();
?>
--EXPECT--
object(SST_t)#1 (0) {
  ["type"]=>
  uninitialized(?GrSstType)
  ["sstBoard"]=>
  uninitialized(GrVoodooConfig_t|GrSst96Config_t|GrAT3DConfig_t|GrVoodoo2Config_t|null)
}
string(70) "Typed property SST_t::$type must not be accessed before initialization"
string(74) "Typed property SST_t::$sstBoard must not be accessed before initialization"
type: -1,
object(SST_t)#1 (2) {
  ["type"]=>
  enum(GrSstType::GR_SSTTYPE_VOODOO)
  ["sstBoard"]=>
  object(GrVoodooConfig_t)#5 (5) {
    ["fbRam"]=>
    int(2)
    ["fbiRev"]=>
    int(1)
    ["nTexelfx"]=>
    int(3)
    ["sliDetect"]=>
    bool(true)
    ["tmuConfig"]=>
    array(2) {
      [0]=>
      object(GrTMUConfig_t)#2 (0) {
        ["tmuRev"]=>
        uninitialized(int)
        ["tmuRam"]=>
        uninitialized(int)
      }
      [1]=>
      object(GrTMUConfig_t)#4 (2) {
        ["tmuRev"]=>
        int(5)
        ["tmuRam"]=>
        int(6)
      }
    }
  }
}
type: 0, sstBoard: [fbiRev: 1, fbRam: 2, nTexelfx: 3, sliDetect: 1, tmuConfig: [[tmuRev: -1, tmuRam: -1], [tmuRev: 5, tmuRam: 6]]

object(SST_t)#8 (2) {
  ["type"]=>
  enum(GrSstType::GR_SSTTYPE_SST96)
  ["sstBoard"]=>
  object(GrSst96Config_t)#7 (3) {
    ["fbRam"]=>
    int(1)
    ["nTexelfx"]=>
    int(2)
    ["tmuConfig"]=>
    object(GrTMUConfig_t)#4 (2) {
      ["tmuRev"]=>
      int(5)
      ["tmuRam"]=>
      int(6)
    }
  }
}
type: 1, sstBoard: [fbRam: 1, nTexelfx: 2, tmuConfig: [tmuRev: 5, tmuRam: 5]]

object(SST_t)#10 (2) {
  ["type"]=>
  enum(GrSstType::GR_SSTTYPE_AT3D)
  ["sstBoard"]=>
  object(GrAT3DConfig_t)#9 (1) {
    ["rev"]=>
    int(1)
  }
}
type: 2, sstBoard: [rev: 1]

object(SST_t)#12 (2) {
  ["type"]=>
  enum(GrSstType::GR_SSTTYPE_Voodoo2)
  ["sstBoard"]=>
  object(GrVoodoo2Config_t)#11 (5) {
    ["fbRam"]=>
    int(2)
    ["fbiRev"]=>
    int(1)
    ["nTexelfx"]=>
    int(3)
    ["sliDetect"]=>
    bool(true)
    ["tmuConfig"]=>
    array(2) {
      [0]=>
      object(GrTMUConfig_t)#2 (0) {
        ["tmuRev"]=>
        uninitialized(int)
        ["tmuRam"]=>
        uninitialized(int)
      }
      [1]=>
      object(GrTMUConfig_t)#4 (2) {
        ["tmuRev"]=>
        int(5)
        ["tmuRam"]=>
        int(6)
      }
    }
  }
}
type: 3, sstBoard: [fbiRev: 1, fbRam: 2, nTexelfx: 3, sliDetect: 1, tmuConfig: [[tmuRev: -1, tmuRam: -1], [tmuRev: 5, tmuRam: 6]]
object(SST_t)#13 (2) {
  ["type"]=>
  enum(GrSstType::GR_SSTTYPE_Voodoo2)
  ["sstBoard"]=>
  object(GrVoodoo2Config_t)#11 (5) {
    ["fbRam"]=>
    int(2)
    ["fbiRev"]=>
    int(1)
    ["nTexelfx"]=>
    int(3)
    ["sliDetect"]=>
    bool(true)
    ["tmuConfig"]=>
    array(2) {
      [0]=>
      object(GrTMUConfig_t)#2 (0) {
        ["tmuRev"]=>
        uninitialized(int)
        ["tmuRam"]=>
        uninitialized(int)
      }
      [1]=>
      object(GrTMUConfig_t)#4 (2) {
        ["tmuRev"]=>
        int(5)
        ["tmuRam"]=>
        int(6)
      }
    }
  }
}
bool(true)
bool(false)
type: 3, sstBoard: [fbiRev: 1, fbRam: 2, nTexelfx: 3, sliDetect: 1, tmuConfig: [[tmuRev: -1, tmuRam: -1], [tmuRev: 5, tmuRam: 6]]
bool(true)
bool(true)