<?php

include_once('helper.php');

$color = 255.0;

guColorCombineFunction( GrColorCombineFnc_t::GR_COLORCOMBINE_ITRGB );

$centre = new GrVertex;
$centre->x = 320;
$centre->y = 240;

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

$arr = [$vtx1, $vtx2, $vtx3];
array_walk($arr , fn($vt) => $vt->flush());


while (!_kbhit()) {
	
	$angle = microtime(true); // radians per second (change as needed)

    $vtr1 = rotate_point($vtx1, $angle, $centre);
    $vtr2 = rotate_point($vtx2, $angle, $centre);
    $vtr3 = rotate_point($vtx3, $angle, $centre);

	grBufferClear( 0, 0, GrDepth_t::GR_WDEPTHVALUE_FARTHEST );

	grAADrawTriangle($vtr1, $vtr2, $vtr3, true, false, true);
	
	grBufferSwap(1);
	
	//usleep(1000); // Reduce CPU usage
}

grSstIdle();

grSstWinClose();

grGlideShutdown();

echo 'done';