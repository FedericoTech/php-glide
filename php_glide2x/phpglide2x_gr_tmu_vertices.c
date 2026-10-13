#include "phpglide2x_structs.h"

zend_class_entry* grTmuVertices_ce;

#ifdef _DEBUG
ZEND_FUNCTION(testGrTmuVertices)
{
    zend_object* grTmuVertices_zo = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(grTmuVertices_zo, grTmuVertices_ce)
        ZEND_PARSE_PARAMETERS_END();

    _GrTmuVertices* config = O_EMBEDDED_P(_GrTmuVertices, grTmuVertices_zo);

    GrTmuVertex *grTmuVertices = config->gtvArray;
    /*
    for(int cont = 0; cont < GLIDE_NUM_TMU; cont++){
        flush_grTmuVertex(O_EMBEDDED_P(_GrTmuVertex, Z_OBJ_P(&config->tmu[cont])), &grTmuVertices[cont]);
    }
    */
    
    php_printf(
        "tmu[0]: sow: %f, tow: %f, oow: %f\n"
        "tmu[1]: sow: %f, tow: %f, oow: %f\n",

        grTmuVertices[0].sow,
        grTmuVertices[0].tow,
        grTmuVertices[0].oow,

        grTmuVertices[1].sow,
        grTmuVertices[1].tow,
        grTmuVertices[1].oow
    );
}
#endif // _DEBUG

PHP_METHOD(GrTmuVertices, __construct)
{
    //zend_throw_error(NULL, "Cannot instantiate GrTmuVertices directly");
}

PHP_METHOD(GrTmuVertices, offsetExists)
{
    zend_long index;
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(index)
        ZEND_PARSE_PARAMETERS_END();

    RETURN_BOOL(index >= 0 && index < GLIDE_NUM_TMU);
}

PHP_METHOD(GrTmuVertices, offsetSet)
{
    zend_long idx;
    zend_object* grTmuVertex_zo = NULL;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_LONG(idx)
        Z_PARAM_OBJ_OF_CLASS(grTmuVertex_zo, grTmuVertex_ce)
        ZEND_PARSE_PARAMETERS_END();

    if (!(idx >= 0 && idx < GLIDE_NUM_TMU)) {
        zend_throw_exception(
            NULL,
            "only indices 0 through 1",
            0
        );
    }

    _GrTmuVertices* self = O_EMBEDDED_P(_GrTmuVertices, Z_OBJ_P(ZEND_THIS));

    // If there's already an object at this index, release it
    if (!Z_ISUNDEF(self->tmu[idx])) {

        //remove sync pointer from the object
        grTmuVertices_remove_sync_ref(&self->gtvArray[idx], Z_EMBEDDED_P(_GrTmuVertex, &self->tmu[idx]));

        zval_ptr_dtor(&self->tmu[idx]); //remove reference to the GrTmyVertex object
    }

    // Assign the new object and increment refcount
    ZVAL_OBJ(&self->tmu[idx], grTmuVertex_zo);

    //subscribe to the sync pointer of the GrTmyVertex object
    grTmuVertices_set_sync_ref(&self->gtvArray[idx], Z_EMBEDDED_P(_GrTmuVertex, &self->tmu[idx]));

    //we copy the data as soon as it's set
    self->gtvArray[idx] = O_EMBEDDED_P(_GrTmuVertex, grTmuVertex_zo)->tmuVertex.tmu;

    GC_ADDREF(Z_OBJ(self->tmu[idx]));   //we add a reference counting
}

PHP_METHOD(GrTmuVertices, offsetGet)
{
    zend_long idx;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(idx)
        ZEND_PARSE_PARAMETERS_END();

    _GrTmuVertices* tv = O_EMBEDDED_P(_GrTmuVertices, Z_OBJ_P(ZEND_THIS));

    if (idx < 0 || idx >= GLIDE_NUM_TMU) {
        zend_throw_error(NULL, "Index out of bounds");
        RETURN_THROWS();
    }

    RETURN_ZVAL(&tv->tmu[idx], 1, 0);
}

PHP_METHOD(GrTmuVertices, offsetUnset)
{
    zend_long idx;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(idx)
        ZEND_PARSE_PARAMETERS_END();

    if (!(idx >= 0 && idx < GLIDE_NUM_TMU)) {
        zend_throw_exception(
            NULL,
            "only indices 0 through 1",
            0
        );
    }


    _GrTmuVertices* self = O_EMBEDDED_P(_GrTmuVertices, Z_OBJ_P(ZEND_THIS));

    // If there's already an object at this index, release it
    if (!Z_ISUNDEF(self->tmu[idx])) {

        //remove sync pointer from the object
        grTmuVertices_remove_sync_ref(&self->gtvArray[idx], Z_EMBEDDED_P(_GrTmuVertex, &self->tmu[idx]));
        
        zval_ptr_dtor(&self->tmu[idx]); //remove reference to the GrTmyVertex object

        self->gtvArray[idx] = (GrTmuVertex){ 0 };   //we zero the buffer

        ZVAL_UNDEF(&self->tmu[idx]);    //we make the element undefined
    }
}

PHP_METHOD(GrTmuVertices, __debugInfo)
{
    _GrTmuVertices* obj = O_EMBEDDED_P(_GrTmuVertices, Z_OBJ_P(ZEND_THIS));

    array_init_size(return_value, GLIDE_NUM_TMU);

    for (int i = 0; i < GLIDE_NUM_TMU; i++) {
        Z_TRY_ADDREF(obj->tmu[i]);
        zend_hash_index_add(
            Z_ARRVAL_P(return_value),
            i,
            &obj->tmu[i]
        );
    }

    /*
    for (int i = 0; i < GLIDE_NUM_TMU; i++) {
        if (!Z_ISUNDEF(obj->tmu[i])) {
            zval tmp;
            ZVAL_COPY(&tmp, &obj->tmu[i]);
            zend_hash_index_add(Z_ARRVAL_P(return_value), i, &tmp);
        }
    }
    */
}

static zend_object_handlers object_handlers;

//function that allocates memory for the object and sets the handlers
static zend_object* gr_new_obj(zend_class_entry* ce)
{
    //it allocates memory
    _GrTmuVertices* grTmuVertices = zend_object_alloc(sizeof(_GrTmuVertices), ce);

    //it initializes the object
    zend_object_std_init(&grTmuVertices->std, ce);
    object_properties_init(&grTmuVertices->std, ce);

    //it sets the handlers
    grTmuVertices->std.handlers = &object_handlers;

    // Initialize the array to undefined
    for (int i = 0; i < GLIDE_NUM_TMU; i++) {
        ZVAL_UNDEF(&grTmuVertices->tmu[i]);
    }

    //it returns the zend object
    return &grTmuVertices->std;
}


static void gr_free_obj(zend_object* object)
{
    _GrTmuVertices* self = O_EMBEDDED_P(_GrTmuVertices, object);

    for (int idx = 0; idx < GLIDE_NUM_TMU; idx++) {
        if (!Z_ISUNDEF(self->tmu[idx])) {
            //remove sync pointer from the object
            grTmuVertices_remove_sync_ref(&self->gtvArray[idx], Z_EMBEDDED_P(_GrTmuVertex, &self->tmu[idx]));

            zval_ptr_dtor(&self->tmu[idx]);    //we remove one reference count
        }
    }

    zend_object_std_dtor(object);
}

void grTmuVertices_remove_sync_ref(GrTmuVertex* my, _GrTmuVertex* from)
{
    for (int cont = 0; cont < MAX_SYNCERS; cont++) {
        if (from->sync_references[cont] == my) {

            from->sync_references[cont] = NULL;
            --from->sync_count; //we substract a sync count
            break;
        }
    }
}

void grTmuVertices_set_sync_ref(GrTmuVertex* my, _GrTmuVertex* to)
{
    for (int cont = 0; cont < MAX_SYNCERS; cont++) {
        if (to->sync_references[cont] == NULL) {

            to->sync_references[cont] = my;
            ++to->sync_count; //we add a sync count
            break;
        }
    }
}

void phpglide2x_register_grTmuVertices(INIT_FUNC_ARGS)
{
    grTmuVertices_ce = register_class_GrTmuVertices(zend_ce_arrayaccess);
    grTmuVertices_ce->create_object = gr_new_obj; //asign an internal constructor

    object_handlers = std_object_handlers;

    //we set the address of the beginning of the whole embedded data
    object_handlers.offset = XtOffsetOf(_GrTmuVertices, std);

    object_handlers.free_obj = gr_free_obj;
}

void flush_grTmuVertices(const _GrTmuVertices* grTmuVertices, GrTmuVertex* buffer)
{
    //we go through the tmus
    for (int cont = 0; cont < GLIDE_NUM_TMU; cont++) {
        
        //if the tmu is not set...
        if (Z_ISUNDEF(grTmuVertices->tmu[cont])) {
            //we restart the memory
            memset(&buffer[cont], 0, sizeof(GrTmuVertex));
            continue;
        }

        flush_grTmuVertex(Z_EMBEDDED_P(_GrTmuVertex, &grTmuVertices->tmu[cont]), &buffer[cont]);
    }
}

void hydrate_grTmuVertices(const GrTmuVertex* buffer, _GrTmuVertices* grTmuVertices)
{
    //we go through the tmus
    for (int cont = 0; cont < GLIDE_NUM_TMU; cont++) {

        //if the tmu is not set...
        if (Z_ISUNDEF(grTmuVertices->tmu[cont])) {
            object_init_ex(&grTmuVertices->tmu[cont], grTmuVertex_ce);
        }

        hydrate_grTmuVertex(&buffer[cont], Z_EMBEDDED_P(_GrTmuVertex, &grTmuVertices->tmu[cont]));
    }
}