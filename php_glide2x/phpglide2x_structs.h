#ifndef STRUCT_H
#define STRUCT_H

#include "stdafx.h"

#define MAX_SYNCERS 100

static void handle_property_error(zend_object* object, zend_string* member) {
    zend_throw_error(NULL, "Typed property %s::$%s must not be accessed before initialization", ZSTR_VAL(object->ce->name), ZSTR_VAL(member));
}

//macros to get the address of the scaler_embedded_t from zend_object and from zval
#define O_EMBEDDED_P(t, zo) \
	((t*)((char*)(zo) - XtOffsetOf(t, std)))

#define Z_EMBEDDED_P(t, zv) \
	O_EMBEDDED_P(t, Z_OBJ_P(zv))

zend_class_entry* gr_Binarizable_ce;

extern zend_class_entry* grTMUConfig_ce;
typedef zend_object _GrTMUConfig_t;
void GrTMUConfig_flush(const _GrTMUConfig_t* self, GrTMUConfig_t* buffer);
void GrTMUConfig_hydrate(_GrTMUConfig_t* self, const GrTMUConfig_t* buffer);


extern zend_class_entry* grVoodooConfig_ce;
typedef zend_object _GrVoodooConfig_t;
void GrVoodooConfig_flush(const _GrVoodooConfig_t* self, GrVoodooConfig_t* buffer);
void GrVoodooConfig_hydrate(_GrVoodooConfig_t* self, const GrVoodooConfig_t* buffer);


extern zend_class_entry* grVoodoo2Config_ce;
typedef zend_object _GrVoodoo2Config_t;
void GrVoodoo2Config_flush(const _GrVoodoo2Config_t* self, GrVoodoo2Config_t* buffer);
void GrVoodoo2Config_hydrate(_GrVoodoo2Config_t* self, const GrVoodoo2Config_t* buffer);


extern zend_class_entry* grSst96Config_ce;
typedef zend_object _GrSst96Config_t;
void GrSst96Config_flush(const _GrSst96Config_t* self, GrSst96Config_t* buffer);
void GrSst96Config_hydrate(_GrSst96Config_t* self, const GrSst96Config_t* buffer);


extern zend_class_entry* grAT3DConfig_ce;
typedef zend_object _GrAT3DConfig_t;
void GrAT3DConfig_flush(const _GrAT3DConfig_t* self, GrAT3DConfig_t* buffer);
void GrAT3DConfig_hydrate(_GrAT3DConfig_t* self, const GrAT3DConfig_t* buffer);


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
void SST_flush(const _SST_t* self, SST_t* buffer);
void SST_hydrate(_SST_t* self, const SST_t* buffer);


extern zend_class_entry* grHwConfiguration_ce;
typedef zend_object _GrHwConfiguration;
void GrHwConfiguration_flush(const _GrHwConfiguration* self, GrHwConfiguration* buffer);
void GrHwConfiguration_hydrate(_GrHwConfiguration* self, const GrHwConfiguration* buffer);



extern zend_class_entry* grTmuVertex_ce;

typedef struct _GrTmuVertex {
    union {
        uint32_t arr[3];
        struct {
            uint32_t sow;
            uint32_t tow;
            uint32_t oow;
        } fields;
    } offsets;
    zend_object std;
} _GrTmuVertex;

void GrTmuVertex_flush(const _GrTmuVertex* self, GrTmuVertex* buffer);

void GrTmuVertex_hydrate(_GrTmuVertex* self, const GrTmuVertex* buffer);

void phpglide2x_register_grTmuVertex(INIT_FUNC_ARGS);

extern zend_class_entry* grTmuVertices_ce;

typedef struct _GrTmuVertices {
    zval tmu[GLIDE_NUM_TMU]; 
    zend_object std;
} _GrTmuVertices;

void GrTmuVertices_flush(const _GrTmuVertices* self, GrTmuVertex* buffer);

void GrTmuVertices_hydrate(_GrTmuVertices* self, const GrTmuVertex* buffer);

void phpglide2x_register_grTmuVertices(INIT_FUNC_ARGS);


extern zend_class_entry* grVertex_ce;

typedef struct _GrVertex {
    //offsets part
    union {
        uint32_t arr[10];   //we store the offset to find the zvals directly
        struct {
            uint32_t x, y, z;
            uint32_t r, g, b;
            uint32_t ooz, a, oow;
            uint32_t tmuvtx;
        } fields;
    } offsets;
    zend_object std;
} _GrVertex;

void GrVertex_flush(const _GrVertex* self, GrVertex* buffer);
void GrVertex_hydrate(_GrVertex* self, const GrVertex* buffer);

void phpglide2x_register_grVertex(INIT_FUNC_ARGS);

extern zend_class_entry* grState_ce;

typedef struct _GrState {
    GrState grState;
    zend_object std;
} _GrState;

void GrState_flush(const _GrState* self, GrState* buffer);
void GrState_hydrate(_GrState* self, const GrState* buffer);

void phpglide2x_register_grState(INIT_FUNC_ARGS);



extern zend_class_entry* grLfbInfo_ce;

typedef struct _GrLfbInfo_t {
    GrLfbInfo_t grLfbInfo;	// the embeded data
    zend_object std;	// it is important that the zend_object goes last
} _GrLfbInfo_t;

void GrLfbInfo_flush(const _GrLfbInfo_t* self, GrLfbInfo_t* buffer, bool write);
void GrLfbInfo_hydrate(_GrLfbInfo_t* self, const GrLfbInfo_t* buffer, bool read);

void phpglide2x_register_grLfbInfo(INIT_FUNC_ARGS);





extern zend_class_entry* gr_SstPerfStats_ce;
typedef zend_object _GrSstPerfStats_t;
void GrSstPerfStats_flush(const _GrSstPerfStats_t* self, GrSstPerfStats_t* buffer);
void GrSstPerfStats_hydrate(_GrSstPerfStats_t* self, const GrSstPerfStats_t* buffer);





extern zend_class_entry* grTexInfo_ce;

typedef struct _GrTexInfo {
    GrTexInfo grTexInfo;	// the embeded data
    zend_object std;	// it is important that the zend_object goes last
} _GrTexInfo;

void GrTexInfo_flush(const _GrTexInfo* self, GrTexInfo* buffer);
void GrTexInfo_hydrate(_GrTexInfo* self, const GrTexInfo* buffer);

void phpglide2x_register_grTexInfo(INIT_FUNC_ARGS);




extern zend_class_entry* gu3dfHeader_ce;
typedef zend_object _Gu3dfHeader;
void Gu3dfHeader_flush(const _Gu3dfHeader* self, Gu3dfHeader* buffer);
void Gu3dfHeader_hydrate(_Gu3dfHeader* self, const Gu3dfHeader* buffer);







void phpglide2x_register_structs(INIT_FUNC_ARGS);

#endif