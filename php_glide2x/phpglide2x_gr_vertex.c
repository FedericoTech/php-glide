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

    GrVertex *vertex = gr_vertex_auto_flush(grVertex_zo);

    php_printf(
        "x: %f, y: %f, z: %f, r: %f, g: %f, b: %f, ooz: %f, a: %f, oow: %f\n",
        vertex->x,
        vertex->y,
        vertex->z,

        vertex->r,
        vertex->g,
        vertex->b,
        
        vertex->ooz,
        vertex->a,
        vertex->oow
    );

    for (uint32_t cont = 0; cont < GLIDE_NUM_TMU; cont++) {

        php_printf(
            "[%d] sow: %f, tow: %f, oow: %f\n",
            cont,
            vertex->tmuvtx[cont].sow,
            vertex->tmuvtx[cont].tow,
            vertex->tmuvtx[cont].oow
        );
    }
}
#endif // _DEBUG

PHP_METHOD(GrVertex, flush)
{
    ZEND_PARSE_PARAMETERS_NONE();

    GrVertex* vertex = gr_vertex_auto_flush(Z_OBJ_P(ZEND_THIS));

    zend_string* bin = zend_string_alloc(sizeof(GrVertex), 0);

    //we flush into the backup data
    memcpy(
        ZSTR_VAL(bin),
        vertex,
        sizeof(GrVertex)
    );

    ZSTR_VAL(bin)[sizeof(GrVertex)] = '\0'; // null terminator (optional for binary)

    RETURN_STR(bin);
}


PHP_METHOD(GrVertex, getLength)
{
    ZEND_PARSE_PARAMETERS_NONE();

    _GrVertex* obj = O_EMBEDDED_P(_GrVertex, Z_OBJ_P(ZEND_THIS));

    zval* value = NULL;
    double rtn = 0;

    //through x, y, and z
    for (int cont = 0; cont < 3; cont++) {

        value = OBJ_PROP(&obj->std, obj->offsets.arr[cont]);
        rtn += Z_DVAL_P(value) * Z_DVAL_P(value);
    }

    RETURN_DOUBLE(sqrt(rtn));
}

PHP_METHOD(GrVertex, setAutoload)
{
    zend_long autoload;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(autoload);
    ZEND_PARSE_PARAMETERS_END();

    _GrVertex* obj = O_EMBEDDED_P(_GrVertex, Z_OBJ_P(ZEND_THIS));

    obj->referenced_mask = autoload;
}

PHP_METHOD(GrVertex, isAutoload)
{
    ZEND_PARSE_PARAMETERS_NONE();

    _GrVertex* obj = O_EMBEDDED_P(_GrVertex, Z_OBJ_P(ZEND_THIS));

    RETURN_LONG(obj->referenced_mask);
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
           
    zend_property_info* info;

    for (int cont = 0; cont < floats_num; cont++) {
        info = zend_hash_str_find_ptr(&ce->properties_info, properties[cont], strlen(properties[cont]));

        //we store the offset to find the zvals directly
        grVertex->offsets.arr[cont] = info->offset;
    }

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

    //grVertex->defined_mask = GR_TMUVTX_DEFINED; //only the last one is defined
    

    //it returns the zend object
    return &grVertex->std;
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

    clone->offsets = orig->offsets;
    clone->grVertex = orig->grVertex;
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
        GrVertex* vertex = gr_vertex_auto_flush(readobj);

        // produce binary representation
        zend_string* bin = zend_string_alloc(sizeof(GrVertex), 0);

        //we flush into the backup data
        memcpy(
            ZSTR_VAL(bin),
            vertex,
            sizeof(GrVertex)
        );

        ZSTR_VAL(bin)[sizeof(GrVertex)] = '\0';

        ZVAL_STR(retval, bin);

        return SUCCESS;
    }


    default:
        // cast type not supported
        return FAILURE;
    }
}

static void gr_unset_property(zend_object* object, zend_string* name, void** cache_slot)
{
    //we go through the Vector float properties
    for (int cont = 0; cont < floats_num; cont++) {
        //if the property is one of them...
        if (zend_string_equals_cstr(name, properties[cont], strlen(properties[cont]))) {

            _GrVertex* v = O_EMBEDDED_P(_GrVertex, object);

            v->grVertex.props[cont] = 0.0;

            //we clear the bit as the zval is now a value
            v->referenced_mask &= ~(1u << cont);
            break;
        }
    }

    zend_std_unset_property(object, name, cache_slot);
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

    bool op1_is_vec = EXPECTED(Z_TYPE_P(op1) == IS_OBJECT && Z_OBJCE_P(op1) == grVertex_ce);

    bool op2_is_vec = Z_TYPE_P(op2) == IS_OBJECT && Z_OBJCE_P(op2) == grVertex_ce;

    _GrVertex* v_out = NULL;
    zval* value1 = NULL;

    //if the two of them are vectors...
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

        zval* value2 = NULL;

        //we go through the x, y, z properties
        for (int cont = 0; cont < 3; cont++) {

            value1 = OBJ_PROP(&v_out->std, v_out->offsets.arr[cont]);
            value2 = OBJ_PROP(&v2->std, v2->offsets.arr[cont]);

            double ello1 = Z_ISUNDEF_P(value1)
                ? 0.0
                : Z_DVAL_P(value1);

            double ello2 = Z_ISUNDEF_P(value2)
                ? 0.0
                : Z_DVAL_P(value2);



            switch (opcode) {
            case ZEND_ADD:
                ZVAL_DOUBLE(value1, ello1 + ello2);
                break;
            case ZEND_SUB:
                ZVAL_DOUBLE(value1, ello1 - ello2);
                break;
            case ZEND_MUL:
                ZVAL_DOUBLE(value1, ello1 * ello2);
                break;
            case ZEND_DIV:
                ZVAL_DOUBLE(value1, ello1 / ello2);
                break;
            default:
                zend_throw_exception(NULL, "Unsupported operation", 0);
                return FAILURE;
            }

            //we update the buffer
            v_out->grVertex.props[cont] = (FxFloat)(Z_ISUNDEF_P(value1)
                ? 0.0
                : Z_DVAL_P(value1)
            );
        }

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

    if (
        UNEXPECTED(
            Z_TYPE_P(z_scalar) != IS_LONG
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

    //we go through the x, y and z properties.
    for (int cont = 0; cont < 3; cont++) {

        value1 = OBJ_PROP(&v_out->std, v_out->offsets.arr[cont]);

        double ello1 = Z_ISUNDEF_P(value1)
            ? 0.0
            : Z_DVAL_P(value1);

        switch (opcode) {
        case ZEND_ADD:
            ZVAL_DOUBLE(value1, ello1 + scalar);
            break;
        case ZEND_SUB:
            ZVAL_DOUBLE(value1,
                op1_is_vec
                    ? ello1 - scalar
                    : scalar - ello1
            );
            break;
        case ZEND_MUL:
            ZVAL_DOUBLE(value1, ello1 * scalar);
            break;
        case ZEND_DIV:
            ZVAL_DOUBLE(value1,
                op1_is_vec
                    ? ello1 / scalar
                    : scalar / ello1
            );
            break;
        default:
            zend_throw_exception(NULL, "Unsupported operation", 0);
            return FAILURE;
        }

        //we update the buffer
        v_out->grVertex.props[cont] = (FxFloat)Z_DVAL_P(value1);
    }

    return SUCCESS;
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

    //we go through the float properties...
    for (int cont = 0; cont < floats_num; cont++) {
        //if we find the property...
        if (zend_string_equals_cstr(name, properties[cont], strlen(properties[cont]))) {

            _GrVertex* grVertex = O_EMBEDDED_P(_GrVertex, object);

            grVertex->grVertex.props[cont] = (FxFloat)(Z_ISUNDEF_P(value) 
                ? 0.0 
                : Z_TYPE_P(value) == IS_DOUBLE
                    ? Z_DVAL_P(value)
                    : zval_get_double(value)
            );

            //we clear the bit as the zval is now a value
            grVertex->referenced_mask &= ~(1u << cont);

            break;
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
    #define BP_VAR_R			0   // read like in  = $obj->foo;
    #define BP_VAR_W			1   // write like in $obj->foo = 123
    #define BP_VAR_RW			2   // read and write like in $obj->foo++, $obj->foo += 1
    #define BP_VAR_IS			3   // Read for isset() / existence test	isset($obj->foo)
    #define BP_VAR_FUNC_ARG		4   // Read as a function argument	foo($obj->foo)
    #define BP_VAR_UNSET		5   // Access for unset()	unset($obj->foo)
    */

#endif  //DEBUG_HANDLERS

    //we go through the Vector float properties
    for (int cont = 0; cont < floats_num; cont++) {
        //if the property is one of them...
        if (zend_string_equals_cstr(member, properties[cont], strlen(properties[cont]))) {
            _GrVertex* v = O_EMBEDDED_P(_GrVertex, object);

            v->referenced_mask |= (1u << cont);  //we mark the property as not loger garanteed
            
            break;
        }
    }
    //otherwise, the default behaviour    
    return zend_std_get_property_ptr_ptr(object, member, type, cache_slot);
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
    object_handlers.get_property_ptr_ptr = gr_get_property_ptr_ptr;
    object_handlers.write_property = gr_write_property;
    object_handlers.unset_property = gr_unset_property;
    object_handlers.do_operation = gr_operation;
    object_handlers.cast_object = gr_cast_object;
    object_handlers.free_obj = gr_free_obj;
    
}

void flush_grVertex(const _GrVertex* grVertex, GrVertex* buffer)
{
    zval rv, *value = NULL;
    
    //we go through the inner float zvals
    for (int cont = 0; cont < floats_num; cont++) {
        //if the property was referenced...
        if (grVertex->referenced_mask & (1u << cont)) {
            value = OBJ_PROP(&grVertex->std, grVertex->offsets.arr[cont]);

            php_printf("[%d] \n", Z_TYPE_P(value));

            ((FxFloat*)&buffer->x)[cont] = (FxFloat)zval_get_double(value);
        }
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
    //we go through the inner float zvals
    for (int cont = 0; cont < floats_num; cont++) {

        ZVAL_DOUBLE(
            OBJ_PROP(&grVertex->std, grVertex->offsets.arr[cont]),
            ((FxFloat*)buffer)[cont]
        );
    }

    zval grTmuVertices;

    object_init_ex(&grTmuVertices, grTmuVertices_ce);

    hydrate_grTmuVertices(&buffer->tmuvtx[0], Z_EMBEDDED_P(_GrTmuVertices, &grTmuVertices));

    zend_update_property(grVertex_ce, &grVertex->std, "tmuvtx", sizeof("tmuvtx") - 1, &grTmuVertices);

    zval_ptr_dtor(&grTmuVertices); //destroy the local pointer
    
}

