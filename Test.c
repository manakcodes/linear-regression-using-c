#include "linreg.h"

void TestCase(void);

int main(void)
{
    TestCase();
    return 0;
}

void TestCase(void)
{
    ChangeConsole(PINK, NULL);
    size_t dataset_size = 5;

    {
        LinearRegression *lin_reg = AllocateMemoryForStruct(dataset_size);

        for (size_t i = 0; i < dataset_size; i++)
        {
            lin_reg->x[i] = lin_reg->y[i] = i + 1;
        }

        ComputeStatisticalParameters(lin_reg);

        if (IS_ONE(lin_reg->correlation_coefficient))
        {
            printf("correlation -> [1.0000]  :: test 1 passed !!\n");
        }

        else
        {
            printf("correlation -> [1.0000]  :: test 1 FAILED !!\n");
        }

        DeallocateMemoryOfStruct(lin_reg);
    }

    {
        LinearRegression *lin_reg = AllocateMemoryForStruct(dataset_size);

        for (size_t i = 0; i < dataset_size; i++)
        {
            lin_reg->x[i] = i + 1;
            lin_reg->y[i] = dataset_size - i;
        }

        ComputeStatisticalParameters(lin_reg);

        if (IS_NEGATIVE(lin_reg->correlation_coefficient))
        {
            printf("correlation -> [-1.0000] :: test 2 passed !!\n");
        }

        else
        {
            printf("correlation -> [-1.0000]  :: test 2 FAILED !!\n");
        }

        DeallocateMemoryOfStruct(lin_reg);
    }

    {
        LinearRegression *lin_reg = AllocateMemoryForStruct(dataset_size);

        for (size_t i = 0; i < dataset_size; i++)
        {
            lin_reg->x[i] = i + 1;
            lin_reg->y[i] = 5;
        }

        ComputeStatisticalParameters(lin_reg);

        if (IS_INVALID(lin_reg->correlation_coefficient))
        {
            printf("correlation -> [0.0000]  :: test 3 passed !!\n");
        }

        else
        {
            printf("correlation -> [0.0000]  :: test 3 FAILED !!\n");
        }

        DeallocateMemoryOfStruct(lin_reg);
    }

    ResetConsole();
}
