<?php

/**
 * @generate-class-entries
 * @undocumentable
 */

enum GrCombineFunction_t {
	case GR_COMBINE_FUNCTION_ZERO;
	case GR_COMBINE_FUNCTION_NONE;
	case GR_COMBINE_FUNCTION_LOCAL;
	case GR_COMBINE_FUNCTION_LOCAL_ALPHA;
	case GR_COMBINE_FUNCTION_SCALE_OTHER;
	case GR_COMBINE_FUNCTION_BLEND_OTHER;
	case GR_COMBINE_FUNCTION_SCALE_OTHER_ADD_LOCAL;
	case GR_COMBINE_FUNCTION_SCALE_OTHER_ADD_LOCAL_ALPHA;
	case GR_COMBINE_FUNCTION_SCALE_OTHER_MINUS_LOCAL;
	case GR_COMBINE_FUNCTION_SCALE_OTHER_MINUS_LOCAL_ADD_LOCAL;
	case GR_COMBINE_FUNCTION_BLEND;
	case GR_COMBINE_FUNCTION_SCALE_OTHER_MINUS_LOCAL_ADD_LOCAL_ALPHA;
	case GR_COMBINE_FUNCTION_SCALE_MINUS_LOCAL_ADD_LOCAL;
	case GR_COMBINE_FUNCTION_BLEND_LOCAL;
	case GR_COMBINE_FUNCTION_SCALE_MINUS_LOCAL_ADD_LOCAL_ALPHA;
	
	public function toInt() : int;
}

enum GrCombineFactor_t {
	case GR_COMBINE_FACTOR_ZERO;
	case GR_COMBINE_FACTOR_NONE;
	case GR_COMBINE_FACTOR_LOCAL;
	case GR_COMBINE_FACTOR_OTHER_ALPHA;
	case GR_COMBINE_FACTOR_LOCAL_ALPHA;
	case GR_COMBINE_FACTOR_TEXTURE_ALPHA;
	case GR_COMBINE_FACTOR_TEXTURE_RGB;
	case GR_COMBINE_FACTOR_DETAIL_FACTOR;
	case GR_COMBINE_FACTOR_LOD_FRACTION;
	case GR_COMBINE_FACTOR_ONE;
	case GR_COMBINE_FACTOR_ONE_MINUS_LOCAL;
	case GR_COMBINE_FACTOR_ONE_MINUS_OTHER_ALPHA;
	case GR_COMBINE_FACTOR_ONE_MINUS_LOCAL_ALPHA;
	case GR_COMBINE_FACTOR_ONE_MINUS_TEXTURE_ALPHA;
	case GR_COMBINE_FACTOR_ONE_MINUS_DETAIL_FACTOR;
	case GR_COMBINE_FACTOR_ONE_MINUS_LOD_FRACTION;
	
	public function toInt() : int;
}

enum GrCombineLocal_t {
	case GR_COMBINE_LOCAL_ITERATED;
	case GR_COMBINE_LOCAL_CONSTANT;
	case GR_COMBINE_LOCAL_NONE;
	case GR_COMBINE_LOCAL_DEPTH;
	
	public function toInt() : int;
}

enum GrCombineOther_t {
	case GR_COMBINE_OTHER_ITERATED;
	case GR_COMBINE_OTHER_TEXTURE;
	case GR_COMBINE_OTHER_CONSTANT;
	case GR_COMBINE_OTHER_NONE;
	
	public function toInt() : int;
}

enum GrAlphaSource_t {
	case GR_ALPHASOURCE_CC_ALPHA;
	case GR_ALPHASOURCE_ITERATED_ALPHA;
	case GR_ALPHASOURCE_TEXTURE_ALPHA;
	case GR_ALPHASOURCE_TEXTURE_ALPHA_TIMES_ITERATED_ALPHA;
	
	public function toInt() : int;
}

enum GrColorCombineFnc_t {
	case GR_COLORCOMBINE_ZERO;
	case GR_COLORCOMBINE_CCRGB;
	case GR_COLORCOMBINE_ITRGB;
	case GR_COLORCOMBINE_ITRGB_DELTA0;
	case GR_COLORCOMBINE_DECAL_TEXTURE;
	case GR_COLORCOMBINE_TEXTURE_TIMES_CCRGB;
	case GR_COLORCOMBINE_TEXTURE_TIMES_ITRGB;
	case GR_COLORCOMBINE_TEXTURE_TIMES_ITRGB_DELTA0;
	case GR_COLORCOMBINE_TEXTURE_TIMES_ITRGB_ADD_ALPHA;
	case GR_COLORCOMBINE_TEXTURE_TIMES_ALPHA;
	case GR_COLORCOMBINE_TEXTURE_TIMES_ALPHA_ADD_ITRGB;
	case GR_COLORCOMBINE_TEXTURE_ADD_ITRGB;
	case GR_COLORCOMBINE_TEXTURE_SUB_ITRGB;
	case GR_COLORCOMBINE_CCRGB_BLEND_ITRGB_ON_TEXALPHA;
	case GR_COLORCOMBINE_DIFF_SPEC_A;
	case GR_COLORCOMBINE_DIFF_SPEC_B;
	case GR_COLORCOMBINE_ONE;
	
	public function toInt() : int;
}

enum GrAlphaBlendFnc_t {
	case GR_BLEND_ZERO;
	case GR_BLEND_SRC_ALPHA;
	case GR_BLEND_SRC_COLOR;
	case GR_BLEND_DST_COLOR;
	case GR_BLEND_DST_ALPHA;
	case GR_BLEND_ONE;
	case GR_BLEND_ONE_MINUS_SRC_ALPHA;
	case GR_BLEND_ONE_MINUS_SRC_COLOR;
	case GR_BLEND_ONE_MINUS_DST_COLOR;
	case GR_BLEND_ONE_MINUS_DST_ALPHA;
	case GR_BLEND_RESERVED_8;
	case GR_BLEND_RESERVED_9;
	case GR_BLEND_RESERVED_A;
	case GR_BLEND_RESERVED_B;
	case GR_BLEND_RESERVED_C;
	case GR_BLEND_RESERVED_D;
	case GR_BLEND_RESERVED_E;
	case GR_BLEND_ALPHA_SATURATE;
	case GR_BLEND_PREFOG_COLOR;
	
	public function toInt() : int;
}

enum GrAspectRatio_t {
	//typedef FxI32 GrAspectRatio_t;
	case GR_ASPECT_LOG2_8x1;
	case GR_ASPECT_LOG2_4x1;
	case GR_ASPECT_LOG2_2x1;
	case GR_ASPECT_LOG2_1x1;
	case GR_ASPECT_LOG2_1x2;
	case GR_ASPECT_LOG2_1x4;
	case GR_ASPECT_LOG2_1x8;
	
	public function toInt() : int;
}

enum GrBuffer_t {
	//typedef FxI32 GrBuffer_t;
	case GR_BUFFER_FRONTBUFFER;
	case GR_BUFFER_BACKBUFFER;
	case GR_BUFFER_AUXBUFFER;
	case GR_BUFFER_DEPTHBUFFER;
	case GR_BUFFER_ALPHABUFFER;
	case GR_BUFFER_TRIPLEBUFFER;
	
	public function toInt() : int;
}

enum GrChromakeyMode_t {
	//typedef FxI32 GrChromakeyMode_t;
	case GR_CHROMAKEY_DISABLE;
	case GR_CHROMAKEY_ENABLE;
	
	public function toInt() : int;
}

enum GrChromaRangeMode_t {
	//typedef FxI32 GrChromaRangeMode_t;
	case GR_CHROMARANGE_RGB_ALL_EXT;
	case GR_CHROMARANGE_DISABLE_EXT;
	case GR_CHROMARANGE_ENABLE_EXT;
	
	public function toInt() : int;
}

enum GrTexChromakeyMode_t {
	//typedef FxI32 GrTexChromakeyMode_t;
	case GR_TEXCHROMA_DISABLE_EXT;
	case GR_TEXCHROMA_ENABLE_EXT;
	case GR_TEXCHROMARANGE_RGB_ALL_EXT;
	
	public function toInt() : int;
}

enum GrCmpFnc_t {
	//typedef FxI32 GrCmpFnc_t;
	case GR_CMP_NEVER;
	case GR_CMP_LESS;
	case GR_CMP_EQUAL;
	case GR_CMP_LEQUAL;
	case GR_CMP_GREATER;
	case GR_CMP_NOTEQUAL;
	case GR_CMP_GEQUAL;
	case GR_CMP_ALWAYS;
	
	public function toInt() : int;
}

enum GrColorFormat_t {
	//typedef FxI32 GrColorFormat_t;
	case GR_COLORFORMAT_ARGB;
	case GR_COLORFORMAT_ABGR;
	case GR_COLORFORMAT_RGBA;
	case GR_COLORFORMAT_BGRA;
	
	public function toInt() : int;
}

enum GrCullMode_t {
	//typedef FxI32 GrCullMode_t;
	case GR_CULL_DISABLE;
	case GR_CULL_NEGATIVE;
	case GR_CULL_POSITIVE;
	
	public function toInt() : int;
}

enum GrDepthBufferMode_t {
	//typedef FxI32 GrDepthBufferMode_t;
	case GR_DEPTHBUFFER_DISABLE;
	case GR_DEPTHBUFFER_ZBUFFER;
	case GR_DEPTHBUFFER_WBUFFER;
	case GR_DEPTHBUFFER_ZBUFFER_COMPARE_TO_BIAS;
	case GR_DEPTHBUFFER_WBUFFER_COMPARE_TO_BIAS;
	
	public function toInt() : int;
}

enum GrDitherMode_t {
	//typedef FxI32 GrDitherMode_t;
	case GR_DITHER_DISABLE;
	case GR_DITHER_2x2;
	case GR_DITHER_4x4;
	
	public function toInt() : int;
}

enum GrFogMode_t {
	//typedef FxI32 GrFogMode_t;
	case GR_FOG_DISABLE;
	case GR_FOG_WITH_TABLE_ON_FOGCOORD_EXT;
	case GR_FOG_WITH_TABLE_ON_Q;
	case GR_FOG_WITH_TABLE_ON_W;
	case GR_FOG_WITH_ITERATED_Z;
	case GR_FOG_MULT2;
	case GR_FOG_ADD2;
	
	public function toInt() : int;
}

enum GrLock_t {
	//typedef FxU32 GrLock_t;
	case GR_LFB_READ_ONLY;
	case GR_LFB_WRITE_ONLY;
	case GR_LFB_IDLE;
	case GR_LFB_NOIDLE;
	
	public function toInt() : int;
}

enum GrLfbBypassMode_t {
	//typedef FxI32 GrLfbBypassMode_t;
	case GR_LFBBYPASS_DISABLE;
	case GR_LFBBYPASS_ENABLE;
	
	public function toInt() : int;
}

enum GrLfbWriteMode_t {
	//typedef FxI32 GrLfbWriteMode_t;
	case GR_LFBWRITEMODE_565;
	case GR_LFBWRITEMODE_555;
	case GR_LFBWRITEMODE_1555;
	case GR_LFBWRITEMODE_RESERVED1;
	case GR_LFBWRITEMODE_888;
	case GR_LFBWRITEMODE_8888;
	case GR_LFBWRITEMODE_RESERVED2;
	case GR_LFBWRITEMODE_RESERVED3;
	case GR_LFBWRITEMODE_RESERVED4;
	case GR_LFBWRITEMODE_RESERVED5;
	case GR_LFBWRITEMODE_RESERVED6;
	case GR_LFBWRITEMODE_RESERVED7;
	case GR_LFBWRITEMODE_565_DEPTH;
	case GR_LFBWRITEMODE_555_DEPTH;
	case GR_LFBWRITEMODE_1555_DEPTH;
	case GR_LFBWRITEMODE_ZA16;
	case GR_LFBWRITEMODE_ANY;
	
	public function toInt() : int;
}

enum GrOriginLocation_t {
	//typedef FxI32 GrOriginLocation_t;
	case GR_ORIGIN_UPPER_LEFT;
	case GR_ORIGIN_LOWER_LEFT;
	case GR_ORIGIN_ANY;
	
	public function toInt() : int;
}

enum GrLOD_t {
	case GR_LOD_LOG2_256;
	case GR_LOD_LOG2_128;
	case GR_LOD_LOG2_64;
	case GR_LOD_LOG2_32;
	case GR_LOD_LOG2_16;
	case GR_LOD_LOG2_8;
	case GR_LOD_LOG2_4;
	case GR_LOD_LOG2_2;
	case GR_LOD_LOG2_1;
	
	public function toInt() : int;
}

enum GrMipMapMode_t {
	//typedef FxI32 GrMipMapMode_t;
	case GR_MIPMAP_DISABLE;
	case GR_MIPMAP_NEAREST;
	case GR_MIPMAP_NEAREST_DITHER;
	
	public function toInt() : int;
}

enum GrSmoothingMode_t {
	//typedef FxI32 GrSmoothingMode_t;
	case GR_SMOOTHING_DISABLE;
	case GR_SMOOTHING_ENABLE;
	
	public function toInt() : int;
}

enum GrTextureClampMode_t {
	//typedef FxI32 GrTextureClampMode_t;
	case GR_TEXTURECLAMP_WRAP;
	case GR_TEXTURECLAMP_CLAMP;
	case GR_TEXTURECLAMP_MIRROR_EXT;
	
	public function toInt() : int;
}

enum GrTextureCombineFnc_t {
	//typedef FxI32 GrTextureCombineFnc_t;
	case GR_TEXTURECOMBINE_ZERO;
	case GR_TEXTURECOMBINE_DECAL;
	case GR_TEXTURECOMBINE_OTHER;
	case GR_TEXTURECOMBINE_ADD;
	case GR_TEXTURECOMBINE_MULTIPLY;
	case GR_TEXTURECOMBINE_SUBTRACT;
	case GR_TEXTURECOMBINE_DETAIL;
	case GR_TEXTURECOMBINE_DETAIL_OTHER;
	case GR_TEXTURECOMBINE_TRILINEAR_ODD;
	case GR_TEXTURECOMBINE_TRILINEAR_EVEN;
	case GR_TEXTURECOMBINE_ONE;
	
	public function toInt() : int;
}

enum GrTextureFilterMode_t {
	//typedef FxI32 GrTextureFilterMode_t;
	case GR_TEXTUREFILTER_POINT_SAMPLED;
	case GR_TEXTUREFILTER_BILINEAR;
	
	public function toInt() : int;
}

enum GrTextureFormat_t {
	//typedef FxI32 GrTextureFormat_t;
	case GR_TEXFMT_8BIT;
	case GR_TEXFMT_RGB_332;
	case GR_TEXFMT_YIQ_422;
	case GR_TEXFMT_ALPHA_8;
	case GR_TEXFMT_INTENSITY_8;
	case GR_TEXFMT_ALPHA_INTENSITY_44;
	case GR_TEXFMT_P_8;
	case GR_TEXFMT_RSVD0;
	case GR_TEXFMT_RSVD1;
	case GR_TEXFMT_16BIT;
	case GR_TEXFMT_ARGB_8332;
	case GR_TEXFMT_AYIQ_8422;
	case GR_TEXFMT_RGB_565;
	case GR_TEXFMT_ARGB_1555;
	case GR_TEXFMT_ARGB_4444;
	case GR_TEXFMT_ALPHA_INTENSITY_88;
	case GR_TEXFMT_AP_88;
	case GR_TEXFMT_RSVD2;
	
	public function toInt() : int;
}

enum GrTexTable_t {
	//typedef FxU32 GrTexTable_t;
	case GR_TEXTABLE_NCC0;
	case GR_TEXTABLE_NCC1;
	case GR_TEXTABLE_PALETTE;
	case GR_TEXTABLE_PALETTE_6666_EXT;
	
	public function toInt() : int;
}

enum GrNCCTable_t {
	case GR_NCCTABLE_NCC0;
	case GR_NCCTABLE_NCC1;
	
	public function toInt() : int;
}

enum GrTexBaseRange_t {
	//typedef FxU32 GrTexBaseRange_t;
	case GR_TEXBASE_256;
	case GR_TEXBASE_128;
	case GR_TEXBASE_64;
	case GR_TEXBASE_32_TO_1;
	
	public function toInt() : int;
}

enum GrEnableMode_t {
	//typedef FxU32 GrEnableMode_t;
	case GR_MODE_DISABLE;
	case GR_MODE_ENABLE;
	case GR_AA_ORDERED;
	case GR_ALLOW_MIPMAP_DITHER;
	case GR_PASSTHRU;
	case GR_SHAMELESS_PLUG;
	case GR_VIDEO_SMOOTHING;
	
	public function toInt() : int;
}

enum GrCoordinateSpaceMode_t {
	//typedef FxU32 GrCoordinateSpaceMode_t;
	case GR_WINDOW_COORDS;
	case GR_CLIP_COORDS;
	
	public function toInt() : int;
}

enum GrDataStrips_t {
	/* Types of data in strips */
	case GR_FLOAT;
	case GR_U8;
	
	public function toInt() : int;
}

enum GrParams_t {
	/* Parameters for strips */
	case GR_PARAM_XY;
	case GR_PARAM_Z;
	case GR_PARAM_W;
	case GR_PARAM_Q;
	case GR_PARAM_FOG_EXT;

	case GR_PARAM_A;

	case GR_PARAM_RGB;

	case GR_PARAM_PARGB;

	case GR_PARAM_ST0;
	case GR_PARAM_ST1;
	case GR_PARAM_ST2;

	case GR_PARAM_Q0;
	case GR_PARAM_Q1;
	case GR_PARAM_Q2;
	
	public function toInt() : int;
}

enum GrMode_t {
	case GR_PARAM_DISABLE;
	case GR_PARAM_ENABLE;
	
	public function toInt() : int;
}

abstract class AbstractVertex {
	public float $x;
	public float $y;
}

#ifdef _DEBUG
function testAbstractVertex(AbstractVertex $av) : void {};
#endif

enum GrVertex_t {
	//grDrawVertexArray/grDrawVertexArrayContiguous primitive type
	case GR_POINTS;
	case GR_LINE_STRIP;
	case GR_LINES;
	case GR_POLYGON;
	case GR_TRIANGLE_STRIP;
	case GR_TRIANGLE_FAN;
	case GR_TRIANGLES;
	case GR_TRIANGLE_STRIP_CONTINUE;
	case GR_TRIANGLE_FAN_CONTINUE;
	
	public function toInt() : int;
}


enum GrGet_t {
	//grGet/grReset types
	case GR_BITS_DEPTH;
	case GR_BITS_RGBA;
	case GR_BITS_GAMMA;
	case GR_FIFO_FULLNESS;
	case GR_FOG_TABLE_ENTRIES;
	case GR_GAMMA_TABLE_ENTRIES;
	case GR_GLIDE_STATE_SIZE;
	case GR_GLIDE_VERTEXLAYOUT_SIZE;
	case GR_IS_BUSY;
	case GR_LFB_PIXEL_PIPE;
	case GR_MAX_TEXTURE_SIZE;
	case GR_MAX_TEXTURE_ASPECT_RATIO;
	case GR_MEMORY_FB;
	case GR_MEMORY_TMU;
	case GR_MEMORY_UMA;
	case GR_NON_POWER_OF_TWO_TEXTURES;
	case GR_NUM_BOARDS;
	case GR_NUM_FB;
	case GR_NUM_SWAP_HISTORY_BUFFER;
	case GR_NUM_TMU;
	case GR_PENDING_BUFFERSWAPS;
	case GR_REVISION_FB;
	case GR_REVISION_TMU;
	case GR_STATS_LINES;
	case GR_STATS_PIXELS_AFUNC_FAIL;
	case GR_STATS_PIXELS_CHROMA_FAIL;
	case GR_STATS_PIXELS_DEPTHFUNC_FAIL;
	case GR_STATS_PIXELS_IN;
	case GR_STATS_PIXELS_OUT;
	case GR_STATS_POINTS;
	case GR_STATS_TRIANGLES_IN;
	case GR_STATS_TRIANGLES_OUT;
	case GR_SWAP_HISTORY;
	case GR_SUPPORTS_PASSTHRU;
	case GR_TEXTURE_ALIGN;
	case GR_VIDEO_POSITION;
	case GR_VIEWPORT;
	case GR_WDEPTH_MIN_MAX;
	case GR_ZDEPTH_MIN_MAX;
	
	public function toInt() : int;
}

enum GrString_t {
	//grGetString types
	case GR_EXTENSION;
	case GR_HARDWARE;
	case GR_RENDERER;
	case GR_VENDOR;
	case GR_VERSION;
	
	public function toInt() : int;
}

enum GrScreenRefresh_t {
	//typedef FxI32 GrScreenRefresh_t
	case GR_REFRESH_60Hz;
	case GR_REFRESH_70Hz;
	case GR_REFRESH_72Hz;
	case GR_REFRESH_75Hz;
	case GR_REFRESH_80Hz;
	case GR_REFRESH_90Hz;
	case GR_REFRESH_100Hz;
	case GR_REFRESH_85Hz;
	case GR_REFRESH_120Hz;
	case GR_REFRESH_NONE;
	
	public function toInt() : int;
}

enum GrScreenResolution_t {
	//typedef FxI32 GrScreenResolution_t;
	case GR_RESOLUTION_320x200;
	case GR_RESOLUTION_320x240;
	case GR_RESOLUTION_400x256;
	case GR_RESOLUTION_512x384;
	case GR_RESOLUTION_640x200;
	case GR_RESOLUTION_640x350;
	case GR_RESOLUTION_640x400;
	case GR_RESOLUTION_640x480;
	case GR_RESOLUTION_800x600;
	case GR_RESOLUTION_960x720;
	case GR_RESOLUTION_856x480;
	case GR_RESOLUTION_512x256;
	case GR_RESOLUTION_1024x768;
	case GR_RESOLUTION_1280x1024;
	case GR_RESOLUTION_1600x1200;
	case GR_RESOLUTION_400x300;
	case GR_RESOLUTION_NONE;

	case GR_RESOLUTION_MIN;
	case GR_RESOLUTION_MAX;
	
	public function toInt() : int;
}


function _kbhit() : int {};

function grGlideInit() : void {};

function grGlideShutdown() : void {};

function grVertexLayout(GrParams_t $param, int $offset, GrMode_t $mode) : void {};

function grConstantColorValue(int $color) : void {};

function grGet(GrGet_t $pname, mixed &$params, ?int $plength = null) : int {};

function grGetString(GrString_t $name) : ?string {};

function grDrawTriangle(object $a, object $b, object $c) : void {};

function grBufferClear(int $color, int $alpha, int $depth) : void {};

function grBufferSwap(int $swap_interval) : void {};

function grColorCombine(GrCombineFunction_t $func, GrCombineFactor_t $factor, GrCombineLocal_t $local, GrCombineOther_t $other, bool $invert) : void {};

function grColorMask(bool $rgb, bool $alpha) : void {};

function grSstSelect(int $which_sst) : void {};

function grSstWinClose(int $context): bool {};

function grSstWinOpen(?int $hWin, GrScreenResolution_t $res, GrScreenRefresh_t $ref, GrColorFormat_t $cFormat, GrOriginLocation_t $org_loc, int $num_buffers, int $num_aux_buffers) : int {};