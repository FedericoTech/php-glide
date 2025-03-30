#include <php.h>
#include <ext/standard/info.h>

#include "phpglide3x_constants.h"
#include "phpglide3x_enums.h"
#include "phpglide3x_functions.h"
#include "phpglide3x_grBuffer.h"
#include "phpglide3x_grColor.h"
#include "phpglide3x_grDraw.h"
#include "phpglide3x_grSst.h"
#include "phpglide3x_Vec2.h"


# define PHP_TEST_VERSION "0.1.0"

//if Zend Thread Safe is active and also compiled as a Dynamic Library...
# if defined(ZTS) && defined(COMPILE_DL_TEST)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

PHP_INI_BEGIN()
	PHP_INI_ENTRY("phpglide3x.enable_logging", "1", PHP_INI_ALL, NULL)
	PHP_INI_ENTRY("phpglide3x.log_level", "debug", PHP_INI_ALL, NULL)
PHP_INI_END()

/**
 * Module setup and tear down START
 */
PHP_MINIT_FUNCTION(phpglide3x)
{
	REGISTER_INI_ENTRIES();
	
	// callbacks
	phpglide3x_init_callbacks();

	// grDraw module
	phpglide3x_register_constants(INIT_FUNC_ARGS_PASSTHRU);
	phpglide3x_register_enums(INIT_FUNC_ARGS_PASSTHRU);
	phpglide3x_register_gr_functions_module(INIT_FUNC_ARGS_PASSTHRU);
	phpglide3x_register_gr_buffer_module(INIT_FUNC_ARGS_PASSTHRU);
	phpglide3x_register_gr_color_module(INIT_FUNC_ARGS_PASSTHRU);
	phpglide3x_register_gr_draw_module(INIT_FUNC_ARGS_PASSTHRU);
	phpglide3x_register_gr_sst_module(INIT_FUNC_ARGS_PASSTHRU);
	phpglide3x_register_gr_vec2_module(INIT_FUNC_ARGS_PASSTHRU);


	return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(phpglide3x)
{
	return SUCCESS;
}

/**
 * Module setup and tear down END
 */

/**
 * Request setup and tear down START
 */

PHP_RINIT_FUNCTION(phpglide3x)
{
#if defined(ZTS) && defined(COMPILE_DL_TEST)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	return SUCCESS;
}

PHP_RSHUTDOWN_FUNCTION(phpglide3x)
{
	// destruct registered callbacks
	phpglide3x_shutdown_callbacks();

	return SUCCESS;
}

/**
 * Request setup and tear down END
 */

PHP_MINFO_FUNCTION(phpglide3x)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "Glide 3", "enabled");
	php_info_print_table_row(2, "Some parameter", "Some value");
	php_info_print_table_end();
}

/* Define the module entry */
extern zend_module_entry  phpglide3x_module_entry = {
	STANDARD_MODULE_HEADER,
	"PHP Glide3x",				/* Extension name */
	NULL,						/* zend_function_entry. No global function table, functions are registered separately */
	PHP_MINIT(phpglide3x),		/* PHP_MINIT - Module initialization */
	PHP_MSHUTDOWN(phpglide3x),	/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(phpglide3x),		/* PHP_RINIT - Request initialization */
	PHP_RSHUTDOWN(phpglide3x),	/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(phpglide3x),		/* PHP_MINFO - Module info (PHP Info) */
	"1.0",						/* Version */
	STANDARD_MODULE_PROPERTIES
};

//if compiled as a Dynamic Library...
#ifdef COMPILE_DL_TEST
	//if compiled as thread safe...
	#ifdef ZTS
		ZEND_TSRMLS_CACHE_DEFINE()
	#endif
	//this function GET_MODULE is neccessary
	ZEND_GET_MODULE(phpglide3x)
#endif