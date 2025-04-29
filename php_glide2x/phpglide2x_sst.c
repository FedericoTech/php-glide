#include "phpglide2x_sst.h"
#include "phpglide2x_enums.h"
#include "phpglide2x_structs.h"

PHP_FUNCTION(grSstQueryHardware) {

	zend_object* grHwConfiguration_obj = NULL;
	FxBool result;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(grHwConfiguration_obj, grHwConfiguration_ce)
	ZEND_PARSE_PARAMETERS_END();

	GrHwConfiguration ghcf;

	result = grSstQueryHardware(&ghcf);

	zend_update_property_long(
		grHwConfiguration_ce, grHwConfiguration_obj,
		"num_sst", sizeof("num_sst") - 1, 
		ghcf.num_sst
	);

	zval sSTs_arr_zval;
	array_init_size(&sSTs_arr_zval, ghcf.num_sst);
	/*
	zend_string* prop_name = NULL;
	zend_property_info* prop_info = NULL;
	zval* prop_zv = NULL;
	*/
	for (int cont = 0; cont < ghcf.num_sst; cont++) {

		zval sst_obj, sst_board, val_zv;
		zend_object *enum_case = NULL, *sst_board_zo = NULL;

		//we instantiate the SST_t class
		object_init_ex(&sst_obj, grSST_ce);

		switch (ghcf.SSTs[cont].type)
		{
		case GR_SSTTYPE_VOODOO:
			
			enum_case = zend_enum_get_case_cstr(grSstType_ce, "GR_SSTTYPE_VOODOO");
			
			object_init_ex(&sst_board, grVoodooConfig_ce);

			sst_board_zo = Z_OBJ_P(&sst_board);

			ZVAL_LONG(&val_zv, ghcf.SSTs[cont].sstBoard.VoodooConfig.fbRam);
			zend_update_property(grVoodooConfig_ce, sst_board_zo, "fbRam", sizeof("fbRam") - 1, &val_zv);

			ZVAL_LONG(&val_zv, ghcf.SSTs[cont].sstBoard.VoodooConfig.fbiRev);
			zend_update_property(grVoodooConfig_ce, sst_board_zo, "fbiRev", sizeof("fbiRev") - 1, &val_zv);

			ZVAL_LONG(&val_zv, ghcf.SSTs[cont].sstBoard.VoodooConfig.nTexelfx);
			zend_update_property(grVoodooConfig_ce, sst_board_zo, "nTexelfx", sizeof("nTexelfx") - 1, &val_zv);
			
			ZVAL_BOOL(&val_zv, ghcf.SSTs[cont].sstBoard.VoodooConfig.sliDetect);
			zend_update_property(grVoodooConfig_ce, sst_board_zo, "sliDetect", sizeof("sliDetect") - 1, &val_zv);
					
			{
				zval tmuConfig_arr_zval;
				array_init_size(&tmuConfig_arr_zval, ghcf.SSTs[cont].sstBoard.VoodooConfig.nTexelfx);
				
				for (int cont2 = 0; cont2 < ghcf.SSTs[cont].sstBoard.VoodooConfig.nTexelfx; cont2++) {
					zval grTMUConfig_t;

					object_init_ex(&grTMUConfig_t, grTMUConfig_ce);
					zend_object* grTMUConfig_zo = Z_OBJ_P(&grTMUConfig_t);

					ZVAL_LONG(&val_zv, ghcf.SSTs[cont].sstBoard.VoodooConfig.tmuConfig[cont2].tmuRev);
					zend_update_property(grTMUConfig_ce, grTMUConfig_zo, "tmuRev", sizeof("tmuRev") - 1, &val_zv);

					ZVAL_LONG(&val_zv, ghcf.SSTs[cont].sstBoard.VoodooConfig.tmuConfig[cont2].tmuRam);
					zend_update_property(grTMUConfig_ce, grTMUConfig_zo, "tmuRam", sizeof("tmuRam") - 1, &val_zv);

					add_next_index_zval(&tmuConfig_arr_zval, &grTMUConfig_t);
				}
				
				zend_update_property(
					grVoodooConfig_ce,
					sst_board_zo,
					"tmuConfig",
					sizeof("tmuConfig") - 1,
					&tmuConfig_arr_zval
				);

				zval_ptr_dtor(&tmuConfig_arr_zval); //destroy the local pointer
			}


			break;
		default: //Banshee, and others. not garanteed it will work
		case GR_SSTTYPE_Voodoo2:
			enum_case = zend_enum_get_case_cstr(grSstType_ce, "GR_SSTTYPE_Voodoo2");
			
			object_init_ex(&sst_board, grVoodoo2Config_ce);

			sst_board_zo = Z_OBJ_P(&sst_board);
			
			ZVAL_LONG(&val_zv, ghcf.SSTs[cont].sstBoard.Voodoo2Config.fbRam);
			zend_update_property(grVoodoo2Config_ce, sst_board_zo, "fbRam", sizeof("fbRam") - 1, &val_zv);

			ZVAL_LONG(&val_zv, ghcf.SSTs[cont].sstBoard.Voodoo2Config.fbiRev);
			zend_update_property(grVoodoo2Config_ce, sst_board_zo, "fbiRev", sizeof("fbiRev") - 1, &val_zv);

			ZVAL_LONG(&val_zv, ghcf.SSTs[cont].sstBoard.Voodoo2Config.nTexelfx);
			zend_update_property(grVoodoo2Config_ce, sst_board_zo, "nTexelfx", sizeof("nTexelfx") - 1, &val_zv);

			ZVAL_BOOL(&val_zv, ghcf.SSTs[cont].sstBoard.Voodoo2Config.sliDetect);
			zend_update_property(grVoodoo2Config_ce, sst_board_zo, "sliDetect", sizeof("sliDetect") - 1, &val_zv);

			{
				zval tmuConfig_arr_zval;
				array_init_size(&tmuConfig_arr_zval, ghcf.SSTs[cont].sstBoard.Voodoo2Config.nTexelfx);
				
				for (int cont2 = 0; cont2 < ghcf.SSTs[cont].sstBoard.Voodoo2Config.nTexelfx; cont2++) {
					zval grTMUConfig_t;
					
					object_init_ex(&grTMUConfig_t, grTMUConfig_ce);
					zend_object* grTMUConfig_zo = Z_OBJ_P(&grTMUConfig_t);

					ZVAL_LONG(&val_zv, ghcf.SSTs[cont].sstBoard.Voodoo2Config.tmuConfig[cont2].tmuRev);
					zend_update_property(grTMUConfig_ce, grTMUConfig_zo, "tmuRev", sizeof("tmuRev") - 1, &val_zv);

					ZVAL_LONG(&val_zv, ghcf.SSTs[cont].sstBoard.Voodoo2Config.tmuConfig[cont2].tmuRam);
					zend_update_property(grTMUConfig_ce, grTMUConfig_zo, "tmuRam", sizeof("tmuRam") - 1, &val_zv);

					add_next_index_zval(&tmuConfig_arr_zval, &grTMUConfig_t);
				}
				
				zend_update_property(
					grVoodoo2Config_ce,
					sst_board_zo,
					"tmuConfig",
					sizeof("tmuConfig") - 1,
					&tmuConfig_arr_zval
				);

				zval_ptr_dtor(&tmuConfig_arr_zval); //destroy the local pointer
			}

			break;
		case GR_SSTTYPE_SST96:
			enum_case = zend_enum_get_case_cstr(grSstType_ce, "GR_SSTTYPE_SST96");

			object_init_ex(&sst_board, grSst96Config_ce);

			sst_board_zo = Z_OBJ_P(&sst_board);
			
			ZVAL_LONG(&val_zv, ghcf.SSTs[cont].sstBoard.SST96Config.fbRam);
			zend_update_property(grSst96Config_ce, sst_board_zo, "fbRam", sizeof("fbRam") - 1, &val_zv);

			ZVAL_LONG(&val_zv, ghcf.SSTs[cont].sstBoard.SST96Config.nTexelfx);
			zend_update_property(grSst96Config_ce, sst_board_zo, "nTexelfx", sizeof("nTexelfx") - 1, &val_zv);

			{
				zval grTMUConfig_t;
				zend_object* grTMUConfig_zo = NULL;

				object_init_ex(&grTMUConfig_t, grTMUConfig_ce);
				grTMUConfig_zo = Z_OBJ_P(&grTMUConfig_t);

				ZVAL_LONG(&val_zv, ghcf.SSTs[cont].sstBoard.SST96Config.tmuConfig.tmuRev);
				zend_update_property(grTMUConfig_ce, grTMUConfig_zo, "tmuRev", sizeof("tmuRev") - 1, &val_zv);

				ZVAL_LONG(&val_zv, ghcf.SSTs[cont].sstBoard.SST96Config.tmuConfig.tmuRam);
				zend_update_property(grTMUConfig_ce, grTMUConfig_zo, "tmuRam", sizeof("tmuRam") - 1, &val_zv);

				zend_update_property(grSst96Config_ce, sst_board_zo, "tmuConfig", sizeof("tmuConfig") - 1, &grTMUConfig_t);

				zval_ptr_dtor(&grTMUConfig_t); //destroy the local pointer
			}

			break;
		case GR_SSTTYPE_AT3D:
			enum_case = zend_enum_get_case_cstr(grSstType_ce, "GR_SSTTYPE_AT3D");

			object_init_ex(&sst_board, grAT3DConfig_ce);

			sst_board_zo = Z_OBJ_P(&sst_board);

			ZVAL_LONG(&val_zv, ghcf.SSTs[cont].sstBoard.AT3DConfig.rev);
			zend_update_property(grAT3DConfig_ce, sst_board_zo, "rev", sizeof("rev") - 1, &val_zv);

			break;
		}		
		
		
		ZVAL_OBJ(&val_zv, enum_case);
		zend_update_property(
			grSST_ce, Z_OBJ_P(&sst_obj), 
			"type", sizeof("type") - 1, 
			&val_zv
		);
		
		zend_update_property(
			grSST_ce, Z_OBJ_P(&sst_obj),
			"sstBoard", sizeof("sstBoard") - 1,
			&sst_board
		);
		zval_ptr_dtor(&sst_board); //destroy the local pointer
		
		
		add_next_index_zval(&sSTs_arr_zval, &sst_obj);

		//zval_ptr_dtor(&sst_obj);  //destroy the local pointer I'M WORKING HERE !!!!

	} //for loop

	zend_update_property(
		grHwConfiguration_ce, grHwConfiguration_obj, 
		"SSTs", sizeof("SSTs") - 1, 
		&sSTs_arr_zval
	);

	zval_ptr_dtor(&sSTs_arr_zval);  //destroy the local pointer

	RETURN_BOOL(result);
}

PHP_FUNCTION(grSstSelect)
{
	zend_long which_sst;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(which_sst)
	ZEND_PARSE_PARAMETERS_END();

	grSstSelect((int)which_sst);
}

PHP_FUNCTION(grSstWinOpen)
{
	zend_long hWin;
	zend_bool is_null;
	zend_object* res = NULL;
	zend_object* ref = NULL;
	zend_object* cFormat = NULL;
	zend_object* org_loc = NULL;
	zend_long num_buffers;
	zend_long num_aux_buffers;

	FxBool result;

	ZEND_PARSE_PARAMETERS_START(7, 7)
		Z_PARAM_LONG_OR_NULL(hWin, is_null)
		Z_PARAM_OBJ_OF_CLASS(res, grScreenResolution_ce)
		Z_PARAM_OBJ_OF_CLASS(ref, grScreenRefresh_ce)
		Z_PARAM_OBJ_OF_CLASS(cFormat, grColorFormat_ce)
		Z_PARAM_OBJ_OF_CLASS(org_loc, grOriginLocation_ce)
		Z_PARAM_LONG(num_buffers)
		Z_PARAM_LONG(num_aux_buffers)
	ZEND_PARSE_PARAMETERS_END();

	result = grSstWinOpen(
		(FxU32)(is_null ? 0 : hWin),
		(GrScreenResolution_t) enum_to_int(res),
		(GrScreenRefresh_t) enum_to_int(ref),
		(GrColorFormat_t) enum_to_int(cFormat),
		(GrOriginLocation_t)enum_to_int(org_loc),
		(int)num_buffers,
		(int)num_aux_buffers
	);

	RETURN_BOOL(result);
}

PHP_FUNCTION(grSstWinClose) {
	ZEND_PARSE_PARAMETERS_NONE();
	grSstWinClose();
}
