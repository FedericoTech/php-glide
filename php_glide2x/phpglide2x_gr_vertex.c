#include "phpglide2x_structs.h"

zend_class_entry* grVertex_ce;

static const char* properties[] = { "x", "y", "z", "r", "g", "b", "ooz", "a", "oow", "tmuvtx" };

#ifdef _DEBUG
ZEND_FUNCTION(testGrVertex)
{
    zend_object* grVertex_zo = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(grVertex_zo, grVertex_ce)
        ZEND_PARSE_PARAMETERS_END();

    _GrVertex* config = O_EMBEDDED_P(_GrVertex, grVertex_zo);

    php_printf(
        "x: %f, y: %f, z: %f, r: %f, g: %f, b: %f, ooz: %f, a: %f, oow: %f\n",
        config->grVertex.x,
        config->grVertex.y,
        config->grVertex.z,

        config->grVertex.r,
        config->grVertex.g,
        config->grVertex.b,
        
        config->grVertex.ooz,
        config->grVertex.a,
        config->grVertex.oow
    );

    for (uint32_t cont = 0; cont < GLIDE_NUM_TMU; cont++) {

        php_printf(
            "[%d] sow: %f, tow: %f, oow: %f\n",
            cont,
            config->grVertex.tmuvtx[cont].sow,
            config->grVertex.tmuvtx[cont].tow,
            config->grVertex.tmuvtx[cont].oow
        );
    }
}
#endif // _DEBUG

PHP_METHOD(GrVertex, flush)
{
    ZEND_PARSE_PARAMETERS_NONE();

    _GrVertex* obj = O_EMBEDDED_P(_GrVertex, Z_OBJ_P(ZEND_THIS));

    flush_grVertex(obj, &obj->grVertex);

    zend_string* bin = zend_string_alloc(sizeof(_GrVertex) + 1, 0);

    memcpy(
        ZSTR_VAL(bin),
        &obj->grVertex,
        sizeof(_GrVertex) + 1
    );

    ZSTR_VAL(bin)[sizeof(_GrVertex) + 1] = '\0'; // null terminator (optional for binary)

    RETURN_STR(bin);
}

static zend_object_handlers object_handlers;

//function that allocates memory for the object and sets the handlers
static zend_object* gr_new_obj(zend_class_entry* ce)
{
    //it allocates memory
    _GrVertex* grVertex = zend_object_alloc(sizeof(_GrVertex), ce);

    //it initializes the object
    zend_object_std_init(&grVertex->std, ce);
    object_properties_init(&grVertex->std, ce);

    //it sets the handlers
    grVertex->std.handlers = &object_handlers;

    //it returns the zend object
    return &grVertex->std;
}

static zend_object* gr_clone_obj(zend_object* object)
{
    // Step 1: Call the default clone handler
    zend_object* new_obj = gr_new_obj(object->ce);
               
    _GrVertex* clone = O_EMBEDDED_P(_GrVertex, new_obj);
    _GrVertex* orig = O_EMBEDDED_P(_GrVertex, object);

    clone->grVertex = orig->grVertex;
        
    zend_objects_clone_members(&clone->std, &orig->std);

    return new_obj;
}

void phpglide2x_register_grVertex(INIT_FUNC_ARGS)
{
    grVertex_ce = register_class_GrVertex(gr_flushable_ce);
    grVertex_ce->create_object = gr_new_obj; //asign an internal constructor

    object_handlers = std_object_handlers;
    
    //we set the address of the beginning of the whole embedded data
    object_handlers.offset = XtOffsetOf(_GrVertex, std);

    object_handlers.clone_obj = gr_clone_obj;
}

void flush_grVertex(const _GrVertex* grVertex, GrVertex* buffer)
{
    zval* value = NULL;

    for (int cont = 0; cont < 9; cont++) {
        value = zend_read_property(
            grVertex->std.ce,            // zend_class_entry* of the object
            (zend_object*)&grVertex->std,           // zval* or zend_object* (see below)
            properties[cont],   // property name
            strlen(properties[cont]),
            1,             // silent (1 = don't emit notice if not found)
            NULL           // Optional return zval ptr, or NULL
        );
        ((FxFloat*)&buffer->x)[cont] = (FxFloat)zval_get_double(value);
    }

    value = zend_read_property(
        grVertex->std.ce,            // zend_class_entry* of the object
        (zend_object*)&grVertex->std,           // zval* or zend_object* (see below)
        "tmuvtx",   // property name
        sizeof("tmuvtx") - 1,
        1,             // silent (1 = don't emit notice if not found)
        NULL           // Optional return zval ptr, or NULL
    );

    //the array is not initialized...
    if (Z_TYPE_P(value) == IS_NULL) {
        //memset(&buffer->tmuvtx, 0, sizeof(GrTmuVertex) * 2);
    }
    else {
        zval* val;
        HashTable* ht = Z_ARRVAL_P(value); // array_zval is a zval* pointing to the PHP array
        int cont = 0;
        ZEND_HASH_FOREACH_VAL(ht, val) {
            if (cont >= GLIDE_NUM_TMU) {
                break;
            }

            if (Z_TYPE_P(val) == IS_OBJECT && instanceof_function(Z_OBJCE_P(val), grTmuVertex_ce)) {

                _GrTmuVertex* grTmuVertex = O_EMBEDDED_P(_GrTmuVertex, Z_OBJ_P(val));

                buffer->tmuvtx[cont++] = grTmuVertex->grTmuVertex;

                //flush_grTmuVertex(grTmuVertex, &buffer->tmuvtx[cont++]);
            }
            else {
                //memset(&buffer->tmuvtx[cont++], 0, sizeof(_GrTmuVertex));
            }

        } ZEND_HASH_FOREACH_END();
    }
}

void hydrate_grVertex(const GrVertex* buffer, _GrVertex* grVertex)
{
    for (int cont = 0; cont < GLIDE_NUM_TMU; cont++) {
        zend_update_property_long(
            grVertex_ce,
            &grVertex->std,
            properties[cont],
            strlen(properties[cont]) - 1,
            (zend_long)((FxFloat*)&buffer->x)[cont]
        );
    }

    zval grTmuVertex_arr_zval;
    array_init_size(&grTmuVertex_arr_zval, GLIDE_NUM_TMU);

    for (int cont2 = 0; cont2 < GLIDE_NUM_TMU; cont2++) {
        zval grTmuVertex;
        object_init_ex(&grTmuVertex, grTMUConfig_ce);

        hydrate_grTmuVertex(&buffer->tmuvtx[cont2], (_GrTmuVertex *) &Z_OBJ(grTmuVertex));

        add_next_index_zval(&grTmuVertex_arr_zval, &grTmuVertex);
    }

    zend_update_property(
        grVertex_ce,
        &grVertex->std,
        "tmuvtx",
        sizeof("tmuvtx") - 1,
        &grTmuVertex_arr_zval
    );

    zval_ptr_dtor(&grTmuVertex_arr_zval); //destroy the local pointer
}