#ifndef STRUCT_H
#define STRUCT_H

#include "php.h"

extern zend_class_entry* grTMUConfig_ce;
extern zend_class_entry* grVoodooConfig_ce;
extern zend_class_entry* grSst96Config_ce;
extern zend_class_entry* grAT3DConfig_ce;
extern zend_class_entry* sST_ce;
extern zend_class_entry* grHwConfiguration_ce;

extern zend_class_entry* grTmuVertex_ce;
extern zend_class_entry* grVertex_ce;

void phpglide2x_register_structs(INIT_FUNC_ARGS);

#endif