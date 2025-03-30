#include <glide.h>

#include "phpglide3x_grDraw.h"

//prototype of function multiply;
ZEND_BEGIN_ARG_INFO(arginfo_grDrawTriangle, 0)
	ZEND_ARG_TYPE_INFO(0, a, IS_OBJECT, 0)
	ZEND_ARG_TYPE_INFO(0, b, IS_OBJECT, 0)
	ZEND_ARG_TYPE_INFO(0, c, IS_OBJECT, 0)
ZEND_END_ARG_INFO()

PHP_FUNCTION(grDrawTriangle)
{
	zval *a = NULL, *b = NULL, *c = NULL;
	zend_class_entry* ce;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT(a)
		Z_PARAM_OBJECT(b)
		Z_PARAM_OBJECT(c)
	ZEND_PARSE_PARAMETERS_END();

	typedef struct {
		FxFloat x, y;
	} Vertex;

	Vertex aCU, bCU, cCU;

	// Get the class entry of the expected class (Vec2)
	ce = zend_lookup_class(zend_string_init("Vec2", strlen("Vec2"), 0));
	
	if (ce && instanceof_function(Z_OBJCE_P(a), ce)) {
		
		zval* x = zend_read_property(Z_OBJCE_P(a), Z_OBJ_P(a), "x", sizeof("x") - 1, 1, NULL);
		zval* y = zend_read_property(Z_OBJCE_P(a), Z_OBJ_P(a), "y", sizeof("y") - 1, 1, NULL);

		aCU.x = (float) Z_DVAL_P(x);
		aCU.y = (float) Z_DVAL_P(y);

		php_printf("param $a is Vec2. x: %f, y: %f\n", aCU.x, aCU.y);
	}

	if (ce && instanceof_function(Z_OBJCE_P(b), ce)) {

		zval* x = zend_read_property(Z_OBJCE_P(b), Z_OBJ_P(b), "x", sizeof("x") - 1, 1, NULL);
		zval* y = zend_read_property(Z_OBJCE_P(b), Z_OBJ_P(b), "y", sizeof("y") - 1, 1, NULL);

		bCU.x = (float) Z_DVAL_P(x);
		bCU.y = (float) Z_DVAL_P(y);

		php_printf("param $b is Vec2. x: %f, y: %f\n", bCU.x, bCU.y);
	}

	if (ce && instanceof_function(Z_OBJCE_P(c), ce)) {

		zval* x = zend_read_property(Z_OBJCE_P(c), Z_OBJ_P(c), "x", sizeof("x") - 1, 1, NULL);
		zval* y = zend_read_property(Z_OBJCE_P(c), Z_OBJ_P(c), "y", sizeof("y") - 1, 1, NULL);

		cCU.x = (float) Z_DVAL_P(x);
		cCU.y = (float) Z_DVAL_P(y);

		php_printf("param $c is Vec2. x: %f, y: %f\n", cCU.x, cCU.y);
	}

	grDrawTriangle(&aCU, &bCU, &cCU);
}


void phpglide3x_register_gr_draw_module(INIT_FUNC_ARGS)
{

	const zend_function_entry gr_draw_functions[] = {
		PHP_FE(grDrawTriangle, arginfo_grDrawTriangle)
		PHP_FE_END
	};

	zend_register_functions(NULL, gr_draw_functions, NULL, MODULE_PERSISTENT);
}
