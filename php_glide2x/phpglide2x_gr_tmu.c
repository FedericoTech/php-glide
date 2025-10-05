#include "phpglide2x_structs.h"

zend_class_entry* grTMUConfig_ce;

#ifdef _DEBUG
ZEND_FUNCTION(testGrTMUConfig_t)
{
    zend_object* grTMUConfig_zo = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(grTMUConfig_zo, grTMUConfig_ce)
    ZEND_PARSE_PARAMETERS_END();

    GrTMUConfig_t buffer;

    flush_grTMUConfig(grTMUConfig_zo, &buffer);

    php_printf(
        "tmuRev: %d, tmuRam: %d\n",
        buffer.tmuRev,
        buffer.tmuRam
    );
}
#endif // _DEBUG

PHP_METHOD(GrTMUConfig_t, flush)
{
    ZEND_PARSE_PARAMETERS_NONE();

    zend_string* bin = zend_string_alloc(sizeof(GrTMUConfig_t) + 1, 0);

    flush_grTMUConfig(Z_OBJ_P(ZEND_THIS), (GrTMUConfig_t*)ZSTR_VAL(bin));

    ZSTR_VAL(bin)[sizeof(GrTMUConfig_t)+1] = '\0'; // null terminator (optional for binary)
    
    RETURN_STR(bin);
}

void flush_grTMUConfig(const _GrTMUConfig_t *obj, GrTMUConfig_t* buffer)
{
    zval* value = zend_read_property(
        grTMUConfig_ce,             // zend_class_entry* of the object
        (zend_object*)obj,          // zval* or zend_object* (see below)
        "tmuRev",                   // property name
        sizeof("tmuRev") - 1,
        1,                          // silent (1 = don't emit notice if not found)
        NULL                        // Optional return zval ptr, or NULL
    );

    buffer->tmuRev = Z_TYPE_P(value) == IS_NULL ? 0 : Z_LVAL_P(value);

    value = zend_read_property(
        grTMUConfig_ce,             // zend_class_entry* of the object
        (zend_object*)obj,          // zval* or zend_object* (see below)
        "tmuRam",                   // property name
        sizeof("tmuRam") - 1,
        1,                          // silent (1 = don't emit notice if not found)
        NULL                        // Optional return zval ptr, or NULL
    );

    buffer->tmuRam = Z_TYPE_P(value) == IS_NULL ? 0 : Z_LVAL_P(value);
}

void hydrate_grTMUConfig(const GrTMUConfig_t* tmuConfig, _GrTMUConfig_t* obj)
{
    zend_update_property_long(grTMUConfig_ce, obj, "tmuRev", sizeof("tmuRev") - 1, tmuConfig->tmuRev);

    zend_update_property_long(grTMUConfig_ce, obj, "tmuRam", sizeof("tmuRam") - 1, tmuConfig->tmuRam);
}