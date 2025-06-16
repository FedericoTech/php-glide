#include "phpglide2x_depth.h"
#include "phpglide2x_enums.h"


PHP_FUNCTION(grDepthBiasLevel)
{
	zend_long level;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(level)
		ZEND_PARSE_PARAMETERS_END();

	grDepthBiasLevel((FxI16)level);
}

PHP_FUNCTION(grDepthBufferFunction)
{
	zend_object* func = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(func, grCmpFnc_ce)
		ZEND_PARSE_PARAMETERS_END();

	grDepthBufferFunction((GrCmpFnc_t)enum_to_int(func));
}

PHP_FUNCTION(grDepthBufferMode)
{
	zend_object* mode = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(mode, grDepthBufferMode_ce)
		ZEND_PARSE_PARAMETERS_END();

	grDepthBufferMode((GrDepthBufferMode_t)enum_to_int(mode));
}

PHP_FUNCTION(grDepthMask)
{
	zend_bool enable;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(enable)
		ZEND_PARSE_PARAMETERS_END();

	grDepthMask((FxBool)enable);
}