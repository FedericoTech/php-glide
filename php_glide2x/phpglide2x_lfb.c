#include "phpglide2x_lfb.h"
#include "phpglide2x_structs.h"
#include "phpglide2x_enums.h"


PHP_FUNCTION(grLfbConstantAlpha)
{
	zend_long alpha;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(alpha);
	ZEND_PARSE_PARAMETERS_END();

	grLfbConstantAlpha((GrAlpha_t)alpha);
}

PHP_FUNCTION(grLfbConstantDepth)
{
	zend_long depth;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(depth);
	ZEND_PARSE_PARAMETERS_END();

	grLfbConstantDepth((FxU16)depth);
}

PHP_FUNCTION(grLfbLock)
{
	zend_object* type = NULL;
	zend_object* buffer = NULL;
	zend_object* writeMode = NULL;
	zend_object* origin = NULL;
	zend_bool pixelPipeline;
	zend_object* info = NULL;

	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_OBJ_OF_CLASS(type, grLock_ce);
		Z_PARAM_OBJ_OF_CLASS(buffer, grBuffer_ce);
		Z_PARAM_OBJ_OF_CLASS(writeMode, grLfbWriteMode_ce);
		Z_PARAM_OBJ_OF_CLASS(origin, grOriginLocation_ce);
		Z_PARAM_BOOL(pixelPipeline);
		Z_PARAM_OBJ_OF_CLASS(info, grLfbInfo_ce);
	ZEND_PARSE_PARAMETERS_END();

	_GrLfbInfo_t *grLfbInfo = O_EMBEDDED_P(_GrLfbInfo_t, info);

	GrLock_t lock_type = enum_to_int(type);

	RETVAL_BOOL(grLfbLock(
		lock_type,
		(GrBuffer_t)enum_to_int(buffer),
		(GrLfbWriteMode_t)enum_to_int(writeMode),
		(GrOriginLocation_t)enum_to_int(origin),
		(FxBool)pixelPipeline,
		&grLfbInfo->grLfbInfo
	));

	hydrate_grLfbInfo(
		&grLfbInfo->grLfbInfo, 
		grLfbInfo, 
		lock_type == GR_LFB_READ_ONLY
	);
}

PHP_FUNCTION(grLfbReadRegion)
{
	zend_object* src_buffer = NULL;
	zend_long src_x, src_y, src_width, src_height, dst_stride;
	zval* dst_data_zv = NULL;
	//char* dst_data_str = NULL;
	//size_t dst_data_len;

	ZEND_PARSE_PARAMETERS_START(7, 7)
		Z_PARAM_OBJ_OF_CLASS(src_buffer, grBuffer_ce);
		Z_PARAM_LONG(src_x);
		Z_PARAM_LONG(src_y);
		Z_PARAM_LONG(src_width);
		Z_PARAM_LONG(src_height);
		Z_PARAM_LONG(dst_stride);
		Z_PARAM_ZVAL(dst_data_zv)
		//Z_PARAM_STRING(dst_data_str, dst_data_len)
	ZEND_PARSE_PARAMETERS_END();

	size_t len = src_width * 2 * src_height;

	char* buffer = emalloc(len);
	
	bool ret = grLfbReadRegion(
		(GrLock_t)enum_to_int(src_buffer),
		(FxU32)src_x, (FxU32)src_y,
		(FxU32)src_width, (FxU32)src_height,
		(FxU32)dst_stride,
		buffer
	);

	RETVAL_BOOL(ret);

	if (ret) {
		zend_string* zstr = zend_string_init(buffer, len, 0);

		// Make sure we're working with a real zval reference
		ZVAL_DEREF(dst_data_zv);         // Ensure it's not shared
		zval_ptr_dtor(dst_data_zv);         // Free previous value
		ZVAL_STR(dst_data_zv, zstr);        // Set new binary string
	}

	efree(buffer);
}

PHP_FUNCTION(grLfbUnlock)
{
	zend_object* type = NULL;
	zend_object* buffer = NULL;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJ_OF_CLASS(type, grLock_ce);
		Z_PARAM_OBJ_OF_CLASS(buffer, grBuffer_ce);
	ZEND_PARSE_PARAMETERS_END();

	RETURN_BOOL(grLfbUnlock(
		(GrLock_t)enum_to_int(type),
		(GrBuffer_t)enum_to_int(buffer)
	));
}

PHP_FUNCTION(grLfbWriteRegion)
{
	zend_object* buffer = NULL;
	zend_long dst_x, dst_y;
	zend_object* src_format = NULL;
	zend_long src_width, src_height;
	zend_long src_stride;
	char* src_data_str = NULL;
	size_t src_data_len;
	
	ZEND_PARSE_PARAMETERS_START(8, 8)
		Z_PARAM_OBJ_OF_CLASS(buffer, grBuffer_ce);
		Z_PARAM_LONG(dst_x);
		Z_PARAM_LONG(dst_y);
		Z_PARAM_OBJ_OF_CLASS(src_format, grLfbSrcFmt_ce);
		Z_PARAM_LONG(src_width);
		Z_PARAM_LONG(src_height);
		Z_PARAM_LONG(src_stride);
		Z_PARAM_STRING(src_data_str, src_data_len)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_BOOL(grLfbWriteRegion(
		(GrBuffer_t)enum_to_int(buffer),
		(FxU32) dst_x, (FxU32) dst_y,
		(GrLfbSrcFmt_t)enum_to_int(src_format),
		(FxU32) src_width, (FxU32) src_height,
		(FxI32) src_stride,
		src_data_str
	));
}