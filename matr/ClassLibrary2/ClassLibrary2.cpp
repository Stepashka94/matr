// ������� DLL-����.

#include "stdafx.h"

#include "ClassLibrary2.h"
#include "..\matr\MyMatrFuncs.h"
#include "..\matr\MyMatrFuncs.cpp"
ClassLibrary2::MatrFuncs::MatrFuncs()
{
	myCppClass = new MyMatrFuncs();
}

/// <summary>
/// ��������� ������� �� ������.
/// </summary>
/// <param name="m">�������.</param>
/// <param name="v">������.</param>
/// <param name="n">������ �������.</param>
/// <param name="k">������ �������.</param>
/// <returns>������.</returns>
array<double>^ ClassLibrary2::MatrFuncs::MatrXVec(array<array<double>^>^ m, array<double>^ v, int n, int k)
{
	double* vv = new double[n];
	pin_ptr<double> p_deep = &(vv)[0];
	System::Runtime::InteropServices::Marshal::Copy(v, 0, System::IntPtr(vv), n);
	double **vv1 = new double*[n];
	for (int i = 0; i < n; i++)
	{
		vv1[i] = new double[k];
	}
	for (int i = 0; i < n; i++)
	{
		pin_ptr<double> p_deep1 = &(vv1)[i][0];
		System::Runtime::InteropServices::Marshal::Copy(m[i], 0, System::IntPtr((void *)p_deep1), k);
	}
	double *res_MatrXVect = myCppClass->MatrXVect(vv1, vv, n, k);
	array<double>^ new_v = gcnew array<double>(n);
	System::Runtime::InteropServices::Marshal::Copy(System::IntPtr(res_MatrXVect), new_v, 0, n);
	return new_v;
}

/// <summary>
/// ��������� ������� �� �������.
/// </summary>
/// <param name="m1">������ �������.</param>
/// <param name="m2">������ �������.</param>
/// <param name="h1">������ ������ �������.</param>
/// <param name="w1">������ ������ �������.</param>
/// <param name="h2">������ ������ �������.</param>
/// <param name="w2">������ ������ �������.</param>
/// <returns>�������.</returns>
array<array<double>^>^ ClassLibrary2::MatrFuncs::MatrXMatr(array<array<double>^>^ m1, array<array<double>^>^ m2, int h1, int w1, int h2, int w2)
{
	double **vv = new double*[h1];
	for (int i = 0; i < h1; i++)
	{
		vv[i] = new double[w1];
	}
	for (int i = 0; i < h1; i++)
	{
		pin_ptr<double> p_deep = &(vv)[i][0];
		System::Runtime::InteropServices::Marshal::Copy(m1[i], 0, System::IntPtr((void *)p_deep), w1);
	}

	double **vv1 = new double*[h2];
	for (int i = 0; i < h2; i++)
	{
		vv1[i] = new double[w2];
	}
	for (int i = 0; i < h2; i++)
	{
		pin_ptr<double> p_deep1 = &(vv1)[i][0];
		System::Runtime::InteropServices::Marshal::Copy(m2[i], 0, System::IntPtr((void *)p_deep1), w2);
	}
	double **res_MatrXMatr = myCppClass->MatrXMatr(vv, vv1, h1, w1, h2, w2);
	array<array<double>^>^ new_m = gcnew array<array<double>^>(h1);
	for (int i = 0; i < h1; i++)
	{
		new_m[i] = gcnew array<double>(w2);
	}
	for (int i = 0; i < h1; i++)
	{		
		System::Runtime::InteropServices::Marshal::Copy(System::IntPtr(res_MatrXMatr[i]), new_m[i], 0, w2);
	}

	return new_m;
}


/// <summary>
/// ���������������� �������.
/// </summary>
/// <param name="m">�������.</param>
/// <param name="n">�����������.</param>
/// <returns>�������.</returns>
array<array<double>^>^ ClassLibrary2::MatrFuncs::MatrTranspon(array<array<double>^>^ m, int n)
{
	double **vv1 = new double*[n];
	for (int i = 0; i < n; i++)
	{
		vv1[i] = new double[n];
	}
	for (int i = 0; i < n; i++)
	{
		pin_ptr<double> p_deep1 = &(vv1)[i][0];
		System::Runtime::InteropServices::Marshal::Copy(m[i], 0, System::IntPtr((void *)p_deep1), n);
	}
	double **res_MatrTransp = myCppClass->MatrTransp(vv1, n);
	array<array<double>^>^ new_m = gcnew array<array<double>^>(n);
	for (int i = 0; i < n; i++)
	{
		new_m[i] = gcnew array<double>(n);
	}
	for (int i = 0; i < n; i++)
	{
		System::Runtime::InteropServices::Marshal::Copy(System::IntPtr(res_MatrTransp[i]), new_m[i], 0, n);
	}
	return new_m;
}

