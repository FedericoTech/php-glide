#include "phpglide2x_structs.h"

zend_class_entry* grHwConfiguration_ce;

#ifdef _DEBUG
ZEND_FUNCTION(testGrHwConfiguration)
{
    zend_object* grHwConfiguration_zo = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJ_OF_CLASS(grHwConfiguration_zo, grHwConfiguration_ce)
        ZEND_PARSE_PARAMETERS_END();

    GrHwConfiguration grHwConfiguration;

    flush_GrHwConfiguration(grHwConfiguration_zo, &grHwConfiguration);

    php_printf("num_sst: %d\n", grHwConfiguration.num_sst);
    for (int cont = 0; cont < grHwConfiguration.num_sst; cont++) {

        php_printf("board n: %d, type: %d\n", cont, grHwConfiguration.SSTs[cont].type);

        switch (grHwConfiguration.SSTs[cont].type) {
        case GR_SSTTYPE_VOODOO:
        {
            php_printf(
                "board n: %d: [fbiRev: %d, fbRam: %d, nTexelfx: %d, sliDetect: %d, [0][tmuRev: %d, tmuRam: %d], [1][tmuRev: %d, tmuRam: %d]]\n\n", 
                cont, 

                grHwConfiguration.SSTs[cont].sstBoard.VoodooConfig.fbiRev,
                grHwConfiguration.SSTs[cont].sstBoard.VoodooConfig.fbRam,
                grHwConfiguration.SSTs[cont].sstBoard.VoodooConfig.nTexelfx,
                grHwConfiguration.SSTs[cont].sstBoard.VoodooConfig.sliDetect,

                grHwConfiguration.SSTs[cont].sstBoard.VoodooConfig.tmuConfig[0].tmuRev,
                grHwConfiguration.SSTs[cont].sstBoard.VoodooConfig.tmuConfig[0].tmuRam,

                grHwConfiguration.SSTs[cont].sstBoard.VoodooConfig.tmuConfig[1].tmuRev,
                grHwConfiguration.SSTs[cont].sstBoard.VoodooConfig.tmuConfig[1].tmuRam
            );
        }
        break;
        case GR_SSTTYPE_SST96:
        {
            php_printf(
                "board n: %d, [fbRam: %d, nTexelfx: %d, [tmuRev: %d, tmuRam: %d]]\n\n",
                cont,

                grHwConfiguration.SSTs[cont].sstBoard.SST96Config.fbRam,
                grHwConfiguration.SSTs[cont].sstBoard.SST96Config.nTexelfx,
                grHwConfiguration.SSTs[cont].sstBoard.SST96Config.tmuConfig.tmuRev,
                grHwConfiguration.SSTs[cont].sstBoard.SST96Config.tmuConfig.tmuRam
            );
        }
        break;
        case GR_SSTTYPE_AT3D:
        {
            php_printf(
                "board n: %d, [rev: %d]\n\n",
                cont,

                grHwConfiguration.SSTs[cont].sstBoard.AT3DConfig.rev
            );
        }
        break;
        case GR_SSTTYPE_Voodoo2:
        {
            php_printf(
                "board n: %d: [fbiRev: %d, fbRam: %d, nTexelfx: %d, sliDetect: %d, [0][tmuRev: %d, tmuRam: %d], [1][tmuRev: %d, tmuRam: %d]]\n\n",
                cont,

                grHwConfiguration.SSTs[cont].sstBoard.Voodoo2Config.fbiRev,
                grHwConfiguration.SSTs[cont].sstBoard.Voodoo2Config.fbRam,
                grHwConfiguration.SSTs[cont].sstBoard.Voodoo2Config.nTexelfx,
                grHwConfiguration.SSTs[cont].sstBoard.Voodoo2Config.sliDetect,

                grHwConfiguration.SSTs[cont].sstBoard.Voodoo2Config.tmuConfig[0].tmuRev,
                grHwConfiguration.SSTs[cont].sstBoard.Voodoo2Config.tmuConfig[0].tmuRam,

                grHwConfiguration.SSTs[cont].sstBoard.Voodoo2Config.tmuConfig[1].tmuRev,
                grHwConfiguration.SSTs[cont].sstBoard.Voodoo2Config.tmuConfig[1].tmuRam
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

    zend_string* bin = zend_string_alloc(sizeof(GrHwConfiguration) + 1, 0);

    flush_GrHwConfiguration(Z_OBJ_P(ZEND_THIS), (GrHwConfiguration*)ZSTR_VAL(bin));

    ZSTR_VAL(bin)[sizeof(GrHwConfiguration) + 1] = '\0'; // null terminator (optional for binary)

    RETURN_STR(bin);
}

void flush_GrHwConfiguration(const _GrHwConfiguration* obj, GrHwConfiguration* buffer)
{
    zval* value = zend_read_property(
        grHwConfiguration_ce,            // zend_class_entry* of the object
        (zend_object*)obj,           // zval* or zend_object* (see below)
        "num_sst",   // property name
        sizeof("num_sst") - 1,
        1,             // silent (1 = don't emit notice if not found)
        NULL           // Optional return zval ptr, or NULL
    );

    buffer->num_sst = Z_TYPE_P(value) == IS_NULL ? 0 : Z_LVAL_P(value);

    value = zend_read_property(
        grHwConfiguration_ce,            // zend_class_entry* of the object
        (zend_object*)obj,           // zval* or zend_object* (see below)
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
                flush_SST((_SST_t *)Z_OBJ_P(val), (SST_t*)&buffer->SSTs[cont++]);
            }
            else {
                memset(&buffer->SSTs[cont++], 0, sizeof(SST_t));
            }

        } ZEND_HASH_FOREACH_END();
    }
}

void hydrate_GrHwConfiguration(const GrHwConfiguration* buffer, _GrHwConfiguration* obj)
{
    zend_update_property_long(
        grHwConfiguration_ce, obj,
        "num_sst", sizeof("num_sst") - 1,
        buffer->num_sst
    );
        
    zval sSTs_arr_zval;
    array_init_size(&sSTs_arr_zval, buffer->num_sst);
        
    for (int cont = 0; cont < buffer->num_sst; cont++) {

        zval sst_obj;

        //we instantiate the SST_t class
        object_init_ex(&sst_obj, sST_ce);

        hydrate_SST((SST_t*) &buffer->SSTs[cont], (_SST_t *)Z_OBJ(sst_obj));
        
        add_next_index_zval(&sSTs_arr_zval, &sst_obj);
    }

    zend_update_property(
        grHwConfiguration_ce, obj,
        "SSTs", sizeof("SSTs") - 1,
        &sSTs_arr_zval
    );

    zval_ptr_dtor(&sSTs_arr_zval);  //destroy the local pointer
}