<?php

include_once('helper.php');

$color = 255.0;

guColorCombineFunction( GrColorCombineFnc_t::GR_COLORCOMBINE_ITRGB );

$centre = new GrVertex;
$centre->x = 320;
$centre->y = 240;

$cubeVertices = [
	//x,	y,		z,		r, 		g, 		b		a
	[-1, 	-1, 	-1,		$color, 0,		0,		0.3],	//0
    [ 1,	-1, 	-1,		0,		$color,	0,		0.3],	//1
    [ 1,	 1, 	-1,		0,		0,		$color,	0.3],	//2
    [-1,	 1, 	-1,		$color,	0,		0,		0.3],	//3
    [-1,	-1, 	 1,		0,		$color,	0,		0.3],	//4
    [ 1,	-1, 	 1,		0,		0,		$color,	0.3],	//5
    [ 1,	 1, 	 1,		$color,	0,		0,		0.3],	//6
    [-1,	 1, 	 1,		0,		$color,	0,		0.3],	//7
];

$vertices = array_map(function($item){

	$vertex = new GrVertex;

	list($vertex->x, $vertex->y, $vertex->z, $vertex->r, $vertex->g, $vertex->b, $vertex->a) = $item;
		
	return $vertex;
}, $cubeVertices);

$cubeIndices = [
	[
		0, 1, 2, 3, //front
		0, 4, 5, 1,	//top
		0, 3, 7, 4,	//left
	],[
		6, 7, 3, 2,	// bottom
		6, 5, 4, 7,	//back
		6, 2, 1, 5	//right
	]
];

$angle = 0.0;


grDepthBufferMode(GrDepthBufferMode_t::GR_DEPTHBUFFER_WBUFFER);  // Or GR_DEPTHBUFFER_ZBUFFER
grDepthBufferFunction(GrCmpFnc_t::GR_CMP_LESS);
grDepthMask(true);
grCullMode( GrCullMode_t::GR_CULL_POSITIVE );


$fogTable = [
	0, 5, 10, 15, 19, 24, 28, 33,
    37, 41, 45, 49, 53, 56, 60, 63,
    67, 70, 73, 76, 79, 82, 85, 88,
    91, 94, 96, 99, 101, 104, 106, 108,
    111, 113, 115, 117, 119, 121, 123, 125,
    127, 129, 131, 133, 134, 136, 138, 139,
    141, 142, 144, 145, 147, 148, 150, 151,
    153, 154, 156, 157, 158, 160, 161, 255
];
/*
grFogColorValue(0x00FFFFFF);
grFogTable($fogTable);
grFogMode(GrFogMode_t::GR_FOG_WITH_TABLE);
*/



while (!_kbhit()) {
	
	grBufferClear( 0, 0, GrDepth_t::GR_WDEPTHVALUE_FARTHEST );

	$transformed = [];
	foreach($vertices as $vertex){
		$v = clone $vertex;
		
		$v = rotateX($v, $angle);
		$v = rotateY($v, $angle);
		$v = rotateZ($v, $angle);
		
        $v = project($v, 1.0, 1.0, 3.0); // Basic projection
        $v->x = ($v->x + 1.0) * 320.0; // convert to screen
        $v->y = (1.0 - $v->y) * 240.0;
		
		//$v->oow = 1.0 / $v->z;
		$v->flush();

		$transformed[] = $v;
	}
		
	foreach($cubeIndices as $indices){
		grAADrawPolygon(
			count($indices),
			$indices,
			$transformed
		);
	}

	grBufferSwap(1);
	$angle += 0.01;
}

grSstIdle();

grSstWinClose();

grGlideShutdown();

echo 'done';