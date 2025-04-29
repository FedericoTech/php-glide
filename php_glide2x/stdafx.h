#ifndef STDAFX_H
#define STDAFX_H

#include <glide.h>
#include <stdint.h>
#include <php.h>
#include <Zend/zend_enum.h>

#include "phpglide2x_arginfo.h"

#define SENTINEL_INT      INT32_MAX
#define SENTINEL_UINT     UINT32_MAX
#define SENTINEL_LONG     INT64_MAX
#define SENTINEL_FLOAT    NAN
#define SENTINEL_DOUBLE   NAN
#define SENTINEL_PTR      NULL

#define IS_UNSET_INT(x)   ((x) == SENTINEL_INT)
#define IS_UNSET_UINT(x)  ((x) == SENTINEL_UINT)
#define IS_UNSET_LONG(x)  ((x) == SENTINEL_LONG)
#define IS_UNSET_FLOAT(x) isnan(x)
#define IS_UNSET_DOUBLE(x) isnan(x)
#define IS_UNSET_PTR(x)   ((x) == SENTINEL_PTR)

#endif