--TEST--
grTexTextureMemRequired
--FILE--
<?php
grGlideInit();

$size = grTexCalcMemRequired(
	GrLOD_t::GR_LOD_64,
	GrLOD_t::GR_LOD_64,
	GrAspectRatio_t::GR_ASPECT_1x1,
	GrTextureFormat_t::GR_TEXFMT_16BIT
);

echo "[$size]\n";

$info = new GrTexInfo;
$info->smallLod = GrLOD_t::GR_LOD_64;
$info->largeLod = GrLOD_t::GR_LOD_64;
$info->aspectRatio = GrAspectRatio_t::GR_ASPECT_1x1;
$info->format = GrTextureFormat_t::GR_TEXFMT_RGB_565;
$info->data = str_repeat(pack('v', 0xFA01), 64 * 64);
$info->flush();

//testGrTexInfo($info);

$size2 = grTexTextureMemRequired(
	GrEvenOdd_t::GR_MIPMAPLEVELMASK_BOTH,
    $info
);

echo "[$size2]\n";

grGlideShutdown();
?>
--EXPECT--
[8192]
[8192]