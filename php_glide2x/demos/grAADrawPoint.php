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
$vtx1->r = 0;
$vtx1->g = $color;
$vtx1->b = $color;
$vtx1->a = 0;

$vtx2 = new GrVertex;
$vtx2->x = '480.0';
$vtx2->y = '180';
$vtx2->r = $color;
$vtx2->g = 0;
$vtx2->b = $color;
$vtx2->a = 128.0;

$vtx3 = new GrVertex;
$vtx3->x = 320.0;
$vtx3->y = 360.0;
$vtx3->r = $color;
$vtx3->g = $color;
$vtx3->b = 0;
$vtx3->a = 255.0;

$angle = 0.0;

while (!_kbhit()) {
	
    $vtr1 = rotate_point($vtx1, $angle, $centre);
    $vtr2 = rotate_point($vtx2, $angle, $centre);
    $vtr3 = rotate_point($vtx3, $angle, $centre);
	
	$aux = [$vtr1, $vtr2, $vtr3];
	array_walk($aux, fn($v) => $v->flush());
	
	grBufferClear( 0, 0, GrDepth_t::GR_WDEPTHVALUE_FARTHEST );

	grAADrawPoint($vtr1);
	grAADrawPoint($vtr2);
	grAADrawPoint($vtr3);
	
	grBufferSwap(1);
	
	$angle += 0.01;
}

grSstIdle();

grSstWinClose();

grGlideShutdown();

echo 'done';