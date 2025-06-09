<?php 

function rotate_point(GrVertex $point, float $angle_rad, $origin = null) {
    
	if ($origin === null) {
		$origin = new GrVertex;
		$origin->x = 0.0;
		$origin->y = 0.0;
    }

    $sin = sin($angle_rad);
    $cos = cos($angle_rad);

    // Translate point back to origin
    $x = $point->x - $origin->x;
    $y = $point->y - $origin->y;

    // Rotate
    $x_new = $x * $cos - $y * $sin;
    $y_new = $x * $sin + $y * $cos;
	
	$new = clone $point;
	//$new = new GrVertex;
	
	$new->x = $x_new + $origin->x;
	$new->y = $y_new + $origin->y;
	
	//echo "[$new->r]" . PHP_EOL;
	/*
	// Copy all other relevant properties
    //$new->z = $point->z;
    $new->r = $point->r;
    $new->g = $point->g;
    $new->b = $point->b;
    //$new->ooz = $point->ooz;
    $new->a = $point->a;
    //$new->oow = $point->oow;
	*/
	
	$new->flush();
	
    // Translate back
    return $new;
}

//this handler is to gracefully close the script when CTRL+C
function ctrl_handler(int $event)
{
    switch ($event) {
        case PHP_WINDOWS_EVENT_CTRL_C:
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