#include "BinLattice.h"
#include "BinModel.h"
#include "Option.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	BinModel Model;
	if (Model.GetInputData() == 1) return 1;
	
	ofstream fout;
	fout.open("Results_zw2855.txt");

	Call Option1;
	Option1.GetInputData();
	BinLattice<double> PriceTree1;
	BinLattice<double> X1;
	BinLattice<double> Y1;

	fout << "S0 = " << Model.GetS0() << endl
		<< "U = " << Model.GetU() << endl
		<< "D = " << Model.GetD() << endl
		<< "R = " << Model.GetR() << endl
		<< "N = " << Option1.GetN() << endl
		<< "K = " << Option1.GetK() << endl
		<< "European call prices by PriceByCRR: " << Option1.PriceByCRR(Model) << endl << endl
		<< "European call prices by PriceByCRRHW6: " << Option1.PriceByCRRHW6(Model, PriceTree1,X1, Y1) << endl << endl;
	fout << "Stock positions in replicating strategy:" << endl << endl;
	X1.Display(fout);
	fout << "Money market account positions in replicating strategy:" << endl << endl;
	Y1.Display(fout);



	Put Option2;
	Option2.GetInputData();
	BinLattice<double> PriceTree2;
	BinLattice<double> X2;
	BinLattice<double> Y2;

	fout << "N = " << Option2.GetN() << endl
		<< "K = " << Option2.GetK() << endl
		<< "European put prices by PriceByCRR: " << Option2.PriceByCRR(Model) << endl << endl
		<< "European put prices by PriceByCRRHW6: " << Option2.PriceByCRRHW6(Model, PriceTree2, X2, Y2) << endl << endl;
	fout << "Stock positions in replicating strategy:" << endl << endl;
	X2.Display(fout);
	fout << "Money market account positions in replicating strategy:" << endl << endl;
	Y2.Display(fout);

	return 0;
}

/*
Enter S0 : 106
Enter U : 0.15125
Enter D : -0.13138
Enter R : 0.00545

Input data checked
There is no arbitrage

Enter put option data :
Enter steps to expiry N : 8
Enter strike price K : 100

Enter put option data :
Enter steps to expiry N : 8
Enter strike price K : 100
*/
