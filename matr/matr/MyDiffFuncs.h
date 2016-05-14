#pragma once

#include <omp.h>

class MyDiffFuncs
{
public:
	typedef double (*FType)(double x, double* y);
    FType F;

	double* Eiler(void** Function, double a, double b, int n, double* y, int count);
	double* RungeKutta2(void** Function, double a, double b, int n, double* y, int count);
	double* RungeKutta4(void** Function, double a, double b, int n, double* y, int count);

	double* Eiler_Paral(void** Function, double a, double b, int n, double* y, int count);
	double* RungeKutta2_Paral(void** Function, double a, double b, int n, double* y, int count);
	double* RungeKutta4_Paral(void** Function, double a, double b, int n, double* y, int count);


	//перегрузки с использованием tau
	double* Eiler(void** Function, double tau, int n, double* y, int count);
	double* RungeKutta2(void** Function, double tau, int n, double* y, int count);
	double* RungeKutta4(void** Function, double tau, int n, double* y, int count);

	double* Eiler_Paral(void** Function, double tau, int n, double* y, int count);
	double* RungeKutta2_Paral(void** Function, double tau, int n, double* y, int count);
	double* RungeKutta4_Paral(void** Function, double tau, int n, double* y, int count);
};