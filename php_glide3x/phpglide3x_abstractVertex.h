#ifndef ABSTRACT_VERTEX_H
#define ABSTRACT_VERTEX_H

#include "stdafx.h"

extern zend_class_entry* abstractVertex_ce;

//macros to get the address of the scaler_embedded_t from zend_object and from zval
#define O_EMBEDDED_P(t, o) \
	((t*)((char*)(o) - XtOffsetOf(t, std)))

#define Z_EMBEDDED_P(t, zv) \
	O_EMBEDDED_P(t, Z_OBJ_P(zv))

typedef struct AbstractVertex_t {
    char layout[60];
} AbstractVertex_t;

typedef struct _AbstractVertex_t {
    AbstractVertex_t abstractVertex;	// the embeded data
    //HashTable field_map;
    zend_object std;	// it is important that the zend_object goes last
} _AbstractVertex_t;

void phpglide3x_register_abstractVertex(INIT_FUNC_ARGS);

#endif
