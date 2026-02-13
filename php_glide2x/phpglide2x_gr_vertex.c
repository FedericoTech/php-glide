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

    GrVertex buffer;

    _GrVertex* config = O_EMBEDDED_P(_GrVertex, grVertex_zo);

    flush_grVertex(config, &buffer);

    php_printf(
        "x: %f, y: %f, z: %f, r: %f, g: %f, b: %f, ooz: %f, a: %f, oow: %f\n",
        buffer.x,
        buffer.y,
        buffer.z,

        buffer.r,
        buffer.g,
        buffer.b,
        
        buffer.ooz,
        buffer.a,
        buffer.oow
    );

    for (uint32_t cont = 0; cont < GLIDE_NUM_TMU; cont++) {

        php_printf(
            "[%d] sow: %f, tow: %f, oow: %f\n",
            cont,
            buffer.tmuvtx[cont].sow,
            buffer.tmuvtx[cont].tow,
            buffer.tmuvtx[cont].oow
        );
    }
}
#endif // _DEBUG

PHP_METHOD(GrVertex, flush)
{
    ZEND_PARSE_PARAMETERS_NONE();

    _GrVertex* obj = O_EMBEDDED_P(_GrVertex, Z_OBJ_P(ZEND_THIS));

    zend_string* bin = zend_string_alloc(sizeof(GrVertex), 0);

    flush_grVertex(obj, (GrVertex*) &ZSTR_VAL(bin));

    ZSTR_VAL(bin)[sizeof(GrVertex)] = '\0'; // null terminator (optional for binary)

    RETURN_STR(bin);
}


PHP_METHOD(GrVertex, getLength)
{
    ZEND_PARSE_PARAMETERS_NONE();

    _GrVertex* obj = O_EMBEDDED_P(_GrVertex, Z_OBJ_P(ZEND_THIS));

    zval rv, *value = NULL;
    double rtn = 0;

    for (int cont = 0; cont < 3; cont++) {

        value = OBJ_PROP(&obj->std, obj->offsets.arr[cont]);

        /*
        value = zend_read_property(
            grVertex_ce, Z_OBJ_P(ZEND_THIS),
            properties[cont], strlen(properties[cont]),
            0, &rv
        );
        */

        rtn += Z_DVAL_P(value) * Z_DVAL_P(value);
    }

    RETURN_DOUBLE(sqrt(rtn));
}

PHP_METHOD(GrVertex, setAutoload)
{
    zend_bool autoload;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_BOOL(autoload);
    ZEND_PARSE_PARAMETERS_END();

    _GrVertex* obj = O_EMBEDDED_P(_GrVertex, Z_OBJ_P(ZEND_THIS));

    //obj->auto_flush = autoload;
}

PHP_METHOD(GrVertex, isAutoload)
{
    ZEND_PARSE_PARAMETERS_NONE();

    _GrVertex* obj = O_EMBEDDED_P(_GrVertex, Z_OBJ_P(ZEND_THIS));

    RETURN_BOOL(0);
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

        php_printf("%s %d %d\n", properties[cont], cont, info->offset);
        

        grVertex->offsets.arr[cont] = info->offset;
    }

    //zend_error(E_ERROR, "Fatal extension error");

    
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

        flush_grVertex(v, (GrVertex *) ZSTR_VAL(buf));

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
    zval rv, * value1 = NULL;
    double rst;

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

        zval *value2 = NULL;

        for (int cont = 0; cont < 3; cont++) {

            value1 = OBJ_PROP(&v_out->std, v_out->offsets.arr[cont]);


            //if(Z_TYPE(value1) == IS_UNDEF){}

            /*
            value1 = zend_read_property(
                grVertex_ce, &v_out->std,
                properties[cont], strlen(properties[cont]),
                0, &rv
            );
            */

            value2 = OBJ_PROP(&v2->std, v2->offsets.arr[cont]);

            
            /*
            value2 = zend_read_property(
                grVertex_ce, &v2->std,
                properties[cont], strlen(properties[cont]),
                0, &rv
            );
            */

            switch (opcode) {
            case ZEND_ADD:
                ZVAL_DOUBLE(value1, Z_DVAL_P(value1) + Z_DVAL_P(value2));
                break;
            case ZEND_SUB:
                ZVAL_DOUBLE(value1, Z_DVAL_P(value1) - Z_DVAL_P(value2));
                break;
            case ZEND_MUL:
                ZVAL_DOUBLE(value1, Z_DVAL_P(value1) * Z_DVAL_P(value2));
                break;
            case ZEND_DIV:
                ZVAL_DOUBLE(value1, Z_DVAL_P(value1) / Z_DVAL_P(value2));
                break;
            default:
                zend_throw_exception(NULL, "Unsupported operation", 0);
                return FAILURE;
            }
            /*
            zend_update_property_double(
                grVertex_ce, &v_out->std,
                properties[cont], strlen(properties[cont]),
                rst
            );
            */
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

    for (int cont = 0; cont < 3; cont++) {

        value1 = OBJ_PROP(&v_out->std, v_out->offsets.arr[cont]);

        /*
        value1 = zend_read_property(
            grVertex_ce, &v_out->std,
            properties[cont], strlen(properties[cont]),
            0, &rv
        );
        */

        switch (opcode) {
        case ZEND_ADD:
            ZVAL_DOUBLE(value1, Z_DVAL_P(value1) + scalar);
            break;
        case ZEND_SUB:
            ZVAL_DOUBLE(value1,
                op1_is_vec
                ? Z_DVAL_P(value1) - scalar
                : scalar - Z_DVAL_P(value1)
            );
            break;
        case ZEND_MUL:
            ZVAL_DOUBLE(value1, Z_DVAL_P(value1) * scalar);
            break;
        case ZEND_DIV:
            ZVAL_DOUBLE(value1,
                op1_is_vec
                ? Z_DVAL_P(value1) / scalar
                : scalar / Z_DVAL_P(value1)
            );
            break;
        default:
            zend_throw_exception(NULL, "Unsupported operation", 0);
            return FAILURE;
        }
        /*
        zend_update_property_double(
            grVertex_ce, &v_out->std,
            properties[cont], strlen(properties[cont]),
            rst
        );
        */
    }

    return SUCCESS;
}

void phpglide2x_register_grVertex(INIT_FUNC_ARGS)
{
    grVertex_ce = register_class_GrVertex(gr_flushable_ce);
    grVertex_ce->create_object = gr_new_obj; //asign an internal constructor

    object_handlers = std_object_handlers;
    
    //we set the address of the beginning of the whole embedded data
    object_handlers.offset = XtOffsetOf(_GrVertex, std);


    object_handlers.do_operation = gr_operation;
    object_handlers.cast_object = gr_cast_object;
}

void flush_grVertex(const _GrVertex* grVertex, GrVertex* buffer)
{
    zval rv, *value = NULL;

    for (int cont = 0; cont < floats_num; cont++) {

        //grVertex->offsets.arr[cont

        php_printf("%s %d %d\n", properties[cont], cont, grVertex->offsets.arr[cont]);

        value = OBJ_PROP(&grVertex->std, grVertex->offsets.arr[cont]);

        /*
        value = zend_read_property(
            grVertex_ce, (zend_object*)&grVertex->std,
            properties[cont], strlen(properties[cont]),
            1, &rv
        );
        */

        ((FxFloat*)&buffer->x)[cont] = (FxFloat)(Z_ISUNDEF_P(value)
            ? 0.0
            : Z_DVAL_P(value)
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
    zval* value = NULL;

    for (int cont = 0; cont < floats_num; cont++) {

        value = OBJ_PROP(&grVertex->std, grVertex->offsets.arr[cont]);

        ZVAL_DOUBLE(value, ((FxFloat*)buffer)[cont]);
        /*
        zend_update_property_double(
            grVertex_ce, &grVertex->std, 
            properties[cont], strlen(properties[cont]),
            ((FxFloat*)buffer)[cont]
        );
        */
    }

    zval grTmuVertices;

    object_init_ex(&grTmuVertices, grTmuVertices_ce);

    hydrate_grTmuVertices(&buffer->tmuvtx[0], Z_EMBEDDED_P(_GrTmuVertices, &grTmuVertices));

    zend_update_property(
        grVertex_ce, &grVertex->std,
        "tmuvtx", sizeof("tmuvtx") - 1, 
        &grTmuVertices
    );

    zval_ptr_dtor(&grTmuVertices); //destroy the local pointer
    
}

