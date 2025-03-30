--TEST--
grGetString
--FILE--
<?php
grGlideInit();

echo 'GR_EXTENSION: ';
$r = null;
$r = grGetString(GrString_t::GR_EXTENSION);
var_dump($r) . PHP_EOL;

echo 'GR_HARDWARE: ';
$r = null;
$r = grGetString(GrString_t::GR_HARDWARE);
var_dump($r) . PHP_EOL;

echo 'GR_RENDERER: ';
$r = null;
$r = grGetString(GrString_t::GR_RENDERER);
var_dump($r) . PHP_EOL;

echo 'GR_VENDOR: ';
$r = null;
$r = grGetString(GrString_t::GR_VENDOR);
var_dump($r) . PHP_EOL;

echo 'GR_VERSION: ';
$r = null;
$r = grGetString(GrString_t::GR_VERSION);
var_dump($r) . PHP_EOL;


grGlideShutdown();
?>
--EXPECT--
GR_EXTENSION: string(43) "CHROMARANGE TEXMIRROR PALETTE6666 GETGAMMA "
GR_HARDWARE: string(7) "Voodoo2"
GR_RENDERER: string(5) "Glide"
GR_VENDOR: string(4) "Dege"
GR_VERSION: string(4) "3.10"