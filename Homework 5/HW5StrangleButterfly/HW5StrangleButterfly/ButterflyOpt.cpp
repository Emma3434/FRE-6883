#include "ButterflyOpt.h"
#include <iostream>
using namespace std;

int Butterfly::GetInputData()
{
	cout << "Enter European butterfly spread data:" << endl;
	int N;
	cout << "Enter steps to expiry N:	"; cin >> N;
	SetN(N);
	cout << "Enter strike price K1:		"; cin >> K1;
	cout << "Enter strike price K2:		"; cin >> K2;
	cout << endl;
	return 0;
}

double Butterfly::Payoff(double z) {
	if ((z > K1) && (z <= ((K1 + K2) / 2))) return z - K1;
	else if ((z > ((K1 + K2) / 2)) && (z <= K2)) return K2 - z;
	else return 0.0;
	return 0.0;
}
