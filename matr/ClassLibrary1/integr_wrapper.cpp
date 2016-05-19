#include "stdafx.h"

#include "integr_wrapper.h"
#include "..\matr\MyIntegrFuncs.h"
#include "..\matr\MyIntegrFuncs.cpp"
math_wrapper::IntegrFuncs::IntegrFuncs()
{
	myCppClass = new MyIntegrFuncs();
}

//================================================================================================
//================================================================================================
//================================================================================================

/// <summary>
/// Решение определенного интеграла методом Симпсона. Параллельная реализация.
/// </summary>
/// <param name="fdelegate">Функция.</param>
/// <param name="a">Нижняя граница.</param>
/// <param name="b">Верхняя граница.</param>
/// <param name="N">Количество шагов интегрирования.</param>
/// <returns>Значение интеграла.</returns>
double math_wrapper::IntegrFuncs::Simpson(FDelegate ^ fdelegate, double a, double b, int N)
{
	delegatePointer = (void*)Marshal::GetFunctionPointerForDelegate(fdelegate).ToPointer();//преобразование делегата в указатель на функцию
	return myCppClass->Simpson(delegatePointer, a, b, N);
};

/// <summary>
/// Решение определенного интеграла методом Симпсона 3/8. Параллельная реализация.
/// </summary>
/// <param name="fdelegate">Функция.</param>
/// <param name="a">Нижняя граница.</param>
/// <param name="b">Верхняя граница.</param>
/// <param name="N">Количество шагов интегрирования.</param>
/// <returns>Значение интеграла.</returns>
double math_wrapper::IntegrFuncs::Simpson38(FDelegate ^ fdelegate, double a, double b, int N)
{
	delegatePointer = (void*)Marshal::GetFunctionPointerForDelegate(fdelegate).ToPointer();//преобразование делегата в указатель на функцию
	return myCppClass->Simpson38(delegatePointer, a, b, N);
};

/// <summary>
/// Решение определенного интеграла методом Монте-Карло. Параллельная реализация.
/// </summary>
/// <param name="fdelegate">Функция.</param>
/// <param name="a">Нижняя граница.</param>
/// <param name="b">Верхняя граница.</param>
/// <param name="N">Число испытаний.</param>
/// <returns>Значение интеграла.</returns>
double math_wrapper::IntegrFuncs::MonteKarlo(FDelegate ^ fdelegate, double a, double b, int N)
{
	delegatePointer = (void*)Marshal::GetFunctionPointerForDelegate(fdelegate).ToPointer();
	return myCppClass->MonteKarlo(delegatePointer, a, b, N);
};

//================================================================================================
//================================================================================================
//================================================================================================

/// <summary>
/// Решение определенного интеграла методом Симпсона.
/// </summary>
/// <param name="fdelegate">Функция.</param>
/// <param name="a">Нижняя граница.</param>
/// <param name="b">Верхняя граница.</param>
/// <param name="N">Количество шагов интегрирования.</param>
/// <returns>Значение интеграла.</returns>
double math_wrapper::IntegrFuncs::Simpson_NotParal(FDelegate ^ fdelegate, double a, double b, int N)
{
	delegatePointer = (void*)Marshal::GetFunctionPointerForDelegate(fdelegate).ToPointer();
	return myCppClass->Simpson_NotParal(delegatePointer, a, b, N);
};

/// <summary>
/// Решение определенного интеграла методом Симпсона 3/8.
/// </summary>
/// <param name="fdelegate">Функция.</param>
/// <param name="a">Нижняя граница.</param>
/// <param name="b">Верхняя граница.</param>
/// <param name="N">Количество шагов интегрирования.</param>
/// <returns>Значение интеграла.</returns>
double math_wrapper::IntegrFuncs::Simpson38_NotParal(FDelegate ^ fdelegate, double a, double b, int N)
{
	delegatePointer = (void*)Marshal::GetFunctionPointerForDelegate(fdelegate).ToPointer();
	return myCppClass->Simpson38_NotParal(delegatePointer, a, b, N);
};

/// <summary>
/// Решение определенного интеграла методом Монте-Карло.
/// </summary>
/// <param name="fdelegate">Функция.</param>
/// <param name="a">Нижняя граница.</param>
/// <param name="b">Верхняя граница.</param>
/// <param name="N">Число испытаний.</param>
/// <returns>Значение интеграла.</returns>
double math_wrapper::IntegrFuncs::MonteKarlo_NotParal(FDelegate ^ fdelegate, double a, double b, int N)
{
	delegatePointer = (void*)Marshal::GetFunctionPointerForDelegate(fdelegate).ToPointer();
	return myCppClass->MonteKarlo_NotParal(delegatePointer, a, b, N);
};