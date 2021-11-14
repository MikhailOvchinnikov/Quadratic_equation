#define _CRT_SECURE_NO_WARNINGS
#define INF_NUMBER_OF_SOLUTIONS 100
#define EMPTY_SOLUTION 0

#include "quadratic_equation.h"
#include "test.h"


#include <stdio.h>


int main()
{
    TestQuadraticEquation();
    //Creating command array
    char command[5] = {};
    double x1 = 0;
    double x2 = 0;
    int solutions_cnt = 0;

    //Going first iteration without requests
    do
    {
        //Creating equation's coefficients variables
        double first = 0;
        double second = 0;
        double third = 0;

        printf("Write three coefficients of quatered equation: ");

        //Reading information for beginning variables
        //If read bad variables, programm will repeat request
        while (scanf("%lf", &first) == 0 || scanf("%lf", &second) == 0 || scanf("%lf", &third) == 0)
        {
            printf("Wrong data, repeat, please: ");
            while (getchar() != '\n');
        }

        solutions_cnt = SolutionQuadraticEquation(first, second, third, &x1, &x2);

        if (solutions_cnt == EMPTY_SOLUTION)
        {
            printf("Empty solutions\n");
        }
        else if(solutions_cnt == INF_NUMBER_OF_SOLUTIONS)
        {
            printf("Infinite solutions\n");
        }
        else if(solutions_cnt == 1)
        {
            printf("%f\n", x1);
        }
        else
        {
            printf("%f, %f\n", x1, x2);
        }

        //Reading second command for new equation
        printf("Next equation - \"next\", finish - any symbol: ");
        scanf("%s", &command);
    } while (CheckCommand(command));
}

