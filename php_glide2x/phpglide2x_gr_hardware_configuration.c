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

static zval* gr_write_property(zend_object* object, zend_string* member, zval* value, void** cache_slot)
{
    if (zend_string_equals_literal(object->ce->name, "GrHwConfiguration")) {

        _GrHwConfiguration* config = O_EMBEDDED_P(_GrHwConfiguration, object);  // Get your embedded struct from the object

        if (zend_string_equals_literal(member, "num_sst")) {
            config->grHwConfiguration.num_sst = Z_LVAL_P(value);
        } else if (zend_string_equals_literal(member, "SSTs")) {

            zval* entry = NULL;
            zend_string* key = NULL;

            for (int cont = 0; cont < min(MAX_NUM_SST, zend_hash_num_elements(Z_ARRVAL_P(value))); cont++) {

                if ((entry = zend_hash_index_find(Z_ARRVAL_P(value), cont)) != NULL) {

                    _GrSST* grSST = O_EMBEDDED_P(_GrSST, Z_OBJ_P(entry));

                    memcpy(
                        &config->grHwConfiguration.SSTs[cont],
                        &grSST->SST,
                        (size_t) & (((_GrSST*)0)->std) - (size_t) & (((_GrSST*)0)->SST)
                    );
                }
            } // for
        }
    }

    return zend_std_write_property(object, member, value, cache_slot);
}

static zend_object* gr_clone_obj(zend_object* object)
{
    // Step 1: Call the default clone handler
    zend_object* new_obj = GrHwConfiguration_new(object->ce);


    _GrHwConfiguration* clone = O_EMBEDDED_P(_GrHwConfiguration, new_obj);
    _GrHwConfiguration* orig = O_EMBEDDED_P(_GrHwConfiguration, object);

    memcpy(&clone->grHwConfiguration, &orig->grHwConfiguration, sizeof(GrHwConfiguration));

    return new_obj;
}

void phpglide2x_register_grHwConfiguration(INIT_FUNC_ARGS)
{
    grHwConfiguration_ce = register_class_GrHwConfiguration();
    grHwConfiguration_ce->create_object = GrHwConfiguration_new; //asign an internal constructor

    memcpy(
        &grHwConfiguration_object_handlers,	// our handler 
        &std_object_handlers,				        // the standard handler
        sizeof(zend_object_handlers)		        // size of the standar handler
    );

    //we set the address of the beginning of the whole embedded data
    grHwConfiguration_object_handlers.offset = XtOffsetOf(_GrHwConfiguration, std);
    grHwConfiguration_object_handlers.write_property = gr_write_property;
    grHwConfiguration_object_handlers.clone_obj = gr_clone_obj;
}