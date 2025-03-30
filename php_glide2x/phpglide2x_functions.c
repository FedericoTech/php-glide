
#include <glide.h>

#include "phpglide2x_glide.h"

#include <conio.h>

//prototype of function grGlideInit;
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_kbhit, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

PHP_FUNCTION(_kbhit) {
	ZEND_PARSE_PARAMETERS_NONE();
	RETURN_LONG(_kbhit());
}



void phpglide2x_register_functions(INIT_FUNC_ARGS)
{

	const zend_function_entry gr_functions_functions[] = {

		PHP_FE(_kbhit, arginfo_kbhit)
		PHP_FE_END
	};

	zend_register_functions(NULL, gr_functions_functions, NULL, MODULE_PERSISTENT);
}