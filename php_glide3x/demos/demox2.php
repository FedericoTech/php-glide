<?php

include_once('helper.php');

$color = 255.0;

$vtx1 = new Vec2;
$vtx2 = new Vec2;
$vtx3 = new Vec2;

grColorCombine(
   GrCombineFunction_t::GR_COMBINE_FUNCTION_LOCAL,   //function
   GrCombineFactor_t::GR_COMBINE_FACTOR_NONE,      //factor
   GrCombineLocal_t::GR_COMBINE_LOCAL_CONSTANT,   //local
   GrCombineOther_t::GR_COMBINE_OTHER_NONE,       //other
   false                      //invert
);

grConstantColorValue(0x00ff0000);

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

	grBufferClear( 0, 0, 0 );

	grDrawTriangle($vtx1, $vtx2, $vtx3);
	
	grBufferSwap(1);
		
	usleep(1000); // Reduce CPU usage
}

grFinish();

grSstWinClose($context);

grGlideShutdown();

echo 'done';