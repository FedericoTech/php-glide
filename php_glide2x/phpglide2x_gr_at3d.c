#include "phpglide2x_structs.h"

zend_class_entry* grAT3DConfig_ce;

#ifdef _DEBUG
ZEND_FUNCTION(testGrAT3DConfig_t)
{
    zend_object* grAT3DConfig_zo = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(grAT3DConfig_zo, grAT3DConfig_ce)
    ZEND_PARSE_PARAMETERS_END();

    GrAT3DConfig_t buffer = { 0xffffffff };

    GrAT3DConfig_flush(grAT3DConfig_zo, &buffer);

    php_printf(
        "rev: %d\n",
        buffer.rev
    );
}
#endif // _DEBUG

PHP_METHOD(GrAT3DConfig_t, toBinary)
{
    ZEND_PARSE_PARAMETERS_NONE();

    zend_string* bin = zend_string_alloc(sizeof(GrAT3DConfig_t), 0);

    GrAT3DConfig_flush(Z_OBJ_P(ZEND_THIS), (GrAT3DConfig_t *) ZSTR_VAL(bin));

    ZSTR_VAL(bin)[sizeof(GrAT3DConfig_t)] = '\0'; // null terminator (optional for binary)

    RETURN_STR(bin);
}

void GrAT3DConfig_flush(const _GrAT3DConfig_t* self, GrAT3DConfig_t* buffer)
{
    zval* value = zend_read_property(
        grAT3DConfig_ce,                // zend_class_entry* of the object
        (zend_object *)self,    // zval* or zend_object* (see below)
        "rev",                  // property name
        sizeof("rev") - 1,
        1,                      // silent (1 = don't emit notice if not found)
        NULL                    // Optional return zval ptr, or NULL
    );

    if (!Z_ISNULL_P(value)) { buffer->rev = Z_LVAL_P(value); }
}

void GrAT3DConfig_hydrate(_GrAT3DConfig_t* self, const GrAT3DConfig_t* buffer)
{
    zend_update_property_long(
        grAT3DConfig_ce, 
        self,
        "rev", 
        sizeof("rev") - 1, buffer->rev
    );
}