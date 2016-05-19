// math_wrapper.h

#pragma once
#include "..\matr\MyMatrFuncs.h"
#include "..\matr\MyMatrFuncs.cpp"
using namespace System;

namespace math_wrapper {

	public ref class MatrFuncs
	{
	public: MatrFuncs();
	private:
		MyMatrFuncs *myCppClass;
		// TODO: здесь следует добавить свои методы для этого класса.
	public:
		array<double>^ MatrXVec(array<array<double>^>^ m, array<double>^ v, int n, int k);
	public:
		array<array<double>^>^ MatrTranspon(array<array<double>^>^ m, int n);
	public:
		array<array<double>^>^ MatrXMatr(array<array<double>^>^ m1, array<array<double>^>^ m2, int h1, int w1, int h2, int w2);


	public:
		array<double>^ MatrXVec_NotParal(array<array<double>^>^ m, array<double>^ v, int n, int k);
	public:
		array<array<double>^>^ MatrTranspon_NotParal(array<array<double>^>^ m, int n);
	public:
		array<array<double>^>^ MatrXMatr_NotParal(array<array<double>^>^ m1, array<array<double>^>^ m2, int h1, int w1, int h2, int w2);


		//одномерный массив
	public:
		array<double>^ MatrXVec(array<double>^ m, array<double>^ v, int n, int k);
	public:
		array<double>^ MatrTranspon(array<double>^ m, int n);
	public:
		array<double>^ MatrXMatr(array<double>^ m1, array<double>^ m2, int h1, int w1, int h2, int w2);

	public:
		array<double>^ MatrXVec_NotParal(array<double>^ m, array<double>^ v, int n, int k);
	public:
		array<double>^ MatrTranspon_NotParal(array<double>^ m, int n);
	public:
		array<double>^ MatrXMatr_NotParal(array<double>^ m1, array<double>^ m2, int h1, int w1, int h2, int w2);
	};	
}
