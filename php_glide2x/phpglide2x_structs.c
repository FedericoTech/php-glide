#include "phpglide2x_structs.h"

zend_class_entry* grTMUConfig_ce;
zend_class_entry* grVoodooConfig_ce;
zend_class_entry* grSst96Config_ce;
zend_class_entry* grAT3DConfig_ce;
zend_class_entry* sST_ce;
zend_class_entry* grHwConfiguration_ce;
zend_class_entry* grTmuVertex_ce;
zend_class_entry* grVertex_ce;

void phpglide2x_register_structs(INIT_FUNC_ARGS)
{
    zval val;
    zend_string* property_name = NULL;

    const zend_function_entry no_methods[] = {
        PHP_FE_END
    };

    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "GrTMUConfig_t", no_methods);
    grTMUConfig_ce = zend_register_internal_class_ex(&ce, NULL);
    grTMUConfig_ce->ce_flags |= ZEND_ACC_FINAL;

    // Declare properties
    ZVAL_UNDEF(&val);
    property_name = zend_string_init_interned("tmuRev", sizeof("tmuRev") - 1, 1);
    zend_declare_typed_property(
        grTMUConfig_ce,
        property_name,          // name
        &val,                   // default value
        ZEND_ACC_PUBLIC,        // access scope
        NULL,
        (zend_type)ZEND_TYPE_INIT_MASK(MAY_BE_LONG) // type
    );
    //zend_string_release(property_name);

    property_name = zend_string_init_interned("tmuRam", sizeof("tmuRam") - 1, 1);
    zend_declare_typed_property(
        grTMUConfig_ce,
        property_name,          // name
        &val,                   // default value
        ZEND_ACC_PUBLIC,        // access scope
        NULL,
        (zend_type)ZEND_TYPE_INIT_MASK(MAY_BE_LONG) // type
    );
    //zend_string_release(property_name);

    INIT_CLASS_ENTRY(ce, "GrVoodooConfig_t", no_methods);
    grVoodooConfig_ce = zend_register_internal_class_ex(&ce, NULL);
    grVoodooConfig_ce->ce_flags |= ZEND_ACC_FINAL;

    // Declare properties
    ZVAL_UNDEF(&val);

    property_name = zend_string_init_interned("fbRam", sizeof("fbRam") - 1, 1);
    zend_declare_typed_property(
        grVoodooConfig_ce,
        property_name,          // name
        &val,                   // default value
        ZEND_ACC_PUBLIC,        // access scope
        NULL,
        (zend_type)ZEND_TYPE_INIT_MASK(MAY_BE_LONG) // type
    );
    //zend_string_release(property_name);

    property_name = zend_string_init_interned("fbiRev", sizeof("fbiRev") - 1, 1);
    zend_declare_typed_property(
        grVoodooConfig_ce,
        property_name,          // name
        &val,                   // default value
        ZEND_ACC_PUBLIC,        // access scope
        NULL,
        (zend_type)ZEND_TYPE_INIT_MASK(MAY_BE_LONG) // type
    );
    //zend_string_release(property_name);

    property_name = zend_string_init_interned("nTexelfx", sizeof("nTexelfx") - 1, 1);
    zend_declare_typed_property(
        grVoodooConfig_ce,
        property_name,          // name
        &val,                   // default value
        ZEND_ACC_PUBLIC,        // access scope
        NULL,
        (zend_type)ZEND_TYPE_INIT_MASK(MAY_BE_LONG) // type
    );
    //zend_string_release(property_name);

    ZVAL_FALSE(&val);
    property_name = zend_string_init_interned("sliDetect", sizeof("sliDetect") - 1, 1);
    zend_declare_typed_property(
        grVoodooConfig_ce,
        property_name,          // name
        &val,                   // default value
        ZEND_ACC_PUBLIC,        // access scope
        NULL,
        (zend_type)ZEND_TYPE_INIT_MASK(MAY_BE_BOOL) // type
    );
    //zend_string_release(property_name);
    
    ZVAL_EMPTY_ARRAY(&val);
    property_name = zend_string_init_interned("tmuConfig", sizeof("tmuConfig") - 1, 1);

    zend_declare_typed_property(
        grVoodooConfig_ce, 
        property_name,
        &val,
        ZEND_ACC_PUBLIC, 
        NULL, 
        (zend_type)ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY)
    );
    //zend_string_release(property_name);
    
    INIT_CLASS_ENTRY(ce, "GrSst96Config_t", no_methods);
    grSst96Config_ce = zend_register_internal_class_ex(&ce, NULL);
    grSst96Config_ce->ce_flags |= ZEND_ACC_FINAL;

    // Declare properties
    ZVAL_UNDEF(&val);
    property_name = zend_string_init_interned("fbRam", sizeof("fbRam") - 1, 1);
    zend_declare_typed_property(
        grSst96Config_ce,
        property_name,          // name
        &val,                   // default value
        ZEND_ACC_PUBLIC,        // access scope
        NULL,
        (zend_type)ZEND_TYPE_INIT_MASK(MAY_BE_LONG) // type
    );
    //zend_string_release(property_name);

    property_name = zend_string_init_interned("tmuConfig", sizeof("tmuConfig") - 1, 1);
    zend_declare_typed_property(
        grSst96Config_ce, 
        property_name,
        &val,
        ZEND_ACC_PUBLIC, 
        NULL,
        (zend_type) ZEND_TYPE_INIT_CLASS(zend_string_init_interned("GrTMUConfig_t", sizeof("GrTMUConfig_t") - 1, 1), 0, 0)
    );
    //zend_string_release(property_name);

    zend_register_class_alias("GrVoodoo2Config_t", grVoodooConfig_ce);

    INIT_CLASS_ENTRY(ce, "GrAT3DConfig_t", no_methods);
    grAT3DConfig_ce = zend_register_internal_class_ex(&ce, NULL);
    grAT3DConfig_ce->ce_flags |= ZEND_ACC_FINAL;

    ZVAL_UNDEF(&val);
    property_name = zend_string_init_interned("rev", sizeof("rev") - 1, 1);
    zend_declare_typed_property(
        grAT3DConfig_ce, 
        property_name,
        &val, 
        ZEND_ACC_PUBLIC, 
        NULL, 
        (zend_type)ZEND_TYPE_INIT_MASK(MAY_BE_LONG)
    );
    //zend_string_release(property_name);
    

    INIT_CLASS_ENTRY(ce, "SST_t", no_methods);
    sST_ce = zend_register_internal_class_ex(&ce, NULL);
    sST_ce->ce_flags |= ZEND_ACC_FINAL;

    //Declare properties
    ZVAL_UNDEF(&val);

    property_name = zend_string_init_interned("type", sizeof("type") - 1, 1);
    zend_declare_typed_property(
        sST_ce, 
        property_name, 
        &val, 
        ZEND_ACC_PUBLIC, 
        NULL, 
        (zend_type) ZEND_TYPE_INIT_CLASS(zend_string_init_interned("GrSstType", sizeof("GrSstType") - 1, 1), 0, 0)
    );
    //zend_string_release(property_name);
    
    ZVAL_UNDEF(&val);
    zend_string* property_sstBoard_class_GrVoodooConfig_t = zend_string_init_interned("GrVoodooConfig_t", sizeof("GrVoodooConfig_t") - 1, 1);
    zend_string* property_sstBoard_class_GrSst96Config_t = zend_string_init_interned("GrSst96Config_t", sizeof("GrSst96Config_t") - 1, 1);
    zend_string* property_sstBoard_class_GrAT3DConfig_t = zend_string_init_interned("GrAT3DConfig_t", sizeof("GrAT3DConfig_t") - 1, 1);
    zend_string* property_sstBoard_class_GrVoodoo2Config_t = zend_string_init_interned("GrVoodoo2Config_t", sizeof("GrVoodoo2Config_t") - 1, 1);

    zend_type_list* property_sstBoard_type_list = pemalloc(ZEND_TYPE_LIST_SIZE(4), 1);

    property_sstBoard_type_list->num_types = 4;
    property_sstBoard_type_list->types[0] = (zend_type)ZEND_TYPE_INIT_CLASS(property_sstBoard_class_GrVoodooConfig_t, 0, 0);
    property_sstBoard_type_list->types[1] = (zend_type)ZEND_TYPE_INIT_CLASS(property_sstBoard_class_GrSst96Config_t, 0, 0);
    property_sstBoard_type_list->types[2] = (zend_type)ZEND_TYPE_INIT_CLASS(property_sstBoard_class_GrAT3DConfig_t, 0, 0);
    property_sstBoard_type_list->types[3] = (zend_type)ZEND_TYPE_INIT_CLASS(property_sstBoard_class_GrVoodoo2Config_t, 0, 0);
    
    zend_type property_sstBoard_type = ZEND_TYPE_INIT_UNION(property_sstBoard_type_list, 0);

    property_name = zend_string_init_interned("sstBoard", sizeof("sstBoard") - 1, 1);
    zend_declare_typed_property(
        sST_ce,
        property_name, 
        &val, 
        ZEND_ACC_PUBLIC, 
        NULL, 
        property_sstBoard_type
    );


    INIT_CLASS_ENTRY(ce, "GrHwConfiguration", no_methods);
    grHwConfiguration_ce = zend_register_internal_class_ex(&ce, NULL);
    grHwConfiguration_ce->ce_flags |= ZEND_ACC_FINAL;

    // Declare properties
    ZVAL_UNDEF(&val);
    property_name = zend_string_init_interned("num_sst", sizeof("num_sst") - 1, 1);
    zend_declare_typed_property(
        grHwConfiguration_ce,
        property_name,
        &val,
        ZEND_ACC_PUBLIC,
        NULL,
        (zend_type)ZEND_TYPE_INIT_MASK(MAY_BE_LONG)
    );

    ZVAL_UNDEF(&val);
    property_name = zend_string_init_interned("SSTs", sizeof("SSTs") - 1, 1);
    zend_declare_typed_property(
        grHwConfiguration_ce,
        property_name,
        &val,
        ZEND_ACC_PUBLIC,
        NULL,
        (zend_type)ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY)
    );




    INIT_CLASS_ENTRY(ce, "GrTmuVertex", no_methods);
    grTmuVertex_ce = zend_register_internal_class_ex(&ce, NULL);

    // Declare properties
    ZVAL_UNDEF(&val);
    property_name = zend_string_init_interned("sow", sizeof("sow") - 1, 1);
    zend_declare_typed_property(
        grTmuVertex_ce,
        property_name,          // name
        &val,                   // default value
        ZEND_ACC_PUBLIC,        // access scope
        NULL,
        (zend_type)ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE) // type
    );

    property_name = zend_string_init_interned("tow", sizeof("tow") - 1, 1);
    zend_declare_typed_property(
        grTmuVertex_ce,
        property_name,          // name
        &val,                   // default value
        ZEND_ACC_PUBLIC,        // access scope
        NULL,
        (zend_type)ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE) // type
    );

    property_name = zend_string_init_interned("oow", sizeof("oow") - 1, 1);
    zend_declare_typed_property(
        grTmuVertex_ce,
        property_name,          // name
        &val,                   // default value
        ZEND_ACC_PUBLIC,        // access scope
        NULL,
        (zend_type)ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE) // type
    );





    INIT_CLASS_ENTRY(ce, "GrVertex", no_methods);
    grVertex_ce = zend_register_internal_class_ex(&ce, NULL);

    // Declare properties
    ZVAL_UNDEF(&val);
    property_name = zend_string_init_interned("x", sizeof("x") - 1, 1);
    zend_declare_typed_property(
        grVertex_ce,
        property_name,          // name
        &val,                   // default value
        ZEND_ACC_PUBLIC,        // access scope
        NULL,
        (zend_type)ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE) // type
    );

    property_name = zend_string_init_interned("y", sizeof("y") - 1, 1);
    zend_declare_typed_property(
        grVertex_ce,
        property_name,          // name
        &val,                   // default value
        ZEND_ACC_PUBLIC,        // access scope
        NULL,
        (zend_type)ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE) // type
    );

    property_name = zend_string_init_interned("z", sizeof("z") - 1, 1);
    zend_declare_typed_property(
        grVertex_ce,
        property_name,          // name
        &val,                   // default value
        ZEND_ACC_PUBLIC,        // access scope
        NULL,
        (zend_type)ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE) // type
    );

    property_name = zend_string_init_interned("r", sizeof("r") - 1, 1);
    zend_declare_typed_property(
        grVertex_ce,
        property_name,          // name
        &val,                   // default value
        ZEND_ACC_PUBLIC,        // access scope
        NULL,
        (zend_type)ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE) // type
    );

    property_name = zend_string_init_interned("g", sizeof("g") - 1, 1);
    zend_declare_typed_property(
        grVertex_ce,
        property_name,          // name
        &val,                   // default value
        ZEND_ACC_PUBLIC,        // access scope
        NULL,
        (zend_type)ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE) // type
    );

    property_name = zend_string_init_interned("b", sizeof("b") - 1, 1);
    zend_declare_typed_property(
        grVertex_ce,
        property_name,          // name
        &val,                   // default value
        ZEND_ACC_PUBLIC,        // access scope
        NULL,
        (zend_type)ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE) // type
    );

    property_name = zend_string_init_interned("ooz", sizeof("ooz") - 1, 1);
    zend_declare_typed_property(
        grVertex_ce,
        property_name,          // name
        &val,                   // default value
        ZEND_ACC_PUBLIC,        // access scope
        NULL,
        (zend_type)ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE) // type
    );

    property_name = zend_string_init_interned("a", sizeof("a") - 1, 1);
    zend_declare_typed_property(
        grVertex_ce,
        property_name,          // name
        &val,                   // default value
        ZEND_ACC_PUBLIC,        // access scope
        NULL,
        (zend_type)ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE) // type
    );

    property_name = zend_string_init_interned("oow", sizeof("oow") - 1, 1);
    zend_declare_typed_property(
        grVertex_ce,
        property_name,          // name
        &val,                   // default value
        ZEND_ACC_PUBLIC,        // access scope
        NULL,
        (zend_type)ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE) // type
    );

    property_name = zend_string_init("tmuvtx", sizeof("tmuvtx") - 1, 1);
    zend_declare_typed_property(
        grVertex_ce,
        property_name, 
        &val, 
        ZEND_ACC_PUBLIC, 
        NULL, 
        (zend_type)ZEND_TYPE_INIT_MASK(MAY_BE_ARRAY)
    );
}