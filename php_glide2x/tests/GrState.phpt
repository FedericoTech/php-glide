--TEST--
grState
--FILE--
<?php
grGlideInit();

$ello = new GrState;

$ello->pad = 'bobo';
$ello->flush();

var_dump($ello);

testGrState($ello);

grGlideSetState($ello);

echo 'we set the state' . PHP_EOL;

$aquello = new GrState;

grGlideGetState($aquello);

testGrState($aquello);

echo '[' . ($aquello->pad === str_repeat("\0", 312)) . ']' . PHP_EOL;

//var_dump($aquello);

echo 'we retrieved the state' . PHP_EOL;

$ello2 = clone $ello;

testGrState($ello2);

var_dump($ello2);



echo 'we cloned' . PHP_EOL;

grGlideShutdown();

echo 'done';
?>
--EXPECT--
object(GrState)#1 (1) {
  ["pad"]=>
  string(4) "bobo"
}
pad: bobo
we set the state
pad: 
[1]
we retrieved the state
pad: bobo
object(GrState)#3 (1) {
  ["pad"]=>
  string(4) "bobo"
}
we cloned
done