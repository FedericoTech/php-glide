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

extern zend_class_entry* grTMUConfig_ce;
typedef zend_object _GrTMUConfig_t;
void flush_grTMUConfig(const _GrTMUConfig_t* obj, GrTMUConfig_t* buffer);
void hydrate_grTMUConfig(const GrTMUConfig_t* buffer, _GrTMUConfig_t* obj);


extern zend_class_entry* grVoodooConfig_ce;
typedef zend_object _GrVoodooConfig_t;
void flush_grVoodooConfig(const _GrVoodooConfig_t* obj, GrVoodooConfig_t* buffer);
void hydrate_grVoodooConfig(const GrVoodooConfig_t* buffer, _GrVoodooConfig_t* obj);


extern zend_class_entry* grVoodoo2Config_ce;
typedef zend_object _GrVoodoo2Config_t;
void flush_grVoodoo2Config(const _GrVoodoo2Config_t* obj, GrVoodoo2Config_t* buffer);
void hydrate_grVoodoo2Config(const GrVoodoo2Config_t* buffer, _GrVoodoo2Config_t* obj);


extern zend_class_entry* grSst96Config_ce;
typedef zend_object _GrSst96Config_t;
void flush_GrSst96Config(const _GrSst96Config_t* obj, GrSst96Config_t* buffer);
void hydrate_GrSst96Config(const GrSst96Config_t* buffer, _GrSst96Config_t* obj);


extern zend_class_entry* grAT3DConfig_ce;
typedef zend_object _GrAT3DConfig_t;
void flush_GrAT3DConfig(const _GrAT3DConfig_t* obj, GrAT3DConfig_t* buffer);
void hydrate_GrAT3DConfig(const GrAT3DConfig_t* buffer, _GrAT3DConfig_t* obj);


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

typedef zend_object _SST_t;
void flush_SST(const _SST_t* obj, SST_t* buffer);
void hydrate_SST(const SST_t* buffer, _SST_t* obj);


extern zend_class_entry* grHwConfiguration_ce;
typedef zend_object _GrHwConfiguration;
void flush_GrHwConfiguration(const _GrHwConfiguration* grHwConfiguration_obj, GrHwConfiguration* buffer);
void hydrate_GrHwConfiguration(const GrHwConfiguration* buffer, _GrHwConfiguration* grHwConfiguration_obj);



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





extern zend_class_entry* grTexInfo_ce;

typedef struct _GrTexInfo {
    GrTexInfo grTexInfo;	// the embeded data
    zend_object std;	// it is important that the zend_object goes last
} _GrTexInfo;

void flush_grTexInfo(const _GrTexInfo* grTexInfo, GrTexInfo* buffer);

void hydrate_grTexInfo(const GrTexInfo* buffer, _GrTexInfo* grTexInfo);

void phpglide2x_register_grTexInfo(INIT_FUNC_ARGS);




extern zend_class_entry* gu3dfHeader_ce;

typedef struct _Gu3dfHeader {
    Gu3dfHeader gu3dfHeader;	// the embeded data
    zend_object std;	// it is important that the zend_object goes last
} _Gu3dfHeader;

void flush_gu3dfHeader(const _Gu3dfHeader* gu3dfHeader, Gu3dfHeader* buffer);

void hydrate_gu3dfHeader(const Gu3dfHeader* buffer, _Gu3dfHeader* gu3dfHeader);

void phpglide2x_register_gu3dfHeader(INIT_FUNC_ARGS);







void phpglide2x_register_structs(INIT_FUNC_ARGS);

#endif