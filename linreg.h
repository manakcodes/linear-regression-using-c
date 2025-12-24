// ========================================================================== //
// INCLUDES SECTION
// ========================================================================== //

#pragma once
#include "src/utility.h"
#include "src/core.h"
#include "src/io.h"

// ========================================================================== //
// function prototypes section
// ========================================================================== //

// master method to run the project
void execute(void);

// ========================================================================== //
// function bodies sections
// ========================================================================== //

void execute(void)
{
    PrintProjectGuide();

    while (1)
    {
        ChangeConsole(BLUE, NULL);

        LinearRegression *lin_reg = InputData();

        if (lin_reg == NULL)
        {
            ChangeConsole(RED, BOLD);
            TypePrint("memory allocation failed !!\n", HIGH_DELAY);
            ResetConsole();
            return;
        }

        ComputeStatisticalParameters(lin_reg);

        ChangeConsole(CYAN, NULL);
        PrintDataSet(lin_reg);
        ResetConsole();

        ChangeConsole(HOTPINK, NULL);
        PrintRegressionEquations(lin_reg);
        ResetConsole();

        if (IS_INVALID(lin_reg->slope_x_on_y) || IS_INVALID(lin_reg->slope_y_on_x))
        {
            ChangeConsole(RED, BOLD);
            printf("\ninvalid regression parameters\nno correlation\n[nan values]\n\n");
            ResetConsole();
            DeallocateMemoryOfStruct(lin_reg);

            while (1)
            {
                ChangeConsole(BLUE, NULL);

                char choice;
                printf("\ncontinue with a new dataset ? [Y, y, N, n]: ");

                ClearInputBuffer();
                scanf("%c", &choice);
                ClearInputBuffer();

                if (choice == 'Y' || choice == 'y')
                {
                    ResetConsole();
                    break;
                }

                else if (choice == 'N' || choice == 'n')
                {
                    PrintExitAnimation();
                    return;
                }

                else
                {
                    ChangeConsole(RED, BOLD);
                    printf("\ninvalid choice ! please enter a valid choice\nvalid choice : [Y, y, N, n]\n\n");
                    ResetConsole();
                    continue;
                }
            }
            continue;
        }

        ChangeConsole(BLUE, NULL);

        printf("\nenter x to predict y: ");
        scanf("%lf", &lin_reg->asked_x);

        ClearInputBuffer();

        ChangeConsole(GREEN, NULL);

        LinearRegressionYOnX(lin_reg, lin_reg->asked_x);
        printf("[predicted y = %.4lf for x = %.4lf]\n", lin_reg->predicted_y, lin_reg->asked_x);

        ChangeConsole(BLUE, NULL);

        printf("\nenter y to predict x: ");
        scanf("%lf", &lin_reg->asked_y);

        ClearInputBuffer();

        ChangeConsole(GREEN, NULL);

        LinearRegressionXOnY(lin_reg, lin_reg->asked_y);
        printf("[predicted x = %.4lf for y = %.4lf]\n", lin_reg->predicted_x, lin_reg->asked_y);

        ResetConsole();

        ChangeConsole(PINK, NULL);

        PrintStatisticalParameters(lin_reg);
        DeallocateMemoryOfStruct(lin_reg);

        while (1)
        {
            ChangeConsole(BLUE, NULL);

            char choice;
            printf("\ncontinue with a new dataset ? [Y, y, N, n]: ");

            scanf("%c", &choice);
            ClearInputBuffer();

            if (choice == 'Y' || choice == 'y')
            {
                ResetConsole();
                break;
            }

            else if (choice == 'N' || choice == 'n')
            {
                PrintExitAnimation();
                return;
            }

            else

            {
                ChangeConsole(RED, BOLD);
                printf("\ninvalid choice ! please enter a valid choice\nvalid choice : [Y, y, N, n]\n\n");
                ResetConsole();
                continue;
            }
        }
    }
}
