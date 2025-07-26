#include "phpglide2x_sst.h"
#include "phpglide2x_enums.h"
#include "phpglide2x_structs.h"

/*
PHP_FUNCTION(grSstControlMode)
{
	zend_long mode;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(mode)
		ZEND_PARSE_PARAMETERS_END();

	RETURN_BOOL(grSstControlMode((int)mode));
}
*/

PHP_FUNCTION(grSstIdle) {
	ZEND_PARSE_PARAMETERS_NONE();
	grSstIdle();
}

PHP_FUNCTION(grSstIsBusy) {
	ZEND_PARSE_PARAMETERS_NONE();
	RETURN_BOOL(grSstIsBusy());
}

PHP_FUNCTION(grSstOrigin) 
{
	zend_object* origin = NULL;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(origin, grOriginLocation_ce);
	ZEND_PARSE_PARAMETERS_END();

	grSstOrigin((GrOriginLocation_t)enum_to_int(origin));
}

PHP_FUNCTION(grSstPerfStats)
{
	zend_object* pStats = NULL;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(pStats, gr_SstPerfStats_ce);
	ZEND_PARSE_PARAMETERS_END();

	_GrSstPerfStats_t* gsps = O_EMBEDDED_P(_GrSstPerfStats_t, pStats);

	grSstPerfStats(&gsps->grSstPerfStats);

	hydrate_grSstPerfStats(&gsps->grSstPerfStats, gsps);
}

PHP_FUNCTION(grSstQueryBoards) {

	zend_object* grHwConfiguration_obj = NULL;
	FxBool result;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(grHwConfiguration_obj, grHwConfiguration_ce)
		ZEND_PARSE_PARAMETERS_END();

	_GrHwConfiguration* ghcf = O_EMBEDDED_P(_GrHwConfiguration, grHwConfiguration_obj);

	result = grSstQueryBoards(&ghcf->grHwConfiguration);

	hydrate_GrHwConfiguration(&ghcf->grHwConfiguration, ghcf);

	RETURN_BOOL(result);
}

PHP_FUNCTION(grSstQueryHardware) {

	zend_object* grHwConfiguration_obj = NULL;
	FxBool result;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(grHwConfiguration_obj, grHwConfiguration_ce)
		ZEND_PARSE_PARAMETERS_END();

	_GrHwConfiguration* ghcf = O_EMBEDDED_P(_GrHwConfiguration, grHwConfiguration_obj);

	result = grSstQueryHardware(&ghcf->grHwConfiguration);

	hydrate_GrHwConfiguration(&ghcf->grHwConfiguration, ghcf);

	RETURN_BOOL(result);
}

PHP_FUNCTION(grSstResetPerfStats) {
	ZEND_PARSE_PARAMETERS_NONE();
	grSstResetPerfStats();
}

PHP_FUNCTION(grSstScreenHeight) {
	ZEND_PARSE_PARAMETERS_NONE();
	RETURN_LONG(grSstScreenHeight());
}

PHP_FUNCTION(grSstScreenWidth) {
	ZEND_PARSE_PARAMETERS_NONE();
	RETURN_LONG(grSstScreenWidth());
}

PHP_FUNCTION(grSstSelect)
{
	zend_long which_sst;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(which_sst)
		ZEND_PARSE_PARAMETERS_END();

	grSstSelect((int)which_sst);
}

PHP_FUNCTION(grSstStatus) {
	ZEND_PARSE_PARAMETERS_NONE();
	RETURN_LONG(grSstStatus());
}

PHP_FUNCTION(grSstVideoLine) {
	ZEND_PARSE_PARAMETERS_NONE();
	RETURN_LONG(grSstVideoLine());
}

PHP_FUNCTION(grSstVRetraceOn) {
	ZEND_PARSE_PARAMETERS_NONE();
	RETURN_BOOL(grSstVRetraceOn());
}

PHP_FUNCTION(grSstWinClose) {
	ZEND_PARSE_PARAMETERS_NONE();
	grSstWinClose();
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
		(GrScreenResolution_t)enum_to_int(res),
		(GrScreenRefresh_t)enum_to_int(ref),
		(GrColorFormat_t)enum_to_int(cFormat),
		(GrOriginLocation_t)enum_to_int(org_loc),
		(int)num_buffers,
		(int)num_aux_buffers
	);

	RETURN_BOOL(result);
}


