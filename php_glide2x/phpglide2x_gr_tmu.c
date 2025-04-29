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

static zend_object_handlers grTMUConfig_object_handlers;

//function that allocates memory for the object and sets the handlers
zend_object* GrTMUConfig_new(zend_class_entry* ce)
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

static zval* gr_write_property(zend_object* object, zend_string* member, zval* value, void** cache_slot)
{
    if (zend_string_equals_literal(object->ce->name, "GrTMUConfig_t")) {

        _GrTMUConfig_t* config = O_EMBEDDED_P(_GrTMUConfig_t, object);  // Get your embedded struct from the object

        //if the property we are checking is factor and the value is integer...
        if (zend_string_equals_literal(member, "tmuRev") && Z_TYPE_P(value) == IS_LONG) {

            //we update the inner field
            config->grTMUConfig.tmuRev = Z_LVAL_P(value);
        }

        //if the property we are checking is factor and the value is integer...
        else if (zend_string_equals_literal(member, "tmuRam") && Z_TYPE_P(value) == IS_LONG) {

            //we update the inner field
            config->grTMUConfig.tmuRam = Z_LVAL_P(value);
        }
    }

    return zend_std_write_property(object, member, value, cache_slot);
}

void phpglide2x_register_grTMUConfig(INIT_FUNC_ARGS)
{
    grTMUConfig_ce = register_class_GrTMUConfig_t();
    grTMUConfig_ce->create_object = GrTMUConfig_new; //asign an internal constructor

    memcpy(
        &grTMUConfig_object_handlers,	// our handler 
        &std_object_handlers,				        // the standard handler
        sizeof(zend_object_handlers)		        // size of the standar handler
    );

    //we set the address of the beginning of the whole embedded data
    grTMUConfig_object_handlers.offset = XtOffsetOf(_GrTMUConfig_t, std);

    grTMUConfig_object_handlers.write_property = gr_write_property;
}