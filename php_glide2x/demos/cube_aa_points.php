<?php

include_once('helper.php');

$color = 255.0;

guColorCombineFunction( GrColorCombineFnc_t::GR_COLORCOMBINE_ITRGB );

$vertices = [
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
		
		$vertex->flush();
		
		return $vertex;
	},
    $vertices
);

$angle = 0.0;

grDepthBufferMode(GrDepthBufferMode_t::GR_DEPTHBUFFER_WBUFFER);  // Or GR_DEPTHBUFFER_ZBUFFER
grDepthBufferFunction(GrCmpFnc_t::GR_CMP_LESS);
grDepthMask(true);

$event = new sfEvent;

while(sfWindow_isOpen($window)) {

    $time = microtime(true);

    while (sfWindow_pollEvent($window, $event)) {
        switch ($event->type) {
            case sfEventType::sfEvtClosed:
                break(3);
        }
        break;
    }

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
        //$v->flush();

        $transformed[] = $v;

        grAADrawPoint($v);
    }

    grBufferSwap(1);
    $angle += 0.01;

    $fps = 1 / (microtime(true) - $time);

    sfWindow_setTitle($window, "fps: $fps");
}

grSstIdle();

grSstWinClose();

grGlideShutdown();

echo 'done';