#include "phpglide2x_structs.h"

zend_class_entry* grTmuVertex_ce;

static const char* properties[] = { "sow", "tow", "oow" };

#ifdef _DEBUG
ZEND_FUNCTION(testGrTmuVertex)
{
    zend_object* grTmuVertex_zo = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(grTmuVertex_zo, grTmuVertex_ce)
        ZEND_PARSE_PARAMETERS_END();

    GrTmuVertex buffer;

    memset(&buffer, 0xff, sizeof buffer);

    flush_grTmuVertex(grTmuVertex_zo, &buffer);

    php_printf(
        "sow: %f, tow: %f, oow: %f\n",
        buffer.sow,
        buffer.tow,
        buffer.oow
    );
}
#endif // _DEBUG

PHP_METHOD(GrTmuVertex, flush)
{
    ZEND_PARSE_PARAMETERS_NONE();

    zend_string* bin = zend_string_alloc(sizeof(GrTmuVertex) + 1, 0);

    flush_grTmuVertex(Z_OBJ_P(ZEND_THIS), (GrTmuVertex*) ZSTR_VAL(bin));

    ZSTR_VAL(bin)[sizeof(GrTmuVertex) + 1] = '\0'; // null terminator (optional for binary)

    RETURN_STR(bin);
}

void flush_grTmuVertex(const _GrTmuVertex* obj, GrTmuVertex* buffer)
{
    zval* value = NULL;
    for (int cont = 0; cont < 3; cont++) {
        value = zend_read_property(
            grTmuVertex_ce,                     // zend_class_entry* of the object
            (zend_object*)obj,    // zval* or zend_object* (see below)
            properties[cont],                   // property name
            strlen(properties[cont]),
            1,                                  // silent (1 = don't emit notice if not found)
            NULL                                // Optional return zval ptr, or NULL
        );

        if (Z_TYPE_P(value) != IS_NULL) {
            ((FxFloat*)&buffer->sow)[cont] = (FxFloat)(
                Z_TYPE_P(value) == IS_DOUBLE
                ? Z_DVAL_P(value)
                : zval_get_double(value)
                );
        }
    }
}

void hydrate_grTmuVertex(const GrTmuVertex* buffer, _GrTmuVertex* obj)
{
    for (int cont = 0; cont < 3; cont++) {
        zend_update_property_long(
            grTMUConfig_ce,
            obj,
            properties[cont],
            strlen(properties[cont]),
            (zend_long)((FxFloat*)&buffer->sow)[cont]
        );
    }
}