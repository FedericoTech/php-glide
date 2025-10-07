#include "stdafx.h"
#include "phpglide2x_structs.h"

PHP_FUNCTION(grGlideGetVersion) {
		
	zval* version = NULL;  // zval for the PHP variable

	// Parse parameters: expecting 1 parameter passed by reference
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(version)
		ZEND_PARSE_PARAMETERS_END();

	ZVAL_DEREF(version);

	char versionStr[80];  // your C buffer

	grGlideGetVersion(versionStr);

	ZVAL_STRING(version, versionStr);
}

PHP_FUNCTION(grGlideGetState)
{
	zend_object* state_zo = NULL;

	// Parse parameters: expecting 1 parameter passed by reference
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(state_zo, grState_ce)
		ZEND_PARSE_PARAMETERS_END();

	GrState buffer;

	memset(&buffer, 0, sizeof buffer);

	grGlideGetState(&buffer);

	hydrate_grState(&buffer, state_zo);
}

PHP_FUNCTION(grGlideInit) {

	ZEND_PARSE_PARAMETERS_NONE();

	grGlideInit();
}

PHP_FUNCTION(grGlideSetState)
{
	zend_object* state_zo = NULL;

	// Parse parameters: expecting 1 parameter passed by reference
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(state_zo, grState_ce)
		ZEND_PARSE_PARAMETERS_END();

	GrState buffer;

	flush_grState(state_zo, &buffer);

	grGlideSetState(&buffer);
}

PHP_FUNCTION(grGlideShutdown) {

	ZEND_PARSE_PARAMETERS_NONE();

	grGlideShutdown();
}