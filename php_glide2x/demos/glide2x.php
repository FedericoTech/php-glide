<?php

grGlideInit();

$ello = new GrVertex;

var_dump($ello);

echo PHP_EOL;

$reflection = new ReflectionClass(GrVertex::class);
var_dump($reflection->isFinal());

grGlideShutdown();

echo 'done';
