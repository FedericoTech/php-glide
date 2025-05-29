#include "phpglide3x_abstractVertex.h"

zend_class_entry* abstractVertex_ce;

#ifdef _DEBUG
ZEND_FUNCTION(testAbstractVertex)
{
    zend_object* abstractVertex_zo = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(abstractVertex_zo, abstractVertex_ce)
        ZEND_PARSE_PARAMETERS_END();

    _AbstractVertex_t* abstractVertex = O_EMBEDDED_P(_AbstractVertex_t, abstractVertex_zo);

    php_printf(
        //"x: %f, y: %f, z: %f, r: %f, g: %f, b: %f, ooz: %f, a: %f, oow: %f\n",
        "x: %f, y: %f, a: %f, z: %f, ooz: %f, oow: %f\n",
        (FxFloat) *(FxFloat*) &abstractVertex->abstractVertex.layout,
        (FxFloat) *(FxFloat*) (((char *) &abstractVertex->abstractVertex.layout)+4),
        (FxFloat) * (FxFloat*)(((char*)&abstractVertex->abstractVertex.layout) + 8),
        (FxFloat) * (FxFloat*)(((char*)&abstractVertex->abstractVertex.layout) + 12),
        (FxFloat) * (FxFloat*)(((char*)&abstractVertex->abstractVertex.layout) + 16),
        (FxFloat) * (FxFloat*)(((char*)&abstractVertex->abstractVertex.layout) + 20)

    );
}
#endif // _DEBUG

static zend_object_handlers AbstractVertex_object_handlers;

//function that allocates memory for the object and sets the handlers
zend_object* AbstractVertex_new(zend_class_entry* ce)
{
    //it allocates memory
    _AbstractVertex_t* abstractVertex = zend_object_alloc(sizeof(_AbstractVertex_t), ce);

    //it initializes the object
    zend_object_std_init(&abstractVertex->std, ce);
    object_properties_init(&abstractVertex->std, ce);

    //it sets the handlers
    abstractVertex->std.handlers = &AbstractVertex_object_handlers;

    //it returns the zend object
    return &abstractVertex->std;
}

static zval* gr_write_property(zend_object* object, zend_string* member, zval* value, void** cache_slot)
{

    static const struct {
        const char* name;
        int size;
    } map[] = {
        {"x", 4},
        {"y", 4},
        {"z", 4},
        {"rgb", 12},
        {"ooz", 4},
        {"a", 4},
        {"oow", 4},
        {"st0", 8},
        {"oow0", 4},
        {"st1", 8},
        {"oow1", 4},
        { NULL, 0 }
    };

    zend_class_entry* ce = object->ce;
    _AbstractVertex_t* abstractVertex = O_EMBEDDED_P(_AbstractVertex_t, object);

    int step = 0;
    zend_string* prop_name;
    zend_property_info* prop_info;
    ZEND_HASH_FOREACH_STR_KEY_PTR(&ce->properties_info, prop_name, prop_info) {

        // Skip integer keys if any (usually none)
        if (!prop_name) { continue; }

        php_printf(
            "%d, %s, %s, %f\n",
            step,
            ZSTR_VAL(member),
            ZSTR_VAL(prop_name),
            (float)zval_get_double(value)
        );

        if (zend_string_equal_val(member, prop_name)) {

            zend_property_info* prop_info = zend_get_property_info(ce, prop_name, 1);
            zval* prop_zv = OBJ_PROP(object, prop_info->offset);

            switch (Z_TYPE_P(value))
            {
            case IS_STRING:
                if (!is_numeric_string(Z_STRVAL_P(value), Z_STRLEN_P(value), NULL, NULL, 0)) {
                    break;
                }
            case IS_DOUBLE:
            case IS_LONG:
                *(FxFloat*)(((char*)&abstractVertex->abstractVertex.layout) + step) = (FxFloat)zval_get_double(value);
                break;
            }

            php_printf("done\n");
            break;
        }

        //we look up the size of the param...
        for (int i = 0; map[i].name != NULL; i++) {
            //if param is found...
            if (ZSTR_LEN(prop_name) == strlen(map[i].name)
                && memcmp(ZSTR_VAL(prop_name), map[i].name, ZSTR_LEN(prop_name)) == 0){
                //we add the size
                step += map[i].size;
            }
        }

    } ZEND_HASH_FOREACH_END();

    return zend_std_write_property(object, member, value, cache_slot);
}

void phpglide3x_register_abstractVertex(INIT_FUNC_ARGS)
{
    abstractVertex_ce = register_class_AbstractVertex();
    abstractVertex_ce->create_object = AbstractVertex_new; //asign an internal constructor

    memcpy(
        &AbstractVertex_object_handlers,	// our handler 
        &std_object_handlers,				        // the standard handler
        sizeof(zend_object_handlers)		        // size of the standar handler
    );

    //we set the address of the beginning of the whole embedded data
    AbstractVertex_object_handlers.offset = XtOffsetOf(_AbstractVertex_t, std);
    AbstractVertex_object_handlers.write_property = gr_write_property;
}