#include "quadratic_equation.h"
#include "test.h"

#include <stdio.h>
#include "test.h"
#include <cassert>


void TestQuadraticEquation()
{
	int counter_errors = 0;

	double two_solutions_and_cnt[3] = {};

	const char part_error_messages[][30] = { 
		"must have infinite solutions", 
		"must not have solutions", 
		"must has one solution", 
		"must has two solutions" 
	};

	double test_case[][7] = {
		{0, 0, 0, 100, 0, 0, 0},
		{0, 0, 1, 0, 0, 0, 1},
		{0, 1, 0, 1, 0, 0, 2},
		{0, 5, 1, 1, -0.2, -0.2, 2},
		{1, 1, 10, 0, 0, 0, 1},
		{1, 4, 4, 1, -2, -2, 2},
		{1, -3, -4, 2, 4, -1, 3}
	};
	for (int i = 0; i < sizeof(test_case) / sizeof(test_case[0]); i++)
	{
		two_solutions_and_cnt[2] = SolutionQuadraticEquation(test_case[i][0], test_case[i][1], test_case[i][2], 
			&two_solutions_and_cnt[0], &two_solutions_and_cnt[1]);

		if (!AssertEqual(two_solutions_and_cnt[2], two_solutions_and_cnt[0], two_solutions_and_cnt[1], 
			test_case[i][3], test_case[i][4], test_case[i][5]))
		{
			counter_errors++;
			printf("Error, equation (%.2fl)x^2 + (%.2fl)x + (%.2fl) = 0 %s\n", 
				test_case[i][0], test_case[i][1], test_case[i][2], part_error_messages[(int)test_case[i][6]]);
		}
	}

	if (counter_errors == 0)
	{
		printf("All tests are right\n\n\n");
	}
	else
	{
		printf("%d errors exist\n", counter_errors);
		assert(0);
	}
}



bool AssertEqual(int sol, double f_root, double s_root, int real_sol, double real_f_root, double real_s_root)
{
	if ((real_sol == sol) && 
		(((f_root == real_f_root) && (s_root == real_s_root)) || ((f_root == real_s_root) && (s_root == real_f_root))))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}