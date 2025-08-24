#include "stdafx.h"
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


//grTexDownloadMipMapLevel

PHP_FUNCTION(grTexDownloadMipMapLevel)
{
	zend_object* tmu = NULL;
	zend_long startAddress;
	zend_object* thisLod = NULL;
	zend_object* largeLod = NULL;
	zend_object* aspectRatio = NULL;
	zend_object* format = NULL;
	zend_object* evenOdd = NULL;
	char* src_data_str = NULL;
	size_t src_data_len;

	ZEND_PARSE_PARAMETERS_START(8, 8)
		Z_PARAM_OBJ_OF_CLASS(tmu, grChipID_ce);
		Z_PARAM_LONG(startAddress)
		Z_PARAM_OBJ_OF_CLASS(thisLod, grLOD_ce);
		Z_PARAM_OBJ_OF_CLASS(largeLod, grLOD_ce);
		Z_PARAM_OBJ_OF_CLASS(aspectRatio, grAspectRatio_ce);
		Z_PARAM_OBJ_OF_CLASS(format, grTextureFormat_ce);
		Z_PARAM_OBJ_OF_CLASS(evenOdd, grEvenOdd_ce);
		Z_PARAM_STRING(src_data_str, src_data_len)
	ZEND_PARSE_PARAMETERS_END();

	grTexDownloadMipMapLevel(
		(GrChipID_t)enum_to_int(tmu),
		(FxU32)startAddress,
		(GrLOD_t)enum_to_int(thisLod),
		(GrLOD_t)enum_to_int(largeLod),
		(GrAspectRatio_t)enum_to_int(aspectRatio),
		(GrTextureFormat_t)enum_to_int(format),
		(FxU32)enum_to_int(evenOdd),
		src_data_str
	);
}

PHP_FUNCTION(grTexDownloadMipMapLevelPartial)
{
	zend_object* tmu = NULL;
	zend_long startAddress;
	zend_object* thisLod = NULL;
	zend_object* largeLod = NULL;
	zend_object* aspectRatio = NULL;
	zend_object* format = NULL;
	zend_object* evenOdd = NULL;
	char* src_data_str = NULL;
	size_t src_data_len;
	zend_long start;
	zend_long end;

	ZEND_PARSE_PARAMETERS_START(10, 10)
		Z_PARAM_OBJ_OF_CLASS(tmu, grChipID_ce);
		Z_PARAM_LONG(startAddress)
		Z_PARAM_OBJ_OF_CLASS(thisLod, grLOD_ce);
		Z_PARAM_OBJ_OF_CLASS(largeLod, grLOD_ce);
		Z_PARAM_OBJ_OF_CLASS(aspectRatio, grAspectRatio_ce);
		Z_PARAM_OBJ_OF_CLASS(format, grTextureFormat_ce);
		Z_PARAM_OBJ_OF_CLASS(evenOdd, grEvenOdd_ce);
		Z_PARAM_STRING(src_data_str, src_data_len);
		Z_PARAM_LONG(start);
		Z_PARAM_LONG(end);
	ZEND_PARSE_PARAMETERS_END();

	grTexDownloadMipMapLevelPartial(
		(GrChipID_t)enum_to_int(tmu),
		(FxU32)startAddress,
		(GrLOD_t)enum_to_int(thisLod),
		(GrLOD_t)enum_to_int(largeLod),
		(GrAspectRatio_t)enum_to_int(aspectRatio),
		(GrTextureFormat_t)enum_to_int(format),
		(FxU32)enum_to_int(evenOdd),
		src_data_str,
		(FxU32)start,
		(FxU32)end
	);
}

PHP_FUNCTION(grTexDownloadTable)
{
	zend_object* tmu = NULL;
	zend_object* type = NULL;
	char* src_data_str = NULL;
	size_t src_data_len;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJ_OF_CLASS(tmu, grChipID_ce);
		Z_PARAM_OBJ_OF_CLASS(type, grTexTable_ce);
		Z_PARAM_STRING(src_data_str, src_data_len);
	ZEND_PARSE_PARAMETERS_END();

	grTexDownloadTable(
		(GrChipID_t)enum_to_int(tmu),
		(GrTexTable_t)enum_to_int(type),
		src_data_str
	);
}

PHP_FUNCTION(grTexDownloadTablePartial)
{
	zend_object* tmu = NULL;
	zend_object* type = NULL;
	char* src_data_str = NULL;
	size_t src_data_len;
	zend_long start;
	zend_long end;

	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_OBJ_OF_CLASS(tmu, grChipID_ce);
		Z_PARAM_OBJ_OF_CLASS(type, grTexTable_ce);
		Z_PARAM_STRING(src_data_str, src_data_len);
		Z_PARAM_LONG(start);
		Z_PARAM_LONG(end);
	ZEND_PARSE_PARAMETERS_END();

	grTexDownloadTablePartial(
		(GrChipID_t)enum_to_int(tmu),
		(GrTexTable_t)enum_to_int(type),
		src_data_str,
		start,
		end
	);
}

PHP_FUNCTION(grTexFilterMode)
{
	zend_object* tmu = NULL;
	zend_object* minFilterMode = NULL;
	zend_object* magFilterMode = NULL;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJ_OF_CLASS(tmu, grChipID_ce);
		Z_PARAM_OBJ_OF_CLASS(minFilterMode, grTextureFilterMode_ce);
		Z_PARAM_OBJ_OF_CLASS(magFilterMode, grTextureFilterMode_ce);
	ZEND_PARSE_PARAMETERS_END();

	grTexFilterMode(
		(GrChipID_t)enum_to_int(tmu),
		(GrTextureFilterMode_t)enum_to_int(minFilterMode),
		(GrTextureFilterMode_t)enum_to_int(magFilterMode)
	);
}

//grTexLodBiasValue

PHP_FUNCTION(grTexLodBiasValue)
{
	zend_object* tmu = NULL;
	double detailMax;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJ_OF_CLASS(tmu, grChipID_ce);
		Z_PARAM_DOUBLE(detailMax);
	ZEND_PARSE_PARAMETERS_END();

	grTexLodBiasValue(
		(GrChipID_t)enum_to_int(tmu),
		(float) detailMax
	);
}

PHP_FUNCTION(grTexMinAddress)
{
	zend_object* tmu = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(tmu, grChipID_ce);
	ZEND_PARSE_PARAMETERS_END();

	RETURN_LONG(grTexMinAddress((GrChipID_t)enum_to_int(tmu)));
}

PHP_FUNCTION(grTexMaxAddress)
{
	zend_object* tmu = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(tmu, grChipID_ce);
	ZEND_PARSE_PARAMETERS_END();

	RETURN_LONG(grTexMaxAddress((GrChipID_t)enum_to_int(tmu)));
}

PHP_FUNCTION(grTexMipMapMode)
{
	zend_object* tmu = NULL;
	zend_object* mode = NULL;
	zend_bool lodBlend;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJ_OF_CLASS(tmu, grChipID_ce);
		Z_PARAM_OBJ_OF_CLASS(mode, grMipMapMode_ce);
		Z_PARAM_BOOL(lodBlend)
	ZEND_PARSE_PARAMETERS_END();

	grTexMipMapMode(
		(GrChipID_t)enum_to_int(tmu),
		(FxU32)enum_to_int(mode),
		lodBlend
	);
}

PHP_FUNCTION(grTexMultibase)
{
	zend_object* tmu = NULL;
	zend_bool enabled;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJ_OF_CLASS(tmu, grChipID_ce);
		Z_PARAM_BOOL(enabled);
	ZEND_PARSE_PARAMETERS_END();

	grTexMultibase(
		(GrChipID_t)enum_to_int(tmu),
		enabled
	);
}

PHP_FUNCTION(grTexMultibaseAddress)
{
	zend_object* tmu = NULL;
	zend_object* range = NULL;
	zend_long startAddress;
	zend_object* evenOdd = NULL;
	zend_object* info = NULL;

	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_OBJ_OF_CLASS(tmu, grChipID_ce);
		Z_PARAM_OBJ_OF_CLASS(range, grTexBaseRange_ce);
		Z_PARAM_LONG(startAddress);
		Z_PARAM_OBJ_OF_CLASS(evenOdd, grEvenOdd_ce);
		Z_PARAM_OBJ_OF_CLASS(info, grTexInfo_ce);
	ZEND_PARSE_PARAMETERS_END();

	grTexMultibaseAddress(
		(GrChipID_t)enum_to_int(tmu),
		(GrTexBaseRange_t)enum_to_int(range),
		(int)startAddress,
		(FxU32)enum_to_int(evenOdd),
		&O_EMBEDDED_P(_GrTexInfo, info)->grTexInfo
	);
}

PHP_FUNCTION(grTexNCCTable)
{
	zend_object* tmu = NULL;
	zend_object* table = NULL;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJ_OF_CLASS(tmu, grChipID_ce);
		Z_PARAM_OBJ_OF_CLASS(table, grNCCTable_ce);
	ZEND_PARSE_PARAMETERS_END();

	grTexNCCTable(
		(GrChipID_t)enum_to_int(tmu),
		(GrNCCTable_t)enum_to_int(table)
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


PHP_FUNCTION(grTexTextureMemRequired)
{
	zend_object* evenOdd = NULL;
	zend_object* info = NULL;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJ_OF_CLASS(evenOdd, grEvenOdd_ce);
		Z_PARAM_OBJ_OF_CLASS(info, grTexInfo_ce);
	ZEND_PARSE_PARAMETERS_END();

	RETURN_LONG(grTexTextureMemRequired(
		(FxU32)enum_to_int(evenOdd),
		&O_EMBEDDED_P(_GrTexInfo, info)->grTexInfo
	));
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