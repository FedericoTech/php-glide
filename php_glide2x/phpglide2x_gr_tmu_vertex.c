#include "phpglide2x_structs.h"

zend_class_entry* grTmuVertex_ce;

static const char* properties[] = { "sow", "tow", "oow" };
static const props_num = sizeof properties / sizeof properties[0];

#ifdef _DEBUG
ZEND_FUNCTION(testGrTmuVertex)
{
    zend_object* grTmuVertex_zo = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(grTmuVertex_zo, grTmuVertex_ce)
        ZEND_PARSE_PARAMETERS_END();

    _GrTmuVertex* config = O_EMBEDDED_P(_GrTmuVertex, grTmuVertex_zo);

    GrTmuVertex grTmuVertex;
        
    flush_grTmuVertex(config, &grTmuVertex);

    php_printf(
        "sow: %f, tow: %f, oow: %f\n",
        grTmuVertex.sow,
        grTmuVertex.tow,
        grTmuVertex.oow
    );
}
#endif // _DEBUG

PHP_METHOD(GrTmuVertex, flush)
{
    ZEND_PARSE_PARAMETERS_NONE();

    _GrTmuVertex* obj = O_EMBEDDED_P(_GrTmuVertex, Z_OBJ_P(ZEND_THIS));

    flush_grTmuVertex(obj, &obj->tmuVertex.tmu);

    zend_string* bin = zend_string_alloc(sizeof(GrTmuVertex), 0);

    //we flush into the backup data
    memcpy(
        ZSTR_VAL(bin),
        &obj->tmuVertex.tmu,
        sizeof(GrTmuVertex)
    );

    ZSTR_VAL(bin)[sizeof(GrTmuVertex)] = '\0';

    flush_grTmuVertex(obj, (GrTmuVertex *) ZSTR_VAL(bin));

    RETURN_STR(bin);
}

/*
PHP_METHOD(GrTmuVertex, copyFrom)
{
    zend_object* grTmuVertex_zo = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(grTmuVertex_zo, grTmuVertex_ce)
        ZEND_PARSE_PARAMETERS_END();

    _GrTmuVertex* ths = O_EMBEDDED_P(_GrTmuVertex, Z_OBJ_P(ZEND_THIS));

    _GrTmuVertex* other = O_EMBEDDED_P(_GrTmuVertex, grTmuVertex_zo);

    //if the two are assigned then we can just copy the memory
    if (ths->grTmuVertex && other->grTmuVertex) {
        *ths->grTmuVertex = *other->grTmuVertex;

    //any of then is not assigned, we copy the properties
    }
    else {
        for (int cont = 0; cont < 3; cont++) {

            zend_update_property(
                grTMUConfig_ce,
                &ths->std,
                properties[cont],
                strlen(properties[cont]),
                OBJ_PROP(&other->std, grTmuVertex_ce->properties_info_table[cont]->offset)
            );
        }
    }
}
*/

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

    //all marked as undefined
    for (int cont = 0; cont < props_num; cont++) {
        ZVAL_UNDEF(&grTmuVertex->zvals.arr[cont]);
    }

    //it returns the zend object
    return &grTmuVertex->std;
}

static zval* gr_read_property(zend_object* object, zend_string* name, int type, void** cache_slot, zval* rv)
{
    /*
    #define BP_VAR_R			0
    #define BP_VAR_W			1
    #define BP_VAR_RW			2
    #define BP_VAR_IS			3
    #define BP_VAR_FUNC_ARG		4
    #define BP_VAR_UNSET		5
    */

    //php_printf("type: %d\n", type);


    if (type == BP_VAR_W) {

        php_error_docref(
            NULL,
            E_WARNING,
            "Indirect modification of overloaded property %s::$%s has no effect",
            ZSTR_VAL(object->ce->name),
            ZSTR_VAL(name)
        );
    }

    if (0 & (type != BP_VAR_R && type != BP_VAR_IS)) {

        zend_throw_error(
            NULL,
            "Cannot indirectly modify typed property %s::$%s",
            ZSTR_VAL(object->ce->name),
            ZSTR_VAL(name)
        );
        return &EG(uninitialized_zval);
    }
    else {

        //we go through the float properties
        for (int cont = 0; cont < props_num; cont++) {
            //if property found...
            if (zend_string_equals_cstr(name, properties[cont], strlen(properties[cont]))) {

                _GrTmuVertex* v = O_EMBEDDED_P(_GrTmuVertex, object);

                if (Z_TYPE_P(&v->zvals.arr[cont]) == IS_DOUBLE) {

                    ZVAL_COPY(rv, &v->zvals.arr[cont]);
                    return rv;
                }
            }
        }
    }

    // fallback
    return zend_std_read_property(object, name, type, cache_slot, rv);
}

static zval* gr_write_property(zend_object* object, zend_string* name, zval* value, void** cache_slot)
{
    for (int cont = 0; cont < props_num; cont++) {
        if (zend_string_equals_cstr(name, properties[cont], strlen(properties[cont]))) {

            _GrTmuVertex* v = O_EMBEDDED_P(_GrTmuVertex, object);

            ZVAL_DOUBLE(&v->zvals.arr[cont],
                Z_TYPE_P(value) == IS_DOUBLE
                ? Z_DVAL_P(value)
                : zval_get_double(value)
            );

            v->tmuVertex.props[cont] = (FxFloat)Z_DVAL(v->zvals.arr[cont]);

            return value;
        }
    }

    return zend_std_write_property(object, name, value, cache_slot);
}

static zval* gr_get_property_ptr_ptr(zend_object* object, zend_string* member, int type, void** cache_slot)
{
    for (int cont = 0; cont < props_num; cont++) {
        if (zend_string_equals_cstr(member, properties[cont], strlen(properties[cont]))) {

            return NULL;
        }
    }

    // Return NULL to force PHP to use read_property + write_property
    return zend_std_get_property_ptr_ptr(object, member, type, cache_slot);
}

static HashTable* gr_get_properties(zend_object* obj)
{
    _GrTmuVertex* v = O_EMBEDDED_P(_GrTmuVertex, obj);

    HashTable* props = zend_std_get_properties(obj); // start with dynamic properties

    for (int cont = 0; cont < props_num; cont++) {

        if (Z_TYPE(v->zvals.arr[cont]) != IS_UNDEF) {
            zval tmp;

            //php_printf("%f %d\n", v->zvals.arr[cont], cont);
            ZVAL_COPY(&tmp, &v->zvals.arr[cont]);

            zend_hash_str_update(props, properties[cont], strlen(properties[cont]), &tmp);
        }
    }

    return props;
}

static int gr_has_property(zend_object* object, zend_string* member, int has_set_exists, void** cache_slot)
{
    for (int cont = 0; cont < props_num; cont++) {
        if (zend_string_equals_cstr(member, properties[cont], strlen(properties[cont]))) {

            _GrTmuVertex* v = O_EMBEDDED_P(_GrTmuVertex, object);

            switch (has_set_exists) {
            case ZEND_PROPERTY_EXISTS:
                return 1;

            case ZEND_PROPERTY_ISSET:
                return Z_TYPE(v->zvals.arr[cont]) != IS_UNDEF;

            case ZEND_PROPERTY_NOT_EMPTY:

                if (Z_TYPE(v->zvals.arr[cont]) == IS_UNDEF) {
                    return 0;
                }

                /* if guaranteed double otherwise */
                return Z_DVAL(v->zvals.arr[cont]) != 0.0;
            }
            break;
        }
    }

    return zend_std_has_property(object, member, has_set_exists, cache_slot);
}

static void gr_unset_property(zend_object* object, zend_string* member, void** cache_slot)
{
    for (int cont = 0; cont < props_num; cont++) {
        if (zend_string_equals_cstr(member, properties[cont], strlen(properties[cont]))) {

            _GrTmuVertex* v = O_EMBEDDED_P(_GrTmuVertex, object);

            ZVAL_UNDEF(&v->zvals.arr[cont]);

            v->tmuVertex.props[cont] = 0.0;

            return;
        }
    }

    zend_std_unset_property(object, member, cache_slot);
}

static int gr_compare(zval* o1, zval* o2)
{

    _GrTmuVertex* v1 = Z_EMBEDDED_P(_GrTmuVertex, o1);
    _GrTmuVertex* v2 = Z_EMBEDDED_P(_GrTmuVertex, o2);

    for (int cont = 0; cont < props_num; cont++) {

        //if the masks are different, that's a clue.
        if (Z_TYPE_P(&v1->zvals.arr[cont]) != Z_TYPE_P(&v2->zvals.arr[cont])
            || Z_DVAL_P(&v1->zvals.arr[cont]) != Z_DVAL_P(&v2->zvals.arr[cont])
        ) {
            return 1;
        }
    }

    return 0; // equal
}

static zend_object* gr_clone_obj(zend_object* object)
{
    // Step 1: Call the default clone handler
    zend_object* new_obj = gr_new_obj(object->ce);

    _GrTmuVertex* clone = O_EMBEDDED_P(_GrTmuVertex, new_obj);
    _GrTmuVertex* orig = O_EMBEDDED_P(_GrTmuVertex, object);


    clone->tmuVertex.tmu = orig->tmuVertex.tmu;

    for (int cont = 0; cont < props_num; cont++) {
        ZVAL_COPY(&clone->zvals.arr[cont], &orig->zvals.arr[cont]);
    }

    zend_objects_clone_members(&clone->std, &orig->std);

    return new_obj;
}

static void gr_free_obj(zend_object* object)
{
    zend_object_std_dtor(object);
}

void phpglide2x_register_grTmuVertex(INIT_FUNC_ARGS)
{
    grTmuVertex_ce = register_class_GrTmuVertex(gr_flushable_ce);
    grTmuVertex_ce->create_object = gr_new_obj; //asign an internal constructor

    object_handlers = std_object_handlers;

    //we set the address of the beginning of the whole embedded data
    object_handlers.offset = XtOffsetOf(_GrTmuVertex, std);

    object_handlers.clone_obj = gr_clone_obj;
    //object_handlers.do_operation = gr_operation;
    //object_handlers.cast_object = gr_cast_object;

    object_handlers.write_property = gr_write_property;
    object_handlers.read_property = gr_read_property;
    object_handlers.get_property_ptr_ptr = gr_get_property_ptr_ptr;
    object_handlers.get_properties = gr_get_properties;
    object_handlers.has_property = gr_has_property;
    object_handlers.unset_property = gr_unset_property;
    object_handlers.compare = gr_compare;
    object_handlers.free_obj = gr_free_obj;
}

void flush_grTmuVertex(const _GrTmuVertex* grTmuVertex, GrTmuVertex* buffer)
{
    zval* value = NULL;

    for (int cont = 0; cont < props_num; cont++) {

        ((FxFloat*)&buffer->sow)[cont] = (FxFloat)(Z_ISUNDEF_P(&grTmuVertex->zvals.arr[cont])
            ? 0.0
            : Z_DVAL_P(&grTmuVertex->zvals.arr[cont])
         );
    }
}

void hydrate_grTmuVertex(const GrTmuVertex* buffer, _GrTmuVertex* grTmuVertex)
{
    
    for (int cont = 0; cont < props_num; cont++) {
        ZVAL_DOUBLE(
            &grTmuVertex->zvals.arr[cont],
            ((FxFloat*)buffer)[cont]
        );

    }
    
}