#include "phpglide2x_structs.h"

//#define DEBUG_HANDLERS

zend_class_entry* grVertex_ce;

static const char* properties[] = { "x", "y", "z", "r", "g", "b", "ooz", "a", "oow", "tmuvtx" };
static const properties_num = sizeof(properties) / sizeof(properties[0]);
static const floats_num = sizeof(properties) / sizeof(properties[0]) - 1;

#ifdef _DEBUG
ZEND_FUNCTION(testGrVertex)
{
    zend_object* grVertex_zo = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(grVertex_zo, grVertex_ce)
        ZEND_PARSE_PARAMETERS_END();

    _GrVertex* config = O_EMBEDDED_P(_GrVertex, grVertex_zo);

    //if the autoflush is set...
    if (config->auto_flush) {
        //we flush
        flush_grVertex(config, &config->grVertex.vertex);
    }

    php_printf(
        "x: %f, y: %f, z: %f, r: %f, g: %f, b: %f, ooz: %f, a: %f, oow: %f\n",
        config->grVertex.vertex.x,
        config->grVertex.vertex.y,
        config->grVertex.vertex.z,

        config->grVertex.vertex.r,
        config->grVertex.vertex.g,
        config->grVertex.vertex.b,
        
        config->grVertex.vertex.ooz,
        config->grVertex.vertex.a,
        config->grVertex.vertex.oow
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

    flush_grVertex(obj, &obj->grVertex.vertex);

    zend_string* bin = zend_string_alloc(sizeof(GrVertex), 0);

    //we flush into the backup data
    memcpy(
        ZSTR_VAL(bin),
        &obj->grVertex.vertex,
        sizeof(GrVertex)
    );

    ZSTR_VAL(bin)[sizeof(GrVertex)] = '\0'; // null terminator (optional for binary)

    RETURN_STR(bin);
}


PHP_METHOD(GrVertex, getLength)
{
    ZEND_PARSE_PARAMETERS_NONE();

    _GrVertex* obj = O_EMBEDDED_P(_GrVertex, Z_OBJ_P(ZEND_THIS));

    //flush_grVertex(obj, &obj->grVertex);

    RETURN_DOUBLE(sqrt(
          obj->grVertex.vertex.x * obj->grVertex.vertex.x
        + obj->grVertex.vertex.y * obj->grVertex.vertex.y
        + obj->grVertex.vertex.z * obj->grVertex.vertex.z
    ));
}

PHP_METHOD(GrVertex, setAutoload)
{
    zend_bool autoload;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_BOOL(autoload);
    ZEND_PARSE_PARAMETERS_END();

    _GrVertex* obj = O_EMBEDDED_P(_GrVertex, Z_OBJ_P(ZEND_THIS));

    obj->auto_flush = autoload;
}

PHP_METHOD(GrVertex, isAutoload)
{
    ZEND_PARSE_PARAMETERS_NONE();

    _GrVertex* obj = O_EMBEDDED_P(_GrVertex, Z_OBJ_P(ZEND_THIS));

    RETURN_BOOL(obj->auto_flush);
}

PHP_METHOD(GrVertex, fromString)
{
    char* string = NULL;
    size_t string_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(string, string_len)
        ZEND_PARSE_PARAMETERS_END();

    if (string == NULL) {
        zend_throw_exception(zend_exception_get_default(), "String cannot be NULL", 1);
        return;
    }

    if (string_len != sizeof(GrVertex)) {
        zend_throw_exception(zend_exception_get_default(), "String must be 60 bytes long", 1);
        return;
    }

    zval zv;
    object_init_ex(&zv, grVertex_ce);

    zend_object* obj = Z_OBJ(zv);

    _GrVertex* grv = O_EMBEDDED_P(_GrVertex, obj);

    hydrate_grVertex((GrVertex*)string, grv);

    memcpy(&grv->grVertex, string, sizeof(GrVertex));

    RETURN_OBJ(obj);
}

static zend_object_handlers object_handlers;

//function that allocates memory for the object and sets the handlers
static zend_object* gr_new_obj(zend_class_entry* ce)
{
#ifdef DEBUG_HANDLERS
    php_printf(
        "%s, %s\n",
        __FUNCTION__,
        ZSTR_VAL(ce->name)
    );
#endif  //DEBUG_HANDLERS

    //it allocates memory
    _GrVertex* grVertex = zend_object_alloc(sizeof(_GrVertex), ce);

    //it initializes the object
    zend_object_std_init(&grVertex->std, ce);
    object_properties_init(&grVertex->std, ce);

    //it sets the handlers
    grVertex->std.handlers = &object_handlers;
           
    grVertex->defined_mask = 0; //all marked as undefined

    //grVertex->auto_flush = true;

    //now we create the GrTmuVertices instance
    
    zval tmuvtx;

    // Create GrTmuVertices object
    object_init_ex(&tmuvtx, grTmuVertices_ce);
        
    zend_update_property(
        grVertex_ce,
        &grVertex->std,
        "tmuvtx",
        sizeof("tmuvtx") - 1,
        &tmuvtx
    );

    zval_ptr_dtor(&tmuvtx);

    //we set the pointer
    _GrTmuVertices* tmuvtx_obj = O_EMBEDDED_P(_GrTmuVertices, Z_OBJ(tmuvtx));

    //we create the GrTmuVertex instances
    for (int i = 0; i < GLIDE_NUM_TMU; i++) {
        object_init_ex(&tmuvtx_obj->tmu[i], grTmuVertex_ce);
    }

    grVertex->defined_mask = GR_TMUVTX_DEFINED; //only the last one is defined
    

    //it returns the zend object
    return &grVertex->std;
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

    _GrVertex* v = O_EMBEDDED_P(_GrVertex, readobj);

    switch (type) {

    case IS_STRING: {
        // produce binary representation
        zend_string* buf = zend_string_alloc(sizeof(GrVertex), 0);
        memcpy(ZSTR_VAL(buf), &v->grVertex, sizeof(GrVertex));
        ZSTR_VAL(buf)[sizeof(GrVertex)] = '\0';

        ZVAL_STR(retval, buf);

        return SUCCESS;
    }


    default:
        // cast type not supported
        return FAILURE;
    }
}

static zend_result gr_operation(uint8_t opcode, zval* result, zval* op1, zval* op2)
{
#ifdef DEBUG_HANDLERS
    php_printf(
        "%s, opcode: %d\n",
        __FUNCTION__,
        opcode
    );
#endif // DEBUG_HANDLERS

    bool op1_is_vec = Z_TYPE_P(op1) == IS_OBJECT && Z_OBJCE_P(op1) == grVertex_ce;

    bool op2_is_vec = Z_TYPE_P(op2) == IS_OBJECT && Z_OBJCE_P(op2) == grVertex_ce;

    _GrVertex* v_out = NULL;

    //if two of them are vectors...
    if (op1_is_vec && op2_is_vec) {

        //if not defined, operations are +, -, and so on...
        if (Z_TYPE_P(result) == IS_UNDEF) {
            //we clone the object
            zend_object* zo = Z_OBJ_HANDLER_P(op1, clone_obj)(Z_OBJ_P(op1));
            v_out = O_EMBEDDED_P(_GrVertex, zo);
            ZVAL_OBJ(result, zo);

        //if the fined, operations are +=, -=, and so on...
        } else {
            v_out = Z_EMBEDDED_P(_GrVertex, op1);
        }

        _GrVertex* v2 = Z_EMBEDDED_P(_GrVertex, op2);

        switch (opcode) {
        case ZEND_ADD:
            for (int cont = 0; cont < 3; cont++) {
                v_out->shadow[cont] += v2->shadow[cont];
                v_out->grVertex.props[cont] = (FxFloat)v_out->shadow[cont];
                v_out->defined_mask |= (1 << cont);
            }
            break;
        case ZEND_SUB:
            for (int cont = 0; cont < 3; cont++) {
                v_out->shadow[cont] -= v2->shadow[cont];
                v_out->grVertex.props[cont] = (FxFloat)v_out->shadow[cont];
                v_out->defined_mask |= (1 << cont);
            }
            break;
        case ZEND_MUL:
            for (int cont = 0; cont < 3; cont++) {
                v_out->shadow[cont] *= v2->shadow[cont];
                v_out->grVertex.props[cont] = (FxFloat)v_out->shadow[cont];
                v_out->defined_mask |= (1 << cont);
            }
            break;
        case ZEND_DIV:
            for (int cont = 0; cont < 3; cont++) {
                v_out->shadow[cont] /= v2->shadow[cont];
                v_out->grVertex.props[cont] = (FxFloat)v_out->shadow[cont];
                v_out->defined_mask |= (1 << cont);
            }
            break;
        default:
            zend_throw_exception(NULL, "Unsupported operation", 0);
            return FAILURE;
        }

        

        //hydrate_grVertex(&v_out->grVertex, v_out);

        return SUCCESS;
    }

    zval* z_scalar = NULL;
    zval* z_vector = NULL;
    
    //if the op1 is the object...
    if (op1_is_vec) {

        z_vector = op1;
        z_scalar = op2;

    //if the op2 is the object...
    } else {
        z_scalar = op1;
        z_vector = op2;
    }

    if (Z_TYPE_P(z_scalar) != IS_LONG
        && Z_TYPE_P(z_scalar) != IS_DOUBLE
        && (
            Z_TYPE_P(z_scalar) != IS_STRING
            || is_numeric_string(
                Z_STRVAL_P(z_scalar),
                Z_STRLEN_P(z_scalar),
                NULL,
                NULL,
                0
            ) == 0
        )
    ) {
        zend_throw_exception(NULL, "The scalar must be a number", 0);
        return FAILURE;
    }

    double scalar = zval_get_double(z_scalar);

    //if it not += or -= and so on...
    if (Z_TYPE_P(result) == IS_UNDEF) {
        //we clone the object
        zend_object* zo = Z_OBJ_HANDLER_P(z_vector, clone_obj)(Z_OBJ_P(z_vector));
        v_out = O_EMBEDDED_P(_GrVertex, zo);
        ZVAL_OBJ(result, zo);

    //otherwise we use the same object
    } else {
        v_out = Z_EMBEDDED_P(_GrVertex, z_vector);
    }

    switch (opcode) {
    case ZEND_ADD:
        for (int cont = 0; cont < 3; cont++) {
            v_out->shadow[cont] += scalar;
            v_out->grVertex.props[cont] = (FxFloat)v_out->shadow[cont];
            v_out->defined_mask |= (1 << cont);
        }
        break;
    case ZEND_SUB:
        for (int cont = 0; cont < 3; cont++) {

            if (op1_is_vec) {
                v_out->shadow[cont] -= scalar;
            }
            else {
                v_out->shadow[cont] = scalar - v_out->shadow[cont];
            }

            v_out->grVertex.props[cont] = (FxFloat)v_out->shadow[cont];
            v_out->defined_mask |= (1 << cont);
        }
        break;
    case ZEND_MUL:
        for (int cont = 0; cont < 3; cont++) {
            v_out->shadow[cont] *= scalar;
            v_out->grVertex.props[cont] = (FxFloat)v_out->shadow[cont];
            v_out->defined_mask |= (1 << cont);
        }
        break;
    case ZEND_DIV:
        for (int cont = 0; cont < 3; cont++) {

            if (op1_is_vec) {
                v_out->shadow[cont] /= scalar;
            }
            else {
                v_out->shadow[cont] = scalar / v_out->shadow[cont];
            }

            v_out->grVertex.props[cont] = (FxFloat)v_out->shadow[cont];
            v_out->defined_mask |= (1 << cont);
        }
        break;
    default:
        zend_throw_exception(NULL, "Unsupported operation", 0);
        return FAILURE;
    }

    //hydrate_grVertex(&v_out->grVertex, v_out);

    return SUCCESS;
}

static zval* gr_read_property(zend_object* object, zend_string* name, int type, void** cache_slot, zval* rv)
{
#ifdef DEBUG_HANDLERS
    php_printf(
        "%s, prop: %s, type: %d\n",
        __FUNCTION__,
        ZSTR_VAL(name),
        type
    );
#endif // DEBUG_HANDLERS

    /*
    #define BP_VAR_R			0
    #define BP_VAR_W			1
    #define BP_VAR_RW			2
    #define BP_VAR_IS			3
    #define BP_VAR_FUNC_ARG		4
    #define BP_VAR_UNSET		5
    */

    if (0 && (type != BP_VAR_R && type != BP_VAR_IS)) {
        zend_throw_error(
            NULL, 
            "%s properties are virtual and cannot be referenced.",
            ZSTR_VAL(object->ce->name)
        );
        return &EG(uninitialized_zval);
    }
    else {

        //we go through the float properties
        for (int cont = 0; cont < floats_num; cont++) {
            //if property found...
            if (zend_string_equals_cstr(name, properties[cont], strlen(properties[cont]))) {

                _GrVertex* v = O_EMBEDDED_P(_GrVertex, object);

                //php_printf("%s [%d]: - %f\n", properties[cont], v->defined_mask & (1 << cont), v->shadow[cont]);

                if (v->defined_mask & (1 << cont)) {
                    ZVAL_DOUBLE(rv, v->shadow[cont]);

                    return rv;
                }

                break;
            }
        }
    }

    // fallback
    return zend_std_read_property(object, name, type, cache_slot, rv);
}

static zval* gr_write_property(zend_object* object, zend_string* name, zval* value, void** cache_slot)
{
#ifdef DEBUG_HANDLERS
    php_printf(
        "%s, prop: %s\n", 
        __FUNCTION__, 
        ZSTR_VAL(name)
    );
#endif  //DEBUG_HANDLERS

    for (int cont = 0; cont < floats_num; cont++) {
        if (zend_string_equals_cstr(name, properties[cont], strlen(properties[cont]))) {

            _GrVertex* v = O_EMBEDDED_P(_GrVertex, object);

            //if the value is the right type...
            v->shadow[cont] = Z_TYPE_P(value) == IS_DOUBLE
                ? Z_DVAL_P(value)
                : zval_get_double(value)
            ;

            v->grVertex.props[cont] = (FxFloat)v->shadow[cont];

            v->defined_mask |= (1 << cont);
            
            return value;
        }
    }

    return zend_std_write_property(object, name, value, cache_slot);
}



static zval* gr_get_property_ptr_ptr(zend_object* object, zend_string* member, int type, void** cache_slot)
{
#ifdef DEBUG_HANDLERS
    php_printf(
        "%s, prop: %s, type: %d\n",
        __FUNCTION__,
        ZSTR_VAL(member),
        type
    );

    /*
    #define BP_VAR_R			0
    #define BP_VAR_W			1
    #define BP_VAR_RW			2
    #define BP_VAR_IS			3
    #define BP_VAR_FUNC_ARG		4
    #define BP_VAR_UNSET		5
    */

#endif  //DEBUG_HANDLERS
      

    for (int cont = 0; cont < floats_num; cont++) {
        if (zend_string_equals_cstr(member, properties[cont], strlen(properties[cont]))) {

            return NULL;
        }
    }

    // Return NULL to force PHP to use read_property + write_property
    return zend_std_get_property_ptr_ptr(object, member, type, cache_slot);
}

static HashTable* gr_get_properties(zend_object* obj)
{
#ifdef DEBUG_HANDLERS
    php_printf(
        "%s\n",
        __FUNCTION__
    );
#endif  //DEBUG_HANDLERS

    _GrVertex* v = O_EMBEDDED_P(_GrVertex, obj);

    HashTable* props = zend_std_get_properties(obj); // start with dynamic properties

    for (int cont = 0; cont < floats_num; cont++) {

        if (v->defined_mask & (1 << cont)) {
            zval tmp;

            //php_printf("%f %d\n", v->shadow[cont], cont);

            ZVAL_DOUBLE(&tmp, v->shadow[cont]);

            zend_hash_str_update(props, properties[cont], strlen(properties[cont]), &tmp);
        }
    }

    return props;
}

static int gr_has_property(zend_object* object, zend_string* member, int has_set_exists, void** cache_slot)
{
#ifdef DEBUG_HANDLERS
    php_printf(
        "%s, prop: %s, has_set_exist: %d\n",
        __FUNCTION__,
        ZSTR_VAL(member),
        has_set_exists
    );

    //#define ZEND_PROPERTY_ISSET     0x0          /* Property exists and is not NULL */
    //#define ZEND_PROPERTY_NOT_EMPTY ZEND_ISEMPTY /* Property is not empty */
    //#define ZEND_PROPERTY_EXISTS    0x2          /* Property exists */

#endif  //DEBUG_HANDLERS

    for (int cont = 0; cont < floats_num; cont++) {
        if (zend_string_equals_cstr(member, properties[cont], strlen(properties[cont]))) {

            _GrVertex* v = O_EMBEDDED_P(_GrVertex, object);

            switch (has_set_exists) {
            case ZEND_PROPERTY_EXISTS:
                return 1;

            case ZEND_PROPERTY_ISSET:
                return (v->defined_mask & (1 << cont)) != 0;

            case ZEND_PROPERTY_NOT_EMPTY:
                /* empty(): false if undefined or falsy */
                if (!(v->defined_mask & (1 << cont))) {
                    return 0;
                }
                return v->shadow[cont] != 0.0;
            }
            break;
        }
    }
    
    return zend_std_has_property(object, member, has_set_exists, cache_slot);
}

static void gr_unset_property(zend_object* object, zend_string* member, void** cache_slot)
{
#ifdef DEBUG_HANDLERS
    php_printf(
        "%s, prop: %s\n",
        __FUNCTION__,
        ZSTR_VAL(member)
    );
#endif  //DEBUG_HANDLERS

    for (int cont = 0; cont < floats_num; cont++) {
        if (zend_string_equals_cstr(member, properties[cont], strlen(properties[cont]))) {

            _GrVertex* v = O_EMBEDDED_P(_GrVertex, object);

            v->defined_mask &= ~(1 << cont);

            v->grVertex.props[cont] = 0.0;
            v->shadow[cont] = 0.0;

            return;
        }
    }

    zend_std_unset_property(object, member, cache_slot);
}

static int gr_compare(zval* o1, zval* o2)
{
#ifdef DEBUG_HANDLERS
    php_printf(
        "%s\n",
        __FUNCTION__
    );
#endif  //DEBUG_HANDLERS

    _GrVertex* v1 = Z_EMBEDDED_P(_GrVertex, o1);
    _GrVertex* v2 = Z_EMBEDDED_P(_GrVertex, o2);

    //if the masks are different, that's a clue.
    if (v1->defined_mask != v2->defined_mask) {
        return 1;
    }

    for (int cont = 0; cont < floats_num; cont++) {
        if (v1->grVertex.props[cont] != v2->grVertex.props[cont]) {
            return 1;
        }
    }

    return 0; // equal
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
               
    _GrVertex* clone = O_EMBEDDED_P(_GrVertex, new_obj);
    _GrVertex* orig = O_EMBEDDED_P(_GrVertex, object);

    clone->defined_mask = orig->defined_mask;
    clone->grVertex.vertex = orig->grVertex.vertex;

    memcpy(clone->shadow, orig->shadow, sizeof(orig->shadow));
            
    zend_objects_clone_members(&clone->std, &orig->std);
    
    return new_obj;
}

static void gr_free_obj(zend_object* object)
{
#ifdef DEBUG_HANDLERS
    php_printf(
        "%s\n",
        __FUNCTION__
    );
#endif  //DEBUG_HANDLERS

    zend_object_std_dtor(object);
}

void phpglide2x_register_grVertex(INIT_FUNC_ARGS)
{
    grVertex_ce = register_class_GrVertex(gr_flushable_ce);
    grVertex_ce->create_object = gr_new_obj; //asign an internal constructor

    object_handlers = std_object_handlers;
    
    //we set the address of the beginning of the whole embedded data
    object_handlers.offset = XtOffsetOf(_GrVertex, std);

    object_handlers.clone_obj = gr_clone_obj;
    object_handlers.do_operation = gr_operation;
    object_handlers.cast_object = gr_cast_object;

    object_handlers.write_property = gr_write_property;
    object_handlers.read_property = gr_read_property;
    object_handlers.get_property_ptr_ptr = gr_get_property_ptr_ptr;
    object_handlers.get_properties = gr_get_properties;
    object_handlers.has_property = gr_has_property;
    object_handlers.unset_property = gr_unset_property;
    object_handlers.compare = gr_compare;
    object_handlers.free_obj = gr_free_obj;
}

void flush_grVertex(const _GrVertex* grVertex, GrVertex* buffer)
{
    zval rv, *value = NULL;

    for (int cont = 0; cont < floats_num; cont++) {

        zval* value = zend_read_property(
            grVertex_ce, (zend_object*) &grVertex->std,
            properties[cont], strlen(properties[cont]),
            0,
            &rv
        );

        ((FxFloat*)&buffer->x)[cont] = (FxFloat)(Z_ISUNDEF_P(value)
            ? 0.0
            : (FxFloat)Z_DVAL_P(value)
        );
    }

    value = zend_read_property(
        grVertex_ce, (zend_object *) & grVertex->std,
        "tmuvtx", sizeof("tmuvtx") - 1,
        0, &rv
    );

    //if it wasn't defined...
    if (Z_ISUNDEF_P(value)) {
        //we set all to zero
        memset(&buffer->tmuvtx, 0, sizeof(GrTmuVertex) * 2);
    }
    else {
        flush_grTmuVertices(Z_EMBEDDED_P(_GrTmuVertices, value), buffer->tmuvtx);
    }
}

void hydrate_grVertex(const GrVertex* buffer, _GrVertex* grVertex)
{
    for (int cont = 0; cont < floats_num; cont++) {

        zend_update_property_double(
            grVertex_ce, (zend_object*)&grVertex->std,
            properties[cont], strlen(properties[cont]),
            ((FxFloat*)buffer)[cont]
        );
    }

    zval grTmuVertices;

    object_init_ex(&grTmuVertices, grTmuVertices_ce);

    hydrate_grTmuVertices(&buffer->tmuvtx[0], Z_EMBEDDED_P(_GrTmuVertices, &grTmuVertices));

    zend_update_property(grVertex_ce, &grVertex->std, "tmuvtx", sizeof("tmuvtx") - 1, &grTmuVertices);

    zval_ptr_dtor(&grTmuVertices); //destroy the local pointer
    
}

