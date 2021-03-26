#include "BinModel01.h" 
#include "Options01.h" 
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double S0 = 0, U = 0, D = 0, R = 0;
	if (GetInputData(S0, U, D, R) == 1) return 1;

	double K = 0;   //strike price
	int N = 0;      //steps to expiry
	cout << "Enter call option data:" << endl;
	GetInputData(N, K);

	cout << "European call option price = " << PriceByCRR(S0, U, D, R, N, K) << endl << endl; return 0;
}
