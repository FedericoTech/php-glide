<?php

define('S_FACTOR', 20);

grGlideInit();

$n = 'ello';

if (!($m = grGet(grGet_t::GR_NUM_BOARDS, $n))) {
	printf("ERROR: no 3Dfx Interactive Graphics Accelerator!\n");
	grGlideShutdown();
	return -1;
}

printf("[$n]\nhardware %s (glide 3) n of boards: %s - %d\n", grGetString(GrString_t::GR_HARDWARE), $n, $m);

grSstSelect(0);

$context = null;

if(($context = grSstWinOpen(
	(int)NULL,			// hWin cast to FxU32 or null if console app or Voodoo 1 or full screen.
	GrScreenResolution_t::GR_RESOLUTION_640x480,  // screen resolution
	GrScreenRefresh_t::GR_REFRESH_60Hz,        // refresh rate
	GrColorFormat_t::GR_COLORFORMAT_ARGB,    // color format
	GrOriginLocation_t::GR_ORIGIN_LOWER_LEFT,   // origin location
	2,                      // number of buffers
	0                       // number of aux buffers
)) == 0) {
	printf("ERROR: failed to open graphics context! (glide 3)\n");
	grGlideShutdown();
	return -1;
};

sleep(3); //wait for initialization


class VertexARGB extends Vec2 {
	public int $argb;
}

grVertexLayout(
   GrParams_t::GR_PARAM_XY,     //this param is X and Y
   0,               //it starts on the first byte
   GrMode_t::GR_PARAM_ENABLE  //we enable it
);
	
$aCU = new Vec2();
$aCU->x = -.5;
$aCU->y = -1.0;

$bCU = new Vec2(.5, -1.0);

$cCU = new Vec2(y:1.0);
$cCU->x = .0;

grBufferClear(
	0,	//color
	0,	//alpha
	0	//depth
);

grColorCombine(
   GrCombineFunction_t::GR_COMBINE_FUNCTION_LOCAL,   //function
   GrCombineFactor_t::GR_COMBINE_FACTOR_NONE,      //factor
   GrCombineLocal_t::GR_COMBINE_LOCAL_CONSTANT,   //local
   GrCombineOther_t::GR_COMBINE_OTHER_NONE,       //other
   false                      //invert
);

grConstantColorValue(0x00ff0000);

$x = 50;
$y = 200;

$aCU->x = $aCU->x * S_FACTOR + $x;
$aCU->y = $aCU->y * S_FACTOR + $y;

$bCU->x = $bCU->x * S_FACTOR + $x;
$bCU->y = $bCU->y * S_FACTOR + $y;

$cCU->x = $cCU->x * S_FACTOR + $x;
$cCU->y = $cCU->y * S_FACTOR + $y;


while(true){

	grDrawTriangle($aCU, $bCU, $cCU);

	grBufferSwap(1);
}

grGlideShutdown();

/*
class Vec3 extends Vec2
{
	public $z;
	
	public function __construct($x=8, $y=45, $z=4)
	{
		parent::__construct($x, $y);
		
		$this->z = $z;
	}
}
*/

/*
$lala = new Vec2(y:10.34);
//$lala = new Vec2();
$lala->myMethod();

var_dump($lala);
*/
echo 'done';
