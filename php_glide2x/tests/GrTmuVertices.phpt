--TEST--
GrTmuVertices
--FILE--
<?php
echo 'we create an empty object' . PHP_EOL;
<?php
//we create an empty GrTmuVertex to check the default values.
$gtvs = new GrTmuVertices;

var_dump($gtvs);
print_r($gtvs);

testGrTmuVertices($gtvs);

$grtv = new GrTmuVertex;
var_dump($grtv);
print_r($grtv);
testGrTmuVertex($grtv);

$gtvs[0] = $grtv;
var_dump($gtvs);
print_r($gtvs);
testGrTmuVertices($gtvs);

$gtvs[1] = $grtv;
var_dump($gtvs);
print_r($gtvs);
testGrTmuVertices($gtvs);



$grtv->sow = 1;

var_dump($gtvs);
print_r($gtvs);
testGrTmuVertices($gtvs);
testGrTmuVertex($grtv);

$gtvs[0]->tow = '2.0';
var_dump($gtvs);
print_r($gtvs);
testGrTmuVertices($gtvs);
testGrTmuVertex($grtv);


$gtvs[1]->oow = 3.0;
var_dump($gtvs);
print_r($gtvs);
testGrTmuVertices($gtvs);
testGrTmuVertex($grtv);


unset($gtvs[0]);
var_dump($gtvs);
print_r($gtvs);
testGrTmuVertices($gtvs);
testGrTmuVertex($grtv);

$grtv2 = new GrTmuVertex;
$grtv2->sow = 4;
$grtv2->tow = '5';
$grtv2->oow = 6.0;

$gtvs[0] = $grtv2;
var_dump($gtvs);
print_r($gtvs);
testGrTmuVertices($gtvs);
testGrTmuVertex($grtv2);


$gtvs2 = new GrTmuVertices;
$gtvs2[0] = $gtvs[1];
$gtvs2[1] = $gtvs[0];
testGrTmuVertices($gtvs2);


$grtv->sow = 7;
$grtv->tow = '8';
$grtv->oow = 9.0;

echo PHP_EOL;

unset($grtv, $grtv2);


testGrTmuVertices($gtvs);
testGrTmuVertices($gtvs2);

$grtv = $gtvs[0];

$ello = 90;

$gtvs[0]->sow =& $ello;

var_dump($gtvs);
print_r($gtvs);
testGrTmuVertices($gtvs);

var_dump(
	$gtvs[0] == $grtv,
	$gtvs[0] === $grtv,
);
testGrTmuVertex($grtv);


$gtvs3 = new GrTmuVertices;
$gtvs3[0] = $gtvs3[1] = $grtv;
testGrTmuVertices($gtvs3);

$grtv->sow = $grtv->tow = $grtv->oow = 88;
testGrTmuVertex($grtv);
testGrTmuVertices($gtvs);
testGrTmuVertices($gtvs2);
testGrTmuVertices($gtvs3);

exit('done');
?>
--EXPECT--
object(GrTmuVertices)#1 (2) {
}
GrTmuVertices Object
(
)
tmu[0]: sow: 0.000000, tow: 0.000000, oow: 0.000000
tmu[1]: sow: 0.000000, tow: 0.000000, oow: 0.000000
object(GrTmuVertex)#2 (0) {
  ["sow"]=>
  uninitialized(float)
  ["tow"]=>
  uninitialized(float)
  ["oow"]=>
  uninitialized(float)
}
GrTmuVertex Object
(
)
referenced_mask: 0
sow: 0.000000, tow: 0.000000, oow: 0.000000
object(GrTmuVertices)#1 (2) {
  [0]=>
  object(GrTmuVertex)#2 (0) {
    ["sow"]=>
    uninitialized(float)
    ["tow"]=>
    uninitialized(float)
    ["oow"]=>
    uninitialized(float)
  }
}
GrTmuVertices Object
(
    [0] => GrTmuVertex Object
        (
        )

)
tmu[0]: sow: 0.000000, tow: 0.000000, oow: 0.000000
tmu[1]: sow: 0.000000, tow: 0.000000, oow: 0.000000
object(GrTmuVertices)#1 (2) {
  [0]=>
  object(GrTmuVertex)#2 (0) {
    ["sow"]=>
    uninitialized(float)
    ["tow"]=>
    uninitialized(float)
    ["oow"]=>
    uninitialized(float)
  }
  [1]=>
  object(GrTmuVertex)#2 (0) {
    ["sow"]=>
    uninitialized(float)
    ["tow"]=>
    uninitialized(float)
    ["oow"]=>
    uninitialized(float)
  }
}
GrTmuVertices Object
(
    [0] => GrTmuVertex Object
        (
        )

    [1] => GrTmuVertex Object
        (
        )

)
tmu[0]: sow: 0.000000, tow: 0.000000, oow: 0.000000
tmu[1]: sow: 0.000000, tow: 0.000000, oow: 0.000000
object(GrTmuVertices)#1 (2) {
  [0]=>
  object(GrTmuVertex)#2 (1) {
    ["sow"]=>
    float(1)
    ["tow"]=>
    uninitialized(float)
    ["oow"]=>
    uninitialized(float)
  }
  [1]=>
  object(GrTmuVertex)#2 (1) {
    ["sow"]=>
    float(1)
    ["tow"]=>
    uninitialized(float)
    ["oow"]=>
    uninitialized(float)
  }
}
GrTmuVertices Object
(
    [0] => GrTmuVertex Object
        (
            [sow] => 1
        )

    [1] => GrTmuVertex Object
        (
            [sow] => 1
        )

)
tmu[0]: sow: 1.000000, tow: 0.000000, oow: 0.000000
tmu[1]: sow: 1.000000, tow: 0.000000, oow: 0.000000
referenced_mask: 0
sow: 1.000000, tow: 0.000000, oow: 0.000000
object(GrTmuVertices)#1 (2) {
  [0]=>
  object(GrTmuVertex)#2 (2) {
    ["sow"]=>
    float(1)
    ["tow"]=>
    float(2)
    ["oow"]=>
    uninitialized(float)
  }
  [1]=>
  object(GrTmuVertex)#2 (2) {
    ["sow"]=>
    float(1)
    ["tow"]=>
    float(2)
    ["oow"]=>
    uninitialized(float)
  }
}
GrTmuVertices Object
(
    [0] => GrTmuVertex Object
        (
            [sow] => 1
            [tow] => 2
        )

    [1] => GrTmuVertex Object
        (
            [sow] => 1
            [tow] => 2
        )

)
tmu[0]: sow: 1.000000, tow: 2.000000, oow: 0.000000
tmu[1]: sow: 1.000000, tow: 2.000000, oow: 0.000000
referenced_mask: 0
sow: 1.000000, tow: 2.000000, oow: 0.000000
object(GrTmuVertices)#1 (2) {
  [0]=>
  object(GrTmuVertex)#2 (3) {
    ["sow"]=>
    float(1)
    ["tow"]=>
    float(2)
    ["oow"]=>
    float(3)
  }
  [1]=>
  object(GrTmuVertex)#2 (3) {
    ["sow"]=>
    float(1)
    ["tow"]=>
    float(2)
    ["oow"]=>
    float(3)
  }
}
GrTmuVertices Object
(
    [0] => GrTmuVertex Object
        (
            [sow] => 1
            [tow] => 2
            [oow] => 3
        )

    [1] => GrTmuVertex Object
        (
            [sow] => 1
            [tow] => 2
            [oow] => 3
        )

)
tmu[0]: sow: 1.000000, tow: 2.000000, oow: 3.000000
tmu[1]: sow: 1.000000, tow: 2.000000, oow: 3.000000
referenced_mask: 0
sow: 1.000000, tow: 2.000000, oow: 3.000000
object(GrTmuVertices)#1 (2) {
  [1]=>
  object(GrTmuVertex)#2 (3) {
    ["sow"]=>
    float(1)
    ["tow"]=>
    float(2)
    ["oow"]=>
    float(3)
  }
}
GrTmuVertices Object
(
    [1] => GrTmuVertex Object
        (
            [sow] => 1
            [tow] => 2
            [oow] => 3
        )

)
tmu[0]: sow: 0.000000, tow: 0.000000, oow: 0.000000
tmu[1]: sow: 1.000000, tow: 2.000000, oow: 3.000000
referenced_mask: 0
sow: 1.000000, tow: 2.000000, oow: 3.000000
object(GrTmuVertices)#1 (2) {
  [0]=>
  object(GrTmuVertex)#3 (3) {
    ["sow"]=>
    float(4)
    ["tow"]=>
    float(5)
    ["oow"]=>
    float(6)
  }
  [1]=>
  object(GrTmuVertex)#2 (3) {
    ["sow"]=>
    float(1)
    ["tow"]=>
    float(2)
    ["oow"]=>
    float(3)
  }
}
GrTmuVertices Object
(
    [0] => GrTmuVertex Object
        (
            [sow] => 4
            [tow] => 5
            [oow] => 6
        )

    [1] => GrTmuVertex Object
        (
            [sow] => 1
            [tow] => 2
            [oow] => 3
        )

)
tmu[0]: sow: 4.000000, tow: 5.000000, oow: 6.000000
tmu[1]: sow: 1.000000, tow: 2.000000, oow: 3.000000
referenced_mask: 0
sow: 4.000000, tow: 5.000000, oow: 6.000000
tmu[0]: sow: 1.000000, tow: 2.000000, oow: 3.000000
tmu[1]: sow: 4.000000, tow: 5.000000, oow: 6.000000

tmu[0]: sow: 4.000000, tow: 5.000000, oow: 6.000000
tmu[1]: sow: 7.000000, tow: 8.000000, oow: 9.000000
tmu[0]: sow: 7.000000, tow: 8.000000, oow: 9.000000
tmu[1]: sow: 4.000000, tow: 5.000000, oow: 6.000000
object(GrTmuVertices)#1 (2) {
  [0]=>
  object(GrTmuVertex)#3 (3) {
    ["sow"]=>
    &float(90)
    ["tow"]=>
    float(5)
    ["oow"]=>
    float(6)
  }
  [1]=>
  object(GrTmuVertex)#2 (3) {
    ["sow"]=>
    float(7)
    ["tow"]=>
    float(8)
    ["oow"]=>
    float(9)
  }
}
GrTmuVertices Object
(
    [0] => GrTmuVertex Object
        (
            [sow] => 90
            [tow] => 5
            [oow] => 6
        )

    [1] => GrTmuVertex Object
        (
            [sow] => 7
            [tow] => 8
            [oow] => 9
        )

)
tmu[0]: sow: 90.000000, tow: 5.000000, oow: 6.000000
tmu[1]: sow: 7.000000, tow: 8.000000, oow: 9.000000
bool(true)
bool(true)
referenced_mask: 1
sow: 90.000000, tow: 5.000000, oow: 6.000000
tmu[0]: sow: 90.000000, tow: 5.000000, oow: 6.000000
tmu[1]: sow: 90.000000, tow: 5.000000, oow: 6.000000
referenced_mask: 0
sow: 88.000000, tow: 88.000000, oow: 88.000000
tmu[0]: sow: 88.000000, tow: 88.000000, oow: 88.000000
tmu[1]: sow: 7.000000, tow: 8.000000, oow: 9.000000
tmu[0]: sow: 7.000000, tow: 8.000000, oow: 9.000000
tmu[1]: sow: 88.000000, tow: 88.000000, oow: 88.000000
tmu[0]: sow: 88.000000, tow: 88.000000, oow: 88.000000
tmu[1]: sow: 88.000000, tow: 88.000000, oow: 88.000000
done