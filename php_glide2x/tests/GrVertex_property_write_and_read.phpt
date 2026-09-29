--TEST--
GrVertex property write and read
--FILE--
<?php
$vertex = new GrVertex;

$vertex->x = 1;
$vertex->y = 2.0;
$vertex->z = '3';
$vertex->r = '4.0';
$vertex->g = 5;
$vertex->b = 6.0;
$vertex->ooz = '7';
$vertex->a = '8.0';
$vertex->oow = 9;

var_dump($vertex);
print_r($vertex);
testGrVertex($vertex);

var_dump($vertex->x);
echo $vertex->x . PHP_EOL;
var_dump($vertex->y);
echo $vertex->y . PHP_EOL;
var_dump($vertex->z);
echo $vertex->z . PHP_EOL;
var_dump($vertex->r);
echo $vertex->r . PHP_EOL;
var_dump($vertex->g);
echo $vertex->g . PHP_EOL;
var_dump($vertex->b);
echo $vertex->b . PHP_EOL;
var_dump($vertex->ooz);
echo $vertex->ooz . PHP_EOL;
var_dump($vertex->a);
echo $vertex->a . PHP_EOL;
var_dump($vertex->oow);
echo $vertex->oow . PHP_EOL;

$vertex->x = 2;
$vertex->y = 4.0;
$vertex->z = '6';
$vertex->r = '8.0';
$vertex->g = 10;
$vertex->b = 12.0;
$vertex->ooz = '14';
$vertex->a = '16.0';
$vertex->oow = 18;

var_dump($vertex->x);
echo $vertex->x . PHP_EOL;
var_dump($vertex->y);
echo $vertex->y . PHP_EOL;
var_dump($vertex->z);
echo $vertex->z . PHP_EOL;
var_dump($vertex->r);
echo $vertex->r . PHP_EOL;
var_dump($vertex->g);
echo $vertex->g . PHP_EOL;
var_dump($vertex->b);
echo $vertex->b . PHP_EOL;
var_dump($vertex->ooz);
echo $vertex->ooz . PHP_EOL;
var_dump($vertex->a);
echo $vertex->a . PHP_EOL;
var_dump($vertex->oow);
echo $vertex->oow . PHP_EOL;

var_dump($vertex);
print_r($vertex);
testGrVertex($vertex);

?>
--EXPECT--
object(GrVertex)#1 (10) {
  ["x"]=>
  float(1)
  ["y"]=>
  float(2)
  ["z"]=>
  float(3)
  ["r"]=>
  float(4)
  ["g"]=>
  float(5)
  ["b"]=>
  float(6)
  ["ooz"]=>
  float(7)
  ["a"]=>
  float(8)
  ["oow"]=>
  float(9)
  ["tmuvtx"]=>
  object(GrTmuVertices)#2 (2) {
    [0]=>
    object(GrTmuVertex)#3 (0) {
      ["sow"]=>
      uninitialized(float)
      ["tow"]=>
      uninitialized(float)
      ["oow"]=>
      uninitialized(float)
    }
    [1]=>
    object(GrTmuVertex)#4 (0) {
      ["sow"]=>
      uninitialized(float)
      ["tow"]=>
      uninitialized(float)
      ["oow"]=>
      uninitialized(float)
    }
  }
}
GrVertex Object
(
    [x] => 1
    [y] => 2
    [z] => 3
    [r] => 4
    [g] => 5
    [b] => 6
    [ooz] => 7
    [a] => 8
    [oow] => 9
    [tmuvtx] => GrTmuVertices Object
        (
            [0] => GrTmuVertex Object
                (
                )

            [1] => GrTmuVertex Object
                (
                )

        )

)
x: 1.000000, y: 2.000000, z: 3.000000, r: 4.000000, g: 5.000000, b: 6.000000, ooz: 7.000000, a: 8.000000, oow: 9.000000
[0] sow: 0.000000, tow: 0.000000, oow: 0.000000
[1] sow: 0.000000, tow: 0.000000, oow: 0.000000
float(1)
1
float(2)
2
float(3)
3
float(4)
4
float(5)
5
float(6)
6
float(7)
7
float(8)
8
float(9)
9
float(2)
2
float(4)
4
float(6)
6
float(8)
8
float(10)
10
float(12)
12
float(14)
14
float(16)
16
float(18)
18
object(GrVertex)#1 (10) {
  ["x"]=>
  float(2)
  ["y"]=>
  float(4)
  ["z"]=>
  float(6)
  ["r"]=>
  float(8)
  ["g"]=>
  float(10)
  ["b"]=>
  float(12)
  ["ooz"]=>
  float(14)
  ["a"]=>
  float(16)
  ["oow"]=>
  float(18)
  ["tmuvtx"]=>
  object(GrTmuVertices)#2 (2) {
    [0]=>
    object(GrTmuVertex)#3 (0) {
      ["sow"]=>
      uninitialized(float)
      ["tow"]=>
      uninitialized(float)
      ["oow"]=>
      uninitialized(float)
    }
    [1]=>
    object(GrTmuVertex)#4 (0) {
      ["sow"]=>
      uninitialized(float)
      ["tow"]=>
      uninitialized(float)
      ["oow"]=>
      uninitialized(float)
    }
  }
}
GrVertex Object
(
    [x] => 2
    [y] => 4
    [z] => 6
    [r] => 8
    [g] => 10
    [b] => 12
    [ooz] => 14
    [a] => 16
    [oow] => 18
    [tmuvtx] => GrTmuVertices Object
        (
            [0] => GrTmuVertex Object
                (
                )

            [1] => GrTmuVertex Object
                (
                )

        )

)
x: 2.000000, y: 4.000000, z: 6.000000, r: 8.000000, g: 10.000000, b: 12.000000, ooz: 14.000000, a: 16.000000, oow: 18.000000
[0] sow: 0.000000, tow: 0.000000, oow: 0.000000
[1] sow: 0.000000, tow: 0.000000, oow: 0.000000