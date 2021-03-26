#pragma once
#include "Options.h"

class DoubleDigitOpt: public EurOption
{
private:
	double K1;
	double K2;
public:
	int GetInputData();
	double Payoff(double z);
};

