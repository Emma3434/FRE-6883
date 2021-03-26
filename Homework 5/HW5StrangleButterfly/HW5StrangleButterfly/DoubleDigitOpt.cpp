#include "DoubleDigitOpt.h"
#include <iostream>
using namespace std;

int DoubleDigitOpt::GetInputData()
{
	cout << "Enter double-digital option data:" << endl;
	int N;
	cout << "Enter steps to expiry N:	"; cin >> N;
	SetN(N);
	cout << "Enter strike price K1:		"; cin >> K1;
	cout << "Enter strike price K2:		"; cin >> K2;
	cout << endl;
	return 0;
}

double DoubleDigitOpt::Payoff(double z)
{
	if (K1 < z && z < K2) return 1.0;
	return 0.0;
}