
#include "phpglide3x_constants.h"

#include <php.h>
#define __MSC__
#include <glide.h>

#define CREATE_CONSTANT(v) REGISTER_LONG_CONSTANT(#v, v, CONST_CS | CONST_PERSISTENT)

void phpglide3x_register_constants(INIT_FUNC_ARGS) 
{
	//typedef FxI32 GrCombineFunction_t;
	CREATE_CONSTANT(GR_COMBINE_FUNCTION_ZERO);
	CREATE_CONSTANT(GR_COMBINE_FUNCTION_NONE);
	CREATE_CONSTANT(GR_COMBINE_FUNCTION_LOCAL);
	CREATE_CONSTANT(GR_COMBINE_FUNCTION_LOCAL_ALPHA);
	CREATE_CONSTANT(GR_COMBINE_FUNCTION_SCALE_OTHER);
	CREATE_CONSTANT(GR_COMBINE_FUNCTION_BLEND_OTHER);
	CREATE_CONSTANT(GR_COMBINE_FUNCTION_SCALE_OTHER_ADD_LOCAL);
	CREATE_CONSTANT(GR_COMBINE_FUNCTION_SCALE_OTHER_ADD_LOCAL_ALPHA);
	CREATE_CONSTANT(GR_COMBINE_FUNCTION_SCALE_OTHER_MINUS_LOCAL);
	CREATE_CONSTANT(GR_COMBINE_FUNCTION_SCALE_OTHER_MINUS_LOCAL_ADD_LOCAL);
	CREATE_CONSTANT(GR_COMBINE_FUNCTION_BLEND);
	CREATE_CONSTANT(GR_COMBINE_FUNCTION_SCALE_OTHER_MINUS_LOCAL_ADD_LOCAL_ALPHA);
	CREATE_CONSTANT(GR_COMBINE_FUNCTION_SCALE_MINUS_LOCAL_ADD_LOCAL);
	CREATE_CONSTANT(GR_COMBINE_FUNCTION_BLEND_LOCAL);
	CREATE_CONSTANT(GR_COMBINE_FUNCTION_SCALE_MINUS_LOCAL_ADD_LOCAL_ALPHA);

	//typedef FxI32 GrCombineFactor_t;
	CREATE_CONSTANT(GR_COMBINE_FACTOR_ZERO);
	CREATE_CONSTANT(GR_COMBINE_FACTOR_NONE);
	CREATE_CONSTANT(GR_COMBINE_FACTOR_LOCAL);
	CREATE_CONSTANT(GR_COMBINE_FACTOR_OTHER_ALPHA);
	CREATE_CONSTANT(GR_COMBINE_FACTOR_LOCAL_ALPHA);
	CREATE_CONSTANT(GR_COMBINE_FACTOR_TEXTURE_ALPHA);
	CREATE_CONSTANT(GR_COMBINE_FACTOR_TEXTURE_RGB);
	CREATE_CONSTANT(GR_COMBINE_FACTOR_DETAIL_FACTOR);
	CREATE_CONSTANT(GR_COMBINE_FACTOR_LOD_FRACTION);
	CREATE_CONSTANT(GR_COMBINE_FACTOR_ONE);
	CREATE_CONSTANT(GR_COMBINE_FACTOR_ONE_MINUS_LOCAL);
	CREATE_CONSTANT(GR_COMBINE_FACTOR_ONE_MINUS_OTHER_ALPHA);
	CREATE_CONSTANT(GR_COMBINE_FACTOR_ONE_MINUS_LOCAL_ALPHA);
	CREATE_CONSTANT(GR_COMBINE_FACTOR_ONE_MINUS_TEXTURE_ALPHA);
	CREATE_CONSTANT(GR_COMBINE_FACTOR_ONE_MINUS_DETAIL_FACTOR);
	CREATE_CONSTANT(GR_COMBINE_FACTOR_ONE_MINUS_LOD_FRACTION);

	//typedef FxI32 GrCombineLocal_t;
	CREATE_CONSTANT(GR_COMBINE_LOCAL_ITERATED);
	CREATE_CONSTANT(GR_COMBINE_LOCAL_CONSTANT);
	CREATE_CONSTANT(GR_COMBINE_LOCAL_NONE);
	CREATE_CONSTANT(GR_COMBINE_LOCAL_DEPTH);

	//typedef FxI32 GrCombineOther_t;
	CREATE_CONSTANT(GR_COMBINE_OTHER_ITERATED);
	CREATE_CONSTANT(GR_COMBINE_OTHER_TEXTURE);
	CREATE_CONSTANT(GR_COMBINE_OTHER_CONSTANT);
	CREATE_CONSTANT(GR_COMBINE_OTHER_NONE);

	//typedef FxI32 GrAlphaSource_t;
	CREATE_CONSTANT(GR_ALPHASOURCE_CC_ALPHA);
	CREATE_CONSTANT(GR_ALPHASOURCE_ITERATED_ALPHA);
	CREATE_CONSTANT(GR_ALPHASOURCE_TEXTURE_ALPHA);
	CREATE_CONSTANT(GR_ALPHASOURCE_TEXTURE_ALPHA_TIMES_ITERATED_ALPHA);

	//typedef FxI32 GrColorCombineFnc_t;
	CREATE_CONSTANT(GR_COLORCOMBINE_ZERO);
	CREATE_CONSTANT(GR_COLORCOMBINE_CCRGB);
	CREATE_CONSTANT(GR_COLORCOMBINE_ITRGB);
	CREATE_CONSTANT(GR_COLORCOMBINE_ITRGB_DELTA0);
	CREATE_CONSTANT(GR_COLORCOMBINE_DECAL_TEXTURE);
	CREATE_CONSTANT(GR_COLORCOMBINE_TEXTURE_TIMES_CCRGB);
	CREATE_CONSTANT(GR_COLORCOMBINE_TEXTURE_TIMES_ITRGB);
	CREATE_CONSTANT(GR_COLORCOMBINE_TEXTURE_TIMES_ITRGB_DELTA0);
	CREATE_CONSTANT(GR_COLORCOMBINE_TEXTURE_TIMES_ITRGB_ADD_ALPHA);
	CREATE_CONSTANT(GR_COLORCOMBINE_TEXTURE_TIMES_ALPHA);
	CREATE_CONSTANT(GR_COLORCOMBINE_TEXTURE_TIMES_ALPHA_ADD_ITRGB);
	CREATE_CONSTANT(GR_COLORCOMBINE_TEXTURE_ADD_ITRGB);
	CREATE_CONSTANT(GR_COLORCOMBINE_TEXTURE_SUB_ITRGB);
	CREATE_CONSTANT(GR_COLORCOMBINE_CCRGB_BLEND_ITRGB_ON_TEXALPHA);
	CREATE_CONSTANT(GR_COLORCOMBINE_DIFF_SPEC_A);
	CREATE_CONSTANT(GR_COLORCOMBINE_DIFF_SPEC_B);
	CREATE_CONSTANT(GR_COLORCOMBINE_ONE);

	//typedef FxI32 GrAlphaBlendFnc_t;
	CREATE_CONSTANT(GR_BLEND_ZERO);
	CREATE_CONSTANT(GR_BLEND_SRC_ALPHA);
	CREATE_CONSTANT(GR_BLEND_SRC_COLOR);
	CREATE_CONSTANT(GR_BLEND_DST_COLOR);
	CREATE_CONSTANT(GR_BLEND_DST_ALPHA);
	CREATE_CONSTANT(GR_BLEND_ONE);
	CREATE_CONSTANT(GR_BLEND_ONE_MINUS_SRC_ALPHA);
	CREATE_CONSTANT(GR_BLEND_ONE_MINUS_SRC_COLOR);
	CREATE_CONSTANT(GR_BLEND_ONE_MINUS_DST_COLOR);
	CREATE_CONSTANT(GR_BLEND_ONE_MINUS_DST_ALPHA);
	CREATE_CONSTANT(GR_BLEND_RESERVED_8);
	CREATE_CONSTANT(GR_BLEND_RESERVED_9);
	CREATE_CONSTANT(GR_BLEND_RESERVED_A);
	CREATE_CONSTANT(GR_BLEND_RESERVED_B);
	CREATE_CONSTANT(GR_BLEND_RESERVED_C);
	CREATE_CONSTANT(GR_BLEND_RESERVED_D);
	CREATE_CONSTANT(GR_BLEND_RESERVED_E);
	CREATE_CONSTANT(GR_BLEND_ALPHA_SATURATE);
	CREATE_CONSTANT(GR_BLEND_PREFOG_COLOR);

	//typedef FxI32 GrAspectRatio_t;
	CREATE_CONSTANT(GR_ASPECT_LOG2_8x1);
	CREATE_CONSTANT(GR_ASPECT_LOG2_4x1);
	CREATE_CONSTANT(GR_ASPECT_LOG2_2x1);
	CREATE_CONSTANT(GR_ASPECT_LOG2_1x1);
	CREATE_CONSTANT(GR_ASPECT_LOG2_1x2);
	CREATE_CONSTANT(GR_ASPECT_LOG2_1x4);
	CREATE_CONSTANT(GR_ASPECT_LOG2_1x8);

	//typedef FxI32 GrBuffer_t;
	CREATE_CONSTANT(GR_BUFFER_FRONTBUFFER);
	CREATE_CONSTANT(GR_BUFFER_BACKBUFFER);
	CREATE_CONSTANT(GR_BUFFER_AUXBUFFER);
	CREATE_CONSTANT(GR_BUFFER_DEPTHBUFFER);
	CREATE_CONSTANT(GR_BUFFER_ALPHABUFFER);
	CREATE_CONSTANT(GR_BUFFER_TRIPLEBUFFER);

	//typedef FxI32 GrChromakeyMode_t;
	CREATE_CONSTANT(GR_CHROMAKEY_DISABLE);
	CREATE_CONSTANT(GR_CHROMAKEY_ENABLE);

	//typedef FxI32 GrChromaRangeMode_t;
	CREATE_CONSTANT(GR_CHROMARANGE_RGB_ALL_EXT);
	CREATE_CONSTANT(GR_CHROMARANGE_DISABLE_EXT);
	CREATE_CONSTANT(GR_CHROMARANGE_ENABLE_EXT);

	//typedef FxI32 GrTexChromakeyMode_t;
	CREATE_CONSTANT(GR_TEXCHROMA_DISABLE_EXT);
	CREATE_CONSTANT(GR_TEXCHROMA_ENABLE_EXT);
	CREATE_CONSTANT(GR_TEXCHROMARANGE_RGB_ALL_EXT);

	//typedef FxI32 GrCmpFnc_t;
	CREATE_CONSTANT(GR_CMP_NEVER);
	CREATE_CONSTANT(GR_CMP_LESS);
	CREATE_CONSTANT(GR_CMP_EQUAL);
	CREATE_CONSTANT(GR_CMP_LEQUAL);
	CREATE_CONSTANT(GR_CMP_GREATER);
	CREATE_CONSTANT(GR_CMP_NOTEQUAL);
	CREATE_CONSTANT(GR_CMP_GEQUAL);
	CREATE_CONSTANT(GR_CMP_ALWAYS);

	//typedef FxI32 GrColorFormat_t;
	CREATE_CONSTANT(GR_COLORFORMAT_ARGB);
	CREATE_CONSTANT(GR_COLORFORMAT_ABGR);
	CREATE_CONSTANT(GR_COLORFORMAT_RGBA);
	CREATE_CONSTANT(GR_COLORFORMAT_BGRA);

	//typedef FxI32 GrCullMode_t;
	CREATE_CONSTANT(GR_CULL_DISABLE);
	CREATE_CONSTANT(GR_CULL_NEGATIVE);
	CREATE_CONSTANT(GR_CULL_POSITIVE);

	//typedef FxI32 GrDepthBufferMode_t;
	CREATE_CONSTANT(GR_DEPTHBUFFER_DISABLE);
	CREATE_CONSTANT(GR_DEPTHBUFFER_ZBUFFER);
	CREATE_CONSTANT(GR_DEPTHBUFFER_WBUFFER);
	CREATE_CONSTANT(GR_DEPTHBUFFER_ZBUFFER_COMPARE_TO_BIAS);
	CREATE_CONSTANT(GR_DEPTHBUFFER_WBUFFER_COMPARE_TO_BIAS);

	//typedef FxI32 GrDitherMode_t;
	CREATE_CONSTANT(GR_DITHER_DISABLE);
	CREATE_CONSTANT(GR_DITHER_2x2);
	CREATE_CONSTANT(GR_DITHER_4x4);

	//typedef FxI32 GrFogMode_t;
	CREATE_CONSTANT(GR_FOG_DISABLE);
	CREATE_CONSTANT(GR_FOG_WITH_TABLE_ON_FOGCOORD_EXT);
	CREATE_CONSTANT(GR_FOG_WITH_TABLE_ON_Q);
	CREATE_CONSTANT(GR_FOG_WITH_TABLE_ON_W);
	CREATE_CONSTANT(GR_FOG_WITH_ITERATED_Z);
	CREATE_CONSTANT(GR_FOG_MULT2);
	CREATE_CONSTANT(GR_FOG_ADD2);

	//typedef FxU32 GrLock_t;
	CREATE_CONSTANT(GR_LFB_READ_ONLY);
	CREATE_CONSTANT(GR_LFB_WRITE_ONLY);
	CREATE_CONSTANT(GR_LFB_IDLE);
	CREATE_CONSTANT(GR_LFB_NOIDLE);

	//typedef FxI32 GrLfbBypassMode_t;
	CREATE_CONSTANT(GR_LFBBYPASS_DISABLE);
	CREATE_CONSTANT(GR_LFBBYPASS_ENABLE);

	//typedef FxI32 GrLfbWriteMode_t;
	CREATE_CONSTANT(GR_LFBWRITEMODE_565);
	CREATE_CONSTANT(GR_LFBWRITEMODE_555);
	CREATE_CONSTANT(GR_LFBWRITEMODE_1555);
	CREATE_CONSTANT(GR_LFBWRITEMODE_RESERVED1);
	CREATE_CONSTANT(GR_LFBWRITEMODE_888);
	CREATE_CONSTANT(GR_LFBWRITEMODE_8888);
	CREATE_CONSTANT(GR_LFBWRITEMODE_RESERVED2);
	CREATE_CONSTANT(GR_LFBWRITEMODE_RESERVED3);
	CREATE_CONSTANT(GR_LFBWRITEMODE_RESERVED4);
	CREATE_CONSTANT(GR_LFBWRITEMODE_RESERVED5);
	CREATE_CONSTANT(GR_LFBWRITEMODE_RESERVED6);
	CREATE_CONSTANT(GR_LFBWRITEMODE_RESERVED7);
	CREATE_CONSTANT(GR_LFBWRITEMODE_565_DEPTH);
	CREATE_CONSTANT(GR_LFBWRITEMODE_555_DEPTH);
	CREATE_CONSTANT(GR_LFBWRITEMODE_1555_DEPTH);
	CREATE_CONSTANT(GR_LFBWRITEMODE_ZA16);
	CREATE_CONSTANT(GR_LFBWRITEMODE_ANY);

	//typedef FxI32 GrOriginLocation_t;
	CREATE_CONSTANT(GR_ORIGIN_UPPER_LEFT);
	CREATE_CONSTANT(GR_ORIGIN_LOWER_LEFT);
	CREATE_CONSTANT(GR_ORIGIN_ANY);

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
	CREATE_CONSTANT(GR_LOD_LOG2_256);
	CREATE_CONSTANT(GR_LOD_LOG2_128);
	CREATE_CONSTANT(GR_LOD_LOG2_64);
	CREATE_CONSTANT(GR_LOD_LOG2_32);
	CREATE_CONSTANT(GR_LOD_LOG2_16);
	CREATE_CONSTANT(GR_LOD_LOG2_8);
	CREATE_CONSTANT(GR_LOD_LOG2_4);
	CREATE_CONSTANT(GR_LOD_LOG2_2);
	CREATE_CONSTANT(GR_LOD_LOG2_1);

	//typedef FxI32 GrMipMapMode_t;
	CREATE_CONSTANT(GR_MIPMAP_DISABLE);
	CREATE_CONSTANT(GR_MIPMAP_NEAREST);
	CREATE_CONSTANT(GR_MIPMAP_NEAREST_DITHER);

	//typedef FxI32 GrSmoothingMode_t;
	CREATE_CONSTANT(GR_SMOOTHING_DISABLE);
	CREATE_CONSTANT(GR_SMOOTHING_ENABLE);

	//typedef FxI32 GrTextureClampMode_t;
	CREATE_CONSTANT(GR_TEXTURECLAMP_WRAP);
	CREATE_CONSTANT(GR_TEXTURECLAMP_CLAMP);
	CREATE_CONSTANT(GR_TEXTURECLAMP_MIRROR_EXT);

	//typedef FxI32 GrTextureCombineFnc_t;
	CREATE_CONSTANT(GR_TEXTURECOMBINE_ZERO);
	CREATE_CONSTANT(GR_TEXTURECOMBINE_DECAL);
	CREATE_CONSTANT(GR_TEXTURECOMBINE_OTHER);
	CREATE_CONSTANT(GR_TEXTURECOMBINE_ADD);
	CREATE_CONSTANT(GR_TEXTURECOMBINE_MULTIPLY);
	CREATE_CONSTANT(GR_TEXTURECOMBINE_SUBTRACT);
	CREATE_CONSTANT(GR_TEXTURECOMBINE_DETAIL);
	CREATE_CONSTANT(GR_TEXTURECOMBINE_DETAIL_OTHER);
	CREATE_CONSTANT(GR_TEXTURECOMBINE_TRILINEAR_ODD);
	CREATE_CONSTANT(GR_TEXTURECOMBINE_TRILINEAR_EVEN);
	CREATE_CONSTANT(GR_TEXTURECOMBINE_ONE);

	//typedef FxI32 GrTextureFilterMode_t;
	CREATE_CONSTANT(GR_TEXTUREFILTER_POINT_SAMPLED);
	CREATE_CONSTANT(GR_TEXTUREFILTER_BILINEAR);

	//typedef FxI32 GrTextureFormat_t;
	CREATE_CONSTANT(GR_TEXFMT_8BIT);
	CREATE_CONSTANT(GR_TEXFMT_RGB_332);
	CREATE_CONSTANT(GR_TEXFMT_YIQ_422);
	CREATE_CONSTANT(GR_TEXFMT_ALPHA_8);
	CREATE_CONSTANT(GR_TEXFMT_INTENSITY_8);
	CREATE_CONSTANT(GR_TEXFMT_ALPHA_INTENSITY_44);
	CREATE_CONSTANT(GR_TEXFMT_P_8);
	CREATE_CONSTANT(GR_TEXFMT_RSVD0);
	CREATE_CONSTANT(GR_TEXFMT_RSVD1);
	CREATE_CONSTANT(GR_TEXFMT_16BIT);
	CREATE_CONSTANT(GR_TEXFMT_ARGB_8332);
	CREATE_CONSTANT(GR_TEXFMT_AYIQ_8422);
	CREATE_CONSTANT(GR_TEXFMT_RGB_565);
	CREATE_CONSTANT(GR_TEXFMT_ARGB_1555);
	CREATE_CONSTANT(GR_TEXFMT_ARGB_4444);
	CREATE_CONSTANT(GR_TEXFMT_ALPHA_INTENSITY_88);
	CREATE_CONSTANT(GR_TEXFMT_AP_88);
	CREATE_CONSTANT(GR_TEXFMT_RSVD2);

	//typedef FxU32 GrTexTable_t;
	CREATE_CONSTANT(GR_TEXTABLE_NCC0);
	CREATE_CONSTANT(GR_TEXTABLE_NCC1);
	CREATE_CONSTANT(GR_TEXTABLE_PALETTE);
	CREATE_CONSTANT(GR_TEXTABLE_PALETTE_6666_EXT);

	//typedef FxU32 GrNCCTable_t;
	CREATE_CONSTANT(GR_NCCTABLE_NCC0);
	CREATE_CONSTANT(GR_NCCTABLE_NCC1);

	//typedef FxU32 GrTexBaseRange_t;
	CREATE_CONSTANT(GR_TEXBASE_256);
	CREATE_CONSTANT(GR_TEXBASE_128);
	CREATE_CONSTANT(GR_TEXBASE_64);
	CREATE_CONSTANT(GR_TEXBASE_32_TO_1);

	//typedef FxU32 GrEnableMode_t;
	CREATE_CONSTANT(GR_MODE_DISABLE);
	CREATE_CONSTANT(GR_MODE_ENABLE);
	CREATE_CONSTANT(GR_AA_ORDERED);
	CREATE_CONSTANT(GR_ALLOW_MIPMAP_DITHER);
	CREATE_CONSTANT(GR_PASSTHRU);
	CREATE_CONSTANT(GR_SHAMELESS_PLUG);
	CREATE_CONSTANT(GR_VIDEO_SMOOTHING);

	//typedef FxU32 GrCoordinateSpaceMode_t;
	CREATE_CONSTANT(GR_WINDOW_COORDS);
	CREATE_CONSTANT(GR_CLIP_COORDS);

	/* Types of data in strips */
	CREATE_CONSTANT(GR_FLOAT);
	CREATE_CONSTANT(GR_U8);

	/* Parameters for strips */
	CREATE_CONSTANT(GR_PARAM_XY);
	CREATE_CONSTANT(GR_PARAM_Z);
	CREATE_CONSTANT(GR_PARAM_W);
	CREATE_CONSTANT(GR_PARAM_Q);
	CREATE_CONSTANT(GR_PARAM_FOG_EXT);

	CREATE_CONSTANT(GR_PARAM_A);

	CREATE_CONSTANT(GR_PARAM_RGB);

	CREATE_CONSTANT(GR_PARAM_PARGB);

	CREATE_CONSTANT(GR_PARAM_ST0);
	CREATE_CONSTANT(GR_PARAM_ST1);
	CREATE_CONSTANT(GR_PARAM_ST2);

	CREATE_CONSTANT(GR_PARAM_Q0);
	CREATE_CONSTANT(GR_PARAM_Q1);
	CREATE_CONSTANT(GR_PARAM_Q2);

	CREATE_CONSTANT(GR_PARAM_DISABLE);
	CREATE_CONSTANT(GR_PARAM_ENABLE);

	//grDrawVertexArray/grDrawVertexArrayContiguous primitive type
	CREATE_CONSTANT(GR_POINTS);
	CREATE_CONSTANT(GR_LINE_STRIP);
	CREATE_CONSTANT(GR_LINES);
	CREATE_CONSTANT(GR_POLYGON);
	CREATE_CONSTANT(GR_TRIANGLE_STRIP);
	CREATE_CONSTANT(GR_TRIANGLE_FAN);
	CREATE_CONSTANT(GR_TRIANGLES);
	CREATE_CONSTANT(GR_TRIANGLE_STRIP_CONTINUE);
	CREATE_CONSTANT(GR_TRIANGLE_FAN_CONTINUE);


	//grGet/grReset types
	CREATE_CONSTANT(GR_BITS_DEPTH);
	CREATE_CONSTANT(GR_BITS_RGBA);
	CREATE_CONSTANT(GR_BITS_GAMMA);
	CREATE_CONSTANT(GR_FIFO_FULLNESS);
	CREATE_CONSTANT(GR_FOG_TABLE_ENTRIES);
	CREATE_CONSTANT(GR_GAMMA_TABLE_ENTRIES);
	CREATE_CONSTANT(GR_GLIDE_STATE_SIZE);
	CREATE_CONSTANT(GR_GLIDE_VERTEXLAYOUT_SIZE);
	CREATE_CONSTANT(GR_IS_BUSY);
	CREATE_CONSTANT(GR_LFB_PIXEL_PIPE);
	CREATE_CONSTANT(GR_MAX_TEXTURE_SIZE);
	CREATE_CONSTANT(GR_MAX_TEXTURE_ASPECT_RATIO);
	CREATE_CONSTANT(GR_MEMORY_FB);
	CREATE_CONSTANT(GR_MEMORY_TMU);
	CREATE_CONSTANT(GR_MEMORY_UMA);
	CREATE_CONSTANT(GR_NON_POWER_OF_TWO_TEXTURES);
	CREATE_CONSTANT(GR_NUM_BOARDS);
	CREATE_CONSTANT(GR_NUM_FB);
	CREATE_CONSTANT(GR_NUM_SWAP_HISTORY_BUFFER);
	CREATE_CONSTANT(GR_NUM_TMU);
	CREATE_CONSTANT(GR_PENDING_BUFFERSWAPS);
	CREATE_CONSTANT(GR_REVISION_FB);
	CREATE_CONSTANT(GR_REVISION_TMU);
	CREATE_CONSTANT(GR_STATS_LINES);
	CREATE_CONSTANT(GR_STATS_PIXELS_AFUNC_FAIL);
	CREATE_CONSTANT(GR_STATS_PIXELS_CHROMA_FAIL);
	CREATE_CONSTANT(GR_STATS_PIXELS_DEPTHFUNC_FAIL);
	CREATE_CONSTANT(GR_STATS_PIXELS_IN);
	CREATE_CONSTANT(GR_STATS_PIXELS_OUT);
	CREATE_CONSTANT(GR_STATS_POINTS);
	CREATE_CONSTANT(GR_STATS_TRIANGLES_IN);
	CREATE_CONSTANT(GR_STATS_TRIANGLES_OUT);
	CREATE_CONSTANT(GR_SWAP_HISTORY);
	CREATE_CONSTANT(GR_SUPPORTS_PASSTHRU);
	CREATE_CONSTANT(GR_TEXTURE_ALIGN);
	CREATE_CONSTANT(GR_VIDEO_POSITION);
	CREATE_CONSTANT(GR_VIEWPORT);
	CREATE_CONSTANT(GR_WDEPTH_MIN_MAX);
	CREATE_CONSTANT(GR_ZDEPTH_MIN_MAX);

	//grGetString types
	CREATE_CONSTANT(GR_EXTENSION);
	CREATE_CONSTANT(GR_HARDWARE);
	CREATE_CONSTANT(GR_RENDERER);
	CREATE_CONSTANT(GR_VENDOR);
	CREATE_CONSTANT(GR_VERSION);















	//typedef FxI32 GrScreenRefresh_t
	CREATE_CONSTANT(GR_REFRESH_60Hz);
	CREATE_CONSTANT(GR_REFRESH_70Hz);
	CREATE_CONSTANT(GR_REFRESH_72Hz);
	CREATE_CONSTANT(GR_REFRESH_75Hz);
	CREATE_CONSTANT(GR_REFRESH_80Hz);
	CREATE_CONSTANT(GR_REFRESH_90Hz);
	CREATE_CONSTANT(GR_REFRESH_100Hz);
	CREATE_CONSTANT(GR_REFRESH_85Hz);
	CREATE_CONSTANT(GR_REFRESH_120Hz);
	CREATE_CONSTANT(GR_REFRESH_NONE);

	//typedef FxI32 GrScreenResolution_t;
	CREATE_CONSTANT(GR_RESOLUTION_320x200);
	CREATE_CONSTANT(GR_RESOLUTION_320x240);
	CREATE_CONSTANT(GR_RESOLUTION_400x256);
	CREATE_CONSTANT(GR_RESOLUTION_512x384);
	CREATE_CONSTANT(GR_RESOLUTION_640x200);
	CREATE_CONSTANT(GR_RESOLUTION_640x350);
	CREATE_CONSTANT(GR_RESOLUTION_640x400);
	CREATE_CONSTANT(GR_RESOLUTION_640x480);
	CREATE_CONSTANT(GR_RESOLUTION_800x600);
	CREATE_CONSTANT(GR_RESOLUTION_960x720);
	CREATE_CONSTANT(GR_RESOLUTION_856x480);
	CREATE_CONSTANT(GR_RESOLUTION_512x256);
	CREATE_CONSTANT(GR_RESOLUTION_1024x768);
	CREATE_CONSTANT(GR_RESOLUTION_1280x1024);
	CREATE_CONSTANT(GR_RESOLUTION_1600x1200);
	CREATE_CONSTANT(GR_RESOLUTION_400x300);
	CREATE_CONSTANT(GR_RESOLUTION_NONE);

	CREATE_CONSTANT(GR_RESOLUTION_MIN);
	CREATE_CONSTANT(GR_RESOLUTION_MAX);


	CREATE_CONSTANT(FXTRUE);
	CREATE_CONSTANT(FXFALSE);
}