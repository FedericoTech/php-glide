
#include "stdafx.h"
#include "phpglide2x_enums.h"

PHP_FUNCTION(grChromakeyMode) {

	zend_object* mode = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(mode, grChromakeyMode_ce)
		ZEND_PARSE_PARAMETERS_END();

	grChromakeyMode(enum_to_int(mode));
}

PHP_FUNCTION(grChromakeyValue)
{
	zend_long color;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(color)
		ZEND_PARSE_PARAMETERS_END();

	grChromakeyValue((GrColor_t)color);
}

PHP_FUNCTION(grColorCombine)
{
	zend_object* func = NULL;
	zend_object* factor = NULL;
	zend_object* local = NULL;
	zend_object* other = NULL;
	zend_bool invert;

	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_OBJ_OF_CLASS(func, grCombineFunction_ce)
		Z_PARAM_OBJ_OF_CLASS(factor, grCombineFactor_ce)
		Z_PARAM_OBJ_OF_CLASS(local, grCombineLocal_ce)
		Z_PARAM_OBJ_OF_CLASS(other, grCombineOther_ce)
		Z_PARAM_BOOL(invert)
		ZEND_PARSE_PARAMETERS_END();

	grColorCombine(
		(GrCombineFunction_t)enum_to_int(func),
		(GrCombineFactor_t)enum_to_int(factor),
		(GrCombineLocal_t)enum_to_int(local),
		(GrCombineOther_t)enum_to_int(other),
		(FxBool)invert
	);
}

PHP_FUNCTION(grColorMask)
{
	zend_bool rgb;
	zend_bool alpha;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_BOOL(rgb)
		Z_PARAM_BOOL(alpha)
		ZEND_PARSE_PARAMETERS_END();

	grColorMask((FxBool)rgb, (FxBool)alpha);
}

PHP_FUNCTION(grConstantColorValue)
{
	zend_long color;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(color)
		ZEND_PARSE_PARAMETERS_END();

	grConstantColorValue((GrColor_t)color);
}


PHP_FUNCTION(guColorCombineFunction) {

	zend_object* func_obj = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(func_obj, grColorCombineFnc_ce)
	ZEND_PARSE_PARAMETERS_END();

	guColorCombineFunction(enum_to_int(func_obj));
}