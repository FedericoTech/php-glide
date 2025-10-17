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

    zend_string* bin = zend_string_alloc(sizeof(GrState), 0);

    *ZSTR_VAL(bin) = *(char*)&obj->grState;

    ZSTR_VAL(bin)[sizeof(GrState)] = '\0'; // null terminator (optional for binary)

    RETURN_STR(bin);
}

static zend_object_handlers object_handlers;

//function that allocates memory for the object and sets the handlers
static zend_object* gr_new_obj(zend_class_entry* ce)
{
    //it allocates memory
    _GrState* grState = zend_object_alloc(sizeof(_GrState), ce);

    //it initializes the object
    zend_object_std_init(&grState->std, ce);
    object_properties_init(&grState->std, ce);

    //it sets the handlers
    grState->std.handlers = &object_handlers;

    //it returns the zend object
    return &grState->std;
}

static zend_object* gr_clone_obj(zend_object* object)
{
    // Step 1: Call the default clone handler
    zend_object* new_obj = gr_new_obj(object->ce);

    _GrState* clone = O_EMBEDDED_P(_GrState, new_obj);
    _GrState* orig = O_EMBEDDED_P(_GrState, object);

    clone->grState = orig->grState;

    zend_objects_clone_members(&clone->std, &orig->std);

    return new_obj;
}

void phpglide2x_register_grState(INIT_FUNC_ARGS)
{
    grState_ce = register_class_GrState(gr_flushable_ce);
    grState_ce->create_object = gr_new_obj; //asign an internal constructor

    object_handlers = std_object_handlers;

    //we set the address of the beginning of the whole embedded data
    object_handlers.offset = XtOffsetOf(_GrState, std);
    //object_handlers.write_property = gr_write_property;
    object_handlers.clone_obj = gr_clone_obj;
}

void flush_grState(const _GrState* obj, GrState* buffer)
{
    zval* value = zend_read_property(
        grState_ce,         // zend_class_entry* of the object
        (zend_object*)&obj->std,  // zval* or zend_object* (see below)
        "pad",              // property name
        sizeof("pad") - 1,
        1,                  // silent (1 = don't emit notice if not found)
        NULL                // Optional return zval ptr, or NULL
    );

    if (Z_TYPE_P(value) == IS_NULL) {
        memset(buffer->pad, 0, sizeof(buffer->pad));
    }
    else {
        size_t len = MIN(Z_STRLEN_P(value), sizeof(buffer->pad));
        // Make sure not to overflow the destination buffer
        memcpy(buffer->pad, Z_STRVAL_P(value), len);
        
        if (len < sizeof(buffer->pad)) {
            memset(buffer->pad + len, 0, sizeof(buffer->pad) - len);
        }
    }
}

void hydrate_grState(const GrState* buffer, _GrState* obj)
{
    zend_update_property_stringl(
        grState_ce,
        &obj->std,
        "pad",
        sizeof("pad") - 1,
        buffer->pad, 
        GLIDE_STATE_PAD_SIZE
    );
}