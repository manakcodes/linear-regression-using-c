/*
// ========================================================================== //
file : src/io.h

description:
contains all the core functions required for I/O operations

// ========================================================================== //
*/

// ========================================================================== //
// INCLUDES SECTION
// ========================================================================== //

#pragma once
#include "core.h"

// ========================================================================== //
// MACROS and const DECLARATIONS SECTION
// ========================================================================== //

const char *RED = "\033[31m";
const char *BLUE = "\033[34m";
const char *GREEN = "\033[32m";
const char *CYAN = "\033[36m";
const char *MAGENTA = "\033[35m";
const char *PINK = "\033[95m";
const char *HOTPINK = "\033[38;5;205m";
const char *BOLD = "\033[1m";
const char *UNDERLINE = "\033[4m";
const char *RESET = "\033[0m";

const int HIGH_DELAY = 15000;
const int MEDIUM_DELAY = 12500;
const int LOW_DELAY = 10000;

// ========================================================================== //
// function prototypes section
// ========================================================================== //

void ChangeConsole(const char *color, const char *style);
void ResetConsole(void);
void TypePrint(const char *text, int delay_ums);
void ClearInputBuffer(void);
void PrintProjectGuide(void);
LinearRegression *InputData(void);
void PrintDataSet(const LinearRegression *lin_reg);
void PrintRegressionEquations(const LinearRegression *lin_reg);
void PrintStatisticalParameters(const LinearRegression *lin_reg);
void PrintExitAnimation(void);

// ========================================================================== //
// function bodies section
// ========================================================================== //

void ChangeConsole(const char *color, const char *style)
{
    if (color != NULL)
    {
        printf("%s", color);
    }

    if (style != NULL)
    {
        printf("%s", style);
    }
}

void ResetConsole(void)
{
    printf("%s", RESET);
}

void TypePrint(const char *text, int delay_ums)
{
    while (*text)
    {
        putchar(*text++);
        fflush(stdout);
        usleep(delay_ums);
    }
}

void ClearInputBuffer(void)
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        // ===== //
    }
}

void PrintProjectGuide(void)
{
    ChangeConsole(HOTPINK, NULL);
    TypePrint("====================================================\n", HIGH_DELAY);
    TypePrint("            linear-regression-using-c\n", HIGH_DELAY);
    TypePrint("====================================================\n\n", HIGH_DELAY);

    ChangeConsole(PINK, NULL);

    TypePrint("A minimal, lightweight implementation of simple linear\nregression using C, built from scratch using only the C\nstandard library.\n\n", HIGH_DELAY);

    ResetConsole();

    ChangeConsole(BLUE, NULL);
    TypePrint("the project will prompt you to enter:\n", LOW_DELAY);

    ChangeConsole(GREEN, NULL);
    TypePrint("\t- sizeof the dataset\n", LOW_DELAY);
    TypePrint("\t- enter the dataset (x[i], y[i])\n", LOW_DELAY);
    TypePrint("\t- enter the value of x for which you want to predict y\n", LOW_DELAY);
    TypePrint("\t- enter the value of y for which you want to predict x\n", LOW_DELAY);

    printf("\n\n");

    ChangeConsole(BLUE, NULL);
    TypePrint("then it prints the:\n", LOW_DELAY);

    ChangeConsole(GREEN, NULL);
    TypePrint("\t- dataset in a tabular manner\n", LOW_DELAY);
    TypePrint("\t- regression equations [x on y] and [y on x]\n", LOW_DELAY);
    TypePrint("\t- value of predicted y for input x\n", LOW_DELAY);
    TypePrint("\t- value of predicted x for input y\n", LOW_DELAY);
    TypePrint("\t- statistical parameters in a tabular manner\n", LOW_DELAY);

    printf("\n\n");

    ChangeConsole(RED, BOLD);
    TypePrint("NOTE -> in case of invalid operations it displays nan values\n", LOW_DELAY);

    ChangeConsole(HOTPINK, NULL);
    TypePrint("\n==================================================\n\n", HIGH_DELAY);
    ResetConsole();
}

LinearRegression *InputData(void)
{
    ChangeConsole(BLUE, NULL);
    size_t dataset_size = 0;
    printf("enter the size of the dataset: ");
    scanf("%zu", &dataset_size);

    printf("\n");

    LinearRegression *lin_reg = AllocateMemoryForStruct(dataset_size);

    printf("\nenter dataset x[i] below:\n");

    ChangeConsole(GREEN, NULL);
    for (size_t i = 0; i < dataset_size; i++)
    {
        printf("x[%zu] = ", i + 1);
        scanf("%lf", &lin_reg->x[i]);
    }

    ChangeConsole(BLUE, NULL);
    printf("\ndataset x[i] completed\n\n");

    printf("\nenter dataset y[i] below:\n");

    ChangeConsole(GREEN, NULL);
    for (size_t i = 0; i < dataset_size; i++)
    {
        printf("y[%zu] = ", i + 1);
        scanf("%lf", &lin_reg->y[i]);
    }

    ChangeConsole(BLUE, NULL);
    printf("\ndataset x[i] completed\n\n");

    ResetConsole();
    return lin_reg;
}

void PrintDataSet(const LinearRegression *lin_reg)
{
    printf("\n\n");
    printf("+-------+------------------+------------------+\n");
    printf("| index |        x[i]      |        y[i]      |\n");
    printf("+-------+------------------+------------------+\n");
    for (size_t i = 0; i < lin_reg->n; i++)
    {
        printf("| %5zu | %16.4f | %16.4f |\n", i + 1, lin_reg->x[i], lin_reg->y[i]);
    }
    printf("+-------+------------------+------------------+\n");
}

void PrintRegressionEquations(const LinearRegression *lin_reg)
{
    printf("\n\n");
    printf("+----------------------------------------------+\n");
    printf("|        linear regression equations           |\n");
    printf("+----------------------------------------------+\n");
    printf(" x on y : x = %-8.4f + %-8.4f * y\n", lin_reg->intercept_x_on_y, lin_reg->slope_x_on_y);
    printf(" y on x : y = %-8.4f + %-8.4f * x\n", lin_reg->intercept_y_on_x, lin_reg->slope_y_on_x);
    printf("+----------------------------------------------+\n");
}

void PrintStatisticalParameters(const LinearRegression *lin_reg)
{
    printf("\n\n");
    printf("+----------------------------+------------------+\n");
    printf("| parameter                  | value            |\n");
    printf("+----------------------------+------------------+\n");

    printf("| dataset_size               | %-16zu |\n", lin_reg->n);
    printf("| mean_x                     | %-16.4f |\n", lin_reg->mean_x);
    printf("| mean_y                     | %-16.4f |\n", lin_reg->mean_y);
    printf("| variance_x                 | %-16.4f |\n", lin_reg->variance_x);
    printf("| variance_y                 | %-16.4f |\n", lin_reg->variance_y);
    printf("| standard_deviation_x       | %-16.4f |\n", lin_reg->std_x);
    printf("| standard_deviation_y       | %-16.4f |\n", lin_reg->std_y);
    printf("| covariance                 | %-16.4f |\n", lin_reg->covariance);
    printf("| correlation_coefficient    | %-16.4f |\n", lin_reg->correlation_coefficient);
    printf("| slope_x_on_y               | %-16.4f |\n", lin_reg->slope_x_on_y);
    printf("| intercept_x_on_y           | %-16.4f |\n", lin_reg->intercept_x_on_y);
    printf("| slope_y_on_x               | %-16.4f |\n", lin_reg->slope_y_on_x);
    printf("| intercept_y_on_x           | %-16.4f |\n", lin_reg->intercept_y_on_x);
    printf("| asked_x                    | %-16.4f |\n", lin_reg->asked_x);
    printf("| asked_y                    | %-16.4f |\n", lin_reg->asked_y);
    printf("| predicted_x                | %-16.4f |\n", lin_reg->predicted_x);
    printf("| predicted_y                | %-16.4f |\n", lin_reg->predicted_y);
    printf("+----------------------------+------------------+\n");
}

void PrintExitAnimation(void)
{
    ChangeConsole(RED, BOLD);
    TypePrint("========== EXIT ==========\n", 2 * HIGH_DELAY);
    ResetConsole();
}
