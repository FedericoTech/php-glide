#ifndef ENUMS_H
#define ENUMS_H

#include "stdafx.h"


extern zend_class_entry* grAlphaBlendFnc_ce;
extern zend_class_entry* grAlphaSource_ce;
extern zend_class_entry* grAspectRatio_ce;

extern zend_class_entry* grBuffer_ce;

extern zend_class_entry* grChipID_ce;
extern zend_class_entry* grChromakeyMode_ce;
extern zend_class_entry* grCmpFnc_ce;
extern zend_class_entry* grColorCombineFnc_ce;
extern zend_class_entry* grColorFormat_ce;
extern zend_class_entry* grCombineFunction_ce;
extern zend_class_entry* grCombineFactor_ce;
extern zend_class_entry* grCombineLocal_ce;
extern zend_class_entry* grCombineOther_ce;

extern zend_class_entry* grCullMode_ce;

extern zend_class_entry* grDepth_ce;
extern zend_class_entry* grDepthBufferMode_ce;
extern zend_class_entry* grDitherMode_ce;

extern zend_class_entry* grEvenOdd_ce;

extern zend_class_entry* grFogMode_ce;

extern zend_class_entry* grHints_ce;

extern zend_class_entry* grLfbBypassMode_ce;
extern zend_class_entry* grLfbWriteMode_ce;
extern zend_class_entry* grLock_ce;
extern zend_class_entry* grLOD_ce;

extern zend_class_entry* grMipMapMode_ce;
extern zend_class_entry* grNCCTable_ce;
extern zend_class_entry* grOriginLocation_ce;

extern zend_class_entry* grScreenRefresh_ce;
extern zend_class_entry* grScreenResolution_ce;
extern zend_class_entry* grSmoothingMode_ce;
extern zend_class_entry* grSstType_ce;

extern zend_class_entry* grTexBaseRange_ce;
extern zend_class_entry* grTexTable_ce;
extern zend_class_entry* grTextureClampMode_ce;
extern zend_class_entry* grTextureCombineFnc_ce;
extern zend_class_entry* grTextureFilterMode_ce;
extern zend_class_entry* grTextureFormat_ce;

int enum_to_int(zend_object* enum_obj);


void phpglide2x_register_enums(INIT_FUNC_ARGS);

#endif
