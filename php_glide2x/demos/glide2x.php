<?php

//this handler is to gracefully close the script when CTRL+C
function ctrl_handler(int $event)
{
    switch ($event) {
        case PHP_WINDOWS_EVENT_CTRL_C:
            grGlideShutdown();
			exit();
            break;
        case PHP_WINDOWS_EVENT_CTRL_BREAK:
            echo "You have pressed CTRL+BREAK\n";
            break;
    }
}

sapi_windows_set_ctrl_handler('ctrl_handler');

grGlideInit();

$ello = new GrVertex;

var_dump($ello);

echo PHP_EOL;

$reflection = new ReflectionClass(GrVertex::class);
var_dump($reflection->isFinal());

grGlideShutdown();

echo 'done';
