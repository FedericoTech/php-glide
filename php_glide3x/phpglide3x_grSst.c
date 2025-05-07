#include <glide.h>

#include "phpglide3x_grSst.h"
#include "phpglide3x_enums.h"
#include <Zend/zend_enum.h>

PHP_FUNCTION(grSstSelect)
{
	zend_long which_sst;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(which_sst)
	ZEND_PARSE_PARAMETERS_END();

	grSstSelect((int)which_sst);
}

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

PHP_FUNCTION(grSstWinOpen)
{
	bool hWin_is_null = true;
	zend_long hWin;
	zend_object* res = NULL;
	zend_object* ref = NULL;
	zend_object* cFormat = NULL;
	zend_object* org_loc = NULL;
	zend_long num_buffers;
	zend_long num_aux_buffers;

	GrContext_t result;

	ZEND_PARSE_PARAMETERS_START(7, 7)
		Z_PARAM_LONG_OR_NULL(hWin, hWin_is_null)
		Z_PARAM_OBJ_OF_CLASS(res, grScreenResolution_ce)
		Z_PARAM_OBJ_OF_CLASS(ref, grScreenRefresh_ce)
		Z_PARAM_OBJ_OF_CLASS(cFormat, grColorFormat_ce)
		Z_PARAM_OBJ_OF_CLASS(org_loc, grOriginLocation_ce)
		Z_PARAM_LONG(num_buffers)
		Z_PARAM_LONG(num_aux_buffers)
	ZEND_PARSE_PARAMETERS_END();

	result = grSstWinOpen(
		hWin_is_null ? 0 : (FxU32) hWin,
		(GrScreenResolution_t)enum_to_int(res),
		(GrScreenRefresh_t)enum_to_int(ref),
		(GrColorFormat_t)enum_to_int(cFormat),
		(GrOriginLocation_t)enum_to_int(org_loc),
		(int) num_buffers,
		(int) num_aux_buffers
	);

	RETURN_LONG(result);
}
