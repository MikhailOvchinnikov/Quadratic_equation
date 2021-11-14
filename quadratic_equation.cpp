
#define EPS 0.00000000001
#include "quadratic_equation.h"
#include <stdio.h>
#include <assert.h>

int SolutionQuadraticEquation(const double first, const double second, const double third, double* x1, double* x2)
{
    assert(x1 != NULL);
    assert(x1 != x2);
    assert(isfinite(first));

    double mod_f = fabs(first);
    double mod_s = fabs(second);
    double mod_th = fabs(third);

    //Make infinite and empty solutions
    if (mod_f < EPS && mod_s < EPS)
    {
        if (mod_th < EPS)
        {
            *x1 = *x2 = 0;
            return 100;
        }
        else if (mod_th >= EPS)
        {
            *x1 = *x2 = 0;
            return 0;
        }
    }
    else if (mod_f < EPS && mod_s >= EPS)
    {
        *x1 = -third / second;
        *x2 = *x1;
        CheckMinusZero(x1, x2);
        return 1;
    }

    //Count descriminant
    double D = Discriminant(first, second, third);
    double mod_D = fabs(D);
    if (D < -EPS)
    {
        *x1 = *x2 = 0;
        return 0;
    }

    //Make equation for descriminant
    if(mod_D < EPS)
    {
        *x1 = -second / (2 * first);
        *x2 = *x1;
        CheckMinusZero(x1, x2);
        return 1;
    }
    else
    {

        *x1 = (-second - sqrt(D)) / (2 * first);
        *x2 = (-second + sqrt(D)) / (2 * first);
        CheckMinusZero(x1, x2);
        return 2;
    }
}


inline double Discriminant(const double f, const double s, const double t)
{
    return s * s - 4 * f * t;
}


bool CheckCommand(const char command[])
{
    assert(command != NULL);
    return !strcmp("next", command);
}

void CheckMinusZero(double* x1, double* x2)
{
    if (*x1 != 0 && *x2 != 0)
    {
        return;
    }
    else
    {
        *x1 = fabs(*x1);
        *x2 = fabs(*x2);
    }
}
