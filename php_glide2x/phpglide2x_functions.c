
#include "phpglide2x_functions.h"
#include "phpglide2x_structs.h"
#include "phpglide2x_enums.h"

#include <conio.h>


PHP_FUNCTION(grClipWindow)
{
	zend_long minx;
	zend_long miny;
	zend_long maxx;
	zend_long maxy;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(minx)
		Z_PARAM_LONG(miny)
		Z_PARAM_LONG(maxx)
		Z_PARAM_LONG(maxy)
		ZEND_PARSE_PARAMETERS_END();

	grClipWindow((FxU32)minx, (FxU32)miny, (FxU32)maxx, (FxU32)maxy);
}

PHP_FUNCTION(grCullMode)
{
	zend_object* mode = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(mode, grCullMode_ce)
		ZEND_PARSE_PARAMETERS_END();

	grCullMode((GrCullMode_t)enum_to_int(mode));
}

PHP_FUNCTION(grDisableAllEffects)
{
	ZEND_PARSE_PARAMETERS_NONE();

	grDisableAllEffects();
}

PHP_FUNCTION(grDitherMode)
{
	zend_object* mode = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(mode, grDitherMode_ce)
		ZEND_PARSE_PARAMETERS_END();

	grDitherMode((GrDitherMode_t)enum_to_int(mode));
}

PHP_FUNCTION(grGammaCorrectionValue)
{
	zend_long value;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(value);
	ZEND_PARSE_PARAMETERS_END();

	grGammaCorrectionValue((float)value);
}

PHP_FUNCTION(grHints)
{
	zend_object* type = NULL;
	zend_long hintMask;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJ_OF_CLASS(type, grHints_ce);
		Z_PARAM_LONG(hintMask);
		ZEND_PARSE_PARAMETERS_END();

	grHints((GrHint_t) enum_to_int(type), (FxU32) hintMask);
}


PHP_FUNCTION(grRenderBuffer)
{
	zend_object* buffer = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(buffer, grBuffer_ce)
		ZEND_PARSE_PARAMETERS_END();

	grRenderBuffer((GrBuffer_t)enum_to_int(buffer));
}

static zend_fcall_info gr_error_fci;
static zend_fcall_info_cache gr_error_fci_cache;
static bool gr_error_callback_set = false;

static void php_gr_error_callback(const char* msg, FxBool fatal)
{
	zval retval;
	zval params[2];

	ZVAL_STRING(&params[0], msg);
	ZVAL_BOOL(&params[1], fatal);

	gr_error_fci.retval = &retval;
	gr_error_fci.params = params;
	gr_error_fci.param_count = 2;

	if (zend_call_function(&gr_error_fci, &gr_error_fci_cache) == SUCCESS) {
		zval_ptr_dtor(&retval);
	}

	zval_ptr_dtor(&params[0]);
}

PHP_FUNCTION(grErrorSetCallback)
{
	zend_fcall_info fci;
	zend_fcall_info_cache fcc;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_FUNC(fci, fcc)
		ZEND_PARSE_PARAMETERS_END();

	zend_function* func = fcc.function_handler;

	if (func->common.num_args != 2) {
		zend_throw_exception(NULL, "Callback must take exactly 2 parameters", 0);
		RETURN_THROWS();
	}

	zend_arg_info* args = func->common.arg_info;

	grErrorSetCallback(php_gr_error_callback); // Install the wrapper

}


// OTHER FUNCTIONS


PHP_FUNCTION(_kbhit) {
	ZEND_PARSE_PARAMETERS_NONE();
	RETURN_LONG(_kbhit());
}


PHP_FUNCTION(testObject) {

	zend_object* obj = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(obj)
	ZEND_PARSE_PARAMETERS_END();

	_SST_t* config = O_EMBEDDED_P(_SST_t, obj);

	php_printf("ello %d\n", config->SST.type);
}