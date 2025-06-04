--TEST--
GrAT3DConfig_t
--FILE--
<?php
grGlideInit();

$ga3dc = new GrAT3DConfig_t;
$ga3dc->flush();
var_dump($ga3dc);

try{
	echo $ga3dc->rev; //we need to implement not initialized case
} catch(Error  $e){
	var_dump($e->getMessage());
}

testGrAT3DConfig_t($ga3dc);

echo PHP_EOL;

$ga3dc->rev = 1;
$ga3dc->flush();
var_dump(
	$ga3dc,
	$ga3dc->rev
);
testGrAT3DConfig_t($ga3dc);

echo PHP_EOL;

$ga3dc->rev = 2;
$ga3dc->flush();

var_dump(
	$ga3dc,
	$ga3dc->rev
);
testGrAT3DConfig_t($ga3dc);

$ga3dc2 = clone $ga3dc;

var_dump(
	$ga3dc2,
	$ga3dc2 == $ga3dc,
	$ga3dc2 === $ga3dc
);

testGrAT3DConfig_t($ga3dc2);

$reflection = new ReflectionClass(GrAT3DConfig_t::class);
var_dump(
	$reflection->isInternal(),
	$reflection->isFinal()
);

grGlideShutdown();
?>
--EXPECT--
object(GrAT3DConfig_t)#1 (0) {
  ["rev"]=>
  uninitialized(int)
}
string(78) "Typed property GrAT3DConfig_t::$rev must not be accessed before initialization"
rev: 0

object(GrAT3DConfig_t)#1 (1) {
  ["rev"]=>
  int(1)
}
int(1)
rev: 1

object(GrAT3DConfig_t)#1 (1) {
  ["rev"]=>
  int(2)
}
int(2)
rev: 2
object(GrAT3DConfig_t)#3 (1) {
  ["rev"]=>
  int(2)
}
bool(true)
bool(false)
rev: 2
bool(true)
bool(true)