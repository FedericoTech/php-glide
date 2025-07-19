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

PHP_METHOD(GrVoodooConfig_t, flush)
{
    ZEND_PARSE_PARAMETERS_NONE();

    _GrVoodooConfig_t* obj = O_EMBEDDED_P(_GrVoodooConfig_t, Z_OBJ_P(ZEND_THIS));

    flush_grVoodooConfig(obj, &obj->grVoodooConfig);

    zend_string* bin = zend_string_alloc(sizeof(GrVoodooConfig_t) + 1, 0);

    memcpy(
        ZSTR_VAL(bin),
        &obj->grVoodooConfig,
        sizeof(GrVoodooConfig_t) + 1
    );

    ZSTR_VAL(bin)[sizeof(GrVoodooConfig_t) + 1] = '\0'; // null terminator (optional for binary)

    RETURN_STR(bin);
}

PHP_METHOD(GrVoodoo2Config_t, flush)
{
    ZEND_PARSE_PARAMETERS_NONE();

    _GrVoodoo2Config_t* obj = O_EMBEDDED_P(_GrVoodoo2Config_t, Z_OBJ_P(ZEND_THIS));

    flush_grVoodoo2Config(obj, &obj->grVoodoo2Config);

    zend_string* bin = zend_string_alloc(sizeof(GrVoodoo2Config_t) + 1, 0);

    memcpy(
        ZSTR_VAL(bin),
        &obj->grVoodoo2Config,
        sizeof(GrVoodoo2Config_t) + 1
    );

    ZSTR_VAL(bin)[sizeof(GrVoodoo2Config_t) + 1] = '\0'; // null terminator (optional for binary)

    RETURN_STR(bin);
}

static zend_object_handlers grVoodooConfig_object_handlers;
static zend_object_handlers grVoodoo2Config_object_handlers;

//function that allocates memory for the object and sets the handlers
static zend_object* GrVoodooConfig_new(zend_class_entry* ce)
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
static zend_object* GrVoodoo2Config_new(zend_class_entry* ce)
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

static zend_object* gr_clone_obj(zend_object* object)
{
    zend_object* new_obj = NULL;

    if (object->ce == grVoodooConfig_ce) {

        // Step 1: Call the default clone handler
        new_obj = GrVoodooConfig_new(object->ce);


        _GrVoodooConfig_t* clone = O_EMBEDDED_P(_GrVoodooConfig_t, new_obj);
        _GrVoodooConfig_t* orig = O_EMBEDDED_P(_GrVoodooConfig_t, object);

        //flush_grVoodooConfig(orig);

        memcpy(&clone->grVoodooConfig, &orig->grVoodooConfig, sizeof(GrVoodooConfig_t));

        zend_objects_clone_members(&clone->std, &orig->std);
    }
    else if (object->ce == grVoodoo2Config_ce) {

        // Step 1: Call the default clone handler
        new_obj = GrVoodoo2Config_new(object->ce);

        _GrVoodoo2Config_t* clone = O_EMBEDDED_P(_GrVoodoo2Config_t, new_obj);
        _GrVoodoo2Config_t* orig = O_EMBEDDED_P(_GrVoodoo2Config_t, object);

        //flush_grVoodoo2Config(orig);

        memcpy(&clone->grVoodoo2Config, &orig->grVoodoo2Config, sizeof(GrVoodooConfig_t));

        zend_objects_clone_members(&clone->std, &orig->std);
    }

    return new_obj;
}

void phpglide2x_register_grVoodooConfig(INIT_FUNC_ARGS)
{
    grVoodooConfig_ce = register_class_GrVoodooConfig_t(gr_flushable_ce);
    grVoodooConfig_ce->create_object = GrVoodooConfig_new; //asign an internal constructor

    grVoodoo2Config_ce = register_class_GrVoodoo2Config_t(gr_flushable_ce);
    grVoodoo2Config_ce->create_object = GrVoodoo2Config_new; //asign an internal constructor

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
    grVoodooConfig_object_handlers.clone_obj = gr_clone_obj;

    grVoodoo2Config_object_handlers.offset = XtOffsetOf(_GrVoodoo2Config_t, std);
    grVoodoo2Config_object_handlers.clone_obj = gr_clone_obj;
}

void flush_grVoodooConfig(const _GrVoodooConfig_t* grVoodooConfig, GrVoodooConfig_t* buffer) {
    zval* value = zend_read_property(
        grVoodooConfig->std.ce,            // zend_class_entry* of the object
        (zend_object*) &grVoodooConfig->std,           // zval* or zend_object* (see below)
        "fbRam",   // property name
        sizeof("fbRam") - 1,
        1,             // silent (1 = don't emit notice if not found)
        NULL           // Optional return zval ptr, or NULL
    );

    buffer->fbRam = Z_TYPE_P(value) == IS_NULL ? 0 : Z_LVAL_P(value);
    
    value = zend_read_property(
        grVoodooConfig->std.ce,            // zend_class_entry* of the object
        (zend_object*) &grVoodooConfig->std,           // zval* or zend_object* (see below)
        "fbiRev",   // property name
        sizeof("fbiRev") - 1,
        1,             // silent (1 = don't emit notice if not found)
        NULL           // Optional return zval ptr, or NULL
    );

    buffer->fbiRev = Z_TYPE_P(value) == IS_NULL ? 0 : Z_LVAL_P(value);
    
    value = zend_read_property(
        grVoodooConfig->std.ce,            // zend_class_entry* of the object
        (zend_object*)&grVoodooConfig->std,           // zval* or zend_object* (see below)
        "nTexelfx",   // property name
        sizeof("nTexelfx") - 1,
        1,             // silent (1 = don't emit notice if not found)
        NULL           // Optional return zval ptr, or NULL
    );

    buffer->nTexelfx = Z_TYPE_P(value) == IS_NULL ? 0 : Z_LVAL_P(value);
    
    value = zend_read_property(
        grVoodooConfig->std.ce,            // zend_class_entry* of the object
        (zend_object*)&grVoodooConfig->std,           // zval* or zend_object* (see below)
        "sliDetect",   // property name
        sizeof("sliDetect") - 1,
        1,             // silent (1 = don't emit notice if not found)
        NULL           // Optional return zval ptr, or NULL
    );

    buffer->sliDetect = Z_TYPE_P(value) == IS_TRUE;
    
    value = zend_read_property(
        grVoodooConfig->std.ce,            // zend_class_entry* of the object
        (zend_object*)&grVoodooConfig->std,           // zval* or zend_object* (see below)
        "tmuConfig",   // property name
        sizeof("tmuConfig") - 1,
        1,             // silent (1 = don't emit notice if not found)
        NULL           // Optional return zval ptr, or NULL
    );
    
    //the array is not initialized...
    if (Z_TYPE_P(value) == IS_NULL) {
        memset(&buffer->tmuConfig, 0, sizeof(GrTMUConfig_t) * 2);
    }
    else {
        zval* val;
        HashTable* ht = Z_ARRVAL_P(value); // array_zval is a zval* pointing to the PHP array
        int cont = 0;
        ZEND_HASH_FOREACH_VAL(ht, val) {
            if (cont >= GLIDE_NUM_TMU) {
                break;
            }

            if (Z_TYPE_P(val) == IS_OBJECT && instanceof_function(Z_OBJCE_P(val), grTMUConfig_ce)) {

                _GrTMUConfig_t* grTMUConfig = O_EMBEDDED_P(_GrTMUConfig_t, Z_OBJ_P(val));

                flush_grTMUConfig(grTMUConfig, &buffer->tmuConfig[cont++]);

            }
            else {
                memset(&buffer->tmuConfig[cont++], 0, sizeof(GrTMUConfig_t));
            }
                
        } ZEND_HASH_FOREACH_END();

    }    
}

void hydrate_grVoodooConfig(const GrVoodooConfig_t* voodooConfig, _GrVoodooConfig_t* grVoodooConfig)
{
    zend_update_property_long(grVoodooConfig_ce, &grVoodooConfig->std, "fbRam", sizeof("fbRam") - 1, voodooConfig->fbRam);
    
    zend_update_property_long(grVoodooConfig_ce, &grVoodooConfig->std, "fbiRev", sizeof("fbiRev") - 1, voodooConfig->fbiRev);

    zend_update_property_long(grVoodooConfig_ce, &grVoodooConfig->std, "nTexelfx", sizeof("nTexelfx") - 1, voodooConfig->nTexelfx);

    zend_update_property_bool(grVoodooConfig_ce, &grVoodooConfig->std, "sliDetect", sizeof("sliDetect") - 1, voodooConfig->sliDetect);

    zval tmuConfig_arr_zval;
    array_init_size(&tmuConfig_arr_zval, voodooConfig->nTexelfx);
    
    for (int cont2 = 0; cont2 < voodooConfig->nTexelfx; cont2++) {
        zval grTMUConfig_t;

        object_init_ex(&grTMUConfig_t, grTMUConfig_ce);
        
        hydrate_grTMUConfig(&voodooConfig->tmuConfig[cont2], O_EMBEDDED_P(_GrTMUConfig_t, Z_OBJ_P(&grTMUConfig_t)));

        add_next_index_zval(&tmuConfig_arr_zval, &grTMUConfig_t);
    }

    zend_update_property(
        grVoodooConfig_ce,
        &grVoodooConfig->std,
        "tmuConfig",
        sizeof("tmuConfig") - 1,
        &tmuConfig_arr_zval
    );

    zval_ptr_dtor(&tmuConfig_arr_zval); //destroy the local pointer
}

void flush_grVoodoo2Config(const _GrVoodoo2Config_t* grVoodoo2Config, GrVoodoo2Config_t *buffer) {
    zval* value = zend_read_property(
        grVoodoo2Config->std.ce,            // zend_class_entry* of the object
        (zend_object*)&grVoodoo2Config->std,           // zval* or zend_object* (see below)
        "fbRam",   // property name
        sizeof("fbRam") - 1,
        1,             // silent (1 = don't emit notice if not found)
        NULL           // Optional return zval ptr, or NULL
    );

    buffer->fbRam = Z_TYPE_P(value) == IS_NULL ? 0 : Z_LVAL_P(value);

    value = zend_read_property(
        grVoodoo2Config->std.ce,            // zend_class_entry* of the object
        (zend_object*)&grVoodoo2Config->std,           // zval* or zend_object* (see below)
        "fbiRev",   // property name
        sizeof("fbiRev") - 1,
        1,             // silent (1 = don't emit notice if not found)
        NULL           // Optional return zval ptr, or NULL
    );

    buffer->fbiRev = Z_TYPE_P(value) == IS_NULL ? 0 : Z_LVAL_P(value);

    value = zend_read_property(
        grVoodoo2Config->std.ce,            // zend_class_entry* of the object
        (zend_object*)&grVoodoo2Config->std,           // zval* or zend_object* (see below)
        "nTexelfx",   // property name
        sizeof("nTexelfx") - 1,
        1,             // silent (1 = don't emit notice if not found)
        NULL           // Optional return zval ptr, or NULL
    );

    buffer->nTexelfx = Z_TYPE_P(value) == IS_NULL ? 0 : Z_LVAL_P(value);

    value = zend_read_property(
        grVoodoo2Config->std.ce,            // zend_class_entry* of the object
        (zend_object*)&grVoodoo2Config->std,           // zval* or zend_object* (see below)
        "sliDetect",   // property name
        sizeof("sliDetect") - 1,
        1,             // silent (1 = don't emit notice if not found)
        NULL           // Optional return zval ptr, or NULL
    );

    buffer->sliDetect = Z_TYPE_P(value) == IS_TRUE;

    value = zend_read_property(
        grVoodoo2Config->std.ce,            // zend_class_entry* of the object
        (zend_object*)&grVoodoo2Config->std,           // zval* or zend_object* (see below)
        "tmuConfig",   // property name
        sizeof("tmuConfig") - 1,
        1,             // silent (1 = don't emit notice if not found)
        NULL           // Optional return zval ptr, or NULL
    );

    //the array is not initialized...
    if (Z_TYPE_P(value) == IS_NULL) {
        memset(&buffer->tmuConfig, 0, sizeof(GrTMUConfig_t) * 2);
    }
    else {
        zval* val;
        HashTable* ht = Z_ARRVAL_P(value); // array_zval is a zval* pointing to the PHP array
        int cont = 0;
        ZEND_HASH_FOREACH_VAL(ht, val) {
            if (cont >= GLIDE_NUM_TMU) {
                break;
            }

            if (Z_TYPE_P(val) == IS_OBJECT && instanceof_function(Z_OBJCE_P(val), grTMUConfig_ce)) {

                _GrTMUConfig_t* grTMUConfig = O_EMBEDDED_P(_GrTMUConfig_t, Z_OBJ_P(val));

                flush_grTMUConfig(grTMUConfig, &buffer->tmuConfig[cont++]);
            }
            else {
                memset(&buffer->tmuConfig[cont++], 0, sizeof(GrTMUConfig_t));
            }

        } ZEND_HASH_FOREACH_END();
    }
}

void hydrate_grVoodoo2Config(const GrVoodoo2Config_t* voodoo2Config, _GrVoodoo2Config_t* grVoodoo2Config)
{
    zend_update_property_long(grVoodoo2Config_ce, &grVoodoo2Config->std, "fbRam", sizeof("fbRam") - 1, voodoo2Config->fbRam);

    zend_update_property_long(grVoodoo2Config_ce, &grVoodoo2Config->std, "fbiRev", sizeof("fbiRev") - 1, voodoo2Config->fbiRev);

    zend_update_property_long(grVoodoo2Config_ce, &grVoodoo2Config->std, "nTexelfx", sizeof("nTexelfx") - 1, voodoo2Config->nTexelfx);

    zend_update_property_bool(grVoodoo2Config_ce, &grVoodoo2Config->std, "sliDetect", sizeof("sliDetect") - 1, voodoo2Config->sliDetect);

    zval tmuConfig_arr_zval;
    array_init_size(&tmuConfig_arr_zval, voodoo2Config->nTexelfx);

    for (int cont2 = 0; cont2 < voodoo2Config->nTexelfx; cont2++) {
        zval grTMUConfig_t;
        object_init_ex(&grTMUConfig_t, grTMUConfig_ce);

        hydrate_grTMUConfig(&voodoo2Config->tmuConfig[cont2], O_EMBEDDED_P(_GrTMUConfig_t, &Z_OBJ(grTMUConfig_t)));

        add_next_index_zval(&tmuConfig_arr_zval, &grTMUConfig_t);
    }

    zend_update_property(
        grVoodoo2Config_ce,
        &grVoodoo2Config->std,
        "tmuConfig",
        sizeof("tmuConfig") - 1,
        &tmuConfig_arr_zval
    );

    zval_ptr_dtor(&tmuConfig_arr_zval); //destroy the local pointer
}