--TEST--
GrTmuVertex property isset and empty
--FILE--
<?php
$grtv = new GrTmuVertex;
var_dump(
    isset($grtv->sow),
    empty($grtv->sow)
);

$grtv->sow = 1;

var_dump(
    isset($grtv->sow),
    empty($grtv->sow)
);

unset($grtv->sow);

var_dump(
    isset($grtv->sow),
    empty($grtv->sow)
);
?>
--EXPECT--
bool(false)
bool(true)
bool(true)
bool(false)
bool(false)
bool(true)