#ifndef STRUCT_H
#define STRUCT_H

#include "stdafx.h"

static void handle_property_error(zend_object* object, zend_string* member) {
    zend_throw_error(NULL, "Typed property %s::$%s must not be accessed before initialization", ZSTR_VAL(object->ce->name), ZSTR_VAL(member));
}

//macros to get the address of the scaler_embedded_t from zend_object and from zval
#define O_EMBEDDED_P(t, o) \
	((t*)((char*)(o) - XtOffsetOf(t, std)))

#define Z_EMBEDDED_P(t, zv) \
	O_EMBEDDED_P(t, Z_OBJ_P(zv))

zend_class_entry* gr_flushable_ce;

void phpglide2x_register_gr_flushable(INIT_FUNC_ARGS);

extern zend_class_entry* grTMUConfig_ce;

typedef struct _GrTMUConfig_t {
    GrTMUConfig_t grTMUConfig;	// the embeded data
    //HashTable field_map;
    zend_object std;	// it is important that the zend_object goes last
} _GrTMUConfig_t;

void flush_grTMUConfig(const _GrTMUConfig_t* grTMUConfig, GrTMUConfig_t* buffer);

void hydrate_grTMUConfig(const GrTMUConfig_t* buffer, _GrTMUConfig_t* grTMUConfig);

void phpglide2x_register_grTMUConfig(INIT_FUNC_ARGS);



extern zend_class_entry* grVoodooConfig_ce;
extern zend_class_entry* grVoodoo2Config_ce;

typedef struct _GrVoodooConfig_t {
    GrVoodooConfig_t grVoodooConfig;	// the embeded data
    zend_object std;	// it is important that the zend_object goes last
} _GrVoodooConfig_t;

typedef struct _GrVoodoo2Config_t {
    GrVoodoo2Config_t grVoodoo2Config;	// the embeded data
    zend_object std;	// it is important that the zend_object goes last
} _GrVoodoo2Config_t;

void phpglide2x_register_grVoodooConfig(INIT_FUNC_ARGS);

void flush_grVoodooConfig(const _GrVoodooConfig_t* grVoodooConfig, GrVoodooConfig_t* buffer);

void hydrate_grVoodooConfig(const GrVoodooConfig_t* voodooConfig, _GrVoodooConfig_t* grVoodooConfig);

void flush_grVoodoo2Config(const _GrVoodoo2Config_t* grVoodoo2Config, GrVoodoo2Config_t* buffer);

void hydrate_grVoodoo2Config(const GrVoodoo2Config_t* voodoo2Config, _GrVoodoo2Config_t* grVoodoo2Config);



extern zend_class_entry* grSst96Config_ce;

typedef struct _GrSst96Config_t {
    GrSst96Config_t grSst96Config;	// the embeded data
    zend_object std;	// it is important that the zend_object goes last
} _GrSst96Config_t;

void flush_GrSst96Config(const _GrSst96Config_t* grSst96Config, GrSst96Config_t* buffer);

void hydrate_GrSst96Config(const GrSst96Config_t* buffer, _GrSst96Config_t* grSst96Config);

void phpglide2x_register_grSst96Config(INIT_FUNC_ARGS);



extern zend_class_entry* grAT3DConfig_ce;

typedef struct _GrAT3DConfig_t {
    GrAT3DConfig_t grAT3DConfig;	// the embeded data
    zend_object std;	// it is important that the zend_object goes last
} _GrAT3DConfig_t;

void flush_GrAT3DConfig(const _GrAT3DConfig_t* grAT3DConfig, GrAT3DConfig_t* buffer);

void hydrate_GrAT3DConfig(const GrAT3DConfig_t* buffer, _GrAT3DConfig_t* grAT3DConfig);

void phpglide2x_register_grAT3DConfig(INIT_FUNC_ARGS);


extern zend_class_entry* sST_ce;

typedef struct SST_t {
    GrSstType type;             /* Which hardware is it? */
    union {
        GrVoodooConfig_t  VoodooConfig;
        GrSst96Config_t   SST96Config;
        GrAT3DConfig_t    AT3DConfig;
        GrVoodoo2Config_t Voodoo2Config;
    } sstBoard;
} SST_t;

typedef struct _SST_t {
    SST_t SST;	// the embeded data
    //HashTable field_map;
    zend_object std;	// it is important that the zend_object goes last
} _SST_t;

void flush_SST(const _SST_t* sST, SST_t* buffer);

void hydrate_SST(const SST_t* sSTs, _SST_t* _sST);

void phpglide2x_register_grSST(INIT_FUNC_ARGS);



extern zend_class_entry* grHwConfiguration_ce;

typedef struct _GrHwConfiguration {
    GrHwConfiguration grHwConfiguration;
    zend_object std;
} _GrHwConfiguration;

void flush_GrHwConfiguration(const _GrHwConfiguration* grHwConfiguration_obj, GrHwConfiguration* buffer);

void hydrate_GrHwConfiguration(const GrHwConfiguration* buffer, _GrHwConfiguration* grHwConfiguration_obj);

void phpglide2x_register_grHwConfiguration(INIT_FUNC_ARGS);





extern zend_class_entry* grTmuVertex_ce;

typedef struct _GrTmuVertex {
    GrTmuVertex grTmuVertex;
    zend_object std;
} _GrTmuVertex;

void flush_grTmuVertex(const _GrTmuVertex* grVertex, GrTmuVertex* buffer);

void hydrate_grTmuVertex(const GrTmuVertex* buffer, _GrTmuVertex* grVertex);

void phpglide2x_register_grTmuVertex(INIT_FUNC_ARGS);


extern zend_class_entry* grVertex_ce;

typedef struct _GrVertex {
    GrVertex grVertex;
    zend_object std;
} _GrVertex;

void flush_grVertex(const _GrVertex* grVertex, GrVertex* buffer);

void hydrate_grVertex(const GrVertex* buffer, _GrVertex* grVertex);

void phpglide2x_register_grVertex(INIT_FUNC_ARGS);



extern zend_class_entry* grState_ce;

typedef struct _GrState {
    GrState grState;
    zend_object std;
} _GrState;

void flush_grState(const _GrState* grState, GrState* buffer);

void hydrate_grState(const GrState* buffer, _GrState* grState);

void phpglide2x_register_grState(INIT_FUNC_ARGS);



extern zend_class_entry* grLfbInfo_ce;

typedef struct _GrLfbInfo_t {
    GrLfbInfo_t grLfbInfo;	// the embeded data
    zend_object std;	// it is important that the zend_object goes last
} _GrLfbInfo_t;

void flush_grLfbInfo(const _GrLfbInfo_t* grLfbInfo, GrLfbInfo_t* buffer, bool write);

void hydrate_grLfbInfo(const GrLfbInfo_t* buffer, _GrLfbInfo_t* grLfbInfo, bool read);

void phpglide2x_register_grLfbInfo(INIT_FUNC_ARGS);





extern zend_class_entry* gr_SstPerfStats_ce;

typedef struct _GrSstPerfStats_t {
    GrSstPerfStats_t grSstPerfStats;	// the embeded data
    zend_object std;	// it is important that the zend_object goes last
} _GrSstPerfStats_t;

void flush_grSstPerfStats(const _GrSstPerfStats_t* grLfbInfo, GrSstPerfStats_t* buffer);

void hydrate_grSstPerfStats(const GrSstPerfStats_t* buffer, _GrSstPerfStats_t* grLfbInfo);

void phpglide2x_register_grSstPerfStats(INIT_FUNC_ARGS);



void phpglide2x_register_structs(INIT_FUNC_ARGS);

#endif