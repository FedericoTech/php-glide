#include "phpglide2x_enums.h"

#include <Zend/zend_enum.h>

#include <glide.h>

#define CREATE_CONSTANT(v) REGISTER_LONG_CONSTANT(#v, v, CONST_CS | CONST_PERSISTENT)

#define SET_PROPERTY(ce, v) \
	ZVAL_LONG(&case_value, v); \
	zend_enum_add_case_cstr(ce, #v, &case_value);


zend_class_entry* grDepth_ce;
zend_class_entry* grEvenOdd_ce;

zend_class_entry* grChipID_ce;
zend_class_entry* grCombineFunction_ce;
zend_class_entry* grCombineFactor_ce;
zend_class_entry* grCombineLocal_ce;
zend_class_entry* grCombineOther_ce;
zend_class_entry* grAlphaSource_ce;
zend_class_entry* grColorCombineFnc_ce;
zend_class_entry* grAlphaBlendFnc_ce;
zend_class_entry* grAspectRatio_ce;
zend_class_entry* grBuffer_ce;
zend_class_entry* grChromakeyMode_ce;
zend_class_entry* grCmpFnc_ce;
zend_class_entry* grColorFormat_ce;
zend_class_entry* grCullMode_ce;
zend_class_entry* grDepthBufferMode_ce;
zend_class_entry* grDitherMode_ce;
zend_class_entry* grFogMode_ce;
zend_class_entry* grLock_ce;
zend_class_entry* grLfbBypassMode_ce;
zend_class_entry* grLfbWriteMode_ce;

zend_class_entry* grOriginLocation_ce;

zend_class_entry* grLOD_ce;
zend_class_entry* grMipMapMode_ce;
zend_class_entry* grSmoothingMode_ce;
zend_class_entry* grTextureClampMode_ce;
zend_class_entry* grTextureCombineFnc_ce;
zend_class_entry* grTextureFilterMode_ce;
zend_class_entry* grTextureFormat_ce;
zend_class_entry* grTexTable_ce;
zend_class_entry* grNCCTable_ce;
zend_class_entry* grTexBaseRange_ce;

zend_class_entry* grSstType_ce;

zend_class_entry* grScreenRefresh_ce;
zend_class_entry* grScreenResolution_ce;


void phpglide2x_register_enums(INIT_FUNC_ARGS)
{
	zval case_value;

	CREATE_CONSTANT(MAX_NUM_SST);
	CREATE_CONSTANT(MAX_MIPMAPS_PER_SST);
	
	CREATE_CONSTANT(GR_FOG_TABLE_SIZE);
	
	CREATE_CONSTANT(GR_NULL_MIPMAP_HANDLE);
	
	grDepth_ce = zend_register_internal_enum("GrDepth_t", IS_LONG, NULL);
	SET_PROPERTY(grDepth_ce, GR_ZDEPTHVALUE_NEAREST);
	SET_PROPERTY(grDepth_ce, GR_ZDEPTHVALUE_FARTHEST);
	SET_PROPERTY(grDepth_ce, GR_WDEPTHVALUE_NEAREST);
	SET_PROPERTY(grDepth_ce, GR_WDEPTHVALUE_FARTHEST);

	grEvenOdd_ce = zend_register_internal_enum("GrEvenOdd_t", IS_LONG, NULL);
	SET_PROPERTY(grEvenOdd_ce, GR_MIPMAPLEVELMASK_EVEN);
	SET_PROPERTY(grEvenOdd_ce, GR_MIPMAPLEVELMASK_ODD);
	SET_PROPERTY(grEvenOdd_ce, GR_MIPMAPLEVELMASK_BOTH);
		
	REGISTER_DOUBLE_CONSTANT("GR_LODBIAS_BILINEAR", GR_LODBIAS_BILINEAR, CONST_CS | CONST_PERSISTENT); // because they are double
	REGISTER_DOUBLE_CONSTANT("GR_LODBIAS_TRILINEAR", GR_LODBIAS_TRILINEAR, CONST_CS | CONST_PERSISTENT); // because they are double

	//typedef FxI32 GrChipID_ce;
	grChipID_ce = zend_register_internal_enum("GrChipID_t", IS_LONG, NULL);
	SET_PROPERTY(grChipID_ce, GR_TMU0);
	SET_PROPERTY(grChipID_ce, GR_TMU1);
	SET_PROPERTY(grChipID_ce, GR_TMU2);
	SET_PROPERTY(grChipID_ce, GR_FBI);

	//typedef FxI32 GrCombineFunction_ce;
	grCombineFunction_ce = zend_register_internal_enum("GrCombineFunction_t", IS_LONG, NULL);
	SET_PROPERTY(grCombineFunction_ce, GR_COMBINE_FUNCTION_ZERO);
	SET_PROPERTY(grCombineFunction_ce, GR_COMBINE_FUNCTION_NONE);
	SET_PROPERTY(grCombineFunction_ce, GR_COMBINE_FUNCTION_LOCAL);
	SET_PROPERTY(grCombineFunction_ce, GR_COMBINE_FUNCTION_LOCAL_ALPHA);
	SET_PROPERTY(grCombineFunction_ce, GR_COMBINE_FUNCTION_SCALE_OTHER);
	SET_PROPERTY(grCombineFunction_ce, GR_COMBINE_FUNCTION_BLEND_OTHER);
	SET_PROPERTY(grCombineFunction_ce, GR_COMBINE_FUNCTION_SCALE_OTHER_ADD_LOCAL);
	SET_PROPERTY(grCombineFunction_ce, GR_COMBINE_FUNCTION_SCALE_OTHER_ADD_LOCAL_ALPHA);
	SET_PROPERTY(grCombineFunction_ce, GR_COMBINE_FUNCTION_SCALE_OTHER_MINUS_LOCAL);
	SET_PROPERTY(grCombineFunction_ce, GR_COMBINE_FUNCTION_SCALE_OTHER_MINUS_LOCAL_ADD_LOCAL);
	SET_PROPERTY(grCombineFunction_ce, GR_COMBINE_FUNCTION_BLEND);
	SET_PROPERTY(grCombineFunction_ce, GR_COMBINE_FUNCTION_SCALE_OTHER_MINUS_LOCAL_ADD_LOCAL_ALPHA);
	SET_PROPERTY(grCombineFunction_ce, GR_COMBINE_FUNCTION_SCALE_MINUS_LOCAL_ADD_LOCAL);
	SET_PROPERTY(grCombineFunction_ce, GR_COMBINE_FUNCTION_BLEND_LOCAL);
	SET_PROPERTY(grCombineFunction_ce, GR_COMBINE_FUNCTION_SCALE_MINUS_LOCAL_ADD_LOCAL_ALPHA);

	//typedef FxI32 GrCombineFactor_ce;
	grCombineFactor_ce = zend_register_internal_enum("GrCombineFactor_t", IS_LONG, NULL);
	SET_PROPERTY(grCombineFactor_ce, GR_COMBINE_FUNCTION_ZERO);
	SET_PROPERTY(grCombineFactor_ce, GR_COMBINE_FACTOR_NONE);
	SET_PROPERTY(grCombineFactor_ce, GR_COMBINE_FACTOR_LOCAL);
	SET_PROPERTY(grCombineFactor_ce, GR_COMBINE_FACTOR_OTHER_ALPHA);
	SET_PROPERTY(grCombineFactor_ce, GR_COMBINE_FACTOR_LOCAL_ALPHA);
	SET_PROPERTY(grCombineFactor_ce, GR_COMBINE_FACTOR_TEXTURE_ALPHA);
	SET_PROPERTY(grCombineFactor_ce, GR_COMBINE_FACTOR_TEXTURE_RGB);
	SET_PROPERTY(grCombineFactor_ce, GR_COMBINE_FACTOR_DETAIL_FACTOR);
	SET_PROPERTY(grCombineFactor_ce, GR_COMBINE_FACTOR_LOD_FRACTION);
	SET_PROPERTY(grCombineFactor_ce, GR_COMBINE_FACTOR_ONE);
	SET_PROPERTY(grCombineFactor_ce, GR_COMBINE_FACTOR_ONE_MINUS_LOCAL);
	SET_PROPERTY(grCombineFactor_ce, GR_COMBINE_FACTOR_ONE_MINUS_OTHER_ALPHA);
	SET_PROPERTY(grCombineFactor_ce, GR_COMBINE_FACTOR_ONE_MINUS_LOCAL_ALPHA);
	SET_PROPERTY(grCombineFactor_ce, GR_COMBINE_FACTOR_ONE_MINUS_TEXTURE_ALPHA);
	SET_PROPERTY(grCombineFactor_ce, GR_COMBINE_FACTOR_ONE_MINUS_DETAIL_FACTOR);
	SET_PROPERTY(grCombineFactor_ce, GR_COMBINE_FACTOR_ONE_MINUS_LOD_FRACTION);

	//typedef FxI32 GrCombineLocal_ce;
	grCombineLocal_ce = zend_register_internal_enum("GrCombineLocal_t", IS_LONG, NULL);
	SET_PROPERTY(grCombineLocal_ce, GR_COMBINE_FUNCTION_ZERO);
	SET_PROPERTY(grCombineLocal_ce, GR_COMBINE_LOCAL_CONSTANT);
	SET_PROPERTY(grCombineLocal_ce, GR_COMBINE_LOCAL_NONE);
	SET_PROPERTY(grCombineLocal_ce, GR_COMBINE_LOCAL_DEPTH);

	//typedef FxI32 GrCombineOther_ce;
	grCombineOther_ce = zend_register_internal_enum("GrCombineOther_t", IS_LONG, NULL);
	SET_PROPERTY(grCombineOther_ce, GR_COMBINE_OTHER_ITERATED);
	SET_PROPERTY(grCombineOther_ce, GR_COMBINE_OTHER_TEXTURE);
	SET_PROPERTY(grCombineOther_ce, GR_COMBINE_OTHER_CONSTANT);
	SET_PROPERTY(grCombineOther_ce, GR_COMBINE_OTHER_NONE);

	//typedef FxI32 GrAlphaSource_ce;
	grAlphaSource_ce = zend_register_internal_enum("GrAlphaSource_t", IS_LONG, NULL);
	SET_PROPERTY(grAlphaSource_ce, GR_ALPHASOURCE_CC_ALPHA);
	SET_PROPERTY(grAlphaSource_ce, GR_ALPHASOURCE_ITERATED_ALPHA);
	SET_PROPERTY(grAlphaSource_ce, GR_ALPHASOURCE_TEXTURE_ALPHA);
	SET_PROPERTY(grAlphaSource_ce, GR_ALPHASOURCE_TEXTURE_ALPHA_TIMES_ITERATED_ALPHA);

	//typedef FxI32 GrColorCombineFnc_ce;
	grColorCombineFnc_ce = zend_register_internal_enum("GrColorCombineFnc_t", IS_LONG, NULL);
	SET_PROPERTY(grColorCombineFnc_ce, GR_COLORCOMBINE_ZERO);
	SET_PROPERTY(grColorCombineFnc_ce, GR_COLORCOMBINE_CCRGB);
	SET_PROPERTY(grColorCombineFnc_ce, GR_COLORCOMBINE_ITRGB);
	SET_PROPERTY(grColorCombineFnc_ce, GR_COLORCOMBINE_ITRGB_DELTA0);
	SET_PROPERTY(grColorCombineFnc_ce, GR_COLORCOMBINE_DECAL_TEXTURE);
	SET_PROPERTY(grColorCombineFnc_ce, GR_COLORCOMBINE_TEXTURE_TIMES_CCRGB);
	SET_PROPERTY(grColorCombineFnc_ce, GR_COLORCOMBINE_TEXTURE_TIMES_ITRGB);
	SET_PROPERTY(grColorCombineFnc_ce, GR_COLORCOMBINE_TEXTURE_TIMES_ITRGB_DELTA0);
	SET_PROPERTY(grColorCombineFnc_ce, GR_COLORCOMBINE_TEXTURE_TIMES_ITRGB_ADD_ALPHA);
	SET_PROPERTY(grColorCombineFnc_ce, GR_COLORCOMBINE_TEXTURE_TIMES_ALPHA);
	SET_PROPERTY(grColorCombineFnc_ce, GR_COLORCOMBINE_TEXTURE_TIMES_ALPHA_ADD_ITRGB);
	SET_PROPERTY(grColorCombineFnc_ce, GR_COLORCOMBINE_TEXTURE_ADD_ITRGB);
	SET_PROPERTY(grColorCombineFnc_ce, GR_COLORCOMBINE_TEXTURE_SUB_ITRGB);
	SET_PROPERTY(grColorCombineFnc_ce, GR_COLORCOMBINE_CCRGB_BLEND_ITRGB_ON_TEXALPHA);
	SET_PROPERTY(grColorCombineFnc_ce, GR_COLORCOMBINE_DIFF_SPEC_A);
	SET_PROPERTY(grColorCombineFnc_ce, GR_COLORCOMBINE_DIFF_SPEC_B);
	SET_PROPERTY(grColorCombineFnc_ce, GR_COLORCOMBINE_ONE);

	//typedef FxI32 GrAlphaBlendFnc_ce;
	grAlphaBlendFnc_ce = zend_register_internal_enum("GrAlphaBlendFnc_t", IS_LONG, NULL);
	SET_PROPERTY(grAlphaBlendFnc_ce, GR_BLEND_ZERO);
	SET_PROPERTY(grAlphaBlendFnc_ce, GR_BLEND_SRC_ALPHA);
	SET_PROPERTY(grAlphaBlendFnc_ce, GR_BLEND_SRC_COLOR);
	SET_PROPERTY(grAlphaBlendFnc_ce, GR_BLEND_DST_COLOR);
	SET_PROPERTY(grAlphaBlendFnc_ce, GR_BLEND_DST_ALPHA);
	SET_PROPERTY(grAlphaBlendFnc_ce, GR_BLEND_ONE);
	SET_PROPERTY(grAlphaBlendFnc_ce, GR_BLEND_ONE_MINUS_SRC_ALPHA);
	SET_PROPERTY(grAlphaBlendFnc_ce, GR_BLEND_ONE_MINUS_SRC_COLOR);
	SET_PROPERTY(grAlphaBlendFnc_ce, GR_BLEND_ONE_MINUS_DST_COLOR);
	SET_PROPERTY(grAlphaBlendFnc_ce, GR_BLEND_ONE_MINUS_DST_ALPHA);
	SET_PROPERTY(grAlphaBlendFnc_ce, GR_BLEND_RESERVED_8);
	SET_PROPERTY(grAlphaBlendFnc_ce, GR_BLEND_RESERVED_9);
	SET_PROPERTY(grAlphaBlendFnc_ce, GR_BLEND_RESERVED_A);
	SET_PROPERTY(grAlphaBlendFnc_ce, GR_BLEND_RESERVED_B);
	SET_PROPERTY(grAlphaBlendFnc_ce, GR_BLEND_RESERVED_C);
	SET_PROPERTY(grAlphaBlendFnc_ce, GR_BLEND_RESERVED_D);
	SET_PROPERTY(grAlphaBlendFnc_ce, GR_BLEND_RESERVED_E);
	SET_PROPERTY(grAlphaBlendFnc_ce, GR_BLEND_ALPHA_SATURATE);
	SET_PROPERTY(grAlphaBlendFnc_ce, GR_BLEND_PREFOG_COLOR);

	//typedef FxI32 GrAspectRatio_ce;
	grAspectRatio_ce = zend_register_internal_enum("GrAspectRatio_t", IS_LONG, NULL);
	SET_PROPERTY(grAspectRatio_ce, GR_ASPECT_8x1);
	SET_PROPERTY(grAspectRatio_ce, GR_ASPECT_4x1);
	SET_PROPERTY(grAspectRatio_ce, GR_ASPECT_2x1);
	SET_PROPERTY(grAspectRatio_ce, GR_ASPECT_1x1);
	SET_PROPERTY(grAspectRatio_ce, GR_ASPECT_1x2);
	SET_PROPERTY(grAspectRatio_ce, GR_ASPECT_1x4);
	SET_PROPERTY(grAspectRatio_ce, GR_ASPECT_1x8);

	//typedef FxI32 GrBuffer_ce;
	grBuffer_ce = zend_register_internal_enum("GrBuffer_t", IS_LONG, NULL);
	SET_PROPERTY(grBuffer_ce, GR_BUFFER_FRONTBUFFER);
	SET_PROPERTY(grBuffer_ce, GR_BUFFER_BACKBUFFER);
	SET_PROPERTY(grBuffer_ce, GR_BUFFER_AUXBUFFER);
	SET_PROPERTY(grBuffer_ce, GR_BUFFER_DEPTHBUFFER);
	SET_PROPERTY(grBuffer_ce, GR_BUFFER_ALPHABUFFER);
	SET_PROPERTY(grBuffer_ce, GR_BUFFER_TRIPLEBUFFER);

	//typedef FxI32 GrChromakeyMode_ce;
	grChromakeyMode_ce = zend_register_internal_enum("GrChromakeyMode_t", IS_LONG, NULL);
	SET_PROPERTY(grChromakeyMode_ce, GR_CHROMAKEY_DISABLE);
	SET_PROPERTY(grChromakeyMode_ce, GR_CHROMAKEY_ENABLE);

	//typedef FxI32 GrCmpFnc_ce;
	grCmpFnc_ce = zend_register_internal_enum("GrCmpFnc_t", IS_LONG, NULL);
	SET_PROPERTY(grCmpFnc_ce, GR_CMP_NEVER);
	SET_PROPERTY(grCmpFnc_ce, GR_CMP_LESS);
	SET_PROPERTY(grCmpFnc_ce, GR_CMP_EQUAL);
	SET_PROPERTY(grCmpFnc_ce, GR_CMP_LEQUAL);
	SET_PROPERTY(grCmpFnc_ce, GR_CMP_GREATER);
	SET_PROPERTY(grCmpFnc_ce, GR_CMP_NOTEQUAL);
	SET_PROPERTY(grCmpFnc_ce, GR_CMP_GEQUAL);
	SET_PROPERTY(grCmpFnc_ce, GR_CMP_ALWAYS);

	//typedef FxI32 GrColorFormat_ce;
	grColorFormat_ce = zend_register_internal_enum("GrColorFormat_t", IS_LONG, NULL);
	SET_PROPERTY(grColorFormat_ce, GR_COLORFORMAT_ARGB);
	SET_PROPERTY(grColorFormat_ce, GR_COLORFORMAT_ABGR);
	SET_PROPERTY(grColorFormat_ce, GR_COLORFORMAT_RGBA);
	SET_PROPERTY(grColorFormat_ce, GR_COLORFORMAT_BGRA);

	//typedef FxI32 GrCullMode_ce;
	grCullMode_ce = zend_register_internal_enum("GrCullMode_t", IS_LONG, NULL);
	SET_PROPERTY(grCullMode_ce, GR_CULL_DISABLE);
	SET_PROPERTY(grCullMode_ce, GR_CULL_NEGATIVE);
	SET_PROPERTY(grCullMode_ce, GR_CULL_POSITIVE);

	//typedef FxI32 GrDepthBufferMode_ce;
	grDepthBufferMode_ce = zend_register_internal_enum("GrDepthBufferMode_t", IS_LONG, NULL);
	SET_PROPERTY(grDepthBufferMode_ce, GR_DEPTHBUFFER_DISABLE);
	SET_PROPERTY(grDepthBufferMode_ce, GR_DEPTHBUFFER_ZBUFFER);
	SET_PROPERTY(grDepthBufferMode_ce, GR_DEPTHBUFFER_WBUFFER);
	SET_PROPERTY(grDepthBufferMode_ce, GR_DEPTHBUFFER_ZBUFFER_COMPARE_TO_BIAS);
	SET_PROPERTY(grDepthBufferMode_ce, GR_DEPTHBUFFER_WBUFFER_COMPARE_TO_BIAS);

	//typedef FxI32 GrDitherMode_ce;
	grDitherMode_ce = zend_register_internal_enum("GrDitherMode_t", IS_LONG, NULL);
	SET_PROPERTY(grDitherMode_ce, GR_DITHER_DISABLE);
	SET_PROPERTY(grDitherMode_ce, GR_DITHER_2x2);
	SET_PROPERTY(grDitherMode_ce, GR_DITHER_4x4);

	//typedef FxI32 GrFogMode_ce;
	grFogMode_ce = zend_register_internal_enum("GrFogMode_t", IS_LONG, NULL);
	SET_PROPERTY(grFogMode_ce, GR_FOG_DISABLE);
	SET_PROPERTY(grFogMode_ce, GR_FOG_WITH_ITERATED_ALPHA);
	SET_PROPERTY(grFogMode_ce, GR_FOG_WITH_TABLE);
	SET_PROPERTY(grFogMode_ce, GR_FOG_WITH_ITERATED_Z); /* Bug 735 */
	SET_PROPERTY(grFogMode_ce, GR_FOG_MULT2);
	SET_PROPERTY(grFogMode_ce, GR_FOG_ADD2);

	//typedef FxU32 GrLock_ce;
	grLock_ce = zend_register_internal_enum("GrLock_t", IS_LONG, NULL);
	SET_PROPERTY(grLock_ce, GR_LFB_READ_ONLY);
	SET_PROPERTY(grLock_ce, GR_LFB_WRITE_ONLY);
	SET_PROPERTY(grLock_ce, GR_LFB_IDLE);
	SET_PROPERTY(grLock_ce, GR_LFB_NOIDLE);

	//typedef FxI32 GrLfbBypassMode_ce;
	grLfbBypassMode_ce = zend_register_internal_enum("GrLfbBypassMode_t", IS_LONG, NULL);
	SET_PROPERTY(grLfbBypassMode_ce, GR_LFBBYPASS_DISABLE);
	SET_PROPERTY(grLfbBypassMode_ce, GR_LFBBYPASS_ENABLE);

	//typedef FxI32 GrLfbWriteMode_ce;
	grLfbWriteMode_ce = zend_register_internal_enum("GrLfbWriteMode_t", IS_LONG, NULL);
	SET_PROPERTY(grLfbWriteMode_ce, GR_LFBWRITEMODE_565);
	SET_PROPERTY(grLfbWriteMode_ce, GR_LFBWRITEMODE_555);
	SET_PROPERTY(grLfbWriteMode_ce, GR_LFBWRITEMODE_1555);
	SET_PROPERTY(grLfbWriteMode_ce, GR_LFBWRITEMODE_RESERVED1);
	SET_PROPERTY(grLfbWriteMode_ce, GR_LFBWRITEMODE_888);
	SET_PROPERTY(grLfbWriteMode_ce, GR_LFBWRITEMODE_8888);
	SET_PROPERTY(grLfbWriteMode_ce, GR_LFBWRITEMODE_RESERVED2);
	SET_PROPERTY(grLfbWriteMode_ce, GR_LFBWRITEMODE_RESERVED3);
	SET_PROPERTY(grLfbWriteMode_ce, GR_LFBWRITEMODE_RESERVED4);
	SET_PROPERTY(grLfbWriteMode_ce, GR_LFBWRITEMODE_RESERVED5);
	SET_PROPERTY(grLfbWriteMode_ce, GR_LFBWRITEMODE_RESERVED6);
	SET_PROPERTY(grLfbWriteMode_ce, GR_LFBWRITEMODE_RESERVED7);
	SET_PROPERTY(grLfbWriteMode_ce, GR_LFBWRITEMODE_565_DEPTH);
	SET_PROPERTY(grLfbWriteMode_ce, GR_LFBWRITEMODE_555_DEPTH);
	SET_PROPERTY(grLfbWriteMode_ce, GR_LFBWRITEMODE_1555_DEPTH);
	SET_PROPERTY(grLfbWriteMode_ce, GR_LFBWRITEMODE_ZA16);
	SET_PROPERTY(grLfbWriteMode_ce, GR_LFBWRITEMODE_ANY);

	//typedef FxI32 GrOriginLocation_ce;
	grOriginLocation_ce = zend_register_internal_enum("GrOriginLocation_t", IS_LONG, NULL);
	SET_PROPERTY(grOriginLocation_ce, GR_ORIGIN_UPPER_LEFT);
	SET_PROPERTY(grOriginLocation_ce, GR_ORIGIN_LOWER_LEFT);
	SET_PROPERTY(grOriginLocation_ce, GR_ORIGIN_ANY);

	/*
	typedef struct {
		int                size;
		void               *lfbPtr;
		FxU32              strideInBytes;        
		GrLfbWriteMode_t   writeMode;
		GrOriginLocation_t origin;
	} GrLfbInfo_ce;
	*/

	//typedef FxI32 GrLOD_ce;
	grLOD_ce = zend_register_internal_enum("GrLOD_t", IS_LONG, NULL);
	SET_PROPERTY(grLOD_ce, GR_LOD_256);
	SET_PROPERTY(grLOD_ce, GR_LOD_128);
	SET_PROPERTY(grLOD_ce, GR_LOD_64);
	SET_PROPERTY(grLOD_ce, GR_LOD_32);
	SET_PROPERTY(grLOD_ce, GR_LOD_16);
	SET_PROPERTY(grLOD_ce, GR_LOD_8);
	SET_PROPERTY(grLOD_ce, GR_LOD_4);
	SET_PROPERTY(grLOD_ce, GR_LOD_2);
	SET_PROPERTY(grLOD_ce, GR_LOD_1);

	//typedef FxI32 GrMipMapMode_ce;
	grMipMapMode_ce = zend_register_internal_enum("GrMipMapMode_t", IS_LONG, NULL);
	SET_PROPERTY(grMipMapMode_ce, GR_MIPMAP_DISABLE);
	SET_PROPERTY(grMipMapMode_ce, GR_MIPMAP_NEAREST);
	SET_PROPERTY(grMipMapMode_ce, GR_MIPMAP_NEAREST_DITHER);

	//typedef FxI32 GrSmoothingMode_ce;
	grSmoothingMode_ce = zend_register_internal_enum("GrSmoothingMode_t", IS_LONG, NULL);
	SET_PROPERTY(grSmoothingMode_ce, GR_SMOOTHING_DISABLE);
	SET_PROPERTY(grSmoothingMode_ce, GR_SMOOTHING_ENABLE);

	//typedef FxI32 GrTextureClampMode_ce;
	grTextureClampMode_ce = zend_register_internal_enum("GrTextureClampMode_t", IS_LONG, NULL);
	SET_PROPERTY(grTextureClampMode_ce, GR_TEXTURECLAMP_WRAP);
	SET_PROPERTY(grTextureClampMode_ce, GR_TEXTURECLAMP_CLAMP);

	//typedef FxI32 GrTextureCombineFnc_ce;
	grTextureCombineFnc_ce = zend_register_internal_enum("GrTextureCombineFnc_t", IS_LONG, NULL);
	SET_PROPERTY(grTextureCombineFnc_ce, GR_TEXTURECOMBINE_ZERO);
	SET_PROPERTY(grTextureCombineFnc_ce, GR_TEXTURECOMBINE_DECAL);
	SET_PROPERTY(grTextureCombineFnc_ce, GR_TEXTURECOMBINE_OTHER);
	SET_PROPERTY(grTextureCombineFnc_ce, GR_TEXTURECOMBINE_ADD);
	SET_PROPERTY(grTextureCombineFnc_ce, GR_TEXTURECOMBINE_MULTIPLY);
	SET_PROPERTY(grTextureCombineFnc_ce, GR_TEXTURECOMBINE_SUBTRACT);
	SET_PROPERTY(grTextureCombineFnc_ce, GR_TEXTURECOMBINE_DETAIL);
	SET_PROPERTY(grTextureCombineFnc_ce, GR_TEXTURECOMBINE_DETAIL_OTHER);
	SET_PROPERTY(grTextureCombineFnc_ce, GR_TEXTURECOMBINE_TRILINEAR_ODD);
	SET_PROPERTY(grTextureCombineFnc_ce, GR_TEXTURECOMBINE_TRILINEAR_EVEN);
	SET_PROPERTY(grTextureCombineFnc_ce, GR_TEXTURECOMBINE_ONE);
	

	//typedef FxI32 GrTextureFilterMode_ce;
	grTextureFilterMode_ce = zend_register_internal_enum("GrTextureFilterMode_t", IS_LONG, NULL);
	SET_PROPERTY(grTextureFilterMode_ce, GR_TEXTUREFILTER_POINT_SAMPLED);
	SET_PROPERTY(grTextureFilterMode_ce, GR_TEXTUREFILTER_BILINEAR);
	
	//typedef FxI32 GrTextureFormat_ce;
	grTextureFormat_ce = zend_register_internal_enum("GrTextureFormat_t", IS_LONG, NULL);
	SET_PROPERTY(grTextureFormat_ce, GR_TEXFMT_8BIT);
	SET_PROPERTY(grTextureFormat_ce, GR_TEXFMT_RGB_332);
	SET_PROPERTY(grTextureFormat_ce, GR_TEXFMT_YIQ_422);
	SET_PROPERTY(grTextureFormat_ce, GR_TEXFMT_ALPHA_8);
	SET_PROPERTY(grTextureFormat_ce, GR_TEXFMT_INTENSITY_8);
	SET_PROPERTY(grTextureFormat_ce, GR_TEXFMT_ALPHA_INTENSITY_44);
	SET_PROPERTY(grTextureFormat_ce, GR_TEXFMT_P_8);
	SET_PROPERTY(grTextureFormat_ce, GR_TEXFMT_RSVD0);
	SET_PROPERTY(grTextureFormat_ce, GR_TEXFMT_RSVD1);
	SET_PROPERTY(grTextureFormat_ce, GR_TEXFMT_16BIT);
	SET_PROPERTY(grTextureFormat_ce, GR_TEXFMT_ARGB_8332);
	SET_PROPERTY(grTextureFormat_ce, GR_TEXFMT_AYIQ_8422);
	SET_PROPERTY(grTextureFormat_ce, GR_TEXFMT_RGB_565);
	SET_PROPERTY(grTextureFormat_ce, GR_TEXFMT_ARGB_1555);
	SET_PROPERTY(grTextureFormat_ce, GR_TEXFMT_ARGB_4444);
	SET_PROPERTY(grTextureFormat_ce, GR_TEXFMT_ALPHA_INTENSITY_88);
	SET_PROPERTY(grTextureFormat_ce, GR_TEXFMT_AP_88);
	SET_PROPERTY(grTextureFormat_ce, GR_TEXFMT_RSVD2);


	//typedef FxU32 GrTexTable_ce;
	grTexTable_ce = zend_register_internal_enum("GrTexTable_t", IS_LONG, NULL);
	SET_PROPERTY(grTexTable_ce, GR_TEXTABLE_NCC0);
	SET_PROPERTY(grTexTable_ce, GR_TEXTABLE_NCC1);
	SET_PROPERTY(grTexTable_ce, GR_TEXTABLE_PALETTE);
	
	//typedef FxU32 GrNCCTable_ce;
	grNCCTable_ce = zend_register_internal_enum("GrNCCTable_t", IS_LONG, NULL);
	SET_PROPERTY(grNCCTable_ce, GR_NCCTABLE_NCC0);
	SET_PROPERTY(grNCCTable_ce, GR_NCCTABLE_NCC1);

	//typedef FxU32 GrTexBaseRange_ce;
	grTexBaseRange_ce = zend_register_internal_enum("GrTexBaseRange_t", IS_LONG, NULL);
	SET_PROPERTY(grTexBaseRange_ce, GR_TEXBASE_256);
	SET_PROPERTY(grTexBaseRange_ce, GR_TEXBASE_128);
	SET_PROPERTY(grTexBaseRange_ce, GR_TEXBASE_64);
	SET_PROPERTY(grTexBaseRange_ce, GR_TEXBASE_32_TO_1);

	/*
	typedef struct _GrState_s {
	  char pad[GLIDE_STATE_PAD_SIZE];
	} GrState;
	*/

	/*
	typedef struct {
		GrLOD_t           smallLod;
		GrLOD_t           largeLod;
		GrAspectRatio_t   aspectRatio;
		GrTextureFormat_t format;
		void              *data;
	} GrTexInfo;
	*/

	//typedef int GrSstType;
	grSstType_ce = zend_register_internal_enum("GrSstType", IS_LONG, NULL);
	SET_PROPERTY(grSstType_ce, GR_SSTTYPE_VOODOO)
	SET_PROPERTY(grSstType_ce, GR_SSTTYPE_SST96)
	SET_PROPERTY(grSstType_ce, GR_SSTTYPE_AT3D)
	SET_PROPERTY(grSstType_ce, GR_SSTTYPE_Voodoo2)



	grScreenRefresh_ce = zend_register_internal_enum("GrScreenRefresh_t", IS_LONG, NULL);
	SET_PROPERTY(grScreenRefresh_ce, GR_REFRESH_60Hz);
	SET_PROPERTY(grScreenRefresh_ce, GR_REFRESH_70Hz);
	SET_PROPERTY(grScreenRefresh_ce, GR_REFRESH_72Hz);
	SET_PROPERTY(grScreenRefresh_ce, GR_REFRESH_75Hz);
	SET_PROPERTY(grScreenRefresh_ce, GR_REFRESH_80Hz);
	SET_PROPERTY(grScreenRefresh_ce, GR_REFRESH_90Hz);
	SET_PROPERTY(grScreenRefresh_ce, GR_REFRESH_100Hz);
	SET_PROPERTY(grScreenRefresh_ce, GR_REFRESH_85Hz);
	SET_PROPERTY(grScreenRefresh_ce, GR_REFRESH_120Hz);
	SET_PROPERTY(grScreenRefresh_ce, GR_REFRESH_NONE);

	//typedef FxI32 GrScreenResolution_ce;
	grScreenResolution_ce = zend_register_internal_enum("GrScreenResolution_t", IS_LONG, NULL);
	SET_PROPERTY(grScreenResolution_ce, GR_RESOLUTION_320x200);
	SET_PROPERTY(grScreenResolution_ce, GR_RESOLUTION_320x240);
	SET_PROPERTY(grScreenResolution_ce, GR_RESOLUTION_400x256);
	SET_PROPERTY(grScreenResolution_ce, GR_RESOLUTION_512x384);
	SET_PROPERTY(grScreenResolution_ce, GR_RESOLUTION_640x200);
	SET_PROPERTY(grScreenResolution_ce, GR_RESOLUTION_640x350);
	SET_PROPERTY(grScreenResolution_ce, GR_RESOLUTION_640x400);
	SET_PROPERTY(grScreenResolution_ce, GR_RESOLUTION_640x480);
	SET_PROPERTY(grScreenResolution_ce, GR_RESOLUTION_800x600);
	SET_PROPERTY(grScreenResolution_ce, GR_RESOLUTION_960x720);
	SET_PROPERTY(grScreenResolution_ce, GR_RESOLUTION_856x480);
	SET_PROPERTY(grScreenResolution_ce, GR_RESOLUTION_512x256);
	SET_PROPERTY(grScreenResolution_ce, GR_RESOLUTION_1024x768);
	SET_PROPERTY(grScreenResolution_ce, GR_RESOLUTION_1280x1024);
	SET_PROPERTY(grScreenResolution_ce, GR_RESOLUTION_1600x1200);
	SET_PROPERTY(grScreenResolution_ce, GR_RESOLUTION_400x300);
	SET_PROPERTY(grScreenResolution_ce, GR_RESOLUTION_NONE);

	SET_PROPERTY(grScreenResolution_ce, GR_RESOLUTION_MIN);
	SET_PROPERTY(grScreenResolution_ce, GR_RESOLUTION_MAX);
}