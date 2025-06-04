#include "phpglide2x_structs.h"

zend_class_entry* gr_flushable_ce;

void phpglide2x_register_gr_flushable(INIT_FUNC_ARGS)
{
	gr_flushable_ce = register_class_flushable();
}