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
/// ������� ������������� ��������� ������� ��������. ������������ ����������.
/// </summary>
/// <param name="fdelegate">�������.</param>
/// <param name="a">������ �������.</param>
/// <param name="b">������� �������.</param>
/// <param name="N">���������� ����� ��������������.</param>
/// <returns>�������� ���������.</returns>
double math_wrapper::IntegrFuncs::Simpson(FDelegate ^ fdelegate, double a, double b, int N)
{
	delegatePointer = (void*)Marshal::GetFunctionPointerForDelegate(fdelegate).ToPointer();//�������������� �������� � ��������� �� �������
	return myCppClass->Simpson(delegatePointer, a, b, N);
};

/// <summary>
/// ������� ������������� ��������� ������� �������� 3/8. ������������ ����������.
/// </summary>
/// <param name="fdelegate">�������.</param>
/// <param name="a">������ �������.</param>
/// <param name="b">������� �������.</param>
/// <param name="N">���������� ����� ��������������.</param>
/// <returns>�������� ���������.</returns>
double math_wrapper::IntegrFuncs::Simpson38(FDelegate ^ fdelegate, double a, double b, int N)
{
	delegatePointer = (void*)Marshal::GetFunctionPointerForDelegate(fdelegate).ToPointer();//�������������� �������� � ��������� �� �������
	return myCppClass->Simpson38(delegatePointer, a, b, N);
};

/// <summary>
/// ������� ������������� ��������� ������� �����-�����. ������������ ����������.
/// </summary>
/// <param name="fdelegate">�������.</param>
/// <param name="a">������ �������.</param>
/// <param name="b">������� �������.</param>
/// <param name="N">����� ���������.</param>
/// <returns>�������� ���������.</returns>
double math_wrapper::IntegrFuncs::MonteKarlo(FDelegate ^ fdelegate, double a, double b, int N)
{
	delegatePointer = (void*)Marshal::GetFunctionPointerForDelegate(fdelegate).ToPointer();
	return myCppClass->MonteKarlo(delegatePointer, a, b, N);
};

//================================================================================================
//================================================================================================
//================================================================================================

/// <summary>
/// ������� ������������� ��������� ������� ��������.
/// </summary>
/// <param name="fdelegate">�������.</param>
/// <param name="a">������ �������.</param>
/// <param name="b">������� �������.</param>
/// <param name="N">���������� ����� ��������������.</param>
/// <returns>�������� ���������.</returns>
double math_wrapper::IntegrFuncs::Simpson_NotParal(FDelegate ^ fdelegate, double a, double b, int N)
{
	delegatePointer = (void*)Marshal::GetFunctionPointerForDelegate(fdelegate).ToPointer();
	return myCppClass->Simpson_NotParal(delegatePointer, a, b, N);
};

/// <summary>
/// ������� ������������� ��������� ������� �������� 3/8.
/// </summary>
/// <param name="fdelegate">�������.</param>
/// <param name="a">������ �������.</param>
/// <param name="b">������� �������.</param>
/// <param name="N">���������� ����� ��������������.</param>
/// <returns>�������� ���������.</returns>
double math_wrapper::IntegrFuncs::Simpson38_NotParal(FDelegate ^ fdelegate, double a, double b, int N)
{
	delegatePointer = (void*)Marshal::GetFunctionPointerForDelegate(fdelegate).ToPointer();
	return myCppClass->Simpson38_NotParal(delegatePointer, a, b, N);
};

/// <summary>
/// ������� ������������� ��������� ������� �����-�����.
/// </summary>
/// <param name="fdelegate">�������.</param>
/// <param name="a">������ �������.</param>
/// <param name="b">������� �������.</param>
/// <param name="N">����� ���������.</param>
/// <returns>�������� ���������.</returns>
double math_wrapper::IntegrFuncs::MonteKarlo_NotParal(FDelegate ^ fdelegate, double a, double b, int N)
{
	delegatePointer = (void*)Marshal::GetFunctionPointerForDelegate(fdelegate).ToPointer();
	return myCppClass->MonteKarlo_NotParal(delegatePointer, a, b, N);
};