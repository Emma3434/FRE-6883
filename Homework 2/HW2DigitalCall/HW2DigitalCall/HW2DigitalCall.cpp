#include "BinModel.h" 
#include "Options.h" 
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
	cout << "European call option price = " << PriceByCRR(S0, U, D, R, N, K, CallPayoff) << endl << endl;
	cout << "European digit call option price = " << PriceByCRR(S0, U, D, R, N, K, DCallPayoff) << endl << endl;

	cout << "Enter put option data:" << endl;
	GetInputData(N, K);
	cout << "European put option price = " << PriceByCRR(S0, U, D, R, N, K, PutPayoff) << endl << endl;
	cout << "European digit put option price = " << PriceByCRR(S0, U, D, R, N, K, DPutPayoff) << endl << endl;

	char exit;
	cout << "Enter e to exit" << endl;
	cin >> exit;
	if (exit == 'e')
	{
		return 0;
	}
	else return 1;
}

/*

Enter S0: 106
Enter U:  0.15125
Enter D:  -0.13138
Enter R:  0.00545

Input data checked
There is no arbitrage

Enter call option data:
Enter steps to expiry N: 8
Enter strike price K:    100

European call option price = 21.6811

European digit call option price = 0.575897

Enter put option data:
Enter steps to expiry N: 8
Enter strike price K:    100

European put option price =  11.4261

European digit put option price =  0.381553

*/