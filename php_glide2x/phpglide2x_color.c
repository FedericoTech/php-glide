
#include "phpglide2x_color.h"
#include "phpglide2x_enums.h"

PHP_FUNCTION(guColorCombineFunction) {

	zend_object* func_obj = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(func_obj, grColorCombineFnc_ce)
	ZEND_PARSE_PARAMETERS_END();

	guColorCombineFunction(enum_to_int(func_obj));
}