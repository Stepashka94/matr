#pragma once
#include "..\matr\MyDiffFuncs.h"
#include "..\matr\MyDiffFuncs.cpp"
using namespace System;
using namespace System::Runtime::InteropServices;

namespace math_wrapper {
	public ref class DiffFuncs
	{
	public: DiffFuncs();
	private:
		MyDiffFuncs *myCppClass;

		void** delegatePointer;
	public:
		[UnmanagedFunctionPointerAttribute(CallingConvention::Cdecl)] 
		delegate double FDelegate(double x, double* y); 
	public:
		array<double>^ Eiler(array<FDelegate ^>^ fdelegate, double a, double b, int N, array<double>^ arr_y, int count);
	public:
		array<double>^ RungeKutta2(array<FDelegate ^>^ fdelegate, double a, double b, int N, array<double>^ arr_y, int count);
	public:
		array<double>^ RungeKutta4(array<FDelegate ^>^ fdelegate, double a, double b, int N, array<double>^ arr_y, int count);


	public:
		array<double>^ Eiler_Paral(array<FDelegate ^>^ fdelegate, double a, double b, int N, array<double>^ arr_y, int count);
	public:
		array<double>^ RungeKutta2_Paral(array<FDelegate ^>^ fdelegate, double a, double b, int N, array<double>^ arr_y, int count);
	public:
		array<double>^ RungeKutta4_Paral(array<FDelegate ^>^ fdelegate, double a, double b, int N, array<double>^ arr_y, int count);




	//==============================================================================================
	//Перегрузки с использованием tau
	//==============================================================================================

	public:
		array<double>^ Eiler(array<FDelegate ^>^ fdelegate, double tau, int N, array<double>^ arr_y, int count);
	public:
		array<double>^ RungeKutta2(array<FDelegate ^>^ fdelegate, double tau, int N, array<double>^ arr_y, int count);
	public:
		array<double>^ RungeKutta4(array<FDelegate ^>^ fdelegate, double tau, int N, array<double>^ arr_y, int count);


	public:
		array<double>^ Eiler_Paral(array<FDelegate ^>^ fdelegate, double tau, int N, array<double>^ arr_y, int count);
	public:
		array<double>^ RungeKutta2_Paral(array<FDelegate ^>^ fdelegate, double tau, int N, array<double>^ arr_y, int count);
	public:
		array<double>^ RungeKutta4_Paral(array<FDelegate ^>^ fdelegate, double tau, int N, array<double>^ arr_y, int count);
	};
}