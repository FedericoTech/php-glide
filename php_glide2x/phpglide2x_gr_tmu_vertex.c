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

    if (config->grTmuVertex == NULL) {
        php_printf("not assigned\n");
    } else {
        php_printf(
            "sow: %f, tow: %f, oow: %f\n",
            &config->grTmuVertex->sow,
            &config->grTmuVertex->tow,
            &config->grTmuVertex->oow
        );
    }
}
#endif // _DEBUG

PHP_METHOD(GrTmuVertex, flush)
{
    ZEND_PARSE_PARAMETERS_NONE();

    _GrTmuVertex* obj = O_EMBEDDED_P(_GrTmuVertex, Z_OBJ_P(ZEND_THIS));

    zend_string* bin = zend_string_alloc(sizeof(GrTmuVertex), 0);

    ZSTR_VAL(bin)[sizeof(GrTmuVertex)] = '\0';

    flush_grTmuVertex(obj, (GrTmuVertex *) ZSTR_VAL(bin));

    //if it's got a parent, then we can copy the data in the parent
    if (obj->grTmuVertex != NULL) {

        memcpy(obj->grTmuVertex, ZSTR_VAL(bin), ZSTR_LEN(bin));
    }

    RETURN_STR(bin);
}

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


static zval* gr_write_property(zend_object* object, zend_string* name, zval* value, void** cache_slot)
{
    _GrTmuVertex* v = O_EMBEDDED_P(_GrTmuVertex, object);

    if (v->grTmuVertex != NULL) {
        for (int cont = 0; cont < 9; cont++) {
            if (zend_string_equals_cstr(name, properties[cont], strlen(properties[cont]))) {
                ((FxFloat*)v->grTmuVertex)[cont] = (FxFloat)zval_get_double(value);
                return value;
            }
        }
    }

    return zend_std_write_property(object, name, value, cache_slot);
}

static zval* gr_read_property(zend_object* object, zend_string* name, int type, void** cache_slot, zval* rv)
{
    _GrTmuVertex* v = O_EMBEDDED_P(_GrTmuVertex, object);

    if (v->grTmuVertex != NULL) {

        for (int cont = 0; cont < 3; cont++) {
            if (zend_string_equals_cstr(name, properties[cont], strlen(properties[cont]))) {
                ZVAL_DOUBLE(rv, (double)((FxFloat*)v->grTmuVertex)[cont]);
                return rv;
            }
        }
    }

    return zend_std_read_property(object, name, type, cache_slot, rv);
}

static zval* gr_get_property_ptr_ptr(zend_object* object, zend_string* member, int type, void** cache_slot)
{
    _GrTmuVertex* v = O_EMBEDDED_P(_GrTmuVertex, object);

    if (v->grTmuVertex != NULL) {
        // Return NULL to force PHP to use read_property + write_property
        return NULL;
    }

    return zend_std_get_property_ptr_ptr(object, member, type, cache_slot);
}

static HashTable* gr_get_properties(zend_object* obj) {

    _GrTmuVertex* v = O_EMBEDDED_P(_GrTmuVertex, obj);

    if (v->grTmuVertex != NULL) {

        HashTable* props = zend_std_get_properties(obj); // start with dynamic properties

        zval tmp;

        for (int cont = 0; cont < 3; cont++) {

            ZVAL_DOUBLE(&tmp, (double)((FxFloat *)v->grTmuVertex)[cont]);

            zend_hash_str_update(props, properties[cont], strlen(properties[cont]), &tmp);
        }

        return props;
    }

    return zend_std_get_properties(obj);
}

static zend_object* gr_clone_obj(zend_object* object)
{
    // Step 1: Call the default clone handler
    zend_object* new_obj = gr_new_obj(object->ce);

    _GrTmuVertex* clone = O_EMBEDDED_P(_GrTmuVertex, new_obj);
    _GrTmuVertex* orig = O_EMBEDDED_P(_GrTmuVertex, object);

    //clone->grTmuVertex = orig->grTmuVertex;

    zend_objects_clone_members(&clone->std, &orig->std);

    return new_obj;
}

void phpglide2x_register_grTmuVertex(INIT_FUNC_ARGS)
{
    grTmuVertex_ce = register_class_GrTmuVertex(gr_flushable_ce);
    grTmuVertex_ce->create_object = gr_new_obj; //asign an internal constructor

    object_handlers = std_object_handlers;

    //we set the address of the beginning of the whole embedded data
    object_handlers.offset = XtOffsetOf(_GrTmuVertex, std);

    object_handlers.clone_obj = gr_clone_obj;
    object_handlers.write_property = gr_write_property;
    object_handlers.read_property = gr_read_property;
    object_handlers.get_property_ptr_ptr = gr_get_property_ptr_ptr;
    object_handlers.get_properties = gr_get_properties;
}

void flush_grTmuVertex(const _GrTmuVertex* grTmuVertex, GrTmuVertex* buffer)
{
    zval* value = NULL;

    for (int cont = 0; cont < 3; cont++) {
        //this way we don't use zend_read_property
        value = OBJ_PROP(&grTmuVertex->std, grTmuVertex_ce->properties_info_table[cont]->offset);

        ((FxFloat*)&buffer->sow)[cont] = (FxFloat)(Z_ISUNDEF_P(value)
            ? 0.0
            : Z_DVAL_P(value));
    }
}

void hydrate_grTmuVertex(const GrTmuVertex* buffer, _GrTmuVertex* grTmuVertex)
{
    for (int cont = 0; cont < 3; cont++) {
        zend_update_property_double(
            grTMUConfig_ce,
            &grTmuVertex->std,
            properties[cont],
            strlen(properties[cont]),
            (zend_long)((FxFloat*)buffer)[cont]
        );
    }
}