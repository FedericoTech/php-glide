#include "phpglide2x_structs.h"

zend_class_entry* grVertex_ce;

static const char* properties[] = { "x", "y", "z", "r", "g", "b", "ooz", "a", "oow", "tmuvtx" };
static const floats_num = sizeof (properties) / sizeof (properties[0]) - 1;

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
        flush_grVertex(config, &config->grVertex);
    }

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

    zend_string* bin = zend_string_alloc(sizeof(GrVertex), 0);

    //we flush into the backup data
    memcpy(
        ZSTR_VAL(bin),
        &obj->grVertex,
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

    RETURN_DOUBLE(sqrt(obj->grVertex.x * obj->grVertex.x + obj->grVertex.y * obj->grVertex.y + obj->grVertex.z * obj->grVertex.z));
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
    //it allocates memory
    _GrVertex* grVertex = zend_object_alloc(sizeof(_GrVertex), ce);

    //it initializes the object
    zend_object_std_init(&grVertex->std, ce);
    object_properties_init(&grVertex->std, ce);

    //it sets the handlers
    grVertex->std.handlers = &object_handlers;

    

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
    

    //it returns the zend object
    return &grVertex->std;
}

static zend_result gr_cast_object(zend_object* readobj, zval* retval, int type)
{
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
            v_out->grVertex.x += v2->grVertex.x;
            v_out->grVertex.y += v2->grVertex.y;
            v_out->grVertex.z += v2->grVertex.z;
            break;
        case ZEND_SUB:
            v_out->grVertex.x -= v2->grVertex.x;
            v_out->grVertex.y -= v2->grVertex.y;
            v_out->grVertex.z -= v2->grVertex.z;
            break;
        case ZEND_MUL:
            v_out->grVertex.x *= v2->grVertex.x;
            v_out->grVertex.y *= v2->grVertex.y;
            v_out->grVertex.z *= v2->grVertex.z;
            break;
        case ZEND_DIV:
            v_out->grVertex.x /= v2->grVertex.x;
            v_out->grVertex.y /= v2->grVertex.y;
            v_out->grVertex.z /= v2->grVertex.z;
            break;
        default:
            zend_throw_exception(NULL, "Unsupported operation", 0);
            return FAILURE;
        }

        //hydrate_grVertex(&v_out->grVertex, v_out);

        return SUCCESS;
    }

    FxFloat scalar;
    zval* zv = NULL;

    if (op1_is_vec) {

        if (Z_TYPE_P(op2) != IS_LONG && Z_TYPE_P(op2) != IS_DOUBLE) {
            zend_throw_exception(NULL, "Right operand must be a scalar", 0);
            return FAILURE;
        }

        zv = op1;

        scalar = (FxFloat)zval_get_double(op2);

    }
    else {
        if (Z_TYPE_P(op1) != IS_LONG && Z_TYPE_P(op1) != IS_DOUBLE) {
            zend_throw_exception(NULL, "Left operand must be a scalar", 0);
            return FAILURE;
        }

        zv = op2;

        scalar = (FxFloat)zval_get_double(op1);
    }

    //if it not += or -= and so on...
    if (Z_TYPE_P(result) == IS_UNDEF) {
        //we clone the object
        zend_object* zo = Z_OBJ_HANDLER_P(op1, clone_obj)(Z_OBJ_P(op1));
        v_out = O_EMBEDDED_P(_GrVertex, zo);
        ZVAL_OBJ(result, zo);

    //otherwise we use the same object
    } else {
        v_out = Z_EMBEDDED_P(_GrVertex, zv);
    }
    
    switch (opcode) {
    case ZEND_ADD:
        v_out->grVertex.x += scalar;
        v_out->grVertex.y += scalar;
        v_out->grVertex.z += scalar;
        break;
    case ZEND_SUB:
        v_out->grVertex.x -= scalar;
        v_out->grVertex.y -= scalar;
        v_out->grVertex.z -= scalar;
        break;
    case ZEND_MUL:
        v_out->grVertex.x *= scalar;
        v_out->grVertex.y *= scalar;
        v_out->grVertex.z *= scalar;
        break;
    case ZEND_DIV:
        v_out->grVertex.x /= scalar;
        v_out->grVertex.y /= scalar;
        v_out->grVertex.z /= scalar;
        break;
    default:
        zend_throw_exception(NULL, "Unsupported operation", 0);
        return FAILURE;
    }

    hydrate_grVertex(&v_out->grVertex, v_out);

    return SUCCESS;
}


static zend_object* gr_clone_obj(zend_object* object)
{
    // Step 1: Call the default clone handler
    zend_object* new_obj = gr_new_obj(object->ce);
               
    _GrVertex* clone = O_EMBEDDED_P(_GrVertex, new_obj);
    _GrVertex* orig = O_EMBEDDED_P(_GrVertex, object);

    clone->grVertex = orig->grVertex;
    clone->auto_flush = orig->auto_flush;
        
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
    object_handlers.do_operation = gr_operation;
    object_handlers.cast_object = gr_cast_object;
}

void flush_grVertex(const _GrVertex* grVertex, GrVertex* buffer)
{
    zval* value = NULL;

    for (int cont = 0; cont < floats_num; cont++) {
        //this way we don't use zend_read_property
        value = OBJ_PROP(&grVertex->std, grVertex_ce->properties_info_table[cont]->offset);

        ((FxFloat*)&buffer->x)[cont] = (FxFloat)(Z_ISUNDEF_P(value)
            ? 0.0
            : Z_DVAL_P(value));
    }

    //we retrieve the tmuvtx property
    value = OBJ_PROP(&grVertex->std, grVertex_ce->properties_info_table[9]->offset);

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
            grVertex_ce,
            &grVertex->std,
            properties[cont],
            strlen(properties[cont]),
            (double)(((FxFloat*)buffer)[cont])
        );
    }

    zval grTmuVertices;

    object_init_ex(&grTmuVertices, grTmuVertices_ce);

    hydrate_grTmuVertices(&buffer->tmuvtx[0], Z_EMBEDDED_P(_GrTmuVertices, &grTmuVertices));

    zend_update_property(grVertex_ce, &grVertex->std, "tmuvtx", sizeof("tmuvtx") - 1, &grTmuVertices);

    zval_ptr_dtor(&grTmuVertices); //destroy the local pointer
        
    /*
    zval grTmuVertex_arr_zval;
    array_init_size(&grTmuVertex_arr_zval, GLIDE_NUM_TMU);
    
    for (int cont2 = 0; cont2 < GLIDE_NUM_TMU; cont2++) {
        zval grTmuVertex;
        object_init_ex(&grTmuVertex, grTmuVertex_ce);

        hydrate_grTmuVertex(&buffer->tmuvtx[cont2], O_EMBEDDED_P(_GrTmuVertex, Z_OBJ(grTmuVertex)));

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
    */
}

