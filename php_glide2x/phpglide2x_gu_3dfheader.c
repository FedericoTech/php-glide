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

    _Gu3dfHeader* config = O_EMBEDDED_P(_Gu3dfHeader, gu3dfHeader_zo);

    php_printf(
        "width: %d, height: %d, small_lod: %d, large_lod: %d, aspect_ratio: %d, format:%d\n",
        config->gu3dfHeader.width,
        config->gu3dfHeader.height,
        config->gu3dfHeader.small_lod,
        config->gu3dfHeader.large_lod,
        config->gu3dfHeader.aspect_ratio,
        config->gu3dfHeader.format
    );
}
#endif // _DEBUG

PHP_METHOD(Gu3dfHeader, flush)
{
    ZEND_PARSE_PARAMETERS_NONE();

    _Gu3dfHeader* obj = O_EMBEDDED_P(_Gu3dfHeader, Z_OBJ_P(ZEND_THIS));

    flush_gu3dfHeader(obj, &obj->gu3dfHeader);

    zend_string* bin = zend_string_alloc(sizeof(Gu3dfHeader) + 1, 0);

    memcpy(
        ZSTR_VAL(bin),
        &obj->gu3dfHeader,
        sizeof(Gu3dfHeader) + 1
    );

    ZSTR_VAL(bin)[sizeof(Gu3dfHeader) + 1] = '\0'; // null terminator (optional for binary)

    RETURN_STR(bin);
}

static zend_object_handlers object_handlers;

//function that allocates memory for the object and sets the handlers
static zend_object* gr_new_obj(zend_class_entry* ce)
{
    //it allocates memory
    _Gu3dfHeader* gu3dfHeader = zend_object_alloc(sizeof(_Gu3dfHeader), ce);

    //it initializes the object
    zend_object_std_init(&gu3dfHeader->std, ce);

    object_properties_init(&gu3dfHeader->std, ce);

    //it sets the handlers
    gu3dfHeader->std.handlers = &object_handlers;

    //it returns the zend object
    return &gu3dfHeader->std;
}

static zend_object* gr_clone_obj(zend_object* object)
{
    // Step 1: Call the default clone handler
    zend_object* new_obj = gr_new_obj(object->ce);

    _Gu3dfHeader* clone = O_EMBEDDED_P(_Gu3dfHeader, new_obj);
    _Gu3dfHeader* orig = O_EMBEDDED_P(_Gu3dfHeader, object);

    memcpy(&clone->gu3dfHeader, &orig->gu3dfHeader, sizeof(Gu3dfHeader));

    zend_objects_clone_members(&clone->std, &orig->std);

    return new_obj;
}

void phpglide2x_register_gu3dfHeader(INIT_FUNC_ARGS)
{
    gu3dfHeader_ce = register_class_Gu3dfHeader(gr_flushable_ce);
    gu3dfHeader_ce->create_object = gr_new_obj; //asign an internal constructor

    memcpy(
        &object_handlers,	// our handler 
        &std_object_handlers,				        // the standard handler
        sizeof(zend_object_handlers)		        // size of the standar handler
    );

    //we set the address of the beginning of the whole embedded data
    object_handlers.offset = XtOffsetOf(_Gu3dfHeader, std);
    object_handlers.clone_obj = gr_clone_obj;
}

void flush_gu3dfHeader(const _Gu3dfHeader* gu3dfHeader, Gu3dfHeader* buffer)
{
    zval* value = zend_read_property(
        gu3dfHeader_ce,                     // zend_class_entry* of the object
        (zend_object*)&gu3dfHeader->std,    // zval* or zend_object* (see below)
        "width",                            // property name
        sizeof("width") - 1,
        1,                                  // silent (1 = don't emit notice if not found)
        NULL                                // Optional return zval ptr, or NULL
    );

    buffer->width = Z_TYPE_P(value) == IS_NULL ? 0 : Z_LVAL_P(value);



    value = zend_read_property(
        gu3dfHeader_ce,                     // zend_class_entry* of the object
        (zend_object*)&gu3dfHeader->std,    // zval* or zend_object* (see below)
        "height",                            // property name
        sizeof("height") - 1,
        1,                                  // silent (1 = don't emit notice if not found)
        NULL                                // Optional return zval ptr, or NULL
    );

    buffer->height = Z_TYPE_P(value) == IS_NULL ? 0 : Z_LVAL_P(value);



    value = zend_read_property(
        gu3dfHeader_ce,                     // zend_class_entry* of the object
        (zend_object*)&gu3dfHeader->std,    // zval* or zend_object* (see below)
        "small_lod",                            // property name
        sizeof("small_lod") - 1,
        1,                                  // silent (1 = don't emit notice if not found)
        NULL                                // Optional return zval ptr, or NULL
    );

    buffer->small_lod = Z_TYPE_P(value) == IS_NULL ? 0 : enum_to_int(Z_OBJ_P(value));



    value = zend_read_property(
        gu3dfHeader_ce,                     // zend_class_entry* of the object
        (zend_object*)&gu3dfHeader->std,    // zval* or zend_object* (see below)
        "large_lod",                            // property name
        sizeof("large_lod") - 1,
        1,                                  // silent (1 = don't emit notice if not found)
        NULL                                // Optional return zval ptr, or NULL
    );

    buffer->large_lod = Z_TYPE_P(value) == IS_NULL ? 0 : enum_to_int(Z_OBJ_P(value));



    value = zend_read_property(
        gu3dfHeader_ce,                     // zend_class_entry* of the object
        (zend_object*)&gu3dfHeader->std,    // zval* or zend_object* (see below)
        "aspect_ratio",                            // property name
        sizeof("aspect_ratio") - 1,
        1,                                  // silent (1 = don't emit notice if not found)
        NULL                                // Optional return zval ptr, or NULL
    );

    buffer->aspect_ratio = Z_TYPE_P(value) == IS_NULL ? 0 : enum_to_int(Z_OBJ_P(value));



    value = zend_read_property(
        gu3dfHeader_ce,                     // zend_class_entry* of the object
        (zend_object*)&gu3dfHeader->std,    // zval* or zend_object* (see below)
        "format",                            // property name
        sizeof("format") - 1,
        1,                                  // silent (1 = don't emit notice if not found)
        NULL                                // Optional return zval ptr, or NULL
    );

    buffer->format = Z_TYPE_P(value) == IS_NULL ? 0 : enum_to_int(Z_OBJ_P(value));
}

void hydrate_gu3dfHeader(const Gu3dfHeader* buffer, _Gu3dfHeader* gu3dfHeader)
{
    zend_update_property_long(
        gu3dfHeader_ce,
        &gu3dfHeader->std,
        "width",
        sizeof("width") - 1, buffer->width
    );

    zend_update_property_long(
        gu3dfHeader_ce,
        &gu3dfHeader->std,
        "height",
        sizeof("height") - 1, buffer->height
    );

    zval val_zv;
    ZVAL_OBJ(&val_zv, int_to_enum(buffer->small_lod, grLOD_ce));
    zend_update_property(
        gu3dfHeader_ce, &gu3dfHeader->std,
        "small_lod", sizeof("small_lod") - 1,
        &val_zv
    );

    ZVAL_OBJ(&val_zv, int_to_enum(buffer->large_lod, grLOD_ce));
    zend_update_property(
        gu3dfHeader_ce, &gu3dfHeader->std,
        "large_lod", sizeof("large_lod") - 1,
        &val_zv
    );

    ZVAL_OBJ(&val_zv, int_to_enum(buffer->aspect_ratio, grAspectRatio_ce));
    zend_update_property(
        gu3dfHeader_ce, &gu3dfHeader->std,
        "aspect_ratio", sizeof("aspect_ratio") - 1,
        &val_zv
    );

    ZVAL_OBJ(&val_zv, int_to_enum(buffer->format, grTextureFormat_ce));
    zend_update_property(
        gu3dfHeader_ce, &gu3dfHeader->std,
        "format", sizeof("format") - 1,
        &val_zv
    );

}