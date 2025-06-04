--TEST--
GrSst96Config_t
--FILE--
<?php
grGlideInit();

//show the object empty. 
$gs9c = new GrSst96Config_t;
$gs9c->flush();
var_dump($gs9c);	//it shows uninitialized properties

try{
	echo $gs9c->fbRam;	//it show throw an error for trying to read from uninitialized
} catch(Error  $e){
	var_dump($e->getMessage());
}

try{
	echo $gs9c->nTexelfx; //it show throw an error for trying to read from uninitialized
} catch(Error  $e){
	var_dump($e->getMessage());
}

try{
	echo $gs9c->tmuConfig; //it show throw an error for trying to read from uninitialized
} catch(Error  $e){
	var_dump($e->getMessage());
}

testGrSst96Config_t($gs9c); //it shows zero as in C it's zero initialized

echo PHP_EOL;

$gtmc = new GrTMUConfig_t;
$gtmc->tmuRev = 1;
$gtmc->tmuRam = 2;

$gs9c->fbRam = 3;
$gs9c->nTexelfx = 4;
$gs9c->tmuConfig = $gtmc;

$gs9c->flush();

var_dump(
	$gs9c,
	$gs9c->fbRam,
	$gs9c->nTexelfx,
	$gs9c->tmuConfig->tmuRev,
	$gs9c->tmuConfig->tmuRam
);
testGrSst96Config_t($gs9c);

echo PHP_EOL;

$gs9c->fbRam = 5;
$gs9c->nTexelfx = 6;
$gs9c->tmuConfig->tmuRev = 7;	//the change is not being communicated to GrSst96Config_t
$gs9c->tmuConfig->tmuRam = 8;	//the change is not being communicated to GrSst96Config_t

$gs9c->flush();

var_dump(
	$gs9c,
	$gs9c->fbRam,
	$gs9c->nTexelfx,
	$gs9c->tmuConfig->tmuRev,	//the change is not being communicated to GrSst96Config_t
	$gs9c->tmuConfig->tmuRam	//the change is not being communicated to GrSst96Config_t
);
testGrSst96Config_t($gs9c);

$gs9c2 = clone $gs9c;

var_dump(
	$gs9c,
	$gs9c2,
	$gs9c == $gs9c2,
	$gs9c === $gs9c2
);
testGrSst96Config_t($gs9c2);

$reflection = new ReflectionClass(GrTMUConfig_t::class);
var_dump(
	$reflection->isInternal(),
	$reflection->isFinal()	//we test that the class is final
);	

grGlideShutdown();
?>
--EXPECT--
object(GrSst96Config_t)#1 (0) {
  ["fbRam"]=>
  uninitialized(int)
  ["nTexelfx"]=>
  uninitialized(int)
  ["tmuConfig"]=>
  uninitialized(GrTMUConfig_t)
}
string(81) "Typed property GrSst96Config_t::$fbRam must not be accessed before initialization"
string(84) "Typed property GrSst96Config_t::$nTexelfx must not be accessed before initialization"
string(85) "Typed property GrSst96Config_t::$tmuConfig must not be accessed before initialization"
fbRam: 0, nTexelfx: 0, tmuConfig: [tmuRev: 0, tmuRam: 0]

object(GrSst96Config_t)#1 (3) {
  ["fbRam"]=>
  int(3)
  ["nTexelfx"]=>
  int(4)
  ["tmuConfig"]=>
  object(GrTMUConfig_t)#3 (2) {
    ["tmuRev"]=>
    int(1)
    ["tmuRam"]=>
    int(2)
  }
}
int(3)
int(4)
int(1)
int(2)
fbRam: 3, nTexelfx: 4, tmuConfig: [tmuRev: 1, tmuRam: 2]

object(GrSst96Config_t)#1 (3) {
  ["fbRam"]=>
  int(5)
  ["nTexelfx"]=>
  int(6)
  ["tmuConfig"]=>
  object(GrTMUConfig_t)#3 (2) {
    ["tmuRev"]=>
    int(7)
    ["tmuRam"]=>
    int(8)
  }
}
int(5)
int(6)
int(7)
int(8)
fbRam: 5, nTexelfx: 6, tmuConfig: [tmuRev: 7, tmuRam: 8]
object(GrSst96Config_t)#1 (3) {
  ["fbRam"]=>
  int(5)
  ["nTexelfx"]=>
  int(6)
  ["tmuConfig"]=>
  object(GrTMUConfig_t)#3 (2) {
    ["tmuRev"]=>
    int(7)
    ["tmuRam"]=>
    int(8)
  }
}
object(GrSst96Config_t)#4 (3) {
  ["fbRam"]=>
  int(5)
  ["nTexelfx"]=>
  int(6)
  ["tmuConfig"]=>
  object(GrTMUConfig_t)#3 (2) {
    ["tmuRev"]=>
    int(7)
    ["tmuRam"]=>
    int(8)
  }
}
bool(true)
bool(false)
fbRam: 5, nTexelfx: 6, tmuConfig: [tmuRev: 7, tmuRam: 8]
bool(true)
bool(true)