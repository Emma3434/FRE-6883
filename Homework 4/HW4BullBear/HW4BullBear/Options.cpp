#include "Options.h"
#include "BinModel.h"
using namespace std;

// Price by CRR using the CRR formula
double EurOption::PriceByCRR(BinModel Model)
{

	double q = Model.RiskNeutProb();
	double* Price = new double[N + 1];
	for (int i = 0; i <= N; i++)
	{
		Price[i] = Payoff(Model.S(N,i));
	}
	for (int n = N - 1; n >= 0; n--)
	{
		for (int i = 0; i <= n; i++)
		{
			Price[i] = (q * Price[i + 1] + (1 - q) * Price[i]) / (1 + Model.GetR());
		}
	}
	return Price[0];

	delete[] Price;
}

int Call::GetInputData()
{
	cout << "Enter call option data:" << endl;
	int N;
	cout << "Enter steps to expiry N:	"; cin >> N;
	SetN(N);
	cout << "Enter strike price K:		"; cin >> K;
	cout << endl;
	return 0;
}

double Call::Payoff(double z) {
	if (z > K) return z - K;
	return 0.0;
}

int Put::GetInputData()
{
	cout << "Enter put option data:" << endl;
	int N;
	cout << "Enter steps to expiry N:	"; cin >> N;
	SetN(N);
	cout << "Enter strike price K:		"; cin >> K;
	cout << endl;
	return 0;
}

double Put::Payoff(double z) {
	if (z < K) return K - z;
	return 0.0;
}

int Bull::GetInputData()
{
	cout << "Enter European bull spread data:" << endl;
	int N;
	cout << "Enter steps to expiry N:	"; cin >> N;
	SetN(N);
	cout << "Enter strike price K1:		"; cin >> K1;
	cout << "Enter strike price K2:		"; cin >> K2;
	cout << endl;
	return 0;
}

double Bull::Payoff(double z) {
	if (z <= K1) return 0.0;
	else if ((z > K1) && (z < K2)) return z - K1;
	else if (z >= K2) return K2 - K1;
	return 0.0;
}

int Bear::GetInputData()
{
	cout << "Enter European bear spread data:" << endl;
	int N;
	cout << "Enter steps to expiry N:	"; cin >> N;
	SetN(N);
	cout << "Enter strike price K1:		"; cin >> K1;
	cout << "Enter strike price K2:		"; cin >> K2;
	cout << endl;
	return 0;
}

double Bear::Payoff(double z) {
	if (z <= K1) return K2 - K1;
	else if ((z > K1) && (z < K2)) return K2-z;
	else if (z >= K2) return 0.0;
	return 0.0;
}



