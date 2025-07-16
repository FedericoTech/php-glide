#include "phpglide2x_glide.h"

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

PHP_FUNCTION(grGlideInit) {

	ZEND_PARSE_PARAMETERS_NONE();

	grGlideInit();
}

PHP_FUNCTION(grGlideShutdown) {

	ZEND_PARSE_PARAMETERS_NONE();

	grGlideShutdown();
}