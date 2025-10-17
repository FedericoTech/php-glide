<?php

include_once('helper.php');

$color = 255.0;

//guColorCombineFunction( GrColorCombineFnc_t::GR_COLORCOMBINE_ITRGB );

grRenderBuffer(GrBuffer_t::GR_BUFFER_BACKBUFFER);

$filename = 'screenshot.data';

$buffer = file_get_contents($filename);


grLfbWriteRegion(
    GrBuffer_t::GR_BUFFER_BACKBUFFER,
    0, 0,
    GrLfbSrcFmt_t::GR_LFB_SRC_FMT_565,
    640, 480,
    640 * 2, $buffer
);

$event = new sfEvent;

while(sfWindow_isOpen($window)) {

    while (sfWindow_pollEvent($window, $event)) {
        switch ($event->type) {
            case sfEventType::sfEvtClosed:
                break(3);
        }
        break;
    }

	grBufferSwap(1);
}

grSstIdle();

grSstWinClose();

grGlideShutdown();

echo 'done';