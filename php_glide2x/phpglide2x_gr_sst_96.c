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

    flush_GrSst96Config(obj, &obj->grSst96Config);

    zend_string* bin = zend_string_alloc(sizeof(GrSst96Config_t) + 1, 0);

    memcpy(
        ZSTR_VAL(bin),
        &obj->grSst96Config,
        sizeof(GrSst96Config_t) + 1
    );

    ZSTR_VAL(bin)[sizeof(GrSst96Config_t)+1] = '\0'; // null terminator (optional for binary)

    RETURN_STR(bin);
}

static zend_object_handlers object_handlers;

//function that allocates memory for the object and sets the handlers
static zend_object* gr_new_obj(zend_class_entry* ce)
{
    //it allocates memory
    _GrSst96Config_t* grSst96Config = zend_object_alloc(sizeof(_GrSst96Config_t), ce);

    //it initializes the object
    zend_object_std_init(&grSst96Config->std, ce);
    object_properties_init(&grSst96Config->std, ce);

    //it sets the handlers
    grSst96Config->std.handlers = &object_handlers;

    //it returns the zend object
    return &grSst96Config->std;
}

static zend_object* gr_clone_obj(zend_object* object)
{
    // Step 1: Call the default clone handler
    zend_object* new_obj = gr_new_obj(object->ce);


    _GrSst96Config_t* clone = O_EMBEDDED_P(_GrSst96Config_t, new_obj);
    _GrSst96Config_t* orig = O_EMBEDDED_P(_GrSst96Config_t, object);

    clone->grSst96Config = orig->grSst96Config;

    zend_objects_clone_members(&clone->std, &orig->std);

    return new_obj;
}

void phpglide2x_register_grSst96Config(INIT_FUNC_ARGS)
{
    grSst96Config_ce = register_class_GrSst96Config_t(gr_flushable_ce);
    grSst96Config_ce->create_object = gr_new_obj; //asign an internal constructor

    object_handlers = std_object_handlers;

    //we set the address of the beginning of the whole embedded data
    object_handlers.offset = XtOffsetOf(_GrSst96Config_t, std);
    object_handlers.clone_obj = gr_clone_obj;
}

void flush_GrSst96Config(const _GrSst96Config_t* obj, GrSst96Config_t* buffer)
{
    zval* value = zend_read_property(
        obj->std.ce,            // zend_class_entry* of the object
        (zend_object*)&obj->std,           // zval* or zend_object* (see below)
        "fbRam",   // property name
        sizeof("fbRam") - 1,
        1,             // silent (1 = don't emit notice if not found)
        NULL           // Optional return zval ptr, or NULL
    );

    buffer->fbRam = Z_TYPE_P(value) == IS_NULL ? 0 : Z_LVAL_P(value);

    value = zend_read_property(
        obj->std.ce,            // zend_class_entry* of the object
        (zend_object*)&obj->std,           // zval* or zend_object* (see below)
        "nTexelfx",   // property name
        sizeof("nTexelfx") - 1,
        1,             // silent (1 = don't emit notice if not found)
        NULL           // Optional return zval ptr, or NULL
    );

    buffer->nTexelfx = Z_TYPE_P(value) == IS_NULL ? 0 : Z_LVAL_P(value);

    value = zend_read_property(
        obj->std.ce,            // zend_class_entry* of the object
        (zend_object*)&obj->std,           // zval* or zend_object* (see below)
        "tmuConfig",   // property name
        sizeof("tmuConfig") - 1,
        1,             // silent (1 = don't emit notice if not found)
        NULL           // Optional return zval ptr, or NULL
    );

    if (Z_TYPE_P(value) == IS_NULL) {
        memset(&buffer->tmuConfig, 0, sizeof(GrTMUConfig_t));
    }
    else {

        flush_grTMUConfig(O_EMBEDDED_P(_GrTMUConfig_t, Z_OBJ_P(value)), &buffer->tmuConfig);
    }
}

void hydrate_GrSst96Config(const GrSst96Config_t* sST96Config, _GrSst96Config_t* grSst96Config)
{
    zend_update_property_long(grSst96Config_ce, &grSst96Config->std, "fbRam", sizeof("fbRam") - 1, sST96Config->fbRam);

    zend_update_property_long(grSst96Config_ce, &grSst96Config->std, "nTexelfx", sizeof("nTexelfx") - 1, sST96Config->nTexelfx);

    zval grTMUConfig_t;

    object_init_ex(&grTMUConfig_t, grTMUConfig_ce);

    hydrate_grTMUConfig(&sST96Config->tmuConfig, O_EMBEDDED_P(_GrTMUConfig_t, &Z_OBJ(grTMUConfig_t)));

    zend_update_property(grSst96Config_ce, &grSst96Config->std, "tmuConfig", sizeof("tmuConfig") - 1, &grTMUConfig_t);

    //zval_ptr_dtor(&grTMUConfig_t); //destroy the local pointer

}