--TEST--
grGlideGetVersion
--FILE--
<?php
grGlideInit();

grGlideGetVersion($ello);

var_dump($ello);

grGlideShutdown();

echo 'done';
?>
--EXPECT--
string(4) "2.60"
done