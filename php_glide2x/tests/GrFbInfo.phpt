--TEST--
GrLfbInfo_t
--FILE--
<?php
grGlideInit();

$ello = new GrLfbInfo_t;

var_dump($ello);

testGrLfbInfo_t($ello);

//$ello->size = 10;
$ello->lfbPtr = '1234567890';
$ello->strideInBytes = 4;
$ello->writeMode = GrLfbWriteMode_t::GR_LFBWRITEMODE_RESERVED1;
$ello->origin = GrOriginLocation_t::GR_ORIGIN_LOWER_LEFT;
$ello->flush();

var_dump($ello);

testGrLfbInfo_t($ello);


//$ello->size = 9;
$ello->lfbPtr = '1444567890';
$ello->flush();

var_dump($ello);

testGrLfbInfo_t($ello);

$ello2 = clone $ello;

var_dump($ello2);

testGrLfbInfo_t($ello2);


grGlideShutdown();

echo 'done';
?>
--EXPECT--
object(GrLfbInfo_t)#1 (1) {
  ["size"]=>
  int(20)
  ["lfbPtr"]=>
  uninitialized(string)
  ["strideInBytes"]=>
  uninitialized(int)
  ["writeMode"]=>
  uninitialized(GrLfbWriteMode_t)
  ["origin"]=>
  uninitialized(GrOriginLocation_t)
}
size: 20, lfbPtr: 0, lfbPtr: (null), strideInBytes: 0, writeMode: 0, origin: 0
object(GrLfbInfo_t)#1 (5) {
  ["size"]=>
  int(20)
  ["lfbPtr"]=>
  string(10) "1234567890"
  ["strideInBytes"]=>
  int(4)
  ["writeMode"]=>
  enum(GrLfbWriteMode_t::GR_LFBWRITEMODE_RESERVED1)
  ["origin"]=>
  enum(GrOriginLocation_t::GR_ORIGIN_LOWER_LEFT)
}
size: 20, lfbPtr: 0, lfbPtr: (null), strideInBytes: 4, writeMode: 3, origin: 1
object(GrLfbInfo_t)#1 (5) {
  ["size"]=>
  int(20)
  ["lfbPtr"]=>
  string(10) "1444567890"
  ["strideInBytes"]=>
  int(4)
  ["writeMode"]=>
  enum(GrLfbWriteMode_t::GR_LFBWRITEMODE_RESERVED1)
  ["origin"]=>
  enum(GrOriginLocation_t::GR_ORIGIN_LOWER_LEFT)
}
size: 20, lfbPtr: 0, lfbPtr: (null), strideInBytes: 4, writeMode: 3, origin: 1
object(GrLfbInfo_t)#4 (5) {
  ["size"]=>
  int(20)
  ["lfbPtr"]=>
  string(10) "1444567890"
  ["strideInBytes"]=>
  int(4)
  ["writeMode"]=>
  enum(GrLfbWriteMode_t::GR_LFBWRITEMODE_RESERVED1)
  ["origin"]=>
  enum(GrOriginLocation_t::GR_ORIGIN_LOWER_LEFT)
}
size: 20, lfbPtr: 0, lfbPtr: (null), strideInBytes: 4, writeMode: 3, origin: 1
done