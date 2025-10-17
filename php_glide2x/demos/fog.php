<?php

include_once('helper.php');

$color = 255.0;

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

$fogTable = [];
grFogMode(GrFogMode_t::GR_FOG_WITH_TABLE);
grFogColorValue(0x00FFFFff); // Fog color: blue
	
guFogGenerateLinear($fogTable, 32.0, 64.0); // start and end Z for fog

//var_dump($fogTable);

grFogTable($fogTable);

$centre = new GrVertex;
$centre->x = 320;
$centre->y = 240;
$centre->flush();

$vtx1 = new GrVertex;
$vtx1->x = '160';
$vtx1->y = 120;
$vtx1->z = 25;
$vtx1->r = $color;
$vtx1->g = 0;
$vtx1->b = 0;
$vtx1->a = 0.0;
$vtx1->oow = 1.0 / $vtx1->z;

$vtx2 = new GrVertex;
$vtx2->x = '480.0';
$vtx2->y = '180';
$vtx2->z = 128;
$vtx2->r = 0;
$vtx2->g = $color;
$vtx2->b = 0;
$vtx2->a = 128.0;
$vtx2->oow = 1.0 / $vtx2->z;

$vtx3 = new GrVertex;
$vtx3->x = 320.0;
$vtx3->y = 360.0;
$vtx3->z = 255;
$vtx3->r = 0;
$vtx3->g = 0;
$vtx3->b = $color;
$vtx3->a = 255.0;
$vtx3->oow = 1.0 / $vtx3->z;

$angle = 0.0;

$event = new sfEvent;

while(sfWindow_isOpen($window)) {

    while (sfWindow_pollEvent($window, $event)) {
        switch ($event->type) {
            case sfEventType::sfEvtClosed:
                break(3);
        }
        break;
    }

    grBufferClear( 0x00FFFFff, 0, GrDepth_t::GR_WDEPTHVALUE_FARTHEST );

    $vtr1 = rotate_point($vtx1, $angle, $centre);
    $vtr2 = rotate_point($vtx2, $angle, $centre);
    $vtr3 = rotate_point($vtx3, $angle, $centre);

    $aux = [$vtr1, $vtr2, $vtr3];
    array_walk($aux, fn($v) => $v->flush());

    //testGrVertex($vtr3);

    grDrawTriangle($vtr1, $vtr2, $vtr3);

    grBufferSwap(1);

    //usleep(1000); // Reduce CPU usage
    $angle += 0.01;
}

grSstIdle();

grSstWinClose();

grGlideShutdown();

echo 'done';