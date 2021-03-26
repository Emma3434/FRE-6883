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

// Factorial
double Factorial(int k)
{
	if (k<0) return 0;
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
double PriceByCRR(double S0, double U, double D, double R, int N, double K)
{
	double q = RiskNeutProb(U, D, R);
	double Price = 0.0;
	for (int i = 0; i <= N; i++)
	{
		Price = Price + (Factorial(N) / (Factorial(i) * Factorial(N - i))) * pow(q, i) * pow(1 - q, N - i) * CallPayoff(S(S0, U, D, N, i), K) / pow(1 + R, N);
	}
	return Price;
}

// Price by CRR using remove factorial
double HW1PriceByCRR(double S0, double U, double D, double R, int N, double K)
{
	double q = RiskNeutProb(U, D, R);
	double Price = 0;
	for (int n = 0; n <= N; n++)
	{
		Price = Price + RemoveFactorial(N, n) * pow(q, n) * pow(1 - q, N - n) * CallPayoff(S(S0, U, D, N, n), K) / pow(1 + R, N);
	}
	return Price;
}