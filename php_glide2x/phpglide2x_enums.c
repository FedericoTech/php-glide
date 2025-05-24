
#include "phpglide2x_enums.h"

#define SET_CASE(c) {#c, c}

#define CREATE_CONSTANT(v) REGISTER_LONG_CONSTANT(#v, v, CONST_CS | CONST_PERSISTENT)

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

typedef struct {
	const char* name;
	int value;
} EnumValue;

struct {
	zend_class_entry* enum_entry;
	EnumValue* values;  // NULL-terminated (or name==NULL) sentinel array
} grouped_enums[] = {
	{
		NULL, //grDepth_ce
		(EnumValue[]) {
			//typedef FxI32 GrChipID_ce;
			SET_CASE(GR_ZDEPTHVALUE_NEAREST),
			SET_CASE(GR_ZDEPTHVALUE_FARTHEST),
			SET_CASE(GR_WDEPTHVALUE_NEAREST),
			SET_CASE(GR_WDEPTHVALUE_FARTHEST),
			{ NULL, 0 } // sentinel
		}
	},
	{
		NULL, //grEvenOdd_ce
		(EnumValue[]) {
			SET_CASE(GR_MIPMAPLEVELMASK_EVEN),
			SET_CASE(GR_MIPMAPLEVELMASK_ODD),
			SET_CASE(GR_MIPMAPLEVELMASK_BOTH),
			{ NULL, 0 } // sentinel
		}
	},
	{
		NULL, //grChipID_ce
		(EnumValue[]) {
			SET_CASE(GR_TMU0),
			SET_CASE(GR_TMU1),
			SET_CASE(GR_TMU2),
			SET_CASE(GR_FBI),
			{ NULL, 0 } // sentinel
		}
	},
	{
		NULL, //grCombineFunction_ce
		(EnumValue[]) {
			SET_CASE(GR_COMBINE_FUNCTION_ZERO),
			SET_CASE(GR_COMBINE_FUNCTION_NONE),
			SET_CASE(GR_COMBINE_FUNCTION_LOCAL),
			SET_CASE(GR_COMBINE_FUNCTION_LOCAL_ALPHA),
			SET_CASE(GR_COMBINE_FUNCTION_SCALE_OTHER),
			SET_CASE(GR_COMBINE_FUNCTION_BLEND_OTHER),
			SET_CASE(GR_COMBINE_FUNCTION_SCALE_OTHER_ADD_LOCAL),
			SET_CASE(GR_COMBINE_FUNCTION_SCALE_OTHER_ADD_LOCAL_ALPHA),
			SET_CASE(GR_COMBINE_FUNCTION_SCALE_OTHER_MINUS_LOCAL),
			SET_CASE(GR_COMBINE_FUNCTION_SCALE_OTHER_MINUS_LOCAL_ADD_LOCAL),
			SET_CASE(GR_COMBINE_FUNCTION_BLEND),
			SET_CASE(GR_COMBINE_FUNCTION_SCALE_OTHER_MINUS_LOCAL_ADD_LOCAL_ALPHA),
			SET_CASE(GR_COMBINE_FUNCTION_SCALE_MINUS_LOCAL_ADD_LOCAL),
			SET_CASE(GR_COMBINE_FUNCTION_BLEND_LOCAL),
			SET_CASE(GR_COMBINE_FUNCTION_SCALE_MINUS_LOCAL_ADD_LOCAL_ALPHA),
			{ NULL, 0 } // sentinel
		}
	},
	{
		NULL, //grCombineFactor_ce
		(EnumValue[]) {
			SET_CASE(GR_COMBINE_FACTOR_ZERO),
			SET_CASE(GR_COMBINE_FACTOR_NONE),
			SET_CASE(GR_COMBINE_FACTOR_LOCAL),
			SET_CASE(GR_COMBINE_FACTOR_OTHER_ALPHA),
			SET_CASE(GR_COMBINE_FACTOR_LOCAL_ALPHA),
			SET_CASE(GR_COMBINE_FACTOR_TEXTURE_ALPHA),
			SET_CASE(GR_COMBINE_FACTOR_TEXTURE_RGB),
			SET_CASE(GR_COMBINE_FACTOR_DETAIL_FACTOR),
			SET_CASE(GR_COMBINE_FACTOR_LOD_FRACTION),
			SET_CASE(GR_COMBINE_FACTOR_ONE),
			SET_CASE(GR_COMBINE_FACTOR_ONE_MINUS_LOCAL),
			SET_CASE(GR_COMBINE_FACTOR_ONE_MINUS_OTHER_ALPHA),
			SET_CASE(GR_COMBINE_FACTOR_ONE_MINUS_LOCAL_ALPHA),
			SET_CASE(GR_COMBINE_FACTOR_ONE_MINUS_TEXTURE_ALPHA),
			SET_CASE(GR_COMBINE_FACTOR_ONE_MINUS_DETAIL_FACTOR),
			SET_CASE(GR_COMBINE_FACTOR_ONE_MINUS_LOD_FRACTION),
			{ NULL, 0 } // sentinel
		}
	},
	{
		NULL, //grCombineLocal_ce
		(EnumValue[]) {
			SET_CASE(GR_COMBINE_LOCAL_ITERATED),
			SET_CASE(GR_COMBINE_LOCAL_CONSTANT),
			SET_CASE(GR_COMBINE_LOCAL_NONE),
			SET_CASE(GR_COMBINE_LOCAL_DEPTH),
			{ NULL, 0 } // sentinel
		}
	},
	{
		NULL, //grCombineOther_ce
		(EnumValue[]) {
			SET_CASE(GR_COMBINE_OTHER_ITERATED),
			SET_CASE(GR_COMBINE_OTHER_TEXTURE),
			SET_CASE(GR_COMBINE_OTHER_CONSTANT),
			SET_CASE(GR_COMBINE_OTHER_NONE),
			{ NULL, 0 } // sentinel
		}
	},
	{
		NULL, //grAlphaSource_ce
		(EnumValue[]) {
			SET_CASE(GR_ALPHASOURCE_CC_ALPHA),
			SET_CASE(GR_ALPHASOURCE_ITERATED_ALPHA),
			SET_CASE(GR_ALPHASOURCE_TEXTURE_ALPHA),
			SET_CASE(GR_ALPHASOURCE_TEXTURE_ALPHA_TIMES_ITERATED_ALPHA),
			{ NULL, 0 } // sentinel
		}
	},
	{
		NULL, //grColorCombineFnc_ce
		(EnumValue[]) {
			SET_CASE(GR_COLORCOMBINE_ZERO),
			SET_CASE(GR_COLORCOMBINE_CCRGB),
			SET_CASE(GR_COLORCOMBINE_ITRGB),
			SET_CASE(GR_COLORCOMBINE_ITRGB_DELTA0),
			SET_CASE(GR_COLORCOMBINE_DECAL_TEXTURE),
			SET_CASE(GR_COLORCOMBINE_TEXTURE_TIMES_CCRGB),
			SET_CASE(GR_COLORCOMBINE_TEXTURE_TIMES_ITRGB),
			SET_CASE(GR_COLORCOMBINE_TEXTURE_TIMES_ITRGB_DELTA0),
			SET_CASE(GR_COLORCOMBINE_TEXTURE_TIMES_ITRGB_ADD_ALPHA),
			SET_CASE(GR_COLORCOMBINE_TEXTURE_TIMES_ALPHA),
			SET_CASE(GR_COLORCOMBINE_TEXTURE_TIMES_ALPHA_ADD_ITRGB),
			SET_CASE(GR_COLORCOMBINE_TEXTURE_ADD_ITRGB),
			SET_CASE(GR_COLORCOMBINE_TEXTURE_SUB_ITRGB),
			SET_CASE(GR_COLORCOMBINE_CCRGB_BLEND_ITRGB_ON_TEXALPHA),
			SET_CASE(GR_COLORCOMBINE_DIFF_SPEC_A),
			SET_CASE(GR_COLORCOMBINE_DIFF_SPEC_B),
			SET_CASE(GR_COLORCOMBINE_ONE),
			{ NULL, 0 } // sentinel
		}
	},
	{
		NULL, //grAlphaBlendFnc_ce
		(EnumValue[]) {
			SET_CASE(GR_BLEND_ZERO),
			SET_CASE(GR_BLEND_SRC_ALPHA),
			SET_CASE(GR_BLEND_SRC_COLOR),
			SET_CASE(GR_BLEND_DST_COLOR),
			SET_CASE(GR_BLEND_DST_ALPHA),
			SET_CASE(GR_BLEND_ONE),
			SET_CASE(GR_BLEND_ONE_MINUS_SRC_ALPHA),
			SET_CASE(GR_BLEND_ONE_MINUS_SRC_COLOR),
			SET_CASE(GR_BLEND_ONE_MINUS_DST_COLOR),
			SET_CASE(GR_BLEND_ONE_MINUS_DST_ALPHA),
			SET_CASE(GR_BLEND_RESERVED_8),
			SET_CASE(GR_BLEND_RESERVED_9),
			SET_CASE(GR_BLEND_RESERVED_A),
			SET_CASE(GR_BLEND_RESERVED_B),
			SET_CASE(GR_BLEND_RESERVED_C),
			SET_CASE(GR_BLEND_RESERVED_D),
			SET_CASE(GR_BLEND_RESERVED_E),
			SET_CASE(GR_BLEND_ALPHA_SATURATE),
			SET_CASE(GR_BLEND_PREFOG_COLOR),
			{ NULL, 0 } // sentinel
		}
	},
	{
		NULL, //grAspectRatio_ce
		(EnumValue[]) {
			SET_CASE(GR_ASPECT_8x1),
			SET_CASE(GR_ASPECT_4x1),
			SET_CASE(GR_ASPECT_2x1),
			SET_CASE(GR_ASPECT_1x1),
			SET_CASE(GR_ASPECT_1x2),
			SET_CASE(GR_ASPECT_1x4),
			SET_CASE(GR_ASPECT_1x8),
			{ NULL, 0 } // sentinel
		}
	},
	{
		NULL, //grBuffer_ce
		(EnumValue[]) {
			SET_CASE(GR_BUFFER_FRONTBUFFER),
			SET_CASE(GR_BUFFER_BACKBUFFER),
			SET_CASE(GR_BUFFER_AUXBUFFER),
			SET_CASE(GR_BUFFER_DEPTHBUFFER),
			SET_CASE(GR_BUFFER_ALPHABUFFER),
			SET_CASE(GR_BUFFER_TRIPLEBUFFER),
			{ NULL, 0 } // sentinel
		}
	},
	{
		NULL, //grChromakeyMode_ce
		(EnumValue[]) {
			SET_CASE(GR_CHROMAKEY_DISABLE),
			SET_CASE(GR_CHROMAKEY_ENABLE),
			{ NULL, 0 } // sentinel
		}
	},
	{
		NULL, //grCmpFnc_ce
		(EnumValue[]) {
			SET_CASE(GR_CMP_NEVER),
			SET_CASE(GR_CMP_LESS),
			SET_CASE(GR_CMP_EQUAL),
			SET_CASE(GR_CMP_LEQUAL),
			SET_CASE(GR_CMP_GREATER),
			SET_CASE(GR_CMP_NOTEQUAL),
			SET_CASE(GR_CMP_GEQUAL),
			SET_CASE(GR_CMP_ALWAYS),
			{ NULL, 0 } // sentinel
		}
	},
	{
		NULL, //grColorFormat_ce
		(EnumValue[]) {
			SET_CASE(GR_COLORFORMAT_ARGB),
			SET_CASE(GR_COLORFORMAT_ABGR),
			SET_CASE(GR_COLORFORMAT_RGBA),
			SET_CASE(GR_COLORFORMAT_BGRA),
			{ NULL, 0 } // sentinel
		}
	},
	{
		NULL, //grCullMode_ce
		(EnumValue[]) {
			SET_CASE(GR_CULL_DISABLE),
			SET_CASE(GR_CULL_NEGATIVE),
			SET_CASE(GR_CULL_POSITIVE),
			{ NULL, 0 } // sentinel
		}
	},
	{
		NULL, //grDepthBufferMode_ce
		(EnumValue[]) {
			SET_CASE(GR_DEPTHBUFFER_DISABLE),
			SET_CASE(GR_DEPTHBUFFER_ZBUFFER),
			SET_CASE(GR_DEPTHBUFFER_WBUFFER),
			SET_CASE(GR_DEPTHBUFFER_ZBUFFER_COMPARE_TO_BIAS),
			SET_CASE(GR_DEPTHBUFFER_WBUFFER_COMPARE_TO_BIAS),
			{ NULL, 0 } // sentinel
		}
	},
	{
		NULL, //grDitherMode_ce
		(EnumValue[]) {
			SET_CASE(GR_DITHER_DISABLE),
			SET_CASE(GR_DITHER_2x2),
			SET_CASE(GR_DITHER_4x4),
			{ NULL, 0 } // sentinel
		}
	},
	{
		NULL, //grFogMode_ce
		(EnumValue[]) {
			SET_CASE(GR_FOG_DISABLE),
			SET_CASE(GR_FOG_WITH_ITERATED_ALPHA),
			SET_CASE(GR_FOG_WITH_TABLE),
			SET_CASE(GR_FOG_WITH_ITERATED_Z),
			SET_CASE(GR_FOG_MULT2),
			SET_CASE(GR_FOG_ADD2),
			{ NULL, 0 } // sentinel
		}
	},
	{
		NULL, //grLock_ce
		(EnumValue[]) {
			SET_CASE(GR_LFB_READ_ONLY),
			SET_CASE(GR_LFB_WRITE_ONLY),
			SET_CASE(GR_LFB_IDLE),
			SET_CASE(GR_LFB_NOIDLE),
			{ NULL, 0 } // sentinel
		}
	},
	{
		NULL, //grLfbBypassMode_ce
		(EnumValue[]) {
			SET_CASE(GR_LFBBYPASS_DISABLE),
			SET_CASE(GR_LFBBYPASS_ENABLE),
			{ NULL, 0 } // sentinel
		}
	},
	{
		NULL, //grLfbWriteMode_ce
		(EnumValue[]) {
			SET_CASE(GR_LFBWRITEMODE_565),
			SET_CASE(GR_LFBWRITEMODE_555),
			SET_CASE(GR_LFBWRITEMODE_1555),
			SET_CASE(GR_LFBWRITEMODE_RESERVED1),
			SET_CASE(GR_LFBWRITEMODE_888),
			SET_CASE(GR_LFBWRITEMODE_8888),
			SET_CASE(GR_LFBWRITEMODE_RESERVED2),
			SET_CASE(GR_LFBWRITEMODE_RESERVED3),
			SET_CASE(GR_LFBWRITEMODE_RESERVED4),
			SET_CASE(GR_LFBWRITEMODE_RESERVED5),
			SET_CASE(GR_LFBWRITEMODE_RESERVED6),
			SET_CASE(GR_LFBWRITEMODE_RESERVED7),
			SET_CASE(GR_LFBWRITEMODE_565_DEPTH),
			SET_CASE(GR_LFBWRITEMODE_555_DEPTH),
			SET_CASE(GR_LFBWRITEMODE_1555_DEPTH),
			SET_CASE(GR_LFBWRITEMODE_ZA16),
			SET_CASE(GR_LFBWRITEMODE_ANY),
			{ NULL, 0 } // sentinel
		}
	},
	{
		NULL, //grOriginLocation_ce
		(EnumValue[]) {
			SET_CASE(GR_ORIGIN_UPPER_LEFT),
			SET_CASE(GR_ORIGIN_LOWER_LEFT),
			SET_CASE(GR_ORIGIN_ANY),
			{ NULL, 0 } // sentinel
		}
	},
	{
		NULL, //grLOD_ce
		(EnumValue[]) {
			SET_CASE(GR_LOD_256),
			SET_CASE(GR_LOD_128),
			SET_CASE(GR_LOD_64),
			SET_CASE(GR_LOD_32),
			SET_CASE(GR_LOD_16),
			SET_CASE(GR_LOD_8),
			SET_CASE(GR_LOD_4),
			SET_CASE(GR_LOD_2),
			SET_CASE(GR_LOD_1),
			{ NULL, 0 } // sentinel
		}
	},
	{
		NULL, //grMipMapMode_ce
		(EnumValue[]) {
			SET_CASE(GR_MIPMAP_DISABLE),
			SET_CASE(GR_MIPMAP_NEAREST),
			SET_CASE(GR_MIPMAP_NEAREST_DITHER),
			{ NULL, 0 } // sentinel
		}
	},
	{
		NULL, //grSmoothingMode_ce
		(EnumValue[]) {
			SET_CASE(GR_SMOOTHING_DISABLE),
			SET_CASE(GR_SMOOTHING_ENABLE),
			{ NULL, 0 } // sentinel
		}
	},
	{
		NULL, //grTextureClampMode_ce
		(EnumValue[]) {
			SET_CASE(GR_TEXTURECLAMP_WRAP),
			SET_CASE(GR_TEXTURECLAMP_CLAMP),
			{ NULL, 0 } // sentinel
		}
	},
	{
		NULL, //grTextureCombineFnc_ce
		(EnumValue[]) {
			SET_CASE(GR_TEXTURECOMBINE_ZERO),
			SET_CASE(GR_TEXTURECOMBINE_DECAL),
			SET_CASE(GR_TEXTURECOMBINE_OTHER),
			SET_CASE(GR_TEXTURECOMBINE_ADD),
			SET_CASE(GR_TEXTURECOMBINE_MULTIPLY),
			SET_CASE(GR_TEXTURECOMBINE_SUBTRACT),
			SET_CASE(GR_TEXTURECOMBINE_DETAIL),
			SET_CASE(GR_TEXTURECOMBINE_DETAIL_OTHER),
			SET_CASE(GR_TEXTURECOMBINE_TRILINEAR_ODD),
			SET_CASE(GR_TEXTURECOMBINE_TRILINEAR_EVEN),
			SET_CASE(GR_TEXTURECOMBINE_ONE),
			{ NULL, 0 } // sentinel
		}
	},
	{
		NULL, //grTextureFilterMode_ce
		(EnumValue[]) {
			SET_CASE(GR_TEXTUREFILTER_POINT_SAMPLED),
			SET_CASE(GR_TEXTUREFILTER_BILINEAR),
			{ NULL, 0 } // sentinel
		}
	},
	{
		NULL, //grTextureFormat_ce
		(EnumValue[]) {
			SET_CASE(GR_TEXFMT_8BIT),
			SET_CASE(GR_TEXFMT_RGB_332),
			SET_CASE(GR_TEXFMT_YIQ_422),
			SET_CASE(GR_TEXFMT_ALPHA_8),
			SET_CASE(GR_TEXFMT_INTENSITY_8),
			SET_CASE(GR_TEXFMT_ALPHA_INTENSITY_44),
			SET_CASE(GR_TEXFMT_P_8),
			SET_CASE(GR_TEXFMT_RSVD0),
			SET_CASE(GR_TEXFMT_RSVD1),
			SET_CASE(GR_TEXFMT_16BIT),
			SET_CASE(GR_TEXFMT_ARGB_8332),
			SET_CASE(GR_TEXFMT_AYIQ_8422),
			SET_CASE(GR_TEXFMT_RGB_565),
			SET_CASE(GR_TEXFMT_ARGB_1555),
			SET_CASE(GR_TEXFMT_ARGB_4444),
			SET_CASE(GR_TEXFMT_ALPHA_INTENSITY_88),
			SET_CASE(GR_TEXFMT_AP_88),
			SET_CASE(GR_TEXFMT_RSVD2),
			{ NULL, 0 } // sentinel
		}
	},
	{
		NULL, //grTexTable_ce
		(EnumValue[]) {
			SET_CASE(GR_TEXTABLE_NCC0),
			SET_CASE(GR_TEXTABLE_NCC1),
			SET_CASE(GR_TEXTABLE_PALETTE),
			{ NULL, 0 } // sentinel
		}
	},
	{
		NULL, //grNCCTable_ce
		(EnumValue[]) {
			SET_CASE(GR_NCCTABLE_NCC0),
			SET_CASE(GR_NCCTABLE_NCC1),
			{ NULL, 0 } // sentinel
		}
	},
	{
		NULL, //grTexBaseRange_ce
		(EnumValue[]) {
			SET_CASE(GR_TEXBASE_256),
			SET_CASE(GR_TEXBASE_128),
			SET_CASE(GR_TEXBASE_64),
			SET_CASE(GR_TEXBASE_32_TO_1),
			{ NULL, 0 } // sentinel
		}
	},
	{
		NULL, //grSstType_ce
		(EnumValue[]) {
			SET_CASE(GR_SSTTYPE_VOODOO),
			SET_CASE(GR_SSTTYPE_SST96),
			SET_CASE(GR_SSTTYPE_AT3D),
			SET_CASE(GR_SSTTYPE_Voodoo2),
			{ NULL, 0 } // sentinel
		}
	},
	{
		NULL, //grScreenRefresh_ce
		(EnumValue[]) {
			SET_CASE(GR_REFRESH_60Hz),
			SET_CASE(GR_REFRESH_70Hz),
			SET_CASE(GR_REFRESH_72Hz),
			SET_CASE(GR_REFRESH_75Hz),
			SET_CASE(GR_REFRESH_80Hz),
			SET_CASE(GR_REFRESH_90Hz),
			SET_CASE(GR_REFRESH_100Hz),
			SET_CASE(GR_REFRESH_85Hz),
			SET_CASE(GR_REFRESH_120Hz),
			SET_CASE(GR_REFRESH_NONE),
			{ NULL, 0 } // sentinel
		}
	},
	{
		NULL, //grScreenResolution_ce
		(EnumValue[]) {
			SET_CASE(GR_RESOLUTION_320x200),
			SET_CASE(GR_RESOLUTION_320x240),
			SET_CASE(GR_RESOLUTION_400x256),
			SET_CASE(GR_RESOLUTION_512x384),
			SET_CASE(GR_RESOLUTION_640x200),
			SET_CASE(GR_RESOLUTION_640x350),
			SET_CASE(GR_RESOLUTION_640x400),
			SET_CASE(GR_RESOLUTION_640x480),
			SET_CASE(GR_RESOLUTION_800x600),
			SET_CASE(GR_RESOLUTION_960x720),
			SET_CASE(GR_RESOLUTION_856x480),
			SET_CASE(GR_RESOLUTION_512x256),
			SET_CASE(GR_RESOLUTION_1024x768),
			SET_CASE(GR_RESOLUTION_1280x1024),
			SET_CASE(GR_RESOLUTION_1600x1200),
			SET_CASE(GR_RESOLUTION_400x300),
			SET_CASE(GR_RESOLUTION_NONE),
			SET_CASE(GR_RESOLUTION_MIN),
			SET_CASE(GR_RESOLUTION_MAX),
			{ NULL, 0 } // sentinel
		}
	},
	{ NULL, NULL }
};

int enum_to_int(zend_object* enum_obj) {
	for (int i = 0; grouped_enums[i].enum_entry != NULL; i++) {
		if (grouped_enums[i].enum_entry == enum_obj->ce) {
			const char* case_name = ZSTR_VAL(Z_STR_P(zend_enum_fetch_case_name(enum_obj)));
			int len = strlen(case_name);

			for (int j = 0; grouped_enums[i].values[j].name != NULL; j++) {
				if (len == strlen(grouped_enums[i].values[j].name)
					&& memcmp(case_name, grouped_enums[i].values[j].name, len) == 0
					) {
					return grouped_enums[i].values[j].value;
				}
			}

			zend_throw_error(NULL, "Unknown enum case");
			return 0;
		}
	}

	zend_throw_error(NULL, "Unknown enum case");
	return 0;
}

ZEND_METHOD(GrDepth_t, toInt) { RETURN_LONG(enum_to_int(Z_OBJ_P(ZEND_THIS))); };
ZEND_METHOD(GrEvenOdd_t, toInt) { RETURN_LONG(enum_to_int(Z_OBJ_P(ZEND_THIS))); };
ZEND_METHOD(GrChipID_t, toInt) { RETURN_LONG(enum_to_int(Z_OBJ_P(ZEND_THIS))); };
ZEND_METHOD(GrCombineFunction_t, toInt) { RETURN_LONG(enum_to_int(Z_OBJ_P(ZEND_THIS))); };
ZEND_METHOD(GrCombineFactor_t, toInt) { RETURN_LONG(enum_to_int(Z_OBJ_P(ZEND_THIS))); };
ZEND_METHOD(GrCombineLocal_t, toInt) { RETURN_LONG(enum_to_int(Z_OBJ_P(ZEND_THIS))); };
ZEND_METHOD(GrCombineOther_t, toInt) { RETURN_LONG(enum_to_int(Z_OBJ_P(ZEND_THIS))); };
ZEND_METHOD(GrAlphaSource_t, toInt) { RETURN_LONG(enum_to_int(Z_OBJ_P(ZEND_THIS))); };
ZEND_METHOD(GrColorCombineFnc_t, toInt) { RETURN_LONG(enum_to_int(Z_OBJ_P(ZEND_THIS))); };
ZEND_METHOD(GrAlphaBlendFnc_t, toInt) { RETURN_LONG(enum_to_int(Z_OBJ_P(ZEND_THIS))); };
ZEND_METHOD(GrAspectRatio_t, toInt) { RETURN_LONG(enum_to_int(Z_OBJ_P(ZEND_THIS))); };
ZEND_METHOD(GrBuffer_t, toInt) { RETURN_LONG(enum_to_int(Z_OBJ_P(ZEND_THIS))); };
ZEND_METHOD(GrChromakeyMode_t, toInt) { RETURN_LONG(enum_to_int(Z_OBJ_P(ZEND_THIS))); };
ZEND_METHOD(GrCmpFnc_t, toInt) { RETURN_LONG(enum_to_int(Z_OBJ_P(ZEND_THIS))); };
ZEND_METHOD(GrColorFormat_t, toInt) { RETURN_LONG(enum_to_int(Z_OBJ_P(ZEND_THIS))); };
ZEND_METHOD(GrCullMode_t, toInt) { RETURN_LONG(enum_to_int(Z_OBJ_P(ZEND_THIS))); };
ZEND_METHOD(GrDepthBufferMode_t, toInt) { RETURN_LONG(enum_to_int(Z_OBJ_P(ZEND_THIS))); };
ZEND_METHOD(GrDitherMode_t, toInt) { RETURN_LONG(enum_to_int(Z_OBJ_P(ZEND_THIS))); };
ZEND_METHOD(GrFogMode_t, toInt) { RETURN_LONG(enum_to_int(Z_OBJ_P(ZEND_THIS))); };
ZEND_METHOD(GrLock_t, toInt) { RETURN_LONG(enum_to_int(Z_OBJ_P(ZEND_THIS))); };
ZEND_METHOD(GrLfbBypassMode_t, toInt) { RETURN_LONG(enum_to_int(Z_OBJ_P(ZEND_THIS))); };
ZEND_METHOD(GrLfbWriteMode_t, toInt) { RETURN_LONG(enum_to_int(Z_OBJ_P(ZEND_THIS))); };
ZEND_METHOD(GrOriginLocation_t, toInt) { RETURN_LONG(enum_to_int(Z_OBJ_P(ZEND_THIS))); };
ZEND_METHOD(GrLOD_t, toInt) { RETURN_LONG(enum_to_int(Z_OBJ_P(ZEND_THIS))); };
ZEND_METHOD(GrMipMapMode_t, toInt) { RETURN_LONG(enum_to_int(Z_OBJ_P(ZEND_THIS))); };
ZEND_METHOD(GrSmoothingMode_t, toInt) { RETURN_LONG(enum_to_int(Z_OBJ_P(ZEND_THIS))); };
ZEND_METHOD(GrTextureClampMode_t, toInt) { RETURN_LONG(enum_to_int(Z_OBJ_P(ZEND_THIS))); };
ZEND_METHOD(GrTextureCombineFnc_t, toInt) { RETURN_LONG(enum_to_int(Z_OBJ_P(ZEND_THIS))); };
ZEND_METHOD(GrTextureFilterMode_t, toInt) { RETURN_LONG(enum_to_int(Z_OBJ_P(ZEND_THIS))); };
ZEND_METHOD(GrTextureFormat_t, toInt) { RETURN_LONG(enum_to_int(Z_OBJ_P(ZEND_THIS))); };
ZEND_METHOD(GrTexTable_t, toInt) { RETURN_LONG(enum_to_int(Z_OBJ_P(ZEND_THIS))); };
ZEND_METHOD(GrNCCTable_t, toInt) { RETURN_LONG(enum_to_int(Z_OBJ_P(ZEND_THIS))); };
ZEND_METHOD(GrTexBaseRange_t, toInt) { RETURN_LONG(enum_to_int(Z_OBJ_P(ZEND_THIS))); };
ZEND_METHOD(GrSstType, toInt) { RETURN_LONG(enum_to_int(Z_OBJ_P(ZEND_THIS))); };
ZEND_METHOD(GrScreenRefresh_t, toInt) { RETURN_LONG(enum_to_int(Z_OBJ_P(ZEND_THIS))); };
ZEND_METHOD(GrScreenResolution_t, toInt) { RETURN_LONG(enum_to_int(Z_OBJ_P(ZEND_THIS))); };

void phpglide2x_register_enums(INIT_FUNC_ARGS)
{
	grDepth_ce = grouped_enums[0].enum_entry = register_class_GrDepth_t();

	grEvenOdd_ce = grouped_enums[1].enum_entry = register_class_GrEvenOdd_t();

	//typedef FxI32 GrChipID_ce;
	grChipID_ce = grouped_enums[2].enum_entry = register_class_GrChipID_t();

	//typedef FxI32 GrCombineFunction_ce;
	grCombineFunction_ce = grouped_enums[3].enum_entry = register_class_GrCombineFunction_t();

	//typedef FxI32 GrCombineFactor_ce;
	grCombineFactor_ce = grouped_enums[4].enum_entry = register_class_GrCombineFactor_t();

	//typedef FxI32 GrCombineLocal_ce;
	grCombineLocal_ce = grouped_enums[5].enum_entry = register_class_GrCombineLocal_t();

	//typedef FxI32 GrCombineOther_ce;
	grCombineOther_ce = grouped_enums[6].enum_entry = register_class_GrCombineOther_t();

	//typedef FxI32 GrAlphaSource_ce;
	grAlphaSource_ce = grouped_enums[7].enum_entry = register_class_GrAlphaSource_t();

	//typedef FxI32 GrColorCombineFnc_ce;
	grColorCombineFnc_ce = grouped_enums[8].enum_entry = register_class_GrColorCombineFnc_t();

	//typedef FxI32 GrAlphaBlendFnc_ce;
	grAlphaBlendFnc_ce = grouped_enums[9].enum_entry = register_class_GrAlphaBlendFnc_t();

	//typedef FxI32 GrAspectRatio_ce;
	grAspectRatio_ce = grouped_enums[10].enum_entry = register_class_GrAspectRatio_t();

	//typedef FxI32 GrBuffer_ce;
	grBuffer_ce = grouped_enums[11].enum_entry = register_class_GrBuffer_t();

	//typedef FxI32 GrChromakeyMode_ce;
	grChromakeyMode_ce = grouped_enums[12].enum_entry = register_class_GrChromakeyMode_t();

	//typedef FxI32 GrCmpFnc_ce;
	grCmpFnc_ce = grouped_enums[13].enum_entry = register_class_GrCmpFnc_t();

	//typedef FxI32 GrColorFormat_ce;
	grColorFormat_ce = grouped_enums[14].enum_entry = register_class_GrColorFormat_t();

	//typedef FxI32 GrCullMode_ce;
	grCullMode_ce = grouped_enums[15].enum_entry = register_class_GrCullMode_t();

	//typedef FxI32 GrDepthBufferMode_ce;
	grDepthBufferMode_ce = grouped_enums[16].enum_entry = register_class_GrDepthBufferMode_t();

	//typedef FxI32 GrDitherMode_ce;
	grDitherMode_ce = grouped_enums[17].enum_entry = register_class_GrDitherMode_t();

	//typedef FxI32 GrFogMode_ce;
	grFogMode_ce = grouped_enums[18].enum_entry = register_class_GrFogMode_t();

	//typedef FxU32 GrLock_ce;
	grLock_ce = grouped_enums[19].enum_entry = register_class_GrLock_t();

	//typedef FxI32 GrLfbBypassMode_ce;
	grLfbBypassMode_ce = grouped_enums[20].enum_entry = register_class_GrLfbBypassMode_t();

	//typedef FxI32 GrLfbWriteMode_ce;
	grLfbWriteMode_ce = grouped_enums[21].enum_entry = register_class_GrLfbWriteMode_t();

	//typedef FxI32 GrOriginLocation_ce;
	grOriginLocation_ce = grouped_enums[22].enum_entry = register_class_GrOriginLocation_t();

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
	grLOD_ce = grouped_enums[23].enum_entry = register_class_GrLOD_t();

	//typedef FxI32 GrMipMapMode_ce;
	grMipMapMode_ce = grouped_enums[24].enum_entry = register_class_GrMipMapMode_t();

	//typedef FxI32 GrSmoothingMode_ce;
	grSmoothingMode_ce = grouped_enums[25].enum_entry = register_class_GrSmoothingMode_t();

	//typedef FxI32 GrTextureClampMode_ce;
	grTextureClampMode_ce = grouped_enums[26].enum_entry = register_class_GrTextureClampMode_t();

	//typedef FxI32 GrTextureCombineFnc_ce;
	grTextureCombineFnc_ce = grouped_enums[27].enum_entry = register_class_GrTextureCombineFnc_t();
	

	//typedef FxI32 GrTextureFilterMode_ce;
	grTextureFilterMode_ce = grouped_enums[28].enum_entry = register_class_GrTextureFilterMode_t();
	
	//typedef FxI32 GrTextureFormat_ce;
	grTextureFormat_ce = grouped_enums[29].enum_entry = register_class_GrTextureFormat_t();

	//typedef FxU32 GrTexTable_ce;
	grTexTable_ce = grouped_enums[30].enum_entry = register_class_GrTexTable_t();
	
	//typedef FxU32 GrNCCTable_ce;
	grNCCTable_ce = grouped_enums[31].enum_entry = register_class_GrNCCTable_t();

	//typedef FxU32 GrTexBaseRange_ce;
	grTexBaseRange_ce = grouped_enums[32].enum_entry = register_class_GrTexBaseRange_t();

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
	grSstType_ce = grouped_enums[33].enum_entry = register_class_GrSstType();


	grScreenRefresh_ce = grouped_enums[34].enum_entry = register_class_GrScreenRefresh_t();

	//typedef FxI32 GrScreenResolution_ce;
	grScreenResolution_ce = grouped_enums[35].enum_entry = register_class_GrScreenResolution_t();
}