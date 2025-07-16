<?php
/** 
 * @generate-class-entries 
 * @undocumentable
 */
 
/**
 * @var int
 * @cvalue MAX_NUM_SST
 */
const MAX_NUM_SST = UNKNOWN;

/**
 * @var int
 * @cvalue MAX_MIPMAPS_PER_SST
 */
const MAX_MIPMAPS_PER_SST = UNKNOWN;

/**
 * @var int
 * @cvalue GR_FOG_TABLE_SIZE
 */
const GR_FOG_TABLE_SIZE = UNKNOWN;

/**
 * @var int
 * @cvalue GR_NULL_MIPMAP_HANDLE
 */
const GR_NULL_MIPMAP_HANDLE = UNKNOWN;

enum GrDepth_t {
    case GR_ZDEPTHVALUE_NEAREST;
    case GR_ZDEPTHVALUE_FARTHEST;
    case GR_WDEPTHVALUE_NEAREST;
    case GR_WDEPTHVALUE_FARTHEST;
	
	public function toInt() : int;
}

enum GrEvenOdd_t {
    case GR_MIPMAPLEVELMASK_EVEN;
    case GR_MIPMAPLEVELMASK_ODD;
    case GR_MIPMAPLEVELMASK_BOTH;
	
	public function toInt() : int;
}

/**
 * @var float
 * @cvalue GR_LODBIAS_BILINEAR
 */
const GR_LODBIAS_BILINEAR = UNKNOWN;

/**
 * @var float
 * @cvalue GR_LODBIAS_TRILINEAR
 */
const GR_LODBIAS_TRILINEAR = UNKNOWN;

enum GrChipID_t {
    case GR_TMU0;
    case GR_TMU1;
    case GR_TMU2;
	case GR_FBI;
	
	public function toInt() : int;
}

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
    case GR_ASPECT_8x1;
    case GR_ASPECT_4x1;
    case GR_ASPECT_2x1;
	case GR_ASPECT_1x1;
	case GR_ASPECT_1x2;
	case GR_ASPECT_1x4;
	case GR_ASPECT_1x8;
	
	public function toInt() : int;
}

enum GrBuffer_t {
    case GR_BUFFER_FRONTBUFFER;
    case GR_BUFFER_BACKBUFFER;
    case GR_BUFFER_AUXBUFFER;
	case GR_BUFFER_DEPTHBUFFER;
	case GR_BUFFER_ALPHABUFFER;
	case GR_BUFFER_TRIPLEBUFFER;
	
	public function toInt() : int;
}

enum GrChromakeyMode_t {
    case GR_CHROMAKEY_DISABLE;
    case GR_CHROMAKEY_ENABLE;
	
	public function toInt() : int;
}

enum GrCmpFnc_t {
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
    case GR_COLORFORMAT_ARGB;
    case GR_COLORFORMAT_ABGR;
	case GR_COLORFORMAT_RGBA;
	case GR_COLORFORMAT_BGRA;
	
	public function toInt() : int;
}

enum GrCullMode_t {
    case GR_CULL_DISABLE;
    case GR_CULL_NEGATIVE;
	case GR_CULL_POSITIVE;
	
	public function toInt() : int;
}

enum GrDepthBufferMode_t {
    case GR_DEPTHBUFFER_DISABLE;
    case GR_DEPTHBUFFER_ZBUFFER;
	case GR_DEPTHBUFFER_WBUFFER;
	case GR_DEPTHBUFFER_ZBUFFER_COMPARE_TO_BIAS;
	case GR_DEPTHBUFFER_WBUFFER_COMPARE_TO_BIAS;
	
	public function toInt() : int;
}

enum GrDitherMode_t {
    case GR_DITHER_DISABLE;
    case GR_DITHER_2x2;
	case GR_DITHER_4x4;
	
	public function toInt() : int;
}

enum GrFogMode_t {
    case GR_FOG_DISABLE;
    case GR_FOG_WITH_ITERATED_ALPHA;
	case GR_FOG_WITH_TABLE;
	case GR_FOG_WITH_ITERATED_Z;
	case GR_FOG_MULT2;
	case GR_FOG_ADD2;
	
	public function toInt() : int;
}

enum GrLock_t {
    case GR_LFB_READ_ONLY;
    case GR_LFB_WRITE_ONLY;
	case GR_LFB_IDLE;
	case GR_LFB_NOIDLE;
	
	public function toInt() : int;
}

enum GrLfbBypassMode_t {
    case GR_LFBBYPASS_DISABLE;
    case GR_LFBBYPASS_ENABLE;
	
	public function toInt() : int;
}


enum GrLfbWriteMode_t {
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
    case GR_ORIGIN_UPPER_LEFT;
    case GR_ORIGIN_LOWER_LEFT;
	case GR_ORIGIN_ANY;
	
	public function toInt() : int;
}

enum GrLOD_t {
    case GR_LOD_256;
    case GR_LOD_128;
	case GR_LOD_64;
	case GR_LOD_32;
	case GR_LOD_16;
	case GR_LOD_8;
	case GR_LOD_4;
	case GR_LOD_2;
	case GR_LOD_1;
	
	public function toInt() : int;
}

enum GrMipMapMode_t {
    case GR_MIPMAP_DISABLE;
    case GR_MIPMAP_NEAREST;
	case GR_MIPMAP_NEAREST_DITHER;
	
	public function toInt() : int;
}

enum GrSmoothingMode_t {
    case GR_SMOOTHING_DISABLE;
    case GR_SMOOTHING_ENABLE;
	
	public function toInt() : int;
}

enum GrTextureClampMode_t {
    case GR_TEXTURECLAMP_WRAP;
    case GR_TEXTURECLAMP_CLAMP;
	
	public function toInt() : int;
}

enum GrTextureCombineFnc_t {
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
    case GR_TEXTUREFILTER_POINT_SAMPLED;
    case GR_TEXTUREFILTER_BILINEAR;
	
	public function toInt() : int;
}

enum GrTextureFormat_t {
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
    case GR_TEXTABLE_NCC0;
    case GR_TEXTABLE_NCC1;
	case GR_TEXTABLE_PALETTE;
	
	public function toInt() : int;
}

enum GrNCCTable_t {
    case GR_NCCTABLE_NCC0;
    case GR_NCCTABLE_NCC1;
	
	public function toInt() : int;
}

enum GrTexBaseRange_t {
    case GR_TEXBASE_256;
    case GR_TEXBASE_128;
	case GR_TEXBASE_64;
	case GR_TEXBASE_32_TO_1;
	
	public function toInt() : int;
}

enum GrSstType {
    case GR_SSTTYPE_VOODOO;
    case GR_SSTTYPE_SST96;
	case GR_SSTTYPE_AT3D;
	case GR_SSTTYPE_Voodoo2;
	case GR_SSTTYPE_Banshee;
	case GR_SSTTYPE_Unknown;
	
	public function toInt() : int;
}

enum GrScreenRefresh_t {
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

interface flushable {
	public function flush() : string;
}

final class GrTMUConfig_t implements flushable
{
	public int $tmuRev;
	public int $tmuRam;
	//public function __construct(int $tmuRev, int $tmuRam){}
	public function flush() : string;
}

#ifdef _DEBUG
function testGrTMUConfig_t(GrTMUConfig_t $gtmu) : void {};
#endif



final class GrVoodooConfig_t implements flushable
{
	public int $fbRam;
	public int $fbiRev;
	public int $nTexelfx;
	public bool $sliDetect = false;
	
	/** @var GrTMUConfig_t[] */
	public array $tmuConfig;
	
	public function flush() : string;
}

#ifdef _DEBUG
function testGrVoodooConfig_t(GrVoodooConfig_t $gvc) : void {};
#endif

final class GrVoodoo2Config_t implements flushable
{
	public int $fbRam;
	public int $fbiRev;
	public int $nTexelfx;
	public bool $sliDetect = false;
	
	/** @var GrTMUConfig_t[] */
	public array $tmuConfig;
	
	public function flush() : string;
}

#ifdef _DEBUG
function testGrVoodoo2Config_t(GrVoodoo2Config_t $gv2c) : void {};
#endif

final class GrSst96Config_t implements flushable
{
	public int $fbRam;
	public int $nTexelfx;
	public GrTMUConfig_t $tmuConfig;
	
	public function flush() : string;
}

#ifdef _DEBUG
function testGrSst96Config_t(GrSst96Config_t $gs9c) : void {};
#endif

final class GrAT3DConfig_t implements flushable
{
	public int $rev;
	public function flush() : string;
}

#ifdef _DEBUG
function testGrAT3DConfig_t(GrAT3DConfig_t $ga4dc) : void {};
#endif

final class SST_t implements flushable
{
	public ?GrSstType $type;
	public GrVoodooConfig_t|GrSst96Config_t|GrAT3DConfig_t|GrVoodoo2Config_t|null $sstBoard;
	
	public function flush() : string;
}

#ifdef _DEBUG
function testSST_t(SST_t $sst) : void {};
#endif

final class GrHwConfiguration implements flushable
{
	public int $num_sst;
	
	/** @var SST_t[] */
	public array $SSTs;
	
	public function flush() : string;
}

#ifdef _DEBUG
function testGrHwConfiguration(GrHwConfiguration $chc) : void {};
#endif

final class GrTmuVertex implements flushable {
	public float  $sow;
	public float  $tow;
	public float  $oow;
	
	public function flush() : string;
}

#ifdef _DEBUG
function testGrTmuVertex(GrTmuVertex $gtv) : void {};
#endif

final class GrVertex implements flushable {
	public float $x;
	public float $y;
	public float $z;
	
	public float $r;
	public float $g;
	public float $b;
	
	public float $ooz;
	public float $a;
	public float $oow;
	
	/** @var GrTmuVertex[] */
	public array $tmuvtx;
	
	public function flush() : string;
}

#ifdef _DEBUG
function testGrVertex(GrVertex $chc) : void {};
#endif

#ifdef _DEBUG
function testObject(object $obj) : void {};
#endif

function grAADrawLine(GrVertex $va, GrVertex $vb) : void {};

function grAADrawPoint(GrVertex $p) : void {};

function grAADrawPolygon(int $nVerts, array $ilist, array $vlist) : void {};

function grAADrawPolygonVertexList(int $nVerts, array $vlist) : void {};

function grAADrawTriangle(GrVertex $a, GrVertex $b, GrVertex $c, bool $antialiasAB, bool $antialiasBC, bool $antialiasCA) : void {};

function grAlphaBlendFunction(
	GrAlphaBlendFnc_t $rgb_sf,
	GrAlphaBlendFnc_t $rgb_df,
	GrAlphaBlendFnc_t $alpha_sf,
	GrAlphaBlendFnc_t $alpha_df
) : void {};

function grAlphaCombine(
	GrCombineFunction_t $func,
	GrCombineFactor_t $factor,
	GrCombineLocal_t $local,
	GrCombineOther_t $other,
	bool $invert
) : void {};

function grAlphaControlsITRGBLighting(bool $enable) : void {};

function grAlphaTestFunction(GrCmpFnc_t $function) : void {};

function grAlphaTestReferenceValue(int $value) : void {};

function grBufferClear(int $color, int $alpha, GrDepth_t $depth) : void {};

function grBufferNumPending() : int {};

function grBufferSwap(int $swap_interval) : void {};

function grChromakeyMode(GrChromakeyMode_t $mode) : void {};

function grChromakeyValue(int $color) : void {};

function grClipWindow(int $minx, int $miny, int $maxx, int $maxy) : void {};


function grColorCombine( 
	GrCombineFunction_t $func,
	GrCombineFactor_t $factor,
	GrCombineLocal_t $local,
	GrCombineOther_t $other,
	bool $invert
) : void {};

function grColorMask(bool $rgb, bool $alpha) : void {};

function grConstantColorValue(int $color) : void {};

function grCullMode(GrCullMode_t $mode) : void {};

function grDepthBiasLevel(int $level) : void {};

function grDepthBufferFunction(GrCmpFnc_t $func) : void {};

function grDepthBufferMode(GrDepthBufferMode_t $mode) : void {};

function grDepthMask(bool $enable) : void {};

function grDisableAllEffects() : void {};

function grDitherMode(GrDitherMode_t $mode) : void {};

function grDrawLine(GrVertex $a, GrVertex $b ) : void {};

function grDrawPlanarPolygon(int $nVerts, array $ilist, array $vlist) : void {};

function grDrawPlanarPolygonVertexList(int $nVerts, array $vlist): void {};

function grDrawPoint(GrVertex $a) : void {};

function grDrawPolygon(int $nVerts, array $ilist, array $vlist) : void {};

function grDrawPolygonVertexList(int $nVerts, array $vlist) : void {};

// 						function(string $string, bool $fatal)
function grErrorSetCallback(callable $function) : void {};

function grFogColorValue(int $value) : void {};

function grFogMode( GrFogMode_t $mode ) : void {};

function grFogTable(array $table ) : void {};

function grGammaCorrectionValue(float $value) : void {};

function grGlideGetVersion(string &$version) : void {};





function guFogGenerateLinear(mixed &$fogTable, float $nearW, float $farW) : void {};


function grGlideInit() : void {};
function grGlideShutdown() : void {};

function grSstQueryHardware(GrHwConfiguration $hwConfig) : bool {};
function grSstSelect(int $which_sst) : void {};

function grDrawTriangle(GrVertex $a, GrVertex $b, GrVertex $c) : void {};

function guColorCombineFunction(GrColorCombineFnc_t $func) : void {};

function grSstWinOpen(
	int $hWin, 
	GrScreenResolution_t $res, 
	GrScreenRefresh_t $ref, 
	GrColorFormat_t $cFormat,
	GrOriginLocation_t $org_loc,
	int $num_buffers,
	int $num_aux_buffers
) : bool {};

function grSstWinClose() : void {};

function grSstIdle() : void {};


function grRenderBuffer(GrBuffer_t $buffer) : void {};



// other functions
function _kbhit() : int {};