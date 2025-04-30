
#include "phpglide2x_draw.h"
#include "phpglide2x_structs.h"

PHP_FUNCTION(grDrawTriangle)
{
	zend_object* a = NULL;
	zend_object* b = NULL;
	zend_object* c = NULL;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJ_OF_CLASS(a, grVertex_ce)
		Z_PARAM_OBJ_OF_CLASS(b, grVertex_ce)
		Z_PARAM_OBJ_OF_CLASS(c, grVertex_ce)
	ZEND_PARSE_PARAMETERS_END();

	GrVertex* vtx0 = NULL, * vtx1 = NULL, * vtx2 = NULL;

	if (a) {
		vtx0 = &O_EMBEDDED_P(_GrVertex, a)->grVertex;
	}

	if (b) {
		vtx1 = &O_EMBEDDED_P(_GrVertex, b)->grVertex;
	}

	if (c) {
		vtx2 = &O_EMBEDDED_P(_GrVertex, c)->grVertex;
	}

	grDrawTriangle(vtx0, vtx1, vtx2);
}
