#include "stdafx.h"

#include <ext/standard/info.h>

#include "phpglide2x_enums.h"
#include "phpglide2x_structs.h"

# define PHP_GLIDE2X_VERSION "0.1.0"

//if Zend Thread Safe is active and also compiled as a Dynamic Library...
# if defined(ZTS) && defined(COMPILE_DL_GLIDE2X)
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
	/*
	zend_string* key;
	zend_module_entry* module;

	ZEND_HASH_FOREACH_STR_KEY_PTR(&module_registry, key, module) {
		if (key && module) {
			php_printf("Extension 2x: %s (version: %s)\n", ZSTR_VAL(key), module->version);
		}
	} ZEND_HASH_FOREACH_END();
	*/


	//if glide3x is present
	if (zend_hash_exists(&module_registry, zend_string_init("glide3x", strlen("glide3x"), 1))) {

		zend_error_noreturn(E_ERROR, "[glide2x] Conflict detected: both 'glide2x' and 'glide3x' extensions are loaded.\n");

	}

	REGISTER_INI_ENTRIES();

	if (zend_register_functions(NULL, ext_functions, NULL, MODULE_PERSISTENT) != SUCCESS) {
		return FAILURE;
	}
	
	phpglide2x_register_enums(INIT_FUNC_ARGS_PASSTHRU);

	gr_flushable_ce = register_class_flushable();
	
	grTMUConfig_ce = register_class_GrTMUConfig_t(gr_flushable_ce);

	grVoodooConfig_ce = register_class_GrVoodooConfig_t(gr_flushable_ce);

	grVoodoo2Config_ce = register_class_GrVoodoo2Config_t(gr_flushable_ce);

	grSst96Config_ce = register_class_GrSst96Config_t(gr_flushable_ce);

	grAT3DConfig_ce = register_class_GrAT3DConfig_t(gr_flushable_ce);

	sST_ce = register_class_SST_t(gr_flushable_ce);

	grHwConfiguration_ce = register_class_GrHwConfiguration(gr_flushable_ce);

	phpglide2x_register_grTmuVertex(INIT_FUNC_ARGS_PASSTHRU);
	phpglide2x_register_grVertex(INIT_FUNC_ARGS_PASSTHRU);
	phpglide2x_register_grState(INIT_FUNC_ARGS_PASSTHRU);
	phpglide2x_register_grLfbInfo(INIT_FUNC_ARGS_PASSTHRU);
	phpglide2x_register_grSstPerfStats(INIT_FUNC_ARGS_PASSTHRU);
	phpglide2x_register_grTexInfo(INIT_FUNC_ARGS_PASSTHRU);
	phpglide2x_register_gu3dfHeader(INIT_FUNC_ARGS_PASSTHRU);

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
#if defined(ZTS) && defined(COMPILE_DL_GLIDE2X)
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
	"Glide2x",					/* Extension name */
	NULL, //ext_functions,		/* zend_function_entry. No global function table, functions are registered separately */
	PHP_MINIT(phpglide2x),		/* PHP_MINIT - Module initialization */
	PHP_MSHUTDOWN(phpglide2x),	/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(phpglide2x),		/* PHP_RINIT - Request initialization */
	PHP_RSHUTDOWN(phpglide2x),	/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(phpglide2x),		/* PHP_MINFO - Module info (PHP Info) */
	PHP_GLIDE2X_VERSION,						/* Version */
	STANDARD_MODULE_PROPERTIES
};

//if compiled as a Dynamic Library...
#ifdef COMPILE_DL_GLIDE2X
	//if compiled as thread safe...
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
//this function GET_MODULE is neccessary
ZEND_GET_MODULE(phpglide2x)
#endif