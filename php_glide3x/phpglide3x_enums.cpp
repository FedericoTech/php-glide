#include "phpglide3x_enums.h"

#include <php.h>
#include <Zend/zend_enum.h>
#define __MSC__
#include <glide.h>

#define SET_PROPERTY(ce, v) \
	ZVAL_LONG(&case_value, v); \
	zend_enum_add_case_cstr(ce, #v, &case_value);

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
zend_class_entry* grChromaRangeMode_ce;
zend_class_entry* grTexChromakeyMode_ce;
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
zend_class_entry* grEnableMode_ce;
zend_class_entry* grCoordinateSpaceMode_ce;
zend_class_entry* grDataStrips_ce;
zend_class_entry* grParams_ce;
zend_class_entry* grMode_ce;
zend_class_entry* grVertex_ce;
zend_class_entry* grGet_ce;
zend_class_entry* grString_ce;
zend_class_entry* grScreenRefresh_ce;
zend_class_entry* grScreenResolution_ce;


void phpglide3x_register_enums(INIT_FUNC_ARGS)
{
	zval case_value;

	grCombineFunction_ce = zend_register_internal_enum("GrCombineFunction_t", IS_LONG, NULL);
	SET_PROPERTY(grCombineFunction_ce, GR_COMBINE_FUNCTION_ZERO)
	SET_PROPERTY(grCombineFunction_ce, GR_COMBINE_FUNCTION_NONE)
	SET_PROPERTY(grCombineFunction_ce, GR_COMBINE_FUNCTION_LOCAL)
	SET_PROPERTY(grCombineFunction_ce, GR_COMBINE_FUNCTION_LOCAL_ALPHA)
	SET_PROPERTY(grCombineFunction_ce, GR_COMBINE_FUNCTION_SCALE_OTHER)
	SET_PROPERTY(grCombineFunction_ce, GR_COMBINE_FUNCTION_BLEND_OTHER)
	SET_PROPERTY(grCombineFunction_ce, GR_COMBINE_FUNCTION_SCALE_OTHER_ADD_LOCAL)
	SET_PROPERTY(grCombineFunction_ce, GR_COMBINE_FUNCTION_SCALE_OTHER_ADD_LOCAL_ALPHA)
	SET_PROPERTY(grCombineFunction_ce, GR_COMBINE_FUNCTION_SCALE_OTHER_MINUS_LOCAL)
	SET_PROPERTY(grCombineFunction_ce, GR_COMBINE_FUNCTION_SCALE_OTHER_MINUS_LOCAL_ADD_LOCAL)
	SET_PROPERTY(grCombineFunction_ce, GR_COMBINE_FUNCTION_BLEND)
	SET_PROPERTY(grCombineFunction_ce, GR_COMBINE_FUNCTION_SCALE_OTHER_MINUS_LOCAL_ADD_LOCAL_ALPHA)
	SET_PROPERTY(grCombineFunction_ce, GR_COMBINE_FUNCTION_SCALE_MINUS_LOCAL_ADD_LOCAL)
	SET_PROPERTY(grCombineFunction_ce, GR_COMBINE_FUNCTION_BLEND_LOCAL)
	SET_PROPERTY(grCombineFunction_ce, GR_COMBINE_FUNCTION_SCALE_MINUS_LOCAL_ADD_LOCAL_ALPHA)

	grCombineFactor_ce = zend_register_internal_enum("GrCombineFactor_t", IS_LONG, NULL);
	SET_PROPERTY(grCombineFactor_ce, GR_COMBINE_FACTOR_ZERO)
	SET_PROPERTY(grCombineFactor_ce, GR_COMBINE_FACTOR_NONE)
	SET_PROPERTY(grCombineFactor_ce, GR_COMBINE_FACTOR_LOCAL)
	SET_PROPERTY(grCombineFactor_ce, GR_COMBINE_FACTOR_OTHER_ALPHA)
	SET_PROPERTY(grCombineFactor_ce, GR_COMBINE_FACTOR_LOCAL_ALPHA)
	SET_PROPERTY(grCombineFactor_ce, GR_COMBINE_FACTOR_TEXTURE_ALPHA)
	SET_PROPERTY(grCombineFactor_ce, GR_COMBINE_FACTOR_TEXTURE_RGB)
	SET_PROPERTY(grCombineFactor_ce, GR_COMBINE_FACTOR_DETAIL_FACTOR)
	SET_PROPERTY(grCombineFactor_ce, GR_COMBINE_FACTOR_LOD_FRACTION)
	SET_PROPERTY(grCombineFactor_ce, GR_COMBINE_FACTOR_ONE)
	SET_PROPERTY(grCombineFactor_ce, GR_COMBINE_FACTOR_ONE_MINUS_LOCAL)
	SET_PROPERTY(grCombineFactor_ce, GR_COMBINE_FACTOR_ONE_MINUS_OTHER_ALPHA)
	SET_PROPERTY(grCombineFactor_ce, GR_COMBINE_FACTOR_ONE_MINUS_LOCAL_ALPHA)
	SET_PROPERTY(grCombineFactor_ce, GR_COMBINE_FACTOR_ONE_MINUS_TEXTURE_ALPHA)
	SET_PROPERTY(grCombineFactor_ce, GR_COMBINE_FACTOR_ONE_MINUS_DETAIL_FACTOR)
	SET_PROPERTY(grCombineFactor_ce, GR_COMBINE_FACTOR_ONE_MINUS_LOD_FRACTION)


	grCombineLocal_ce = zend_register_internal_enum("GrCombineLocal_t", IS_LONG, NULL);
	SET_PROPERTY(grCombineLocal_ce, GR_COMBINE_LOCAL_ITERATED)
	SET_PROPERTY(grCombineLocal_ce, GR_COMBINE_LOCAL_CONSTANT)
	SET_PROPERTY(grCombineLocal_ce, GR_COMBINE_LOCAL_NONE)
	SET_PROPERTY(grCombineLocal_ce, GR_COMBINE_LOCAL_DEPTH)

	grCombineOther_ce = zend_register_internal_enum("GrCombineOther_t", IS_LONG, NULL);
	SET_PROPERTY(grCombineOther_ce, GR_COMBINE_OTHER_ITERATED)
	SET_PROPERTY(grCombineOther_ce, GR_COMBINE_OTHER_TEXTURE)
	SET_PROPERTY(grCombineOther_ce, GR_COMBINE_OTHER_CONSTANT)
	SET_PROPERTY(grCombineOther_ce, GR_COMBINE_OTHER_NONE)

	grAlphaSource_ce = zend_register_internal_enum("GrAlphaSource_t", IS_LONG, NULL);
	SET_PROPERTY(grAlphaSource_ce, GR_ALPHASOURCE_CC_ALPHA)
	SET_PROPERTY(grAlphaSource_ce, GR_ALPHASOURCE_ITERATED_ALPHA)
	SET_PROPERTY(grAlphaSource_ce, GR_ALPHASOURCE_TEXTURE_ALPHA)
	SET_PROPERTY(grAlphaSource_ce, GR_ALPHASOURCE_TEXTURE_ALPHA_TIMES_ITERATED_ALPHA)

	grColorCombineFnc_ce = zend_register_internal_enum("GrColorCombineFnc_t", IS_LONG, NULL);
	SET_PROPERTY(grColorCombineFnc_ce, GR_COLORCOMBINE_ZERO)
	SET_PROPERTY(grColorCombineFnc_ce, GR_COLORCOMBINE_CCRGB)
	SET_PROPERTY(grColorCombineFnc_ce, GR_COLORCOMBINE_ITRGB)
	SET_PROPERTY(grColorCombineFnc_ce, GR_COLORCOMBINE_ITRGB_DELTA0)
	SET_PROPERTY(grColorCombineFnc_ce, GR_COLORCOMBINE_DECAL_TEXTURE)
	SET_PROPERTY(grColorCombineFnc_ce, GR_COLORCOMBINE_TEXTURE_TIMES_CCRGB)
	SET_PROPERTY(grColorCombineFnc_ce, GR_COLORCOMBINE_TEXTURE_TIMES_ITRGB)
	SET_PROPERTY(grColorCombineFnc_ce, GR_COLORCOMBINE_TEXTURE_TIMES_ITRGB_DELTA0)
	SET_PROPERTY(grColorCombineFnc_ce, GR_COLORCOMBINE_TEXTURE_TIMES_ITRGB_ADD_ALPHA)
	SET_PROPERTY(grColorCombineFnc_ce, GR_COLORCOMBINE_TEXTURE_TIMES_ALPHA)
	SET_PROPERTY(grColorCombineFnc_ce, GR_COLORCOMBINE_TEXTURE_TIMES_ALPHA_ADD_ITRGB)
	SET_PROPERTY(grColorCombineFnc_ce, GR_COLORCOMBINE_TEXTURE_ADD_ITRGB)
	SET_PROPERTY(grColorCombineFnc_ce, GR_COLORCOMBINE_TEXTURE_SUB_ITRGB)
	SET_PROPERTY(grColorCombineFnc_ce, GR_COLORCOMBINE_CCRGB_BLEND_ITRGB_ON_TEXALPHA)
	SET_PROPERTY(grColorCombineFnc_ce, GR_COLORCOMBINE_DIFF_SPEC_A)
	SET_PROPERTY(grColorCombineFnc_ce, GR_COLORCOMBINE_DIFF_SPEC_B)
	SET_PROPERTY(grColorCombineFnc_ce, GR_COLORCOMBINE_ONE)


	grAlphaBlendFnc_ce = zend_register_internal_enum("GrAlphaBlendFnc_t", IS_LONG, NULL);
	SET_PROPERTY(grAlphaBlendFnc_ce, GR_BLEND_ZERO)
	SET_PROPERTY(grAlphaBlendFnc_ce, GR_BLEND_SRC_ALPHA)
	SET_PROPERTY(grAlphaBlendFnc_ce, GR_BLEND_SRC_COLOR)
	SET_PROPERTY(grAlphaBlendFnc_ce, GR_BLEND_DST_COLOR)
	SET_PROPERTY(grAlphaBlendFnc_ce, GR_BLEND_DST_ALPHA)
	SET_PROPERTY(grAlphaBlendFnc_ce, GR_BLEND_ONE)
	SET_PROPERTY(grAlphaBlendFnc_ce, GR_BLEND_ONE_MINUS_SRC_ALPHA)
	SET_PROPERTY(grAlphaBlendFnc_ce, GR_BLEND_ONE_MINUS_SRC_COLOR)
	SET_PROPERTY(grAlphaBlendFnc_ce, GR_BLEND_ONE_MINUS_DST_COLOR)
	SET_PROPERTY(grAlphaBlendFnc_ce, GR_BLEND_ONE_MINUS_DST_ALPHA)
	SET_PROPERTY(grAlphaBlendFnc_ce, GR_BLEND_RESERVED_8)
	SET_PROPERTY(grAlphaBlendFnc_ce, GR_BLEND_RESERVED_9)
	SET_PROPERTY(grAlphaBlendFnc_ce, GR_BLEND_RESERVED_A)
	SET_PROPERTY(grAlphaBlendFnc_ce, GR_BLEND_RESERVED_B)
	SET_PROPERTY(grAlphaBlendFnc_ce, GR_BLEND_RESERVED_C)
	SET_PROPERTY(grAlphaBlendFnc_ce, GR_BLEND_RESERVED_D)
	SET_PROPERTY(grAlphaBlendFnc_ce, GR_BLEND_RESERVED_E)
	SET_PROPERTY(grAlphaBlendFnc_ce, GR_BLEND_ALPHA_SATURATE)
	SET_PROPERTY(grAlphaBlendFnc_ce, GR_BLEND_PREFOG_COLOR)

	//typedef FxI32 GrAspectRatio_t;
	grAspectRatio_ce = zend_register_internal_enum("GrAspectRatio_t", IS_LONG, NULL);
	SET_PROPERTY(grAspectRatio_ce, GR_ASPECT_LOG2_8x1);
	SET_PROPERTY(grAspectRatio_ce, GR_ASPECT_LOG2_4x1);
	SET_PROPERTY(grAspectRatio_ce, GR_ASPECT_LOG2_2x1);
	SET_PROPERTY(grAspectRatio_ce, GR_ASPECT_LOG2_1x1);
	SET_PROPERTY(grAspectRatio_ce, GR_ASPECT_LOG2_1x2);
	SET_PROPERTY(grAspectRatio_ce, GR_ASPECT_LOG2_1x4);
	SET_PROPERTY(grAspectRatio_ce, GR_ASPECT_LOG2_1x8);

	//typedef FxI32 GrBuffer_t;
	grBuffer_ce = zend_register_internal_enum("GrBuffer_t", IS_LONG, NULL);
	SET_PROPERTY(grBuffer_ce, GR_BUFFER_FRONTBUFFER);
	SET_PROPERTY(grBuffer_ce, GR_BUFFER_BACKBUFFER);
	SET_PROPERTY(grBuffer_ce, GR_BUFFER_AUXBUFFER);
	SET_PROPERTY(grBuffer_ce, GR_BUFFER_DEPTHBUFFER);
	SET_PROPERTY(grBuffer_ce, GR_BUFFER_ALPHABUFFER);
	SET_PROPERTY(grBuffer_ce, GR_BUFFER_TRIPLEBUFFER);

	//typedef FxI32 GrChromakeyMode_t;
	grChromakeyMode_ce = zend_register_internal_enum("GrChromakeyMode_t", IS_LONG, NULL);
	SET_PROPERTY(grChromakeyMode_ce, GR_CHROMAKEY_DISABLE);
	SET_PROPERTY(grChromakeyMode_ce, GR_CHROMAKEY_ENABLE);

	//typedef FxI32 GrChromaRangeMode_t;
	grChromaRangeMode_ce = zend_register_internal_enum("GrChromaRangeMode_t", IS_LONG, NULL);
	SET_PROPERTY(grChromaRangeMode_ce, GR_CHROMARANGE_RGB_ALL_EXT);
	SET_PROPERTY(grChromaRangeMode_ce, GR_CHROMARANGE_DISABLE_EXT);
	SET_PROPERTY(grChromaRangeMode_ce, GR_CHROMARANGE_ENABLE_EXT);

	//typedef FxI32 GrTexChromakeyMode_t;
	grTexChromakeyMode_ce = zend_register_internal_enum("GrTexChromakeyMode_t", IS_LONG, NULL);
	SET_PROPERTY(grTexChromakeyMode_ce, GR_TEXCHROMA_DISABLE_EXT);
	SET_PROPERTY(grTexChromakeyMode_ce, GR_TEXCHROMA_ENABLE_EXT);
	SET_PROPERTY(grTexChromakeyMode_ce, GR_TEXCHROMARANGE_RGB_ALL_EXT);

	//typedef FxI32 GrCmpFnc_t;
	grCmpFnc_ce = zend_register_internal_enum("GrCmpFnc_t", IS_LONG, NULL);
	SET_PROPERTY(grCmpFnc_ce, GR_CMP_NEVER);
	SET_PROPERTY(grCmpFnc_ce, GR_CMP_LESS);
	SET_PROPERTY(grCmpFnc_ce, GR_CMP_EQUAL);
	SET_PROPERTY(grCmpFnc_ce, GR_CMP_LEQUAL);
	SET_PROPERTY(grCmpFnc_ce, GR_CMP_GREATER);
	SET_PROPERTY(grCmpFnc_ce, GR_CMP_NOTEQUAL);
	SET_PROPERTY(grCmpFnc_ce, GR_CMP_GEQUAL);
	SET_PROPERTY(grCmpFnc_ce, GR_CMP_ALWAYS);

	//typedef FxI32 GrColorFormat_t;
	grColorFormat_ce = zend_register_internal_enum("GrColorFormat_t", IS_LONG, NULL);
	SET_PROPERTY(grColorFormat_ce, GR_COLORFORMAT_ARGB);
	SET_PROPERTY(grColorFormat_ce, GR_COLORFORMAT_ABGR);
	SET_PROPERTY(grColorFormat_ce, GR_COLORFORMAT_RGBA);
	SET_PROPERTY(grColorFormat_ce, GR_COLORFORMAT_BGRA);

	//typedef FxI32 GrCullMode_t;
	grCullMode_ce = zend_register_internal_enum("GrCullMode_t", IS_LONG, NULL);
	SET_PROPERTY(grCullMode_ce, GR_CULL_DISABLE);
	SET_PROPERTY(grCullMode_ce, GR_CULL_NEGATIVE);
	SET_PROPERTY(grCullMode_ce, GR_CULL_POSITIVE);

	//typedef FxI32 GrDepthBufferMode_t;
	grDepthBufferMode_ce = zend_register_internal_enum("GrDepthBufferMode_t", IS_LONG, NULL);
	SET_PROPERTY(grDepthBufferMode_ce, GR_DEPTHBUFFER_DISABLE);
	SET_PROPERTY(grDepthBufferMode_ce, GR_DEPTHBUFFER_ZBUFFER);
	SET_PROPERTY(grDepthBufferMode_ce, GR_DEPTHBUFFER_WBUFFER);
	SET_PROPERTY(grDepthBufferMode_ce, GR_DEPTHBUFFER_ZBUFFER_COMPARE_TO_BIAS);
	SET_PROPERTY(grDepthBufferMode_ce, GR_DEPTHBUFFER_WBUFFER_COMPARE_TO_BIAS);

	//typedef FxI32 GrDitherMode_t;
	grDitherMode_ce = zend_register_internal_enum("GrDitherMode_t", IS_LONG, NULL);
	SET_PROPERTY(grDitherMode_ce, GR_DITHER_DISABLE);
	SET_PROPERTY(grDitherMode_ce, GR_DITHER_2x2);
	SET_PROPERTY(grDitherMode_ce, GR_DITHER_4x4);

	//typedef FxI32 GrFogMode_t;
	grFogMode_ce = zend_register_internal_enum("GrFogMode_t", IS_LONG, NULL);
	SET_PROPERTY(grFogMode_ce, GR_FOG_DISABLE);
	SET_PROPERTY(grFogMode_ce, GR_FOG_WITH_TABLE_ON_FOGCOORD_EXT);
	SET_PROPERTY(grFogMode_ce, GR_FOG_WITH_TABLE_ON_Q);
	SET_PROPERTY(grFogMode_ce, GR_FOG_WITH_TABLE_ON_W);
	SET_PROPERTY(grFogMode_ce, GR_FOG_WITH_ITERATED_Z);
	SET_PROPERTY(grFogMode_ce, GR_FOG_MULT2);
	SET_PROPERTY(grFogMode_ce, GR_FOG_ADD2);

	//typedef FxU32 GrLock_t;
	grLock_ce = zend_register_internal_enum("GrLock_t", IS_LONG, NULL);
	SET_PROPERTY(grLock_ce, GR_LFB_READ_ONLY);
	SET_PROPERTY(grLock_ce, GR_LFB_WRITE_ONLY);
	SET_PROPERTY(grLock_ce, GR_LFB_IDLE);
	SET_PROPERTY(grLock_ce, GR_LFB_NOIDLE);

	//typedef FxI32 GrLfbBypassMode_t;
	grLfbBypassMode_ce = zend_register_internal_enum("GrLfbBypassMode_t", IS_LONG, NULL);
	SET_PROPERTY(grLfbBypassMode_ce, GR_LFBBYPASS_DISABLE);
	SET_PROPERTY(grLfbBypassMode_ce, GR_LFBBYPASS_ENABLE);

	//typedef FxI32 GrLfbWriteMode_t;
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

	//typedef FxI32 GrOriginLocation_t;
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
	} GrLfbInfo_t;
	*/

	//typedef FxI32 GrLOD_t;
	grLOD_ce = zend_register_internal_enum("GrLOD_t", IS_LONG, NULL);
	SET_PROPERTY(grLOD_ce, GR_LOD_LOG2_256);
	SET_PROPERTY(grLOD_ce, GR_LOD_LOG2_128);
	SET_PROPERTY(grLOD_ce, GR_LOD_LOG2_64);
	SET_PROPERTY(grLOD_ce, GR_LOD_LOG2_32);
	SET_PROPERTY(grLOD_ce, GR_LOD_LOG2_16);
	SET_PROPERTY(grLOD_ce, GR_LOD_LOG2_8);
	SET_PROPERTY(grLOD_ce, GR_LOD_LOG2_4);
	SET_PROPERTY(grLOD_ce, GR_LOD_LOG2_2);
	SET_PROPERTY(grLOD_ce, GR_LOD_LOG2_1);

	//typedef FxI32 GrMipMapMode_t;
	grMipMapMode_ce = zend_register_internal_enum("GrMipMapMode_t", IS_LONG, NULL);
	SET_PROPERTY(grMipMapMode_ce, GR_MIPMAP_DISABLE);
	SET_PROPERTY(grMipMapMode_ce, GR_MIPMAP_NEAREST);
	SET_PROPERTY(grMipMapMode_ce, GR_MIPMAP_NEAREST_DITHER);

	//typedef FxI32 GrSmoothingMode_t;
	grSmoothingMode_ce = zend_register_internal_enum("GrSmoothingMode_t", IS_LONG, NULL);
	SET_PROPERTY(grSmoothingMode_ce, GR_SMOOTHING_DISABLE);
	SET_PROPERTY(grSmoothingMode_ce, GR_SMOOTHING_ENABLE);

	//typedef FxI32 GrTextureClampMode_t;
	grTextureClampMode_ce = zend_register_internal_enum("GrTextureClampMode_t", IS_LONG, NULL);
	SET_PROPERTY(grTextureClampMode_ce, GR_TEXTURECLAMP_WRAP);
	SET_PROPERTY(grTextureClampMode_ce, GR_TEXTURECLAMP_CLAMP);
	SET_PROPERTY(grTextureClampMode_ce, GR_TEXTURECLAMP_MIRROR_EXT);

	//typedef FxI32 GrTextureCombineFnc_t;
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

	//typedef FxI32 GrTextureFilterMode_t;
	grTextureFilterMode_ce = zend_register_internal_enum("GrTextureFilterMode_t", IS_LONG, NULL);
	SET_PROPERTY(grTextureFilterMode_ce, GR_TEXTUREFILTER_POINT_SAMPLED);
	SET_PROPERTY(grTextureFilterMode_ce, GR_TEXTUREFILTER_BILINEAR);

	//typedef FxI32 GrTextureFormat_t;
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

	//typedef FxU32 GrTexTable_t;
	grTexTable_ce = zend_register_internal_enum("GrTexTable_t", IS_LONG, NULL);
	SET_PROPERTY(grTexTable_ce, GR_TEXTABLE_NCC0);
	SET_PROPERTY(grTexTable_ce, GR_TEXTABLE_NCC1);
	SET_PROPERTY(grTexTable_ce, GR_TEXTABLE_PALETTE);
	SET_PROPERTY(grTexTable_ce, GR_TEXTABLE_PALETTE_6666_EXT);

	//typedef FxU32 GrNCCTable_t;
	grNCCTable_ce = zend_register_internal_enum("GrNCCTable_t", IS_LONG, NULL);
	SET_PROPERTY(grNCCTable_ce, GR_NCCTABLE_NCC0);
	SET_PROPERTY(grNCCTable_ce, GR_NCCTABLE_NCC1);

	//typedef FxU32 GrTexBaseRange_t;
	grTexBaseRange_ce = zend_register_internal_enum("GrTexBaseRange_t", IS_LONG, NULL);
	SET_PROPERTY(grTexBaseRange_ce, GR_TEXBASE_256);
	SET_PROPERTY(grTexBaseRange_ce, GR_TEXBASE_128);
	SET_PROPERTY(grTexBaseRange_ce, GR_TEXBASE_64);
	SET_PROPERTY(grTexBaseRange_ce, GR_TEXBASE_32_TO_1);

	//typedef FxU32 GrEnableMode_t;
	grEnableMode_ce = zend_register_internal_enum("GrEnableMode_t", IS_LONG, NULL);
	SET_PROPERTY(grEnableMode_ce, GR_MODE_DISABLE);
	SET_PROPERTY(grEnableMode_ce, GR_MODE_ENABLE);
	SET_PROPERTY(grEnableMode_ce, GR_AA_ORDERED);
	SET_PROPERTY(grEnableMode_ce, GR_ALLOW_MIPMAP_DITHER);
	SET_PROPERTY(grEnableMode_ce, GR_PASSTHRU);
	SET_PROPERTY(grEnableMode_ce, GR_SHAMELESS_PLUG);
	SET_PROPERTY(grEnableMode_ce, GR_VIDEO_SMOOTHING);

	//typedef FxU32 GrCoordinateSpaceMode_t;
	grCoordinateSpaceMode_ce = zend_register_internal_enum("GrCoordinateSpaceMode_t", IS_LONG, NULL);
	SET_PROPERTY(grCoordinateSpaceMode_ce, GR_WINDOW_COORDS);
	SET_PROPERTY(grCoordinateSpaceMode_ce, GR_CLIP_COORDS);

	/* Types of data in strips */
	grDataStrips_ce = zend_register_internal_enum("GrDataStrips_t", IS_LONG, NULL);
	SET_PROPERTY(grDataStrips_ce, GR_FLOAT);
	SET_PROPERTY(grDataStrips_ce, GR_U8);

	/* Parameters for strips */
	grParams_ce = zend_register_internal_enum("GrParams_t", IS_LONG, NULL);
	SET_PROPERTY(grParams_ce, GR_PARAM_XY);
	SET_PROPERTY(grParams_ce, GR_PARAM_Z);
	SET_PROPERTY(grParams_ce, GR_PARAM_W);
	SET_PROPERTY(grParams_ce, GR_PARAM_Q);
	SET_PROPERTY(grParams_ce, GR_PARAM_FOG_EXT);

	SET_PROPERTY(grParams_ce, GR_PARAM_A);

	SET_PROPERTY(grParams_ce, GR_PARAM_RGB);

	SET_PROPERTY(grParams_ce, GR_PARAM_PARGB);

	SET_PROPERTY(grParams_ce, GR_PARAM_ST0);
	SET_PROPERTY(grParams_ce, GR_PARAM_ST1);
	SET_PROPERTY(grParams_ce, GR_PARAM_ST2);

	SET_PROPERTY(grParams_ce, GR_PARAM_Q0);
	SET_PROPERTY(grParams_ce, GR_PARAM_Q1);
	SET_PROPERTY(grParams_ce, GR_PARAM_Q2);

	grMode_ce = zend_register_internal_enum("GrMode_t", IS_LONG, NULL);

	SET_PROPERTY(grMode_ce, GR_PARAM_DISABLE);
	SET_PROPERTY(grMode_ce, GR_PARAM_ENABLE);

	//grDrawVertexArray/grDrawVertexArrayContiguous primitive type
	grVertex_ce = zend_register_internal_enum("GrVertex_t", IS_LONG, NULL);
	SET_PROPERTY(grVertex_ce, GR_POINTS);
	SET_PROPERTY(grVertex_ce, GR_LINE_STRIP);
	SET_PROPERTY(grVertex_ce, GR_LINES);
	SET_PROPERTY(grVertex_ce, GR_POLYGON);
	SET_PROPERTY(grVertex_ce, GR_TRIANGLE_STRIP);
	SET_PROPERTY(grVertex_ce, GR_TRIANGLE_FAN);
	SET_PROPERTY(grVertex_ce, GR_TRIANGLES);
	SET_PROPERTY(grVertex_ce, GR_TRIANGLE_STRIP_CONTINUE);
	SET_PROPERTY(grVertex_ce, GR_TRIANGLE_FAN_CONTINUE);


	//grGet/grReset types
	grGet_ce = zend_register_internal_enum("GrGet_t", IS_LONG, NULL);
	SET_PROPERTY(grGet_ce, GR_BITS_DEPTH);
	SET_PROPERTY(grGet_ce, GR_BITS_RGBA);
	SET_PROPERTY(grGet_ce, GR_BITS_GAMMA);
	SET_PROPERTY(grGet_ce, GR_FIFO_FULLNESS);
	SET_PROPERTY(grGet_ce, GR_FOG_TABLE_ENTRIES);
	SET_PROPERTY(grGet_ce, GR_GAMMA_TABLE_ENTRIES);
	SET_PROPERTY(grGet_ce, GR_GLIDE_STATE_SIZE);
	SET_PROPERTY(grGet_ce, GR_GLIDE_VERTEXLAYOUT_SIZE);
	SET_PROPERTY(grGet_ce, GR_IS_BUSY);
	SET_PROPERTY(grGet_ce, GR_LFB_PIXEL_PIPE);
	SET_PROPERTY(grGet_ce, GR_MAX_TEXTURE_SIZE);
	SET_PROPERTY(grGet_ce, GR_MAX_TEXTURE_ASPECT_RATIO);
	SET_PROPERTY(grGet_ce, GR_MEMORY_FB);
	SET_PROPERTY(grGet_ce, GR_MEMORY_TMU);
	SET_PROPERTY(grGet_ce, GR_MEMORY_UMA);
	SET_PROPERTY(grGet_ce, GR_NON_POWER_OF_TWO_TEXTURES);
	SET_PROPERTY(grGet_ce, GR_NUM_BOARDS);
	SET_PROPERTY(grGet_ce, GR_NUM_FB);
	SET_PROPERTY(grGet_ce, GR_NUM_SWAP_HISTORY_BUFFER);
	SET_PROPERTY(grGet_ce, GR_NUM_TMU);
	SET_PROPERTY(grGet_ce, GR_PENDING_BUFFERSWAPS);
	SET_PROPERTY(grGet_ce, GR_REVISION_FB);
	SET_PROPERTY(grGet_ce, GR_REVISION_TMU);
	SET_PROPERTY(grGet_ce, GR_STATS_LINES);
	SET_PROPERTY(grGet_ce, GR_STATS_PIXELS_AFUNC_FAIL);
	SET_PROPERTY(grGet_ce, GR_STATS_PIXELS_CHROMA_FAIL);
	SET_PROPERTY(grGet_ce, GR_STATS_PIXELS_DEPTHFUNC_FAIL);
	SET_PROPERTY(grGet_ce, GR_STATS_PIXELS_IN);
	SET_PROPERTY(grGet_ce, GR_STATS_PIXELS_OUT);
	SET_PROPERTY(grGet_ce, GR_STATS_POINTS);
	SET_PROPERTY(grGet_ce, GR_STATS_TRIANGLES_IN);
	SET_PROPERTY(grGet_ce, GR_STATS_TRIANGLES_OUT);
	SET_PROPERTY(grGet_ce, GR_SWAP_HISTORY);
	SET_PROPERTY(grGet_ce, GR_SUPPORTS_PASSTHRU);
	SET_PROPERTY(grGet_ce, GR_TEXTURE_ALIGN);
	SET_PROPERTY(grGet_ce, GR_VIDEO_POSITION);
	SET_PROPERTY(grGet_ce, GR_VIEWPORT);
	SET_PROPERTY(grGet_ce, GR_WDEPTH_MIN_MAX);
	SET_PROPERTY(grGet_ce, GR_ZDEPTH_MIN_MAX);
	
	//grGetString types
	grString_ce = zend_register_internal_enum("GrString_t", IS_LONG, NULL);
	SET_PROPERTY(grString_ce, GR_EXTENSION);
	SET_PROPERTY(grString_ce, GR_HARDWARE);
	SET_PROPERTY(grString_ce, GR_RENDERER);
	SET_PROPERTY(grString_ce, GR_VENDOR);
	SET_PROPERTY(grString_ce, GR_VERSION);





	







	//typedef FxI32 GrScreenRefresh_t
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

	//typedef FxI32 GrScreenResolution_t;
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