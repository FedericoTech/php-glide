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

    zend_string* bin = zend_string_alloc(sizeof(GrTmuVertex), 0);

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

    zend_property_info* info;

    for (int cont = 0; cont < props_num; cont++) {
        info = zend_hash_str_find_ptr(&ce->properties_info, properties[cont], strlen(properties[cont]));

        grTmuVertex->offsets[cont] = info->offset;
    }

    //it returns the zend object
    return &grTmuVertex->std;
}

void phpglide2x_register_grTmuVertex(INIT_FUNC_ARGS)
{
    grTmuVertex_ce = register_class_GrTmuVertex(gr_flushable_ce);
    grTmuVertex_ce->create_object = gr_new_obj; //asign an internal constructor

    object_handlers = std_object_handlers;

    //we set the address of the beginning of the whole embedded data
    object_handlers.offset = XtOffsetOf(_GrTmuVertex, std);
}

void flush_grTmuVertex(const _GrTmuVertex* grTmuVertex, GrTmuVertex* buffer)
{
    zval* value = NULL;

    for (int cont = 0; cont < props_num; cont++) {
        //this way we don't use zend_read_property
        value = OBJ_PROP(&grTmuVertex->std, grTmuVertex->offsets[cont]);

        ((FxFloat*)&buffer->sow)[cont] = (FxFloat)(Z_ISUNDEF_P(value) 
            ? 0.0 
            : Z_DVAL_P(value)
        );
    }
}

void hydrate_grTmuVertex(const GrTmuVertex* buffer, _GrTmuVertex* grTmuVertex)
{
    zval* value = NULL;

    for (int cont = 0; cont < props_num; cont++) {

        value = OBJ_PROP(&grTmuVertex->std, grTmuVertex->offsets[cont]);

        ZVAL_DOUBLE(value, ((FxFloat*)buffer)[cont]);
    }
}