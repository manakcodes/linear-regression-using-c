/*
// ========================================================================== //
file : src/utility.h

description:
contains all the standard C libary headers linked into it and some functions 
to compare values against the tolerance value EPSILON

// ========================================================================== //
*/

// ========================================================================== //
// INCLUDES SECTION
// ========================================================================== //

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

// ========================================================================== //
// macros SECTION
// ========================================================================== //

#define EPSILON 1E-4;

// ========================================================================== //
// function prototypes
// ========================================================================== //

bool IS_NAN(double x);
bool IS_ZERO(double x);
bool IS_ONE(double x);
bool IS_POSITIVE(double x);
bool IS_NEGATIVE(double x);
bool IS_EQUAL(double a, double b);
bool IS_GREATER(double a, double b);
bool IS_LESS(double a, double b);
bool IS_GREATER_THAN_EQUAL_TO(double a, double b);
bool IS_LESS_THAN_EQUAL_TO(double a, double b);
bool IS_INVALID(double x);

// ========================================================================== //
// function bodies
// ========================================================================== //

bool IS_NAN(double x)
{
    return isnan(x);
}

bool IS_ZERO(double x)
{
    return fabs(x) < EPSILON;
}

bool IS_INVALID(double x)
{
    return IS_NAN(x) || IS_ZERO(x);
}

bool IS_ONE(double x)
{
    return fabs(x - 1.0000) < EPSILON;
}

bool IS_POSITIVE(double x)
{
    return x > EPSILON;
}

bool IS_NEGATIVE(double x)
{
    return x < -EPSILON;
}

bool IS_EQUAL(double a, double b)
{
    return fabs(a - b) < EPSILON;
}

bool IS_GREATER(double a, double b)
{
    return (a - b) >= EPSILON;
}

bool IS_LESS(double a, double b)
{
    return (b - a) > EPSILON;
}

bool IS_GREATER_THAN_EQUAL_TO(double a, double b)
{
    return (a > b) || IS_EQUAL(a, b);
}

bool IS_LESS_THAN_EQUAL_TO(double a, double b)
{
    return (a < b) || IS_EQUAL(a, b);
}
