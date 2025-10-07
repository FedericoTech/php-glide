#include "phpglide2x_structs.h"
#include "phpglide2x_enums.h"

zend_class_entry* gu3dfHeader_ce;

#ifdef _DEBUG
ZEND_FUNCTION(testGu3dfHeader)
{
    zend_object* gu3dfHeader_zo = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(gu3dfHeader_zo, gu3dfHeader_ce)
        ZEND_PARSE_PARAMETERS_END();

    Gu3dfHeader buffer;

    memset(&buffer, 0xff, sizeof buffer);

    flush_gu3dfHeader(gu3dfHeader_zo, &buffer);

    php_printf(
        "width: %d, height: %d, small_lod: %d, large_lod: %d, aspect_ratio: %d, format: %d\n",
        buffer.width,
        buffer.height,
        buffer.small_lod,
        buffer.large_lod,
        buffer.aspect_ratio,
        buffer.format
    );
}
#endif // _DEBUG

PHP_METHOD(Gu3dfHeader, flush)
{
    ZEND_PARSE_PARAMETERS_NONE();

    zend_string* bin = zend_string_alloc(sizeof(Gu3dfHeader) + 1, 0);

    flush_gu3dfHeader(Z_OBJ_P(ZEND_THIS), (Gu3dfHeader*)ZSTR_VAL(bin));

    ZSTR_VAL(bin)[sizeof(Gu3dfHeader) + 1] = '\0'; // null terminator (optional for binary)

    RETURN_STR(bin);
}

void flush_gu3dfHeader(const _Gu3dfHeader* obj, Gu3dfHeader* buffer)
{
    zval* value = zend_read_property(
        gu3dfHeader_ce,                     // zend_class_entry* of the object
        (zend_object*)obj,    // zval* or zend_object* (see below)
        "width",                            // property name
        sizeof("width") - 1,
        1,                                  // silent (1 = don't emit notice if not found)
        NULL                                // Optional return zval ptr, or NULL
    );

    if (Z_TYPE_P(value) != IS_NULL) { buffer->width = Z_LVAL_P(value); }


    value = zend_read_property(
        gu3dfHeader_ce,                     // zend_class_entry* of the object
        (zend_object*)obj,    // zval* or zend_object* (see below)
        "height",                            // property name
        sizeof("height") - 1,
        1,                                  // silent (1 = don't emit notice if not found)
        NULL                                // Optional return zval ptr, or NULL
    );

    if (Z_TYPE_P(value) != IS_NULL) { buffer->height = Z_LVAL_P(value); }


    value = zend_read_property(
        gu3dfHeader_ce,                     // zend_class_entry* of the object
        (zend_object*)obj,    // zval* or zend_object* (see below)
        "small_lod",                            // property name
        sizeof("small_lod") - 1,
        1,                                  // silent (1 = don't emit notice if not found)
        NULL                                // Optional return zval ptr, or NULL
    );

    if (Z_TYPE_P(value) != IS_NULL) { buffer->small_lod = enum_to_int(Z_OBJ_P(value)); }


    value = zend_read_property(
        gu3dfHeader_ce,                     // zend_class_entry* of the object
        (zend_object*)obj,    // zval* or zend_object* (see below)
        "large_lod",                            // property name
        sizeof("large_lod") - 1,
        1,                                  // silent (1 = don't emit notice if not found)
        NULL                                // Optional return zval ptr, or NULL
    );

    if (Z_TYPE_P(value) != IS_NULL) { buffer->large_lod = enum_to_int(Z_OBJ_P(value)); }


    value = zend_read_property(
        gu3dfHeader_ce,                     // zend_class_entry* of the object
        (zend_object*)obj,    // zval* or zend_object* (see below)
        "aspect_ratio",                            // property name
        sizeof("aspect_ratio") - 1,
        1,                                  // silent (1 = don't emit notice if not found)
        NULL                                // Optional return zval ptr, or NULL
    );

    if (Z_TYPE_P(value) != IS_NULL) { buffer->aspect_ratio = enum_to_int(Z_OBJ_P(value)); }


    value = zend_read_property(
        gu3dfHeader_ce,                     // zend_class_entry* of the object
        (zend_object*)obj,    // zval* or zend_object* (see below)
        "format",                            // property name
        sizeof("format") - 1,
        1,                                  // silent (1 = don't emit notice if not found)
        NULL                                // Optional return zval ptr, or NULL
    );

    if (Z_TYPE_P(value) != IS_NULL) { buffer->format = enum_to_int(Z_OBJ_P(value)); }
}

void hydrate_gu3dfHeader(const Gu3dfHeader* buffer, _Gu3dfHeader* obj)
{
    zend_update_property_long(
        gu3dfHeader_ce,
        obj,
        "width",
        sizeof("width") - 1, buffer->width
    );

    zend_update_property_long(
        gu3dfHeader_ce,
        obj,
        "height",
        sizeof("height") - 1, buffer->height
    );

    zval val_zv;
    ZVAL_OBJ(&val_zv, int_to_enum(buffer->small_lod, grLOD_ce));
    zend_update_property(
        gu3dfHeader_ce, obj,
        "small_lod", sizeof("small_lod") - 1,
        &val_zv
    );

    ZVAL_OBJ(&val_zv, int_to_enum(buffer->large_lod, grLOD_ce));
    zend_update_property(
        gu3dfHeader_ce, obj,
        "large_lod", sizeof("large_lod") - 1,
        &val_zv
    );

    ZVAL_OBJ(&val_zv, int_to_enum(buffer->aspect_ratio, grAspectRatio_ce));
    zend_update_property(
        gu3dfHeader_ce, obj,
        "aspect_ratio", sizeof("aspect_ratio") - 1,
        &val_zv
    );

    ZVAL_OBJ(&val_zv, int_to_enum(buffer->format, grTextureFormat_ce));
    zend_update_property(
        gu3dfHeader_ce, obj,
        "format", sizeof("format") - 1,
        &val_zv
    );

}