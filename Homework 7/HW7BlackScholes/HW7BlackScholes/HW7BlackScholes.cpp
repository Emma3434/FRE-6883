#include "BinLattice.h"
#include "BinModel.h"
#include "Options.h"
#include "BSModel.h"

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	double S0 = 106.0;
	double r = 0.058;
	double sigma = 0.46;
	double T = (double)9 / 12;
	double K = 100.0;
	int N = 8;

	cout << setiosflags(ios::fixed) << setprecision(5);

	cout << "S0 = " << S0 << endl;
	cout << "r = " << r << endl;
	cout << "sigma = " << sigma << endl;
	cout << "T = " << T << endl;
	cout << "K = " << K << endl;
	cout << "N = " << N << endl;
	cout << endl;

	BSModel Model(S0, r, sigma);
	double h = T / N;
	BinModel ApproxModel = Model.ApproxBinModel(h);

	cout << "U = " << ApproxModel.GetU() << endl;
	cout << "D = " << ApproxModel.GetD() << endl;
	cout << "R = " << ApproxModel.GetR() << endl;

	Call Option(N, K);
	BinLattice<double> PriceTree;
	BinLattice<bool> StoppingTree;

	Option.PriceBySnell(ApproxModel, PriceTree, StoppingTree);
	cout << "American call option price = "
		<< PriceTree.GetNode(0, 0)
		<< endl << endl;

	return 0;
}

/*
S0 = 106.00000
r = 0.05800
sigma = 0.46000
T = 0.75000
K = 100.00000
N = 8
U = 0.14610
D = -0.13526
R = 0.00545
American call option price = 21.33399
*/