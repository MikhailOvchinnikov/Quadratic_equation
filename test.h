#pragma once

typedef struct TestAnswers
{

} TestAnswers;

void TestQuadraticEquation();


bool AssertEqual(int sol, double f_root, double s_root, int real_sol, double real_f_root, double real_s_root);