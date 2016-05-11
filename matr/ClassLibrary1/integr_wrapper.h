#pragma once
#include "..\matr\MyIntegrFuncs.h"
#include "..\matr\MyIntegrFuncs.cpp"
using namespace System;
using namespace System::Runtime::InteropServices;

namespace math_wrapper {
	public ref class IntegrFuncs
	{
	public: IntegrFuncs();
	private:
		MyIntegrFuncs *myCppClass;

		void* delegatePointer;
	public:
		[UnmanagedFunctionPointerAttribute(CallingConvention::Cdecl)] 
		delegate double FDelegate(double x); 
	public:
		double Simpson(FDelegate ^ fdelegate, double a, double b, int N);
	public:
		double Simpson38(FDelegate ^ fdelegate, double a, double b, int N);
	public:
		double MonteKarlo(FDelegate ^ fdelegate, double a, double b, int N);

	public:
		double Simpson_NotParal(FDelegate ^ fdelegate, double a, double b, int N);
	public:
		double Simpson38_NotParal(FDelegate ^ fdelegate, double a, double b, int N);
	public:
		double MonteKarlo_NotParal(FDelegate ^ fdelegate, double a, double b, int N);
	};
}