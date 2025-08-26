--TEST--
Gu3dfHeader
--FILE--
<?php
grGlideInit();

//show the object empty. 
$g3dfh = new Gu3dfHeader;
$g3dfh->flush();
var_dump($g3dfh);	//it shows uninitialized properties

try{
	echo $g3dfh->width;	//it show throw an error for trying to read from uninitialized
} catch(Error  $e){
	var_dump($e->getMessage());
}

try{
	echo $g3dfh->height; //it show throw an error for trying to read from uninitialized
} catch(Error  $e){
	var_dump($e->getMessage());
}

try{
	echo $g3dfh->small_lod; //it show throw an error for trying to read from uninitialized
} catch(Error  $e){
	var_dump($e->getMessage());
}

testGu3dfHeader($g3dfh); //it shows zero as in C it's zero initialized

echo PHP_EOL;

$g3dfh->width = 3;
$g3dfh->height = 4;
$g3dfh->small_lod = GrLOD_t::GR_LOD_8;
$g3dfh->large_lod = GrLOD_t::GR_LOD_256;
$g3dfh->aspect_ratio = GrAspectRatio_t::GR_ASPECT_2x1;
$g3dfh->format = GrTextureFormat_t::GR_TEXFMT_RGB_332;

$g3dfh->flush();

var_dump(
	$g3dfh,
	$g3dfh->width,
	$g3dfh->small_lod,
	$g3dfh->aspect_ratio,
	$g3dfh->format,
);
testGu3dfHeader($g3dfh);

echo PHP_EOL;

$g3dfh2 = clone $g3dfh;

var_dump(
	$g3dfh,
	$g3dfh2,
	$g3dfh == $g3dfh2,
	$g3dfh === $g3dfh2
);
testGu3dfHeader($g3dfh2);

$reflection = new ReflectionClass(Gu3dfHeader::class);
var_dump(
	$reflection->isInternal(),
	$reflection->isFinal()	//we test that the class is final
);	

grGlideShutdown();
?>
--EXPECT--
object(Gu3dfHeader)#1 (0) {
  ["width"]=>
  uninitialized(int)
  ["height"]=>
  uninitialized(int)
  ["small_lod"]=>
  uninitialized(GrLOD_t)
  ["large_lod"]=>
  uninitialized(GrLOD_t)
  ["aspect_ratio"]=>
  uninitialized(GrAspectRatio_t)
  ["format"]=>
  uninitialized(GrTextureFormat_t)
}
string(77) "Typed property Gu3dfHeader::$width must not be accessed before initialization"
string(78) "Typed property Gu3dfHeader::$height must not be accessed before initialization"
string(81) "Typed property Gu3dfHeader::$small_lod must not be accessed before initialization"
width: 0, height: 0, small_lod: 0, large_lod: 0, aspect_ratio: 0, format:0

object(Gu3dfHeader)#1 (6) {
  ["width"]=>
  int(3)
  ["height"]=>
  int(4)
  ["small_lod"]=>
  enum(GrLOD_t::GR_LOD_8)
  ["large_lod"]=>
  enum(GrLOD_t::GR_LOD_256)
  ["aspect_ratio"]=>
  enum(GrAspectRatio_t::GR_ASPECT_2x1)
  ["format"]=>
  enum(GrTextureFormat_t::GR_TEXFMT_RGB_332)
}
int(3)
enum(GrLOD_t::GR_LOD_8)
enum(GrAspectRatio_t::GR_ASPECT_2x1)
enum(GrTextureFormat_t::GR_TEXFMT_RGB_332)
width: 3, height: 4, small_lod: 5, large_lod: 0, aspect_ratio: 2, format:0

object(Gu3dfHeader)#1 (6) {
  ["width"]=>
  int(3)
  ["height"]=>
  int(4)
  ["small_lod"]=>
  enum(GrLOD_t::GR_LOD_8)
  ["large_lod"]=>
  enum(GrLOD_t::GR_LOD_256)
  ["aspect_ratio"]=>
  enum(GrAspectRatio_t::GR_ASPECT_2x1)
  ["format"]=>
  enum(GrTextureFormat_t::GR_TEXFMT_RGB_332)
}
object(Gu3dfHeader)#7 (6) {
  ["width"]=>
  int(3)
  ["height"]=>
  int(4)
  ["small_lod"]=>
  enum(GrLOD_t::GR_LOD_8)
  ["large_lod"]=>
  enum(GrLOD_t::GR_LOD_256)
  ["aspect_ratio"]=>
  enum(GrAspectRatio_t::GR_ASPECT_2x1)
  ["format"]=>
  enum(GrTextureFormat_t::GR_TEXFMT_RGB_332)
}
bool(true)
bool(false)
width: 3, height: 4, small_lod: 5, large_lod: 0, aspect_ratio: 2, format:0
bool(true)
bool(true)