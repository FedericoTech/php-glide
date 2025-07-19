#include "phpglide2x_structs.h"

zend_class_entry* grTMUConfig_ce;

#ifdef _DEBUG
ZEND_FUNCTION(testGrTMUConfig_t)
{
    zend_object* grTMUConfig_zo = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(grTMUConfig_zo, grTMUConfig_ce)
    ZEND_PARSE_PARAMETERS_END();

    _GrTMUConfig_t* config = O_EMBEDDED_P(_GrTMUConfig_t, grTMUConfig_zo);

    php_printf(
        "tmuRev: %d, tmuRam: %d\n",
        config->grTMUConfig.tmuRev,
        config->grTMUConfig.tmuRam
    );
}
#endif // _DEBUG

PHP_METHOD(GrTMUConfig_t, flush)
{
    ZEND_PARSE_PARAMETERS_NONE();

    _GrTMUConfig_t* obj = O_EMBEDDED_P(_GrTMUConfig_t, Z_OBJ_P(ZEND_THIS));

    flush_grTMUConfig(obj, &obj->grTMUConfig);

    zend_string* bin = zend_string_alloc(sizeof(GrTMUConfig_t) + 1, 0);
    
    memcpy(
        ZSTR_VAL(bin), 
        &obj->grTMUConfig,
        sizeof(GrTMUConfig_t) + 1
    );

    ZSTR_VAL(bin)[sizeof(GrTMUConfig_t)+1] = '\0'; // null terminator (optional for binary)
    
    RETURN_STR(bin);
}

static zend_object_handlers grTMUConfig_object_handlers;

//function that allocates memory for the object and sets the handlers
static zend_object* gr_new_obj(zend_class_entry* ce)
{
    //it allocates memory
    _GrTMUConfig_t* grTMUConfig = zend_object_alloc(sizeof(_GrTMUConfig_t), ce);

    //it initializes the object
    zend_object_std_init(&grTMUConfig->std, ce);
    object_properties_init(&grTMUConfig->std, ce);

    //it sets the handlers
    grTMUConfig->std.handlers = &grTMUConfig_object_handlers;

    //it returns the zend object
    return &grTMUConfig->std;
}

static zend_object* gr_clone_obj(zend_object* object)
{
    // Step 1: Call the default clone handler
    zend_object* new_obj = gr_new_obj(object->ce);

    _GrTMUConfig_t* clone = O_EMBEDDED_P(_GrTMUConfig_t, new_obj);
    _GrTMUConfig_t* orig = O_EMBEDDED_P(_GrTMUConfig_t, object);

    //flush_grTMUConfig(orig, &orig->grTMUConfig);

    memcpy(&clone->grTMUConfig, &orig->grTMUConfig, sizeof(GrTMUConfig_t));

    zend_objects_clone_members(&clone->std, &orig->std);

    return new_obj;
}

void phpglide2x_register_grTMUConfig(INIT_FUNC_ARGS)
{
    grTMUConfig_ce = register_class_GrTMUConfig_t(gr_flushable_ce);
    grTMUConfig_ce->create_object = gr_new_obj; //asign an internal constructor

    memcpy(
        &grTMUConfig_object_handlers,	// our handler 
        &std_object_handlers,				        // the standard handler
        sizeof(zend_object_handlers)		        // size of the standar handler
    );

    //we set the address of the beginning of the whole embedded data
    grTMUConfig_object_handlers.offset = XtOffsetOf(_GrTMUConfig_t, std);

    //grTMUConfig_object_handlers.write_property = gr_write_property;
    grTMUConfig_object_handlers.clone_obj = gr_clone_obj;
}

void flush_grTMUConfig(const _GrTMUConfig_t *obj, GrTMUConfig_t* buffer)
{
    zval* value = zend_read_property(
        obj->std.ce,            // zend_class_entry* of the object
        (zend_object*)&obj->std,           // zval* or zend_object* (see below)
        "tmuRev",   // property name
        sizeof("tmuRev") - 1,
        1,             // silent (1 = don't emit notice if not found)
        NULL           // Optional return zval ptr, or NULL
    );

    buffer->tmuRev = Z_TYPE_P(value) == IS_NULL ? 0 : Z_LVAL_P(value);

    value = zend_read_property(
        obj->std.ce,            // zend_class_entry* of the object
        (zend_object*)&obj->std,           // zval* or zend_object* (see below)
        "tmuRam",   // property name
        sizeof("tmuRam") - 1,
        1,             // silent (1 = don't emit notice if not found)
        NULL           // Optional return zval ptr, or NULL
    );

    buffer->tmuRam = Z_TYPE_P(value) == IS_NULL ? 0 : Z_LVAL_P(value);
}

void hydrate_grTMUConfig(const GrTMUConfig_t* tmuConfig, _GrTMUConfig_t* grTMUConfig)
{

    zend_update_property_long(grTMUConfig_ce, &grTMUConfig->std, "tmuRev", sizeof("tmuRev") - 1, tmuConfig->tmuRev);

    zend_update_property_long(grTMUConfig_ce, &grTMUConfig->std, "tmuRam", sizeof("tmuRam") - 1, tmuConfig->tmuRam);
}