#pragma once
#include <math.h>
#include <string.h>
#include <stdlib.h>



/*Function for search solutions of quadratic
 *@param first coefficient x^2
 *@param second coefficient x
 *@param third free term
 *@return double array { first_root, second_root, number_root },
 *if one solution - 2 equal root and number 2
 *if no solution - { 0, 0, 0 }
 *if infinite solutions - { 100, 100, 100 }
 */
int SolutionQuadraticEquation(const double first_coef, const double second_coef, const double third_coef, double* x1, double* x2);


/*Count descriminant
 *@param f coefficient of x^2
 *@param s coefficient of x
 *@param t free term
 *@return value of descriminant
 */
inline double Discriminant(const double first_coef, const double second_coef, const double third_coef);


/*Compare read command with default command
 *@param command[] array of char symbols for keep read information to continue program or break
 *@return 1 if read command and default is equal, else 0
 */
bool CheckCommand(const char command[]);

/*Chage -0 to 0 if zero is root and has a sign
 *@param *x1 first root of equation
 *@param *x2 second root of equation
 */
void CheckMinusZero(double *x1, double *x2);

