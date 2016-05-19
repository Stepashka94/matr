#pragma once
#include "stdafx.h"
#include <omp.h>
#include "MyDiffFuncs.h"
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include "omp.h"

double* MyDiffFuncs::Eiler_Paral(void** Function, double a, double b, int n, double* y, int count)
{
	double h = (b - a) / n;
	FType* F = (FType* )(Function);
	double* y_new = new double[count];
	
	for (int j = 0; j < n; j++)//���� �� �������
	{ 
#pragma omp  parallel for
		for (int i = 0; i < count; i++)
		{
			y_new[i] = y[i] + h * F[i](j * h, y);
		}
		for (int i = 0; i < count; i++)
		{
			y[i] = y_new[i];
		}
	}
	return y;
}

double* MyDiffFuncs::RungeKutta2_Paral(void** Function, double a, double b, int n, double* y, int count)
{
	double h = (b - a) / n;
	double* y_new = new double[count];
	FType* F = (FType* )(Function);
	double* z = new double[count]; 
	for (int i = 0; i < count; i++)
		z[i] = 0;
	for (int j = 0; j < n; j++)//���� �� �������
	{ 
#pragma omp  parallel for
		for (int i = 0; i < count; i++)
		{
			z[i] = y[i] + h/2 * F[i](j * h, y);
		}
		#pragma omp  parallel for
		for (int i = 0; i < count; i++)
		{
			y_new[i] = y[i] + h * F[i](j * h, z);		
		}
		for (int i = 0; i < count; i++)
		{
			y[i] = y_new[i];
		}
	}
	return y;
}

double* MyDiffFuncs::RungeKutta4_Paral(void** Function, double a, double b, int n, double* y, int count)
{
	FType* F = (FType* )(Function);
	// �������� �������
	double* y_new = new double[count];
	double* xx = new double[count];// ��� t=0.
	double* R1 = new double[count]; // ������ ��������� �� ������� ��� ��� �������
	double* R2 = new double[count]; // ������ ��������� �� ������� ��� ��� �������
	double* R3 = new double[count]; // ������ ��������� �� ������� ��� ��� �������
	double* R4 = new double[count]; // ��������� ��������� �� ������� ��� ��� �������
	double h = (b - a) / n;
	double t;
	for (int q = 0; q < n - 1; q++)
	{
		t = q * h;
		// ������ ���������
#pragma  omp parallel for
		for (int i = 0; i < count; i++)
			R1[i] = h * F[i](t, y);

		// ������ ���������
#pragma  omp parallel for
		for (int i = 0; i < count; i++)
			xx[i] = y[i] + 0.5 * R1[i];

#pragma  omp parallel for
		for (int i = 0; i < count; i++)
			R2[i] = h * F[i](t + 0.5 * h, xx);

		// ������ ���������
#pragma  omp parallel for
		for (int i = 0; i < count; i++)
			xx[i] = y[i] + 0.5 * R2[i];


#pragma  omp parallel for
		for (int i = 0; i < count; i++)
			R3[i] = h * F[i](t + h, xx);


		// ��������� ���������
#pragma  omp parallel for
		for (int i = 0; i < count; i++)
			xx[i] = y[i] + R3[i];

#pragma  omp parallel for
		for (int i = 0; i < count; i++)
			R4[i] = h * F[i](t + h, xx);

		// ����� �������� �������
#pragma  omp parallel for
		for (int i = 0; i < count; i++)
			y_new[i] = y[i] + (R1[i] + 2 * R2[i] + 2 * R3[i] + R4[i]) / 6;


		for (int i = 0; i < count; i++)
		{
			y[i] = y_new[i];
		}
	} 
	return y;
}



double* MyDiffFuncs::Eiler(void** Function, double a, double b, int n, double* y, int count)
{
	double h = (b - a) / n;
	FType* F = (FType* )(Function);
	double t = 0;

	for (int j = 0; j < n; j++)//���� �� �������
	{ 
		for (int i = 0; i < count; i++)
		{
			y[i] = y[i] + h * F[i](j * h, y);
		}
	}
	return y;
}

double* MyDiffFuncs::RungeKutta2(void** Function, double a, double b, int n, double* y, int count)
{
	double h = (b - a) / n;
	FType* F = (FType* )(Function);
	double* z = new double[count]; 
	for (int i = 0; i < count; i++)
		z[i] = 0;
	for (int j = 0; j < n; j++)//���� �� �������
	{ 
		for (int i = 0; i < count; i++)
		{
			z[i] = y[i] + h/2 * F[i](j * h, y);
			y[i] = y[i] + h * F[i](j * h, z);		
		}
	}
	return y;
}

double* MyDiffFuncs::RungeKutta4(void** Function, double a, double b, int n, double* y, int count)
{
	FType* F = (FType* )(Function);
	// �������� �������
	double* xx = new double[count];// ��� t=0.
	double* R1 = new double[count]; // ������ ��������� �� ������� ��� ��� �������
	double* R2 = new double[count]; // ������ ��������� �� ������� ��� ��� �������
	double* R3 = new double[count]; // ������ ��������� �� ������� ��� ��� �������
	double* R4 = new double[count]; // ��������� ��������� �� ������� ��� ��� �������
	double h = (b - a) / n;
	double t;
	for (int q = 0; q < n - 1; q++)
	{
		t = q * h;
		// ������ ���������
		for (int i = 0; i < count; i++)
			R1[i] = h * F[i](t, y);

		// ������ ���������
		for (int i = 0; i < count; i++)
			xx[i] = y[i] + 0.5 * R1[i];

		for (int i = 0; i < count; i++)
			R2[i] = h * F[i](t + 0.5 * h, xx);

		// ������ ���������
		for (int i = 0; i < count; i++)
			xx[i] = y[i] + 0.5 * R2[i];


		for (int i = 0; i < count; i++)
			R3[i] = h * F[i](t + h, xx);


		// ��������� ���������
		for (int i = 0; i < count; i++)
			xx[i] = y[i] + R3[i];

		for (int i = 0; i < count; i++)
			R4[i] = h * F[i](t + h, xx);

		// ����� �������� �������
		for (int i = 0; i < count; i++)
			y[i] = y[i] + (R1[i] + 2 * R2[i] + 2 * R3[i] + R4[i]) / 6;

	} 
	return y;
}




//==================================================================
//���������� � �������������� tau
//==================================================================


double* MyDiffFuncs::Eiler_Paral(void** Function, double tau, int n, double* y, int count)
{
	double h = tau;
	FType* F = (FType* )(Function);

	for (int j = 0; j < n; j++)//���� �� �������
	{ 
#pragma omp  parallel for
		for (int i = 0; i < count; i++)
		{
			y[i] = y[i] + h * F[i](j * h, y);
		}
	}
	return y;
}

double* MyDiffFuncs::RungeKutta2_Paral(void** Function, double tau, int n, double* y, int count)
{
	double h = tau;
	FType* F = (FType* )(Function);
	double* z = new double[count]; 
	for (int i = 0; i < count; i++)
		z[i] = 0;
	for (int j = 0; j < n; j++)//���� �� �������
	{ 
#pragma omp  parallel for
		for (int i = 0; i < count; i++)
		{
			z[i] = y[i] + h/2 * F[i](j * h, y);
			y[i] = y[i] + h * F[i](j * h, z);		
		}
	}
	return y;
}

double* MyDiffFuncs::RungeKutta4_Paral(void** Function, double tau, int n, double* y, int count)
{
	FType* F = (FType* )(Function);
	// �������� �������
	double* xx = new double[count];// ��� t=0.
	double* R1 = new double[count]; // ������ ��������� �� ������� ��� ��� �������
	double* R2 = new double[count]; // ������ ��������� �� ������� ��� ��� �������
	double* R3 = new double[count]; // ������ ��������� �� ������� ��� ��� �������
	double* R4 = new double[count]; // ��������� ��������� �� ������� ��� ��� �������
	double h = tau;
	double t;
	for (int q = 0; q < n - 1; q++)
	{
		t = q * h;
		// ������ ���������
#pragma  omp parallel for
		for (int i = 0; i < count; i++)
			R1[i] = h * F[i](t, y);

		// ������ ���������
#pragma  omp parallel for
		for (int i = 0; i < count; i++)
			xx[i] = y[i] + 0.5 * R1[i];

#pragma  omp parallel for
		for (int i = 0; i < count; i++)
			R2[i] = h * F[i](t + 0.5 * h, xx);

		// ������ ���������
#pragma  omp parallel for
		for (int i = 0; i < count; i++)
			xx[i] = y[i] + 0.5 * R2[i];


#pragma  omp parallel for
		for (int i = 0; i < count; i++)
			R3[i] = h * F[i](t + h, xx);


		// ��������� ���������
#pragma  omp parallel for
		for (int i = 0; i < count; i++)
			xx[i] = y[i] + R3[i];

#pragma  omp parallel for
		for (int i = 0; i < count; i++)
			R4[i] = h * F[i](t + h, xx);

		// ����� �������� �������
#pragma  omp parallel for
		for (int i = 0; i < count; i++)
			y[i] = y[i] + (R1[i] + 2 * R2[i] + 2 * R3[i] + R4[i]) / 6;

	} 
	return y;
}



double* MyDiffFuncs::Eiler(void** Function, double tau, int n, double* y, int count)
{
	double h = tau;
	FType* F = (FType* )(Function);
	double t = 0;

	for (int j = 0; j < n; j++)//���� �� �������
	{ 
		for (int i = 0; i < count; i++)
		{
			y[i] = y[i] + h * F[i](j * h, y);
		}
	}
	return y;
}

double* MyDiffFuncs::RungeKutta2(void** Function, double tau, int n, double* y, int count)
{
	double h = tau;
	FType* F = (FType* )(Function);
	double* z = new double[count]; 
	for (int i = 0; i < count; i++)
		z[i] = 0;
	for (int j = 0; j < n; j++)//���� �� �������
	{ 
		for (int i = 0; i < count; i++)
		{
			z[i] = y[i] + h/2 * F[i](j * h, y);
			y[i] = y[i] + h * F[i](j * h, z);		
		}
	}
	return y;
}

double* MyDiffFuncs::RungeKutta4(void** Function, double tau, int n, double* y, int count)
{
	FType* F = (FType* )(Function);
	// �������� �������
	double* xx = new double[count];// ��� t=0.
	double* R1 = new double[count]; // ������ ��������� �� ������� ��� ��� �������
	double* R2 = new double[count]; // ������ ��������� �� ������� ��� ��� �������
	double* R3 = new double[count]; // ������ ��������� �� ������� ��� ��� �������
	double* R4 = new double[count]; // ��������� ��������� �� ������� ��� ��� �������
	double h = tau;
	double t;
	for (int q = 0; q < n - 1; q++)
	{
		t = q * h;
		// ������ ���������
		for (int i = 0; i < count; i++)
			R1[i] = h * F[i](t, y);

		// ������ ���������
		for (int i = 0; i < count; i++)
			xx[i] = y[i] + 0.5 * R1[i];

		for (int i = 0; i < count; i++)
			R2[i] = h * F[i](t + 0.5 * h, xx);

		// ������ ���������
		for (int i = 0; i < count; i++)
			xx[i] = y[i] + 0.5 * R2[i];


		for (int i = 0; i < count; i++)
			R3[i] = h * F[i](t + h, xx);


		// ��������� ���������
		for (int i = 0; i < count; i++)
			xx[i] = y[i] + R3[i];

		for (int i = 0; i < count; i++)
			R4[i] = h * F[i](t + h, xx);

		// ����� �������� �������
		for (int i = 0; i < count; i++)
			y[i] = y[i] + (R1[i] + 2 * R2[i] + 2 * R3[i] + R4[i]) / 6;

	} 
	return y;
}