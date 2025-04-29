
#include "phpglide2x_functions.h"
#include "phpglide2x_structs.h"

#include <conio.h>


PHP_FUNCTION(_kbhit) {
	ZEND_PARSE_PARAMETERS_NONE();
	RETURN_LONG(_kbhit());
}


PHP_FUNCTION(testObject) {

	zend_object* obj = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ(obj)
	ZEND_PARSE_PARAMETERS_END();

	_GrSST* config = O_EMBEDDED_P(_GrSST, obj);

	php_printf("ello %d\n", config->SST.type);
}