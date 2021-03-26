#include "DefInt.h"
#include <iostream>
using namespace std;
DefInt::DefInt(double _a, double _b, double (*_f) (double x))
{
	a = _a;
	b = _b;
	f = _f;
}

double DefInt::ByTrapzoid(int N)
{
	double h = (b - a) / N;
	double sum = f(a) + f(b);
	for (int k = 1; k < N; k++)
	{
		//cout << sum << endl;
		sum += 2 * f(a + k * h);
	}
	return (h / 2) * sum;
}

double DefInt::BySimpson(int N) 
{
	if (N % 2 != 0)
	{
		cout << "N must be an even number to use Simpson rule." << endl;
		return 0;
	}
	else {
		double h = (b - a) / N;
		double sum = f(a);
		for (int k = 1; k < N; k++)
		{
			if (k % 2 == 0) sum += 2 * f(a + k * h);
			else sum += 4 * f(a + k * h);
		}
		sum += f(b);
		return (h / 3) * sum;
	}
}