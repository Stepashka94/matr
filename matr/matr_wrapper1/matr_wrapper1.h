#pragma once
#include "..\matr\MathFuncs.h"
#include "..\matr\MathFuncs.cpp"
using namespace System;

namespace ClassLibrary1 {

	public ref class MathFuncs
	{
	public: MathFuncs();
		private:
       MyMathFuncs *myCppClass;
		// TODO: здесь следует добавить свои методы для этого класса.
	public:
		array<double>^ MatrXVec(array<array<double>^>^ m, array<double>^ v, int n, int k);
	public:
		array<array<double>^>^ MatrT(array<array<double>^>^ m, int n);
	public:
		array<array<double>^>^ MatrXMatr(array<array<double>^>^ m1, array<array<double>^>^ m2, int h1, int w1, int h2, int w2);
	};
}