--TEST--
grGet
--FILE--
<?php
grGlideInit();

echo 'GR_NUM_BOARDS' . PHP_EOL;

$a = $b = null; 
$b = grGet(GrGet_t::GR_NUM_BOARDS, $a);
var_dump($b);
var_dump($a);

echo 'GR_IS_BUSY' . PHP_EOL;

$a = $b = null;
$b = grGet(GrGet_t::GR_IS_BUSY, $a);
var_dump($b);
var_dump($a);

echo 'GR_VIDEO_POSITION' . PHP_EOL;

$a = $b = null; 
$b = grGet(GrGet_t::GR_VIDEO_POSITION, $a);
var_dump($b);
var_dump($a);

echo 'GR_WDEPTH_MIN_MAX' . PHP_EOL;

$a = $b = null; 
$b = grGet(GrGet_t::GR_WDEPTH_MIN_MAX, $a);
var_dump($b);
var_dump($a);

echo 'GR_ZDEPTH_MIN_MAX' . PHP_EOL;

$a = $b = null; 
$b = grGet(GrGet_t::GR_ZDEPTH_MIN_MAX, $a);
var_dump($b);
var_dump($a);

echo 'GR_BITS_RGBA' . PHP_EOL;

$a = $b = null; 
$b = grGet(GrGet_t::GR_BITS_RGBA, $a);
var_dump($b);
var_dump($a);

echo 'GR_NUM_SWAP_HISTORY_BUFFER' . PHP_EOL;

$a = $b = null; 
$b = grGet(GrGet_t::GR_NUM_SWAP_HISTORY_BUFFER, $a);
var_dump($b);
var_dump($a);

echo 'GR_SWAP_HISTORY' . PHP_EOL;

$a = $b = null; 
$b = grGet(GrGet_t::GR_SWAP_HISTORY, $a, 6);
var_dump($b);
var_dump($a);

grGlideShutdown();
?>
--EXPECT--
GR_NUM_BOARDS
int(4)
int(1)
GR_IS_BUSY
int(4)
bool(false)
GR_VIDEO_POSITION
int(8)
array(2) {
  [0]=>
  int(0)
  [1]=>
  int(0)
}
GR_WDEPTH_MIN_MAX
int(8)
array(2) {
  [0]=>
  int(0)
  [1]=>
  int(65535)
}
GR_ZDEPTH_MIN_MAX
int(8)
array(2) {
  [0]=>
  int(65535)
  [1]=>
  int(0)
}
GR_BITS_RGBA
int(16)
array(4) {
  [0]=>
  int(5)
  [1]=>
  int(6)
  [2]=>
  int(5)
  [3]=>
  int(8)
}
GR_NUM_SWAP_HISTORY_BUFFER
int(4)
int(6)
GR_SWAP_HISTORY
int(24)
array(6) {
  [0]=>
  int(0)
  [1]=>
  int(0)
  [2]=>
  int(0)
  [3]=>
  int(0)
  [4]=>
  int(0)
  [5]=>
  int(0)
}