<?php

include_once('helper.php');


function makeCheckerTexture()
{
    $pixel = pack('v', 0xFA00); // 'v' = 16-bit little endian
    return str_repeat($pixel, 64 * 64);
}

$vtx1 = new GrVertex;
$vtx1->x = '100';
$vtx1->y = 100;
$vtx1->r = $vtx1->g = $vtx1->b = 255;
$vtx1->oow = 1.0;
$vtx1->tmuvtx[0] = new GrTmuVertex;
$vtx1->tmuvtx[0]->sow = 0.0;
$vtx1->tmuvtx[0]->tow = 0.0;
//$vtx1->tmuvtx[0]->oow = 1.0;

$vtx2 = new GrVertex;
$vtx2->x = '300';
$vtx2->y = '100';
$vtx2->r = $vtx2->g = $vtx2->b = 0;
$vtx2->oow = 1.0;
$vtx2->tmuvtx[0] = new GrTmuVertex;
$vtx2->tmuvtx[0]->sow = 1.0;
$vtx2->tmuvtx[0]->tow = 0.0;
//$vtx2->tmuvtx[0]->oow = 1.0;

$vtx3 = new GrVertex;
$vtx3->x = 200.0;
$vtx3->y = 300.0;
$vtx3->r = $vtx3->g = $vtx3->b = 255;
$vtx3->oow = 1.0;
$vtx3->tmuvtx[0] = new GrTmuVertex;
$vtx3->tmuvtx[0]->sow = 0.5;
$vtx3->tmuvtx[0]->tow = 1.0;
//$vtx3->tmuvtx[0]->oow = 1.0;


$ello = makeCheckerTexture();

$info = new GrTexInfo;
$info->smallLod = GrLOD_t::GR_LOD_64;
$info->largeLod = GrLOD_t::GR_LOD_64;
$info->aspectRatio = GrAspectRatio_t::GR_ASPECT_1x1;
$info->format = GrTextureFormat_t::GR_TEXFMT_RGB_565;
$info->data = $ello;
$info->flush();

testGrTexInfo($info);

//var_dump($info->data);

$max = grTexMaxAddress(GrChipID_t::GR_TMU0);
$min = grTexMinAddress(GrChipID_t::GR_TMU0);
echo "min: $min, max: $max\n";

grTexDownloadMipMap(
    GrChipID_t::GR_TMU0,
    0,
    GrEvenOdd_t::GR_MIPMAPLEVELMASK_BOTH,
    $info
);

$max = grTexMaxAddress(GrChipID_t::GR_TMU0);
$min = grTexMinAddress(GrChipID_t::GR_TMU0);
echo "min: $min, max: $max\n";
//grSstWinClose(); grGlideShutdown(); exit('ello');

grTexSource(
    GrChipID_t::GR_TMU0,
    0,
    GrEvenOdd_t::GR_MIPMAPLEVELMASK_BOTH,
    $info
);

guTexCombineFunction(
    GrChipID_t::GR_TMU0,
    GrTextureCombineFnc_t::GR_TEXTURECOMBINE_DETAIL_OTHER
);

$aux = [$vtx1, $vtx2, $vtx3];
array_walk($aux, fn($v) => $v->flush());

testGrVertex($vtx1);
testGrVertex($vtx2);
testGrVertex($vtx3);
/*
grAlphaBlendFunction(
    GrAlphaBlendFnc_t::GR_BLEND_SRC_ALPHA,
    GrAlphaBlendFnc_t::GR_BLEND_ONE_MINUS_SRC_ALPHA,
    GrAlphaBlendFnc_t::GR_BLEND_ONE,
    GrAlphaBlendFnc_t::GR_BLEND_ZERO
);
*/

while (!_kbhit()) {
	
	grBufferClear( 0, 0, GrDepth_t::GR_WDEPTHVALUE_FARTHEST );

    grDrawTriangle($vtx1, $vtx2, $vtx3);

	grBufferSwap(1);
}

grSstIdle();

grSstWinClose();

grGlideShutdown();

echo 'done';