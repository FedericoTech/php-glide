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
    ZEND_PARSE_PARAMETERS_NONE();

    _GrLfbInfo_t* obj = O_EMBEDDED_P(_GrLfbInfo_t, Z_OBJ_P(ZEND_THIS));

    flush_grLfbInfo(obj, &obj->grLfbInfo);

    zend_string* bin = zend_string_alloc(sizeof(GrLfbInfo_t) + 1, 0);

    memcpy(
        ZSTR_VAL(bin),
        &obj->grLfbInfo,
        sizeof(GrLfbInfo_t) + 1
    );

    ZSTR_VAL(bin)[sizeof(GrLfbInfo_t) + 1] = '\0'; // null terminator (optional for binary)

    RETURN_STR(bin);
}

static zend_object_handlers grLfbInfo_object_handlers;

//function that allocates memory for the object and sets the handlers
zend_object* GrLfbInfo_new(zend_class_entry* ce)
{
    //it allocates memory
    _GrLfbInfo_t* grLfbInfo = zend_object_alloc(sizeof(_GrLfbInfo_t), ce);

    //it initializes the object
    zend_object_std_init(&grLfbInfo->std, ce);
    object_properties_init(&grLfbInfo->std, ce);

    //it sets the handlers
    grLfbInfo->std.handlers = &grLfbInfo_object_handlers;

    //it returns the zend object
    return &grLfbInfo->std;
}

static zend_object* gr_clone_obj(zend_object* object)
{
    // Step 1: Call the default clone handler
    zend_object* new_obj = GrLfbInfo_new(object->ce);

    _GrLfbInfo_t* clone = O_EMBEDDED_P(_GrLfbInfo_t, new_obj);
    _GrLfbInfo_t* orig = O_EMBEDDED_P(_GrLfbInfo_t, object);

    memcpy(&clone->grLfbInfo, &orig->grLfbInfo, sizeof(GrLfbInfo_t));

    zend_objects_clone_members(&clone->std, &orig->std);

    return new_obj;
}

void phpglide2x_register_grLfbInfo(INIT_FUNC_ARGS)
{
    grLfbInfo_ce = register_class_GrLfbInfo_t(gr_flushable_ce);
    grLfbInfo_ce->create_object = GrLfbInfo_new; //asign an internal constructor

    memcpy(
        &grLfbInfo_object_handlers,	// our handler 
        &std_object_handlers,				        // the standard handler
        sizeof(zend_object_handlers)		        // size of the standar handler
    );

    //we set the address of the beginning of the whole embedded data
    grLfbInfo_object_handlers.offset = XtOffsetOf(_GrState, std);
    //grAT3DConfig_object_handlers.write_property = gr_write_property;
    grLfbInfo_object_handlers.clone_obj = gr_clone_obj;
}

void flush_grLfbInfo(const _GrLfbInfo_t* obj, GrLfbInfo_t* buffer)
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

    value = zend_read_property(
        obj->std.ce,            // zend_class_entry* of the object
        (zend_object*)&obj->std,           // zval* or zend_object* (see below)
        "lfbPtr",   // property name
        sizeof("lfbPtr") - 1,
        1,             // silent (1 = don't emit notice if not found)
        NULL           // Optional return zval ptr, or NULL
    );

    if (Z_TYPE_P(value) == IS_NULL) {
        buffer->lfbPtr = '\0';
    }
    else {
        const char* str = Z_STRVAL_P(value);
        size_t len = Z_STRLEN_P(value);
        // Make sure not to overflow the destination buffer
        strncpy_s(buffer->lfbPtr, sizeof(buffer->lfbPtr), str, _TRUNCATE);
        buffer->lfbPtr[sizeof(buffer->lfbPtr) - 1] = '\0';  // Ensure null-termination
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

    buffer->writeMode = Z_TYPE_P(value) == IS_NULL ? 0 : enum_to_int(Z_OBJ_P(value));
}

void hydrate_grLfbInfo(const GrLfbInfo_t* buffer, _GrLfbInfo_t* grLfbInfo)
{
    zend_update_property_long(
        grLfbInfo_ce,
        &grLfbInfo->std,
        "size", 
        sizeof("size") - 1, 
        buffer->size
    );

    zend_update_property_stringl(
        grLfbInfo_ce,
        &grLfbInfo->std,
        "lfbPtr",
        sizeof("lfbPtr") - 1,
        buffer->lfbPtr,
        buffer->size
    );

    zend_update_property_long(
        grLfbInfo_ce,
        &grLfbInfo->std,
        "strideInBytes",
        sizeof("strideInBytes") - 1,
        buffer->strideInBytes
    );

    zend_object* enum_case = NULL;
    zval val_zv;

    switch (buffer->writeMode) {
    case GR_LFBWRITEMODE_565:
        enum_case = zend_enum_get_case_cstr(grLfbWriteMode_ce, "GR_LFBWRITEMODE_565");
        break;
    }
    

    ZVAL_OBJ(&val_zv, enum_case);
    zend_update_property(
        grLfbInfo_ce, &grLfbInfo->std,
        "writeMode", sizeof("writeMode") - 1,
        &val_zv
    );



    switch (buffer->origin) {
    case GR_LFBWRITEMODE_565:
        enum_case = zend_enum_get_case_cstr(grOriginLocation_ce, "GR_ORIGIN_UPPER_LEFT");
        break;
    }

    ZVAL_OBJ(&val_zv, enum_case);
    zend_update_property(
        grLfbInfo_ce, &grLfbInfo->std,
        "origin", sizeof("origin") - 1,
        &val_zv
    );

}