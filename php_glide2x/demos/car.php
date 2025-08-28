<?php

include_once('helper.php');

$parser = new ObjParser();
$parser->load("php_glide2x/demos/Car.obj");



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

$angle = 0.0;

grDepthBufferMode(GrDepthBufferMode_t::GR_DEPTHBUFFER_WBUFFER);  // Or GR_DEPTHBUFFER_ZBUFFER
grDepthBufferFunction(GrCmpFnc_t::GR_CMP_LESS);
grDepthMask(true);
grCullMode( GrCullMode_t::GR_CULL_DISABLE);

while (!_kbhit()) {

    grBufferClear(0x00000000, 0, GrDepth_t::GR_WDEPTHVALUE_FARTHEST);

    foreach($parser->faces as $face){

        $face = array_map(function($vertex) use ($parser, $angle){

            $vert = new GrVertex();

            list($vert->x, $vert->y, $vert->z) = $parser->vertices[$vertex['v']];

            //$vert->x *= -1;
            //$vert->y *= -1;
            //$vert->z *= -1;

            list($vert->r, $vert->g, $vert->b) = shade(
                $parser->normals[$vertex['n']],
                [0.5, 0.5, 0.5],  //light direction
                [255, 255, 255]
            );

            $vert = rotateX($vert, $angle);
            $vert = rotateY($vert, $angle);
            $vert = rotateZ($vert, $angle);

            $vert = project(
                $vert,  // vertex
                .5,     // $fov
                1.0,    // $aspect
                -5,    // $nearZ
            );
            $vert->x = ($vert->x + 1.0) * 320.0; // convert to screen
            $vert->y = (1.0 - $vert->y) * 240.0;
            $vert->z = (1.0 - $vert->z) * 240.0;

            $vert->oow = 1.0 / ($vert->z + 0.00001);

            $vert->flush();

            return $vert;

        }, $face);

        grAADrawPolygonVertexList(
            count($face),
            $face
        );

    }

    grBufferSwap(1);

    $angle += 0.01;
}

grSstIdle();

grSstWinClose();

grGlideShutdown();

echo 'done';