
#include "stdafx.h"
#include "phpglide2x_structs.h"

static inline GrVertex* glide_ensure_vertex_buffer(uint32_t needed)
{
	if (needed > GLIDE_G(tmp_capacity)) {

		uint32_t new_capacity = needed;

		if (GLIDE_G(tmp_vertices)) {

			GLIDE_G(tmp_vertices) = erealloc(
				GLIDE_G(tmp_vertices),
				sizeof(GrVertex) * new_capacity
			);
		}
		else {
			GLIDE_G(tmp_vertices) = emalloc(
				sizeof(GrVertex) * new_capacity
			);
		}

		GLIDE_G(tmp_capacity) = new_capacity;
	}

	return GLIDE_G(tmp_vertices);
}

PHP_FUNCTION(grAADrawLine)
{
	zend_object* zva = NULL;
	zend_object* zvb = NULL;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJ_OF_CLASS(zva, grVertex_ce)
		Z_PARAM_OBJ_OF_CLASS(zvb, grVertex_ce)
		ZEND_PARSE_PARAMETERS_END();

	grAADrawLine(
		gr_vertex_auto_flush(zva),
		gr_vertex_auto_flush(zvb)
	);
}

PHP_FUNCTION(grAADrawPoint)
{
	zend_object* p = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(p, grVertex_ce)
		ZEND_PARSE_PARAMETERS_END();

	grAADrawPoint(gr_vertex_auto_flush(p));
}

PHP_FUNCTION(grAADrawPolygon)
{
	zend_long nVerts;
	zval* ilist = NULL;
	zval* vlist = NULL;
	
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(nVerts)
		Z_PARAM_ARRAY(ilist)
		Z_PARAM_ARRAY(vlist)
	ZEND_PARSE_PARAMETERS_END();

	// Allocate memory
	int* indices = emalloc(sizeof(int) * zend_array_count(Z_ARRVAL_P(ilist)));

	zend_long vertex_count = zend_array_count(Z_ARRVAL_P(vlist));

	GrVertex* vertices = glide_ensure_vertex_buffer(vertex_count);
	//GrVertex* vertices = emalloc(sizeof(GrVertex) * vertex_count);

	zval* val;
	zend_ulong i = 0;

	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(ilist), val) {

		int index;

		ZVAL_DEREF(val);

		//if it's an integer...
		if (Z_TYPE_P(val) == IS_LONG) {
			index = Z_LVAL_P(val);

		//we check whether the element isn't an integer
		} else if (
			Z_TYPE_P(val) == IS_STRING 
			&& !is_numeric_string(Z_STRVAL_P(val), Z_STRLEN_P(val), NULL, NULL, 0)
		) {
			//we release the resources
			efree(indices);
			//efree(vertices);
			zend_throw_exception(NULL, "ilist must contain only integers", 0);
			return;
		//we make it integer
		}
		else {
			index = zval_get_long(val);
		}

		//we check the index is valid
		if (index < 0 || index > vertex_count) {
			efree(indices);
			//efree(vertices);
			zend_throw_exception(NULL, "ilist contains an invalid number. it must be between 0 to nVerts", 0);
		}

		indices[i++] = index;

	} ZEND_HASH_FOREACH_END();

	i = 0;

	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(vlist), val) {

		ZVAL_DEREF(val);

		if (Z_TYPE_P(val) != IS_OBJECT 
			|| !instanceof_function(Z_OBJCE_P(val), grVertex_ce)
		) {
			efree(indices);
			//efree(vertices);
			zend_throw_exception(NULL, "Array must contain only instances of GrVertex", 0);
			return;
		}


		memcpy(
			&vertices[i++], 
			gr_vertex_auto_flush(Z_OBJ_P(val)), 
			sizeof(GrVertex)
		);

	} ZEND_HASH_FOREACH_END();

	grAADrawPolygon(nVerts, indices, vertices);

	efree(indices);
	//efree(vertices);
}

PHP_FUNCTION(grAADrawPolygonVertexList)
{
	zend_long nVerts;
	zval* vlist = NULL;


	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(nVerts)
		Z_PARAM_ARRAY(vlist)
	ZEND_PARSE_PARAMETERS_END();

	if (nVerts < 0 || nVerts > (zend_long) zend_array_count(Z_ARRVAL_P(vlist))) {
		zend_throw_exception(NULL, "nVerts must be between 0 to vList count", 0);
		return;
	}

	// Allocate memory
	GrVertex* vertices = glide_ensure_vertex_buffer(nVerts);
	//GrVertex* vertices = emalloc(sizeof(GrVertex) * nVerts);

	zval* val;
	zend_ulong i = 0;
	
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(vlist), val) {

		ZVAL_DEREF(val); // <-- add this before your checks
	
		if (Z_TYPE_P(val) != IS_OBJECT
			|| !instanceof_function(Z_OBJCE_P(val), grVertex_ce)
		) {
			//efree(vertices);
			zend_throw_exception(NULL, "Array must contain only instances of GrVertex", 0);
			return;
		}

		memcpy(
			&vertices[i++], 
			gr_vertex_auto_flush(Z_OBJ_P(val)), 
			sizeof(GrVertex)
		);

	} ZEND_HASH_FOREACH_END();

	grAADrawPolygonVertexList(nVerts, vertices);

	//efree(vertices);

	//RETURN_NULL();
}

PHP_FUNCTION(grAADrawTriangle)
{
	zend_object* a = NULL;
	zend_object* b = NULL;
	zend_object* c = NULL;
	zend_bool antialiasAB;
	zend_bool antialiasBC;
	zend_bool antialiasCA;

	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_OBJ_OF_CLASS(a, grVertex_ce)
		Z_PARAM_OBJ_OF_CLASS(b, grVertex_ce)
		Z_PARAM_OBJ_OF_CLASS(c, grVertex_ce)
		Z_PARAM_BOOL(antialiasAB)
		Z_PARAM_BOOL(antialiasBC)
		Z_PARAM_BOOL(antialiasCA)
		ZEND_PARSE_PARAMETERS_END();

	grAADrawTriangle(
		gr_vertex_auto_flush(a),
		gr_vertex_auto_flush(b),
		gr_vertex_auto_flush(c),
		antialiasAB, 
		antialiasBC, 
		antialiasCA
	);
}

PHP_FUNCTION(grDrawLine)
{
	zend_object* zva = NULL;
	zend_object* zvb = NULL;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJ_OF_CLASS(zva, grVertex_ce)
		Z_PARAM_OBJ_OF_CLASS(zvb, grVertex_ce)
		ZEND_PARSE_PARAMETERS_END();

	grDrawLine(
		gr_vertex_auto_flush(zva),
		gr_vertex_auto_flush(zvb)
	);
}

PHP_FUNCTION(grDrawPlanarPolygon)
{
	zend_long nVerts;
	zval* ilist = NULL;
	zval* vlist = NULL;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(nVerts)
		Z_PARAM_ARRAY(ilist)
		Z_PARAM_ARRAY(vlist)
		ZEND_PARSE_PARAMETERS_END();

	// Allocate memory
	int* indices = emalloc(sizeof(int) * nVerts);

	zend_long vertex_count = zend_array_count(Z_ARRVAL_P(vlist));

	GrVertex* vertices = glide_ensure_vertex_buffer(vertex_count);
	//GrVertex* vertices = emalloc(sizeof(GrVertex) * vertex_count);

	zval* val;
	zend_ulong i = 0;

	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(ilist), val) {

		int index;

		ZVAL_DEREF(val);

		//if it's an integer...
		if (Z_TYPE_P(val) == IS_LONG) {
			index = Z_LVAL_P(val);

			//we check whether the element isn't an integer
		}
		else if (
			Z_TYPE_P(val) == IS_STRING
			&& !is_numeric_string(Z_STRVAL_P(val), Z_STRLEN_P(val), NULL, NULL, 0)
		) {
			//we release the resources
			efree(indices);
			//efree(vertices);
			zend_throw_exception(NULL, "ilist must contain only integers", 0);
			return;
			//we make it integer
		}
		else {
			index = zval_get_long(val);
		}

		//we check the index is valid
		if (index < 0 || index > nVerts || index > vertex_count) {
			efree(indices);
			//efree(vertices);
			zend_throw_exception(NULL, "ilist must contain invalid number. must be between 0 to nVerts", 0);
		}

		indices[i++] = index;

	} ZEND_HASH_FOREACH_END();

	i = 0;

	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(vlist), val) {

		ZVAL_DEREF(val);

		if (Z_TYPE_P(val) != IS_OBJECT
			|| !instanceof_function(Z_OBJCE_P(val), grVertex_ce)
		) {
			efree(indices);
			//efree(vertices);
			zend_throw_exception(NULL, "Array must contain only instances of GrVertex", 0);
			return;
		}

		memcpy(
			&vertices[i++], 
			gr_vertex_auto_flush(Z_OBJ_P(val)),
			sizeof(GrVertex)
		);

	} ZEND_HASH_FOREACH_END();

	grDrawPlanarPolygon(nVerts, indices, vertices);

	efree(indices);
	//efree(vertices);
}

PHP_FUNCTION(grDrawPlanarPolygonVertexList)
{
	zend_long nVerts;
	zval* vlist = NULL;


	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(nVerts)
		Z_PARAM_ARRAY(vlist)
		ZEND_PARSE_PARAMETERS_END();

	if (nVerts < 0 || nVerts >(zend_long) zend_array_count(Z_ARRVAL_P(vlist))) {
		zend_throw_exception(NULL, "nVerts must be between 0 to vList count", 0);
		return;
	}

	// Allocate memory
	GrVertex* vertices = glide_ensure_vertex_buffer(nVerts);
	//GrVertex* vertices = emalloc(sizeof(GrVertex) * nVerts);

	zval* val;
	zend_ulong i = 0;

	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(vlist), val) {

		ZVAL_DEREF(val);

		if (Z_TYPE_P(val) != IS_OBJECT
			|| !instanceof_function(Z_OBJCE_P(val), grVertex_ce)
			) {
			//efree(vertices);
			zend_throw_exception(NULL, "Array must contain only instances of GrVertex", 0);
			return;
		}

		memcpy(
			&vertices[i++], 
			gr_vertex_auto_flush(Z_OBJ_P(val)),
			sizeof(GrVertex)
		);

	} ZEND_HASH_FOREACH_END();

	grDrawPlanarPolygonVertexList(nVerts, vertices);

	//efree(vertices);
}

PHP_FUNCTION(grDrawPoint)
{
	zend_object* p = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(p, grVertex_ce)
		ZEND_PARSE_PARAMETERS_END();

	grDrawPoint(gr_vertex_auto_flush(p));
}

PHP_FUNCTION(grDrawPolygon)
{
	zend_long nVerts;
	zval* ilist = NULL;
	zval* vlist = NULL;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(nVerts)
		Z_PARAM_ARRAY(ilist)
		Z_PARAM_ARRAY(vlist)
		ZEND_PARSE_PARAMETERS_END();

	// Allocate memory
	int* indices = emalloc(sizeof(int) * zend_array_count(Z_ARRVAL_P(ilist)));

	zend_long vertex_count = zend_array_count(Z_ARRVAL_P(vlist));

	GrVertex* vertices = glide_ensure_vertex_buffer(vertex_count);
	//GrVertex* vertices = emalloc(sizeof(GrVertex) * vertex_count);

	zval* val;
	zend_ulong i = 0;

	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(ilist), val) {

		int index;

		ZVAL_DEREF(val);

		//if it's an integer...
		if (Z_TYPE_P(val) == IS_LONG) {
			index = Z_LVAL_P(val);

			//we check whether the element isn't an integer
		}
		else if (
			Z_TYPE_P(val) == IS_STRING
			&& !is_numeric_string(Z_STRVAL_P(val), Z_STRLEN_P(val), NULL, NULL, 0)
		) {
			//we release the resources
			efree(indices);
			//efree(vertices);
			zend_throw_exception(NULL, "ilist must contain only integers", 0);
			return;
			//we make it integer
		}
		else {
			index = zval_get_long(val);
		}

		//we check the index is valid
		if (index < 0 || index > vertex_count) {
			efree(indices);
			//efree(vertices);
			zend_throw_exception(NULL, "ilist contains an invalid number. it must be between 0 to nVerts", 0);
		}

		indices[i++] = index;

	} ZEND_HASH_FOREACH_END();

	i = 0;
	
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(vlist), val) {

		ZVAL_DEREF(val);

		if (Z_TYPE_P(val) != IS_OBJECT
			|| !instanceof_function(Z_OBJCE_P(val), grVertex_ce)
		) {
			efree(indices);
			//efree(vertices);
			zend_throw_exception(NULL, "Array must contain only instances of GrVertex", 0);
			return;
		}

		memcpy(
			&vertices[i++], 
			gr_vertex_auto_flush(Z_OBJ_P(val)),
			sizeof(GrVertex)
		);

	} ZEND_HASH_FOREACH_END();

	grDrawPolygon(nVerts, indices, vertices);

	efree(indices);
	//efree(vertices);
}

PHP_FUNCTION(grDrawPolygonVertexList)
{
	zend_long nVerts;
	zval* vlist = NULL;


	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(nVerts)
		Z_PARAM_ARRAY(vlist)
		ZEND_PARSE_PARAMETERS_END();

	if (nVerts < 0 || nVerts >(zend_long) zend_array_count(Z_ARRVAL_P(vlist))) {
		zend_throw_exception(NULL, "nVerts must be between 0 to vList count", 0);
		return;
	}

	// Allocate memory
	//GrVertex* vertices = emalloc(sizeof(GrVertex) * nVerts);
	GrVertex* vertices = glide_ensure_vertex_buffer(nVerts);

	zval* val;
	zend_ulong i = 0;

	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(vlist), val) {

		ZVAL_DEREF(val);

		if (Z_TYPE_P(val) != IS_OBJECT
			|| !instanceof_function(Z_OBJCE_P(val), grVertex_ce)
		) {
			//efree(vertices);
			zend_throw_exception(NULL, "Array must contain only instances of GrVertex", 0);
			return;
		}

		memcpy(
			&vertices[i++], 
			gr_vertex_auto_flush(Z_OBJ_P(val)),
			sizeof(GrVertex)
		);

	} ZEND_HASH_FOREACH_END();

	grDrawPolygonVertexList(nVerts, vertices);

	//efree(vertices);
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

	grDrawTriangle(
		gr_vertex_auto_flush(a),
		gr_vertex_auto_flush(b),
		gr_vertex_auto_flush(c)
	);
}
