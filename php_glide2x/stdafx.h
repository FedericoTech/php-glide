#ifndef STDAFX_H
#define STDAFX_H
#include <glide.h>
#include <stdint.h>
#include <php.h>
#include <Zend/zend_enum.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>
#include <Zend/zend_globals.h>

#include "phpglide2x_arginfo.h"

ZEND_BEGIN_MODULE_GLOBALS(phpglide2x)
GrVertex* tmp_vertices;
uint32_t  tmp_capacity;
ZEND_END_MODULE_GLOBALS(phpglide2x)

ZEND_EXTERN_MODULE_GLOBALS(phpglide2x)

#ifdef ZTS
# define GLIDE_G(v) TSRMG(phpglide2x_globals_id, zend_phpglide2x_globals *, v)
#else
# define GLIDE_G(v) (phpglide2x_globals.v)
#endif

#endif