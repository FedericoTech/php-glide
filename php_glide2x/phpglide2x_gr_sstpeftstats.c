#include "phpglide2x_structs.h"

zend_class_entry* gr_SstPerfStats_ce;

#ifdef _DEBUG
ZEND_FUNCTION(testGrSstPerfStats_t)
{
    zend_object* grSstPerfStats_zo = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(grSstPerfStats_zo, gr_SstPerfStats_ce)
        ZEND_PARSE_PARAMETERS_END();

    GrSstPerfStats_t buffer;

    memset(&buffer, 0xff, sizeof buffer);

    flush_grSstPerfStats(grSstPerfStats_zo, &buffer);

    php_printf(
        "pixelsIn: %u, chromaFail: %u, zFuncFail: %u, aFuncFail: %u, pixelsOut: %u\n",
        buffer.pixelsIn,
        buffer.chromaFail,
        buffer.zFuncFail,
        buffer.aFuncFail,
        buffer.pixelsOut
    );
}
#endif // _DEBUG

PHP_METHOD(GrSstPerfStats_t, flush)
{
    ZEND_PARSE_PARAMETERS_NONE();

    zend_string* bin = zend_string_alloc(sizeof(GrSstPerfStats_t) + 1, 0);

    flush_grSstPerfStats(Z_OBJ_P(ZEND_THIS), (GrSstPerfStats_t*)ZSTR_VAL(bin));

    ZSTR_VAL(bin)[sizeof(GrSstPerfStats_t) + 1] = '\0'; // null terminator (optional for binary)

    RETURN_STR(bin);
}

void flush_grSstPerfStats(const _GrSstPerfStats_t* obj, GrSstPerfStats_t* buffer)
{
    zval* value = zend_read_property(
        gr_SstPerfStats_ce,            // zend_class_entry* of the object
        (zend_object*)obj,           // zval* or zend_object* (see below)
        "pixelsIn",   // property name
        sizeof("pixelsIn") - 1,
        1,             // silent (1 = don't emit notice if not found)
        NULL           // Optional return zval ptr, or NULL
    );

    if (Z_TYPE_P(value) != IS_NULL) { buffer->pixelsIn = (FxU32)Z_LVAL_P(value); }

    value = zend_read_property(
        gr_SstPerfStats_ce,         // zend_class_entry* of the object
        (zend_object*)obj,          // zval* or zend_object* (see below)
        "chromaFail",               // property name
        sizeof("chromaFail") - 1,
        1,                          // silent (1 = don't emit notice if not found)
        NULL                        // Optional return zval ptr, or NULL
    );

    if (Z_TYPE_P(value) != IS_NULL) { buffer->chromaFail = (FxU32)Z_LVAL_P(value); }

    value = zend_read_property(
        gr_SstPerfStats_ce,         // zend_class_entry* of the object
        (zend_object*)obj,          // zval* or zend_object* (see below)
        "zFuncFail",                // property name
        sizeof("zFuncFail") - 1,
        1,                          // silent (1 = don't emit notice if not found)
        NULL                        // Optional return zval ptr, or NULL
    );

    if (Z_TYPE_P(value) != IS_NULL) { buffer->zFuncFail = (FxU32)Z_LVAL_P(value); }

    value = zend_read_property(
        gr_SstPerfStats_ce,         // zend_class_entry* of the object
        (zend_object*)obj,          // zval* or zend_object* (see below)
        "aFuncFail",                // property name
        sizeof("aFuncFail") - 1,
        1,                          // silent (1 = don't emit notice if not found)
        NULL                        // Optional return zval ptr, or NULL
    );

    if (Z_TYPE_P(value) != IS_NULL) { buffer->aFuncFail = (FxU32)Z_LVAL_P(value); }

    value = zend_read_property(
        gr_SstPerfStats_ce,         // zend_class_entry* of the object
        (zend_object*)obj,          // zval* or zend_object* (see below)
        "pixelsOut",                // property name
        sizeof("pixelsOut") - 1,
        1,                          // silent (1 = don't emit notice if not found)
        NULL                        // Optional return zval ptr, or NULL
    );

    if (Z_TYPE_P(value) != IS_NULL) { buffer->pixelsOut = (FxU32)Z_LVAL_P(value); }
}

void hydrate_grSstPerfStats(const GrSstPerfStats_t* buffer, _GrSstPerfStats_t* obj)
{

    zend_update_property_long(gr_SstPerfStats_ce, obj, "pixelsIn", sizeof("pixelsIn") - 1, buffer->pixelsIn);

    zend_update_property_long(gr_SstPerfStats_ce, obj, "chromaFail", sizeof("chromaFail") - 1, buffer->chromaFail);

    zend_update_property_long(gr_SstPerfStats_ce, obj, "zFuncFail", sizeof("zFuncFail") - 1, buffer->zFuncFail);

    zend_update_property_long(gr_SstPerfStats_ce, obj, "aFuncFail", sizeof("aFuncFail") - 1, buffer->aFuncFail);

    zend_update_property_long(gr_SstPerfStats_ce, obj, "pixelsOut", sizeof("pixelsOut") - 1, buffer->pixelsOut);
}