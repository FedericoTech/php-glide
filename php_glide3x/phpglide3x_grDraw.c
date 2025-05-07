#include <glide.h>

#include "phpglide3x_grDraw.h"

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

		aCU.x = (float)zval_get_double(x);
		aCU.y = (float)zval_get_double(y);

		php_printf("param $a is Vec2. x: %f, y: %f\n", aCU.x, aCU.y);
	}

	if (ce && instanceof_function(Z_OBJCE_P(b), ce)) {

		zval* x = zend_read_property(Z_OBJCE_P(b), Z_OBJ_P(b), "x", sizeof("x") - 1, 1, NULL);
		zval* y = zend_read_property(Z_OBJCE_P(b), Z_OBJ_P(b), "y", sizeof("y") - 1, 1, NULL);

		bCU.x = (float)zval_get_double(x);
		bCU.y = (float)zval_get_double(y);

		php_printf("param $b is Vec2. x: %f, y: %f\n", bCU.x, bCU.y);
	}

	if (ce && instanceof_function(Z_OBJCE_P(c), ce)) {

		zval* x = zend_read_property(Z_OBJCE_P(c), Z_OBJ_P(c), "x", sizeof("x") - 1, 1, NULL);
		zval* y = zend_read_property(Z_OBJCE_P(c), Z_OBJ_P(c), "y", sizeof("y") - 1, 1, NULL);

		cCU.x = (float)zval_get_double(x);
		cCU.y = (float)zval_get_double(y);

		php_printf("param $c is Vec2. x: %f, y: %f\n", cCU.x, cCU.y);
	}

	grDrawTriangle(&aCU, &bCU, &cCU);
}