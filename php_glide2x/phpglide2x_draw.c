
#include "phpglide2x_draw.h"
#include "phpglide2x_structs.h"

PHP_FUNCTION(grAADrawLine)
{
	zend_object* va = NULL;
	zend_object* vb = NULL;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJ_OF_CLASS(va, grVertex_ce)
		Z_PARAM_OBJ_OF_CLASS(vb, grVertex_ce)
		ZEND_PARSE_PARAMETERS_END();

	GrVertex* vtx0 = NULL, * vtx1 = NULL;

	if (va) {
		vtx0 = &O_EMBEDDED_P(_GrVertex, va)->grVertex;

		/*
		php_printf(
			"x: %f, y: %f, z: %f, r: %f, g: %f, b: %f, ooz: %f, a: %f, oow: %f\n",
			vtx0->x,
			vtx0->y,
			vtx0->z,

			vtx0->r,
			vtx0->g,
			vtx0->b,

			vtx0->ooz,
			vtx0->a,
			vtx0->oow
		);
		*/
	}

	if (vb) {
		vtx1 = &O_EMBEDDED_P(_GrVertex, vb)->grVertex;
	}

	grAADrawLine(vtx0, vtx1);
}

PHP_FUNCTION(grAADrawPoint)
{
	zend_object* p = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(p, grVertex_ce)
		ZEND_PARSE_PARAMETERS_END();

	GrVertex* vtx0 = NULL;

	if (p) {
		vtx0 = &O_EMBEDDED_P(_GrVertex, p)->grVertex;
	}

	grAADrawPoint(vtx0);
}

PHP_FUNCTION(grAADrawPolygon)
{
}



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
		/*
		php_printf(
			"x: %f, y: %f, z: %f, r: %f, g: %f, b: %f, ooz: %f, a: %f, oow: %f\n",
			vtx0->x,
			vtx0->y,
			vtx0->z,

			vtx0->r,
			vtx0->g,
			vtx0->b,

			vtx0->ooz,
			vtx0->a,
			vtx0->oow
		);
		*/
	}

	if (b) {
		vtx1 = &O_EMBEDDED_P(_GrVertex, b)->grVertex;
	}

	if (c) {
		vtx2 = &O_EMBEDDED_P(_GrVertex, c)->grVertex;
	}

	grDrawTriangle(vtx0, vtx1, vtx2);
}
