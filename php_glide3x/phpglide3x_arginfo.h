/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 4e37d9a5c92f86b65a3e63f23fabdc29370c7a30 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo__kbhit, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grGlideInit, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

#define arginfo_grGlideShutdown arginfo_grGlideInit

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grVertexLayout, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, param, GrParams_t, 0)
	ZEND_ARG_TYPE_INFO(0, offset, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, mode, GrMode_t, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grConstantColorValue, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, color, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grGet, 0, 2, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, pname, GrGet_t, 0)
	ZEND_ARG_TYPE_INFO(1, params, IS_MIXED, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, plength, IS_LONG, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grGetString, 0, 1, IS_STRING, 1)
	ZEND_ARG_OBJ_INFO(0, name, GrString_t, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grDrawTriangle, 0, 3, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, a, IS_OBJECT, 0)
	ZEND_ARG_TYPE_INFO(0, b, IS_OBJECT, 0)
	ZEND_ARG_TYPE_INFO(0, c, IS_OBJECT, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grBufferClear, 0, 3, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, color, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, alpha, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, depth, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grBufferSwap, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, swap_interval, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grColorCombine, 0, 5, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, func, GrCombineFunction_t, 0)
	ZEND_ARG_OBJ_INFO(0, factor, GrCombineFactor_t, 0)
	ZEND_ARG_OBJ_INFO(0, local, GrCombineLocal_t, 0)
	ZEND_ARG_OBJ_INFO(0, other, GrCombineOther_t, 0)
	ZEND_ARG_TYPE_INFO(0, invert, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grColorMask, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, rgb, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, alpha, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grSstSelect, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, which_sst, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grSstWinClose, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, context, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grSstWinOpen, 0, 7, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, hWin, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, res, GrScreenResolution_t, 0)
	ZEND_ARG_OBJ_INFO(0, ref, GrScreenRefresh_t, 0)
	ZEND_ARG_OBJ_INFO(0, cFormat, GrColorFormat_t, 0)
	ZEND_ARG_OBJ_INFO(0, org_loc, GrOriginLocation_t, 0)
	ZEND_ARG_TYPE_INFO(0, num_buffers, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, num_aux_buffers, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GrCombineFunction_t_toInt arginfo__kbhit

#define arginfo_class_GrCombineFactor_t_toInt arginfo__kbhit

#define arginfo_class_GrCombineLocal_t_toInt arginfo__kbhit

#define arginfo_class_GrCombineOther_t_toInt arginfo__kbhit

#define arginfo_class_GrAlphaSource_t_toInt arginfo__kbhit

#define arginfo_class_GrColorCombineFnc_t_toInt arginfo__kbhit

#define arginfo_class_GrAlphaBlendFnc_t_toInt arginfo__kbhit

#define arginfo_class_GrAspectRatio_t_toInt arginfo__kbhit

#define arginfo_class_GrBuffer_t_toInt arginfo__kbhit

#define arginfo_class_GrChromakeyMode_t_toInt arginfo__kbhit

#define arginfo_class_GrChromaRangeMode_t_toInt arginfo__kbhit

#define arginfo_class_GrTexChromakeyMode_t_toInt arginfo__kbhit

#define arginfo_class_GrCmpFnc_t_toInt arginfo__kbhit

#define arginfo_class_GrColorFormat_t_toInt arginfo__kbhit

#define arginfo_class_GrCullMode_t_toInt arginfo__kbhit

#define arginfo_class_GrDepthBufferMode_t_toInt arginfo__kbhit

#define arginfo_class_GrDitherMode_t_toInt arginfo__kbhit

#define arginfo_class_GrFogMode_t_toInt arginfo__kbhit

#define arginfo_class_GrLock_t_toInt arginfo__kbhit

#define arginfo_class_GrLfbBypassMode_t_toInt arginfo__kbhit

#define arginfo_class_GrLfbWriteMode_t_toInt arginfo__kbhit

#define arginfo_class_GrOriginLocation_t_toInt arginfo__kbhit

#define arginfo_class_GrLOD_t_toInt arginfo__kbhit

#define arginfo_class_GrMipMapMode_t_toInt arginfo__kbhit

#define arginfo_class_GrSmoothingMode_t_toInt arginfo__kbhit

#define arginfo_class_GrTextureClampMode_t_toInt arginfo__kbhit

#define arginfo_class_GrTextureCombineFnc_t_toInt arginfo__kbhit

#define arginfo_class_GrTextureFilterMode_t_toInt arginfo__kbhit

#define arginfo_class_GrTextureFormat_t_toInt arginfo__kbhit

#define arginfo_class_GrTexTable_t_toInt arginfo__kbhit

#define arginfo_class_GrNCCTable_t_toInt arginfo__kbhit

#define arginfo_class_GrTexBaseRange_t_toInt arginfo__kbhit

#define arginfo_class_GrEnableMode_t_toInt arginfo__kbhit

#define arginfo_class_GrCoordinateSpaceMode_t_toInt arginfo__kbhit

#define arginfo_class_GrDataStrips_t_toInt arginfo__kbhit

#define arginfo_class_GrParams_t_toInt arginfo__kbhit

#define arginfo_class_GrMode_t_toInt arginfo__kbhit

#define arginfo_class_GrVertex_t_toInt arginfo__kbhit

#define arginfo_class_GrGet_t_toInt arginfo__kbhit

#define arginfo_class_GrString_t_toInt arginfo__kbhit

#define arginfo_class_GrScreenRefresh_t_toInt arginfo__kbhit

#define arginfo_class_GrScreenResolution_t_toInt arginfo__kbhit

ZEND_FUNCTION(_kbhit);
ZEND_FUNCTION(grGlideInit);
ZEND_FUNCTION(grGlideShutdown);
ZEND_FUNCTION(grVertexLayout);
ZEND_FUNCTION(grConstantColorValue);
ZEND_FUNCTION(grGet);
ZEND_FUNCTION(grGetString);
ZEND_FUNCTION(grDrawTriangle);
ZEND_FUNCTION(grBufferClear);
ZEND_FUNCTION(grBufferSwap);
ZEND_FUNCTION(grColorCombine);
ZEND_FUNCTION(grColorMask);
ZEND_FUNCTION(grSstSelect);
ZEND_FUNCTION(grSstWinClose);
ZEND_FUNCTION(grSstWinOpen);
ZEND_METHOD(GrCombineFunction_t, toInt);
ZEND_METHOD(GrCombineFactor_t, toInt);
ZEND_METHOD(GrCombineLocal_t, toInt);
ZEND_METHOD(GrCombineOther_t, toInt);
ZEND_METHOD(GrAlphaSource_t, toInt);
ZEND_METHOD(GrColorCombineFnc_t, toInt);
ZEND_METHOD(GrAlphaBlendFnc_t, toInt);
ZEND_METHOD(GrAspectRatio_t, toInt);
ZEND_METHOD(GrBuffer_t, toInt);
ZEND_METHOD(GrChromakeyMode_t, toInt);
ZEND_METHOD(GrChromaRangeMode_t, toInt);
ZEND_METHOD(GrTexChromakeyMode_t, toInt);
ZEND_METHOD(GrCmpFnc_t, toInt);
ZEND_METHOD(GrColorFormat_t, toInt);
ZEND_METHOD(GrCullMode_t, toInt);
ZEND_METHOD(GrDepthBufferMode_t, toInt);
ZEND_METHOD(GrDitherMode_t, toInt);
ZEND_METHOD(GrFogMode_t, toInt);
ZEND_METHOD(GrLock_t, toInt);
ZEND_METHOD(GrLfbBypassMode_t, toInt);
ZEND_METHOD(GrLfbWriteMode_t, toInt);
ZEND_METHOD(GrOriginLocation_t, toInt);
ZEND_METHOD(GrLOD_t, toInt);
ZEND_METHOD(GrMipMapMode_t, toInt);
ZEND_METHOD(GrSmoothingMode_t, toInt);
ZEND_METHOD(GrTextureClampMode_t, toInt);
ZEND_METHOD(GrTextureCombineFnc_t, toInt);
ZEND_METHOD(GrTextureFilterMode_t, toInt);
ZEND_METHOD(GrTextureFormat_t, toInt);
ZEND_METHOD(GrTexTable_t, toInt);
ZEND_METHOD(GrNCCTable_t, toInt);
ZEND_METHOD(GrTexBaseRange_t, toInt);
ZEND_METHOD(GrEnableMode_t, toInt);
ZEND_METHOD(GrCoordinateSpaceMode_t, toInt);
ZEND_METHOD(GrDataStrips_t, toInt);
ZEND_METHOD(GrParams_t, toInt);
ZEND_METHOD(GrMode_t, toInt);
ZEND_METHOD(GrVertex_t, toInt);
ZEND_METHOD(GrGet_t, toInt);
ZEND_METHOD(GrString_t, toInt);
ZEND_METHOD(GrScreenRefresh_t, toInt);
ZEND_METHOD(GrScreenResolution_t, toInt);

static const zend_function_entry ext_functions[] = {
	ZEND_FE(_kbhit, arginfo__kbhit)
	ZEND_FE(grGlideInit, arginfo_grGlideInit)
	ZEND_FE(grGlideShutdown, arginfo_grGlideShutdown)
	ZEND_FE(grVertexLayout, arginfo_grVertexLayout)
	ZEND_FE(grConstantColorValue, arginfo_grConstantColorValue)
	ZEND_FE(grGet, arginfo_grGet)
	ZEND_FE(grGetString, arginfo_grGetString)
	ZEND_FE(grDrawTriangle, arginfo_grDrawTriangle)
	ZEND_FE(grBufferClear, arginfo_grBufferClear)
	ZEND_FE(grBufferSwap, arginfo_grBufferSwap)
	ZEND_FE(grColorCombine, arginfo_grColorCombine)
	ZEND_FE(grColorMask, arginfo_grColorMask)
	ZEND_FE(grSstSelect, arginfo_grSstSelect)
	ZEND_FE(grSstWinClose, arginfo_grSstWinClose)
	ZEND_FE(grSstWinOpen, arginfo_grSstWinOpen)
	ZEND_FE_END
};

static const zend_function_entry class_GrCombineFunction_t_methods[] = {
	ZEND_ME(GrCombineFunction_t, toInt, arginfo_class_GrCombineFunction_t_toInt, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrCombineFactor_t_methods[] = {
	ZEND_ME(GrCombineFactor_t, toInt, arginfo_class_GrCombineFactor_t_toInt, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrCombineLocal_t_methods[] = {
	ZEND_ME(GrCombineLocal_t, toInt, arginfo_class_GrCombineLocal_t_toInt, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrCombineOther_t_methods[] = {
	ZEND_ME(GrCombineOther_t, toInt, arginfo_class_GrCombineOther_t_toInt, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrAlphaSource_t_methods[] = {
	ZEND_ME(GrAlphaSource_t, toInt, arginfo_class_GrAlphaSource_t_toInt, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrColorCombineFnc_t_methods[] = {
	ZEND_ME(GrColorCombineFnc_t, toInt, arginfo_class_GrColorCombineFnc_t_toInt, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrAlphaBlendFnc_t_methods[] = {
	ZEND_ME(GrAlphaBlendFnc_t, toInt, arginfo_class_GrAlphaBlendFnc_t_toInt, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrAspectRatio_t_methods[] = {
	ZEND_ME(GrAspectRatio_t, toInt, arginfo_class_GrAspectRatio_t_toInt, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrBuffer_t_methods[] = {
	ZEND_ME(GrBuffer_t, toInt, arginfo_class_GrBuffer_t_toInt, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrChromakeyMode_t_methods[] = {
	ZEND_ME(GrChromakeyMode_t, toInt, arginfo_class_GrChromakeyMode_t_toInt, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrChromaRangeMode_t_methods[] = {
	ZEND_ME(GrChromaRangeMode_t, toInt, arginfo_class_GrChromaRangeMode_t_toInt, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrTexChromakeyMode_t_methods[] = {
	ZEND_ME(GrTexChromakeyMode_t, toInt, arginfo_class_GrTexChromakeyMode_t_toInt, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrCmpFnc_t_methods[] = {
	ZEND_ME(GrCmpFnc_t, toInt, arginfo_class_GrCmpFnc_t_toInt, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrColorFormat_t_methods[] = {
	ZEND_ME(GrColorFormat_t, toInt, arginfo_class_GrColorFormat_t_toInt, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrCullMode_t_methods[] = {
	ZEND_ME(GrCullMode_t, toInt, arginfo_class_GrCullMode_t_toInt, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrDepthBufferMode_t_methods[] = {
	ZEND_ME(GrDepthBufferMode_t, toInt, arginfo_class_GrDepthBufferMode_t_toInt, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrDitherMode_t_methods[] = {
	ZEND_ME(GrDitherMode_t, toInt, arginfo_class_GrDitherMode_t_toInt, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrFogMode_t_methods[] = {
	ZEND_ME(GrFogMode_t, toInt, arginfo_class_GrFogMode_t_toInt, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrLock_t_methods[] = {
	ZEND_ME(GrLock_t, toInt, arginfo_class_GrLock_t_toInt, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrLfbBypassMode_t_methods[] = {
	ZEND_ME(GrLfbBypassMode_t, toInt, arginfo_class_GrLfbBypassMode_t_toInt, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrLfbWriteMode_t_methods[] = {
	ZEND_ME(GrLfbWriteMode_t, toInt, arginfo_class_GrLfbWriteMode_t_toInt, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrOriginLocation_t_methods[] = {
	ZEND_ME(GrOriginLocation_t, toInt, arginfo_class_GrOriginLocation_t_toInt, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrLOD_t_methods[] = {
	ZEND_ME(GrLOD_t, toInt, arginfo_class_GrLOD_t_toInt, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrMipMapMode_t_methods[] = {
	ZEND_ME(GrMipMapMode_t, toInt, arginfo_class_GrMipMapMode_t_toInt, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrSmoothingMode_t_methods[] = {
	ZEND_ME(GrSmoothingMode_t, toInt, arginfo_class_GrSmoothingMode_t_toInt, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrTextureClampMode_t_methods[] = {
	ZEND_ME(GrTextureClampMode_t, toInt, arginfo_class_GrTextureClampMode_t_toInt, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrTextureCombineFnc_t_methods[] = {
	ZEND_ME(GrTextureCombineFnc_t, toInt, arginfo_class_GrTextureCombineFnc_t_toInt, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrTextureFilterMode_t_methods[] = {
	ZEND_ME(GrTextureFilterMode_t, toInt, arginfo_class_GrTextureFilterMode_t_toInt, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrTextureFormat_t_methods[] = {
	ZEND_ME(GrTextureFormat_t, toInt, arginfo_class_GrTextureFormat_t_toInt, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrTexTable_t_methods[] = {
	ZEND_ME(GrTexTable_t, toInt, arginfo_class_GrTexTable_t_toInt, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrNCCTable_t_methods[] = {
	ZEND_ME(GrNCCTable_t, toInt, arginfo_class_GrNCCTable_t_toInt, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrTexBaseRange_t_methods[] = {
	ZEND_ME(GrTexBaseRange_t, toInt, arginfo_class_GrTexBaseRange_t_toInt, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrEnableMode_t_methods[] = {
	ZEND_ME(GrEnableMode_t, toInt, arginfo_class_GrEnableMode_t_toInt, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrCoordinateSpaceMode_t_methods[] = {
	ZEND_ME(GrCoordinateSpaceMode_t, toInt, arginfo_class_GrCoordinateSpaceMode_t_toInt, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrDataStrips_t_methods[] = {
	ZEND_ME(GrDataStrips_t, toInt, arginfo_class_GrDataStrips_t_toInt, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrParams_t_methods[] = {
	ZEND_ME(GrParams_t, toInt, arginfo_class_GrParams_t_toInt, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrMode_t_methods[] = {
	ZEND_ME(GrMode_t, toInt, arginfo_class_GrMode_t_toInt, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrVertex_t_methods[] = {
	ZEND_ME(GrVertex_t, toInt, arginfo_class_GrVertex_t_toInt, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrGet_t_methods[] = {
	ZEND_ME(GrGet_t, toInt, arginfo_class_GrGet_t_toInt, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrString_t_methods[] = {
	ZEND_ME(GrString_t, toInt, arginfo_class_GrString_t_toInt, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrScreenRefresh_t_methods[] = {
	ZEND_ME(GrScreenRefresh_t, toInt, arginfo_class_GrScreenRefresh_t_toInt, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrScreenResolution_t_methods[] = {
	ZEND_ME(GrScreenResolution_t, toInt, arginfo_class_GrScreenResolution_t_toInt, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_GrCombineFunction_t(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GrCombineFunction_t", IS_UNDEF, class_GrCombineFunction_t_methods);

	zend_enum_add_case_cstr(class_entry, "GR_COMBINE_FUNCTION_ZERO", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COMBINE_FUNCTION_NONE", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COMBINE_FUNCTION_LOCAL", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COMBINE_FUNCTION_LOCAL_ALPHA", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COMBINE_FUNCTION_SCALE_OTHER", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COMBINE_FUNCTION_BLEND_OTHER", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COMBINE_FUNCTION_SCALE_OTHER_ADD_LOCAL", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COMBINE_FUNCTION_SCALE_OTHER_ADD_LOCAL_ALPHA", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COMBINE_FUNCTION_SCALE_OTHER_MINUS_LOCAL", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COMBINE_FUNCTION_SCALE_OTHER_MINUS_LOCAL_ADD_LOCAL", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COMBINE_FUNCTION_BLEND", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COMBINE_FUNCTION_SCALE_OTHER_MINUS_LOCAL_ADD_LOCAL_ALPHA", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COMBINE_FUNCTION_SCALE_MINUS_LOCAL_ADD_LOCAL", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COMBINE_FUNCTION_BLEND_LOCAL", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COMBINE_FUNCTION_SCALE_MINUS_LOCAL_ADD_LOCAL_ALPHA", NULL);

	return class_entry;
}

static zend_class_entry *register_class_GrCombineFactor_t(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GrCombineFactor_t", IS_UNDEF, class_GrCombineFactor_t_methods);

	zend_enum_add_case_cstr(class_entry, "GR_COMBINE_FACTOR_ZERO", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COMBINE_FACTOR_NONE", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COMBINE_FACTOR_LOCAL", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COMBINE_FACTOR_OTHER_ALPHA", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COMBINE_FACTOR_LOCAL_ALPHA", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COMBINE_FACTOR_TEXTURE_ALPHA", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COMBINE_FACTOR_TEXTURE_RGB", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COMBINE_FACTOR_DETAIL_FACTOR", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COMBINE_FACTOR_LOD_FRACTION", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COMBINE_FACTOR_ONE", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COMBINE_FACTOR_ONE_MINUS_LOCAL", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COMBINE_FACTOR_ONE_MINUS_OTHER_ALPHA", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COMBINE_FACTOR_ONE_MINUS_LOCAL_ALPHA", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COMBINE_FACTOR_ONE_MINUS_TEXTURE_ALPHA", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COMBINE_FACTOR_ONE_MINUS_DETAIL_FACTOR", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COMBINE_FACTOR_ONE_MINUS_LOD_FRACTION", NULL);

	return class_entry;
}

static zend_class_entry *register_class_GrCombineLocal_t(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GrCombineLocal_t", IS_UNDEF, class_GrCombineLocal_t_methods);

	zend_enum_add_case_cstr(class_entry, "GR_COMBINE_LOCAL_ITERATED", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COMBINE_LOCAL_CONSTANT", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COMBINE_LOCAL_NONE", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COMBINE_LOCAL_DEPTH", NULL);

	return class_entry;
}

static zend_class_entry *register_class_GrCombineOther_t(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GrCombineOther_t", IS_UNDEF, class_GrCombineOther_t_methods);

	zend_enum_add_case_cstr(class_entry, "GR_COMBINE_OTHER_ITERATED", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COMBINE_OTHER_TEXTURE", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COMBINE_OTHER_CONSTANT", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COMBINE_OTHER_NONE", NULL);

	return class_entry;
}

static zend_class_entry *register_class_GrAlphaSource_t(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GrAlphaSource_t", IS_UNDEF, class_GrAlphaSource_t_methods);

	zend_enum_add_case_cstr(class_entry, "GR_ALPHASOURCE_CC_ALPHA", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_ALPHASOURCE_ITERATED_ALPHA", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_ALPHASOURCE_TEXTURE_ALPHA", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_ALPHASOURCE_TEXTURE_ALPHA_TIMES_ITERATED_ALPHA", NULL);

	return class_entry;
}

static zend_class_entry *register_class_GrColorCombineFnc_t(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GrColorCombineFnc_t", IS_UNDEF, class_GrColorCombineFnc_t_methods);

	zend_enum_add_case_cstr(class_entry, "GR_COLORCOMBINE_ZERO", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COLORCOMBINE_CCRGB", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COLORCOMBINE_ITRGB", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COLORCOMBINE_ITRGB_DELTA0", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COLORCOMBINE_DECAL_TEXTURE", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COLORCOMBINE_TEXTURE_TIMES_CCRGB", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COLORCOMBINE_TEXTURE_TIMES_ITRGB", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COLORCOMBINE_TEXTURE_TIMES_ITRGB_DELTA0", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COLORCOMBINE_TEXTURE_TIMES_ITRGB_ADD_ALPHA", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COLORCOMBINE_TEXTURE_TIMES_ALPHA", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COLORCOMBINE_TEXTURE_TIMES_ALPHA_ADD_ITRGB", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COLORCOMBINE_TEXTURE_ADD_ITRGB", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COLORCOMBINE_TEXTURE_SUB_ITRGB", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COLORCOMBINE_CCRGB_BLEND_ITRGB_ON_TEXALPHA", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COLORCOMBINE_DIFF_SPEC_A", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COLORCOMBINE_DIFF_SPEC_B", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COLORCOMBINE_ONE", NULL);

	return class_entry;
}

static zend_class_entry *register_class_GrAlphaBlendFnc_t(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GrAlphaBlendFnc_t", IS_UNDEF, class_GrAlphaBlendFnc_t_methods);

	zend_enum_add_case_cstr(class_entry, "GR_BLEND_ZERO", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_BLEND_SRC_ALPHA", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_BLEND_SRC_COLOR", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_BLEND_DST_COLOR", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_BLEND_DST_ALPHA", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_BLEND_ONE", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_BLEND_ONE_MINUS_SRC_ALPHA", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_BLEND_ONE_MINUS_SRC_COLOR", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_BLEND_ONE_MINUS_DST_COLOR", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_BLEND_ONE_MINUS_DST_ALPHA", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_BLEND_RESERVED_8", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_BLEND_RESERVED_9", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_BLEND_RESERVED_A", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_BLEND_RESERVED_B", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_BLEND_RESERVED_C", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_BLEND_RESERVED_D", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_BLEND_RESERVED_E", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_BLEND_ALPHA_SATURATE", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_BLEND_PREFOG_COLOR", NULL);

	return class_entry;
}

static zend_class_entry *register_class_GrAspectRatio_t(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GrAspectRatio_t", IS_UNDEF, class_GrAspectRatio_t_methods);

	zend_enum_add_case_cstr(class_entry, "GR_ASPECT_LOG2_8x1", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_ASPECT_LOG2_4x1", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_ASPECT_LOG2_2x1", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_ASPECT_LOG2_1x1", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_ASPECT_LOG2_1x2", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_ASPECT_LOG2_1x4", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_ASPECT_LOG2_1x8", NULL);

	return class_entry;
}

static zend_class_entry *register_class_GrBuffer_t(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GrBuffer_t", IS_UNDEF, class_GrBuffer_t_methods);

	zend_enum_add_case_cstr(class_entry, "GR_BUFFER_FRONTBUFFER", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_BUFFER_BACKBUFFER", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_BUFFER_AUXBUFFER", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_BUFFER_DEPTHBUFFER", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_BUFFER_ALPHABUFFER", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_BUFFER_TRIPLEBUFFER", NULL);

	return class_entry;
}

static zend_class_entry *register_class_GrChromakeyMode_t(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GrChromakeyMode_t", IS_UNDEF, class_GrChromakeyMode_t_methods);

	zend_enum_add_case_cstr(class_entry, "GR_CHROMAKEY_DISABLE", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_CHROMAKEY_ENABLE", NULL);

	return class_entry;
}

static zend_class_entry *register_class_GrChromaRangeMode_t(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GrChromaRangeMode_t", IS_UNDEF, class_GrChromaRangeMode_t_methods);

	zend_enum_add_case_cstr(class_entry, "GR_CHROMARANGE_RGB_ALL_EXT", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_CHROMARANGE_DISABLE_EXT", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_CHROMARANGE_ENABLE_EXT", NULL);

	return class_entry;
}

static zend_class_entry *register_class_GrTexChromakeyMode_t(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GrTexChromakeyMode_t", IS_UNDEF, class_GrTexChromakeyMode_t_methods);

	zend_enum_add_case_cstr(class_entry, "GR_TEXCHROMA_DISABLE_EXT", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_TEXCHROMA_ENABLE_EXT", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_TEXCHROMARANGE_RGB_ALL_EXT", NULL);

	return class_entry;
}

static zend_class_entry *register_class_GrCmpFnc_t(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GrCmpFnc_t", IS_UNDEF, class_GrCmpFnc_t_methods);

	zend_enum_add_case_cstr(class_entry, "GR_CMP_NEVER", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_CMP_LESS", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_CMP_EQUAL", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_CMP_LEQUAL", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_CMP_GREATER", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_CMP_NOTEQUAL", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_CMP_GEQUAL", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_CMP_ALWAYS", NULL);

	return class_entry;
}

static zend_class_entry *register_class_GrColorFormat_t(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GrColorFormat_t", IS_UNDEF, class_GrColorFormat_t_methods);

	zend_enum_add_case_cstr(class_entry, "GR_COLORFORMAT_ARGB", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COLORFORMAT_ABGR", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COLORFORMAT_RGBA", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_COLORFORMAT_BGRA", NULL);

	return class_entry;
}

static zend_class_entry *register_class_GrCullMode_t(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GrCullMode_t", IS_UNDEF, class_GrCullMode_t_methods);

	zend_enum_add_case_cstr(class_entry, "GR_CULL_DISABLE", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_CULL_NEGATIVE", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_CULL_POSITIVE", NULL);

	return class_entry;
}

static zend_class_entry *register_class_GrDepthBufferMode_t(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GrDepthBufferMode_t", IS_UNDEF, class_GrDepthBufferMode_t_methods);

	zend_enum_add_case_cstr(class_entry, "GR_DEPTHBUFFER_DISABLE", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_DEPTHBUFFER_ZBUFFER", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_DEPTHBUFFER_WBUFFER", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_DEPTHBUFFER_ZBUFFER_COMPARE_TO_BIAS", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_DEPTHBUFFER_WBUFFER_COMPARE_TO_BIAS", NULL);

	return class_entry;
}

static zend_class_entry *register_class_GrDitherMode_t(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GrDitherMode_t", IS_UNDEF, class_GrDitherMode_t_methods);

	zend_enum_add_case_cstr(class_entry, "GR_DITHER_DISABLE", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_DITHER_2x2", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_DITHER_4x4", NULL);

	return class_entry;
}

static zend_class_entry *register_class_GrFogMode_t(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GrFogMode_t", IS_UNDEF, class_GrFogMode_t_methods);

	zend_enum_add_case_cstr(class_entry, "GR_FOG_DISABLE", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_FOG_WITH_TABLE_ON_FOGCOORD_EXT", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_FOG_WITH_TABLE_ON_Q", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_FOG_WITH_TABLE_ON_W", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_FOG_WITH_ITERATED_Z", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_FOG_MULT2", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_FOG_ADD2", NULL);

	return class_entry;
}

static zend_class_entry *register_class_GrLock_t(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GrLock_t", IS_UNDEF, class_GrLock_t_methods);

	zend_enum_add_case_cstr(class_entry, "GR_LFB_READ_ONLY", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_LFB_WRITE_ONLY", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_LFB_IDLE", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_LFB_NOIDLE", NULL);

	return class_entry;
}

static zend_class_entry *register_class_GrLfbBypassMode_t(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GrLfbBypassMode_t", IS_UNDEF, class_GrLfbBypassMode_t_methods);

	zend_enum_add_case_cstr(class_entry, "GR_LFBBYPASS_DISABLE", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_LFBBYPASS_ENABLE", NULL);

	return class_entry;
}

static zend_class_entry *register_class_GrLfbWriteMode_t(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GrLfbWriteMode_t", IS_UNDEF, class_GrLfbWriteMode_t_methods);

	zend_enum_add_case_cstr(class_entry, "GR_LFBWRITEMODE_565", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_LFBWRITEMODE_555", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_LFBWRITEMODE_1555", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_LFBWRITEMODE_RESERVED1", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_LFBWRITEMODE_888", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_LFBWRITEMODE_8888", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_LFBWRITEMODE_RESERVED2", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_LFBWRITEMODE_RESERVED3", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_LFBWRITEMODE_RESERVED4", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_LFBWRITEMODE_RESERVED5", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_LFBWRITEMODE_RESERVED6", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_LFBWRITEMODE_RESERVED7", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_LFBWRITEMODE_565_DEPTH", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_LFBWRITEMODE_555_DEPTH", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_LFBWRITEMODE_1555_DEPTH", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_LFBWRITEMODE_ZA16", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_LFBWRITEMODE_ANY", NULL);

	return class_entry;
}

static zend_class_entry *register_class_GrOriginLocation_t(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GrOriginLocation_t", IS_UNDEF, class_GrOriginLocation_t_methods);

	zend_enum_add_case_cstr(class_entry, "GR_ORIGIN_UPPER_LEFT", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_ORIGIN_LOWER_LEFT", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_ORIGIN_ANY", NULL);

	return class_entry;
}

static zend_class_entry *register_class_GrLOD_t(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GrLOD_t", IS_UNDEF, class_GrLOD_t_methods);

	zend_enum_add_case_cstr(class_entry, "GR_LOD_LOG2_256", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_LOD_LOG2_128", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_LOD_LOG2_64", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_LOD_LOG2_32", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_LOD_LOG2_16", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_LOD_LOG2_8", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_LOD_LOG2_4", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_LOD_LOG2_2", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_LOD_LOG2_1", NULL);

	return class_entry;
}

static zend_class_entry *register_class_GrMipMapMode_t(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GrMipMapMode_t", IS_UNDEF, class_GrMipMapMode_t_methods);

	zend_enum_add_case_cstr(class_entry, "GR_MIPMAP_DISABLE", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_MIPMAP_NEAREST", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_MIPMAP_NEAREST_DITHER", NULL);

	return class_entry;
}

static zend_class_entry *register_class_GrSmoothingMode_t(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GrSmoothingMode_t", IS_UNDEF, class_GrSmoothingMode_t_methods);

	zend_enum_add_case_cstr(class_entry, "GR_SMOOTHING_DISABLE", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_SMOOTHING_ENABLE", NULL);

	return class_entry;
}

static zend_class_entry *register_class_GrTextureClampMode_t(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GrTextureClampMode_t", IS_UNDEF, class_GrTextureClampMode_t_methods);

	zend_enum_add_case_cstr(class_entry, "GR_TEXTURECLAMP_WRAP", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_TEXTURECLAMP_CLAMP", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_TEXTURECLAMP_MIRROR_EXT", NULL);

	return class_entry;
}

static zend_class_entry *register_class_GrTextureCombineFnc_t(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GrTextureCombineFnc_t", IS_UNDEF, class_GrTextureCombineFnc_t_methods);

	zend_enum_add_case_cstr(class_entry, "GR_TEXTURECOMBINE_ZERO", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_TEXTURECOMBINE_DECAL", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_TEXTURECOMBINE_OTHER", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_TEXTURECOMBINE_ADD", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_TEXTURECOMBINE_MULTIPLY", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_TEXTURECOMBINE_SUBTRACT", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_TEXTURECOMBINE_DETAIL", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_TEXTURECOMBINE_DETAIL_OTHER", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_TEXTURECOMBINE_TRILINEAR_ODD", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_TEXTURECOMBINE_TRILINEAR_EVEN", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_TEXTURECOMBINE_ONE", NULL);

	return class_entry;
}

static zend_class_entry *register_class_GrTextureFilterMode_t(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GrTextureFilterMode_t", IS_UNDEF, class_GrTextureFilterMode_t_methods);

	zend_enum_add_case_cstr(class_entry, "GR_TEXTUREFILTER_POINT_SAMPLED", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_TEXTUREFILTER_BILINEAR", NULL);

	return class_entry;
}

static zend_class_entry *register_class_GrTextureFormat_t(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GrTextureFormat_t", IS_UNDEF, class_GrTextureFormat_t_methods);

	zend_enum_add_case_cstr(class_entry, "GR_TEXFMT_8BIT", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_TEXFMT_RGB_332", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_TEXFMT_YIQ_422", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_TEXFMT_ALPHA_8", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_TEXFMT_INTENSITY_8", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_TEXFMT_ALPHA_INTENSITY_44", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_TEXFMT_P_8", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_TEXFMT_RSVD0", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_TEXFMT_RSVD1", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_TEXFMT_16BIT", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_TEXFMT_ARGB_8332", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_TEXFMT_AYIQ_8422", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_TEXFMT_RGB_565", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_TEXFMT_ARGB_1555", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_TEXFMT_ARGB_4444", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_TEXFMT_ALPHA_INTENSITY_88", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_TEXFMT_AP_88", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_TEXFMT_RSVD2", NULL);

	return class_entry;
}

static zend_class_entry *register_class_GrTexTable_t(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GrTexTable_t", IS_UNDEF, class_GrTexTable_t_methods);

	zend_enum_add_case_cstr(class_entry, "GR_TEXTABLE_NCC0", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_TEXTABLE_NCC1", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_TEXTABLE_PALETTE", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_TEXTABLE_PALETTE_6666_EXT", NULL);

	return class_entry;
}

static zend_class_entry *register_class_GrNCCTable_t(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GrNCCTable_t", IS_UNDEF, class_GrNCCTable_t_methods);

	zend_enum_add_case_cstr(class_entry, "GR_NCCTABLE_NCC0", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_NCCTABLE_NCC1", NULL);

	return class_entry;
}

static zend_class_entry *register_class_GrTexBaseRange_t(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GrTexBaseRange_t", IS_UNDEF, class_GrTexBaseRange_t_methods);

	zend_enum_add_case_cstr(class_entry, "GR_TEXBASE_256", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_TEXBASE_128", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_TEXBASE_64", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_TEXBASE_32_TO_1", NULL);

	return class_entry;
}

static zend_class_entry *register_class_GrEnableMode_t(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GrEnableMode_t", IS_UNDEF, class_GrEnableMode_t_methods);

	zend_enum_add_case_cstr(class_entry, "GR_MODE_DISABLE", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_MODE_ENABLE", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_AA_ORDERED", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_ALLOW_MIPMAP_DITHER", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_PASSTHRU", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_SHAMELESS_PLUG", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_VIDEO_SMOOTHING", NULL);

	return class_entry;
}

static zend_class_entry *register_class_GrCoordinateSpaceMode_t(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GrCoordinateSpaceMode_t", IS_UNDEF, class_GrCoordinateSpaceMode_t_methods);

	zend_enum_add_case_cstr(class_entry, "GR_WINDOW_COORDS", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_CLIP_COORDS", NULL);

	return class_entry;
}

static zend_class_entry *register_class_GrDataStrips_t(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GrDataStrips_t", IS_UNDEF, class_GrDataStrips_t_methods);

	zend_enum_add_case_cstr(class_entry, "GR_FLOAT", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_U8", NULL);

	return class_entry;
}

static zend_class_entry *register_class_GrParams_t(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GrParams_t", IS_UNDEF, class_GrParams_t_methods);

	zend_enum_add_case_cstr(class_entry, "GR_PARAM_XY", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_PARAM_Z", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_PARAM_W", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_PARAM_Q", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_PARAM_FOG_EXT", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_PARAM_A", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_PARAM_RGB", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_PARAM_PARGB", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_PARAM_ST0", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_PARAM_ST1", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_PARAM_ST2", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_PARAM_Q0", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_PARAM_Q1", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_PARAM_Q2", NULL);

	return class_entry;
}

static zend_class_entry *register_class_GrMode_t(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GrMode_t", IS_UNDEF, class_GrMode_t_methods);

	zend_enum_add_case_cstr(class_entry, "GR_PARAM_DISABLE", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_PARAM_ENABLE", NULL);

	return class_entry;
}

static zend_class_entry *register_class_GrVertex_t(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GrVertex_t", IS_UNDEF, class_GrVertex_t_methods);

	zend_enum_add_case_cstr(class_entry, "GR_POINTS", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_LINE_STRIP", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_LINES", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_POLYGON", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_TRIANGLE_STRIP", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_TRIANGLE_FAN", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_TRIANGLES", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_TRIANGLE_STRIP_CONTINUE", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_TRIANGLE_FAN_CONTINUE", NULL);

	return class_entry;
}

static zend_class_entry *register_class_GrGet_t(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GrGet_t", IS_UNDEF, class_GrGet_t_methods);

	zend_enum_add_case_cstr(class_entry, "GR_BITS_DEPTH", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_BITS_RGBA", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_BITS_GAMMA", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_FIFO_FULLNESS", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_FOG_TABLE_ENTRIES", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_GAMMA_TABLE_ENTRIES", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_GLIDE_STATE_SIZE", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_GLIDE_VERTEXLAYOUT_SIZE", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_IS_BUSY", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_LFB_PIXEL_PIPE", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_MAX_TEXTURE_SIZE", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_MAX_TEXTURE_ASPECT_RATIO", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_MEMORY_FB", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_MEMORY_TMU", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_MEMORY_UMA", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_NON_POWER_OF_TWO_TEXTURES", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_NUM_BOARDS", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_NUM_FB", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_NUM_SWAP_HISTORY_BUFFER", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_NUM_TMU", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_PENDING_BUFFERSWAPS", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_REVISION_FB", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_REVISION_TMU", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_STATS_LINES", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_STATS_PIXELS_AFUNC_FAIL", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_STATS_PIXELS_CHROMA_FAIL", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_STATS_PIXELS_DEPTHFUNC_FAIL", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_STATS_PIXELS_IN", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_STATS_PIXELS_OUT", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_STATS_POINTS", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_STATS_TRIANGLES_IN", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_STATS_TRIANGLES_OUT", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_SWAP_HISTORY", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_SUPPORTS_PASSTHRU", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_TEXTURE_ALIGN", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_VIDEO_POSITION", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_VIEWPORT", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_WDEPTH_MIN_MAX", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_ZDEPTH_MIN_MAX", NULL);

	return class_entry;
}

static zend_class_entry *register_class_GrString_t(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GrString_t", IS_UNDEF, class_GrString_t_methods);

	zend_enum_add_case_cstr(class_entry, "GR_EXTENSION", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_HARDWARE", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_RENDERER", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_VENDOR", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_VERSION", NULL);

	return class_entry;
}

static zend_class_entry *register_class_GrScreenRefresh_t(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GrScreenRefresh_t", IS_UNDEF, class_GrScreenRefresh_t_methods);

	zend_enum_add_case_cstr(class_entry, "GR_REFRESH_60Hz", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_REFRESH_70Hz", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_REFRESH_72Hz", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_REFRESH_75Hz", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_REFRESH_80Hz", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_REFRESH_90Hz", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_REFRESH_100Hz", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_REFRESH_85Hz", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_REFRESH_120Hz", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_REFRESH_NONE", NULL);

	return class_entry;
}

static zend_class_entry *register_class_GrScreenResolution_t(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GrScreenResolution_t", IS_UNDEF, class_GrScreenResolution_t_methods);

	zend_enum_add_case_cstr(class_entry, "GR_RESOLUTION_320x200", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_RESOLUTION_320x240", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_RESOLUTION_400x256", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_RESOLUTION_512x384", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_RESOLUTION_640x200", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_RESOLUTION_640x350", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_RESOLUTION_640x400", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_RESOLUTION_640x480", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_RESOLUTION_800x600", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_RESOLUTION_960x720", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_RESOLUTION_856x480", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_RESOLUTION_512x256", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_RESOLUTION_1024x768", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_RESOLUTION_1280x1024", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_RESOLUTION_1600x1200", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_RESOLUTION_400x300", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_RESOLUTION_NONE", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_RESOLUTION_MIN", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_RESOLUTION_MAX", NULL);

	return class_entry;
}
