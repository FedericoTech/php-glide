--TEST--
GrVertex
--FILE--
<?php
grGlideInit();

$gtv = new GrTmuVertex;
$gtv->flush();

var_dump($gtv);
testGrTmuVertex($gtv);

echo PHP_EOL;

$gtv->sow = 0;
$gtv->tow = 0.1;
$gtv->oow = '0.2';
$gtv->flush();

var_dump($gtv);
testGrTmuVertex($gtv);

echo PHP_EOL;

$gtv2 = new GrTmuVertex;
$gtv2->sow = '0.3';
$gtv2->tow = 0.4;
$gtv2->oow = 0.5;


echo PHP_EOL;

$vertex = new GrVertex;

$vertex->flush();
var_dump($vertex);
testGrVertex($vertex);

echo PHP_EOL;

$vertex->x = 0;
$vertex->y = 0.1;
$vertex->z = 0.2;

$vertex->r = 0.3;
$vertex->g = 0.4;
$vertex->b = '0.5';

$vertex->ooz = 0.6;
$vertex->a = 0.7;
$vertex->oow = '0.8';

$gtv->flush();
$gtv2->flush();

$vertex->tmuvtx = [$gtv, $gtv2];
$vertex->flush();

var_dump($vertex);
testGrVertex($vertex);

echo PHP_EOL;

$reflection = new ReflectionClass(GrHwConfiguration::class);
var_dump(
	$reflection->isInternal(),
	$reflection->isFinal()
);

try {
	$new_vertex = GrVertex::fromString('');
} catch(Exception $e){
	var_dump($e->getMessage());
}

$string = pack('f15',
    1.0, 2.0, 3.0,  // x, y, z
    4.0, 5.0, 6.0,  // r, g, b
    7.0,             // ooz
    8.0,            // a
    9.0,            // oow
    10.0, 11.0, 12.0,   // tmu 0: sow, tow, oow
    13.0, 14.0, 15.0    // tmo 1: sow, tow, oow
);

var_dump(strlen($string));

$new_vertex = GrVertex::fromString($string);

var_dump($new_vertex);
testGrVertex($new_vertex);

$new_vertex++;

var_dump($new_vertex);
testGrVertex($new_vertex);

$new_vertex = $new_vertex + 2;

var_dump($new_vertex);
testGrVertex($new_vertex);

$new_vertex += 3;

var_dump($new_vertex);
testGrVertex($new_vertex);

$new_vertex2 = $new_vertex + 4;

var_dump($new_vertex2);
testGrVertex($new_vertex2);

grGlideShutdown();
?>
--EXPECT--
object(GrTmuVertex)#1 (0) {
  ["sow"]=>
  uninitialized(float)
  ["tow"]=>
  uninitialized(float)
  ["oow"]=>
  uninitialized(float)
}
sow: 0.000000, tow: 0.000000, oow: 0.000000

object(GrTmuVertex)#1 (3) {
  ["sow"]=>
  float(0)
  ["tow"]=>
  float(0.1)
  ["oow"]=>
  float(0.2)
}
sow: 0.000000, tow: 0.100000, oow: 0.200000


object(GrVertex)#3 (0) {
  ["x"]=>
  uninitialized(float)
  ["y"]=>
  uninitialized(float)
  ["z"]=>
  uninitialized(float)
  ["r"]=>
  uninitialized(float)
  ["g"]=>
  uninitialized(float)
  ["b"]=>
  uninitialized(float)
  ["ooz"]=>
  uninitialized(float)
  ["a"]=>
  uninitialized(float)
  ["oow"]=>
  uninitialized(float)
  ["tmuvtx"]=>
  uninitialized(array)
}
x: 0.000000, y: 0.000000, z: 0.000000, r: 0.000000, g: 0.000000, b: 0.000000, ooz: 0.000000, a: 0.000000, oow: 0.000000
[0] sow: 0.000000, tow: 0.000000, oow: 0.000000
[1] sow: 0.000000, tow: 0.000000, oow: 0.000000

object(GrVertex)#3 (10) {
  ["x"]=>
  float(0)
  ["y"]=>
  float(0.1)
  ["z"]=>
  float(0.2)
  ["r"]=>
  float(0.3)
  ["g"]=>
  float(0.4)
  ["b"]=>
  float(0.5)
  ["ooz"]=>
  float(0.6)
  ["a"]=>
  float(0.7)
  ["oow"]=>
  float(0.8)
  ["tmuvtx"]=>
  array(2) {
    [0]=>
    object(GrTmuVertex)#1 (3) {
      ["sow"]=>
      float(0)
      ["tow"]=>
      float(0.1)
      ["oow"]=>
      float(0.2)
    }
    [1]=>
    object(GrTmuVertex)#2 (3) {
      ["sow"]=>
      float(0.3)
      ["tow"]=>
      float(0.4)
      ["oow"]=>
      float(0.5)
    }
  }
}
x: 0.000000, y: 0.100000, z: 0.200000, r: 0.300000, g: 0.400000, b: 0.500000, ooz: 0.600000, a: 0.700000, oow: 0.800000
[0] sow: 0.000000, tow: 0.100000, oow: 0.200000
[1] sow: 0.300000, tow: 0.400000, oow: 0.500000

bool(true)
bool(true)
string(28) "String must be 60 bytes long"
int(60)
object(GrVertex)#6 (10) {
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
  array(2) {
    [0]=>
    object(GrTmuVertex)#7 (3) {
      ["sow"]=>
      float(10)
      ["tow"]=>
      float(11)
      ["oow"]=>
      float(12)
    }
    [1]=>
    object(GrTmuVertex)#8 (3) {
      ["sow"]=>
      float(13)
      ["tow"]=>
      float(14)
      ["oow"]=>
      float(15)
    }
  }
}
x: 1.000000, y: 2.000000, z: 3.000000, r: 4.000000, g: 5.000000, b: 6.000000, ooz: 7.000000, a: 8.000000, oow: 9.000000
[0] sow: 10.000000, tow: 11.000000, oow: 12.000000
[1] sow: 13.000000, tow: 14.000000, oow: 15.000000
object(GrVertex)#6 (10) {
  ["x"]=>
  float(2)
  ["y"]=>
  float(3)
  ["z"]=>
  float(4)
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
  array(2) {
    [0]=>
    object(GrTmuVertex)#9 (3) {
      ["sow"]=>
      float(10)
      ["tow"]=>
      float(11)
      ["oow"]=>
      float(12)
    }
    [1]=>
    object(GrTmuVertex)#10 (3) {
      ["sow"]=>
      float(13)
      ["tow"]=>
      float(14)
      ["oow"]=>
      float(15)
    }
  }
}
x: 2.000000, y: 3.000000, z: 4.000000, r: 4.000000, g: 5.000000, b: 6.000000, ooz: 7.000000, a: 8.000000, oow: 9.000000
[0] sow: 10.000000, tow: 11.000000, oow: 12.000000
[1] sow: 13.000000, tow: 14.000000, oow: 15.000000
object(GrVertex)#8 (10) {
  ["x"]=>
  float(4)
  ["y"]=>
  float(5)
  ["z"]=>
  float(6)
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
  array(2) {
    [0]=>
    object(GrTmuVertex)#7 (3) {
      ["sow"]=>
      float(10)
      ["tow"]=>
      float(11)
      ["oow"]=>
      float(12)
    }
    [1]=>
    object(GrTmuVertex)#11 (3) {
      ["sow"]=>
      float(13)
      ["tow"]=>
      float(14)
      ["oow"]=>
      float(15)
    }
  }
}
x: 4.000000, y: 5.000000, z: 6.000000, r: 4.000000, g: 5.000000, b: 6.000000, ooz: 7.000000, a: 8.000000, oow: 9.000000
[0] sow: 10.000000, tow: 11.000000, oow: 12.000000
[1] sow: 13.000000, tow: 14.000000, oow: 15.000000
object(GrVertex)#8 (10) {
  ["x"]=>
  float(7)
  ["y"]=>
  float(8)
  ["z"]=>
  float(9)
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
  array(2) {
    [0]=>
    object(GrTmuVertex)#6 (3) {
      ["sow"]=>
      float(10)
      ["tow"]=>
      float(11)
      ["oow"]=>
      float(12)
    }
    [1]=>
    object(GrTmuVertex)#10 (3) {
      ["sow"]=>
      float(13)
      ["tow"]=>
      float(14)
      ["oow"]=>
      float(15)
    }
  }
}
x: 7.000000, y: 8.000000, z: 9.000000, r: 4.000000, g: 5.000000, b: 6.000000, ooz: 7.000000, a: 8.000000, oow: 9.000000
[0] sow: 10.000000, tow: 11.000000, oow: 12.000000
[1] sow: 13.000000, tow: 14.000000, oow: 15.000000
object(GrVertex)#11 (10) {
  ["x"]=>
  float(11)
  ["y"]=>
  float(12)
  ["z"]=>
  float(13)
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
  array(2) {
    [0]=>
    object(GrTmuVertex)#7 (3) {
      ["sow"]=>
      float(10)
      ["tow"]=>
      float(11)
      ["oow"]=>
      float(12)
    }
    [1]=>
    object(GrTmuVertex)#9 (3) {
      ["sow"]=>
      float(13)
      ["tow"]=>
      float(14)
      ["oow"]=>
      float(15)
    }
  }
}
x: 11.000000, y: 12.000000, z: 13.000000, r: 4.000000, g: 5.000000, b: 6.000000, ooz: 7.000000, a: 8.000000, oow: 9.000000
[0] sow: 10.000000, tow: 11.000000, oow: 12.000000
[1] sow: 13.000000, tow: 14.000000, oow: 15.000000