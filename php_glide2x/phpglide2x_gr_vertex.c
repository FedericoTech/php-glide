#include "phpglide2x_structs.h"

zend_class_entry* grVertex_ce;

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

static zval* gr_read_property(zend_object* object, zend_string* member, int type, void** cache_slot, zval* rv)
{
    /*
    //if (zend_string_equals_literal(object->ce->name, "GrAT3DConfig_t")) {

        zend_class_entry* ce = object->ce;
        zend_property_info* prop_info = zend_get_property_info(ce, member, 1);

        zval* prop_zv = OBJ_PROP(object, prop_info->offset);

        if (Z_TYPE_P(prop_zv) != IS_UNDEF) {
            return prop_zv;
        }

        _GrAT3DConfig_t* config = O_EMBEDDED_P(_GrAT3DConfig_t, object);

        if (zend_string_equals_literal(member, "rev")) {
            zend_update_property_long(
                ce, object,
                ZSTR_VAL(member), ZSTR_LEN(member),
                config->grAT3DConfig.rev
            );
        }

    //}
    */
    return zend_std_read_property(object, member, type, cache_slot, rv);
}
/*
static zval* gr_write_property(zend_object* object, zend_string* member, zval* value, void** cache_slot)
{
    if (zend_string_equals_literal(object->ce->name, "GrAT3DConfig_t")) {

        _GrAT3DConfig_t* config = O_EMBEDDED_P(_GrAT3DConfig_t, object);  // Get your embedded struct from the object

        if (zend_string_equals_literal(member, "rev")) {
            config->grAT3DConfig.rev = Z_LVAL_P(value);
        }
    }

    return zend_std_write_property(object, member, value, cache_slot);
}
*/

static HashTable* get_properties(zend_object* object)
{
    /*
    zend_class_entry* ce = object->ce;
    _GrAT3DConfig_t* config = O_EMBEDDED_P(_GrAT3DConfig_t, object);

    zend_string* member = zend_string_init("rev", strlen("rev"), 0);

    zend_property_info* prop_info = zend_get_property_info(ce, member, 1);
    zval* prop_zv = OBJ_PROP(object, prop_info->offset);

    //if the property is not yet defined...
    if (Z_TYPE_P(prop_zv) == IS_UNDEF) {
        zend_update_property_long(
            ce, object,
            ZSTR_VAL(member), ZSTR_LEN(member),
            config->grAT3DConfig.rev
        );
    }

    zend_string_release(member);
    */
    return zend_std_get_properties(object);
}

void phpglide2x_register_grVertex(INIT_FUNC_ARGS)
{
    grTmuVertex_ce = register_class_GrVertex();
    grTmuVertex_ce->create_object = GrVertex_new; //asign an internal constructor

    memcpy(
        &grVertex_object_handlers,	// our handler 
        &std_object_handlers,				        // the standard handler
        sizeof(zend_object_handlers)		        // size of the standar handler
    );

    //we set the address of the beginning of the whole embedded data
    grVertex_object_handlers.offset = XtOffsetOf(_GrVertex, std);
    //grVertex_object_handlers.read_property = gr_read_property;
    //grVertex_object_handlers.get_properties = get_properties;
    //grVertex_object_handlers.write_property = gr_write_property;
}