#include "stdafx.h"

#include "diff_wrapper.h"
#include "..\matr\MyDiffFuncs.h"
#include "..\matr\MyDiffFuncs.cpp"
math_wrapper::DiffFuncs::DiffFuncs()
{
	myCppClass = new MyDiffFuncs();
}

//================================================================================================
//================================================================================================
//================================================================================================

/// <summary>
/// Решение системы дифференциальных уравнений методом Эйлера.
/// </summary>
/// <param name="fdelegate">Массив указателей на функции.</param>
/// <param name="a">Начальное значение интервала.</param>
/// <param name="b">Конечное значение интервала.</param>
/// <param name="N">Количество шагов.</param>
/// <param name="arr_y">Массив с начальными значениями.</param>
/// <param name="count">Количество уравнений.</param>
/// <returns>Массив с найденными значениями.</returns>
array<double>^ math_wrapper::DiffFuncs::Eiler(array<FDelegate ^>^ fdelegate, double a, double b, int N, array<double>^ arr_y, int count)
{
	double* y = new double[count];
	System::Runtime::InteropServices::Marshal::Copy(arr_y, 0, System::IntPtr(y), count);
	delegatePointer = new void*[count];
	for (int i = 0; i < count; i++)
	{
		delegatePointer[i] = (void*)Marshal::GetFunctionPointerForDelegate(fdelegate[i]).ToPointer();
	}
	double* res = myCppClass->Eiler(delegatePointer, a, b, N, y, count);
	array<double>^ new_res = gcnew array<double>(count);
	System::Runtime::InteropServices::Marshal::Copy(System::IntPtr(res), new_res, 0, count);
	return new_res;
};

/// <summary>
/// Решение системы дифференциальных уравнений методом Рунге-Кутта 2 порядка.
/// </summary>
/// <param name="fdelegate">Массив указателей на функции.</param>
/// <param name="a">Начальное значение интервала.</param>
/// <param name="b">Конечное значение интервала.</param>
/// <param name="N">Количество шагов.</param>
/// <param name="arr_y">Массив с начальными значениями.</param>
/// <param name="count">Количество уравнений.</param>
/// <returns>Массив с найденными значениями.</returns>
array<double>^ math_wrapper::DiffFuncs::RungeKutta2(array<FDelegate ^>^ fdelegate, double a, double b, int N, array<double>^ arr_y, int count)
{
	double* y = new double[count];
	System::Runtime::InteropServices::Marshal::Copy(arr_y, 0, System::IntPtr(y), count);
	delegatePointer = new void*[count];
	for (int i = 0; i < count; i++)
	{
		delegatePointer[i] = (void*)Marshal::GetFunctionPointerForDelegate(fdelegate[i]).ToPointer();
	}
	double* res = myCppClass->RungeKutta2(delegatePointer, a, b, N, y, count);
	array<double>^ new_res = gcnew array<double>(count);
	System::Runtime::InteropServices::Marshal::Copy(System::IntPtr(res), new_res, 0, count);
	return new_res;
};

/// <summary>
/// Решение системы дифференциальных уравнений методом Рунге-Кутта 4 порядка.
/// </summary>
/// <param name="fdelegate">Массив указателей на функции.</param>
/// <param name="a">Начальное значение интервала.</param>
/// <param name="b">Конечное значение интервала.</param>
/// <param name="N">Количество шагов.</param>
/// <param name="arr_y">Массив с начальными значениями.</param>
/// <param name="count">Количество уравнений.</param>
/// <returns>Массив с найденными значениями.</returns>
array<double>^ math_wrapper::DiffFuncs::RungeKutta4(array<FDelegate ^>^ fdelegate, double a, double b, int N, array<double>^ arr_y, int count)
{
	double* y = new double[count];
	System::Runtime::InteropServices::Marshal::Copy(arr_y, 0, System::IntPtr(y), count);
	delegatePointer = new void*[count];
	for (int i = 0; i < count; i++)
	{
		delegatePointer[i] = (void*)Marshal::GetFunctionPointerForDelegate(fdelegate[i]).ToPointer();
	}
	double* res = myCppClass->RungeKutta4(delegatePointer, a, b, N, y, count);
	array<double>^ new_res = gcnew array<double>(count);
	System::Runtime::InteropServices::Marshal::Copy(System::IntPtr(res), new_res, 0, count);
	return new_res;
};


//================================================================================================
//================================================================================================
//================================================================================================

/// <summary>
/// Решение системы дифференциальных уравнений методом Эйлера. Параллельная реализация.
/// </summary>
/// <param name="fdelegate">Массив указателей на функции.</param>
/// <param name="a">Начальное значение интервала.</param>
/// <param name="b">Конечное значение интервала.</param>
/// <param name="N">Количество шагов.</param>
/// <param name="arr_y">Массив с начальными значениями.</param>
/// <param name="count">Количество уравнений.</param>
/// <returns>Массив с найденными значениями.</returns>
array<double>^ math_wrapper::DiffFuncs::Eiler_Paral(array<FDelegate ^>^ fdelegate, double a, double b, int N, array<double>^ arr_y, int count)
{
	double* y = new double[count];
	System::Runtime::InteropServices::Marshal::Copy(arr_y, 0, System::IntPtr(y), count);
	delegatePointer = new void*[count];
	for (int i = 0; i < count; i++)
	{
		delegatePointer[i] = (void*)Marshal::GetFunctionPointerForDelegate(fdelegate[i]).ToPointer();
	}
	double* res = myCppClass->Eiler_Paral(delegatePointer, a, b, N, y, count);
	array<double>^ new_res = gcnew array<double>(count);
	System::Runtime::InteropServices::Marshal::Copy(System::IntPtr(res), new_res, 0, count);
	return new_res;
};

/// <summary>
/// Решение системы дифференциальных уравнений методом Рунге-Кутта 2 порядка. Параллельная реализация.
/// </summary>
/// <param name="fdelegate">Массив указателей на функции.</param>
/// <param name="a">Начальное значение интервала.</param>
/// <param name="b">Конечное значение интервала.</param>
/// <param name="N">Количество шагов.</param>
/// <param name="arr_y">Массив с начальными значениями.</param>
/// <param name="count">Количество уравнений.</param>
/// <returns>Массив с найденными значениями.</returns>
array<double>^ math_wrapper::DiffFuncs::RungeKutta2_Paral(array<FDelegate ^>^ fdelegate, double a, double b, int N, array<double>^ arr_y, int count)
{
	double* y = new double[count];
	System::Runtime::InteropServices::Marshal::Copy(arr_y, 0, System::IntPtr(y), count);
	delegatePointer = new void*[count];
	for (int i = 0; i < count; i++)
	{
		delegatePointer[i] = (void*)Marshal::GetFunctionPointerForDelegate(fdelegate[i]).ToPointer();
	}
	double* res = myCppClass->RungeKutta2_Paral(delegatePointer, a, b, N, y, count);
	array<double>^ new_res = gcnew array<double>(count);
	System::Runtime::InteropServices::Marshal::Copy(System::IntPtr(res), new_res, 0, count);
	return new_res;
};

/// <summary>
/// Решение системы дифференциальных уравнений методом Рунге-Кутта 4 порядка. Параллельная реализация.
/// </summary>
/// <param name="fdelegate">Массив указателей на функции.</param>
/// <param name="a">Начальное значение интервала.</param>
/// <param name="b">Конечное значение интервала.</param>
/// <param name="N">Количество шагов.</param>
/// <param name="arr_y">Массив с начальными значениями.</param>
/// <param name="count">Количество уравнений.</param>
/// <returns>Массив с найденными значениями.</returns>
array<double>^ math_wrapper::DiffFuncs::RungeKutta4_Paral(array<FDelegate ^>^ fdelegate, double a, double b, int N, array<double>^ arr_y, int count)
{
	double* y = new double[count];
	System::Runtime::InteropServices::Marshal::Copy(arr_y, 0, System::IntPtr(y), count);
	delegatePointer = new void*[count];
	for (int i = 0; i < count; i++)
	{
		delegatePointer[i] = (void*)Marshal::GetFunctionPointerForDelegate(fdelegate[i]).ToPointer();
	}
	double* res = myCppClass->RungeKutta4_Paral(delegatePointer, a, b, N, y, count);
	array<double>^ new_res = gcnew array<double>(count);
	System::Runtime::InteropServices::Marshal::Copy(System::IntPtr(res), new_res, 0, count);
	return new_res;
};







//================================================================================================
//Перерузки с использованием tau
//================================================================================================

/// <summary>
/// Решение системы дифференциальных уравнений методом Эйлера.
/// </summary>
/// <param name="fdelegate">Массив указателей на функции.</param>
/// <param name="tau">Шаг по времени.</param>
/// <param name="N">Количество шагов.</param>
/// <param name="arr_y">Массив с начальными значениями.</param>
/// <param name="count">Количество уравнений.</param>
/// <returns>Массив с найденными значениями.</returns>
array<double>^ math_wrapper::DiffFuncs::Eiler(array<FDelegate ^>^ fdelegate, double tau, int N, array<double>^ arr_y, int count)
{
	double* y = new double[count];
	System::Runtime::InteropServices::Marshal::Copy(arr_y, 0, System::IntPtr(y), count);
	delegatePointer = new void*[count];
	for (int i = 0; i < count; i++)
	{
		delegatePointer[i] = (void*)Marshal::GetFunctionPointerForDelegate(fdelegate[i]).ToPointer();
	}
	double* res = myCppClass->Eiler(delegatePointer, tau, N, y, count);
	array<double>^ new_res = gcnew array<double>(count);
	System::Runtime::InteropServices::Marshal::Copy(System::IntPtr(res), new_res, 0, count);
	return new_res;
};

/// <summary>
/// Решение системы дифференциальных уравнений методом Рунге-Кутта 2 порядка.
/// </summary>
/// <param name="fdelegate">Массив указателей на функции.</param>
/// <param name="tau">Шаг по времени.</param>
/// <param name="N">Количество шагов.</param>
/// <param name="arr_y">Массив с начальными значениями.</param>
/// <param name="count">Количество уравнений.</param>
/// <returns>Массив с найденными значениями.</returns>
array<double>^ math_wrapper::DiffFuncs::RungeKutta2(array<FDelegate ^>^ fdelegate, double tau, int N, array<double>^ arr_y, int count)
{
	double* y = new double[count];
	System::Runtime::InteropServices::Marshal::Copy(arr_y, 0, System::IntPtr(y), count);
	delegatePointer = new void*[count];
	for (int i = 0; i < count; i++)
	{
		delegatePointer[i] = (void*)Marshal::GetFunctionPointerForDelegate(fdelegate[i]).ToPointer();
	}
	double* res = myCppClass->RungeKutta2(delegatePointer, tau, N, y, count);
	array<double>^ new_res = gcnew array<double>(count);
	System::Runtime::InteropServices::Marshal::Copy(System::IntPtr(res), new_res, 0, count);
	return new_res;
};

/// <summary>
/// Решение системы дифференциальных уравнений методом Рунге-Кутта 4 порядка.
/// </summary>
/// <param name="fdelegate">Массив указателей на функции.</param>
/// <param name="tau">Шаг по времени.</param>
/// <param name="N">Количество шагов.</param>
/// <param name="arr_y">Массив с начальными значениями.</param>
/// <param name="count">Количество уравнений.</param>
/// <returns>Массив с найденными значениями.</returns>
array<double>^ math_wrapper::DiffFuncs::RungeKutta4(array<FDelegate ^>^ fdelegate, double tau, int N, array<double>^ arr_y, int count)
{
	double* y = new double[count];
	System::Runtime::InteropServices::Marshal::Copy(arr_y, 0, System::IntPtr(y), count);
	delegatePointer = new void*[count];
	for (int i = 0; i < count; i++)
	{
		delegatePointer[i] = (void*)Marshal::GetFunctionPointerForDelegate(fdelegate[i]).ToPointer();
	}
	double* res = myCppClass->RungeKutta4(delegatePointer, tau, N, y, count);
	array<double>^ new_res = gcnew array<double>(count);
	System::Runtime::InteropServices::Marshal::Copy(System::IntPtr(res), new_res, 0, count);
	return new_res;
};


//================================================================================================
//================================================================================================
//================================================================================================

/// <summary>
/// Решение системы дифференциальных уравнений методом Эйлера. Параллельная реализация.
/// </summary>
/// <param name="fdelegate">Массив указателей на функции.</param>
/// <param name="tau">Шаг по времени.</param>
/// <param name="N">Количество шагов.</param>
/// <param name="arr_y">Массив с начальными значениями.</param>
/// <param name="count">Количество уравнений.</param>
/// <returns>Массив с найденными значениями.</returns>
array<double>^ math_wrapper::DiffFuncs::Eiler_Paral(array<FDelegate ^>^ fdelegate, double tau, int N, array<double>^ arr_y, int count)
{
	double* y = new double[count];
	System::Runtime::InteropServices::Marshal::Copy(arr_y, 0, System::IntPtr(y), count);
	delegatePointer = new void*[count];
	for (int i = 0; i < count; i++)
	{
		delegatePointer[i] = (void*)Marshal::GetFunctionPointerForDelegate(fdelegate[i]).ToPointer();
	}
	double* res = myCppClass->Eiler_Paral(delegatePointer, tau, N, y, count);
	array<double>^ new_res = gcnew array<double>(count);
	System::Runtime::InteropServices::Marshal::Copy(System::IntPtr(res), new_res, 0, count);
	return new_res;
};

/// <summary>
/// Решение системы дифференциальных уравнений методом Рунге-Кутта 2 порядка. Параллельная реализация.
/// </summary>
/// <param name="fdelegate">Массив указателей на функции.</param>
/// <param name="tau">Шаг по времени.</param>
/// <param name="N">Количество шагов.</param>
/// <param name="arr_y">Массив с начальными значениями.</param>
/// <param name="count">Количество уравнений.</param>
/// <returns>Массив с найденными значениями.</returns>
array<double>^ math_wrapper::DiffFuncs::RungeKutta2_Paral(array<FDelegate ^>^ fdelegate, double tau, int N, array<double>^ arr_y, int count)
{
	double* y = new double[count];
	System::Runtime::InteropServices::Marshal::Copy(arr_y, 0, System::IntPtr(y), count);
	delegatePointer = new void*[count];
	for (int i = 0; i < count; i++)
	{
		delegatePointer[i] = (void*)Marshal::GetFunctionPointerForDelegate(fdelegate[i]).ToPointer();
	}
	double* res = myCppClass->RungeKutta2_Paral(delegatePointer, tau, N, y, count);
	array<double>^ new_res = gcnew array<double>(count);
	System::Runtime::InteropServices::Marshal::Copy(System::IntPtr(res), new_res, 0, count);
	return new_res;
};

/// <summary>
/// Решение системы дифференциальных уравнений методом Рунге-Кутта 4 порядка. Параллельная реализация.
/// </summary>
/// <param name="fdelegate">Массив указателей на функции.</param>
/// <param name="tau">Шаг по времени.</param>
/// <param name="N">Количество шагов.</param>
/// <param name="arr_y">Массив с начальными значениями.</param>
/// <param name="count">Количество уравнений.</param>
/// <returns>Массив с найденными значениями.</returns>
array<double>^ math_wrapper::DiffFuncs::RungeKutta4_Paral(array<FDelegate ^>^ fdelegate, double tau, int N, array<double>^ arr_y, int count)
{
	double* y = new double[count];
	System::Runtime::InteropServices::Marshal::Copy(arr_y, 0, System::IntPtr(y), count);
	delegatePointer = new void*[count];
	for (int i = 0; i < count; i++)
	{
		delegatePointer[i] = (void*)Marshal::GetFunctionPointerForDelegate(fdelegate[i]).ToPointer();
	}
	double* res = myCppClass->RungeKutta4_Paral(delegatePointer, tau, N, y, count);
	array<double>^ new_res = gcnew array<double>(count);
	System::Runtime::InteropServices::Marshal::Copy(System::IntPtr(res), new_res, 0, count);
	return new_res;
};