--TEST--
GrSstPerfStats_t
--FILE--
<?php
grGlideInit();

$gsps = new GrSstPerfStats_t;

var_dump($gsps);

testGrSstPerfStats_t($gsps);

$gsps->pixelsIn = -1;
$gsps->chromaFail = 2;
$gsps->zFuncFail = -2;
$gsps->aFuncFail = 3;
$gsps->pixelsOut = -4;
$gsps->flush();

var_dump($gsps);

testGrSstPerfStats_t($gsps);

$gsps2 = clone $gsps;

var_dump($gsps2);

testGrSstPerfStats_t($gsps2);

grGlideShutdown();

echo 'done';
?>
--EXPECT--
object(GrSstPerfStats_t)#1 (0) {
  ["pixelsIn"]=>
  uninitialized(int)
  ["chromaFail"]=>
  uninitialized(int)
  ["zFuncFail"]=>
  uninitialized(int)
  ["aFuncFail"]=>
  uninitialized(int)
  ["pixelsOut"]=>
  uninitialized(int)
}
pixelsIn: 0, chromaFail: 0, zFuncFail: 0, aFuncFail: 0, pixelsOut: 0
object(GrSstPerfStats_t)#1 (5) {
  ["pixelsIn"]=>
  int(-1)
  ["chromaFail"]=>
  int(2)
  ["zFuncFail"]=>
  int(-2)
  ["aFuncFail"]=>
  int(3)
  ["pixelsOut"]=>
  int(-4)
}
pixelsIn: 4294967295, chromaFail: 2, zFuncFail: 4294967294, aFuncFail: 4294967292, pixelsOut: 0
object(GrSstPerfStats_t)#2 (5) {
  ["pixelsIn"]=>
  int(-1)
  ["chromaFail"]=>
  int(2)
  ["zFuncFail"]=>
  int(-2)
  ["aFuncFail"]=>
  int(3)
  ["pixelsOut"]=>
  int(-4)
}
pixelsIn: 4294967295, chromaFail: 2, zFuncFail: 4294967294, aFuncFail: 4294967292, pixelsOut: 0
done