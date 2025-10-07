#include "phpglide2x_structs.h"

zend_class_entry* grState_ce;

#ifdef _DEBUG
ZEND_FUNCTION(testGrState)
{
    zend_object* grState_zo = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(grState_zo, grState_ce)
        ZEND_PARSE_PARAMETERS_END();

    GrState buffer;

    memset(&buffer, 0xff, sizeof buffer);

    flush_grState(grState_zo, &buffer);

    php_printf(
        "pad: %s\n",
        buffer.pad
    );
}
#endif // _DEBUG

PHP_METHOD(GrState, flush)
{
    ZEND_PARSE_PARAMETERS_NONE();

    zend_string* bin = zend_string_alloc(sizeof(GrState) + 1, 0);

    flush_grState(Z_OBJ_P(ZEND_THIS), (GrState*)ZSTR_VAL(bin));

    ZSTR_VAL(bin)[sizeof(GrState) + 1] = '\0'; // null terminator (optional for binary)

    RETURN_STR(bin);
}

void flush_grState(const _GrState* obj, GrState* buffer)
{
    zval* value = zend_read_property(
        grState_ce,         // zend_class_entry* of the object
        (zend_object*)obj,  // zval* or zend_object* (see below)
        "pad",              // property name
        sizeof("pad") - 1,
        1,                  // silent (1 = don't emit notice if not found)
        NULL                // Optional return zval ptr, or NULL
    );

    if (Z_TYPE_P(value) == IS_NULL) {
        buffer->pad[0] = '\0';
    }
    else {

        const char* str = Z_STRVAL_P(value);
        
        size_t len = Z_STRLEN_P(value);

        // Make sure not to overflow the destination buffer
        strncpy_s(buffer->pad, sizeof(buffer->pad), str, _TRUNCATE);
        
        buffer->pad[sizeof(buffer->pad) - 1] = '\0';  // Ensure null-termination
    }
}

void hydrate_grState(const GrState* buffer, _GrState* obj)
{
    zend_update_property_stringl(
        grState_ce,
        obj,
        "pad",
        sizeof("pad") - 1,
        buffer->pad, 
        GLIDE_STATE_PAD_SIZE
    );
}