
#define __MSC__
#include <glide.h>

#include "phpglide3x_functions.h"
#include "phpglide3x_enums.h"
#include <Zend/zend_enum.h>

//prototype of function grGlideInit;
ZEND_BEGIN_ARG_INFO(arginfo_grGlideInit, 0)
ZEND_END_ARG_INFO()

PHP_FUNCTION(grGlideInit) {

	ZEND_PARSE_PARAMETERS_NONE();

	grGlideInit();
}

//prototype of function grGlideShutdown;
ZEND_BEGIN_ARG_INFO(arginfo_grGlideShutdown, 0)
ZEND_END_ARG_INFO()

PHP_FUNCTION(grGlideShutdown) {

	ZEND_PARSE_PARAMETERS_NONE();

	grGlideShutdown();
}

//prototype of function grVertexLayout;
ZEND_BEGIN_ARG_INFO_EX(arginfo_grVertexLayout, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, param, GrParams_t, 0)
	ZEND_ARG_TYPE_INFO(0, offset, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, mode, GrMode_t, 0)
ZEND_END_ARG_INFO()

PHP_FUNCTION(grVertexLayout)
{
	zval* param = nullptr, * mode = nullptr;
	zend_long offset;

	// Start parsing parameters using modern macros
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(param, grParams_ce)
		Z_PARAM_LONG(offset)
		Z_PARAM_OBJECT_OF_CLASS(mode, grMode_ce)
	ZEND_PARSE_PARAMETERS_END();

	// Call the actual C function
	grVertexLayout(
		(FxU32)Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(param))),
		(FxI32)offset, 
		(FxU32)Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(mode)))
	);
}

//prototype of function grConstantColorValue;
ZEND_BEGIN_ARG_INFO_EX(arginfo_grConstantColorValue, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, color, IS_LONG, 0)
ZEND_END_ARG_INFO()

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

//prototype of function grGet;
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grGet, 0, 2, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, pname, GrGet_t, 0)
	ZEND_ARG_INFO(1, params)  // "1" means it's passed by reference
	ZEND_ARG_TYPE_INFO(0, plength, IS_LONG, 1)
ZEND_END_ARG_INFO()

PHP_FUNCTION(grGet)
{
	typedef union {
		FxI32 data[4];      // For four integers
		FxI32* dynamic;       // For dynamically allocated array
	} ParamValue;

	ParamValue paramValue;

	FxI32* params = nullptr;

	zval* pname = nullptr;
	zend_long plength = 1;
	zval* params_zval = nullptr;
		
	FxU32 result;

	// Start parsing parameters using modern macros
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_OBJECT_OF_CLASS(pname, grGet_ce) // First param: pname (integer)	
		Z_PARAM_ZVAL_EX(params_zval, 0, 1)	// Third param: zval (output)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(plength)		// Second param: plength (integer)
		ZEND_PARSE_PARAMETERS_END();

	params = (FxI32*)&paramValue;

	int returnType = 0;

	int pname_int = Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(pname)));

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

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_grGetString, 0, 1, IS_STRING, 1)
	ZEND_ARG_OBJ_INFO(0, name, GrString_t, 0)
ZEND_END_ARG_INFO()

PHP_FUNCTION(grGetString)
{
	zval* name = nullptr;

	/* Use modern parameter parsing */
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(name, grString_ce) // First param: pname (integer)
		ZEND_PARSE_PARAMETERS_END();

	/* Convert to unsigned 32-bit */
	FxU32 fx_name = (FxU32)(Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(name))) & 0xFFFFFFFF);

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

void phpglide3x_register_gr_functions_module(INIT_FUNC_ARGS)
{

	const zend_function_entry gr_functions_functions[] = {

		PHP_FE(grGlideInit, arginfo_grGlideInit)
		PHP_FE(grGlideShutdown, arginfo_grGlideShutdown)
		PHP_FE(grVertexLayout, arginfo_grVertexLayout)
		PHP_FE(grConstantColorValue, arginfo_grConstantColorValue)
		PHP_FE(grGet, arginfo_grGet)
		PHP_FE(grGetString, arginfo_grGetString)
		PHP_FE_END
	};

	zend_register_functions(NULL, gr_functions_functions, NULL, MODULE_PERSISTENT);
}


void phpglide3x_init_callbacks()
{

}

void phpglide3x_shutdown_callbacks()
{
	grGlideShutdown();
}