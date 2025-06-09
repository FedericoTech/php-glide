#include "phpglide2x_enums.h"
#include "phpglide2x_alpha.h"

PHP_FUNCTION(grAlphaBlendFunction)
{
	zend_object* rgb_sf = NULL;
	zend_object* rgb_df = NULL;
	zend_object* alpha_sf = NULL;
	zend_object* alpha_df = NULL;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJ_OF_CLASS(rgb_sf, grAlphaBlendFnc_ce)
		Z_PARAM_OBJ_OF_CLASS(rgb_df, grAlphaBlendFnc_ce)
		Z_PARAM_OBJ_OF_CLASS(alpha_sf, grAlphaBlendFnc_ce)
		Z_PARAM_OBJ_OF_CLASS(alpha_df, grAlphaBlendFnc_ce)
	ZEND_PARSE_PARAMETERS_END();

	grAlphaBlendFunction(
		(GrAlphaBlendFnc_t)enum_to_int(rgb_sf),
		(GrAlphaBlendFnc_t)enum_to_int(rgb_df),
		(GrAlphaBlendFnc_t)enum_to_int(alpha_sf),
		(GrAlphaBlendFnc_t)enum_to_int(alpha_df)
	);
}

PHP_FUNCTION(grAlphaCombine)
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

	grAlphaCombine(
		(GrCombineFunction_t)enum_to_int(func),
		(GrCombineFactor_t)enum_to_int(factor),
		(GrCombineLocal_t)enum_to_int(local),
		(GrCombineOther_t)enum_to_int(other),
		invert
	);
}

PHP_FUNCTION(grAlphaControlsITRGBLighting)
{
	zend_bool enable;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(enable)
	ZEND_PARSE_PARAMETERS_END();

	grAlphaControlsITRGBLighting(enable);
}

PHP_FUNCTION(grAlphaTestFunction)
{
	zend_object* function = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(function, grCmpFnc_ce)
	ZEND_PARSE_PARAMETERS_END();

	grAlphaTestFunction((GrCmpFnc_t) enum_to_int(function));
}

PHP_FUNCTION(grAlphaTestReferenceValue)
{
	zend_long value;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();

	grAlphaTestReferenceValue((GrAlpha_t) value);
}