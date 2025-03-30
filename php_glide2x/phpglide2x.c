#include <php.h>
#include <ext/standard/info.h>

#include <glide.h>

#include "phpglide2x_enums.h"
#include "phpglide2x_structs.h"
#include "phpglide2x_sst.h"
#include "phpglide2x_glide.h"
#include "phpglide2x_color.h"
#include "phpglide2x_buffer.h"
#include "phpglide2x_draw.h"
#include "phpglide2x_functions.h"



# define PHP_TEST_VERSION "0.1.0"

//if Zend Thread Safe is active and also compiled as a Dynamic Library...
# if defined(ZTS) && defined(COMPILE_DL_TEST)
ZEND_TSRMLS_CACHE_EXTERN()
# endif


PHP_INI_BEGIN()
	PHP_INI_ENTRY("phpglide2x.enable_logging", "1", PHP_INI_ALL, NULL)
	PHP_INI_ENTRY("phpglide2x.log_level", "debug", PHP_INI_ALL, NULL)
PHP_INI_END()

/**
 * Module setup
 */
PHP_MINIT_FUNCTION(phpglide2x)
{
	REGISTER_INI_ENTRIES();

	phpglide2x_register_enums(INIT_FUNC_ARGS_PASSTHRU);
	phpglide2x_register_structs(INIT_FUNC_ARGS_PASSTHRU);
	phpglide2x_register_gr_sst_module(INIT_FUNC_ARGS_PASSTHRU);
	phpglide2x_register_gr_glide_module(INIT_FUNC_ARGS_PASSTHRU);
	phpglide2x_register_gr_color_module(INIT_FUNC_ARGS_PASSTHRU);
	phpglide2x_register_gr_buffer_module(INIT_FUNC_ARGS_PASSTHRU);
	phpglide2x_register_gr_draw_module(INIT_FUNC_ARGS_PASSTHRU);
	phpglide2x_register_functions(INIT_FUNC_ARGS_PASSTHRU);
	
	return SUCCESS;
}

/**
 * Module tear down
 */

PHP_MSHUTDOWN_FUNCTION(phpglide2x)
{
	return SUCCESS;
}


 /**
  * Request setup
  */

PHP_RINIT_FUNCTION(phpglide2x)
{
#if defined(ZTS) && defined(COMPILE_DL_TEST)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	return SUCCESS;
}

/**
 * Request tear down
 */

PHP_RSHUTDOWN_FUNCTION(phpglide2x)
{
	// destruct registered callbacks

	grGlideShutdown();

	return SUCCESS;
}

PHP_MINFO_FUNCTION(phpglide2x)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "Glide 2", "enabled");
	php_info_print_table_row(2, "Some parameter", "Some value");
	php_info_print_table_end();
}

/* Define the module entry */
extern zend_module_entry  phpglide2x_module_entry = {
	STANDARD_MODULE_HEADER,
	"PHP Glide2x",				/* Extension name */
	NULL,						/* zend_function_entry. No global function table, functions are registered separately */
	PHP_MINIT(phpglide2x),		/* PHP_MINIT - Module initialization */
	PHP_MSHUTDOWN(phpglide2x),	/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(phpglide2x),		/* PHP_RINIT - Request initialization */
	PHP_RSHUTDOWN(phpglide2x),	/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(phpglide2x),		/* PHP_MINFO - Module info (PHP Info) */
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
ZEND_GET_MODULE(phpglide2x)
#endif