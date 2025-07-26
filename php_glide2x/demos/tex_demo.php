<?php

include_once('helper.php');


$amount = grTexCalcMemRequired(
    GrLOD_t::GR_LOD_4,
    GrLOD_t::GR_LOD_16,
    GrAspectRatio_t::GR_ASPECT_1x4,
    GrTextureFormat_t::GR_TEXFMT_16BIT
);

echo "amount: $amount\n";

while (!_kbhit()) {
	
	grBufferClear( 0, 0, GrDepth_t::GR_WDEPTHVALUE_FARTHEST );


	

	grBufferSwap(1);
}

grSstIdle();

grSstWinClose();

grGlideShutdown();

echo 'done';