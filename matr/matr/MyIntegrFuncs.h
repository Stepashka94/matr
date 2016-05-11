#pragma once

#include <omp.h>

class MyIntegrFuncs
{
public:
	typedef double (*FType)(double x);
    FType F;

	double Simpson(void* Function, double a, double b, int N);
	double Simpson38(void* Function, double a, double b, int N);
	double MonteKarlo(void* Function, double a, double b, int N);

	double Simpson_NotParal(void* Function, double a, double b, int N);
	double Simpson38_NotParal(void* Function, double a, double b, int N);
	double MonteKarlo_NotParal(void* Function, double a, double b, int N);
};