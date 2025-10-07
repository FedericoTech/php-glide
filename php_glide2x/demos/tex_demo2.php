<?php

include_once('helper.php');


function makeCheckerTexture(int $w = 256, int $h = 256, int $cell = 8): string
{
    return file_get_contents('sonic256x256.data')
        . file_get_contents('tails128x128.data')
        . file_get_contents('knukles64x64.data')
        . file_get_contents('robotnick32x32.data')
        . file_get_contents('amy16x16.data')
        . file_get_contents('shadow8x8.data');



/*
    $orange = pack('v', 0xFA00); // 16-bit little-endian color
    $other  = pack('v', 0x00AF);

    $out = '';

    for ($y = 0; $y < $h; $y++) {
        $yBlock = intdiv($y, $cell);
        for ($x = 0; $x < $w; $x++) {
            $xBlock = intdiv($x, $cell);
            $checker = ($xBlock ^ $yBlock) & 1;
            $out .= $checker ? $orange : $other;
        }
    }

    return $out;
*/
}

$zoom = 100;

$centre = new GrVertex;
$centre->x = 320;
$centre->y = 240;
$centre->flush();


$vtx0 = new GrVertex;
$vtx0->x = - 100;
$vtx0->y = - 100;
$vtx0->z = 0;
//$vtx0->r = $vtx0->g = $vtx0->b = 255;
$vtx0->oow = 1.0;
$vtx0->tmuvtx[0] = new GrTmuVertex;
$vtx0->tmuvtx[0]->sow = 0.0;
$vtx0->tmuvtx[0]->tow = 256.0;
//$vtx1->tmuvtx[0]->oow = 1.0;

$vtx1 = new GrVertex;
$vtx1->x = 100;
$vtx1->y = -100;
$vtx1->z = 0;
//$vtx1->r = $vtx1->g = $vtx1->b = 0;
$vtx1->oow = 1.0;
$vtx1->tmuvtx[0] = new GrTmuVertex;
$vtx1->tmuvtx[0]->sow = 256;
$vtx1->tmuvtx[0]->tow = 256.0;
//$vtx2->tmuvtx[0]->oow = 1.0;

$vtx2 = new GrVertex;
$vtx2->x = 100;
$vtx2->y = 100;
$vtx2->z = 0;
//$vtx2->r = $vtx2->g = $vtx2->b = 255;
$vtx2->oow = 1.0;
$vtx2->tmuvtx[0] = new GrTmuVertex;
$vtx2->tmuvtx[0]->sow = 256;
$vtx2->tmuvtx[0]->tow = 0;

$vtx3 = new GrVertex;
$vtx3->x = -100.0;
$vtx3->y = 100.0;
$vtx3->z = 0;
//$vtx3->r = $vtx3->g = $vtx3->b = 255;
$vtx3->oow = 1.0;
$vtx3->tmuvtx[0] = new GrTmuVertex;
$vtx3->tmuvtx[0]->sow = 0;
$vtx3->tmuvtx[0]->tow = 0;


//START TESTING THESE FUNCTIONS
grColorCombine(
    GrCombineFunction_t::GR_COMBINE_FUNCTION_SCALE_OTHER,
    GrCombineFactor_t::GR_COMBINE_FACTOR_ONE,
    GrCombineLocal_t::GR_COMBINE_LOCAL_NONE,
    GrCombineOther_t::GR_COMBINE_OTHER_TEXTURE,
    false
);

grTexCombine(
    GrChipID_t::GR_TMU0,
    GrCombineFunction_t::GR_COMBINE_FUNCTION_LOCAL,
    GrCombineFactor_t::GR_COMBINE_FACTOR_NONE,
    GrCombineFunction_t::GR_COMBINE_FUNCTION_LOCAL,
    GrCombineFactor_t::GR_COMBINE_FACTOR_NONE,
    false, false
);

grTexClampMode(GrChipID_t::GR_TMU0, GrTextureClampMode_t::GR_TEXTURECLAMP_CLAMP, GrTextureClampMode_t::GR_TEXTURECLAMP_CLAMP);
grTexFilterMode(GrChipID_t::GR_TMU0, GrTextureFilterMode_t::GR_TEXTUREFILTER_BILINEAR, GrTextureFilterMode_t::GR_TEXTUREFILTER_BILINEAR);

//END TESTING THESE FUNCTIONS


$ello = makeCheckerTexture();

$info = new GrTexInfo;
$info->smallLod = GrLOD_t::GR_LOD_8;
$info->largeLod = GrLOD_t::GR_LOD_256;
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

grTexMipMapMode(
    GrChipID_t::GR_TMU0,
    GrMipMapMode_t::GR_MIPMAP_NEAREST_DITHER,
    true
);

$aux = [$vtx0, $vtx1, $vtx2, $vtx3];
array_walk($aux, fn($v) => $v->flush());

testGrVertex($vtx0);
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

$angle = 0.0;
$zoom = 1.0;


function draw()
{
    global $vtx0, $vtx1, $vtx2, $vtx3, $angle, $centre, $zoom;

    $aux = [$vtx0, $vtx1, $vtx2, $vtx3];

    $aux = array_map(function($vtx) use ($angle, $centre, $zoom) {
            $v = clone $vtx;

            $v->x *= $zoom;
            $v->y *= $zoom;

            $v->x += $centre->x;
            $v->y += $centre->y;
            $v = rotate_point($v, $angle, $centre);
            $v->flush();
            return $v;
        },
        $aux
    );

    grBufferClear( 0, 0, GrDepth_t::GR_WDEPTHVALUE_FARTHEST );

    grDrawTriangle($aux[0], $aux[1], $aux[2]);

    grDrawTriangle($aux[0], $aux[2], $aux[3]);

    grBufferSwap(1);

    $angle += 0.01;
}

$event = new sfEvent;

while(sfWindow_isOpen($window)){

    while (sfWindow_pollEvent($window, $event)) {
        switch ($event->type) {
            case sfEventType::sfEvtClosed:
                break(3);
        }
        break;
    }

    // exit;
    if (sfKeyboard_isKeyPressed(sfKeyCode::sfKeyEscape)){
        break;
    }

    $change = 0;

    //forward
    if (sfKeyboard_isKeyPressed(sfKeyCode::sfKeyW)){
        $zoom += 0.01;
    }

    //backward
    if (sfKeyboard_isKeyPressed(sfKeyCode::sfKeyS)){
        $zoom -= 0.01;
    }

    //move left
    if (sfKeyboard_isKeyPressed(sfKeyCode::sfKeyLeft)){
        $centre->x -= 10;
    }

    //move right
    if (sfKeyboard_isKeyPressed(sfKeyCode::sfKeyRight)){
        $centre->x += 10;
    }

    // move up
    if (sfKeyboard_isKeyPressed(sfKeyCode::sfKeyUp)){
        $centre->y += 10;
    }

    // move down
    if (sfKeyboard_isKeyPressed(sfKeyCode::sfKeyDown)){
        $centre->y -= 10;
    }

    draw();
}

grSstIdle();

grSstWinClose();

grGlideShutdown();

echo 'done';