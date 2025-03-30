#include <glide.h>


#include "phpglide2x_color.h"
#include "phpglide2x_enums.h"

#include <Zend/zend_enum.h>

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_guColorCombineFunction, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, func, GrColorCombineFnc_t, 0)
ZEND_END_ARG_INFO()

PHP_FUNCTION(guColorCombineFunction) {

	zend_object* func_obj = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(func_obj, grColorCombineFnc_ce)
	ZEND_PARSE_PARAMETERS_END();

	guColorCombineFunction(Z_LVAL_P(zend_enum_fetch_case_value(func_obj)));
}

void phpglide2x_register_gr_color_module(INIT_FUNC_ARGS)
{

	const zend_function_entry gr_color_functions[] = {

		PHP_FE(guColorCombineFunction, arginfo_guColorCombineFunction)
		PHP_FE_END
	};

	zend_register_functions(NULL, gr_color_functions, NULL, MODULE_PERSISTENT);
}