<?php 

$context = null;

//this handler is to gracefully close the script when CTRL+C
function ctrl_handler(int $event)
{
	global $context;

    switch ($event) {
        case PHP_WINDOWS_EVENT_CTRL_C:
			grSstWinClose($context);
            grGlideShutdown();
			exit();
            break;
        case PHP_WINDOWS_EVENT_CTRL_BREAK:
            echo "You have pressed CTRL+BREAK\n";
            break;
    }
}

sapi_windows_set_ctrl_handler('ctrl_handler');

grGlideInit();

$n = 'ello';

if (!($m = grGet(grGet_t::GR_NUM_BOARDS, $n))) {
	printf("ERROR: no 3Dfx Interactive Graphics Accelerator!\n");
	grGlideShutdown();
	return -1;
}

printf("[$n]\nhardware %s (glide 3) n of boards: %s - %d\n", grGetString(GrString_t::GR_HARDWARE), $n, $m);

grSstSelect(0);



if(!$context = grSstWinOpen(
	null,									// hWin cast to FxU32 or null if console app or Voodoo 1 or full screen.
	GrScreenResolution_t::GR_RESOLUTION_640x480,	// screen resolution
	GrScreenRefresh_t::GR_REFRESH_60Hz,				// refresh rate
	GrColorFormat_t::GR_COLORFORMAT_ABGR,							// color format
	GrOriginLocation_t::GR_ORIGIN_LOWER_LEFT,							// origin location
	2,												// number of buffers
	0												// number of aux buffers
)) {
    printf("ERROR: failed to open graphics context! (glide 3)\n");
    grGlideShutdown();
    return -1;
};