<?php

$centre = new GrVertex;
$centre->x = 0;
$centre->y = -4;
$centre->z = 0;

include_once('helper.php');

$parser = new ObjParser();
$parser->load("php_glide2x/demos/Mazinger_Volador.obj");



grRenderBuffer(GrBuffer_t::GR_BUFFER_BACKBUFFER);

grColorCombine(
    GrCombineFunction_t::GR_COMBINE_FUNCTION_LOCAL,
    GrCombineFactor_t::GR_COMBINE_FACTOR_NONE,
    GrCombineLocal_t::GR_COMBINE_LOCAL_ITERATED,
    GrCombineOther_t::GR_COMBINE_OTHER_NONE,
    false
);

grAlphaCombine(
    GrCombineFunction_t::GR_COMBINE_FUNCTION_NONE,
    GrCombineFactor_t::GR_COMBINE_FACTOR_NONE,
    GrCombineLocal_t::GR_COMBINE_LOCAL_NONE,
    GrCombineOther_t::GR_COMBINE_OTHER_NONE,
    false
);

grDepthBufferMode(GrDepthBufferMode_t::GR_DEPTHBUFFER_WBUFFER);   // 16bits float
//grDepthBufferMode(GrDepthBufferMode_t::GR_DEPTHBUFFER_ZBUFFER); //16 bits fixed
grDepthBufferFunction(GrCmpFnc_t::GR_CMP_LESS);
grDepthMask(true);
grCullMode( GrCullMode_t::GR_CULL_NEGATIVE);

$step = .02;

$xAngle = 0.0;
$yAngle = 0.0;
$zAngle = 0.0;

while (!_kbhit()) {

    $key = _getch();
    //arrows
    if($key == 224){
        switch ($key = _getch()){
            case 72: //up
                $xAngle += $step;
                break;
            case 80: // down
                $xAngle -= $step;
                break;
            case 75: //left
                $yAngle -= $step;
                break;
            case 77: //right
                $yAngle += $step;
                break;
        }


        //normal keys
    } else {
        switch (chr($key)){
            case 'q':   // zoom in
                $zAngle += $step;
                break;
            case 'a':   // zoom out
                $zAngle -= $step;
                break;

            case 'w':   // zoom in
                $centre->z += 0.1;
                break;
            case 's':   // zoom out
                $centre->z -= 0.1;
                break;

            case 'z':   // zoom in
                $centre->x -= 0.1;
                break;
            case 'x':   // zoom out
                $centre->x += 0.1;
                break;

            case 'd':   // zoom in
                $centre->y += 0.1;
                break;
            case 'c':   // zoom out
                $centre->y -= 0.1;
                break;

            default:   // exit;
                echo $key . PHP_EOL;
                break 2;
        }
    }

    grBufferClear(0x202020, 0, GrDepth_t::GR_WDEPTHVALUE_FARTHEST);

    foreach($parser->faces as $face){

        $face = array_map(function($vertex) use ($parser, $xAngle, $yAngle, $zAngle, $centre, $face){

            $vert = new GrVertex();

            list($vert->x, $vert->y, $vert->z) = $parser->vertices[$vertex['v']];
			
			//echo $parser->materials[$face['material']]['Kd'] . PHP_EOL;

            list($vert->r, $vert->g, $vert->b) = shade(
                $parser->normals[$vertex['n']],
                [0.5, 0.5, 0.5],  //light direction
                array_map(
					fn($c) => (int) round($c * 255),
					$parser->materials[$face['material']]['Kd'] ?? [200.0, 200.0, 200.0]
				)
            );


            $vert = rotateX($vert, $xAngle);
            $vert = rotateY($vert, $yAngle);
            $vert = rotateZ($vert, $zAngle);

            $vert->x += $centre->x;
            $vert->y += $centre->y;
            $vert->z += $centre->z;

            //$vert->x *= -1;
            $vert->y *= -1; // turn the car
            //$vert->z *= -1;

            $vert = project(
                $vert,  // vertex
                1,     // $fov
                1,    // $aspect
                5,    // $nearZ
            );

            $vert->x = ($vert->x + 1.0) * 340.0; // convert to screen
            $vert->y = (1.0 - $vert->y) * 480.0;


            $vert->flush();

            return $vert;

        }, $face['vertices']);

        grAADrawPolygonVertexList(
            count($face),
            $face
        );

    } // foreach end

    grBufferSwap(1);
}

grSstIdle();

grSstWinClose();

grGlideShutdown();

echo 'done';