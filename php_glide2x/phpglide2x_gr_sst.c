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

    SST_t buffer;

    memset(&buffer, 0xff, sizeof buffer);

    SST_flush(sST_zo, &buffer);

    php_printf("type: %d,", buffer.type);

    switch (buffer.type) {
    case GR_SSTTYPE_VOODOO:

        php_printf(
            " sstBoard: [fbiRev: %d, fbRam: %d, nTexelfx: %d, sliDetect: %d, tmuConfig: [[tmuRev: %d, tmuRam: %d], [tmuRev: %d, tmuRam: %d]]\n",

            buffer.sstBoard.VoodooConfig.fbiRev,
            buffer.sstBoard.VoodooConfig.fbRam,
            buffer.sstBoard.VoodooConfig.nTexelfx,
            buffer.sstBoard.VoodooConfig.sliDetect,

            buffer.sstBoard.VoodooConfig.tmuConfig[0].tmuRev,
            buffer.sstBoard.VoodooConfig.tmuConfig[0].tmuRam,

            buffer.sstBoard.VoodooConfig.tmuConfig[1].tmuRev,
            buffer.sstBoard.VoodooConfig.tmuConfig[1].tmuRam
        );

        break;
    case GR_SSTTYPE_SST96:

        php_printf(
            " sstBoard: [fbRam: %d, nTexelfx: %d, tmuConfig: [tmuRev: %d, tmuRam: %d]]\n",

            buffer.sstBoard.SST96Config.fbRam,
            buffer.sstBoard.SST96Config.nTexelfx,
            buffer.sstBoard.SST96Config.tmuConfig.tmuRev,
            buffer.sstBoard.SST96Config.tmuConfig.tmuRev
        );

        break;
    case GR_SSTTYPE_AT3D:

        php_printf(
            " sstBoard: [rev: %d]\n",

            buffer.sstBoard.AT3DConfig.rev
        );

        break;
    case GR_SSTTYPE_Voodoo2:

        php_printf(
            " sstBoard: [fbiRev: %d, fbRam: %d, nTexelfx: %d, sliDetect: %d, tmuConfig: [[tmuRev: %d, tmuRam: %d], [tmuRev: %d, tmuRam: %d]]\n",

            buffer.sstBoard.Voodoo2Config.fbiRev,
            buffer.sstBoard.Voodoo2Config.fbRam,
            buffer.sstBoard.Voodoo2Config.nTexelfx,
            buffer.sstBoard.Voodoo2Config.sliDetect,

            buffer.sstBoard.Voodoo2Config.tmuConfig[0].tmuRev,
            buffer.sstBoard.Voodoo2Config.tmuConfig[0].tmuRam,

            buffer.sstBoard.Voodoo2Config.tmuConfig[1].tmuRev,
            buffer.sstBoard.Voodoo2Config.tmuConfig[1].tmuRam
        );

        break;
    }
}
#endif // _DEBUG

PHP_METHOD(SST_t, flush)
{
    ZEND_PARSE_PARAMETERS_NONE();

    zend_string* bin = zend_string_alloc(sizeof(SST_t), 0);
    
    SST_flush(Z_OBJ_P(ZEND_THIS), (SST_t*)ZSTR_VAL(bin));
    
    ZSTR_VAL(bin)[sizeof(SST_t)] = '\0'; // null terminator (optional for binary)
    
    RETURN_STR(bin);
}

void SST_flush(const _SST_t* self, SST_t* buffer)
{
    zval* value = zend_read_property(
        sST_ce,             // zend_class_entry* of the object
        (zend_object*)self,  // zval* or zend_object* (see below)
        "type",             // property name
        sizeof("type") - 1,
        1,                  // silent (1 = don't emit notice if not found)
        NULL                // Optional return zval ptr, or NULL
    );

    if (Z_TYPE_P(value) != IS_NULL) { buffer->type = enum_to_int(Z_OBJ_P(value)); }

    value = zend_read_property(
        sST_ce,             // zend_class_entry* of the object
        (zend_object*)self,  // zval* or zend_object* (see below)
        "sstBoard",         // property name
        sizeof("sstBoard") - 1,
        1,                  // silent (1 = don't emit notice if not found)
        NULL                // Optional return zval ptr, or NULL
    );

    if (Z_TYPE_P(value) == IS_NULL) {
        //memset(&buffer->sstBoard, 0, sizeof(SST_t));
    }
    else {
        switch (buffer->type) {
        case GR_SSTTYPE_VOODOO:
            GrVoodooConfig_flush((_GrVoodooConfig_t *) Z_OBJ_P(value), &buffer->sstBoard.VoodooConfig);
            break;
        case GR_SSTTYPE_SST96:
            GrSst96Config_flush((_GrSst96Config_t *) Z_OBJ_P(value), &buffer->sstBoard.SST96Config);
            break;
        case GR_SSTTYPE_AT3D:
            GrAT3DConfig_flush((_GrAT3DConfig_t*) Z_OBJ_P(value), &buffer->sstBoard.AT3DConfig);
            break;
        case GR_SSTTYPE_Voodoo2:
            GrVoodoo2Config_flush((_GrVoodoo2Config_t *) Z_OBJ_P(value), &buffer->sstBoard.Voodoo2Config);
            break;
        }
    }
}

void SST_hydrate(_SST_t* self, const SST_t* buffer)
{
    zval sst_board, val_zv;
    zend_object* enum_case = NULL, * sst_board_zo = NULL;
        
    switch (buffer->type)
    {
    case GR_SSTTYPE_VOODOO:

        enum_case = zend_enum_get_case_cstr(grSstType_ce, "GR_SSTTYPE_VOODOO");

        object_init_ex(&sst_board, grVoodooConfig_ce);
        
        GrVoodooConfig_hydrate((_GrVoodooConfig_t*)Z_OBJ_P(&sst_board), &buffer->sstBoard.VoodooConfig);
        break;
    
    case GR_SSTTYPE_Voodoo2:
        enum_case = zend_enum_get_case_cstr(grSstType_ce, "GR_SSTTYPE_Voodoo2");

        object_init_ex(&sst_board, grVoodoo2Config_ce);

        GrVoodoo2Config_hydrate((_GrVoodoo2Config_t*)Z_OBJ_P(&sst_board), &buffer->sstBoard.Voodoo2Config);
        break;
    case GR_SSTTYPE_SST96:
        enum_case = zend_enum_get_case_cstr(grSstType_ce, "GR_SSTTYPE_SST96");

        object_init_ex(&sst_board, grSst96Config_ce);

        GrSst96Config_hydrate((_GrSst96Config_t*)Z_OBJ_P(&sst_board), &buffer->sstBoard.SST96Config);
        break;
    case GR_SSTTYPE_AT3D:
        enum_case = zend_enum_get_case_cstr(grSstType_ce, "GR_SSTTYPE_AT3D");

        object_init_ex(&sst_board, grAT3DConfig_ce);

        GrAT3DConfig_hydrate((_GrAT3DConfig_t*)Z_OBJ_P(&sst_board) , &buffer->sstBoard.AT3DConfig);
        break;
    case 4: //Banshee, and others. not garanteed it will work
        enum_case = zend_enum_get_case_cstr(grSstType_ce, "GR_SSTTYPE_Banshe");
        ZVAL_NULL(&sst_board);
        break;
    default: 
        enum_case = zend_enum_get_case_cstr(grSstType_ce, "GR_SSTTYPE_Unknown");
        ZVAL_NULL(&sst_board);
        break;
    }
     
    ZVAL_OBJ(&val_zv, enum_case);
    zend_update_property(
        sST_ce, self,
        "type", sizeof("type") - 1,
        &val_zv
    );

    zend_update_property(
        sST_ce, self,
        "sstBoard", sizeof("sstBoard") - 1,
        &sst_board
    );
    zval_ptr_dtor(&sst_board); //destroy the local pointer
       

    //zval_ptr_dtor(&sst_obj);  //destroy the local pointer I'M WORKING HERE !!!!
}