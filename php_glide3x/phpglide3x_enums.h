#ifndef ENUMS_H
#define ENUMS_H

#include "stdafx.h"

extern zend_class_entry* grCombineFunction_ce;
extern zend_class_entry* grCombineFactor_ce;
extern zend_class_entry* grCombineLocal_ce;
extern zend_class_entry* grCombineOther_ce;
extern zend_class_entry* grAlphaSource_ce;
extern zend_class_entry* grColorCombineFnc_ce;
extern zend_class_entry* grAlphaBlendFnc_ce;
extern zend_class_entry* grAspectRatio_ce;
extern zend_class_entry* grBuffer_ce;
extern zend_class_entry* grChromakeyMode_ce;
extern zend_class_entry* grChromaRangeMode_ce;
extern zend_class_entry* grTexChromakeyMode_ce;
extern zend_class_entry* grCmpFnc_ce;
extern zend_class_entry* grColorFormat_ce;
extern zend_class_entry* grCullMode_ce;
extern zend_class_entry* grDepthBufferMode_ce;
extern zend_class_entry* grDitherMode_ce;
extern zend_class_entry* grFogMode_ce;
extern zend_class_entry* grLock_ce;
extern zend_class_entry* grLfbBypassMode_ce;
extern zend_class_entry* grLfbWriteMode_ce;
extern zend_class_entry* grOriginLocation_ce;
extern zend_class_entry* grLOD_ce;
extern zend_class_entry* grMipMapMode_ce;
extern zend_class_entry* grSmoothingMode_ce;
extern zend_class_entry* grTextureClampMode_ce;
extern zend_class_entry* grTextureCombineFnc_ce;
extern zend_class_entry* grTextureFilterMode_ce;
extern zend_class_entry* grTextureFormat_ce;
extern zend_class_entry* grTexTable_ce;
extern zend_class_entry* grNCCTable_ce;
extern zend_class_entry* grTexBaseRange_ce;
extern zend_class_entry* grEnableMode_ce;
extern zend_class_entry* grCoordinateSpaceMode_ce;
extern zend_class_entry* grDataStrips_ce;
extern zend_class_entry* grParams_ce;
extern zend_class_entry* grMode_ce;
extern zend_class_entry* grVertex_ce;
extern zend_class_entry* grGet_ce;
extern zend_class_entry* grString_ce;
extern zend_class_entry* grScreenRefresh_ce;
extern zend_class_entry* grScreenResolution_ce;

int enum_to_int(zend_object* enum_obj);

void phpglide3x_register_enums(INIT_FUNC_ARGS);

#endif
