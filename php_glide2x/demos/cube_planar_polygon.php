<?php

include_once('helper.php');

$color = 255.0;

guColorCombineFunction( GrColorCombineFnc_t::GR_COLORCOMBINE_ITRGB );

$centre = new GrVertex;
$centre->x = 320;
$centre->y = 240;

$cubeVertices = [
	//x,	y,		z,		r, 		g, 		b
	[-1, 	-1, 	-1,		$color, 0,		0		],	//0
    [ 1,	-1, 	-1,		0,		$color,	0		],	//1
    [ 1,	 1, 	-1,		0,		0,		$color,	],	//2
    [-1,	 1, 	-1,		$color,	0,		0		],	//3
    [-1,	-1, 	 1,		0,		$color,	0		],	//4
    [ 1,	-1, 	 1,		0,		0,		$color	],	//5
    [ 1,	 1, 	 1,		$color,	0,		0		],	//6
    [-1,	 1, 	 1,		0,		$color,	0		],	//7
];

$vertices = array_map(function($item){

	$vertex = new GrVertex;

	list($vertex->x, $vertex->y, $vertex->z, $vertex->r, $vertex->g, $vertex->b) = $item;
		
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
		$v->flush();

		$transformed[] = $v;
	}
	
	foreach($cubeIndices as $indices){
		grDrawPlanarPolygon(
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