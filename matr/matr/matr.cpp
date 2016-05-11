// matr.cpp: определяет точку входа для консольного приложения.
//
#include <omp.h>
#include "stdafx.h"


double* MatrXVect(double** m, double* v, int n, int k) 
{ 
	if (sizeof(m)==0 || sizeof(v)==0)
	{
		return 0;
	}

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

double** MatrTransp(double** m, int n)
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


double** MatrXMatr(double** m1, double** m2, int h1, int w1, int h2, int w2)
{	
	if (w1 != h2)
	{
		return 0;
	}
	if (sizeof(m1) == 0 || sizeof(m2) == 0)
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

//	#pragma omp parallel for reduction(+:m_res)
	for (int i = 0; i < h1; i++)
	{
		for (int k = 0; k < w2; k++)
		{
			for (int j = 0; j < w1; j++)
			{
				m_res[i][k] += m1[i][j] * m2[j][k];
			}
		}
	}
	return m_res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int h1 = 3, w1 = 2, h2 = 2, w2 = 3;
	double ** m1 = new double*[2];
	for (int i = 0; i < h1; i++)
	{
		m1[i]=new double[w1];
		/*for (int j = 0; j < w1; j++)
		{
		m1[i][j] = i;
		}*/
	}
	double ** m2 = new double*[2];
	for (int i = 0; i < h2; i++)
	{
		m2[i]=new double[w2];
		/*for (int j = 0; j < w2; j++)
		{
		m2[i][j] = i;
		}*/
	}
	m1[0][0]=1;
	m1[0][1]=4;
	m1[1][0]=2;
	m1[1][1]=5;
	m1[2][0]=3;
	m1[2][1]=6;

	m2[0][0]=7;
	m2[0][1]=8;
	m2[0][2]=9;
	m2[1][0]=10;
	m2[1][1]=11;
	m2[1][2]=12;
	double ** m_res=MatrXMatr(m1,m2,h1,w1,h2,w2);
	for (int i = 0; i < h1; i++)
	{
		for (int j = 0; j < w2; j++)
		{
			printf("%f   ",m_res[i][j]);
		}
		printf("\n");
	}
	getchar();
	return 0;
}

