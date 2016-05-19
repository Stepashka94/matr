#pragma once

#include <omp.h>

class MyMatrFuncs
{
public:
	double* MatrXVect(double** m, double* v, int n, int k);
	double** MatrTransp(double** m, int n);
	double** MatrXMatr(double** m1, double** m2, int h1, int w1, int h2, int w2);

	double* MatrXVect_NotParal(double** m, double* v, int n, int k);
	double** MatrTransp_NotParal(double** m, int n);
	double** MatrXMatr_NotParal(double** m1, double** m2, int h1, int w1, int h2, int w2);



	//одномерные массивы

	double* MatrXVect(double* m, double* v, int n, int k);
	double* MatrTransp(double* m, int n);
	double* MatrXMatr(double* m1, double* m2, int h1, int w1, int h2, int w2);

	double* MatrXVect_NotParal(double* m, double* v, int n, int k);
	double* MatrTransp_NotParal(double* m, int n);
	double* MatrXMatr_NotParal(double* m1, double* m2, int h1, int w1, int h2, int w2);
};