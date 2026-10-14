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

zend_class_entry* gr_flushable_ce;

extern zend_class_entry* grTMUConfig_ce;
typedef zend_object _GrTMUConfig_t;
void GrTMUConfig_flush(const _GrTMUConfig_t* obj, GrTMUConfig_t* buffer);
void GrTMUConfig_hydrate(const GrTMUConfig_t* buffer, _GrTMUConfig_t* obj);


extern zend_class_entry* grVoodooConfig_ce;
typedef zend_object _GrVoodooConfig_t;
void GrVoodooConfig_flush(const _GrVoodooConfig_t* obj, GrVoodooConfig_t* buffer);
void GrVoodooConfig_hydrate(const GrVoodooConfig_t* buffer, _GrVoodooConfig_t* obj);


extern zend_class_entry* grVoodoo2Config_ce;
typedef zend_object _GrVoodoo2Config_t;
void GrVoodoo2Config_flush(const _GrVoodoo2Config_t* obj, GrVoodoo2Config_t* buffer);
void GrVoodoo2Config_hydrate(const GrVoodoo2Config_t* buffer, _GrVoodoo2Config_t* obj);


extern zend_class_entry* grSst96Config_ce;
typedef zend_object _GrSst96Config_t;
void GrSst96Config_flush(const _GrSst96Config_t* obj, GrSst96Config_t* buffer);
void GrSst96Config_hydrate(const GrSst96Config_t* buffer, _GrSst96Config_t* obj);


extern zend_class_entry* grAT3DConfig_ce;
typedef zend_object _GrAT3DConfig_t;
void GrAT3DConfig_flush(const _GrAT3DConfig_t* obj, GrAT3DConfig_t* buffer);
void GrAT3DConfig_hydrate(const GrAT3DConfig_t* buffer, _GrAT3DConfig_t* obj);


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
void SST_flush(const _SST_t* obj, SST_t* buffer);
void SST_hydrate(const SST_t* buffer, _SST_t* obj);


extern zend_class_entry* grHwConfiguration_ce;
typedef zend_object _GrHwConfiguration;
void GrHwConfiguration_flush(const _GrHwConfiguration* obj, GrHwConfiguration* buffer);
void GrHwConfiguration_hydrate(const GrHwConfiguration* buffer, _GrHwConfiguration* obj);



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
    union {
        GrTmuVertex tmu;
        float props[3];
    } tmuVertex;
    uint16_t referenced_mask;   //properties that have become a reference
    
    GrTmuVertex *sync_references[MAX_SYNCERS];  //pointer to buffers to sync
    uint16_t sync_count;
    zend_object std;
} _GrTmuVertex;

void GrTmuVertex_flush(const _GrTmuVertex* grTmuVertex, GrTmuVertex* buffer);

void GrTmuVertex_hydrate(const GrTmuVertex* buffer, _GrTmuVertex* grTmuVertex);

void phpglide2x_register_grTmuVertex(INIT_FUNC_ARGS);

static inline GrTmuVertex* GrTmuVertex_autoFlush(zend_object* zo)
{
    _GrTmuVertex* v = O_EMBEDDED_P(_GrTmuVertex, zo);

    //if any difference property escaped...
    if (v->referenced_mask) {
        GrTmuVertex_flush(v, &v->tmuVertex.tmu);
    }

    return &v->tmuVertex.tmu;
}




extern zend_class_entry* grTmuVertices_ce;

typedef struct _GrTmuVertices {
    zval tmu[GLIDE_NUM_TMU];

    GrTmuVertex gtvArray[GLIDE_NUM_TMU];   //to the GrTmuVertex[2] off all the objects that point to this
    
    uint16_t referenced_mask;
    zend_object std;
} _GrTmuVertices;

void GrTmuVertices_removeSyncRef(GrTmuVertex* my, _GrTmuVertex* from);
void GrTmuVertices_setSyncRef(GrTmuVertex* my, _GrTmuVertex* to);

void GrTmuVertices_flush(const _GrTmuVertices* grTmuVertices, GrTmuVertex* buffer);

void GrTmuVertices_hydrate(const GrTmuVertex* buffer, _GrTmuVertices* grTmuVertices);

void phpglide2x_register_grTmuVertices(INIT_FUNC_ARGS);


extern zend_class_entry* grVertex_ce;

#define GR_X_REFERENCED (1 << 0)
#define GR_Y_REFERENCED (1 << 1)
#define GR_Z_REFERENCED (1 << 2)

#define GR_R_REFERENCED (1 << 3)
#define GR_G_REFERENCED (1 << 4)
#define GR_B_REFERENCED (1 << 5)

#define GR_OOZ_REFERENCED (1 << 6)
#define GR_A_REFERENCED   (1 << 7)
#define GR_OOW_REFERENCED (1 << 8)

#define GR_TMUVTX_REFERENCED (1 << 9)

typedef struct _GrVertex {
    //offsets part
    union {
        uint32_t  arr[9];   //we store the offset to find the zvals directly
        struct {
            uint32_t x, y, z;
            uint32_t r, g, b;
            uint32_t ooz, a, oow;
        } fields;
    } offsets;
    //GrVertex part
    union {
        GrVertex vertex;    //either GrVertex
        struct {            //or floats array
            float props[9];
            GrTmuVertex tmuvtx[GLIDE_NUM_TMU];
        };
    } grVertex;
    uint16_t referenced_mask;
    zend_object std;
} _GrVertex;

void GrVertex_flush(const _GrVertex* grVertex, GrVertex* buffer);

void GrVertex_hydrate(const GrVertex* buffer, _GrVertex* grVertex);

void phpglide2x_register_grVertex(INIT_FUNC_ARGS);

static inline GrVertex* GrVertex_autoFlush(zend_object* zo)
{
    _GrVertex* v = O_EMBEDDED_P(_GrVertex, zo);

    //if any difference property escaped...
    if (v->referenced_mask) {
        GrVertex_flush(v, &v->grVertex.vertex);
    }

    return &v->grVertex.vertex;
}



extern zend_class_entry* grState_ce;

typedef struct _GrState {
    GrState grState;
    zend_object std;
} _GrState;

void GrState_flush(const _GrState* grState, GrState* buffer);

void GrState_hydrate(const GrState* buffer, _GrState* grState);

void phpglide2x_register_grState(INIT_FUNC_ARGS);



extern zend_class_entry* grLfbInfo_ce;

typedef struct _GrLfbInfo_t {
    GrLfbInfo_t grLfbInfo;	// the embeded data
    zend_object std;	// it is important that the zend_object goes last
} _GrLfbInfo_t;

void GrLfbInfo_flush(const _GrLfbInfo_t* grLfbInfo, GrLfbInfo_t* buffer, bool write);

void GrLfbInfo_hydrate(const GrLfbInfo_t* buffer, _GrLfbInfo_t* grLfbInfo, bool read);

void phpglide2x_register_grLfbInfo(INIT_FUNC_ARGS);





extern zend_class_entry* gr_SstPerfStats_ce;
typedef zend_object _GrSstPerfStats_t;
void GrSstPerfStats_flush(const _GrSstPerfStats_t* obj, GrSstPerfStats_t* buffer);
void GrSstPerfStats_hydrate(const GrSstPerfStats_t* buffer, _GrSstPerfStats_t* obj);





extern zend_class_entry* grTexInfo_ce;

typedef struct _GrTexInfo {
    GrTexInfo grTexInfo;	// the embeded data
    zend_object std;	// it is important that the zend_object goes last
} _GrTexInfo;

void GrTexInfo_flush(const _GrTexInfo* grTexInfo, GrTexInfo* buffer);

void GrTexInfo_hydrate(const GrTexInfo* buffer, _GrTexInfo* grTexInfo);

void phpglide2x_register_grTexInfo(INIT_FUNC_ARGS);




extern zend_class_entry* gu3dfHeader_ce;
typedef zend_object _Gu3dfHeader;
void Gu3dfHeader_flush(const _Gu3dfHeader* obj, Gu3dfHeader* buffer);
void Gu3dfHeader_hydrate(const Gu3dfHeader* buffer, _Gu3dfHeader* obj);







void phpglide2x_register_structs(INIT_FUNC_ARGS);

#endif