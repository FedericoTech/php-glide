#include "phpglide2x_structs.h"

zend_class_entry* grTmuVertex_ce;

static const char* properties[] = { "sow", "tow", "oow" };

#ifdef _DEBUG
ZEND_FUNCTION(testGrTmuVertex)
{
    zend_object* grTmuVertex_zo = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(grTmuVertex_zo, grTmuVertex_ce)
        ZEND_PARSE_PARAMETERS_END();

    _GrTmuVertex* config = O_EMBEDDED_P(_GrTmuVertex, grTmuVertex_zo);

    php_printf(
        "sow: %f, tow: %f, oow: %f\n",
        config->grTmuVertex.sow,
        config->grTmuVertex.tow,
        config->grTmuVertex.oow
    );
}
#endif // _DEBUG

PHP_METHOD(GrTmuVertex, flush)
{
    ZEND_PARSE_PARAMETERS_NONE();

    _GrTmuVertex* obj = O_EMBEDDED_P(_GrTmuVertex, Z_OBJ_P(ZEND_THIS));

    flush_grTmuVertex(obj, &obj->grTmuVertex);
    
    zend_string* bin = zend_string_alloc(sizeof(_GrTmuVertex) + 1, 0);

    memcpy(
        ZSTR_VAL(bin),
        &obj->grTmuVertex,
        sizeof(_GrTmuVertex) + 1
    );

    ZSTR_VAL(bin)[sizeof(_GrTmuVertex) + 1] = '\0'; // null terminator (optional for binary)

    RETURN_STR(bin);
}

static zend_object_handlers object_handlers;

//function that allocates memory for the object and sets the handlers
static zend_object* gr_new_obj(zend_class_entry* ce)
{
    //it allocates memory
    _GrTmuVertex* grTmuVertex = zend_object_alloc(sizeof(_GrTmuVertex), ce);

    //it initializes the object
    zend_object_std_init(&grTmuVertex->std, ce);
    object_properties_init(&grTmuVertex->std, ce);

    //it sets the handlers
    grTmuVertex->std.handlers = &object_handlers;

    //it returns the zend object
    return &grTmuVertex->std;
}

static zend_object* gr_clone_obj(zend_object* object)
{
    // Step 1: Call the default clone handler
    zend_object* new_obj = gr_new_obj(object->ce);

    _GrTmuVertex* clone = O_EMBEDDED_P(_GrTmuVertex, new_obj);
    _GrTmuVertex* orig = O_EMBEDDED_P(_GrTmuVertex, object);

    memcpy(&clone->grTmuVertex, &orig->grTmuVertex, sizeof(GrTmuVertex));
    
    zend_objects_clone_members(&clone->std, &orig->std);
    
    return new_obj;
}

void phpglide2x_register_grTmuVertex(INIT_FUNC_ARGS)
{
    grTmuVertex_ce = register_class_GrTmuVertex(gr_flushable_ce);
    grTmuVertex_ce->create_object = gr_new_obj; //asign an internal constructor

    memcpy(
        &object_handlers,	// our handler 
        &std_object_handlers,				        // the standard handler
        sizeof(zend_object_handlers)		        // size of the standar handler
    );

    //we set the address of the beginning of the whole embedded data
    object_handlers.offset = XtOffsetOf(_GrTmuVertex, std);
    object_handlers.clone_obj = gr_clone_obj;
}

void flush_grTmuVertex(const _GrTmuVertex* grTmuVertex, GrTmuVertex* buffer)
{
    zval* value = NULL;
    for (int cont = 0; cont < 3; cont++) {
        value = zend_read_property(
            grTmuVertex_ce,                     // zend_class_entry* of the object
            (zend_object*)&grTmuVertex->std,    // zval* or zend_object* (see below)
            properties[cont],                   // property name
            strlen(properties[cont]),
            1,                                  // silent (1 = don't emit notice if not found)
            NULL                                // Optional return zval ptr, or NULL
        );

        ((FxFloat*)&buffer->sow)[cont] = (FxFloat) (
            Z_TYPE_P(value) == IS_DOUBLE
                ? Z_DVAL_P(value)
                : zval_get_double(value)
        );
    }

}

void hydrate_grTmuVertex(const GrTmuVertex* buffer, _GrTmuVertex* grTmuVertex)
{
    for (int cont = 0; cont < 3; cont++) {
        zend_update_property_long(
            grTMUConfig_ce,
            &grTmuVertex->std,
            properties[cont],
            strlen(properties[cont]),
            (zend_long)((FxFloat*)&buffer->sow)[cont]
        );
    }
}