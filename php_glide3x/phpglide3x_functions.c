
#include "phpglide3x_functions.h"
#include "phpglide3x_enums.h"

#include <conio.h>


PHP_FUNCTION(grGlideInit) {

	ZEND_PARSE_PARAMETERS_NONE();

	grGlideInit();
}

PHP_FUNCTION(grGlideShutdown) {

	ZEND_PARSE_PARAMETERS_NONE();

	grGlideShutdown();
}

PHP_FUNCTION(grVertexLayout)
{
	zend_object* param = NULL, * mode = NULL;
	zend_long offset;

	// Start parsing parameters using modern macros
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJ_OF_CLASS(param, grParams_ce)
		Z_PARAM_LONG(offset)
		Z_PARAM_OBJ_OF_CLASS(mode, grMode_ce)
	ZEND_PARSE_PARAMETERS_END();

	// Call the actual C function
	grVertexLayout(
		(FxU32)enum_to_int(param),
		(FxI32)offset, 
		(FxU32)enum_to_int(mode)
	);
}

PHP_FUNCTION(grConstantColorValue)
{
	zend_long color;

	// Start parsing parameters using modern macros
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(color)
		ZEND_PARSE_PARAMETERS_END();

	// Call the actual C function
	grConstantColorValue((GrColor_t) color);
}

PHP_FUNCTION(grGet)
{
	typedef union {
		FxI32 data[4];      // For four integers
		FxI32* dynamic;       // For dynamically allocated array
	} ParamValue;

	ParamValue paramValue;

	FxI32* params = NULL;

	zend_object* pname = NULL;
	zend_long plength = 1;
	zval* params_zval = NULL;
		
	FxU32 result;

	// Start parsing parameters using modern macros
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_OBJ_OF_CLASS(pname, grGet_ce) // First param: pname (integer)	
		Z_PARAM_ZVAL_EX(params_zval, 0, 1)	// Third param: zval (output)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(plength)		// Second param: plength (integer)
		ZEND_PARSE_PARAMETERS_END();

	params = (FxI32*)&paramValue;

	int returnType = 0;

	int pname_int = enum_to_int(pname);

	switch (pname_int) {
	// 1/4 return a number
	case GR_BITS_DEPTH:	
	case GR_BITS_GAMMA:
	case GR_FOG_TABLE_ENTRIES:
	case GR_GLIDE_STATE_SIZE:
	case GR_GLIDE_VERTEXLAYOUT_SIZE:
	case GR_MAX_TEXTURE_SIZE:
	case GR_MAX_TEXTURE_ASPECT_RATIO:
	case GR_MEMORY_FB:
	case GR_MEMORY_TMU:
	case GR_NUM_BOARDS:
	case GR_NUM_FB:
	case GR_NUM_SWAP_HISTORY_BUFFER:
	case GR_NUM_TMU:
	case GR_PENDING_BUFFERSWAPS:
	case GR_REVISION_FB:
	case GR_REVISION_TMU:
	case GR_STATS_LINES:
	case GR_STATS_PIXELS_AFUNC_FAIL:
	case GR_STATS_PIXELS_CHROMA_FAIL:
	case GR_STATS_PIXELS_DEPTHFUNC_FAIL:
	case GR_STATS_PIXELS_IN:
	case GR_STATS_PIXELS_OUT:
	case GR_STATS_POINTS:
	case GR_STATS_TRIANGLES_IN:
	case GR_STATS_TRIANGLES_OUT:
	case GR_TEXTURE_ALIGN:
		plength = 1;
		returnType = 0;
		break;
	
	// 1/4 return a number or false
	case GR_GAMMA_TABLE_ENTRIES:
	case GR_LFB_PIXEL_PIPE:
	case GR_MEMORY_UMA:
		plength = 1;
		returnType = 1;
		break;

	// 1/4 return boolean
	case GR_IS_BUSY:
	case GR_NON_POWER_OF_TWO_TEXTURES:
	case GR_SUPPORTS_PASSTHRU:
		plength = 1;
		returnType = 2;
		break;

	case GR_FIFO_FULLNESS: // 2/8
	case GR_VIDEO_POSITION:
	case GR_WDEPTH_MIN_MAX:
	case GR_ZDEPTH_MIN_MAX:
		plength = 2;
		returnType = 3;
		break;
	case GR_BITS_RGBA: // 4/16
	case GR_VIEWPORT:
		plength = 4;
		returnType = 4;
		break;
	case GR_SWAP_HISTORY: // n/4n

		// Allocate memory for params
		params = paramValue.dynamic = (FxI32*)emalloc(plength * sizeof(FxU32));

		if (!params) {
			php_error_docref(NULL, E_WARNING, "Memory allocation failed");
			RETURN_FALSE;
		}

		returnType = 5;

		break;
	default:
		zend_throw_error(NULL, "Invalid pname param");
		break;
	}

	// Call the actual C function
	result = grGet((FxU32)pname_int, (FxU32)plength * sizeof(FxU32), params);

	//php_printf("pname: %d, plength: %d, params: %d, result: %d\n", pname, plength, paramValue.single, result);

	if (!result) {
		if (returnType == 5) {
			efree(params); // Free allocated memory
		}

		RETURN_LONG(result); // Return the function's result
	}

	// Ensure params_zval is properly set as an array
	zval_dtor(params_zval); // Destroy previous value if necessary

	switch (returnType)
	{
	case 0: // 1/4 return a number
		ZVAL_LONG(params_zval, paramValue.data[0]);
		break;
	case 1: // 1/4 return a number or false
		//if the result is 0
		if (paramValue.data[0] == 0) {
			//we return false
			ZVAL_FALSE(params_zval);
		}
		else {
			ZVAL_LONG(params_zval, paramValue.data[0]);
		}
		break;
	case 2: // 1/4 return boolean
		ZVAL_BOOL(params_zval, paramValue.data[0]);
		break;
	case 3:	// 2/8
		array_init(params_zval);
		add_next_index_long(params_zval, paramValue.data[0]);
		add_next_index_long(params_zval, paramValue.data[1]);
		break;
	case 4: // 4/16
		array_init(params_zval);
		add_next_index_long(params_zval, paramValue.data[0]);
		add_next_index_long(params_zval, paramValue.data[1]);
		add_next_index_long(params_zval, paramValue.data[2]);
		add_next_index_long(params_zval, paramValue.data[3]);
		break;
	case 5:	// n/4n
		array_init(params_zval);

		for (FxI32 i = 0; i < plength; i++) {
			add_next_index_long(params_zval, paramValue.dynamic[i]); // Fill the array with output values
		}

		efree(params); // Free allocated memory

	}

	RETURN_LONG(result); // Return the function's result
}

PHP_FUNCTION(grGetString)
{
	zend_object* name = NULL;

	/* Use modern parameter parsing */
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(name, grString_ce) // First param: pname (integer)
		ZEND_PARSE_PARAMETERS_END();

	/* Convert to unsigned 32-bit */
	FxU32 fx_name = (FxU32)(enum_to_int(name) & 0xFFFFFFFF);

	/* Call the C function */
	const char* result = grGetString(fx_name);

	/* Return the result */
	if (result) {
		RETURN_STRING(result);
	}
	else {
		RETURN_NULL();
	}
}

PHP_FUNCTION(grFinish) {
	ZEND_PARSE_PARAMETERS_NONE();
	grFinish();
}

PHP_FUNCTION(_kbhit) {
	ZEND_PARSE_PARAMETERS_NONE();
	RETURN_LONG(_kbhit());
}

void phpglide3x_init_callbacks()
{

}

void phpglide3x_shutdown_callbacks()
{
	grGlideShutdown();
}