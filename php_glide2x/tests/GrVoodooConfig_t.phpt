--TEST--
GrVoodooConfig_t
--FILE--
<?php
grGlideInit();

$gvc = new GrVoodooConfig_t;

var_dump($gvc);

try{
	echo $gvc->fbRam;	//it show throw an error for trying to read from uninitialized
} catch(Error  $e){
	var_dump($e->getMessage());
}

try{
	echo $gvc->fbiRev;	//it show throw an error for trying to read from uninitialized
} catch(Error  $e){
	var_dump($e->getMessage());
}

try{
	echo $gvc->nTexelfx;	//it show throw an error for trying to read from uninitialized
} catch(Error  $e){
	var_dump($e->getMessage());
}

try{
	echo $gvc->sliDetect;	//it show throw an error for trying to read from uninitialized
} catch(Error  $e){
	var_dump($e->getMessage());
}

try{
	echo $gvc->tmuConfig;	//it show throw an error for trying to read from uninitialized
} catch(Error  $e){
	var_dump($e->getMessage());
}

testGrVoodooConfig_t($gvc);

echo PHP_EOL;

$gtmc = new GrTMUConfig_t;

$gtmc2 = new GrTMUConfig_t;

$gtmc2->tmuRev = 1;
$gtmc2->tmuRam = 2;


$gvc->fbRam = 3;
$gvc->fbiRev = 4;
$gvc->sliDetect = true;
$gvc->tmuConfig = [$gtmc, $gtmc2];
$gvc->nTexelfx = count($gvc->tmuConfig);

var_dump(
	$gvc,
	$gvc->fbRam,
	$gvc->fbiRev,
	$gvc->sliDetect,
	$gvc->nTexelfx,
	$gvc->tmuConfig,
	$gvc->tmuConfig[1]->tmuRev,
	$gvc->tmuConfig[1]->tmuRam
);
testGrVoodooConfig_t($gvc);

echo PHP_EOL;

$reflection = new ReflectionClass(GrVoodooConfig_t::class);
var_dump($reflection->isFinal());

grGlideShutdown();
?>
--EXPECT--
object(GrVoodooConfig_t)#1 (1) {
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
string(82) "Typed property GrVoodooConfig_t::$fbRam must not be accessed before initialization"
string(83) "Typed property GrVoodooConfig_t::$fbiRev must not be accessed before initialization"
string(85) "Typed property GrVoodooConfig_t::$nTexelfx must not be accessed before initialization"
string(86) "Typed property GrVoodooConfig_t::$tmuConfig must not be accessed before initialization"
fbRam: 0, fbiRev: 0, nTexelfx: 0, sliDetect: 0
[0] tmuRev: 0, tmuRam: 0
[1] tmuRev: 0, tmuRam: 0

object(GrVoodooConfig_t)#1 (5) {
  ["fbRam"]=>
  int(3)
  ["fbiRev"]=>
  int(4)
  ["nTexelfx"]=>
  int(2)
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
      int(1)
      ["tmuRam"]=>
      int(2)
    }
  }
}
int(3)
int(4)
bool(true)
int(2)
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
    int(1)
    ["tmuRam"]=>
    int(2)
  }
}
int(1)
int(2)
fbRam: 3, fbiRev: 4, nTexelfx: 2, sliDetect: 0
[0] tmuRev: 0, tmuRam: 0
[1] tmuRev: 1, tmuRam: 2

bool(true)