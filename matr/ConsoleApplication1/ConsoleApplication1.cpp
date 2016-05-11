// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "..\matr\MyIntegrFuncs.h"
#include "..\matr\MyIntegrFuncs.cpp"

double F(double x)
{
	return x*x;
}

int _tmain(int argc, _TCHAR* argv[])
{
	MyIntegrFuncs *myCppClass = new MyIntegrFuncs();
		
		double res = myCppClass->Simpson(F,0,10,100000);
		printf("Simpson paral - %f\n", res);
		res = myCppClass->Simpson38(F,0,10,100000);
		printf("Simpson38 paral - %f\n", res);
		res = myCppClass->MonteKarlo(F,0,10,1000000);
		printf("MonteKarlo paral - %f\n", res);

		res = myCppClass->Simpson_NotParal(F,0,10,100000);
		printf("Simpson - %f\n", res);		
		res = myCppClass->Simpson38_NotParal(F,0,10,100000);
		printf("Simpson38 - %f\n", res);
		res = myCppClass->MonteKarlo_NotParal(F,0,10,100000);
		printf("MonteKarlo - %f\n", res);
		getchar();
	return 0;
}

