<?php

$vtx1 = new GrVertex;

$vtx1->x = '160';
$vtx1->y = 120;
$vtx1->r = 255;
$vtx1->g = 3.5;
$vtx1->b = 0;
$vtx1->a = 0;

var_dump($vtx1);
testGrVertex($vtx1);

echo PHP_EOL . 'set values to vtx1' . PHP_EOL . PHP_EOL;

$vtx1->x = 350.5;
$vtx1->y = '14';
$vtx1->r = 25;

var_dump($vtx1);
testGrVertex($vtx1);

echo PHP_EOL . 'clone' . PHP_EOL . PHP_EOL;

$vtx2 = clone $vtx1;

var_dump($vtx2);
testGrVertex($vtx2);

echo PHP_EOL . 'set values to vtx2' . PHP_EOL . PHP_EOL;

$vtx2->x = '245';
$vtx2->y = 12;
$vtx2->r = 25.5;

echo 'printing' . PHP_EOL;
var_dump($vtx2);
testGrVertex($vtx2);