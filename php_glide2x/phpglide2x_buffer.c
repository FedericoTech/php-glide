#include "stdafx.h"
#include "phpglide2x_enums.h"

PHP_FUNCTION(grBufferClear) 
{
	zend_long color;
	zend_long alpha;
	zend_object* depth = NULL;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(color)
		Z_PARAM_LONG(alpha)
		Z_PARAM_OBJ_OF_CLASS(depth, grDepth_ce)
		ZEND_PARSE_PARAMETERS_END();

	grBufferClear((GrColor_t) color, (GrAlpha_t) alpha, enum_to_int(depth));
}

PHP_FUNCTION(grBufferNumPending)
{
	RETURN_LONG(grBufferNumPending());
}

PHP_FUNCTION(grBufferSwap)
{
	zend_long swap_interval;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(swap_interval)
		ZEND_PARSE_PARAMETERS_END();

	grBufferSwap(swap_interval);
}



void phpglide2x_register_gr_buffer_module(INIT_FUNC_ARGS)
{

	const zend_function_entry gr_buffer_functions[] = {

		PHP_FE(grBufferClear, arginfo_grBufferClear)
		PHP_FE(grBufferSwap, arginfo_grBufferSwap)
		PHP_FE_END
	};

	zend_register_functions(NULL, gr_buffer_functions, NULL, MODULE_PERSISTENT);
}