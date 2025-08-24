#include "stdafx.h"
#include "phpglide2x_enums.h"


PHP_FUNCTION(grFogColorValue)
{
	zend_long value;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(value)
		ZEND_PARSE_PARAMETERS_END();

	grFogColorValue((GrColor_t)value);
}

PHP_FUNCTION(guFogGenerateLinear) {

	zval* fogTable = NULL;
	double nearW;
	double farW;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_ZVAL(fogTable)
		Z_PARAM_DOUBLE(nearW)
		Z_PARAM_DOUBLE(farW)
		ZEND_PARSE_PARAMETERS_END();

	ZVAL_DEREF(fogTable);

	GrFog_t fog_table[GR_FOG_TABLE_SIZE];
	guFogGenerateLinear(fog_table, (FxFloat) nearW, (FxFloat) farW);

	zval new_array;
	array_init_size(&new_array, GR_FOG_TABLE_SIZE);

	for (int cont = 0; cont < GR_FOG_TABLE_SIZE; cont++) {
		add_next_index_long(&new_array, (zend_long) fog_table[cont]);
	}

	zval_ptr_dtor(fogTable);             // clean old value
	ZVAL_COPY_VALUE(fogTable, &new_array); // move new array into var
}

PHP_FUNCTION(grFogMode) {

	zend_object* mode = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(mode, grFogMode_ce)
		ZEND_PARSE_PARAMETERS_END();

	grFogMode(enum_to_int(mode));
}

PHP_FUNCTION(grFogTable)
{
	zval* table = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(table)
		ZEND_PARSE_PARAMETERS_END();

	// Allocate memory
	GrFog_t fog_table[GR_FOG_TABLE_SIZE];

	//zend_long fog_count = zend_array_count(Z_ARRVAL_P(table));

	int i = 0;
	zval *val;
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(table), val) {

		ZVAL_DEREF(val);

		int value;

		//if it's an integer...
		if (Z_TYPE_P(val) == IS_LONG) {
			value = Z_LVAL_P(val);

			//we check whether the element isn't an integer
		}
		else if (
			Z_TYPE_P(val) == IS_STRING
			&& !is_numeric_string(Z_STRVAL_P(val), Z_STRLEN_P(val), NULL, NULL, 0)
		) {
			//we release the resources
			zend_throw_exception(NULL, "table must contain only integers", 0);
			return;
			//we make it integer
		}
		else {
			value = zval_get_long(val);
		}

		//we check the index is valid
		if (value < 0 || value > 256) {
			zend_throw_exception(NULL, "table must contain a number between 0 and 255", 0);
		}

		fog_table[i] = (GrFog_t) value;

		++i;

		if (i > GR_FOG_TABLE_SIZE) {
			break;
		}

	} ZEND_HASH_FOREACH_END();


	grFogTable(fog_table);
}