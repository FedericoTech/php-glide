#define __MSC__
#include <glide.h>

#include "phpglide3x_grColor.h"
#include "phpglide3x_enums.h"
#include <Zend/zend_enum.h>

ZEND_BEGIN_ARG_INFO_EX(arginfo_grColorCombine, 0, 0, 5)
	ZEND_ARG_OBJ_INFO(0, func, GrCombineFunction_t, 0)
	ZEND_ARG_OBJ_INFO(0, factor, GrCombineFactor_t, 0)
	ZEND_ARG_OBJ_INFO(0, local, GrCombineLocal_t, 0)
	ZEND_ARG_OBJ_INFO(0, other, GrCombineOther_t, 0)
	ZEND_ARG_TYPE_INFO(0, invert, _IS_BOOL, 0)
	
ZEND_END_ARG_INFO()

PHP_FUNCTION(grColorCombine)
{
	zval* func = nullptr;
	zval* factor = nullptr;
	zval* local = nullptr;
	zval* other = nullptr;

	bool invert;

	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_OBJECT_OF_CLASS(func, grCombineFunction_ce)
		Z_PARAM_OBJECT_OF_CLASS(factor, grCombineFactor_ce)
		Z_PARAM_OBJECT_OF_CLASS(local, grCombineLocal_ce)
		Z_PARAM_OBJECT_OF_CLASS(other, grCombineOther_ce)
		Z_PARAM_BOOL(invert)
		ZEND_PARSE_PARAMETERS_END();

	grColorCombine(
		(GrCombineFunction_t)Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(func))),
		(GrCombineFactor_t)Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(factor))),
		(GrCombineLocal_t)Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(local))),
		(GrCombineOther_t)Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(other))),
		(FxBool)invert
	);
}


ZEND_BEGIN_ARG_INFO_EX(arginfo_grColorMask, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, rgb, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, alpha, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

PHP_FUNCTION(grColorMask)
{
	zend_bool rgb, alpha;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_BOOL(rgb)
		Z_PARAM_BOOL(alpha)
		ZEND_PARSE_PARAMETERS_END();

	grColorMask((FxBool)rgb, (FxBool)alpha);
}

void phpglide3x_register_gr_color_module(INIT_FUNC_ARGS)
{
	const zend_function_entry gr_color_functions[] = {

		PHP_FE(grColorCombine, arginfo_grColorCombine)
		PHP_FE(grColorMask, arginfo_grColorMask)
		PHP_FE_END
	};

	zend_register_functions(NULL, gr_color_functions, NULL, MODULE_PERSISTENT);
}