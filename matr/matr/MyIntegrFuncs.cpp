#pragma once
#include "stdafx.h"
#include <omp.h>
#include "MyIntegrFuncs.h"
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include "omp.h"

double MyIntegrFuncs::Simpson(void* Function, double a, double b, int N)
{ 
	FType F = (FType )(Function);
	double h = (b - a) / N;
	double x = a + h;
	double s = 0;
	double x1;
	int num = (int)((b - x) / (2 * h) + 1);

#pragma omp parallel for reduction(+:s)
	for (int i = 0; i < num; i++)
	{
		s = s + 4 * F(a + h + 2 * h * i);
	}

#pragma omp parallel for reduction(+:s)
	for (int i = 0; i < num; i++)
	{
		s = s + 2 * F(a + h + h + 2 * h * i);
	}

	return h / 3 * (s + F(a) - F(b));
}
double MyIntegrFuncs::Simpson38(void* Function, double a, double b, int N)
{
	FType F = (FType )(Function);
	double h = (b - a) / (3 * N); 
	double s1 = F(a) + F(b); 
	int m = 3 * N - 1;
	#pragma omp parallel for reduction(+:s1)
	for (int i = 1; i <= m; i++)             
	{
		if (i % 3 == 0)
			s1 = s1 + 2 * F(a + h * i);
		else
			s1 = s1 + 3 * F(a + h * i);
	}
	return s1 * 3 / 8 * h;
}
double MyIntegrFuncs::MonteKarlo(void* Function, double a, double b, int N)
{	
	FType F = (FType )(Function);
	double c, d, h;

	// Находим максимум функции
	srand(time(0));
	int n = N;
	int col = 0;
	h = (b - a) / n; // Шаг интегрирования
	double S;
	double a1 = a, b1 = b;
	double x1 = 0, x2 = 0;
	double x = 0;
	double e = 0.0001;
	double q = (1 + sqrt(5.0)) / 2;
	x1 = b1 - (b1 - a1) / q;
	x2 = a1 + (b1 - a1) / q;
	while(abs(b1 - a1) > e)
	{
		if (F(x1) <= F(x2))
		{
			a1 = x1;
			x1 = x2;
			x2 = a1 + (b1 - a1) / q;
		}
		else
		{
			b1 = x2;
			x2 = x1;
			x1 = b1 - (b1 - a1) / q;
		}
	}
	c = F((a1 + b1) / 2);
	S = c * (b - a);

	double m;
	double r3, r4, r5, r6;
	int r1, r2;

#pragma omp parallel for private (r1, r2, r3, r4, r5, r6) reduction(+:col)
	for (int i = 0; i < n; i++)
	{
		r1 = rand()%100;
		r2 = rand()%100;
		r3 = r1 * 0.01; // генерируем число от 0 до 1
		r4 = r2 * 0.01;
		r5 = r3 * (b - a) + a;
		r6 = r4 * c;
		m = F(r5);
		if  (r6 < m)
		{
			col = col + 1;
		}
	}
	return S * ((double)col / n);
}


double MyIntegrFuncs::Simpson_NotParal(void* Function, double a, double b, int N)
{ 
	FType F = (FType )(Function);
	double h = (b - a) / N;
	double x = a + h;
	double s = 0;
	int num = (int)((b - x) / (2 * h) + 1);
	for (int i = 0; i < num; i++)
	{
		s = s + 4 * F(x);
		x = x + h;
		s = s + 2 * F(x);
		x = x + h;
	}

	return h / 3 * (s + F(a) - F(b));
}
double MyIntegrFuncs::Simpson38_NotParal(void* Function, double a, double b, int N)
{
	FType F = (FType )(Function);
	double h = (b - a) / (3 * N); 
	double s1 = F(a) + F(b); 
	double m = 3 * N - 1;
	double x = 0;
	for (int i = 1; i <= m; i++)             
	{
		x = a + h * i;
		if (i % 3 == 0)
			s1 = s1 + 2 * F(x);
		else
			s1 = s1 + 3 * F(x);
	}
	s1 = s1 * 3 / 8 * h;
	return s1;
}
double MyIntegrFuncs::MonteKarlo_NotParal(void* Function, double a, double b, int N)
{	
	FType F= (FType )(Function);
	double c, d, h;

	// Находим максимум функции
	srand(time(0));
	int n = N;
	int col = 0;
	h = (b - a) / n; // Шаг интегрирования
	double S;
	c = F(a);
	// Поиск максимума
	for (int i = 0; i < n; i++)
	{
		if (F(a + (i + 1) * h) > c)
		{
			c = F(a + (i + 1) * h); 
		} 
	}
	d = F(a);
	// Поиск минимума
	for (int i=0; i<n; i++)
	{
		if (F(a + (i + 1) * h) < d)
		{
			d = F(a + (i + 1) * h);
		} 
	}
	S = (c - d) * (b - a);
	double r;
	for (int i = 0; i < n; i++)
	{
		int r1 = rand()%100;
		double r2 = r1 * 0.01; // генерируем число от 0 до 1
		r = (b - a) * r2;
		col = col + F(r);
	}
	double I = (b - a) * col / n;
	return I;
}