#include <glide.h>

#include "phpglide3x_grBuffer.h"

ZEND_BEGIN_ARG_INFO_EX(arginfo_grBufferClear, 0, 0, 3)
	ZEND_ARG_TYPE_INFO(0, color, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, alpha, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, depth, IS_LONG, 0)
ZEND_END_ARG_INFO()

PHP_FUNCTION(grBufferClear)
{
	zend_long color, alpha, depth;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(color)
		Z_PARAM_LONG(alpha)
		Z_PARAM_LONG(depth)
		ZEND_PARSE_PARAMETERS_END();

	grBufferClear((GrColor_t) color, (GrAlpha_t) alpha, (FxU32) depth);
}


ZEND_BEGIN_ARG_INFO_EX(arginfo_grBufferSwap, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, swap_interval, IS_LONG, 0)
ZEND_END_ARG_INFO()

PHP_FUNCTION(grBufferSwap)
{
	zend_long swap_interval;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(swap_interval)
		ZEND_PARSE_PARAMETERS_END();

	grBufferSwap((int)swap_interval);
}

void phpglide3x_register_gr_buffer_module(INIT_FUNC_ARGS)
{
	const zend_function_entry gr_buffer_functions[] = {

		PHP_FE(grBufferClear, arginfo_grBufferClear)
		PHP_FE(grBufferSwap, arginfo_grBufferSwap)
		PHP_FE_END
	};

	zend_register_functions(NULL, gr_buffer_functions, NULL, MODULE_PERSISTENT);
}