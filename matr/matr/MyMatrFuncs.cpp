#pragma once
#include "stdafx.h"
#include <omp.h>
#include "MyMatrFuncs.h"

double* MyMatrFuncs::MatrXVect(double** m, double* v, int n, int k)
{ 
	double* v_res;
	v_res = new double[k];
	double s = 0;
	#pragma omp parallel for reduction(+:s)
	for ( int i = 0; i < n; i++)
	{
		for ( int j = 0; j < k; j++)
		{
			s = s + m[i][j] * v[j];
		}

		v_res[i] = s;
		s = 0;
	}

	return v_res;
}
double** MyMatrFuncs::MatrTransp(double** m, int n)
{
	double** m_res = new double*[n];
	#pragma omp parallel for
	for ( int i = 0; i < n; i++)
	{
		m_res[i]=new double[n];
		for ( int j = 0; j < n; j++)
		{
			m_res[i][j] = m [j][i];
		}
	}
	return m_res;
}
double** MyMatrFuncs::MatrXMatr(double** m1, double** m2, int h1, int w1, int h2, int w2)
{	
	if (w1 != h2)
	{
		return 0;
	}

	double** m_res;
	m_res = new double*[h1];
	for (int i = 0; i < h1; i++)
	{
		m_res[i] = new double[h2];
	}

	for (int i = 0; i < h1; i++)
	{
		for (int j = 0; j < w2; j++)
		{
			m_res[i][j] = 0;
		}
	}
	double sum = 0;
	#pragma omp parallel for reduction(+:sum)
	for (int i = 0; i < h1; i++)
	{
		for (int k = 0; k < w2; k++)
		{
			for (int j = 0; j < w1; j++)
			{
				sum += m1[i][j] * m2[j][k];
			}
			m_res[i][k] = sum;
			sum = 0;
		}
	}
	
	return m_res;
}


double* MyMatrFuncs::MatrXVect_NotParal(double** m, double* v, int n, int k)
{ 
	double* v_res;
	v_res = new double[k];
	double s = 0;
	for ( int i = 0; i < n; i++)
	{
		for ( int j = 0; j < k; j++)
		{
			s = s + m[i][j] * v[j];
		}

		v_res[i] = s;
		s = 0;
	}

	return v_res;
}
double** MyMatrFuncs::MatrTransp_NotParal(double** m, int n)
{
	double** m_res = new double*[n];
	for ( int i = 0; i < n; i++)
	{
		m_res[i]=new double[n];
		for ( int j = 0; j < n; j++)
		{
			m_res[i][j] = m [j][i];
		}
	}
	return m_res;
}
double** MyMatrFuncs::MatrXMatr_NotParal(double** m1, double** m2, int h1, int w1, int h2, int w2)
{	
	if (w1 != h2)
	{
		return 0;
	}
	double** m_res;
	m_res = new double*[h1];
	for (int i = 0; i < h1; i++)
	{
		m_res[i] = new double[h2];
	}

	for (int i = 0; i < h1; i++)
	{
		for (int j = 0; j < w2; j++)
		{
			m_res[i][j] = 0;
		}
	}
	double sum = 0;
	for (int i = 0; i < h1; i++)
	{
		for (int k = 0; k < w2; k++)
		{
			for (int j = 0; j < w1; j++)
			{
				sum += m1[i][j] * m2[j][k];
			}
			m_res[i][k] = sum;
			sum = 0;
		}
	}
	
	return m_res;
}








//одномерный массив
double* MyMatrFuncs::MatrXVect(double* m, double* v, int n, int k)
{ 
	double* v_res;
	v_res = new double[k];
	double s = 0;
	#pragma omp parallel for reduction(+:s)
	for ( int i = 0; i < n; i++)
	{
		for ( int j = 0; j < k; j++)
		{
			s = s + m[i * n + j] * v[j];
		}

		v_res[i] = s;
		s = 0;
	}

	return v_res;
}
double* MyMatrFuncs::MatrTransp(double* m, int n)
{
	double* m_res = new double[n * n];
	#pragma omp parallel for
	for ( int i = 0; i < n; i++)
	{
		for ( int j = 0; j < n; j++)
		{
			m_res[i * n + j] = m [j * n + i];
		}
	}
	return m_res;
}
double* MyMatrFuncs::MatrXMatr(double* m1, double* m2, int h1, int w1, int h2, int w2)
{	
	if (w1 != h2)
	{
		return 0;
	}

	double* m_res;
	m_res = new double[h1 * w2];

	for (int i = 0; i < h1; i++)
	{
		for (int j = 0; j < w2; j++)
		{
			m_res[i * h1 + j] = 0;
		}
	}
	double sum = 0;
	#pragma omp parallel for reduction(+:sum)
	for (int i = 0; i < h1; i++)
	{
		for (int k = 0; k < w2; k++)
		{
			for (int j = 0; j < w1; j++)
			{
				sum += m1[i * h1 + j] * m2[j * w1 + k];
			}
			m_res[i * h1 + k] = sum;
			sum = 0;
		}
	}
	
	return m_res;
}


double* MyMatrFuncs::MatrXVect_NotParal(double* m, double* v, int n, int k)
{ 
	double* v_res;
	v_res = new double[k];
	double s = 0;
	for ( int i = 0; i < n; i++)
	{
		for ( int j = 0; j < k; j++)
		{
			s = s + m[i * n + j] * v[j];
		}

		v_res[i] = s;
		s = 0;
	}

	return v_res;
}
double* MyMatrFuncs::MatrTransp_NotParal(double* m, int n)
{
	double* m_res = new double[n * n];
	for ( int i = 0; i < n; i++)
	{
		for ( int j = 0; j < n; j++)
		{
			m_res[i * n + j] = m [j * n + i];
		}
	}
	return m_res;
}
double* MyMatrFuncs::MatrXMatr_NotParal(double* m1, double* m2, int h1, int w1, int h2, int w2)
{	
	if (w1 != h2)
	{
		return 0;
	}

	double* m_res;
	m_res = new double[h1 * w2];

	for (int i = 0; i < h1; i++)
	{
		for (int j = 0; j < w2; j++)
		{
			m_res[i * h1 + j] = 0;
		}
	}
	double sum = 0;
	for (int i = 0; i < h1; i++)
	{
		for (int k = 0; k < w2; k++)
		{
			for (int j = 0; j < w1; j++)
			{
				sum += m1[i * h1 + j] * m2[j * w1 + k];
			}
			m_res[i * h1 + k] = sum;
			sum = 0;
		}
	}
	
	return m_res;
}