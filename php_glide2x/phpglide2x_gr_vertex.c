#include "phpglide2x_structs.h"

zend_class_entry* grVertex_ce;

const char* properties[] = { "x", "y", "z", "r", "g", "b", "ooz", "a", "oow", "tmuvtx" };

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

static zend_object_handlers grVertex_object_handlers;

//function that allocates memory for the object and sets the handlers
zend_object* GrVertex_new(zend_class_entry* ce)
{
    //it allocates memory
    _GrVertex* grVertex = zend_object_alloc(sizeof(_GrVertex), ce);

    //it initializes the object
    zend_object_std_init(&grVertex->std, ce);
    object_properties_init(&grVertex->std, ce);

    //it sets the handlers
    grVertex->std.handlers = &grVertex_object_handlers;

    //it returns the zend object
    return &grVertex->std;
}

static zval* gr_write_property(zend_object* object, zend_string* member, zval* value, void** cache_slot)
{
    if(object->ce == grVertex_ce) {
        _GrVertex* config = O_EMBEDDED_P(_GrVertex, object);  // Get your embedded struct from the object

        for (int cont = 0; cont < 10; cont++) {

            if (zend_string_equals_cstr(member, properties[cont], strlen(properties[cont]))) {
                //from x to woo
                if (cont < 9) {
                    switch (Z_TYPE_P(value))
                    {
                    case IS_STRING:
                        if (!is_numeric_string(Z_STRVAL_P(value), Z_STRLEN_P(value), NULL, NULL, 0)) {
                            break;
                        }
                    case IS_DOUBLE:
                    case IS_LONG:
                        ((FxFloat*)&config->grVertex.x)[cont] = (FxFloat)zval_get_double(value);
                    }
                }
                //if tmuvtx...
                else {
                    zval* entry = NULL;
                    zend_string* key = NULL;

                    for (uint32_t cont = 0; cont < min(GLIDE_NUM_TMU, zend_hash_num_elements(Z_ARRVAL_P(value))); cont++) {

                        if ((entry = zend_hash_index_find(Z_ARRVAL_P(value), cont)) != NULL) {
                            _GrTmuVertex* gtv = O_EMBEDDED_P(_GrTmuVertex, Z_OBJ_P(entry));

                            memcpy(
                                &config->grVertex.tmuvtx[cont],
                                &gtv->grTmuVertex,
                                sizeof(GrTmuVertex)
                            );
                        }
                    }
                }

                config->initialized_flags |= (1 << cont);

                return value;
            }
        } // for
    }

    return zend_std_write_property(object, member, value, cache_slot);
}

static zval* gr_read_property(zend_object* object, zend_string* member, int type, void** cache_slot, zval* rv)
{
    if (object->ce == grVertex_ce) {
        
        for (int cont = 0; cont < 10; cont++) {
            if (zend_string_equals_cstr(member, properties[cont], strlen(properties[cont]))) {

                _GrVertex* config = O_EMBEDDED_P(_GrVertex, object);

                //from x to woo...
                if (cont < 9) {
                    ZVAL_DOUBLE(rv, ((FxFloat*)&config->grVertex.x)[cont]);
                }
                //if tmuvtx...
                else {
                    /*
                    zval* entry = NULL;
                    zend_string* key = NULL;

                    for (uint32_t cont = 0; cont < min(GLIDE_NUM_TMU, zend_hash_num_elements(Z_ARRVAL_P(value))); cont++) {

                        if ((entry = zend_hash_index_find(Z_ARRVAL_P(value), cont)) != NULL) {
                            _GrTmuVertex* gtv = O_EMBEDDED_P(_GrTmuVertex, Z_OBJ_P(entry));

                            memcpy(
                                &config->grVertex.tmuvtx[cont],
                                &gtv->grTmuVertex,
                                sizeof(GrTmuVertex)
                            );
                        }
                    }
                    */
                }

                return rv;
            }
        }
    }

    // fallback to std handler for unknown properties
    return zend_std_read_property(object, member, type, cache_slot, rv);
}

static zval* gr_get_property_ptr_ptr(zend_object* obj, zend_string* name, int type, void** cache_slot) {
    return NULL; // Force PHP to use write_property
}


int gr_has_property(zend_object* object, zend_string* member, int has_set_exists, void** cache_slot)
{
    //from x to tmuvtx
    for (int cont = 0; cont < 10; cont++) {
        if (zend_string_equals_cstr(member, properties[cont], strlen(properties[cont]))) {

            _GrVertex* config = O_EMBEDDED_P(_GrVertex, object);

            //if the property isn't initialized...
            if ((config->initialized_flags & (1 << cont)) == 0) {
                return 0;   //it is signaled this way
            }

            switch(has_set_exists) {
            case ZEND_PROPERTY_EXISTS:
                return 1; // yes, "foo" exists
            case ZEND_PROPERTY_ISSET:
                return 1;
            case ZEND_PROPERTY_NOT_EMPTY:
                return ((FxFloat*)&config->grVertex.x)[cont] != 0.0;
            }

            break;
        }
    }

    return zend_std_has_property(object, member, has_set_exists, cache_slot);
}

static void gr_unset_property(zend_object* object, zend_string* member, void** cache_slot)
{
    for (int cont = 0; cont < 10; cont++) {
        if (zend_string_equals_cstr(member, properties[cont], strlen(properties[cont]))) {

            _GrVertex* config = O_EMBEDDED_P(_GrVertex, object);

            //from x to woo
            if (cont < 9) {
                ((FxFloat*)&config->grVertex.x)[cont] = 0.0;
            }
            //if tmuvtx...
            else {

            }

            config->initialized_flags &= ~(1 << cont);
            break;
        }
    }

    zend_std_unset_property(object, member, cache_slot);
}


static HashTable* gr_get_properties(zend_object* object)
{
    _GrVertex* config = O_EMBEDDED_P(_GrVertex, object);  // Get your embedded struct from the object

    HashTable* props;
    zval zv;

    // Allocate and initialize HashTable if not done
    props = zend_std_get_properties(object);

    for (int cont = 0; cont < 10; cont++) {
        //if the current property isn't initialized...
        if ((config->initialized_flags & (1 << cont)) == 0) {
            continue;   //we skip it
        }

        //from x to woo
        if (cont < 9) {
            ZVAL_DOUBLE(&zv, ((FxFloat*)&config->grVertex.x)[cont]);
            zend_hash_str_update(props, properties[cont], strlen(properties[cont]), &zv);
        }
        //if tmuvtx...
        else {

        }
    }

    return props;
}

static zend_object* gr_clone_obj(zend_object* object)
{
    // Step 1: Call the default clone handler
    zend_object* new_obj = GrVertex_new(object->ce);
               
    _GrVertex* clone = O_EMBEDDED_P(_GrVertex, new_obj);
    _GrVertex* orig = O_EMBEDDED_P(_GrVertex, object);

    memcpy(&clone->grVertex, &orig->grVertex, sizeof(GrVertex));

    //we copy the flags also
    clone->initialized_flags = orig->initialized_flags;
    
    zend_objects_clone_members(&clone->std, &orig->std);

    return new_obj;
}

void phpglide2x_register_grVertex(INIT_FUNC_ARGS)
{
    grVertex_ce = register_class_GrVertex();
    grVertex_ce->create_object = GrVertex_new; //asign an internal constructor

    memcpy(
        &grVertex_object_handlers,	// our handler 
        &std_object_handlers,				        // the standard handler
        sizeof(zend_object_handlers)		        // size of the standar handler
    );

    //we set the address of the beginning of the whole embedded data
    grVertex_object_handlers.offset = XtOffsetOf(_GrVertex, std);
    grVertex_object_handlers.write_property = gr_write_property;
    grVertex_object_handlers.read_property = gr_read_property;

    grVertex_object_handlers.unset_property = gr_unset_property;
    
    grVertex_object_handlers.get_property_ptr_ptr = gr_get_property_ptr_ptr; //this is for passing by reference. it returns null because our data is in a c struct
    
    grVertex_object_handlers.get_properties = gr_get_properties;
    grVertex_object_handlers.has_property = gr_has_property;
    
    grVertex_object_handlers.clone_obj = gr_clone_obj;
}