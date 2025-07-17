#include "phpglide2x_glide.h"
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

	_GrState* _grState = O_EMBEDDED_P(_GrState, state_zo);

	grGlideGetState(&_grState->grState);

	hydrate_grState(&_grState->grState, _grState);
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

	_GrState* _grState = O_EMBEDDED_P(_GrState, state_zo);

	flush_grState(_grState, &_grState->grState);

	grGlideSetState(&_grState->grState);
}

PHP_FUNCTION(grGlideShutdown) {

	ZEND_PARSE_PARAMETERS_NONE();

	grGlideShutdown();
}