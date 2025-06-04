#include "phpglide2x_structs.h"

zend_class_entry* grSst96Config_ce;

#ifdef _DEBUG
ZEND_FUNCTION(testGrSst96Config_t)
{
    zend_object* grSst96Config_zo = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(grSst96Config_zo, grSst96Config_ce)
    ZEND_PARSE_PARAMETERS_END();

    _GrSst96Config_t* config = O_EMBEDDED_P(_GrSst96Config_t, grSst96Config_zo);

    php_printf(
        "fbRam: %d, nTexelfx: %d, tmuConfig: [tmuRev: %d, tmuRam: %d]\n",
        config->grSst96Config.fbRam,
        config->grSst96Config.nTexelfx,
        config->grSst96Config.tmuConfig.tmuRev,
        config->grSst96Config.tmuConfig.tmuRam
    );
}
#endif // _DEBUG

PHP_METHOD(GrSst96Config_t, flush)
{
    ZEND_PARSE_PARAMETERS_NONE();

    _GrSst96Config_t* obj = O_EMBEDDED_P(_GrSst96Config_t, Z_OBJ_P(ZEND_THIS));

    flush_GrSst96Config(obj);

    zend_string* bin = zend_string_alloc(sizeof(GrSst96Config_t) + 1, 0);

    memcpy(
        ZSTR_VAL(bin),
        &obj->grSst96Config,
        sizeof(GrSst96Config_t) + 1
    );

    ZSTR_VAL(bin)[sizeof(GrSst96Config_t)+1] = '\0'; // null terminator (optional for binary)

    RETURN_STR(bin);
}

static zend_object_handlers grSst96Config_object_handlers;

//function that allocates memory for the object and sets the handlers
zend_object* GrSst96Config_new(zend_class_entry* ce)
{
    //it allocates memory
    _GrSst96Config_t* grSst96Config = zend_object_alloc(sizeof(_GrSst96Config_t), ce);

    /*
    //here we keep a pointer to each field in the hashtable
    zend_hash_init(&grSst96Config->field_map, 3, NULL, NULL, 0);
    zend_hash_str_add_ptr(&grSst96Config->field_map, "fbRam", sizeof("fbRam") - 1, &grSst96Config->grSst96Config.fbRam);
    zend_hash_str_add_ptr(&grSst96Config->field_map, "nTexelfx", sizeof("nTexelfx") - 1, &grSst96Config->grSst96Config.nTexelfx);
    zend_hash_str_add_ptr(&grSst96Config->field_map, "tmuConfig", sizeof("tmuConfig") - 1, &grSst96Config->grSst96Config.tmuConfig);
    */

    //it initializes the object
    zend_object_std_init(&grSst96Config->std, ce);
    object_properties_init(&grSst96Config->std, ce);

    //it sets the handlers
    grSst96Config->std.handlers = &grSst96Config_object_handlers;

    //it returns the zend object
    return &grSst96Config->std;
}

static zval* gr_read_property(zend_object* object, zend_string* member, int type, void** cache_slot, zval* rv)
{
    /*
    //if (zend_string_equals_literal(object->ce->name, "GrSst96Config_t")) {

        zend_class_entry* ce = object->ce;
        zend_property_info* prop_info = zend_get_property_info(ce, member, 1);

        zval* prop_zv = OBJ_PROP(object, prop_info->offset);

        if (Z_TYPE_P(prop_zv) != IS_UNDEF) {
            return prop_zv;
        }

        _GrSst96Config_t* grSst96Config = O_EMBEDDED_P(_GrSst96Config_t, object);

        if ((ZEND_TYPE_FULL_MASK(prop_info->type) & MAY_BE_LONG) == MAY_BE_LONG) {

            zend_update_property_long(
                ce, object,
                ZSTR_VAL(member), ZSTR_LEN(member),
                *(int*)zend_hash_find_ptr(&grSst96Config->field_map, member)
            );
        } else if (zend_string_equals_literal(member, "tmuConfig")) {
            
            zval zv;
            object_init_ex(&zv, grTMUConfig_ce);

            zend_object* grTMUConfig_zo = Z_OBJ_P(&zv);

            _GrTMUConfig_t* grTMUConfig = O_EMBEDDED_P(_GrTMUConfig_t, grTMUConfig_zo);
            
            memcpy(
                &grTMUConfig->grTMUConfig,	                // our handler 
                &grSst96Config->grSst96Config.tmuConfig,	// the standard handler
                sizeof(GrTMUConfig_t)		        // size of the standar handler
            );
            
            zend_update_property_ex(
                ce, object,
                member,
                &zv
            );

            zval_ptr_dtor(&zv); //destroy the local zv
            
        }
    //}
    */
    return zend_std_read_property(object, member, type, cache_slot, rv);
}

static zval* gr_write_property(zend_object* object, zend_string* member, zval* value, void** cache_slot)
{
    if (object->ce == grSst96Config_ce) {

        _GrSst96Config_t* config = O_EMBEDDED_P(_GrSst96Config_t, object);  // Get your embedded struct from the object

        //if the property we are checking is factor and the value is integer...
        if (zend_string_equals_literal(member, "fbRam") 
            && Z_TYPE_P(value) == IS_LONG //not really neccesary
        ) {

            //we update the inner field
            config->grSst96Config.fbRam = Z_LVAL_P(value);
        }

        //if the property we are checking is factor and the value is integer...
        else if (zend_string_equals_literal(member, "nTexelfx") 
            && Z_TYPE_P(value) == IS_LONG //not really neccesary
        ) {

            //we update the inner field
            config->grSst96Config.nTexelfx = Z_LVAL_P(value);
        }

        //if the property we are checking is factor and the value is integer...
        else if (zend_string_equals_literal(member, "tmuConfig")
            && Z_TYPE_P(value) == IS_OBJECT //not really neccesary
        ) {

            _GrTMUConfig_t* grTMUConfig = O_EMBEDDED_P(_GrTMUConfig_t, Z_OBJ_P(value));

            memcpy(
                &config->grSst96Config.tmuConfig,	// the standard handler
                &grTMUConfig->grTMUConfig,	        // our handler 
                sizeof(GrTMUConfig_t)		        // size of the standar handler
            );
        }
    }

    return zend_std_write_property(object, member, value, cache_slot);
}

static zend_object* gr_clone_obj(zend_object* object)
{
    // Step 1: Call the default clone handler
    zend_object* new_obj = GrSst96Config_new(object->ce);


    _GrSst96Config_t* clone = O_EMBEDDED_P(_GrSst96Config_t, new_obj);
    _GrSst96Config_t* orig = O_EMBEDDED_P(_GrSst96Config_t, object);

    flush_GrSst96Config(orig);

    memcpy(&clone->grSst96Config, &orig->grSst96Config, sizeof(GrSst96Config_t));

    zend_objects_clone_members(&clone->std, &orig->std);

    return new_obj;
}

static HashTable* get_properties(zend_object* object) 
{
    /*
    zend_class_entry* ce = object->ce;
    _GrSst96Config_t* grSst96Config = O_EMBEDDED_P(_GrSst96Config_t, object);

    zend_string* member;
    zend_property_info* prop_info;
    ZEND_HASH_FOREACH_STR_KEY_PTR(&ce->properties_info, member, prop_info) {

        // Skip integer keys if any (usually none)
        if (!member) { continue; }

        zend_property_info* prop_info = zend_get_property_info(ce, member, 1);
        zval* prop_zv = OBJ_PROP(object, prop_info->offset);

        //if the property is not yet defined...
        if (Z_TYPE_P(prop_zv) == IS_UNDEF) {

            if ((ZEND_TYPE_FULL_MASK(prop_info->type) & MAY_BE_LONG) == MAY_BE_LONG) {
                zend_update_property_long(
                    ce, object,
                    ZSTR_VAL(member), ZSTR_LEN(member),
                    *(int*)zend_hash_find_ptr(&grSst96Config->field_map, member)
                );
            }
            else {
                
                zval zv;
                object_init_ex(&zv, grTMUConfig_ce);
                zend_object* grTMUConfig_zo = Z_OBJ_P(&zv);
                _GrTMUConfig_t* grTMUConfig = O_EMBEDDED_P(_GrTMUConfig_t, grTMUConfig_zo);
                memcpy(
                    &grTMUConfig->grTMUConfig,	        // our handler 
                    &grSst96Config->grSst96Config.tmuConfig,	// the standard handler
                    sizeof(GrTMUConfig_t)		        // size of the standar handler
                );
                zend_update_property_ex(
                    ce, object,
                    member,
                    &zv
                );
                
                zval_ptr_dtor(&zv); //destroy the local zv
            }
        }
    } ZEND_HASH_FOREACH_END();
    */
    return zend_std_get_properties(object);
}

static void free_obj(zend_object* object)
{

    _GrSst96Config_t* grSst96Config = O_EMBEDDED_P(_GrSst96Config_t, object);

    // Clean up the field_map
    //zend_hash_destroy(&grSst96Config->field_map);

    //php_printf("grSst96Config destroyed\n");

    // Call the default object free
    zend_object_std_dtor(&grSst96Config->std);
}

void phpglide2x_register_grSst96Config(INIT_FUNC_ARGS)
{
    grSst96Config_ce = register_class_GrSst96Config_t(gr_flushable_ce);
    grSst96Config_ce->create_object = GrSst96Config_new; //asign an internal constructor

    memcpy(
        &grSst96Config_object_handlers,	            // our handler
        &std_object_handlers,				        // the standard handler
        sizeof(zend_object_handlers)		        // size of the standar handler
    );

    //we set the address of the beginning of the whole embedded data
    grSst96Config_object_handlers.offset = XtOffsetOf(_GrSst96Config_t, std);
    //grSst96Config_object_handlers.read_property = gr_read_property;
    //grSst96Config_object_handlers.get_properties = get_properties;
    //grSst96Config_object_handlers.write_property = gr_write_property;
    grSst96Config_object_handlers.clone_obj = gr_clone_obj;
    //grSst96Config_object_handlers.free_obj = free_obj;
}

void flush_GrSst96Config(_GrSst96Config_t* obj)
{
    zval* value = zend_read_property(
        obj->std.ce,            // zend_class_entry* of the object
        &obj->std,           // zval* or zend_object* (see below)
        "fbRam",   // property name
        sizeof("fbRam") - 1,
        1,             // silent (1 = don't emit notice if not found)
        NULL           // Optional return zval ptr, or NULL
    );

    obj->grSst96Config.fbRam = Z_TYPE_P(value) == IS_NULL ? 0 : Z_LVAL_P(value);

    value = zend_read_property(
        obj->std.ce,            // zend_class_entry* of the object
        &obj->std,           // zval* or zend_object* (see below)
        "nTexelfx",   // property name
        sizeof("nTexelfx") - 1,
        1,             // silent (1 = don't emit notice if not found)
        NULL           // Optional return zval ptr, or NULL
    );

    obj->grSst96Config.nTexelfx = Z_TYPE_P(value) == IS_NULL ? 0 : Z_LVAL_P(value);

    value = zend_read_property(
        obj->std.ce,            // zend_class_entry* of the object
        &obj->std,           // zval* or zend_object* (see below)
        "tmuConfig",   // property name
        sizeof("tmuConfig") - 1,
        1,             // silent (1 = don't emit notice if not found)
        NULL           // Optional return zval ptr, or NULL
    );

    if (Z_TYPE_P(value) == IS_NULL) {
        memset(&obj->grSst96Config.tmuConfig, 0, sizeof(GrTMUConfig_t));
    }
    else {
        _GrTMUConfig_t* grTMUConfig_t = O_EMBEDDED_P(_GrTMUConfig_t, Z_OBJ_P(value));

        flush_grTMUConfig(grTMUConfig_t);

        memcpy(
            &obj->grSst96Config.tmuConfig,
            &grTMUConfig_t->grTMUConfig,
            sizeof(GrTMUConfig_t)
        );
    }
}