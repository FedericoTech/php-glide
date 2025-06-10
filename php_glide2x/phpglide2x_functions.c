
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