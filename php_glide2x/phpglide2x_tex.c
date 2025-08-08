#include "phpglide2x_tex.h"
#include "phpglide2x_enums.h"
#include "phpglide2x_structs.h"

PHP_FUNCTION(grTexCalcMemRequired)
{
	zend_object* smallLod = NULL;
	zend_object* largeLod = NULL;
	zend_object* aspect = NULL;
	zend_object* format = NULL;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJ_OF_CLASS(smallLod, grLOD_ce);
		Z_PARAM_OBJ_OF_CLASS(largeLod, grLOD_ce);
		Z_PARAM_OBJ_OF_CLASS(aspect, grAspectRatio_ce);
		Z_PARAM_OBJ_OF_CLASS(format, grTextureFormat_ce);
	ZEND_PARSE_PARAMETERS_END();

	RETURN_LONG(grTexCalcMemRequired(
		(GrLOD_t)enum_to_int(smallLod),
		(GrLOD_t)enum_to_int(largeLod),
		(GrAspectRatio_t)enum_to_int(aspect),
		(GrTextureFormat_t)enum_to_int(format)
	));
}

PHP_FUNCTION(grTexClampMode)
{
	zend_object* tmu = NULL;
	zend_object* sClampMode = NULL;
	zend_object* tClampMode = NULL;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJ_OF_CLASS(tmu, grChipID_ce);
		Z_PARAM_OBJ_OF_CLASS(sClampMode, grTextureClampMode_ce);
		Z_PARAM_OBJ_OF_CLASS(tClampMode, grTextureClampMode_ce);
	ZEND_PARSE_PARAMETERS_END();

	grTexClampMode(
		(GrLOD_t)enum_to_int(tmu),
		(GrLOD_t)enum_to_int(sClampMode),
		(GrAspectRatio_t)enum_to_int(tClampMode)
	);
}

PHP_FUNCTION(grTexCombine)
{
	zend_object* tmu = NULL;
	zend_object* rgb_function = NULL;
	zend_object* rgb_factor = NULL;
	zend_object* alpha_function = NULL;
	zend_object* alpha_factor = NULL;
	zend_bool rgb_invert;
	zend_bool alpha_invert;

	ZEND_PARSE_PARAMETERS_START(7, 7)
		Z_PARAM_OBJ_OF_CLASS(tmu, grChipID_ce);
		Z_PARAM_OBJ_OF_CLASS(rgb_function, grCombineFunction_ce);
		Z_PARAM_OBJ_OF_CLASS(rgb_factor, grCombineFactor_ce);
		Z_PARAM_OBJ_OF_CLASS(alpha_function, grCombineFunction_ce);
		Z_PARAM_OBJ_OF_CLASS(alpha_factor, grCombineFactor_ce);
		Z_PARAM_BOOL(rgb_invert)
		Z_PARAM_BOOL(alpha_invert)
	ZEND_PARSE_PARAMETERS_END();

	grTexCombine(
		(GrChipID_t)enum_to_int(tmu),
		(GrCombineFunction_t)enum_to_int(rgb_function),
		(GrCombineFactor_t)enum_to_int(rgb_factor),
		(GrCombineFunction_t)enum_to_int(alpha_function),
		(GrCombineFactor_t)enum_to_int(alpha_factor),
		rgb_invert,
		alpha_invert
	);
}

PHP_FUNCTION(grTexDetailControl)
{
	zend_object* tmu = NULL;
	zend_long lodBias;
	zend_long detailScale;
	double detailMax;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJ_OF_CLASS(tmu, grChipID_ce);
		Z_PARAM_LONG(lodBias)
		Z_PARAM_LONG(detailScale)
		Z_PARAM_DOUBLE(detailMax)
	ZEND_PARSE_PARAMETERS_END();

	grTexDetailControl(
		(GrChipID_t)enum_to_int(tmu),
		(int)lodBias,
		(FxU8)detailScale,
		(float)detailMax
	);
}

PHP_FUNCTION(grTexDownloadMipMap)
{
	zend_object* tmu = NULL;
	zend_long startAddress;
	zend_object* evenOdd = NULL;
	zend_object* info = NULL;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJ_OF_CLASS(tmu, grChipID_ce);
		Z_PARAM_LONG(startAddress)
		Z_PARAM_OBJ_OF_CLASS(evenOdd, grEvenOdd_ce);
		Z_PARAM_OBJ_OF_CLASS(info, grTexInfo_ce);
		ZEND_PARSE_PARAMETERS_END();

	grTexDownloadMipMap(
		(GrChipID_t)enum_to_int(tmu),
		(FxU32)startAddress,
		(FxU32)enum_to_int(evenOdd),
		&O_EMBEDDED_P(_GrTexInfo, info)->grTexInfo
	);
}

PHP_FUNCTION(grTexSource)
{
	zend_object* tmu = NULL;
	zend_long startAddress;
	zend_object* evenOdd = NULL;
	zend_object* info = NULL;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJ_OF_CLASS(tmu, grChipID_ce);
		Z_PARAM_LONG(startAddress)
		Z_PARAM_OBJ_OF_CLASS(evenOdd, grEvenOdd_ce);
		Z_PARAM_OBJ_OF_CLASS(info, grTexInfo_ce);
	ZEND_PARSE_PARAMETERS_END();

	grTexSource(
		(GrChipID_t)enum_to_int(tmu),
		(FxU32)startAddress,
		(FxU32)enum_to_int(evenOdd),
		&O_EMBEDDED_P(_GrTexInfo, info)->grTexInfo
	);
}

PHP_FUNCTION(guTexCombineFunction)
{
	zend_object* tmu = NULL;
	zend_object* func = NULL;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJ_OF_CLASS(tmu, grChipID_ce);
		Z_PARAM_OBJ_OF_CLASS(func, grTextureCombineFnc_ce);
	ZEND_PARSE_PARAMETERS_END();

	guTexCombineFunction(
		(GrChipID_t)enum_to_int(tmu),
		(GrTextureCombineFnc_t)enum_to_int(func)
	);
}