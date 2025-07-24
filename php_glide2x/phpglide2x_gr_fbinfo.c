#include "phpglide2x_structs.h"
#include "phpglide2x_enums.h"

zend_class_entry* grLfbInfo_ce;

#ifdef _DEBUG
ZEND_FUNCTION(testGrLfbInfo_t)
{
    zend_object* grLfbInfo_zo = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(grLfbInfo_zo, grLfbInfo_ce)
        ZEND_PARSE_PARAMETERS_END();

    _GrLfbInfo_t* config = O_EMBEDDED_P(_GrLfbInfo_t, grLfbInfo_zo);

    php_printf(
        "size: %d, lfbPtr: %s, strideInBytes: %d, writeMode: %d, origin: %d\n",
        config->grLfbInfo.size,
        config->grLfbInfo.lfbPtr,
        config->grLfbInfo.strideInBytes,
        config->grLfbInfo.writeMode,
        config->grLfbInfo.origin
    );
}
#endif // _DEBUG



PHP_METHOD(GrLfbInfo_t, flush)
{
    zend_bool write = true;

    ZEND_PARSE_PARAMETERS_START(0, 1)
        Z_PARAM_OPTIONAL
        Z_PARAM_BOOL(write);
        ZEND_PARSE_PARAMETERS_END();

    _GrLfbInfo_t* obj = O_EMBEDDED_P(_GrLfbInfo_t, Z_OBJ_P(ZEND_THIS));
      

    flush_grLfbInfo(obj, &obj->grLfbInfo, write);

    zend_string* bin = zend_string_alloc(sizeof(GrLfbInfo_t) + 1, 0);

    memcpy(
        ZSTR_VAL(bin),
        &obj->grLfbInfo,
        sizeof(GrLfbInfo_t) + 1
    );

    ZSTR_VAL(bin)[sizeof(GrLfbInfo_t) + 1] = '\0'; // null terminator (optional for binary)

    RETURN_STR(bin);
}

static zend_object_handlers object_handlers;

//function that allocates memory for the object and sets the handlers
static zend_object* gr_new_obj(zend_class_entry* ce)
{
    //it allocates memory
    _GrLfbInfo_t* grLfbInfo = zend_object_alloc(sizeof(_GrLfbInfo_t), ce);

    //it initializes the object
    zend_object_std_init(&grLfbInfo->std, ce);
    object_properties_init(&grLfbInfo->std, ce);

    grLfbInfo->grLfbInfo.size = sizeof(GrLfbInfo_t);

    //memset(&grLfbInfo->grLfbInfo, 0, sizeof(GrLfbInfo_t));

    //it sets the handlers
    grLfbInfo->std.handlers = &object_handlers;

    //it returns the zend object
    return &grLfbInfo->std;
}

static zend_object* gr_clone_obj(zend_object* object)
{
    // Step 1: Call the default clone handler
    zend_object* new_obj = gr_new_obj(object->ce);

    _GrLfbInfo_t* clone = O_EMBEDDED_P(_GrLfbInfo_t, new_obj);
    _GrLfbInfo_t* orig = O_EMBEDDED_P(_GrLfbInfo_t, object);

    memcpy(&clone->grLfbInfo, &orig->grLfbInfo, sizeof(GrLfbInfo_t));

    zend_objects_clone_members(&clone->std, &orig->std);

    return new_obj;
}
/*
static void gr_free_obj(zend_object* object)
{
    _GrLfbInfo_t* obj = O_EMBEDDED_P(_GrLfbInfo_t, object);

    zend_object_std_dtor(&obj->std);
}
*/

void phpglide2x_register_grLfbInfo(INIT_FUNC_ARGS)
{
    grLfbInfo_ce = register_class_GrLfbInfo_t(gr_flushable_ce);
    grLfbInfo_ce->create_object = gr_new_obj; //asign an internal constructor

    memcpy(
        &object_handlers,	// our handler 
        &std_object_handlers,				        // the standard handler
        sizeof(zend_object_handlers)		        // size of the standar handler
    );

    //we set the address of the beginning of the whole embedded data
    object_handlers.offset = XtOffsetOf(_GrLfbInfo_t, std);
    //object_handlers.write_property = gr_write_property;
    object_handlers.clone_obj = gr_clone_obj;
    //object_handlers.free_obj = gr_free_obj;
}

void flush_grLfbInfo(const _GrLfbInfo_t* obj, GrLfbInfo_t* buffer, bool write)
{
    zval* value = zend_read_property(
        obj->std.ce,            // zend_class_entry* of the object
        (zend_object*)&obj->std,           // zval* or zend_object* (see below)
        "size",   // property name
        sizeof("size") - 1,
        1,             // silent (1 = don't emit notice if not found)
        NULL           // Optional return zval ptr, or NULL
    );

    buffer->size = Z_TYPE_P(value) == IS_NULL ? 0 : Z_LVAL_P(value);

    if (write) {
        value = zend_read_property(
            obj->std.ce,            // zend_class_entry* of the object
            (zend_object*)&obj->std,           // zval* or zend_object* (see below)
            "lfbPtr",   // property name
            sizeof("lfbPtr") - 1,
            1,             // silent (1 = don't emit notice if not found)
            NULL           // Optional return zval ptr, or NULL
        );

        if (buffer->lfbPtr) {
            memcpy(buffer->lfbPtr, Z_STRVAL_P(value), Z_STRLEN_P(value));
        }
    }

    value = zend_read_property(
        obj->std.ce,            // zend_class_entry* of the object
        (zend_object*)&obj->std,           // zval* or zend_object* (see below)
        "strideInBytes",   // property name
        sizeof("strideInBytes") - 1,
        1,             // silent (1 = don't emit notice if not found)
        NULL           // Optional return zval ptr, or NULL
    );

    buffer->strideInBytes = Z_TYPE_P(value) == IS_NULL ? 0 : Z_LVAL_P(value);

    value = zend_read_property(
        obj->std.ce,            // zend_class_entry* of the object
        (zend_object*)&obj->std,           // zval* or zend_object* (see below)
        "writeMode",   // property name
        sizeof("writeMode") - 1,
        1,             // silent (1 = don't emit notice if not found)
        NULL           // Optional return zval ptr, or NULL
    );

    buffer->writeMode = Z_TYPE_P(value) == IS_NULL ? 0 : enum_to_int(Z_OBJ_P(value));

    value = zend_read_property(
        obj->std.ce,            // zend_class_entry* of the object
        (zend_object*)&obj->std,           // zval* or zend_object* (see below)
        "origin",   // property name
        sizeof("origin") - 1,
        1,             // silent (1 = don't emit notice if not found)
        NULL           // Optional return zval ptr, or NULL
    );

    buffer->origin = Z_TYPE_P(value) == IS_NULL ? 0 : enum_to_int(Z_OBJ_P(value));
}

void hydrate_grLfbInfo(const GrLfbInfo_t* buffer, _GrLfbInfo_t* grLfbInfo, bool read)
{
    zend_update_property_long(
        grLfbInfo_ce,
        &grLfbInfo->std,
        "size", 
        sizeof("size") - 1, 
        buffer->size
    );

    if (read) {
        zend_update_property_stringl(
            grLfbInfo_ce,
            &grLfbInfo->std,
            "lfbPtr",
            sizeof("lfbPtr") - 1,
            buffer->lfbPtr,
            buffer->size
        );
    }

    //php_printf("[%d]\n", buffer->size);

    zend_update_property_long(
        grLfbInfo_ce,
        &grLfbInfo->std,
        "strideInBytes",
        sizeof("strideInBytes") - 1,
        buffer->strideInBytes
    );
   
    zend_object* enum_case = NULL;
    zval val_zv;

    enum_case = int_to_enum(buffer->writeMode, grLfbWriteMode_ce);

    ZVAL_OBJ(&val_zv, enum_case);
    zend_update_property(
        grLfbInfo_ce, &grLfbInfo->std,
        "writeMode", sizeof("writeMode") - 1,
        &val_zv
    );


    enum_case = int_to_enum(buffer->origin, grOriginLocation_ce);

    ZVAL_OBJ(&val_zv, enum_case);
    zend_update_property(
        grLfbInfo_ce, &grLfbInfo->std,
        "origin", sizeof("origin") - 1,
        &val_zv
    );
}