#ifndef STRUCT_H
#define STRUCT_H

#include "stdafx.h"

extern zend_class_entry* grTMUConfig_ce;
extern zend_class_entry* grVoodooConfig_ce;
extern zend_class_entry* grVoodoo2Config_ce;

extern zend_class_entry* grSst96Config_ce;
extern zend_class_entry* grAT3DConfig_ce;
extern zend_class_entry* grSST_ce;
extern zend_class_entry* grHwConfiguration_ce;

extern zend_class_entry* grTmuVertex_ce;
extern zend_class_entry* grVertex_ce;

static void handle_property_error(zend_object* object, zend_string* member) {
    zend_throw_error(NULL, "Typed property %s::$%s must not be accessed before initialization", ZSTR_VAL(object->ce->name), ZSTR_VAL(member));
}

//macros to get the address of the scaler_embedded_t from zend_object and from zval
#define O_EMBEDDED_P(t, o) \
	((t*)((char*)(o) - XtOffsetOf(t, std)))

#define Z_EMBEDDED_P(t, zv) \
	O_EMBEDDED_P(t, Z_OBJ_P(zv))

typedef struct _GrTMUConfig_t {
    GrTMUConfig_t grTMUConfig;	// the embeded data
    //HashTable field_map;
    zend_object std;	// it is important that the zend_object goes last
} _GrTMUConfig_t;

void phpglide2x_register_grTMUConfig(INIT_FUNC_ARGS);

typedef struct _GrVoodooConfig_t {
    GrVoodooConfig_t grVoodooConfig;	// the embeded data
    //HashTable field_map;
    zend_object std;	// it is important that the zend_object goes last
} _GrVoodooConfig_t;

typedef struct _GrSst96Config_t {
    GrSst96Config_t grSst96Config;	// the embeded data
    //HashTable field_map;
    zend_object std;	// it is important that the zend_object goes last
} _GrSst96Config_t;

void phpglide2x_register_grSst96Config(INIT_FUNC_ARGS);

typedef struct _GrAT3DConfig_t {
    GrAT3DConfig_t grAT3DConfig;	// the embeded data
    zend_object std;	// it is important that the zend_object goes last
} _GrAT3DConfig_t;

// typedef _GrVoodooConfig_t _GrVoodoo2Config_t;

typedef struct _GrVoodoo2Config_t {
    GrVoodoo2Config_t grVoodoo2Config;	// the embeded data
    //HashTable field_map;
    zend_object std;	// it is important that the zend_object goes last
} _GrVoodoo2Config_t;

void phpglide2x_register_grVoodooConfig(INIT_FUNC_ARGS);

void phpglide2x_register_grAT3DConfig(INIT_FUNC_ARGS);

typedef struct _GrSST {
    struct SST {
        GrSstType type;             /* Which hardware is it? */
        union {
            GrVoodooConfig_t  VoodooConfig;
            GrSst96Config_t   SST96Config;
            GrAT3DConfig_t    AT3DConfig;
            GrVoodoo2Config_t Voodoo2Config;
        } sstBoard;
    } SST;	// the embeded data
    //HashTable field_map;
    zend_object std;	// it is important that the zend_object goes last
} _GrSST;

void phpglide2x_register_grSST(INIT_FUNC_ARGS);

typedef struct _GrHwConfiguration {
    GrHwConfiguration grHwConfiguration;
    zend_object std;
} _GrHwConfiguration;

void phpglide2x_register_grHwConfiguration(INIT_FUNC_ARGS);

typedef struct _GrTmuVertex {
    GrTmuVertex grTmuVertex;
    zend_object std;
} _GrTmuVertex;

void phpglide2x_register_grTmuVertex(INIT_FUNC_ARGS);

typedef struct _GrVertex {
    uint16_t initialized_flags;
    GrVertex grVertex;
    zend_object std;
} _GrVertex;

void phpglide2x_register_grVertex(INIT_FUNC_ARGS);

void phpglide2x_register_structs(INIT_FUNC_ARGS);

#endif