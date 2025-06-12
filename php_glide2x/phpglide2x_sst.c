#include "phpglide2x_sst.h"
#include "phpglide2x_enums.h"
#include "phpglide2x_structs.h"

PHP_FUNCTION(grSstQueryHardware) {

	zend_object* grHwConfiguration_obj = NULL;
	FxBool result;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(grHwConfiguration_obj, grHwConfiguration_ce)
	ZEND_PARSE_PARAMETERS_END();

	GrHwConfiguration ghcf;

	result = grSstQueryHardware(&ghcf);
		
	hydrate_GrHwConfiguration(&ghcf, O_EMBEDDED_P(_GrHwConfiguration, grHwConfiguration_obj));

	RETURN_BOOL(result);
}

PHP_FUNCTION(grSstSelect)
{
	zend_long which_sst;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(which_sst)
	ZEND_PARSE_PARAMETERS_END();

	grSstSelect((int)which_sst);
}

PHP_FUNCTION(grSstWinOpen)
{
	zend_long hWin;
	zend_bool is_null;
	zend_object* res = NULL;
	zend_object* ref = NULL;
	zend_object* cFormat = NULL;
	zend_object* org_loc = NULL;
	zend_long num_buffers;
	zend_long num_aux_buffers;

	FxBool result;

	ZEND_PARSE_PARAMETERS_START(7, 7)
		Z_PARAM_LONG_OR_NULL(hWin, is_null)
		Z_PARAM_OBJ_OF_CLASS(res, grScreenResolution_ce)
		Z_PARAM_OBJ_OF_CLASS(ref, grScreenRefresh_ce)
		Z_PARAM_OBJ_OF_CLASS(cFormat, grColorFormat_ce)
		Z_PARAM_OBJ_OF_CLASS(org_loc, grOriginLocation_ce)
		Z_PARAM_LONG(num_buffers)
		Z_PARAM_LONG(num_aux_buffers)
	ZEND_PARSE_PARAMETERS_END();

	result = grSstWinOpen(
		(FxU32)(is_null ? 0 : hWin),
		(GrScreenResolution_t) enum_to_int(res),
		(GrScreenRefresh_t) enum_to_int(ref),
		(GrColorFormat_t) enum_to_int(cFormat),
		(GrOriginLocation_t)enum_to_int(org_loc),
		(int)num_buffers,
		(int)num_aux_buffers
	);

	RETURN_BOOL(result);
}

PHP_FUNCTION(grSstWinClose) {
	ZEND_PARSE_PARAMETERS_NONE();
	grSstWinClose();
}

PHP_FUNCTION(grSstIdle) {
	ZEND_PARSE_PARAMETERS_NONE();
	grSstIdle();
}
