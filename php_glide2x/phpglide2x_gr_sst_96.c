#include "phpglide2x_structs.h"

zend_class_entry* grSst96Config_ce;

#ifdef _DEBUG
ZEND_FUNCTION(testGrSst96Config_t)
{
    zend_object* grSst96Config_zo = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(grSst96Config_zo, grSst96Config_ce)
    ZEND_PARSE_PARAMETERS_END();

    GrSst96Config_t buffer;

    memset(&buffer, 0xff, sizeof buffer);

    flush_GrSst96Config(grSst96Config_zo, &buffer);

    php_printf(
        "fbRam: %d, nTexelfx: %d, tmuConfig: [tmuRev: %d, tmuRam: %d]\n",
        buffer.fbRam,
        buffer.nTexelfx,
        buffer.tmuConfig.tmuRev,
        buffer.tmuConfig.tmuRam
    );
}
#endif // _DEBUG

PHP_METHOD(GrSst96Config_t, flush)
{
    ZEND_PARSE_PARAMETERS_NONE();

    zend_string* bin = zend_string_alloc(sizeof(GrAT3DConfig_t) + 1, 0);

    flush_GrSst96Config(Z_OBJ_P(ZEND_THIS), (GrSst96Config_t*)ZSTR_VAL(bin));

    ZSTR_VAL(bin)[sizeof(GrAT3DConfig_t) + 1] = '\0'; // null terminator (optional for binary)

    RETURN_STR(bin);
}


void flush_GrSst96Config(const _GrSst96Config_t* obj, GrSst96Config_t* buffer)
{
    zval* value = zend_read_property(
        grSst96Config_ce,            // zend_class_entry* of the object
        (zend_object*)obj,           // zval* or zend_object* (see below)
        "fbRam",   // property name
        sizeof("fbRam") - 1,
        1,             // silent (1 = don't emit notice if not found)
        NULL           // Optional return zval ptr, or NULL
    );

    if (Z_TYPE_P(value) != IS_NULL) { buffer->fbRam = Z_LVAL_P(value); }

    value = zend_read_property(
        grSst96Config_ce,            // zend_class_entry* of the object
        (zend_object*)obj,           // zval* or zend_object* (see below)
        "nTexelfx",   // property name
        sizeof("nTexelfx") - 1,
        1,             // silent (1 = don't emit notice if not found)
        NULL           // Optional return zval ptr, or NULL
    );

    if (Z_TYPE_P(value) != IS_NULL) { buffer->nTexelfx = Z_LVAL_P(value); }

    value = zend_read_property(
        grSst96Config_ce,            // zend_class_entry* of the object
        (zend_object*)obj,           // zval* or zend_object* (see below)
        "tmuConfig",   // property name
        sizeof("tmuConfig") - 1,
        1,             // silent (1 = don't emit notice if not found)
        NULL           // Optional return zval ptr, or NULL
    );

    if (Z_TYPE_P(value) == IS_NULL) {
        //memset(&buffer->tmuConfig, 0, sizeof(GrTMUConfig_t));
    }
    else {

        flush_grTMUConfig((_GrTMUConfig_t*) Z_OBJ_P(value), &buffer->tmuConfig);
    }
}

void hydrate_GrSst96Config(const GrSst96Config_t* buffer, _GrSst96Config_t* obj)
{
    zend_update_property_long(grSst96Config_ce, obj, "fbRam", sizeof("fbRam") - 1, buffer->fbRam);

    zend_update_property_long(grSst96Config_ce, obj, "nTexelfx", sizeof("nTexelfx") - 1, buffer->nTexelfx);

    zval grTMUConfig_t;

    object_init_ex(&grTMUConfig_t, grTMUConfig_ce);

    hydrate_grTMUConfig(&buffer->tmuConfig, (_GrTMUConfig_t *)&Z_OBJ(grTMUConfig_t));

    zend_update_property(grSst96Config_ce, obj, "tmuConfig", sizeof("tmuConfig") - 1, &grTMUConfig_t);

    //zval_ptr_dtor(&grTMUConfig_t); //destroy the local pointer

}