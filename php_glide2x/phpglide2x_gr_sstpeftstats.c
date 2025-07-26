#include "phpglide2x_structs.h"

zend_class_entry* gr_SstPerfStats_ce;

#ifdef _DEBUG
ZEND_FUNCTION(testGrSstPerfStats_t)
{
    zend_object* grSstPerfStats_zo = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(grSstPerfStats_zo, gr_SstPerfStats_ce)
        ZEND_PARSE_PARAMETERS_END();

    _GrSstPerfStats_t* config = O_EMBEDDED_P(_GrSstPerfStats_t, grSstPerfStats_zo);

    php_printf(
        "pixelsIn: %u, chromaFail: %u, zFuncFail: %u, aFuncFail: %u, pixelsOut: %u\n",
        config->grSstPerfStats.pixelsIn,
        config->grSstPerfStats.chromaFail,
        config->grSstPerfStats.zFuncFail,
        config->grSstPerfStats.aFuncFail,
        config->grSstPerfStats.pixelsOut
    );
}
#endif // _DEBUG

PHP_METHOD(GrSstPerfStats_t, flush)
{
    ZEND_PARSE_PARAMETERS_NONE();

    _GrSstPerfStats_t* obj = O_EMBEDDED_P(_GrSstPerfStats_t, Z_OBJ_P(ZEND_THIS));

    flush_grSstPerfStats(obj, &obj->grSstPerfStats);

    zend_string* bin = zend_string_alloc(sizeof(GrSstPerfStats_t) + 1, 0);

    memcpy(
        ZSTR_VAL(bin),
        &obj->grSstPerfStats,
        sizeof(GrSstPerfStats_t) + 1
    );

    ZSTR_VAL(bin)[sizeof(GrSstPerfStats_t) + 1] = '\0'; // null terminator (optional for binary)

    RETURN_STR(bin);
}

static zend_object_handlers object_handlers;

//function that allocates memory for the object and sets the handlers
static zend_object* gr_new_obj(zend_class_entry* ce)
{
    //it allocates memory
    _GrSstPerfStats_t* grSstPerfStats = zend_object_alloc(sizeof(_GrSstPerfStats_t), ce);

    //it initializes the object
    zend_object_std_init(&grSstPerfStats->std, ce);
    object_properties_init(&grSstPerfStats->std, ce);

    //it sets the handlers
    grSstPerfStats->std.handlers = &object_handlers;

    //it returns the zend object
    return &grSstPerfStats->std;
}

static zend_object* gr_clone_obj(zend_object* object)
{
    // Step 1: Call the default clone handler
    zend_object* new_obj = gr_new_obj(object->ce);

    _GrSstPerfStats_t* clone = O_EMBEDDED_P(_GrSstPerfStats_t, new_obj);
    _GrSstPerfStats_t* orig = O_EMBEDDED_P(_GrSstPerfStats_t, object);

    memcpy(&clone->grSstPerfStats, &orig->grSstPerfStats, sizeof(GrSstPerfStats_t));

    zend_objects_clone_members(&clone->std, &orig->std);

    return new_obj;
}

void phpglide2x_register_grSstPerfStats(INIT_FUNC_ARGS)
{
    gr_SstPerfStats_ce = register_class_GrSstPerfStats_t(gr_flushable_ce);
    gr_SstPerfStats_ce->create_object = gr_new_obj; //asign an internal constructor

    memcpy(
        &object_handlers,	// our handler 
        &std_object_handlers,				        // the standard handler
        sizeof(zend_object_handlers)		        // size of the standar handler
    );

    //we set the address of the beginning of the whole embedded data
    object_handlers.offset = XtOffsetOf(_GrSstPerfStats_t, std);

    //object_handlers.write_property = gr_write_property;
    object_handlers.clone_obj = gr_clone_obj;
}

void flush_grSstPerfStats(const _GrSstPerfStats_t* obj, GrSstPerfStats_t* buffer)
{
    zval* value = zend_read_property(
        obj->std.ce,            // zend_class_entry* of the object
        (zend_object*)&obj->std,           // zval* or zend_object* (see below)
        "pixelsIn",   // property name
        sizeof("pixelsIn") - 1,
        1,             // silent (1 = don't emit notice if not found)
        NULL           // Optional return zval ptr, or NULL
    );

    buffer->pixelsIn = (FxU32) (Z_TYPE_P(value) == IS_NULL ? 0 : Z_LVAL_P(value));

    value = zend_read_property(
        obj->std.ce,            // zend_class_entry* of the object
        (zend_object*)&obj->std,           // zval* or zend_object* (see below)
        "chromaFail",   // property name
        sizeof("chromaFail") - 1,
        1,             // silent (1 = don't emit notice if not found)
        NULL           // Optional return zval ptr, or NULL
    );

    buffer->chromaFail = (FxU32)(Z_TYPE_P(value) == IS_NULL ? 0 : Z_LVAL_P(value));

    value = zend_read_property(
        obj->std.ce,            // zend_class_entry* of the object
        (zend_object*)&obj->std,           // zval* or zend_object* (see below)
        "zFuncFail",   // property name
        sizeof("zFuncFail") - 1,
        1,             // silent (1 = don't emit notice if not found)
        NULL           // Optional return zval ptr, or NULL
    );

    buffer->zFuncFail = (FxU32)(Z_TYPE_P(value) == IS_NULL ? 0 : Z_LVAL_P(value));

    value = zend_read_property(
        obj->std.ce,            // zend_class_entry* of the object
        (zend_object*)&obj->std,           // zval* or zend_object* (see below)
        "aFuncFail",   // property name
        sizeof("aFuncFail") - 1,
        1,             // silent (1 = don't emit notice if not found)
        NULL           // Optional return zval ptr, or NULL
    );

    buffer->aFuncFail = (FxU32)(Z_TYPE_P(value) == IS_NULL ? 0 : Z_LVAL_P(value));

    value = zend_read_property(
        obj->std.ce,            // zend_class_entry* of the object
        (zend_object*)&obj->std,           // zval* or zend_object* (see below)
        "pixelsOut",   // property name
        sizeof("pixelsOut") - 1,
        1,             // silent (1 = don't emit notice if not found)
        NULL           // Optional return zval ptr, or NULL
    );

    buffer->aFuncFail = (FxU32)(Z_TYPE_P(value) == IS_NULL ? 0 : Z_LVAL_P(value));
}

void hydrate_grSstPerfStats(const GrSstPerfStats_t* buffer, _GrSstPerfStats_t* obj)
{

    zend_update_property_long(obj->std.ce, &obj->std, "pixelsIn", sizeof("pixelsIn") - 1, buffer->pixelsIn);

    zend_update_property_long(obj->std.ce, &obj->std, "chromaFail", sizeof("chromaFail") - 1, buffer->chromaFail);

    zend_update_property_long(obj->std.ce, &obj->std, "zFuncFail", sizeof("zFuncFail") - 1, buffer->zFuncFail);

    zend_update_property_long(obj->std.ce, &obj->std, "aFuncFail", sizeof("aFuncFail") - 1, buffer->aFuncFail);

    zend_update_property_long(obj->std.ce, &obj->std, "pixelsOut", sizeof("pixelsOut") - 1, buffer->pixelsOut);
}