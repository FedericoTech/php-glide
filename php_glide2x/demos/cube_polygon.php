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

$faces = [
	[0, 1, 2, 3], // Back face
    [4, 5, 6, 7], // Front face
    [0, 4, 7, 3], // Left face
    [1, 5, 6, 2], // Right face
    [3, 2, 6, 7], // Top face
    [0, 1, 5, 4], // Bottom face
];


$angle = 0.0;

//var_dump($vertices); exit();

grDepthBufferMode(GrDepthBufferMode_t::GR_DEPTHBUFFER_WBUFFER);  // Or GR_DEPTHBUFFER_ZBUFFER
grDepthBufferFunction(GrCmpFnc_t::GR_CMP_LESS);
grDepthMask(true);

while (!_kbhit()) {
	
	grBufferClear( 0, 0, GrDepth_t::GR_WDEPTHVALUE_FARTHEST );

	$vertices = [];
	foreach($cubeVertices as $vertex){
		$v = new GrVertex;
		list($v->x, $v->y, $v->z, $v->r, $v->g, $v->b) = $vertex;

		$v = rotateX($v, $angle);
		$v = rotateY($v, $angle);
		$v = rotateZ($v, $angle);
		
		$v = project($v, 1.0, 1.0, 3.0); // Basic projection
		$v->x = ($v->x + 1.0) * 320.0; // convert to screen
		$v->y = (1.0 - $v->y) * 240.0;
		$v->flush();

		$vertices[] = $v;
	}

	foreach($faces as $face){

		grDrawPolygon(
			8,
			$face,
			$vertices
		);
	}

	grBufferSwap(1);
	$angle += 0.01;
}

grSstIdle();

grSstWinClose();

grGlideShutdown();

echo 'done';