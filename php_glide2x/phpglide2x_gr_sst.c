#include "phpglide2x_structs.h"
#include "phpglide2x_enums.h"

zend_class_entry* sST_ce;

#ifdef _DEBUG
ZEND_FUNCTION(testSST_t)
{
    zend_object* sST_zo = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(sST_zo, sST_ce)
        ZEND_PARSE_PARAMETERS_END();

    _SST_t* config = O_EMBEDDED_P(_SST_t, sST_zo);

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

PHP_METHOD(SST_t, flush)
{
    ZEND_PARSE_PARAMETERS_NONE();

    _SST_t* obj = O_EMBEDDED_P(_SST_t, Z_OBJ_P(ZEND_THIS));

    flush_SST(obj, &obj->SST);

    zend_string* bin = zend_string_alloc(sizeof(_SST_t) + 1, 0);

    memcpy(
        ZSTR_VAL(bin),
        &obj->SST,
        sizeof(_SST_t) + 1
    );

    ZSTR_VAL(bin)[sizeof(_SST_t) + 1] = '\0'; // null terminator (optional for binary)

    RETURN_STR(bin);
}

static zend_object_handlers grSST_object_handlers;

//function that allocates memory for the object and sets the handlers
zend_object* SST_new(zend_class_entry* ce)
{
    //it allocates memory
    _SST_t* sST = zend_object_alloc(sizeof(_SST_t), ce);

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
    if (object->ce == sST_ce) {
        _SST_t* sst = O_EMBEDDED_P(_SST_t, object);

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
    zend_object* new_obj = SST_new(object->ce);

    _SST_t* clone = O_EMBEDDED_P(_SST_t, new_obj);
    _SST_t* orig = O_EMBEDDED_P(_SST_t, object);

    memcpy(&clone->SST, &orig->SST, sizeof orig->SST);

    zend_objects_clone_members(&clone->std, &orig->std);

    return new_obj;
}

void phpglide2x_register_grSST(INIT_FUNC_ARGS)
{
    sST_ce = register_class_SST_t(gr_flushable_ce);
    sST_ce->create_object = SST_new; //asign an internal constructor

    memcpy(
        &grSST_object_handlers,	// our handler 
        &std_object_handlers,				        // the standard handler
        sizeof(zend_object_handlers)		        // size of the standar handler
    );

    //we set the address of the beginning of the whole embedded data
    grSST_object_handlers.offset = XtOffsetOf(_SST_t, std);
    //grSST_object_handlers.write_property = gr_write_property;
    grSST_object_handlers.clone_obj = gr_clone_obj;
}

void flush_SST(const _SST_t* sST, SST_t* buffer)
{
    zval* value = zend_read_property(
        sST->std.ce,      // zend_class_entry* of the object
        (zend_object*)&sST->std,        // zval* or zend_object* (see below)
        "type",             // property name
        sizeof("type") - 1,
        1,                  // silent (1 = don't emit notice if not found)
        NULL                // Optional return zval ptr, or NULL
    );

    buffer->type = Z_TYPE_P(value) == IS_NULL ? 0 : enum_to_int(Z_OBJ_P(value));

    value = zend_read_property(
        sST->std.ce,      // zend_class_entry* of the object
        (zend_object*)&sST->std,        // zval* or zend_object* (see below)
        "sstBoard",             // property name
        sizeof("sstBoard") - 1,
        1,                  // silent (1 = don't emit notice if not found)
        NULL                // Optional return zval ptr, or NULL
    );

    if (Z_TYPE_P(value) == IS_NULL) {
        memset(&buffer->sstBoard, 0, sizeof(SST_t));
    }
    else {
        switch (buffer->type) {
        case GR_SSTTYPE_VOODOO:
            flush_grVoodooConfig(O_EMBEDDED_P(_GrVoodooConfig_t, Z_OBJ_P(value)), &buffer->sstBoard.VoodooConfig);
            break;
        case GR_SSTTYPE_SST96:
            flush_GrSst96Config(O_EMBEDDED_P(_GrSst96Config_t, Z_OBJ_P(value)), &buffer->sstBoard.SST96Config);
            break;
        case GR_SSTTYPE_AT3D:
            flush_GrAT3DConfig(O_EMBEDDED_P(_GrAT3DConfig_t, Z_OBJ_P(value)), &buffer->sstBoard.AT3DConfig);
            break;
        case GR_SSTTYPE_Voodoo2:
            flush_grVoodoo2Config(O_EMBEDDED_P(_GrVoodoo2Config_t, Z_OBJ_P(value)), &buffer->sstBoard.Voodoo2Config);
            break;
        }
    }
}

void hydrate_SST(const SST_t* sSTs, _SST_t* _sST)
{
    zval sst_board, val_zv;
    zend_object* enum_case = NULL, * sst_board_zo = NULL;

    switch (sSTs->type)
    {
    case GR_SSTTYPE_VOODOO:

        enum_case = zend_enum_get_case_cstr(grSstType_ce, "GR_SSTTYPE_VOODOO");

        object_init_ex(&sst_board, grVoodooConfig_ce);

        hydrate_grVoodooConfig(&sSTs->sstBoard.VoodooConfig, O_EMBEDDED_P(_GrVoodooConfig_t, &Z_OBJ(sst_board)));

        break;
    default: //Banshee, and others. not garanteed it will work
    case GR_SSTTYPE_Voodoo2:
        enum_case = zend_enum_get_case_cstr(grSstType_ce, "GR_SSTTYPE_Voodoo2");

        object_init_ex(&sst_board, grVoodoo2Config_ce);

        hydrate_grVoodoo2Config(&sSTs->sstBoard.Voodoo2Config, O_EMBEDDED_P(_GrVoodoo2Config_t, &Z_OBJ(sst_board)));

        break;
    case GR_SSTTYPE_SST96:
        enum_case = zend_enum_get_case_cstr(grSstType_ce, "GR_SSTTYPE_SST96");

        object_init_ex(&sst_board, grSst96Config_ce);

        hydrate_GrSst96Config(&sSTs->sstBoard.SST96Config, O_EMBEDDED_P(_GrSst96Config_t, &Z_OBJ(sst_board)));

        break;
    case GR_SSTTYPE_AT3D:
        enum_case = zend_enum_get_case_cstr(grSstType_ce, "GR_SSTTYPE_AT3D");

        object_init_ex(&sst_board, grAT3DConfig_ce);

        hydrate_GrAT3DConfig(&sSTs->sstBoard.AT3DConfig, O_EMBEDDED_P(_GrAT3DConfig_t, &Z_OBJ(sst_board)));

        break;
    }


    ZVAL_OBJ(&val_zv, enum_case);
    zend_update_property(
        sST_ce, &_sST->std,
        "type", sizeof("type") - 1,
        &val_zv
    );

    zend_update_property(
        sST_ce, &_sST->std,
        "sstBoard", sizeof("sstBoard") - 1,
        &sst_board
    );
    zval_ptr_dtor(&sst_board); //destroy the local pointer


    

    //zval_ptr_dtor(&sst_obj);  //destroy the local pointer I'M WORKING HERE !!!!
}