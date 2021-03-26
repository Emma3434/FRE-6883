#include "BinModel.h" 
#include "Options.h" 
#include "DoubleDigitOpt.h"
#include "ButterflyOpt.h"
#include "StrangleOpt.h"
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	BinModel Model;
	if (Model.GetInputData() == 1) return 1;

	Call Option1;
	Option1.GetInputData();
	cout << "European call option price = " << Option1.PriceByCRR(Model) << endl << endl;

	Put Option2;
	Option2.GetInputData();
	cout << "European put option price = " << Option2.PriceByCRR(Model) << endl << endl;

	DoubleDigitOpt Option3;
	Option3.GetInputData();
	cout << "European double-digital option price =" << Option3.PriceByCRR(Model) << endl << endl;

	Strangle Option4;
	Option4.GetInputData();
	cout << "European strangle spread price = " << Option4.PriceByCRR(Model) << endl << endl;

	Butterfly Option5;
	Option5.GetInputData();
	cout << "European butterfly spread price = " << Option5.PriceByCRR(Model) << endl << endl;


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

European call option price = 21.68

Enter put option data:
Enter steps to expiry N: 8
Enter strike price K:    100

European put option price = 11.43

Enter double-digital option data:
Enter steps to expiry N: 8
Enter parameter K1:      100
Enter parameter K2:      110

European double-digital option price = 0.26

Enter European strangle option data:
Enter steps to expiry N: 8
Enter parameter K1:      100
Enter parameter K2:      110

European strangle spread option price = 28.39

Enter European butterfly spread option data:
Enter steps to expiry N: 8
Enter parameter K1:      100
Enter parameter K2:      110

European butterfly spread option price = 1.04

*/


