<?php



include_once('helper.php');

$parser = new ObjParser();
//$parser->load('php_glide2x/demos/car.obj');
$parser->load('php_glide2x/demos/Mazinger_Volador.obj');

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

$centre = new GrVertex;
$centre->x = 0;
$centre->y = -4;
$centre->z = 0;

$step = .02;

$xAngle = 0.0;
$yAngle = 0.0;
$zAngle = 0.0;

$light = normalize([0.5, 0.5, 0.5]);

function draw()
{
    $time = microtime(true);
    global $parser, $window, $xAngle, $yAngle, $zAngle;

    grBufferClear(0x202020, 0, GrDepth_t::GR_WDEPTHVALUE_FARTHEST);

    $matrix = rotationMatrix($xAngle, $yAngle, $zAngle);

    $faceCount = 0;

    foreach($parser->faces as $face){

        $face = array_map(function($vertex) use ($face, $matrix){

            global $parser, $centre, $light, $xAngle, $yAngle, $zAngle;

            $vert = new GrVertex;

            list($vert->x, $vert->y, $vert->z) = applyMatrix($parser->vertices[$vertex['v']], $matrix);

            //echo $parser->materials[$face['material']]['Kd'] . PHP_EOL;
/*
            list($vert->r, $vert->g, $vert->b) = array_map(
                fn($c) => (int) round($c * 255),
                $parser->materials[$face['material']]['Kd'] ?? [200.0, 200.0, 200.0]
            );
*/


            $normal =  $parser->normals[$vertex['n']];

            $nml = new GrVertex;
            list($nml->x, $nml->y, $nml->z) = applyMatrix($normal, $matrix);

            //$nml = rotateZ(rotateY(rotateX($nml, $xAngle), $yAngle), $zAngle);

            $normal = [$nml->x, $nml->y, $nml->z];

            list($vert->r, $vert->g, $vert->b) = shade(
                $normal,
                $light,  //light direction
                array_map(
                    fn($c) => (int) round($c * 255),
                    $parser->materials[$face['material']]['Kd'] ?? [200.0, 200.0, 200.0]
                )
            );

/*
            $vert = rotateX($vert, $xAngle);
            $vert = rotateY($vert, $yAngle);
            $vert = rotateZ($vert, $zAngle);
*/

            $vert->x += $centre->x;
            $vert->y += $centre->y;
            $vert->z += $centre->z;

            $vert->y *= -1; // turn the car

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

        $faceCount++;

    } // foreach end

    grBufferSwap(1);

    //echo 'time: ' . (microtime(true) - $time) . PHP_EOL;

    $fps = 1 / (microtime(true) - $time);

    sfWindow_setTitle($window, "fps: $fps, faces: $faceCount");
}

$event = new sfEvent;

while(sfWindow_isOpen($window)){

    while (sfWindow_pollEvent($window, $event)){
        switch($event->type){
            case sfEventType::sfEvtClosed:
                break(3);
            case sfEventType::sfEvtKeyPressed:
                /*
                switch ($event->data->code){
                    case sfKeyCode::sfKeyUp:    //roll up
                        $xAngle += $step;
                        break;
                    case sfKeyCode::sfKeyDown:  //roll down
                        $xAngle -= $step;
                        break;
                    case sfKeyCode::sfKeyLeft:  //turn left
                        $yAngle -= $step;
                        break;
                    case sfKeyCode::sfKeyRight:  //turn right
                        $yAngle += $step;
                        break;
                    case sfKeyCode::sfKeyQ:  //roll left
                        $zAngle += $step;
                        break;
                    case sfKeyCode::sfKeyA:  //roll right
                        $zAngle -= $step;
                        break;
                    case sfKeyCode::sfKeyW:  //forward
                        $centre->z -= 0.1;
                        break;
                    case sfKeyCode::sfKeyS:  //backward
                        $centre->z += 0.1;
                        break;
                    case sfKeyCode::sfKeyZ:  //move left
                        $centre->x -= 0.1;
                        break;
                    case sfKeyCode::sfKeyX:  //move right
                        $centre->x += 0.1;
                        break;
                    case sfKeyCode::sfKeyD:  //move up
                        $centre->y += 0.1;
                        break;
                    case sfKeyCode::sfKeyC:  //move down
                        $centre->y -= 0.1;
                        break;
                    case sfKeyCode::sfKeyEscape:  //exit
                        break(3);
                } // key pressed switch

                draw();
                */
                break;
        } // witch event type
    } //pollEvent loop

    // exit;
    if (sfKeyboard_isKeyPressed(sfKeyCode::sfKeyEscape)){
        break;
    }

    $change = 0;

    //roll up
    if (sfKeyboard_isKeyPressed(sfKeyCode::sfKeyUp)){
        $xAngle += $step;
        ++$change;
    }

    //roll down
    if (sfKeyboard_isKeyPressed(sfKeyCode::sfKeyDown)){
        $xAngle -= $step;
        ++$change;
    }

    //turn left
    if (sfKeyboard_isKeyPressed(sfKeyCode::sfKeyLeft)){
        $yAngle -= $step;
        ++$change;
    }

    //turn right
    if (sfKeyboard_isKeyPressed(sfKeyCode::sfKeyRight)){
        $yAngle += $step;
        ++$change;
    }

    // roll left
    if (sfKeyboard_isKeyPressed(sfKeyCode::sfKeyQ)){
        $zAngle += $step;
        ++$change;
    }

    // roll right
    if (sfKeyboard_isKeyPressed(sfKeyCode::sfKeyA)){
        $zAngle -= $step;
        ++$change;
    }

    //forward
    if (sfKeyboard_isKeyPressed(sfKeyCode::sfKeyW)){
        $centre->z -= $step;
        ++$change;
    }

    //backward
    if (sfKeyboard_isKeyPressed(sfKeyCode::sfKeyS)){
        $centre->z += $step;
        ++$change;
    }

    //move left
    if (sfKeyboard_isKeyPressed(sfKeyCode::sfKeyZ)){
        $centre->x -= $step;
        ++$change;
    }

    //move right
    if (sfKeyboard_isKeyPressed(sfKeyCode::sfKeyX)){
        $centre->x += $step;
        ++$change;
    }

    // move up
    if (sfKeyboard_isKeyPressed(sfKeyCode::sfKeyD)){
        $centre->y += $step;
        ++$change;
    }

    // move down
    if (sfKeyboard_isKeyPressed(sfKeyCode::sfKeyC)){
        $centre->y -= $step;
        ++$change;
    }

    if($change){
        draw();
    }
}

grSstIdle();

grSstWinClose();

grGlideShutdown();

sfWindow_close($window);

echo 'done';