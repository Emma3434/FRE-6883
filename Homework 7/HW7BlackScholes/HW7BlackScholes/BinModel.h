#pragma once
#include<iostream>
#include <stdio.h>
class BinModel
{
private:
	double S0;
	double U;
	double D;
	double R;
public:
	//computing risk-neutral probability
	double RiskNeutProb();

	//computing the stock price at node n,i
	double S(int n, int i);

	//inputting, displaying and checking model data
	int GetInputData();
	double GetR();
	double GetS0();
	double GetU();
	double GetD();

	BinModel(double S0_, double U_, double D_, double R_) {
		S0 = S0_; U = U_; D = D_; R = R_;
	}
};