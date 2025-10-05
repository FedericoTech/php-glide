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

    GrVoodooConfig_t buffer;

    flush_grVoodooConfig(grVoodooConfig_zo, &buffer);

    php_printf(
        "fbRam: %d, fbiRev: %d, nTexelfx: %d, sliDetect: %d\n",
        buffer.fbRam,
        buffer.fbiRev,
        buffer.nTexelfx,
        buffer.sliDetect
    );

    for (uint32_t cont = 0; cont < GLIDE_NUM_TMU; cont++) {

        php_printf(
            "[%d] tmuRev: %d, tmuRam: %d\n",
            cont,
            buffer.tmuConfig[cont].tmuRev,
            buffer.tmuConfig[cont].tmuRam
        );
    }
}

ZEND_FUNCTION(testGrVoodoo2Config_t)
{
    zend_object* grVoodoo2Config_zo = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(grVoodoo2Config_zo, grVoodoo2Config_ce)
        ZEND_PARSE_PARAMETERS_END();

    GrVoodoo2Config_t buffer;

    flush_grVoodoo2Config(grVoodoo2Config_zo, &buffer);

    php_printf(
        "fbRam: %d, fbiRev: %d, nTexelfx: %d, sliDetect: %d\n",
        buffer.fbRam,
        buffer.fbiRev,
        buffer.nTexelfx,
        buffer.sliDetect
    );

    for (uint32_t cont = 0; cont < GLIDE_NUM_TMU; cont++) {

        php_printf(
            "[%d] tmuRev: %d, tmuRam: %d\n",
            cont,
            buffer.tmuConfig[cont].tmuRev,
            buffer.tmuConfig[cont].tmuRam
        );
    }
}

#endif // _DEBUG

PHP_METHOD(GrVoodooConfig_t, flush)
{
    ZEND_PARSE_PARAMETERS_NONE();

    zend_string* bin = zend_string_alloc(sizeof(GrVoodooConfig_t) + 1, 0);

    flush_grVoodooConfig(Z_OBJ_P(ZEND_THIS), (GrVoodooConfig_t*) ZSTR_VAL(bin));

    ZSTR_VAL(bin)[sizeof(GrVoodooConfig_t) + 1] = '\0'; // null terminator (optional for binary)

    RETURN_STR(bin);
}

PHP_METHOD(GrVoodoo2Config_t, flush)
{
    ZEND_PARSE_PARAMETERS_NONE();

    zend_string* bin = zend_string_alloc(sizeof(GrVoodoo2Config_t) + 1, 0);

    flush_grVoodoo2Config(Z_OBJ_P(ZEND_THIS), (GrVoodoo2Config_t*)ZSTR_VAL(bin));

    ZSTR_VAL(bin)[sizeof(GrVoodoo2Config_t) + 1] = '\0'; // null terminator (optional for binary)

    RETURN_STR(bin);
}

void flush_grVoodooConfig(const _GrVoodooConfig_t* obj, GrVoodooConfig_t* buffer)
{
    zval* value = zend_read_property(
        grVoodooConfig_ce,          // zend_class_entry* of the object
        (zend_object*)obj,          // zval* or zend_object* (see below)
        "fbRam",                    // property name
        sizeof("fbRam") - 1,
        1,                          // silent (1 = don't emit notice if not found)
        NULL                        // Optional return zval ptr, or NULL
    );

    buffer->fbRam = Z_TYPE_P(value) == IS_NULL ? 0 : Z_LVAL_P(value);
    
    value = zend_read_property(
        grVoodooConfig_ce,          // zend_class_entry* of the object
        (zend_object*)obj,          // zval* or zend_object* (see below)
        "fbiRev",                   // property name
        sizeof("fbiRev") - 1,
        1,                          // silent (1 = don't emit notice if not found)
        NULL                        // Optional return zval ptr, or NULL
    );

    buffer->fbiRev = Z_TYPE_P(value) == IS_NULL ? 0 : Z_LVAL_P(value);
    
    value = zend_read_property(
        grVoodooConfig_ce,          // zend_class_entry* of the object
        (zend_object*)obj,          // zval* or zend_object* (see below)
        "nTexelfx",                 // property name
        sizeof("nTexelfx") - 1,
        1,                          // silent (1 = don't emit notice if not found)
        NULL                        // Optional return zval ptr, or NULL
    );

    buffer->nTexelfx = Z_TYPE_P(value) == IS_NULL ? 0 : Z_LVAL_P(value);
    
    value = zend_read_property(
        grVoodooConfig_ce,          // zend_class_entry* of the object
        (zend_object*)obj,          // zval* or zend_object* (see below)
        "sliDetect",                // property name
        sizeof("sliDetect") - 1,
        1,                          // silent (1 = don't emit notice if not found)
        NULL                        // Optional return zval ptr, or NULL
    );

    buffer->sliDetect = Z_TYPE_P(value) == IS_TRUE;
    
    value = zend_read_property(
        grVoodooConfig_ce,          // zend_class_entry* of the object
        (zend_object*)obj,         // zval* or zend_object* (see below)
        "tmuConfig",                // property name
        sizeof("tmuConfig") - 1,
        1,                          // silent (1 = don't emit notice if not found)
        NULL                        // Optional return zval ptr, or NULL
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

                flush_grTMUConfig((_GrTMUConfig_t*)Z_OBJ_P(val), &buffer->tmuConfig[cont++]);

            }
            else {
                memset(&buffer->tmuConfig[cont++], 0, sizeof(GrTMUConfig_t));
            }
                
        } ZEND_HASH_FOREACH_END();
    }
}

void hydrate_grVoodooConfig(const GrVoodooConfig_t* buffer, _GrVoodooConfig_t* obj)
{
    zend_update_property_long(grVoodooConfig_ce, obj, "fbRam", sizeof("fbRam") - 1, buffer->fbRam);
    
    zend_update_property_long(grVoodooConfig_ce, obj, "fbiRev", sizeof("fbiRev") - 1, buffer->fbiRev);

    zend_update_property_long(grVoodooConfig_ce, obj, "nTexelfx", sizeof("nTexelfx") - 1, buffer->nTexelfx);

    zend_update_property_bool(grVoodooConfig_ce, obj, "sliDetect", sizeof("sliDetect") - 1, buffer->sliDetect);

    zval tmuConfig_arr_zval;
    array_init_size(&tmuConfig_arr_zval, buffer->nTexelfx);
    
    for (int cont2 = 0; cont2 < buffer->nTexelfx; cont2++) {
        zval grTMUConfig_t;

        object_init_ex(&grTMUConfig_t, grTMUConfig_ce);
        
        hydrate_grTMUConfig(&buffer->tmuConfig[cont2], (_GrTMUConfig_t *) Z_OBJ_P(&grTMUConfig_t));

        add_next_index_zval(&tmuConfig_arr_zval, &grTMUConfig_t);
    }

    zend_update_property(
        grVoodooConfig_ce,
        obj,
        "tmuConfig",
        sizeof("tmuConfig") - 1,
        &tmuConfig_arr_zval
    );

    zval_ptr_dtor(&tmuConfig_arr_zval); //destroy the local pointer
}

void flush_grVoodoo2Config(const _GrVoodoo2Config_t* obj, GrVoodoo2Config_t *buffer) {
    zval* value = zend_read_property(
        grVoodoo2Config_ce,         // zend_class_entry* of the object
        (zend_object*)obj,          // zval* or zend_object* (see below)
        "fbRam",                    // property name
        sizeof("fbRam") - 1,
        1,                          // silent (1 = don't emit notice if not found)
        NULL                        // Optional return zval ptr, or NULL
    );

    buffer->fbRam = Z_TYPE_P(value) == IS_NULL ? 0 : Z_LVAL_P(value);

    value = zend_read_property(
        grVoodoo2Config_ce,         // zend_class_entry* of the object
        (zend_object*)obj,          // zval* or zend_object* (see below)
        "fbiRev",                   // property name
        sizeof("fbiRev") - 1,
        1,                          // silent (1 = don't emit notice if not found)
        NULL                        // Optional return zval ptr, or NULL
    );

    buffer->fbiRev = Z_TYPE_P(value) == IS_NULL ? 0 : Z_LVAL_P(value);

    value = zend_read_property(
        grVoodoo2Config_ce,         // zend_class_entry* of the object
        (zend_object*)obj,          // zval* or zend_object* (see below)
        "nTexelfx",                 // property name
        sizeof("nTexelfx") - 1,
        1,                          // silent (1 = don't emit notice if not found)
        NULL                        // Optional return zval ptr, or NULL
    );

    buffer->nTexelfx = Z_TYPE_P(value) == IS_NULL ? 0 : Z_LVAL_P(value);

    value = zend_read_property(
        grVoodoo2Config_ce,         // zend_class_entry* of the object
        (zend_object*)obj,          // zval* or zend_object* (see below)
        "sliDetect",                // property name
        sizeof("sliDetect") - 1,
        1,                          // silent (1 = don't emit notice if not found)
        NULL                        // Optional return zval ptr, or NULL
    );

    buffer->sliDetect = Z_TYPE_P(value) == IS_TRUE;

    value = zend_read_property(
        grVoodoo2Config_ce,         // zend_class_entry* of the object
        (zend_object*)obj,          // zval* or zend_object* (see below)
        "tmuConfig",                // property name
        sizeof("tmuConfig") - 1,
        1,                          // silent (1 = don't emit notice if not found)
        NULL                        // Optional return zval ptr, or NULL
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

                flush_grTMUConfig((_GrTMUConfig_t*)Z_OBJ_P(val), &buffer->tmuConfig[cont++]);
            }
            else {
                memset(&buffer->tmuConfig[cont++], 0, sizeof(GrTMUConfig_t));
            }

        } ZEND_HASH_FOREACH_END();
    }
}

void hydrate_grVoodoo2Config(const GrVoodoo2Config_t* buffer, _GrVoodoo2Config_t* obj)
{
    zend_update_property_long(grVoodoo2Config_ce, obj, "fbRam", sizeof("fbRam") - 1, buffer->fbRam);

    zend_update_property_long(grVoodoo2Config_ce, obj, "fbiRev", sizeof("fbiRev") - 1, buffer->fbiRev);

    zend_update_property_long(grVoodoo2Config_ce, obj, "nTexelfx", sizeof("nTexelfx") - 1, buffer->nTexelfx);

    zend_update_property_bool(grVoodoo2Config_ce, obj, "sliDetect", sizeof("sliDetect") - 1, buffer->sliDetect);

    zval tmuConfig_arr_zval;
    array_init_size(&tmuConfig_arr_zval, buffer->nTexelfx);

    for (int cont2 = 0; cont2 < buffer->nTexelfx; cont2++) {
        zval grTMUConfig_t;
        object_init_ex(&grTMUConfig_t, grTMUConfig_ce);

        hydrate_grTMUConfig(&buffer->tmuConfig[cont2], (_GrTMUConfig_t *)&Z_OBJ(grTMUConfig_t));

        add_next_index_zval(&tmuConfig_arr_zval, &grTMUConfig_t);
    }

    zend_update_property(grVoodoo2Config_ce, obj, "tmuConfig", sizeof("tmuConfig") - 1, &tmuConfig_arr_zval);

    zval_ptr_dtor(&tmuConfig_arr_zval); //destroy the local pointer
}