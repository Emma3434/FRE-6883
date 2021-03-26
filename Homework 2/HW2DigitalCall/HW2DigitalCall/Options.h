#pragma once
#include<iostream>
#include <stdio.h>
#include <cmath>
#include <string.h>

// inputting and displaying option data
int GetInputData(int& N, double& K);

// pricing European option
double PriceByCRR(double S0, double U, double D, double R, int N, double K, double (*Payoff)(double z, double K));

// computing call payoff
double CallPayoff(double z, double K);

// computing put payoff
double PutPayoff(double z, double K);

// computing digital call payoff
double DCallPayoff(double z, double K);

// computing digital put payoff
double DPutPayoff(double z, double K);

double RemoveFactorial(int N, int n);
double Factorial(int k);
