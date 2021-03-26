#include "Options.h"
#include "BinModel.h"
using namespace std;

int GetInputData(int& N, double& K)
{
	cout << "Enter steps to expiry N:	"; cin >> N;
	cout << "Enter strike price K:		"; cin >> K;
	cout << endl;
	return 0;
}

double CallPayoff(double z, double K) {
	if (z > K) return z - K;
	return 0.0;
}

double PutPayoff(double z, double K) {
	if (z < K) return K - z;
	return 0.0;
}

double DCallPayoff(double z, double K) {
	if (z > K) return 1.0;
	return 0.0;
}

double DPutPayoff(double z, double K) {
	if (z < K) return 1.0;
	return 0.0;
}

// Factorial
double Factorial(int k)
{
	if (k < 0) return 0;
	double result = 1;
	for (int i = 1; i <= k; ++i)
	{
		result *= i;
	}
	return result;
}

// Factorial remove function
double RemoveFactorial(int N, int n)
{
	if (n<0 || n>N) return 0;
	double result = 1;
	for (int i = 1; i <= n; i++) result = result * (N - n + i) / i;
	return result;
}

// Price by CRR using the CRR formula
double PriceByCRR(double S0, double U, double D, double R, int N, double K, double (*Payoff)(double z, double K))
{

	double q = RiskNeutProb(U, D, R);
	double* Price = new double[N + 1];
	for (int i = 0; i <= N; i++)
	{
		Price[i] = Payoff(S(S0, U, D, N, i), K);
	}
	for (int n = N - 1; n >= 0; n--)
	{
		for (int i = 0; i <= n; i++)
		{
			Price[i] = (q * Price[i + 1] + (1 - q) * Price[i]) / (1 + R);
		}
	}
	return Price[0];

	delete Price;
	delete[] Price;
}
