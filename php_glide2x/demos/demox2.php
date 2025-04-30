<?php

$color = 255.0;

grGlideInit();

$hwConfig = new GrHwConfiguration;


if(!grSstQueryHardware($hwConfig)){
	echo 'ERROR: grSstQueryHardware din\'t work!' . PHP_EOL;
	grGlideShutdown();
}

if(!$hwConfig->num_sst){
	echo 'ERROR: no 3Dfx Interactive Graphics Accelerator!' . PHP_EOL;
	grGlideShutdown();
	return -1;
}



switch($hwConfig->SSTs[0]->type){
	case GrSstType::GR_SSTTYPE_VOODOO:
		echo 'hardware Voodoo 1 (glide 2)' . PHP_EOL;
		break;
	case GrSstType::GR_SSTTYPE_SST96:
		echo 'hardware Voodoo rush (glide 2)' . PHP_EOL;
		break;
	case GrSstType::GR_SSTTYPE_AT3D:
		echo 'hardware Voodoo rush AT3D (glide 2)' . PHP_EOL;
		break;
	case GrSstType::GR_SSTTYPE_Voodoo2:
		echo 'hardware Voodoo 2 (glide 2)' . PHP_EOL;
		break;
	default:
		echo 'hardware unknown (glide 2)' . PHP_EOL;
		break;
}

// Select SST 0 and open up the hardware
grSstSelect(0);

if(!grSstWinOpen(
	null,									// hWin cast to FxU32 or null if console app or Voodoo 1 or full screen.
	GrScreenResolution_t::GR_RESOLUTION_640x480,	// screen resolution
	GrScreenRefresh_t::GR_REFRESH_60Hz,				// refresh rate
	GrColorFormat_t::GR_COLORFORMAT_ABGR,							// color format
	GrOriginLocation_t::GR_ORIGIN_LOWER_LEFT,							// origin location
	2,												// number of buffers
	0												// number of aux buffers
)) {
    printf("ERROR: failed to open graphics context! (glide 2)\n");
    grGlideShutdown();
    return -1;
};

$vtx1 = new GrVertex;
$vtx2 = new GrVertex;
$vtx3 = new GrVertex;

guColorCombineFunction( GrColorCombineFnc_t::GR_COLORCOMBINE_ITRGB );

$vtx1->x = 160;
$vtx1->y = 120;
$vtx1->r = $color;
$vtx1->g = 0;
$vtx1->b = 0;
$vtx1->a = 0;

$vtx2->x = '480.0';
$vtx2->y = '180';
$vtx2->r = 0;
$vtx2->g = $color;
$vtx2->b = 0;
$vtx2->a = 128.0;

$vtx3->x = 320.0;
$vtx3->y = 360.0;
$vtx3->r = 0;
$vtx3->g = 0;
$vtx3->b = $color;
$vtx3->a = 255.0;

while (!_kbhit()) {

	grBufferClear( 0, 0, GrDepth_t::GR_WDEPTHVALUE_FARTHEST );

	grDrawTriangle($vtx1, $vtx2, $vtx3);
	
	grBufferSwap(1);
	
	usleep(1000); // Reduce CPU usage
}

grSstWinClose();

grGlideShutdown();

echo 'done';