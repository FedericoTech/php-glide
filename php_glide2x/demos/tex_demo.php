<?php

include_once('helper.php');


function makeCheckerTexture()
{
    $myTexture = '';

    for($c = 0; $c < 2; $c++)
        for ($y = 0; $y < 64; $y++) {
            for ($x = 0; $x < 64; $x++) {
                $checker = ((int)($x / 8) ^ (int)($y / 8)) & 1;
                @$myTexture[$y * 64 + $x] = $checker ? 0xFF : 0x00; // white/black
            }
        }

    return $myTexture;
}

$color = 0;

$vtx1 = new GrVertex;
$vtx1->x = '160';
$vtx1->y = 120;
$vtx1->r = $color;
$vtx1->g = 0;
$vtx1->b = 0;
$vtx1->a = 0;

$vtx2 = new GrVertex;
$vtx2->x = '480.0';
$vtx2->y = '180';
$vtx2->r = 0;
$vtx2->g = $color;
$vtx2->b = 0;
$vtx2->a = 128.0;

$vtx3 = new GrVertex;
$vtx3->x = 320.0;
$vtx3->y = 360.0;
$vtx3->r = 0;
$vtx3->g = 0;
$vtx3->b = $color;
$vtx3->a = 255.0;


$ello = makeCheckerTexture();

$info = new GrTexInfo;
$info->smallLod = GrLOD_t::GR_LOD_64;
$info->largeLod = GrLOD_t::GR_LOD_64;
$info->aspectRatio = GrAspectRatio_t::GR_ASPECT_1x1;
$info->format = GrTextureFormat_t::GR_TEXFMT_RGB_565;
$info->data = $ello;
$info->flush();

testGrTexInfo($info);


grTexDownloadMipMap(
    GrChipID_t::GR_TMU0,
    0,
    GrEvenOdd_t::GR_MIPMAPLEVELMASK_BOTH,
    $info
);

//grSstWinClose(); grGlideShutdown(); exit('ello');

grTexSource(
    GrChipID_t::GR_TMU0,
    0,
    GrEvenOdd_t::GR_MIPMAPLEVELMASK_BOTH,
    $info
);

guTexCombineFunction(
    GrChipID_t::GR_TMU0,
    GrTextureCombineFnc_t::GR_TEXTURECOMBINE_MULTIPLY
);

$aux = [$vtx1, $vtx2, $vtx3];
array_walk($aux, fn($v) => $v->flush());

while (!_kbhit()) {
	
	grBufferClear( 0, 0, GrDepth_t::GR_WDEPTHVALUE_FARTHEST );

    grDrawTriangle($vtx1, $vtx2, $vtx3);

	grBufferSwap(1);
}

grSstIdle();

grSstWinClose();

grGlideShutdown();

echo 'done';