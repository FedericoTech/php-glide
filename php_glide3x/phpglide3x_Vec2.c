#include "phpglide3x_Vec2.h"

zend_class_entry* vec2_ce;

ZEND_BEGIN_ARG_INFO_EX(arginfo___construct, 0, 0, 0)
    ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, x, IS_DOUBLE, 0, "0")
    ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, y, IS_DOUBLE, 0, "0")
ZEND_END_ARG_INFO()

PHP_METHOD(Vec2, __construct)
{
    double x = 0, y = 0;

    ZEND_PARSE_PARAMETERS_START(0, 2)
        Z_PARAM_OPTIONAL
        Z_PARAM_DOUBLE(x) // Expect a double parameter
        Z_PARAM_DOUBLE(y) // Expect a double parameter
    ZEND_PARSE_PARAMETERS_END();

    zend_update_property_double(
        vec2_ce, 
        Z_OBJ_P(getThis()), 
        "x", 
        sizeof("x") - 1, 
        x
    );

    zend_update_property_double(
        vec2_ce,
        Z_OBJ_P(getThis()),
        "y",
        sizeof("y") - 1,
        y
    );

    //php_printf("Vec2 constructor\n");
}

ZEND_BEGIN_ARG_INFO_EX(arginfo_myMethod, 0, 0, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(Vec2, myMethod)
{
    php_printf("Vec2::myMethod called\n");
}

void phpglide3x_register_gr_vec2_module(INIT_FUNC_ARGS)
{
    const zend_function_entry vec2_methods[] = {
        PHP_ME(Vec2, __construct, arginfo___construct, ZEND_ACC_PUBLIC)
        PHP_ME(Vec2, myMethod, arginfo_myMethod, ZEND_ACC_PUBLIC)
        PHP_FE_END
    };

    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "Vec2", vec2_methods);
    vec2_ce = zend_register_internal_class(&ce);

    // Declare properties
    zend_declare_property_double(
        vec2_ce, 
        "x",                // name
        sizeof("x") - 1,    // name size
        10.0,                 // default value
        ZEND_ACC_PUBLIC     // access scope
    );
    
    zend_declare_property_double(
        vec2_ce, 
        "y",                // name
        sizeof("y") - 1,    // name size
        10.0,                 // default value
        ZEND_ACC_PUBLIC     // access scope
    );
}