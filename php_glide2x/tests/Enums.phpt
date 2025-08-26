--TEST--
enums
--FILE--
<?php
grGlideInit();

$enums = [
	GrDepth_t::GR_ZDEPTHVALUE_NEAREST,
	GrDepth_t::GR_ZDEPTHVALUE_FARTHEST,
	//GrDepth_t::GR_WDEPTHVALUE_NEAREST,		//it is actually repeated
	//GrDepth_t::GR_WDEPTHVALUE_FARTHEST,		//it is actually repeated
	
	GrEvenOdd_t::GR_MIPMAPLEVELMASK_EVEN,
	GrEvenOdd_t::GR_MIPMAPLEVELMASK_ODD,
	GrEvenOdd_t::GR_MIPMAPLEVELMASK_BOTH,
];

$constants = [
	GR_ZDEPTHVALUE_NEAREST,
	GR_ZDEPTHVALUE_FARTHEST,
	//GR_WDEPTHVALUE_NEAREST,		//it is actually repeated
	//GR_WDEPTHVALUE_FARTHEST,		//it is actually repeated
	
	GR_MIPMAPLEVELMASK_EVEN,
	GR_MIPMAPLEVELMASK_ODD,
	GR_MIPMAPLEVELMASK_BOTH,
];

$input = array_map(function ($enum, $const) {
    return enumToIntTest($enum) === $const;
}, $enums, $constants);

var_dump(count(array_unique($input)));

$input = array_map(function ($enum, $const) {
    return intToEnumTest($const, get_class($enum)) == $enum;
}, $enums, $constants);

var_dump(count(array_unique($input)));

grGlideShutdown();

echo 'done';

?>
--EXPECT--
int(1)
int(1)
done