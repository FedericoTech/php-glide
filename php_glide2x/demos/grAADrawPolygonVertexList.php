<?php

include_once('helper.php');

$color = 255.0;

guColorCombineFunction( GrColorCombineFnc_t::GR_COLORCOMBINE_ITRGB );

$centre = new GrVertex;
$centre->x = 320;
$centre->y = 240;
$centre->flush();

$vtx1 = new GrVertex;
$vtx1->x = '520';
$vtx1->y = 240;
$vtx1->r = $color;
$vtx1->g = 0;
$vtx1->b = 0;
$vtx1->a = 0;

$vtx2 = new GrVertex;
$vtx2->x = '420.0';
$vtx2->y = '412.16';
$vtx2->r = 0;
$vtx2->g = $color;
$vtx2->b = 0;
$vtx2->a = 128.0;

$vtx3 = new GrVertex;
$vtx3->x = 220;
$vtx3->y = 412.16;
$vtx3->r = 0;
$vtx3->g = 0;
$vtx3->b = $color;
$vtx3->a = 255.0;

$vtx4 = new GrVertex;
$vtx4->x = '120';
$vtx4->y = 240;
$vtx4->r = $color;
$vtx4->g = 0;
$vtx4->b = 0;
$vtx4->a = 0;

$vtx5 = new GrVertex;
$vtx5->x = '220.0';
$vtx5->y = '67.84';
$vtx5->r = 0;
$vtx5->g = $color;
$vtx5->b = 0;
$vtx5->a = 128.0;

$vtx6 = new GrVertex;
$vtx6->x = 420;
$vtx6->y = 67.84;
$vtx6->r = 0;
$vtx6->g = 0;
$vtx6->b = $color;
$vtx6->a = 255.0;

//see the case the indices are less than vertices
$indices = [0, 1, 2, 0, 3, 4, 0, 5, 6, 0];

$angle = 0.0;

while (!_kbhit()) {
	
	grBufferClear( 0, 0, GrDepth_t::GR_WDEPTHVALUE_FARTHEST );
	
	$angle_minus = 0 - $angle;
	
	$vtr1 = rotate_point($vtx1, $angle_minus, $centre);
    $vtr2 = rotate_point($vtx2, $angle_minus, $centre);
    $vtr3 = rotate_point($vtx3, $angle_minus, $centre);
	
	$vtr4 = rotate_point($vtx4, $angle_minus, $centre);
    $vtr5 = rotate_point($vtx5, $angle_minus, $centre);
    $vtr6 = rotate_point($vtx6, $angle_minus, $centre);
	
	$aux = [$vtr1, $vtr2, $vtr3, $vtr4, $vtr5, $vtr6];
	array_walk($aux, fn($v) => $v->flush());

	$vertices = [$centre, $vtr1, $vtr2, $vtr3, $vtr4, $centre, $vtr5, $vtr6, $centre];

	grAADrawPolygonVertexList(
		count($vertices), 	//whatever is highter whether indices or vertices
		$vertices
	);

    $vtr1 = rotate_point($vtx1, $angle, $centre);
    $vtr2 = rotate_point($vtx2, $angle, $centre);
    $vtr3 = rotate_point($vtx3, $angle, $centre);
	
	$vtr4 = rotate_point($vtx4, $angle, $centre);
    $vtr5 = rotate_point($vtx5, $angle, $centre);
    $vtr6 = rotate_point($vtx6, $angle, $centre);

	$vertices = [$centre, $vtr1, $vtr2, $vtr3, $vtr4, $centre, $vtr5, $vtr6, $centre];
	array_walk($vertices, fn($v) => $v->flush());

	grAADrawPolygonVertexList(
		count($vertices), 	//whatever is highter whether indices or vertices
		$vertices
	);

	grBufferSwap(1);
	
	//usleep(1000); // Reduce CPU usage
	$angle += 0.01;
}

grSstIdle();

grSstWinClose();

grGlideShutdown();

echo 'done';