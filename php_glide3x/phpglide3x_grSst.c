#include <glide.h>

#include "phpglide3x_grSst.h"
#include "phpglide3x_enums.h"
#include <Zend/zend_enum.h>

ZEND_BEGIN_ARG_INFO_EX(arginfo_grSstSelect, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, which_sst, IS_LONG, 0)
ZEND_END_ARG_INFO()

PHP_FUNCTION(grSstSelect)
{
	zend_long which_sst;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(which_sst)
	ZEND_PARSE_PARAMETERS_END();

	grSstSelect((int)which_sst);
}


ZEND_BEGIN_ARG_INFO_EX(arginfo_grSstWinClose, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, context, IS_LONG, 0)
ZEND_END_ARG_INFO()

PHP_FUNCTION(grSstWinClose)
{
	zend_long context;
	FxBool result;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(context)
	ZEND_PARSE_PARAMETERS_END();

	result = grSstWinClose((GrContext_t) context);

	RETURN_BOOL(result);

}

ZEND_BEGIN_ARG_INFO_EX(arginfo_grSstWinOpen, 0, 0, 7)
	ZEND_ARG_TYPE_INFO(0, hWin, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, res, GrScreenResolution_t, 0)
	ZEND_ARG_OBJ_INFO(0, ref, GrScreenRefresh_t, 0)
	ZEND_ARG_OBJ_INFO(0, cFormat, GrColorFormat_t, 0)
	ZEND_ARG_OBJ_INFO(0, org_loc, GrOriginLocation_t, 0)
	ZEND_ARG_TYPE_INFO(0, num_buffers, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, num_aux_buffers, IS_LONG, 0)
ZEND_END_ARG_INFO()

PHP_FUNCTION(grSstWinOpen)
{

	zend_long hWin;
	zval* res = NULL;
	zval* ref = NULL;
	zval* cFormat = NULL;
	zval* org_loc = NULL;
	zend_long num_buffers;
	zend_long num_aux_buffers;

	GrContext_t result;

	ZEND_PARSE_PARAMETERS_START(7, 7)
		Z_PARAM_LONG(hWin)
		Z_PARAM_OBJECT_OF_CLASS(res, grScreenResolution_ce)
		Z_PARAM_OBJECT_OF_CLASS(ref, grScreenRefresh_ce)
		Z_PARAM_OBJECT_OF_CLASS(cFormat, grColorFormat_ce)
		Z_PARAM_OBJECT_OF_CLASS(org_loc, grOriginLocation_ce)
		Z_PARAM_LONG(num_buffers)
		Z_PARAM_LONG(num_aux_buffers)
	ZEND_PARSE_PARAMETERS_END();

	result = grSstWinOpen(
		(FxU32) hWin,
		(GrScreenResolution_t) Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(res))),
		(GrScreenRefresh_t) Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(ref))),
		(GrColorFormat_t) Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(cFormat))),
		(GrOriginLocation_t) Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(org_loc))),
		(int) num_buffers,
		(int) num_aux_buffers
	);

	RETURN_LONG(result);
}

void phpglide3x_register_gr_sst_module(INIT_FUNC_ARGS)
{
	const zend_function_entry gr_sst_functions[] = {
		PHP_FE(grSstSelect, arginfo_grSstSelect)
		PHP_FE(grSstWinClose, arginfo_grSstWinClose)
		PHP_FE(grSstWinOpen, arginfo_grSstWinOpen)
		PHP_FE_END
	};

	zend_register_functions(NULL, gr_sst_functions, NULL, MODULE_PERSISTENT);
}

