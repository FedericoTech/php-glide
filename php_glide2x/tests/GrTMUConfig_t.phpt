--TEST--
GrTMUConfig_t
--FILE--
<?php
grGlideInit();

//show the object empty. 
$gtmc = new GrTMUConfig_t;
$gtmc->flush();
var_dump($gtmc);	//it shows uninitialized properties

try{
	echo $gtmc->tmuRev;	//it show throw an error for trying to read from uninitialized
} catch(Error  $e){
	var_dump($e->getMessage());
}

try{
	echo $gtmc->tmuRam; //it show throw an error for trying to read from uninitialized
} catch(Error  $e){
	var_dump($e->getMessage());
}

testGrTMUConfig_t($gtmc); //it shows zero as in C it's zero initialized

echo PHP_EOL;

$gtmc->tmuRev = 1;
//$gtmc->tmuRam = 2;

$gtmc->flush();

var_dump(
	$gtmc,
	$gtmc->tmuRev,
	//$gtmc->tmuRam
);
testGrTMUConfig_t($gtmc);

$gtmc2 = clone $gtmc;

var_dump(
	$gtmc2,
	$gtmc == $gtmc2,
	$gtmc === $gtmc2,
);
testGrTMUConfig_t($gtmc2);

echo PHP_EOL;

$gtmc->tmuRev = 3;
$gtmc->tmuRam = 4;
$gtmc->flush();

var_dump(
	$gtmc,
	$gtmc->tmuRev,
	$gtmc->tmuRam
);
testGrTMUConfig_t($gtmc);

$reflection = new ReflectionClass(GrTMUConfig_t::class);
var_dump($reflection->isInternal());	//we test that the class is final
var_dump($reflection->isFinal());	//we test that the class is final

grGlideShutdown();
?>
--EXPECT--
object(GrTMUConfig_t)#1 (0) {
  ["tmuRev"]=>
  uninitialized(int)
  ["tmuRam"]=>
  uninitialized(int)
}
string(80) "Typed property GrTMUConfig_t::$tmuRev must not be accessed before initialization"
string(80) "Typed property GrTMUConfig_t::$tmuRam must not be accessed before initialization"
tmuRev: 0, tmuRam: 0

object(GrTMUConfig_t)#1 (1) {
  ["tmuRev"]=>
  int(1)
  ["tmuRam"]=>
  uninitialized(int)
}
int(1)
tmuRev: 1, tmuRam: 0
object(GrTMUConfig_t)#2 (1) {
  ["tmuRev"]=>
  int(1)
  ["tmuRam"]=>
  uninitialized(int)
}
bool(true)
bool(false)
tmuRev: 1, tmuRam: 0

object(GrTMUConfig_t)#1 (2) {
  ["tmuRev"]=>
  int(3)
  ["tmuRam"]=>
  int(4)
}
int(3)
int(4)
tmuRev: 3, tmuRam: 4
bool(true)
bool(true)