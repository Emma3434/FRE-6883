#pragma once
#include<iostream>
#include <stdio.h>
#include <cmath>
#include <string.h>

//inputting and displaying option data
int GetInputData(int& N, double& K);
//pricing European option
double PriceByCRR(double S0, double U, double D, double R, int N, double K);
//computing call payoff
double CallPayoff(double z, double K);