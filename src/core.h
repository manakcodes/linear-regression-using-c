/*
// ========================================================================== //
file : src/core.h

description:
contains all the core functions required to compute linear regression equations

// ========================================================================== //
*/

// ========================================================================== //
// INCLUDES SECTION
// ========================================================================== //

#pragma once
#include "utility.h"

// ========================================================================== //
// structs SECTION
// ========================================================================== //

typedef struct
{
    size_t n;
    double *x;
    double *y;
    double mean_x;
    double mean_y;
    double variance_x;
    double variance_y;
    double std_x;
    double std_y;
    double covariance;
    double correlation_coefficient;
    double slope_x_on_y;
    double intercept_x_on_y;
    double slope_y_on_x;
    double intercept_y_on_x;
    double asked_x;
    double asked_y;
    double predicted_x;
    double predicted_y;
} LinearRegression;

// ========================================================================== //
// function prototypes section
// ========================================================================== //

LinearRegression *AllocateMemoryForStruct(size_t dataset_size);
void DeallocateMemoryOfStruct(LinearRegression *lin_reg);

double GetDataSetSum(double *x, size_t n);
double GetDataSetMean(double *x, size_t n);
double GetDataSetStandardDeviation(double *x, size_t n);
void ComputeDataSetCovariance(LinearRegression *lin_reg);
void ComputeDataSetCorrelationCoefficientR(LinearRegression *lin_reg);
void ComputeStatisticalParameters(LinearRegression *lin_reg);
void LinearRegressionYOnX(LinearRegression *lin_reg, double x0);
void LinearRegressionXOnY(LinearRegression *lin_reg, double y0);

// ========================================================================== //
// function bodies section
// ========================================================================== //

LinearRegression *AllocateMemoryForStruct(size_t dataset_size)
{
    LinearRegression *linear_regression = (LinearRegression *)malloc(sizeof(LinearRegression));

    if (linear_regression == NULL)
    {
        return NULL;
    }

    linear_regression->n = dataset_size;
    linear_regression->x = (double *)malloc(dataset_size * sizeof(double));
    linear_regression->y = (double *)malloc(dataset_size * sizeof(double));

    if (!linear_regression->x || !linear_regression->y)
    {
        free(linear_regression->x);
        free(linear_regression->y);
        free(linear_regression);
        return NULL;
    }

    return linear_regression;
}

void DeallocateMemoryOfStruct(LinearRegression *lin_reg)
{
    if (lin_reg == NULL)
    {
        return;
    }

    free(lin_reg->x);
    free(lin_reg->y);
    free(lin_reg);
}

double GetDataSetSum(double *x, size_t n)
{
    double sum = 0.0;

    for (size_t i = 0; i < n; i++)
    {
        sum += x[i];
    }

    return sum;
}

double GetDataSetMean(double *x, size_t n)
{
    return GetDataSetSum(x, n) / n;
}

double GetDataSetStandardDeviation(double *x, size_t n)
{
    double mean = GetDataSetMean(x, n);
    double sum = 0.0;
    for (size_t i = 0; i < n; i++)
    {
        sum += (x[i] - mean) * (x[i] - mean);
    }
    return sqrt(sum / n);
}

void ComputeDataSetCovariance(LinearRegression *lin_reg)
{
    double sum = 0.0;

    for (size_t i = 0; i < lin_reg->n; i++)
    {
        sum += (lin_reg->x[i] - lin_reg->mean_x) * (lin_reg->y[i] - lin_reg->mean_y);
    }

    lin_reg->covariance = sum / lin_reg->n;
}

void ComputeDataSetCorrelationCoefficientR(LinearRegression *lin_reg)
{
    if (IS_ZERO(lin_reg->std_x) || IS_ZERO(lin_reg->std_y))
    {
        lin_reg->correlation_coefficient = NAN;
    }

    else
    {
        lin_reg->correlation_coefficient = lin_reg->covariance / (lin_reg->std_x * lin_reg->std_y);
    }
}

void ComputeStatisticalParameters(LinearRegression *lin_reg)
{
    lin_reg->mean_x = GetDataSetMean(lin_reg->x, lin_reg->n);
    lin_reg->mean_y = GetDataSetMean(lin_reg->y, lin_reg->n);

    lin_reg->std_x = GetDataSetStandardDeviation(lin_reg->x, lin_reg->n);
    lin_reg->std_y = GetDataSetStandardDeviation(lin_reg->y, lin_reg->n);

    lin_reg->variance_x = lin_reg->std_x * lin_reg->std_x;
    lin_reg->variance_y = lin_reg->std_y * lin_reg->std_y;

    ComputeDataSetCovariance(lin_reg);
    ComputeDataSetCorrelationCoefficientR(lin_reg);

    lin_reg->slope_x_on_y = lin_reg->correlation_coefficient * (lin_reg->std_x / lin_reg->std_y);
    lin_reg->intercept_x_on_y = lin_reg->mean_x - lin_reg->slope_x_on_y * lin_reg->mean_y;

    lin_reg->slope_y_on_x = lin_reg->correlation_coefficient * (lin_reg->std_y / lin_reg->std_x);
    lin_reg->intercept_y_on_x = lin_reg->mean_y - lin_reg->slope_y_on_x * lin_reg->mean_x;
}

void LinearRegressionYOnX(LinearRegression *lin_reg, double x0)
{
    lin_reg->predicted_y = lin_reg->intercept_y_on_x + lin_reg->slope_y_on_x * x0;
}

void LinearRegressionXOnY(LinearRegression *lin_reg, double y0)
{
    lin_reg->predicted_x = lin_reg->intercept_x_on_y + lin_reg->slope_x_on_y * y0;
}
