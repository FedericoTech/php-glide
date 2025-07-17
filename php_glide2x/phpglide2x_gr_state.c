#include "phpglide2x_structs.h"

zend_class_entry* grState_ce;

#ifdef _DEBUG
ZEND_FUNCTION(testGrState)
{
    zend_object* grState_zo = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(grState_zo, grState_ce)
        ZEND_PARSE_PARAMETERS_END();

    _GrState* config = O_EMBEDDED_P(_GrState, grState_zo);

    php_printf(
        "pad: %s\n",
        config->grState.pad
    );
}
#endif // _DEBUG

PHP_METHOD(GrState, flush)
{
    ZEND_PARSE_PARAMETERS_NONE();

    _GrState* obj = O_EMBEDDED_P(_GrState, Z_OBJ_P(ZEND_THIS));

    flush_grState(obj, &obj->grState);

    zend_string* bin = zend_string_alloc(sizeof(GrState) + 1, 0);

    memcpy(
        ZSTR_VAL(bin),
        &obj->grState,
        sizeof(GrState) + 1
    );

    ZSTR_VAL(bin)[sizeof(GrState) + 1] = '\0'; // null terminator (optional for binary)

    RETURN_STR(bin);
}

static zend_object_handlers grState_object_handlers;

//function that allocates memory for the object and sets the handlers
zend_object* GrState_new(zend_class_entry* ce)
{
    //it allocates memory
    _GrState* grState = zend_object_alloc(sizeof(_GrState), ce);

    //it initializes the object
    zend_object_std_init(&grState->std, ce);
    object_properties_init(&grState->std, ce);

    //it sets the handlers
    grState->std.handlers = &grState_object_handlers;

    //it returns the zend object
    return &grState->std;
}

static zend_object* gr_clone_obj(zend_object* object)
{
    // Step 1: Call the default clone handler
    zend_object* new_obj = GrState_new(object->ce);

    _GrState* clone = O_EMBEDDED_P(_GrState, new_obj);
    _GrState* orig = O_EMBEDDED_P(_GrState, object);

    memcpy(&clone->grState, &orig->grState, sizeof(GrState));

    zend_objects_clone_members(&clone->std, &orig->std);

    return new_obj;
}

void phpglide2x_register_grState(INIT_FUNC_ARGS)
{
    grState_ce = register_class_GrState(gr_flushable_ce);
    grState_ce->create_object = GrState_new; //asign an internal constructor

    memcpy(
        &grState_object_handlers,	// our handler 
        &std_object_handlers,				        // the standard handler
        sizeof(zend_object_handlers)		        // size of the standar handler
    );

    //we set the address of the beginning of the whole embedded data
    grState_object_handlers.offset = XtOffsetOf(_GrState, std);
    //grAT3DConfig_object_handlers.write_property = gr_write_property;
    grState_object_handlers.clone_obj = gr_clone_obj;
}

void flush_grState(const _GrState* obj, GrState* buffer)
{
    zval* value = zend_read_property(
        obj->std.ce,            // zend_class_entry* of the object
        (zend_object*)&obj->std,           // zval* or zend_object* (see below)
        "pad",   // property name
        sizeof("pad") - 1,
        1,             // silent (1 = don't emit notice if not found)
        NULL           // Optional return zval ptr, or NULL
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

void hydrate_grState(const GrState* buffer, _GrState* grState)
{
    zend_update_property_stringl(
        grState_ce,
        &grState->std,
        "pad",
        sizeof("pad") - 1,
        buffer->pad, 
        GLIDE_STATE_PAD_SIZE
    );
}