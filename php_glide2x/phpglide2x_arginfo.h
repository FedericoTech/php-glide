/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 2065484e420d8ed191cba7fb65045d400aa29960 */

#if defined(_DEBUG)
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_testGrTMUConfig_t, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, gtmu, GrTMUConfig_t, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_testGrVoodooConfig_t, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, gvc, GrVoodooConfig_t, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_testGrVoodoo2Config_t, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, gv2c, GrVoodoo2Config_t, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_testGrSst96Config_t, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, gs9c, GrSst96Config_t, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_testGrAT3DConfig_t, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, ga4dc, GrAT3DConfig_t, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_testSST_t, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, sst, SST_t, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_testGrHwConfiguration, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, chc, GrHwConfiguration, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_testGrTmuVertex, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, gtv, GrTmuVertex, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_testGrVertex, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, chc, GrVertex, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_testObject, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, obj, IS_OBJECT, 0)
ZEND_END_ARG_INFO()
#endif

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grAADrawLine, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, va, GrVertex, 0)
	ZEND_ARG_OBJ_INFO(0, vb, GrVertex, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grAADrawPoint, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, p, GrVertex, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grAADrawPolygon, 0, 3, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, nVerts, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ilist, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, vlist, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grAADrawPolygonVertexList, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, nVerts, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, vlist, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grAADrawTriangle, 0, 6, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, a, GrVertex, 0)
	ZEND_ARG_OBJ_INFO(0, b, GrVertex, 0)
	ZEND_ARG_OBJ_INFO(0, c, GrVertex, 0)
	ZEND_ARG_TYPE_INFO(0, antialiasAB, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, antialiasBC, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, antialiasCA, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grAlphaBlendFunction, 0, 4, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, rgb_sf, GrAlphaBlendFnc_t, 0)
	ZEND_ARG_OBJ_INFO(0, rgb_df, GrAlphaBlendFnc_t, 0)
	ZEND_ARG_OBJ_INFO(0, alpha_sf, GrAlphaBlendFnc_t, 0)
	ZEND_ARG_OBJ_INFO(0, alpha_df, GrAlphaBlendFnc_t, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grAlphaCombine, 0, 5, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, func, GrCombineFunction_t, 0)
	ZEND_ARG_OBJ_INFO(0, factor, GrCombineFactor_t, 0)
	ZEND_ARG_OBJ_INFO(0, local, GrCombineLocal_t, 0)
	ZEND_ARG_OBJ_INFO(0, other, GrCombineOther_t, 0)
	ZEND_ARG_TYPE_INFO(0, invert, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grAlphaControlsITRGBLighting, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, enable, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grAlphaTestFunction, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, function, GrCmpFnc_t, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grAlphaTestReferenceValue, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grBufferClear, 0, 3, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, color, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, alpha, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, depth, GrDepth_t, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grBufferNumPending, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grBufferSwap, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, swap_interval, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grChromakeyMode, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, mode, GrChromakeyMode_t, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grChromakeyValue, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, color, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grClipWindow, 0, 4, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, minx, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, miny, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, maxx, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, maxy, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_grColorCombine arginfo_grAlphaCombine

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grColorMask, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, rgb, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, alpha, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_grConstantColorValue arginfo_grChromakeyValue

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grCullMode, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, mode, GrCullMode_t, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grDepthBiasLevel, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, level, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grDepthBufferFunction, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, func, GrCmpFnc_t, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grDepthBufferMode, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, mode, GrDepthBufferMode_t, 0)
ZEND_END_ARG_INFO()

#define arginfo_grDepthMask arginfo_grAlphaControlsITRGBLighting

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grDisableAllEffects, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grDitherMode, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, mode, GrDitherMode_t, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grDrawLine, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, a, GrVertex, 0)
	ZEND_ARG_OBJ_INFO(0, b, GrVertex, 0)
ZEND_END_ARG_INFO()

#define arginfo_grDrawPlanarPolygon arginfo_grAADrawPolygon

#define arginfo_grDrawPlanarPolygonVertexList arginfo_grAADrawPolygonVertexList

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grDrawPoint, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, a, GrVertex, 0)
ZEND_END_ARG_INFO()

#define arginfo_grDrawPolygon arginfo_grAADrawPolygon

#define arginfo_grDrawPolygonVertexList arginfo_grAADrawPolygonVertexList

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grErrorSetCallback, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, function, IS_CALLABLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_grFogColorValue arginfo_grAlphaTestReferenceValue

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grFogMode, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, mode, GrFogMode_t, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grFogTable, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, table, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_guFogGenerateLinear, 0, 3, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(1, fogTable, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, nearW, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, farW, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_grGlideInit arginfo_grDisableAllEffects

#define arginfo_grGlideShutdown arginfo_grDisableAllEffects

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grSstQueryHardware, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, hwConfig, GrHwConfiguration, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grSstSelect, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, which_sst, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grDrawTriangle, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, a, GrVertex, 0)
	ZEND_ARG_OBJ_INFO(0, b, GrVertex, 0)
	ZEND_ARG_OBJ_INFO(0, c, GrVertex, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_guColorCombineFunction, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, func, GrColorCombineFnc_t, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grSstWinOpen, 0, 7, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, hWin, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, res, GrScreenResolution_t, 0)
	ZEND_ARG_OBJ_INFO(0, ref, GrScreenRefresh_t, 0)
	ZEND_ARG_OBJ_INFO(0, cFormat, GrColorFormat_t, 0)
	ZEND_ARG_OBJ_INFO(0, org_loc, GrOriginLocation_t, 0)
	ZEND_ARG_TYPE_INFO(0, num_buffers, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, num_aux_buffers, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_grSstWinClose arginfo_grDisableAllEffects

#define arginfo_grSstIdle arginfo_grDisableAllEffects

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grRenderBuffer, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, buffer, GrBuffer_t, 0)
ZEND_END_ARG_INFO()

#define arginfo__kbhit arginfo_grBufferNumPending

#define arginfo_class_GrDepth_t_toInt arginfo_grBufferNumPending

#define arginfo_class_GrEvenOdd_t_toInt arginfo_grBufferNumPending

#define arginfo_class_GrChipID_t_toInt arginfo_grBufferNumPending

#define arginfo_class_GrCombineFunction_t_toInt arginfo_grBufferNumPending

#define arginfo_class_GrCombineFactor_t_toInt arginfo_grBufferNumPending

#define arginfo_class_GrCombineLocal_t_toInt arginfo_grBufferNumPending

#define arginfo_class_GrCombineOther_t_toInt arginfo_grBufferNumPending

#define arginfo_class_GrAlphaSource_t_toInt arginfo_grBufferNumPending

#define arginfo_class_GrColorCombineFnc_t_toInt arginfo_grBufferNumPending

#define arginfo_class_GrAlphaBlendFnc_t_toInt arginfo_grBufferNumPending

#define arginfo_class_GrAspectRatio_t_toInt arginfo_grBufferNumPending

#define arginfo_class_GrBuffer_t_toInt arginfo_grBufferNumPending

#define arginfo_class_GrChromakeyMode_t_toInt arginfo_grBufferNumPending

#define arginfo_class_GrCmpFnc_t_toInt arginfo_grBufferNumPending

#define arginfo_class_GrColorFormat_t_toInt arginfo_grBufferNumPending

#define arginfo_class_GrCullMode_t_toInt arginfo_grBufferNumPending

#define arginfo_class_GrDepthBufferMode_t_toInt arginfo_grBufferNumPending

#define arginfo_class_GrDitherMode_t_toInt arginfo_grBufferNumPending

#define arginfo_class_GrFogMode_t_toInt arginfo_grBufferNumPending

#define arginfo_class_GrLock_t_toInt arginfo_grBufferNumPending

#define arginfo_class_GrLfbBypassMode_t_toInt arginfo_grBufferNumPending

#define arginfo_class_GrLfbWriteMode_t_toInt arginfo_grBufferNumPending

#define arginfo_class_GrOriginLocation_t_toInt arginfo_grBufferNumPending

#define arginfo_class_GrLOD_t_toInt arginfo_grBufferNumPending

#define arginfo_class_GrMipMapMode_t_toInt arginfo_grBufferNumPending

#define arginfo_class_GrSmoothingMode_t_toInt arginfo_grBufferNumPending

#define arginfo_class_GrTextureClampMode_t_toInt arginfo_grBufferNumPending

#define arginfo_class_GrTextureCombineFnc_t_toInt arginfo_grBufferNumPending

#define arginfo_class_GrTextureFilterMode_t_toInt arginfo_grBufferNumPending

#define arginfo_class_GrTextureFormat_t_toInt arginfo_grBufferNumPending

#define arginfo_class_GrTexTable_t_toInt arginfo_grBufferNumPending

#define arginfo_class_GrNCCTable_t_toInt arginfo_grBufferNumPending

#define arginfo_class_GrTexBaseRange_t_toInt arginfo_grBufferNumPending

#define arginfo_class_GrSstType_toInt arginfo_grBufferNumPending

#define arginfo_class_GrScreenRefresh_t_toInt arginfo_grBufferNumPending

#define arginfo_class_GrScreenResolution_t_toInt arginfo_grBufferNumPending

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_flushable_flush, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GrTMUConfig_t_flush arginfo_class_flushable_flush

#define arginfo_class_GrVoodooConfig_t_flush arginfo_class_flushable_flush

#define arginfo_class_GrVoodoo2Config_t_flush arginfo_class_flushable_flush

#define arginfo_class_GrSst96Config_t_flush arginfo_class_flushable_flush

#define arginfo_class_GrAT3DConfig_t_flush arginfo_class_flushable_flush

#define arginfo_class_SST_t_flush arginfo_class_flushable_flush

#define arginfo_class_GrHwConfiguration_flush arginfo_class_flushable_flush

#define arginfo_class_GrTmuVertex_flush arginfo_class_flushable_flush

#define arginfo_class_GrVertex_flush arginfo_class_flushable_flush

#if defined(_DEBUG)
ZEND_FUNCTION(testGrTMUConfig_t);
ZEND_FUNCTION(testGrVoodooConfig_t);
ZEND_FUNCTION(testGrVoodoo2Config_t);
ZEND_FUNCTION(testGrSst96Config_t);
ZEND_FUNCTION(testGrAT3DConfig_t);
ZEND_FUNCTION(testSST_t);
ZEND_FUNCTION(testGrHwConfiguration);
ZEND_FUNCTION(testGrTmuVertex);
ZEND_FUNCTION(testGrVertex);
ZEND_FUNCTION(testObject);
#endif
ZEND_FUNCTION(grAADrawLine);
ZEND_FUNCTION(grAADrawPoint);
ZEND_FUNCTION(grAADrawPolygon);
ZEND_FUNCTION(grAADrawPolygonVertexList);
ZEND_FUNCTION(grAADrawTriangle);
ZEND_FUNCTION(grAlphaBlendFunction);
ZEND_FUNCTION(grAlphaCombine);
ZEND_FUNCTION(grAlphaControlsITRGBLighting);
ZEND_FUNCTION(grAlphaTestFunction);
ZEND_FUNCTION(grAlphaTestReferenceValue);
ZEND_FUNCTION(grBufferClear);
ZEND_FUNCTION(grBufferNumPending);
ZEND_FUNCTION(grBufferSwap);
ZEND_FUNCTION(grChromakeyMode);
ZEND_FUNCTION(grChromakeyValue);
ZEND_FUNCTION(grClipWindow);
ZEND_FUNCTION(grColorCombine);
ZEND_FUNCTION(grColorMask);
ZEND_FUNCTION(grConstantColorValue);
ZEND_FUNCTION(grCullMode);
ZEND_FUNCTION(grDepthBiasLevel);
ZEND_FUNCTION(grDepthBufferFunction);
ZEND_FUNCTION(grDepthBufferMode);
ZEND_FUNCTION(grDepthMask);
ZEND_FUNCTION(grDisableAllEffects);
ZEND_FUNCTION(grDitherMode);
ZEND_FUNCTION(grDrawLine);
ZEND_FUNCTION(grDrawPlanarPolygon);
ZEND_FUNCTION(grDrawPlanarPolygonVertexList);
ZEND_FUNCTION(grDrawPoint);
ZEND_FUNCTION(grDrawPolygon);
ZEND_FUNCTION(grDrawPolygonVertexList);
ZEND_FUNCTION(grErrorSetCallback);
ZEND_FUNCTION(grFogColorValue);
ZEND_FUNCTION(grFogMode);
ZEND_FUNCTION(grFogTable);
ZEND_FUNCTION(guFogGenerateLinear);
ZEND_FUNCTION(grGlideInit);
ZEND_FUNCTION(grGlideShutdown);
ZEND_FUNCTION(grSstQueryHardware);
ZEND_FUNCTION(grSstSelect);
ZEND_FUNCTION(grDrawTriangle);
ZEND_FUNCTION(guColorCombineFunction);
ZEND_FUNCTION(grSstWinOpen);
ZEND_FUNCTION(grSstWinClose);
ZEND_FUNCTION(grSstIdle);
ZEND_FUNCTION(grRenderBuffer);
ZEND_FUNCTION(_kbhit);
ZEND_METHOD(GrDepth_t, toInt);
ZEND_METHOD(GrEvenOdd_t, toInt);
ZEND_METHOD(GrChipID_t, toInt);
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
ZEND_METHOD(GrSstType, toInt);
ZEND_METHOD(GrScreenRefresh_t, toInt);
ZEND_METHOD(GrScreenResolution_t, toInt);
ZEND_METHOD(GrTMUConfig_t, flush);
ZEND_METHOD(GrVoodooConfig_t, flush);
ZEND_METHOD(GrVoodoo2Config_t, flush);
ZEND_METHOD(GrSst96Config_t, flush);
ZEND_METHOD(GrAT3DConfig_t, flush);
ZEND_METHOD(SST_t, flush);
ZEND_METHOD(GrHwConfiguration, flush);
ZEND_METHOD(GrTmuVertex, flush);
ZEND_METHOD(GrVertex, flush);

static const zend_function_entry ext_functions[] = {
#if defined(_DEBUG)
	ZEND_FE(testGrTMUConfig_t, arginfo_testGrTMUConfig_t)
	ZEND_FE(testGrVoodooConfig_t, arginfo_testGrVoodooConfig_t)
	ZEND_FE(testGrVoodoo2Config_t, arginfo_testGrVoodoo2Config_t)
	ZEND_FE(testGrSst96Config_t, arginfo_testGrSst96Config_t)
	ZEND_FE(testGrAT3DConfig_t, arginfo_testGrAT3DConfig_t)
	ZEND_FE(testSST_t, arginfo_testSST_t)
	ZEND_FE(testGrHwConfiguration, arginfo_testGrHwConfiguration)
	ZEND_FE(testGrTmuVertex, arginfo_testGrTmuVertex)
	ZEND_FE(testGrVertex, arginfo_testGrVertex)
	ZEND_FE(testObject, arginfo_testObject)
#endif
	ZEND_FE(grAADrawLine, arginfo_grAADrawLine)
	ZEND_FE(grAADrawPoint, arginfo_grAADrawPoint)
	ZEND_FE(grAADrawPolygon, arginfo_grAADrawPolygon)
	ZEND_FE(grAADrawPolygonVertexList, arginfo_grAADrawPolygonVertexList)
	ZEND_FE(grAADrawTriangle, arginfo_grAADrawTriangle)
	ZEND_FE(grAlphaBlendFunction, arginfo_grAlphaBlendFunction)
	ZEND_FE(grAlphaCombine, arginfo_grAlphaCombine)
	ZEND_FE(grAlphaControlsITRGBLighting, arginfo_grAlphaControlsITRGBLighting)
	ZEND_FE(grAlphaTestFunction, arginfo_grAlphaTestFunction)
	ZEND_FE(grAlphaTestReferenceValue, arginfo_grAlphaTestReferenceValue)
	ZEND_FE(grBufferClear, arginfo_grBufferClear)
	ZEND_FE(grBufferNumPending, arginfo_grBufferNumPending)
	ZEND_FE(grBufferSwap, arginfo_grBufferSwap)
	ZEND_FE(grChromakeyMode, arginfo_grChromakeyMode)
	ZEND_FE(grChromakeyValue, arginfo_grChromakeyValue)
	ZEND_FE(grClipWindow, arginfo_grClipWindow)
	ZEND_FE(grColorCombine, arginfo_grColorCombine)
	ZEND_FE(grColorMask, arginfo_grColorMask)
	ZEND_FE(grConstantColorValue, arginfo_grConstantColorValue)
	ZEND_FE(grCullMode, arginfo_grCullMode)
	ZEND_FE(grDepthBiasLevel, arginfo_grDepthBiasLevel)
	ZEND_FE(grDepthBufferFunction, arginfo_grDepthBufferFunction)
	ZEND_FE(grDepthBufferMode, arginfo_grDepthBufferMode)
	ZEND_FE(grDepthMask, arginfo_grDepthMask)
	ZEND_FE(grDisableAllEffects, arginfo_grDisableAllEffects)
	ZEND_FE(grDitherMode, arginfo_grDitherMode)
	ZEND_FE(grDrawLine, arginfo_grDrawLine)
	ZEND_FE(grDrawPlanarPolygon, arginfo_grDrawPlanarPolygon)
	ZEND_FE(grDrawPlanarPolygonVertexList, arginfo_grDrawPlanarPolygonVertexList)
	ZEND_FE(grDrawPoint, arginfo_grDrawPoint)
	ZEND_FE(grDrawPolygon, arginfo_grDrawPolygon)
	ZEND_FE(grDrawPolygonVertexList, arginfo_grDrawPolygonVertexList)
	ZEND_FE(grErrorSetCallback, arginfo_grErrorSetCallback)
	ZEND_FE(grFogColorValue, arginfo_grFogColorValue)
	ZEND_FE(grFogMode, arginfo_grFogMode)
	ZEND_FE(grFogTable, arginfo_grFogTable)
	ZEND_FE(guFogGenerateLinear, arginfo_guFogGenerateLinear)
	ZEND_FE(grGlideInit, arginfo_grGlideInit)
	ZEND_FE(grGlideShutdown, arginfo_grGlideShutdown)
	ZEND_FE(grSstQueryHardware, arginfo_grSstQueryHardware)
	ZEND_FE(grSstSelect, arginfo_grSstSelect)
	ZEND_FE(grDrawTriangle, arginfo_grDrawTriangle)
	ZEND_FE(guColorCombineFunction, arginfo_guColorCombineFunction)
	ZEND_FE(grSstWinOpen, arginfo_grSstWinOpen)
	ZEND_FE(grSstWinClose, arginfo_grSstWinClose)
	ZEND_FE(grSstIdle, arginfo_grSstIdle)
	ZEND_FE(grRenderBuffer, arginfo_grRenderBuffer)
	ZEND_FE(_kbhit, arginfo__kbhit)
	ZEND_FE_END
};

static const zend_function_entry class_GrDepth_t_methods[] = {
	ZEND_ME(GrDepth_t, toInt, arginfo_class_GrDepth_t_toInt, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrEvenOdd_t_methods[] = {
	ZEND_ME(GrEvenOdd_t, toInt, arginfo_class_GrEvenOdd_t_toInt, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrChipID_t_methods[] = {
	ZEND_ME(GrChipID_t, toInt, arginfo_class_GrChipID_t_toInt, ZEND_ACC_PUBLIC)
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

static const zend_function_entry class_GrSstType_methods[] = {
	ZEND_ME(GrSstType, toInt, arginfo_class_GrSstType_toInt, ZEND_ACC_PUBLIC)
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

static const zend_function_entry class_flushable_methods[] = {
	ZEND_RAW_FENTRY("flush", NULL, arginfo_class_flushable_flush, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_FE_END
};

static const zend_function_entry class_GrTMUConfig_t_methods[] = {
	ZEND_ME(GrTMUConfig_t, flush, arginfo_class_GrTMUConfig_t_flush, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrVoodooConfig_t_methods[] = {
	ZEND_ME(GrVoodooConfig_t, flush, arginfo_class_GrVoodooConfig_t_flush, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrVoodoo2Config_t_methods[] = {
	ZEND_ME(GrVoodoo2Config_t, flush, arginfo_class_GrVoodoo2Config_t_flush, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrSst96Config_t_methods[] = {
	ZEND_ME(GrSst96Config_t, flush, arginfo_class_GrSst96Config_t_flush, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrAT3DConfig_t_methods[] = {
	ZEND_ME(GrAT3DConfig_t, flush, arginfo_class_GrAT3DConfig_t_flush, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_SST_t_methods[] = {
	ZEND_ME(SST_t, flush, arginfo_class_SST_t_flush, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrHwConfiguration_methods[] = {
	ZEND_ME(GrHwConfiguration, flush, arginfo_class_GrHwConfiguration_flush, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrTmuVertex_methods[] = {
	ZEND_ME(GrTmuVertex, flush, arginfo_class_GrTmuVertex_flush, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrVertex_methods[] = {
	ZEND_ME(GrVertex, flush, arginfo_class_GrVertex_flush, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static void register_phpglide2x_symbols(int module_number)
{
	REGISTER_LONG_CONSTANT("MAX_NUM_SST", MAX_NUM_SST, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("MAX_MIPMAPS_PER_SST", MAX_MIPMAPS_PER_SST, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("GR_FOG_TABLE_SIZE", GR_FOG_TABLE_SIZE, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("GR_NULL_MIPMAP_HANDLE", GR_NULL_MIPMAP_HANDLE, CONST_PERSISTENT);
	REGISTER_DOUBLE_CONSTANT("GR_LODBIAS_BILINEAR", GR_LODBIAS_BILINEAR, CONST_PERSISTENT);
	REGISTER_DOUBLE_CONSTANT("GR_LODBIAS_TRILINEAR", GR_LODBIAS_TRILINEAR, CONST_PERSISTENT);
}

static zend_class_entry *register_class_GrDepth_t(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GrDepth_t", IS_UNDEF, class_GrDepth_t_methods);

	zend_enum_add_case_cstr(class_entry, "GR_ZDEPTHVALUE_NEAREST", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_ZDEPTHVALUE_FARTHEST", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_WDEPTHVALUE_NEAREST", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_WDEPTHVALUE_FARTHEST", NULL);

	return class_entry;
}

static zend_class_entry *register_class_GrEvenOdd_t(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GrEvenOdd_t", IS_UNDEF, class_GrEvenOdd_t_methods);

	zend_enum_add_case_cstr(class_entry, "GR_MIPMAPLEVELMASK_EVEN", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_MIPMAPLEVELMASK_ODD", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_MIPMAPLEVELMASK_BOTH", NULL);

	return class_entry;
}

static zend_class_entry *register_class_GrChipID_t(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GrChipID_t", IS_UNDEF, class_GrChipID_t_methods);

	zend_enum_add_case_cstr(class_entry, "GR_TMU0", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_TMU1", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_TMU2", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_FBI", NULL);

	return class_entry;
}

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

	zend_enum_add_case_cstr(class_entry, "GR_ASPECT_8x1", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_ASPECT_4x1", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_ASPECT_2x1", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_ASPECT_1x1", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_ASPECT_1x2", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_ASPECT_1x4", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_ASPECT_1x8", NULL);

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

	zend_enum_add_case_cstr(class_entry, "GR_FOG_WITH_ITERATED_ALPHA", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_FOG_WITH_TABLE", NULL);

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

	zend_enum_add_case_cstr(class_entry, "GR_LOD_256", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_LOD_128", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_LOD_64", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_LOD_32", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_LOD_16", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_LOD_8", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_LOD_4", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_LOD_2", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_LOD_1", NULL);

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

static zend_class_entry *register_class_GrSstType(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GrSstType", IS_UNDEF, class_GrSstType_methods);

	zend_enum_add_case_cstr(class_entry, "GR_SSTTYPE_VOODOO", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_SSTTYPE_SST96", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_SSTTYPE_AT3D", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_SSTTYPE_Voodoo2", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_SSTTYPE_Banshee", NULL);

	zend_enum_add_case_cstr(class_entry, "GR_SSTTYPE_Unknown", NULL);

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

static zend_class_entry *register_class_flushable(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "flushable", class_flushable_methods);
	class_entry = zend_register_internal_interface(&ce);

	return class_entry;
}

static zend_class_entry *register_class_GrTMUConfig_t(zend_class_entry *class_entry_flushable)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GrTMUConfig_t", class_GrTMUConfig_t_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);
	zend_class_implements(class_entry, 1, class_entry_flushable);

	zval property_tmuRev_default_value;
	ZVAL_UNDEF(&property_tmuRev_default_value);
	zend_string *property_tmuRev_name = zend_string_init("tmuRev", sizeof("tmuRev") - 1, 1);
	zend_declare_typed_property(class_entry, property_tmuRev_name, &property_tmuRev_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_tmuRev_name);

	zval property_tmuRam_default_value;
	ZVAL_UNDEF(&property_tmuRam_default_value);
	zend_string *property_tmuRam_name = zend_string_init("tmuRam", sizeof("tmuRam") - 1, 1);
	zend_declare_typed_property(class_entry, property_tmuRam_name, &property_tmuRam_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_tmuRam_name);

	return class_entry;
}

static zend_class_entry *register_class_GrVoodooConfig_t(zend_class_entry *class_entry_flushable)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GrVoodooConfig_t", class_GrVoodooConfig_t_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);
	zend_class_implements(class_entry, 1, class_entry_flushable);

	zval property_fbRam_default_value;
	ZVAL_UNDEF(&property_fbRam_default_value);
	zend_string *property_fbRam_name = zend_string_init("fbRam", sizeof("fbRam") - 1, 1);
	zend_declare_typed_property(class_entry, property_fbRam_name, &property_fbRam_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_fbRam_name);

	zval property_fbiRev_default_value;
	ZVAL_UNDEF(&property_fbiRev_default_value);
	zend_string *property_fbiRev_name = zend_string_init("fbiRev", sizeof("fbiRev") - 1, 1);
	zend_declare_typed_property(class_entry, property_fbiRev_name, &property_fbiRev_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_fbiRev_name);

	zval property_nTexelfx_default_value;
	ZVAL_UNDEF(&property_nTexelfx_default_value);
	zend_string *property_nTexelfx_name = zend_string_init("nTexelfx", sizeof("nTexelfx") - 1, 1);
	zend_declare_typed_property(class_entry, property_nTexelfx_name, &property_nTexelfx_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_nTexelfx_name);

	zval property_sliDetect_default_value;
	ZVAL_FALSE(&property_sliDetect_default_value);
	zend_string *property_sliDetect_name = zend_string_init("sliDetect", sizeof("sliDetect") - 1, 1);
	zend_declare_typed_property(class_entry, property_sliDetect_name, &property_sliDetect_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_sliDetect_name);

	zval property_tmuConfig_default_value;
	ZVAL_UNDEF(&property_tmuConfig_default_value);
	zend_string *property_tmuConfig_name = zend_string_init("tmuConfig", sizeof("tmuConfig") - 1, 1);
	zend_declare_typed_property(class_entry, property_tmuConfig_name, &property_tmuConfig_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_tmuConfig_name);

	return class_entry;
}

static zend_class_entry *register_class_GrVoodoo2Config_t(zend_class_entry *class_entry_flushable)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GrVoodoo2Config_t", class_GrVoodoo2Config_t_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);
	zend_class_implements(class_entry, 1, class_entry_flushable);

	zval property_fbRam_default_value;
	ZVAL_UNDEF(&property_fbRam_default_value);
	zend_string *property_fbRam_name = zend_string_init("fbRam", sizeof("fbRam") - 1, 1);
	zend_declare_typed_property(class_entry, property_fbRam_name, &property_fbRam_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_fbRam_name);

	zval property_fbiRev_default_value;
	ZVAL_UNDEF(&property_fbiRev_default_value);
	zend_string *property_fbiRev_name = zend_string_init("fbiRev", sizeof("fbiRev") - 1, 1);
	zend_declare_typed_property(class_entry, property_fbiRev_name, &property_fbiRev_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_fbiRev_name);

	zval property_nTexelfx_default_value;
	ZVAL_UNDEF(&property_nTexelfx_default_value);
	zend_string *property_nTexelfx_name = zend_string_init("nTexelfx", sizeof("nTexelfx") - 1, 1);
	zend_declare_typed_property(class_entry, property_nTexelfx_name, &property_nTexelfx_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_nTexelfx_name);

	zval property_sliDetect_default_value;
	ZVAL_FALSE(&property_sliDetect_default_value);
	zend_string *property_sliDetect_name = zend_string_init("sliDetect", sizeof("sliDetect") - 1, 1);
	zend_declare_typed_property(class_entry, property_sliDetect_name, &property_sliDetect_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_BOOL));
	zend_string_release(property_sliDetect_name);

	zval property_tmuConfig_default_value;
	ZVAL_UNDEF(&property_tmuConfig_default_value);
	zend_string *property_tmuConfig_name = zend_string_init("tmuConfig", sizeof("tmuConfig") - 1, 1);
	zend_declare_typed_property(class_entry, property_tmuConfig_name, &property_tmuConfig_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_tmuConfig_name);

	return class_entry;
}

static zend_class_entry *register_class_GrSst96Config_t(zend_class_entry *class_entry_flushable)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GrSst96Config_t", class_GrSst96Config_t_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);
	zend_class_implements(class_entry, 1, class_entry_flushable);

	zval property_fbRam_default_value;
	ZVAL_UNDEF(&property_fbRam_default_value);
	zend_string *property_fbRam_name = zend_string_init("fbRam", sizeof("fbRam") - 1, 1);
	zend_declare_typed_property(class_entry, property_fbRam_name, &property_fbRam_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_fbRam_name);

	zval property_nTexelfx_default_value;
	ZVAL_UNDEF(&property_nTexelfx_default_value);
	zend_string *property_nTexelfx_name = zend_string_init("nTexelfx", sizeof("nTexelfx") - 1, 1);
	zend_declare_typed_property(class_entry, property_nTexelfx_name, &property_nTexelfx_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_nTexelfx_name);

	zval property_tmuConfig_default_value;
	ZVAL_UNDEF(&property_tmuConfig_default_value);
	zend_string *property_tmuConfig_name = zend_string_init("tmuConfig", sizeof("tmuConfig") - 1, 1);
	zend_string *property_tmuConfig_class_GrTMUConfig_t = zend_string_init("GrTMUConfig_t", sizeof("GrTMUConfig_t")-1, 1);
	zend_declare_typed_property(class_entry, property_tmuConfig_name, &property_tmuConfig_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_tmuConfig_class_GrTMUConfig_t, 0, 0));
	zend_string_release(property_tmuConfig_name);

	return class_entry;
}

static zend_class_entry *register_class_GrAT3DConfig_t(zend_class_entry *class_entry_flushable)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GrAT3DConfig_t", class_GrAT3DConfig_t_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);
	zend_class_implements(class_entry, 1, class_entry_flushable);

	zval property_rev_default_value;
	ZVAL_UNDEF(&property_rev_default_value);
	zend_string *property_rev_name = zend_string_init("rev", sizeof("rev") - 1, 1);
	zend_declare_typed_property(class_entry, property_rev_name, &property_rev_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_rev_name);

	return class_entry;
}

static zend_class_entry *register_class_SST_t(zend_class_entry *class_entry_flushable)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "SST_t", class_SST_t_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);
	zend_class_implements(class_entry, 1, class_entry_flushable);

	zval property_type_default_value;
	ZVAL_UNDEF(&property_type_default_value);
	zend_string *property_type_class_GrSstType = zend_string_init("GrSstType", sizeof("GrSstType")-1, 1);
	zend_declare_typed_property(class_entry, ZSTR_KNOWN(ZEND_STR_TYPE), &property_type_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_type_class_GrSstType, 0, MAY_BE_NULL));

	zval property_sstBoard_default_value;
	ZVAL_UNDEF(&property_sstBoard_default_value);
	zend_string *property_sstBoard_name = zend_string_init("sstBoard", sizeof("sstBoard") - 1, 1);
	zend_string *property_sstBoard_class_GrVoodooConfig_t = zend_string_init("GrVoodooConfig_t", sizeof("GrVoodooConfig_t") - 1, 1);
	zend_string *property_sstBoard_class_GrSst96Config_t = zend_string_init("GrSst96Config_t", sizeof("GrSst96Config_t") - 1, 1);
	zend_string *property_sstBoard_class_GrAT3DConfig_t = zend_string_init("GrAT3DConfig_t", sizeof("GrAT3DConfig_t") - 1, 1);
	zend_string *property_sstBoard_class_GrVoodoo2Config_t = zend_string_init("GrVoodoo2Config_t", sizeof("GrVoodoo2Config_t") - 1, 1);
	zend_type_list *property_sstBoard_type_list = malloc(ZEND_TYPE_LIST_SIZE(4));
	property_sstBoard_type_list->num_types = 4;
	property_sstBoard_type_list->types[0] = (zend_type) ZEND_TYPE_INIT_CLASS(property_sstBoard_class_GrVoodooConfig_t, 0, 0);
	property_sstBoard_type_list->types[1] = (zend_type) ZEND_TYPE_INIT_CLASS(property_sstBoard_class_GrSst96Config_t, 0, 0);
	property_sstBoard_type_list->types[2] = (zend_type) ZEND_TYPE_INIT_CLASS(property_sstBoard_class_GrAT3DConfig_t, 0, 0);
	property_sstBoard_type_list->types[3] = (zend_type) ZEND_TYPE_INIT_CLASS(property_sstBoard_class_GrVoodoo2Config_t, 0, 0);
	zend_type property_sstBoard_type = ZEND_TYPE_INIT_UNION(property_sstBoard_type_list, MAY_BE_NULL);
	zend_declare_typed_property(class_entry, property_sstBoard_name, &property_sstBoard_default_value, ZEND_ACC_PUBLIC, NULL, property_sstBoard_type);
	zend_string_release(property_sstBoard_name);

	return class_entry;
}

static zend_class_entry *register_class_GrHwConfiguration(zend_class_entry *class_entry_flushable)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GrHwConfiguration", class_GrHwConfiguration_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);
	zend_class_implements(class_entry, 1, class_entry_flushable);

	zval property_num_sst_default_value;
	ZVAL_UNDEF(&property_num_sst_default_value);
	zend_string *property_num_sst_name = zend_string_init("num_sst", sizeof("num_sst") - 1, 1);
	zend_declare_typed_property(class_entry, property_num_sst_name, &property_num_sst_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_num_sst_name);

	zval property_SSTs_default_value;
	ZVAL_UNDEF(&property_SSTs_default_value);
	zend_string *property_SSTs_name = zend_string_init("SSTs", sizeof("SSTs") - 1, 1);
	zend_declare_typed_property(class_entry, property_SSTs_name, &property_SSTs_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_SSTs_name);

	return class_entry;
}

static zend_class_entry *register_class_GrTmuVertex(zend_class_entry *class_entry_flushable)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GrTmuVertex", class_GrTmuVertex_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);
	zend_class_implements(class_entry, 1, class_entry_flushable);

	zval property_sow_default_value;
	ZVAL_UNDEF(&property_sow_default_value);
	zend_string *property_sow_name = zend_string_init("sow", sizeof("sow") - 1, 1);
	zend_declare_typed_property(class_entry, property_sow_name, &property_sow_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_sow_name);

	zval property_tow_default_value;
	ZVAL_UNDEF(&property_tow_default_value);
	zend_string *property_tow_name = zend_string_init("tow", sizeof("tow") - 1, 1);
	zend_declare_typed_property(class_entry, property_tow_name, &property_tow_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_tow_name);

	zval property_oow_default_value;
	ZVAL_UNDEF(&property_oow_default_value);
	zend_string *property_oow_name = zend_string_init("oow", sizeof("oow") - 1, 1);
	zend_declare_typed_property(class_entry, property_oow_name, &property_oow_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_oow_name);

	return class_entry;
}

static zend_class_entry *register_class_GrVertex(zend_class_entry *class_entry_flushable)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GrVertex", class_GrVertex_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);
	zend_class_implements(class_entry, 1, class_entry_flushable);

	zval property_x_default_value;
	ZVAL_UNDEF(&property_x_default_value);
	zend_string *property_x_name = zend_string_init("x", sizeof("x") - 1, 1);
	zend_declare_typed_property(class_entry, property_x_name, &property_x_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_x_name);

	zval property_y_default_value;
	ZVAL_UNDEF(&property_y_default_value);
	zend_string *property_y_name = zend_string_init("y", sizeof("y") - 1, 1);
	zend_declare_typed_property(class_entry, property_y_name, &property_y_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_y_name);

	zval property_z_default_value;
	ZVAL_UNDEF(&property_z_default_value);
	zend_string *property_z_name = zend_string_init("z", sizeof("z") - 1, 1);
	zend_declare_typed_property(class_entry, property_z_name, &property_z_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_z_name);

	zval property_r_default_value;
	ZVAL_UNDEF(&property_r_default_value);
	zend_string *property_r_name = zend_string_init("r", sizeof("r") - 1, 1);
	zend_declare_typed_property(class_entry, property_r_name, &property_r_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_r_name);

	zval property_g_default_value;
	ZVAL_UNDEF(&property_g_default_value);
	zend_string *property_g_name = zend_string_init("g", sizeof("g") - 1, 1);
	zend_declare_typed_property(class_entry, property_g_name, &property_g_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_g_name);

	zval property_b_default_value;
	ZVAL_UNDEF(&property_b_default_value);
	zend_string *property_b_name = zend_string_init("b", sizeof("b") - 1, 1);
	zend_declare_typed_property(class_entry, property_b_name, &property_b_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_b_name);

	zval property_ooz_default_value;
	ZVAL_UNDEF(&property_ooz_default_value);
	zend_string *property_ooz_name = zend_string_init("ooz", sizeof("ooz") - 1, 1);
	zend_declare_typed_property(class_entry, property_ooz_name, &property_ooz_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_ooz_name);

	zval property_a_default_value;
	ZVAL_UNDEF(&property_a_default_value);
	zend_string *property_a_name = zend_string_init("a", sizeof("a") - 1, 1);
	zend_declare_typed_property(class_entry, property_a_name, &property_a_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_a_name);

	zval property_oow_default_value;
	ZVAL_UNDEF(&property_oow_default_value);
	zend_string *property_oow_name = zend_string_init("oow", sizeof("oow") - 1, 1);
	zend_declare_typed_property(class_entry, property_oow_name, &property_oow_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_oow_name);

	zval property_tmuvtx_default_value;
	ZVAL_UNDEF(&property_tmuvtx_default_value);
	zend_string *property_tmuvtx_name = zend_string_init("tmuvtx", sizeof("tmuvtx") - 1, 1);
	zend_declare_typed_property(class_entry, property_tmuvtx_name, &property_tmuvtx_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY));
	zend_string_release(property_tmuvtx_name);

	return class_entry;
}
