#include "phpglide2x_structs.h"
#include "phpglide2x_enums.h"

zend_class_entry* grSST_ce;

#ifdef _DEBUG
ZEND_FUNCTION(testSST_t)
{
    zend_object* grSST_zo = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(grSST_zo, grSST_ce)
        ZEND_PARSE_PARAMETERS_END();

    _GrSST* config = O_EMBEDDED_P(_GrSST, grSST_zo);

    switch (config->SST.type) {
    case GR_SSTTYPE_VOODOO:

        php_printf(
            "type: %d, sstBoard: [fbiRev: %d, fbRam: %d, nTexelfx: %d, sliDetect: %d, tmuConfig: [[tmuRev: %d, tmuRam: %d], [tmuRev: %d, tmuRam: %d]]\n",
            config->SST.type,

            config->SST.sstBoard.VoodooConfig.fbiRev,
            config->SST.sstBoard.VoodooConfig.fbRam,
            config->SST.sstBoard.VoodooConfig.nTexelfx,
            config->SST.sstBoard.VoodooConfig.sliDetect,

            config->SST.sstBoard.VoodooConfig.tmuConfig[0].tmuRev,
            config->SST.sstBoard.VoodooConfig.tmuConfig[0].tmuRam,

            config->SST.sstBoard.VoodooConfig.tmuConfig[1].tmuRev,
            config->SST.sstBoard.VoodooConfig.tmuConfig[1].tmuRam
        );

        break;
    case GR_SSTTYPE_SST96:

        php_printf(
            "type: %d, sstBoard: [fbRam: %d, nTexelfx: %d, tmuConfig: [tmuRev: %d, tmuRam: %d]]\n",
            config->SST.type,

            config->SST.sstBoard.SST96Config.fbRam,
            config->SST.sstBoard.SST96Config.nTexelfx,
            config->SST.sstBoard.SST96Config.tmuConfig.tmuRev,
            config->SST.sstBoard.SST96Config.tmuConfig.tmuRev
        );

        break;
    case GR_SSTTYPE_AT3D:

        php_printf(
            "type: %d, sstBoard: [rev: %d]\n",
            config->SST.type,

            config->SST.sstBoard.AT3DConfig.rev
        );

        break;
    case GR_SSTTYPE_Voodoo2:

        php_printf(
            "type: %d, sstBoard: [fbiRev: %d, fbRam: %d, nTexelfx: %d, sliDetect: %d, tmuConfig: [[tmuRev: %d, tmuRam: %d], [tmuRev: %d, tmuRam: %d]]\n",
            config->SST.type,

            config->SST.sstBoard.Voodoo2Config.fbiRev,
            config->SST.sstBoard.Voodoo2Config.fbRam,
            config->SST.sstBoard.Voodoo2Config.nTexelfx,
            config->SST.sstBoard.Voodoo2Config.sliDetect,

            config->SST.sstBoard.Voodoo2Config.tmuConfig[0].tmuRev,
            config->SST.sstBoard.Voodoo2Config.tmuConfig[0].tmuRam,

            config->SST.sstBoard.Voodoo2Config.tmuConfig[1].tmuRev,
            config->SST.sstBoard.Voodoo2Config.tmuConfig[1].tmuRam
        );

        break;
    }

    
}
#endif // _DEBUG

static zend_object_handlers grSST_object_handlers;

//function that allocates memory for the object and sets the handlers
zend_object* GrSST_new(zend_class_entry* ce)
{
    //it allocates memory
    _GrSST* sST = zend_object_alloc(sizeof(_GrSST), ce);

    //it initializes the object
    zend_object_std_init(&sST->std, ce);

    object_properties_init(&sST->std, ce);

    //it sets the handlers
    sST->std.handlers = &grSST_object_handlers;

    //it returns the zend object
    return &sST->std;
}


static zval* gr_write_property(zend_object* object, zend_string* member, zval* value, void** cache_slot)
{
    if (object->ce == grSST_ce) {
        _GrSST* sst = O_EMBEDDED_P(_GrSST, object);

        if (zend_string_equals_literal(member, "type")) {

            sst->SST.type = enum_to_int(Z_OBJ_P(value));
        }else if (zend_string_equals_literal(member, "sstBoard")) {

            switch(sst->SST.type){
            case GR_SSTTYPE_VOODOO:
            {
                _GrVoodooConfig_t* config = O_EMBEDDED_P(_GrVoodooConfig_t, Z_OBJ_P(value));

                memcpy(
                    &sst->SST.sstBoard,
                    &config->grVoodooConfig,
                    sizeof(GrVoodooConfig_t)
                );
            }
                break;
            case GR_SSTTYPE_SST96:
            {
                _GrSst96Config_t* config = O_EMBEDDED_P(_GrSst96Config_t, Z_OBJ_P(value));

                memcpy(
                    &sst->SST.sstBoard,
                    &config->grSst96Config,
                    sizeof(GrSst96Config_t)
                );
            }
                break;
            case GR_SSTTYPE_AT3D:
            {
                _GrAT3DConfig_t* config = O_EMBEDDED_P(_GrAT3DConfig_t, Z_OBJ_P(value));

                memcpy(
                    &sst->SST.sstBoard,
                    &config->grAT3DConfig,
                    sizeof(GrAT3DConfig_t)
                );
            }
                break;
            case GR_SSTTYPE_Voodoo2:
            {
                _GrVoodoo2Config_t* config = O_EMBEDDED_P(_GrVoodoo2Config_t, Z_OBJ_P(value));

                memcpy(
                    &sst->SST.sstBoard,
                    &config->grVoodoo2Config,
                    sizeof(GrVoodoo2Config_t)
                );
            }
                break; 
            }
        } //if sstBoard
    }
    
    return zend_std_write_property(object, member, value, cache_slot);
}

static zend_object* gr_clone_obj(zend_object* object)
{
    // Step 1: Call the default clone handler
    zend_object* new_obj = GrSST_new(object->ce);

    _GrSST* clone = O_EMBEDDED_P(_GrSST, new_obj);
    _GrSST* orig = O_EMBEDDED_P(_GrSST, object);

    memcpy(&clone->SST, &orig->SST, sizeof orig->SST);

    zend_objects_clone_members(&clone->std, &orig->std);

    return new_obj;
}

void phpglide2x_register_grSST(INIT_FUNC_ARGS)
{
    grSST_ce = register_class_SST_t();
    grSST_ce->create_object = GrSST_new; //asign an internal constructor

    memcpy(
        &grSST_object_handlers,	// our handler 
        &std_object_handlers,				        // the standard handler
        sizeof(zend_object_handlers)		        // size of the standar handler
    );

    //we set the address of the beginning of the whole embedded data
    grSST_object_handlers.offset = XtOffsetOf(_GrSST, std);
    grSST_object_handlers.write_property = gr_write_property;
    grSST_object_handlers.clone_obj = gr_clone_obj;
}