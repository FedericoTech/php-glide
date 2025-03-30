#include <glide.h>


#include "phpglide2x_draw.h"
#include "phpglide2x_structs.h"
#include "phpglide2x_enums.h"

#include <Zend/zend_enum.h>

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grDrawTriangle, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, vtx1, GrVertex, 0)
	ZEND_ARG_OBJ_INFO(0, vtx2, GrVertex, 0)
	ZEND_ARG_OBJ_INFO(0, vtx3, GrVertex, 0)
ZEND_END_ARG_INFO()

PHP_FUNCTION(grDrawTriangle)
{
	zend_object* vtx_obj[3] = { NULL };

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJ_OF_CLASS(vtx_obj[0], grVertex_ce)
		Z_PARAM_OBJ_OF_CLASS(vtx_obj[1], grVertex_ce)
		Z_PARAM_OBJ_OF_CLASS(vtx_obj[2], grVertex_ce)
	ZEND_PARSE_PARAMETERS_END();

	const char* properties[] = { "x", "y", "z", "r", "g", "b", "ooz", "a", "oow"};

	GrVertex vtx0, vtx1, vtx2;

	float* f[3] = { (float*)&vtx0, (float*)&vtx1, (float*)&vtx2 };

	//we go property by property
	for (int cont = 0; cont < 9; cont++) {
		//we get the property name
		zend_string* property_name = zend_string_init_interned(properties[cont], strlen(properties[cont]), 1);

		//we go object by object
		for (int cont2 = 0; cont2 < 3; cont2++) {
			//we caputre the property
			zval* ello = zend_read_property_ex(grVertex_ce, vtx_obj[cont2], property_name, 1, NULL);
			//if the value is set...
			if (Z_TYPE_P(ello) == IS_DOUBLE) {
				//we copy the value
				*(f[cont2] + cont) = (float)Z_DVAL_P(ello);
			}
		}
	}
	
	grDrawTriangle(&vtx0, &vtx1, &vtx2);
}

void phpglide2x_register_gr_draw_module(INIT_FUNC_ARGS)
{

	const zend_function_entry gr_draw_functions[] = {

		PHP_FE(grDrawTriangle, arginfo_grDrawTriangle)
		PHP_FE_END
	};

	zend_register_functions(NULL, gr_draw_functions, NULL, MODULE_PERSISTENT);
}