#pragma once
#include "Options.h"

class Butterfly : public EurOption
{
private:
	double K1, K2;
public:
	int GetInputData();
	double Payoff(double z);
};