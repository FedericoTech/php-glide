#include <glide.h>

#include "phpglide3x_grColor.h"
#include "phpglide3x_enums.h"

PHP_FUNCTION(grColorCombine)
{
	zend_object* func = NULL;
	zend_object* factor = NULL;
	zend_object* local = NULL;
	zend_object* other = NULL;

	bool invert;

	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_OBJ_OF_CLASS(func, grCombineFunction_ce)
		Z_PARAM_OBJ_OF_CLASS(factor, grCombineFactor_ce)
		Z_PARAM_OBJ_OF_CLASS(local, grCombineLocal_ce)
		Z_PARAM_OBJ_OF_CLASS(other, grCombineOther_ce)
		Z_PARAM_BOOL(invert)
		ZEND_PARSE_PARAMETERS_END();

	grColorCombine(
		(GrCombineFunction_t) enum_to_int(func),
		(GrCombineFactor_t)enum_to_int(factor),
		(GrCombineLocal_t)enum_to_int(local),
		(GrCombineOther_t)enum_to_int(other),
		(FxBool)invert
	);
}

PHP_FUNCTION(grColorMask)
{
	zend_bool rgb, alpha;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_BOOL(rgb)
		Z_PARAM_BOOL(alpha)
		ZEND_PARSE_PARAMETERS_END();

	grColorMask((FxBool)rgb, (FxBool)alpha);
}