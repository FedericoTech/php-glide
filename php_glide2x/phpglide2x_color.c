
#include "phpglide2x_color.h"
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



PHP_FUNCTION(guColorCombineFunction) {

	zend_object* func_obj = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(func_obj, grColorCombineFnc_ce)
	ZEND_PARSE_PARAMETERS_END();

	guColorCombineFunction(enum_to_int(func_obj));
}