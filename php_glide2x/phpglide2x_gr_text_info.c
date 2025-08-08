#include "phpglide2x_structs.h"
#include "phpglide2x_enums.h"

zend_class_entry* grTexInfo_ce;

#ifdef _DEBUG
ZEND_FUNCTION(testGrTexInfo)
{
    zend_object* grTexInfo_zo = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(grTexInfo_zo, grTexInfo_ce)
        ZEND_PARSE_PARAMETERS_END();

    _GrTexInfo* config = O_EMBEDDED_P(_GrTexInfo, grTexInfo_zo);

    php_printf(
        "smallLod: %d, largeLod: %d, aspectRatio: %d, format: %d, data: %p\n",
        config->grTexInfo.smallLod,
        config->grTexInfo.largeLod,
        config->grTexInfo.aspectRatio,
        config->grTexInfo.format,
        config->grTexInfo.data
    );
}
#endif // _DEBUG



PHP_METHOD(GrTexInfo, flush)
{
    zend_bool write = true;

    ZEND_PARSE_PARAMETERS_START(0, 1)
        Z_PARAM_OPTIONAL
        Z_PARAM_BOOL(write);
    ZEND_PARSE_PARAMETERS_END();

    _GrTexInfo* obj = O_EMBEDDED_P(_GrTexInfo, Z_OBJ_P(ZEND_THIS));


    flush_grTexInfo(obj, &obj->grTexInfo /*, write*/);

    zend_string* bin = zend_string_alloc(sizeof(GrTexInfo) + 1, 0);

    memcpy(
        ZSTR_VAL(bin),
        &obj->grTexInfo,
        sizeof(GrTexInfo) + 1
    );

    ZSTR_VAL(bin)[sizeof(GrTexInfo) + 1] = '\0'; // null terminator (optional for binary)

    RETURN_STR(bin);
}

static zend_object_handlers object_handlers;

//function that allocates memory for the object and sets the handlers
static zend_object* gr_new_obj(zend_class_entry* ce)
{
    //it allocates memory
    _GrTexInfo* grTexInfo = zend_object_alloc(sizeof(_GrTexInfo), ce);

    //it initializes the object
    zend_object_std_init(&grTexInfo->std, ce);
    object_properties_init(&grTexInfo->std, ce);

    //it sets the handlers
    grTexInfo->std.handlers = &object_handlers;

    grTexInfo->grTexInfo.data = NULL;

    //it returns the zend object
    return &grTexInfo->std;
}

static zend_object* gr_clone_obj(zend_object* object)
{
    // Step 1: Call the default clone handler
    zend_object* new_obj = gr_new_obj(object->ce);

    _GrTexInfo* clone = O_EMBEDDED_P(_GrTexInfo, new_obj);
    _GrTexInfo* orig = O_EMBEDDED_P(_GrTexInfo, object);

    memcpy(&clone->grTexInfo, &orig->grTexInfo, sizeof(GrTexInfo));

    zend_objects_clone_members(&clone->std, &orig->std);

    return new_obj;
}

static void gr_free_obj(zend_object* object)
{
    _GrTexInfo* obj = O_EMBEDDED_P(_GrTexInfo, object);

    if (obj->grTexInfo.data) {
        efree(obj->grTexInfo.data);
    }

    zend_object_std_dtor(&obj->std);
}

void phpglide2x_register_grTexInfo(INIT_FUNC_ARGS)
{
    grTexInfo_ce = register_class_GrTexInfo(gr_flushable_ce);
    grTexInfo_ce->create_object = gr_new_obj; //asign an internal constructor

    memcpy(
        &object_handlers,	// our handler 
        &std_object_handlers,				        // the standard handler
        sizeof(zend_object_handlers)		        // size of the standar handler
    );

    //we set the address of the beginning of the whole embedded data
    object_handlers.offset = XtOffsetOf(_GrTexInfo, std);
    //object_handlers.write_property = gr_write_property;
    object_handlers.clone_obj = gr_clone_obj;
    object_handlers.free_obj = gr_free_obj;
}

void flush_grTexInfo(const _GrTexInfo* obj, GrTexInfo* buffer /*, bool write*/ )
{
    zval* value = zend_read_property(
        obj->std.ce,            // zend_class_entry* of the object
        (zend_object*)&obj->std,           // zval* or zend_object* (see below)
        "smallLod",   // property name
        sizeof("smallLod") - 1,
        1,             // silent (1 = don't emit notice if not found)
        NULL           // Optional return zval ptr, or NULL
    );

    buffer->smallLod = Z_TYPE_P(value) == IS_NULL ? 0 : enum_to_int(Z_OBJ_P(value));


    value = zend_read_property(
        obj->std.ce,            // zend_class_entry* of the object
        (zend_object*)&obj->std,           // zval* or zend_object* (see below)
        "largeLod",   // property name
        sizeof("largeLod") - 1,
        1,             // silent (1 = don't emit notice if not found)
        NULL           // Optional return zval ptr, or NULL
    );

    buffer->largeLod = Z_TYPE_P(value) == IS_NULL ? 0 : enum_to_int(Z_OBJ_P(value));

    value = zend_read_property(
        obj->std.ce,            // zend_class_entry* of the object
        (zend_object*)&obj->std,           // zval* or zend_object* (see below)
        "aspectRatio",   // property name
        sizeof("aspectRatio") - 1,
        1,             // silent (1 = don't emit notice if not found)
        NULL           // Optional return zval ptr, or NULL
    );

    buffer->aspectRatio = Z_TYPE_P(value) == IS_NULL ? 0 : enum_to_int(Z_OBJ_P(value));

    value = zend_read_property(
        obj->std.ce,            // zend_class_entry* of the object
        (zend_object*)&obj->std,           // zval* or zend_object* (see below)
        "format",   // property name
        sizeof("format") - 1,
        1,             // silent (1 = don't emit notice if not found)
        NULL           // Optional return zval ptr, or NULL
    );

    buffer->format = Z_TYPE_P(value) == IS_NULL ? 0 : enum_to_int(Z_OBJ_P(value));

    value = zend_read_property(
        obj->std.ce,            // zend_class_entry* of the object
        (zend_object*)&obj->std,           // zval* or zend_object* (see below)
        "data",   // property name
        sizeof("data") - 1,
        1,             // silent (1 = don't emit notice if not found)
        NULL           // Optional return zval ptr, or NULL
    );

    //php_printf("[%p]\n", buffer->data);

    if (buffer->data) {
        efree(buffer->data);
    }

    buffer->data = emalloc(Z_STRLEN_P(value));

    memcpy(buffer->data, Z_STRVAL_P(value), Z_STRLEN_P(value));
}

void hydrate_grTexInfo(const GrTexInfo* buffer, _GrTexInfo* obj /*, bool read*/)
{
    /*
    if (buffer->data) {

        size_t buffer_size = buffer->strideInBytes * grSstScreenHeight();

        zend_string* zstr = zend_string_alloc(buffer_size, 0);

        if (read) {
            memcpy(
                ZSTR_VAL(zstr),
                buffer->lfbPtr,
                buffer_size
            );
        }
        else {
            memset(
                ZSTR_VAL(zstr),
                0,
                buffer_size
            );
        }

        ZSTR_VAL(zstr)[buffer_size] = '\0'; // null-terminate for safety

        zend_update_property_str(
            grLfbInfo_ce,
            &grLfbInfo->std,
            "lfbPtr",
            sizeof("lfbPtr") - 1,
            zstr
        );

        zend_string_release(zstr); // zend_update_property will add a ref
    }
    */

    zend_object* enum_case = NULL;
    zval val_zv;

    enum_case = int_to_enum(buffer->smallLod, grLOD_ce);

    ZVAL_OBJ(&val_zv, enum_case);
    zend_update_property(
        grTexInfo_ce, &obj->std,
        "smallLod", sizeof("smallLod") - 1,
        &val_zv
    );


    enum_case = int_to_enum(buffer->largeLod, grLOD_ce);

    ZVAL_OBJ(&val_zv, enum_case);
    zend_update_property(
        grTexInfo_ce, &obj->std,
        "largeLod", sizeof("largeLod") - 1,
        &val_zv
    );


    enum_case = int_to_enum(buffer->aspectRatio, grAspectRatio_ce);

    ZVAL_OBJ(&val_zv, enum_case);
    zend_update_property(
        grTexInfo_ce, &obj->std,
        "aspectRatio", sizeof("aspectRatio") - 1,
        &val_zv
    );


    enum_case = int_to_enum(buffer->format, grTextureFormat_ce);

    ZVAL_OBJ(&val_zv, enum_case);
    zend_update_property(
        grTexInfo_ce, &obj->std,
        "format", sizeof("format") - 1,
        &val_zv
    );

    if (buffer->data) {
        /*
        size_t buffer_size = buffer->strideInBytes * grSstScreenHeight();

        zend_string* zstr = zend_string_alloc(buffer_size, 0);

        if (read) {
            memcpy(
                ZSTR_VAL(zstr),
                buffer->data,
                buffer_size
            );
        }
        else {
            memset(
                ZSTR_VAL(zstr),
                0,
                buffer_size
            );
        }

        ZSTR_VAL(zstr)[buffer_size] = '\0'; // null-terminate for safety

        zend_update_property_str(
            grTexInfo_ce,
            &obj->std,
            "data",
            sizeof("data") - 1,
            zstr
        );

        zend_string_release(zstr); // zend_update_property will add a ref
        */
    }
}