#include "StrangleOpt.h"
#include <iostream>
using namespace std;

int Strangle::GetInputData()
{
	cout << "Enter European strangle spread data:" << endl;
	int N;
	cout << "Enter steps to expiry N:	"; cin >> N;
	SetN(N);
	cout << "Enter strike price K1:		"; cin >> K1;
	cout << "Enter strike price K2:		"; cin >> K2;
	cout << endl;
	return 0;
}

double Strangle::Payoff(double z) {
	if (z <= K1) return K1 - z;
	else if ((z > K1) && (z <= K2)) return 0.0;
	else if (z > K2) return z - K2;
	return 0.0;
}