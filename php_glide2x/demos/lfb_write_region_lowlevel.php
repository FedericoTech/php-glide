<?php

include_once('helper.php');

$color = 255.0;

//guColorCombineFunction( GrColorCombineFnc_t::GR_COLORCOMBINE_ITRGB );

grRenderBuffer(GrBuffer_t::GR_BUFFER_BACKBUFFER);

$info = new GrLfbInfo_t;

// Lock the backbuffer for writing
if ($ello = !grLfbLock(
    GrLock_t::GR_LFB_WRITE_ONLY,
    GrBuffer_t::GR_BUFFER_BACKBUFFER,
    GrLfbWriteMode_t::GR_LFBWRITEMODE_565,
    GrOriginLocation_t::GR_ORIGIN_UPPER_LEFT,
    false, $info)
) {
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

$size = 200;
$x = 150;
$y = 150;

$red = pack('v', 0xF800);

// Draw a red square (in RGB565: red = 0xF800)
for ($j = 0; $j < $size; $j++) {
    for ($i = 0; $i < $size; $i++) {
        $px = $x + $i;
        $py = $y + $j;
        $index = $py * ($info->strideInBytes / 2) + $px;
        @$info->lfbPtr[$index * 2] = $red[0];
        @$info->lfbPtr[$index * 2 + 1] = $red[1]; // Pure red
    }
}

$info->flush(); //apply changes in the underlaying memory.

// Unlock when done
grLfbUnlock(GrLock_t::GR_LFB_WRITE_ONLY, GrBuffer_t::GR_BUFFER_BACKBUFFER);

while (!_kbhit()) {

	grBufferSwap(1);
}

grSstIdle();

grSstWinClose();

grGlideShutdown();

echo 'done';