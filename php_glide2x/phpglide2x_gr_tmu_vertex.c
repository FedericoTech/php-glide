#include "phpglide2x_structs.h"

zend_class_entry* grTmuVertex_ce;

#ifdef _DEBUG
ZEND_FUNCTION(testGrTmuVertex)
{
    zend_object* grTmuVertex_zo = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(grTmuVertex_zo, grTmuVertex_ce)
        ZEND_PARSE_PARAMETERS_END();

    _GrTmuVertex* config = O_EMBEDDED_P(_GrTmuVertex, grTmuVertex_zo);

    php_printf(
        "sow: %f, tow: %f, oow: %f\n",
        config->grTmuVertex.sow,
        config->grTmuVertex.tow,
        config->grTmuVertex.oow
    );
}
#endif // _DEBUG

static zend_object_handlers grTmuVertex_object_handlers;

//function that allocates memory for the object and sets the handlers
zend_object* GrTmuVertex_new(zend_class_entry* ce)
{
    //it allocates memory
    _GrTmuVertex* grTmuVertex = zend_object_alloc(sizeof(_GrTmuVertex), ce);

    //it initializes the object
    zend_object_std_init(&grTmuVertex->std, ce);
    object_properties_init(&grTmuVertex->std, ce);

    //it sets the handlers
    grTmuVertex->std.handlers = &grTmuVertex_object_handlers;

    //it returns the zend object
    return &grTmuVertex->std;
}

static zval* gr_write_property(zend_object* object, zend_string* member, zval* value, void** cache_slot)
{
    if (zend_string_equals_literal(object->ce->name, "GrTmuVertex")) {
        
        const char* properties[] = { "sow", "tow", "oow"};

        _GrTmuVertex* config = O_EMBEDDED_P(_GrTmuVertex, object);  // Get your embedded struct from the object

        for (int cont = 0; cont < 3; cont++) {
            if (zend_string_equals_cstr(member, properties[cont], strlen(properties[cont]))) {
                
                
                switch (Z_TYPE_P(value))
                {
                case IS_STRING:
                    if (!is_numeric_string(Z_STRVAL_P(value), Z_STRLEN_P(value), NULL, NULL, 0)) {
                        break;
                    }
                case IS_DOUBLE:
                case IS_LONG:
                    *((float*)&config->grTmuVertex + cont) = (float)zval_get_double(value);
                }
                break;
            }
        }
    }

    return zend_std_write_property(object, member, value, cache_slot);
}

void phpglide2x_register_grTmuVertex(INIT_FUNC_ARGS)
{
    grTmuVertex_ce = register_class_GrTmuVertex();
    grTmuVertex_ce->create_object = GrTmuVertex_new; //asign an internal constructor

    memcpy(
        &grTmuVertex_object_handlers,	// our handler 
        &std_object_handlers,				        // the standard handler
        sizeof(zend_object_handlers)		        // size of the standar handler
    );

    //we set the address of the beginning of the whole embedded data
    grTmuVertex_object_handlers.offset = XtOffsetOf(_GrTmuVertex, std);
    grTmuVertex_object_handlers.write_property = gr_write_property;
}