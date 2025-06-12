#include "phpglide2x_structs.h"

zend_class_entry* grHwConfiguration_ce;

#ifdef _DEBUG
ZEND_FUNCTION(testGrHwConfiguration)
{
    zend_object* grHwConfiguration_zo = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(grHwConfiguration_zo, grHwConfiguration_ce)
        ZEND_PARSE_PARAMETERS_END();

    _GrHwConfiguration* config = O_EMBEDDED_P(_GrHwConfiguration, grHwConfiguration_zo);

    php_printf("num_sst: %d\n", config->grHwConfiguration.num_sst);
    for (int cont = 0; cont < config->grHwConfiguration.num_sst; cont++) {

        php_printf("board n: %d, type: %d\n", cont, config->grHwConfiguration.SSTs[cont].type);

        switch (config->grHwConfiguration.SSTs[cont].type) {
        case GR_SSTTYPE_VOODOO:
        {
            php_printf(
                "board n: %d: [fbiRev: %d, fbRam: %d, nTexelfx: %d, sliDetect: %d, [0][tmuRev: %d, tmuRam: %d], [1][tmuRev: %d, tmuRam: %d]]\n\n", 
                cont, 

                config->grHwConfiguration.SSTs[cont].sstBoard.VoodooConfig.fbiRev,
                config->grHwConfiguration.SSTs[cont].sstBoard.VoodooConfig.fbRam,
                config->grHwConfiguration.SSTs[cont].sstBoard.VoodooConfig.nTexelfx,
                config->grHwConfiguration.SSTs[cont].sstBoard.VoodooConfig.sliDetect,

                config->grHwConfiguration.SSTs[cont].sstBoard.VoodooConfig.tmuConfig[0].tmuRev,
                config->grHwConfiguration.SSTs[cont].sstBoard.VoodooConfig.tmuConfig[0].tmuRam,

                config->grHwConfiguration.SSTs[cont].sstBoard.VoodooConfig.tmuConfig[1].tmuRev,
                config->grHwConfiguration.SSTs[cont].sstBoard.VoodooConfig.tmuConfig[1].tmuRam
            );
        }
        break;
        case GR_SSTTYPE_SST96:
        {
            php_printf(
                "board n: %d, [fbRam: %d, nTexelfx: %d, [tmuRev: %d, tmuRam: %d]]\n\n",
                cont,

                config->grHwConfiguration.SSTs[cont].sstBoard.SST96Config.fbRam,
                config->grHwConfiguration.SSTs[cont].sstBoard.SST96Config.nTexelfx,
                config->grHwConfiguration.SSTs[cont].sstBoard.SST96Config.tmuConfig.tmuRev,
                config->grHwConfiguration.SSTs[cont].sstBoard.SST96Config.tmuConfig.tmuRam
            );
        }
        break;
        case GR_SSTTYPE_AT3D:
        {
            php_printf(
                "board n: %d, [rev: %d]\n\n",
                cont,

                config->grHwConfiguration.SSTs[cont].sstBoard.AT3DConfig.rev
            );
        }
        break;
        case GR_SSTTYPE_Voodoo2:
        {
            php_printf(
                "board n: %d: [fbiRev: %d, fbRam: %d, nTexelfx: %d, sliDetect: %d, [0][tmuRev: %d, tmuRam: %d], [1][tmuRev: %d, tmuRam: %d]]\n\n",
                cont,

                config->grHwConfiguration.SSTs[cont].sstBoard.Voodoo2Config.fbiRev,
                config->grHwConfiguration.SSTs[cont].sstBoard.Voodoo2Config.fbRam,
                config->grHwConfiguration.SSTs[cont].sstBoard.Voodoo2Config.nTexelfx,
                config->grHwConfiguration.SSTs[cont].sstBoard.Voodoo2Config.sliDetect,

                config->grHwConfiguration.SSTs[cont].sstBoard.Voodoo2Config.tmuConfig[0].tmuRev,
                config->grHwConfiguration.SSTs[cont].sstBoard.Voodoo2Config.tmuConfig[0].tmuRam,

                config->grHwConfiguration.SSTs[cont].sstBoard.Voodoo2Config.tmuConfig[1].tmuRev,
                config->grHwConfiguration.SSTs[cont].sstBoard.Voodoo2Config.tmuConfig[1].tmuRam
            );
        }
        break;
        }

    }
}
#endif // _DEBUG

PHP_METHOD(GrHwConfiguration, flush)
{
    ZEND_PARSE_PARAMETERS_NONE();

    _GrHwConfiguration* obj = O_EMBEDDED_P(_GrHwConfiguration, Z_OBJ_P(ZEND_THIS));

    flush_GrHwConfiguration(obj, &obj->grHwConfiguration);

    zend_string* bin = zend_string_alloc(sizeof(GrHwConfiguration) + 1, 0);

    memcpy(
        ZSTR_VAL(bin),
        &obj->grHwConfiguration,
        sizeof(GrHwConfiguration) + 1
    );

    ZSTR_VAL(bin)[sizeof(GrHwConfiguration) + 1] = '\0'; // null terminator (optional for binary)

    RETURN_STR(bin);
}

static zend_object_handlers grHwConfiguration_object_handlers;

//function that allocates memory for the object and sets the handlers
zend_object* GrHwConfiguration_new(zend_class_entry* ce)
{
    //it allocates memory
    _GrHwConfiguration* grHwConfiguration = zend_object_alloc(sizeof(_GrHwConfiguration), ce);

    //it initializes the object
    zend_object_std_init(&grHwConfiguration->std, ce);
    object_properties_init(&grHwConfiguration->std, ce);

    //it sets the handlers
    grHwConfiguration->std.handlers = &grHwConfiguration_object_handlers;

    //it returns the zend object
    return &grHwConfiguration->std;
}

static zend_object* gr_clone_obj(zend_object* object)
{
    // Step 1: Call the default clone handler
    zend_object* new_obj = GrHwConfiguration_new(object->ce);


    _GrHwConfiguration* clone = O_EMBEDDED_P(_GrHwConfiguration, new_obj);
    _GrHwConfiguration* orig = O_EMBEDDED_P(_GrHwConfiguration, object);

    memcpy(&clone->grHwConfiguration, &orig->grHwConfiguration, sizeof(GrHwConfiguration));

    zend_objects_clone_members(&clone->std, &orig->std);

    return new_obj;
}

void phpglide2x_register_grHwConfiguration(INIT_FUNC_ARGS)
{
    grHwConfiguration_ce = register_class_GrHwConfiguration(gr_flushable_ce);
    grHwConfiguration_ce->create_object = GrHwConfiguration_new; //asign an internal constructor

    memcpy(
        &grHwConfiguration_object_handlers,	// our handler 
        &std_object_handlers,				        // the standard handler
        sizeof(zend_object_handlers)		        // size of the standar handler
    );

    //we set the address of the beginning of the whole embedded data
    grHwConfiguration_object_handlers.offset = XtOffsetOf(_GrHwConfiguration, std);
    grHwConfiguration_object_handlers.clone_obj = gr_clone_obj;
}

void flush_GrHwConfiguration(const _GrHwConfiguration* grHwConfiguration, GrHwConfiguration* buffer)
{
    zval* value = zend_read_property(
        grHwConfiguration->std.ce,            // zend_class_entry* of the object
        (zend_object*)&grHwConfiguration->std,           // zval* or zend_object* (see below)
        "num_sst",   // property name
        sizeof("num_sst") - 1,
        1,             // silent (1 = don't emit notice if not found)
        NULL           // Optional return zval ptr, or NULL
    );

    buffer->num_sst = Z_TYPE_P(value) == IS_NULL ? 0 : Z_LVAL_P(value);

    value = zend_read_property(
        grHwConfiguration->std.ce,            // zend_class_entry* of the object
        (zend_object*)&grHwConfiguration->std,           // zval* or zend_object* (see below)
        "SSTs",   // property name
        sizeof("SSTs") - 1,
        1,             // silent (1 = don't emit notice if not found)
        NULL           // Optional return zval ptr, or NULL
    );

    //the array is not initialized...
    if (Z_TYPE_P(value) == IS_NULL) {
        memset(&buffer->SSTs, 0, sizeof(SST_t) * 2);
    }
    else {
        zval* val;
        HashTable* ht = Z_ARRVAL_P(value); // array_zval is a zval* pointing to the PHP array
        int cont = 0;
        ZEND_HASH_FOREACH_VAL(ht, val) {
            if (cont >= GLIDE_NUM_TMU) {
                break;
            }

            if (Z_TYPE_P(val) == IS_OBJECT && instanceof_function(Z_OBJCE_P(val), sST_ce)) {

                _SST_t* sST = O_EMBEDDED_P(_SST_t, Z_OBJ_P(val));

                flush_SST(sST, (SST_t*) &buffer->SSTs[cont++]);
            }
            else {
                memset(&buffer->SSTs[cont++], 0, sizeof(SST_t));
            }

        } ZEND_HASH_FOREACH_END();
    }
}

void hydrate_GrHwConfiguration(const GrHwConfiguration* buffer, _GrHwConfiguration* grHwConfiguration_obj)
{
    zend_update_property_long(
        grHwConfiguration_ce, &grHwConfiguration_obj->std,
        "num_sst", sizeof("num_sst") - 1,
        buffer->num_sst
    );
        
    zval sSTs_arr_zval;
    array_init_size(&sSTs_arr_zval, buffer->num_sst);
        
    for (int cont = 0; cont < buffer->num_sst; cont++) {

        zval sst_obj;

        //we instantiate the SST_t class
        object_init_ex(&sst_obj, sST_ce);

        hydrate_SST((const SST_t*) &buffer->SSTs[cont], O_EMBEDDED_P(_SST_t, Z_OBJ(sst_obj)));
        
        add_next_index_zval(&sSTs_arr_zval, &sst_obj);
    }

    zend_update_property(
        grHwConfiguration_ce, &grHwConfiguration_obj->std,
        "SSTs", sizeof("SSTs") - 1,
        &sSTs_arr_zval
    );

    zval_ptr_dtor(&sSTs_arr_zval);  //destroy the local pointer
}