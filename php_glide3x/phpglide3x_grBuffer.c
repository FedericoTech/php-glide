#include <glide.h>

#include "phpglide3x_grBuffer.h"

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

PHP_FUNCTION(grBufferSwap)
{
	zend_long swap_interval;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(swap_interval)
		ZEND_PARSE_PARAMETERS_END();

	grBufferSwap((int)swap_interval);
}