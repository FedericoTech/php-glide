#include <glide.h>

#include "phpglide2x_glide.h"

//prototype of function grGlideInit;
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grGlideInit, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

PHP_FUNCTION(grGlideInit) {

	ZEND_PARSE_PARAMETERS_NONE();

	grGlideInit();
}

//prototype of function grGlideShutdown;
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grGlideShutdown, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

PHP_FUNCTION(grGlideShutdown) {

	ZEND_PARSE_PARAMETERS_NONE();

	grGlideShutdown();
}


void phpglide2x_register_gr_glide_module(INIT_FUNC_ARGS)
{

	const zend_function_entry gr_glide_functions[] = {

		PHP_FE(grGlideInit, arginfo_grGlideInit)
		PHP_FE(grGlideShutdown, arginfo_grGlideShutdown)
		PHP_FE_END
	};

	zend_register_functions(NULL, gr_glide_functions, NULL, MODULE_PERSISTENT);
}