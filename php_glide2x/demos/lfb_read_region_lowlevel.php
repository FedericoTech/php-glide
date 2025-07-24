<?php

include_once('helper.php');

$color = 255.0;

guColorCombineFunction( GrColorCombineFnc_t::GR_COLORCOMBINE_ITRGB );

$centre = new GrVertex;
$centre->x = 320;
$centre->y = 240;
$centre->flush();

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

$aux = [$vtx1, $vtx2, $vtx3];
array_walk($aux, fn($v) => $v->flush());

grRenderBuffer(GrBuffer_t::GR_BUFFER_BACKBUFFER);

while (!_kbhit()) {

    grBufferClear( 0, 0, GrDepth_t::GR_WDEPTHVALUE_FARTHEST );

    grDrawTriangle($vtx1, $vtx2, $vtx3);

    grBufferSwap(1);
}

$info = new GrLfbInfo_t;

// Lock the backbuffer for writing
if ($ello = !grLfbLock(
    GrLock_t::GR_LFB_READ_ONLY,
    GrBuffer_t::GR_BUFFER_BACKBUFFER,
    GrLfbWriteMode_t::GR_LFBWRITEMODE_565,
    GrOriginLocation_t::GR_ORIGIN_UPPER_LEFT,
    false,
    $info
)) {
    printf("Failed to lock LFB [$ello]\n");
    grSstWinClose();
    grGlideShutdown();
    return;
}

// Make sure the pointer is valid
if (false && $info->lfbPtr == NULL) {
    printf("Invalid LFB pointer\n");
    grLfbUnlock(GrLock_t::GR_LFB_WRITE_ONLY, GrBuffer_t::GR_BUFFER_BACKBUFFER);
    grSstWinClose();
    grGlideShutdown();
    return;
}

// Unlock when done
grLfbUnlock(GrLock_t::GR_LFB_WRITE_ONLY, GrBuffer_t::GR_BUFFER_BACKBUFFER);

$filename = 'screenshot2.data';

var_dump($info->strideInBytes);

if (file_put_contents($filename, $info->lfbPtr) !== false) {
    echo "Saved. use GIMP and open as Raw image data. In the dialog, select RGB565 Little Endian, Offset 0, Width 1024 and Height 480\n";
} else {
    echo "Failed to save screenshot.raw\n";
}

grSstIdle();

grSstWinClose();

grGlideShutdown();

echo 'done';