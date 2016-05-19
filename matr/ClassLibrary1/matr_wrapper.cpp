// ������� DLL-����.

#include "stdafx.h"

#include "matr_wrapper.h"
#include "..\matr\MyMatrFuncs.h"
#include "..\matr\MyMatrFuncs.cpp"
math_wrapper::MatrFuncs::MatrFuncs()
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
array<double>^ math_wrapper::MatrFuncs::MatrXVec(array<array<double>^>^ m, array<double>^ v, int n, int k)
{
	double* vv = new double[k];//�������� �������������� �������
	pin_ptr<double> p_deep = &(vv)[0];
	System::Runtime::InteropServices::Marshal::Copy(v, 0, System::IntPtr(vv), k);//�������������� ������ �� ������������ ������� � �������������
	double **vv1 = new double*[n];//���������� ������������� ������
	for (int i = 0; i < n; i++)
	{
		vv1[i] = new double[k];
	}
	for (int i = 0; i < n; i++)
	{
		pin_ptr<double> p_deep1 = &(vv1)[i][0];
		System::Runtime::InteropServices::Marshal::Copy(m[i], 0, System::IntPtr((void *)p_deep1), k);////�������������� ������ �� ������������ ������� � �������������
	}
	double *res_MatrXVect = myCppClass->MatrXVect(vv1, vv, n, k);//����� �������. ��������� �����������
	array<double>^ new_v = gcnew array<double>(n);//�������� ������������ �������
	System::Runtime::InteropServices::Marshal::Copy(System::IntPtr(res_MatrXVect), new_v, 0, n);//�������������� ������ �� �������������� ������� � �����������
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
array<array<double>^>^ math_wrapper::MatrFuncs::MatrXMatr(array<array<double>^>^ m1, array<array<double>^>^ m2, int h1, int w1, int h2, int w2)
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
array<array<double>^>^ math_wrapper::MatrFuncs::MatrTranspon(array<array<double>^>^ m, int n)
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





/// <summary>
/// ��������� ������� �� ������.
/// </summary>
/// <param name="m">�������.</param>
/// <param name="v">������.</param>
/// <param name="n">������ �������.</param>
/// <param name="k">������ �������.</param>
/// <returns>������.</returns>
array<double>^ math_wrapper::MatrFuncs::MatrXVec_NotParal(array<array<double>^>^ m, array<double>^ v, int n, int k)
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
	double *res_MatrXVect = myCppClass->MatrXVect_NotParal(vv1, vv, n, k);
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
array<array<double>^>^ math_wrapper::MatrFuncs::MatrXMatr_NotParal(array<array<double>^>^ m1, array<array<double>^>^ m2, int h1, int w1, int h2, int w2)
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
	double **res_MatrXMatr = myCppClass->MatrXMatr_NotParal(vv, vv1, h1, w1, h2, w2);
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
array<array<double>^>^ math_wrapper::MatrFuncs::MatrTranspon_NotParal(array<array<double>^>^ m, int n)
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
	double **res_MatrTransp = myCppClass->MatrTransp_NotParal(vv1, n);
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





//���������� �������


/// <summary>
/// ��������� ������� �� ������.
/// </summary>
/// <param name="m">�������.</param>
/// <param name="v">������.</param>
/// <param name="n">������ �������.</param>
/// <param name="k">������ �������.</param>
/// <returns>������.</returns>
array<double>^ math_wrapper::MatrFuncs::MatrXVec(array<double>^ m, array<double>^ v, int n, int k)
{
	double* vv = new double[k];//�������� �������������� �������
	System::Runtime::InteropServices::Marshal::Copy(v, 0, System::IntPtr(vv), k);//�������������� ������ �� ������������ ������� � �������������
	double *vv1 = new double[n * k];//���������� ������������� ������

	System::Runtime::InteropServices::Marshal::Copy(m, 0, System::IntPtr(vv1), n * k);////�������������� ������ �� ������������ ������� � �������������

	double *res_MatrXVect = myCppClass->MatrXVect(vv1, vv, n, k);//����� �������. ��������� �����������
	array<double>^ new_v = gcnew array<double>(k);//�������� ������������ �������
	System::Runtime::InteropServices::Marshal::Copy(System::IntPtr(res_MatrXVect), new_v, 0, k);//�������������� ������ �� �������������� ������� � �����������
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
array<double>^ math_wrapper::MatrFuncs::MatrXMatr(array<double>^ m1, array<double>^ m2, int h1, int w1, int h2, int w2)
{
	double *vv = new double[h1 * w1];
	System::Runtime::InteropServices::Marshal::Copy(m1, 0, System::IntPtr(vv), h1 * w1);

	double *vv1 = new double[h2 * w2];
	System::Runtime::InteropServices::Marshal::Copy(m2, 0, System::IntPtr(vv1), h2 * w2);
	double *res_MatrXMatr = myCppClass->MatrXMatr(vv, vv1, h1, w1, h2, w2);
	array<double>^ new_m = gcnew array<double>(h1 * w2);
	System::Runtime::InteropServices::Marshal::Copy(System::IntPtr(res_MatrXMatr), new_m, 0, h1 * w2);

	return new_m;
}


/// <summary>
/// ���������������� �������.
/// </summary>
/// <param name="m">�������.</param>
/// <param name="n">�����������.</param>
/// <returns>�������.</returns>
array<double>^ math_wrapper::MatrFuncs::MatrTranspon(array<double>^ m, int n)
{
	double *vv1 = new double[n * n];
	System::Runtime::InteropServices::Marshal::Copy(m, 0, System::IntPtr(vv1), n * n);
	double *res_MatrTransp = myCppClass->MatrTransp(vv1, n);
	array<double>^ new_m = gcnew array<double>(n * n);
	System::Runtime::InteropServices::Marshal::Copy(System::IntPtr(res_MatrTransp), new_m, 0, n * n);
	return new_m;
}


/// <summary>
/// ��������� ������� �� ������.
/// </summary>
/// <param name="m">�������.</param>
/// <param name="v">������.</param>
/// <param name="n">������ �������.</param>
/// <param name="k">������ �������.</param>
/// <returns>������.</returns>
array<double>^ math_wrapper::MatrFuncs::MatrXVec_NotParal(array<double>^ m, array<double>^ v, int n, int k)
{
	double* vv = new double[n];//�������� �������������� �������
	System::Runtime::InteropServices::Marshal::Copy(v, 0, System::IntPtr(vv), n);//�������������� ������ �� ������������ ������� � �������������
	double *vv1 = new double[n * k];//���������� ������������� ������

	System::Runtime::InteropServices::Marshal::Copy(m, 0, System::IntPtr(vv1), n * k);////�������������� ������ �� ������������ ������� � �������������

	double *res_MatrXVect = myCppClass->MatrXVect_NotParal(vv1, vv, n, k);//����� �������. ��������� �����������
	array<double>^ new_v = gcnew array<double>(n);//�������� ������������ �������
	System::Runtime::InteropServices::Marshal::Copy(System::IntPtr(res_MatrXVect), new_v, 0, n);//�������������� ������ �� �������������� ������� � �����������
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
array<double>^ math_wrapper::MatrFuncs::MatrXMatr_NotParal(array<double>^ m1, array<double>^ m2, int h1, int w1, int h2, int w2)
{
	double *vv = new double[h1 * w1];
	System::Runtime::InteropServices::Marshal::Copy(m1, 0, System::IntPtr(vv), h1 * w1);

	double *vv1 = new double[h2 * w2];
	System::Runtime::InteropServices::Marshal::Copy(m2, 0, System::IntPtr(vv1), h2 * w2);
	double *res_MatrXMatr = myCppClass->MatrXMatr_NotParal(vv, vv1, h1, w1, h2, w2);
	array<double>^ new_m = gcnew array<double>(h1 * w2);
	System::Runtime::InteropServices::Marshal::Copy(System::IntPtr(res_MatrXMatr), new_m, 0, h1 * w2);

	return new_m;
}

/// <summary>
/// ���������������� �������.
/// </summary>
/// <param name="m">�������.</param>
/// <param name="n">�����������.</param>
/// <returns>�������.</returns>
array<double>^ math_wrapper::MatrFuncs::MatrTranspon_NotParal(array<double>^ m, int n)
{
	double *vv1 = new double[n * n];
	System::Runtime::InteropServices::Marshal::Copy(m, 0, System::IntPtr(vv1), n * n);
	double *res_MatrTransp = myCppClass->MatrTransp_NotParal(vv1, n);
	array<double>^ new_m = gcnew array<double>(n * n);
	System::Runtime::InteropServices::Marshal::Copy(System::IntPtr(res_MatrTransp), new_m, 0, n * n);
	return new_m;
}