#include "phpglide2x_structs.h"

zend_class_entry* grAT3DConfig_ce;

#ifdef _DEBUG
ZEND_FUNCTION(testGrAT3DConfig_t)
{
    zend_object* grAT3DConfig_zo = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(grAT3DConfig_zo, grAT3DConfig_ce)
    ZEND_PARSE_PARAMETERS_END();

    _GrAT3DConfig_t* config = O_EMBEDDED_P(_GrAT3DConfig_t, grAT3DConfig_zo);

    php_printf(
        "rev: %d\n",
        config->grAT3DConfig.rev
    );
}
#endif // _DEBUG

PHP_METHOD(GrAT3DConfig_t, flush)
{
    ZEND_PARSE_PARAMETERS_NONE();

    _GrAT3DConfig_t* obj = O_EMBEDDED_P(_GrAT3DConfig_t, Z_OBJ_P(ZEND_THIS));

    flush_GrAT3DConfig(obj, &obj->grAT3DConfig);

    zend_string* bin = zend_string_alloc(sizeof(GrAT3DConfig_t) + 1, 0);

    memcpy(
        ZSTR_VAL(bin),
        &obj->grAT3DConfig,
        sizeof(GrAT3DConfig_t) + 1
    );

    ZSTR_VAL(bin)[sizeof(GrAT3DConfig_t) + 1] = '\0'; // null terminator (optional for binary)

    RETURN_STR(bin);
}

static zend_object_handlers grAT3DConfig_object_handlers;

//function that allocates memory for the object and sets the handlers
zend_object* GrAT3DConfig_new(zend_class_entry* ce)
{
    //it allocates memory
    _GrAT3DConfig_t* grAT3DConfig = zend_object_alloc(sizeof(_GrAT3DConfig_t), ce);

    //it initializes the object
    zend_object_std_init(&grAT3DConfig->std, ce);
    object_properties_init(&grAT3DConfig->std, ce);

    //it sets the handlers
    grAT3DConfig->std.handlers = &grAT3DConfig_object_handlers;

    //it returns the zend object
    return &grAT3DConfig->std;
}

/*
static zval* gr_write_property(zend_object* object, zend_string* member, zval* value, void** cache_slot)
{
    if (object->ce == grAT3DConfig_ce) {

        _GrAT3DConfig_t* config = O_EMBEDDED_P(_GrAT3DConfig_t, object);  // Get your embedded struct from the object

        if (zend_string_equals_literal(member, "rev")) {
            config->grAT3DConfig.rev = Z_LVAL_P(value);
        }
    }

    return zend_std_write_property(object, member, value, cache_slot);
}
*/

static zend_object* gr_clone_obj(zend_object* object)
{
    // Step 1: Call the default clone handler
    zend_object* new_obj = GrAT3DConfig_new(object->ce);

    _GrAT3DConfig_t* clone = O_EMBEDDED_P(_GrAT3DConfig_t, new_obj);
    _GrAT3DConfig_t* orig = O_EMBEDDED_P(_GrAT3DConfig_t, object);

    memcpy(&clone->grAT3DConfig, &orig->grAT3DConfig, sizeof(GrAT3DConfig_t));

    zend_objects_clone_members(&clone->std, &orig->std);

    return new_obj;
}

void phpglide2x_register_grAT3DConfig(INIT_FUNC_ARGS)
{
	grAT3DConfig_ce = register_class_GrAT3DConfig_t(gr_flushable_ce);
    grAT3DConfig_ce->create_object = GrAT3DConfig_new; //asign an internal constructor

    memcpy(
        &grAT3DConfig_object_handlers,	// our handler 
        &std_object_handlers,				        // the standard handler
        sizeof(zend_object_handlers)		        // size of the standar handler
    );

    //we set the address of the beginning of the whole embedded data
    grAT3DConfig_object_handlers.offset = XtOffsetOf(_GrAT3DConfig_t, std);
    //grAT3DConfig_object_handlers.write_property = gr_write_property;
    grAT3DConfig_object_handlers.clone_obj = gr_clone_obj;
}

void flush_GrAT3DConfig(const _GrAT3DConfig_t* obj, GrAT3DConfig_t* buffer)
{
    zval* value = zend_read_property(
        obj->std.ce,            // zend_class_entry* of the object
        (zend_object*)&obj->std,           // zval* or zend_object* (see below)
        "rev",   // property name
        sizeof("rev") - 1,
        1,             // silent (1 = don't emit notice if not found)
        NULL           // Optional return zval ptr, or NULL
    );

    buffer->rev = Z_TYPE_P(value) == IS_NULL ? 0 : Z_LVAL_P(value);
}

void hydrate_GrAT3DConfig(const GrAT3DConfig_t* buffer, _GrAT3DConfig_t* grAT3DConfig)
{
    zend_update_property_long(
        grAT3DConfig_ce, 
        &grAT3DConfig->std, 
        "rev", 
        sizeof("rev") - 1, buffer->rev
    );
}