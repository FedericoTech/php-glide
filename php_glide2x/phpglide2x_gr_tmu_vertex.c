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

    GrTmuVertex *grTmuVertex = gr_tmuVertex_auto_flush(grTmuVertex_zo);

    php_printf(
        "referenced_mask: %d\n"
        "sow: %f, tow: %f, oow: %f\n",
        O_EMBEDDED_P(_GrTmuVertex, grTmuVertex_zo)->referenced_mask,
        grTmuVertex->sow,
        grTmuVertex->tow,
        grTmuVertex->oow
    );
}
#endif // _DEBUG

PHP_METHOD(GrTmuVertex, flush)
{
    ZEND_PARSE_PARAMETERS_NONE();

    GrTmuVertex* grTmuVertex = gr_tmuVertex_auto_flush(Z_OBJ_P(ZEND_THIS));

    zend_string* bin = zend_string_alloc(sizeof(GrTmuVertex), 0);

    //we flush into the backup data
    memcpy(
        ZSTR_VAL(bin),
        grTmuVertex,
        sizeof(GrTmuVertex)
    );

    ZSTR_VAL(bin)[sizeof(GrTmuVertex)] = '\0';

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

    zend_property_info* info;

    for (int cont = 0; cont < props_num; cont++) {
        info = zend_hash_str_find_ptr(&ce->properties_info, properties[cont], strlen(properties[cont]));

        //we store the offset to find the zvals directly
        grTmuVertex->offsets.arr[cont] = info->offset;
    }

    //grTmuVertex->referenced_mask = 0;

    //it returns the zend object
    return &grTmuVertex->std;
}

static zend_object* gr_clone_obj(zend_object* object)
{
#ifdef DEBUG_HANDLERS
    php_printf(
        "%s\n",
        __FUNCTION__
    );
#endif  //DEBUG_HANDLERS

    // Step 1: Call the default clone handler
    zend_object* new_obj = gr_new_obj(object->ce);

    _GrTmuVertex* clone = O_EMBEDDED_P(_GrTmuVertex, new_obj);
    _GrTmuVertex* orig = O_EMBEDDED_P(_GrTmuVertex, object);

    clone->offsets = orig->offsets;
    clone->tmuVertex = orig->tmuVertex;
    clone->referenced_mask = orig->referenced_mask;

    zend_objects_clone_members(&clone->std, &orig->std);

    return new_obj;
}

static zend_result gr_cast_object(zend_object* readobj, zval* retval, int type)
{
#ifdef DEBUG_HANDLERS
    php_printf(
        "%s, type: %d\n",
        __FUNCTION__,
        type
    );
#endif // DEBUG_HANDLERS

    switch (type) {

    case IS_STRING: {
        GrTmuVertex* vertex = gr_tmuVertex_auto_flush(readobj);

        // produce binary representation
        zend_string* bin = zend_string_alloc(sizeof(GrTmuVertex), 0);

        //we flush into the backup data
        memcpy(
            ZSTR_VAL(bin),
            vertex,
            sizeof(GrTmuVertex)
        );

        ZSTR_VAL(bin)[sizeof(GrTmuVertex)] = '\0';

        ZVAL_STR(retval, bin);

        return SUCCESS;
    }

    default:
        // cast type not supported
        return FAILURE;
    }
}

static void gr_unset_property(zend_object* object, zend_string* member, void** cache_slot)
{
#ifdef DEBUG_HANDLERS
    php_printf(
        "%s: %s\n",
        __FUNCTION__,
        ZSTR_VAL(member)
    );
#endif // DEBUG_HANDLERS

    //we go through the Vector float properties
    for (int cont = 0; cont < props_num; cont++) {
        //if the property is one of them...
        if (zend_string_equals_cstr(member, properties[cont], strlen(properties[cont]))) {

            _GrTmuVertex* v = O_EMBEDDED_P(_GrTmuVertex, object);

            v->tmuVertex.props[cont] = 0.0;

            //we clear the bit as the zval is now a value
            v->referenced_mask &= ~(1u << cont);
            break;
        }
    }

    zend_std_unset_property(object, member, cache_slot);
}

static zval* gr_write_property(zend_object* object, zend_string* name, zval* value, void** cache_slot)
{
#ifdef DEBUG_HANDLERS
    php_printf(
        "%s: %s: %f\n",
        __FUNCTION__,
        ZSTR_VAL(name),
        zval_get_double(value)
    );
#endif // DEBUG_HANDLERS

    //we go through the float properties...
    for (int cont = 0; cont < props_num; cont++) {
        //if we find the property...
        if (zend_string_equals_cstr(name, properties[cont], strlen(properties[cont]))) {

            _GrTmuVertex* v = O_EMBEDDED_P(_GrTmuVertex, object);

            v->tmuVertex.props[cont] = (FxFloat)(Z_ISUNDEF_P(value)
                ? 0.0
                : Z_TYPE_P(value) == IS_DOUBLE
                    ? Z_DVAL_P(value)
                    : zval_get_double(value)
            );

            //we clear the bit as the zval is now a value
            v->referenced_mask &= ~(1u << cont);

            break;
        }
    }

    return zend_std_write_property(object, name, value, cache_slot);
}

static zval* gr_get_property_ptr_ptr(zend_object* object, zend_string* member, int type, void** cache_slot)
{
    /*
        0   BP_VAR_R            // read
        1    BP_VAR_W           // write
        2    BP_VAR_RW          // read/write
        3    BP_VAR_IS          // isset() / empty()-style "is set?" check
        4    BP_VAR_UNSET       // unset()
        5    BP_VAR_FUNC_ARG    // passing as function argument
    */
#ifdef DEBUG_HANDLERS
    php_printf(
        "%s, type: %d\n",
        __FUNCTION__,
        type
    );
#endif // DEBUG_HANDLERS

    //we go through the Vector properties
    for (int cont = 0; cont < props_num; cont++) {
        //if the property is one of them...
        if (zend_string_equals_cstr(member, properties[cont], strlen(properties[cont]))) {

            _GrTmuVertex* v = O_EMBEDDED_P(_GrTmuVertex, object);

            v->referenced_mask |= (1u << cont);  //we mark the property as not loger garanteed

            break;
        }
    }

    // Return NULL to force PHP to use read_property + write_property
    return zend_std_get_property_ptr_ptr(object, member, type, cache_slot);
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
    object_handlers.get_property_ptr_ptr = gr_get_property_ptr_ptr;
    object_handlers.write_property = gr_write_property;
    object_handlers.unset_property = gr_unset_property;
    object_handlers.cast_object = gr_cast_object;
    object_handlers.free_obj = gr_free_obj;
    
    //object_handlers.do_operation = gr_operation;
    //
    //object_handlers.read_property = gr_read_property;
    
    //object_handlers.get_properties = gr_get_properties;
    //object_handlers.has_property = gr_has_property;
    
}

void flush_grTmuVertex(const _GrTmuVertex* grTmuVertex, GrTmuVertex* buffer)
{
    zval* value = NULL;

    //we go through the inner float zvals
    for (int cont = 0; cont < props_num; cont++) {

        //if the property was referenced...
        if (grTmuVertex->referenced_mask & (1u << cont)) {
            value = OBJ_PROP(&grTmuVertex->std, grTmuVertex->offsets.arr[cont]);

#ifdef DEBUG_HANDLERS
            php_printf(
                "[%d][%d][%d] \n", 
                cont, 
                Z_TYPE_P(value), 
                grTmuVertex->referenced_mask
            );
#endif // DEBUG_HANDLERS

            ((FxFloat*)&buffer->sow)[cont] = (FxFloat)zval_get_double(value);
        }
    }
}

void hydrate_grTmuVertex(const GrTmuVertex* buffer, _GrTmuVertex* grTmuVertex)
{
    for (int cont = 0; cont < props_num; cont++) {
        ZVAL_DOUBLE(
            OBJ_PROP(&grTmuVertex->std, grTmuVertex->offsets.arr[cont]),
            ((FxFloat*)buffer)[cont]
        );
    }   
}