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


static zval* gr_write_property(zend_object* object, zend_string* member, zval* value, void** cache_slot)
{
    if (zend_string_equals_literal(object->ce->name, "GrAT3DConfig_t")) {

        _GrAT3DConfig_t* config = O_EMBEDDED_P(_GrAT3DConfig_t, object);  // Get your embedded struct from the object

        if (zend_string_equals_literal(member, "rev")) {
            config->grAT3DConfig.rev = Z_LVAL_P(value);
        }
    }

    return zend_std_write_property(object, member, value, cache_slot);
}

void phpglide2x_register_grAT3DConfig(INIT_FUNC_ARGS)
{
	grAT3DConfig_ce = register_class_GrAT3DConfig_t();
    grAT3DConfig_ce->create_object = GrAT3DConfig_new; //asign an internal constructor

    memcpy(
        &grAT3DConfig_object_handlers,	// our handler 
        &std_object_handlers,				        // the standard handler
        sizeof(zend_object_handlers)		        // size of the standar handler
    );

    //we set the address of the beginning of the whole embedded data
    grAT3DConfig_object_handlers.offset = XtOffsetOf(_GrAT3DConfig_t, std);
    grAT3DConfig_object_handlers.write_property = gr_write_property;
}