--TEST--
grTexXXXAddress
--FILE--
<?php
grGlideInit();

foreach (GrChipID_t::cases() as $grChipID) {
    $max = grTexMaxAddress($grChipID);
    $min = grTexMinAddress($grChipID);

    echo "$grChipID->name, min: $min, max: $max\n";

    echo PHP_EOL;
}

grGlideShutdown();
?>
--EXPECT--
GR_TMU0, min: 0, max: 4194288

GR_TMU1, min: 0, max: 4194288

GR_TMU2, min: 0, max: -16

GR_FBI, min: 0, max: -16