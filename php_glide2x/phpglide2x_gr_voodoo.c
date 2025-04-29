#include "phpglide2x_structs.h"

zend_class_entry* grVoodooConfig_ce;
zend_class_entry* grVoodoo2Config_ce;

#ifdef _DEBUG
ZEND_FUNCTION(testGrVoodooConfig_t)
{
    zend_object* grVoodooConfig_zo = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(grVoodooConfig_zo, grVoodooConfig_ce)
        ZEND_PARSE_PARAMETERS_END();

    _GrVoodooConfig_t* config = O_EMBEDDED_P(_GrVoodooConfig_t, grVoodooConfig_zo);

    php_printf(
        "fbRam: %d, fbiRev: %d, nTexelfx: %d, sliDetect: %d\n",
        config->grVoodooConfig.fbRam,
        config->grVoodooConfig.fbiRev,
        config->grVoodooConfig.nTexelfx,
        config->grVoodooConfig.sliDetect
    );

    for (uint32_t cont = 0; cont < GLIDE_NUM_TMU; cont++) {

        php_printf(
            "[%d] tmuRev: %d, tmuRam: %d\n",
            cont,
            config->grVoodooConfig.tmuConfig[cont].tmuRev,
            config->grVoodooConfig.tmuConfig[cont].tmuRam
        );
    }
}

ZEND_FUNCTION(testGrVoodoo2Config_t)
{
    zend_object* grVoodoo2Config_zo = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(grVoodoo2Config_zo, grVoodoo2Config_ce)
        ZEND_PARSE_PARAMETERS_END();

    _GrVoodoo2Config_t* config = O_EMBEDDED_P(_GrVoodoo2Config_t, grVoodoo2Config_zo);

    php_printf(
        "fbRam: %d, fbiRev: %d, nTexelfx: %d, sliDetect: %d\n",
        config->grVoodoo2Config.fbRam,
        config->grVoodoo2Config.fbiRev,
        config->grVoodoo2Config.nTexelfx,
        config->grVoodoo2Config.sliDetect
    );

    for (uint32_t cont = 0; cont < GLIDE_NUM_TMU; cont++) {

        php_printf(
            "[%d] tmuRev: %d, tmuRam: %d\n",
            cont,
            config->grVoodoo2Config.tmuConfig[cont].tmuRev,
            config->grVoodoo2Config.tmuConfig[cont].tmuRam
        );
    }
}

#endif // _DEBUG

static zend_object_handlers grVoodooConfig_object_handlers;
static zend_object_handlers grVoodoo2Config_object_handlers;

//function that allocates memory for the object and sets the handlers
zend_object* GrVoodooConfig_new(zend_class_entry* ce)
{
    //it allocates memory
    _GrVoodooConfig_t* grVoodooConfig = zend_object_alloc(sizeof(_GrVoodooConfig_t), ce);
   
    //it initializes the object
    zend_object_std_init(&grVoodooConfig->std, ce);
    object_properties_init(&grVoodooConfig->std, ce);

    //it sets the handlers
    grVoodooConfig->std.handlers = &grVoodooConfig_object_handlers;

    //it returns the zend object
    return &grVoodooConfig->std;
}

//function that allocates memory for the object and sets the handlers
zend_object* GrVoodoo2Config_new(zend_class_entry* ce)
{
    //it allocates memory
    _GrVoodoo2Config_t* grVoodoo2Config = zend_object_alloc(sizeof(_GrVoodoo2Config_t), ce);

    //it initializes the object
    zend_object_std_init(&grVoodoo2Config->std, ce);
    object_properties_init(&grVoodoo2Config->std, ce);

    //it sets the handlers
    grVoodoo2Config->std.handlers = &grVoodoo2Config_object_handlers;

    //it returns the zend object
    return &grVoodoo2Config->std;
}

static zval* gr_write_property(zend_object* object, zend_string* member, zval* value, void** cache_slot)
{
    if (zend_string_equals_literal(object->ce->name, "GrVoodooConfig_t")) {

        _GrVoodooConfig_t* config = O_EMBEDDED_P(_GrVoodooConfig_t, object);  // Get your embedded struct from the object

        //if the property we are checking is factor and the value is integer...
        if (zend_string_equals_literal(member, "fbRam") 
            && Z_TYPE_P(value) == IS_LONG
        ) {

            //we update the inner field
            config->grVoodooConfig.fbRam = Z_LVAL_P(value);
        }

        //if the property we are checking is factor and the value is integer...
        else if (zend_string_equals_literal(member, "fbiRev") 
            && Z_TYPE_P(value) == IS_LONG
        ) {

            //we update the inner field
            config->grVoodooConfig.fbiRev = Z_LVAL_P(value);
        }

        //if the property we are checking is factor and the value is integer...
        else if (zend_string_equals_literal(member, "nTexelfx") 
            && Z_TYPE_P(value) == IS_LONG
        ) {

            //we update the inner field
            config->grVoodooConfig.nTexelfx = Z_LVAL_P(value);
        }

        //if the property we are checking is factor and the value is integer...
        else if (zend_string_equals_literal(member, "sliDetect") 
            && Z_TYPE_P(value) == _IS_BOOL
        ) {

            //we update the inner field
            config->grVoodooConfig.sliDetect = Z_TYPE_P(value) == IS_TRUE;
        }
        
        //if the property we are checking is factor and the value is integer...
        else if (zend_string_equals_literal(member, "tmuConfig") 
            && Z_TYPE_P(value) == IS_ARRAY
        ) {
            zval* entry = NULL;
            zend_string* key = NULL;

            for (int cont = 0; cont < min(GLIDE_NUM_TMU, zend_hash_num_elements(Z_ARRVAL_P(value))); cont++) {
                
                if ((entry = zend_hash_index_find(Z_ARRVAL_P(value), cont)) != NULL) {
                    _GrTMUConfig_t* grTMUConfig = O_EMBEDDED_P(_GrTMUConfig_t, Z_OBJ_P(entry));

                    memcpy(
                        &config->grVoodooConfig.tmuConfig[cont],
                        &grTMUConfig->grTMUConfig,	            
                        sizeof(GrTMUConfig_t)		            
                    );
                }
            }
        }
    } else if (zend_string_equals_literal(object->ce->name, "GrVoodoo2Config_t")) {

        _GrVoodoo2Config_t* config = O_EMBEDDED_P(_GrVoodoo2Config_t, object);  // Get your embedded struct from the object
        
        //if the property we are checking is factor and the value is integer...
        if (zend_string_equals_literal(member, "fbRam")
            && Z_TYPE_P(value) == IS_LONG
            ) {

            //we update the inner field
            config->grVoodoo2Config.fbRam = Z_LVAL_P(value);
        }

        //if the property we are checking is factor and the value is integer...
        else if (zend_string_equals_literal(member, "fbiRev")
            && Z_TYPE_P(value) == IS_LONG
            ) {

            //we update the inner field
            config->grVoodoo2Config.fbiRev = Z_LVAL_P(value);
        }

        //if the property we are checking is factor and the value is integer...
        else if (zend_string_equals_literal(member, "nTexelfx")
            && Z_TYPE_P(value) == IS_LONG
            ) {

            //we update the inner field
            config->grVoodoo2Config.nTexelfx = Z_LVAL_P(value);
        }

        //if the property we are checking is factor and the value is integer...
        else if (zend_string_equals_literal(member, "sliDetect")
            && Z_TYPE_P(value) == _IS_BOOL
            ) {

            //we update the inner field
            config->grVoodoo2Config.sliDetect = Z_TYPE_P(value) == IS_TRUE;
        }

        //if the property we are checking is factor and the value is integer...
        else if (zend_string_equals_literal(member, "tmuConfig")
            && Z_TYPE_P(value) == IS_ARRAY
            ) {
            zval* entry = NULL;
            zend_string* key = NULL;

            for (int cont = 0; cont < min(GLIDE_NUM_TMU, zend_hash_num_elements(Z_ARRVAL_P(value))); cont++) {

                if ((entry = zend_hash_index_find(Z_ARRVAL_P(value), cont)) != NULL) {
                    _GrTMUConfig_t* grTMUConfig = O_EMBEDDED_P(_GrTMUConfig_t, Z_OBJ_P(entry));

                    memcpy(
                        &config->grVoodoo2Config.tmuConfig[cont],
                        &grTMUConfig->grTMUConfig,
                        sizeof(GrTMUConfig_t)
                    );
                }
            }
        }
    }

    return zend_std_write_property(object, member, value, cache_slot);
}

void phpglide2x_register_grVoodooConfig(INIT_FUNC_ARGS)
{
    grVoodooConfig_ce = register_class_GrVoodooConfig_t();
    grVoodooConfig_ce->create_object = GrVoodooConfig_new; //asign an internal constructor

    grVoodoo2Config_ce = register_class_GrVoodoo2Config_t();
    grVoodoo2Config_ce->create_object = GrVoodooConfig_new; //asign an internal constructor

    memcpy(
        &grVoodooConfig_object_handlers,	// our handler 
        &std_object_handlers,				        // the standard handler
        sizeof(zend_object_handlers)		        // size of the standar handler
    );

    memcpy(
        &grVoodoo2Config_object_handlers,	// our handler 
        &std_object_handlers,				        // the standard handler
        sizeof(zend_object_handlers)		        // size of the standar handler
    );

    //we set the address of the beginning of the whole embedded data
    grVoodooConfig_object_handlers.offset = XtOffsetOf(_GrVoodooConfig_t, std);
    grVoodooConfig_object_handlers.write_property = gr_write_property;

    grVoodoo2Config_object_handlers.offset = XtOffsetOf(_GrVoodoo2Config_t, std);
    grVoodoo2Config_object_handlers.write_property = gr_write_property;
}