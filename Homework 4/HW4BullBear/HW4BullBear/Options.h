#pragma once
#include<iostream>
#include <stdio.h>
#include <cmath>
#include <string.h>
#include"BinModel.h"

class EurOption
{
private:
	int N; // steps to expiry
public:
	void SetN(int N_) { N = N_; }
	virtual double Payoff(double z) { return 0.0; }
	double PriceByCRR(BinModel Model);
};

class Call : public EurOption
{
private:
	double K; // strike price
public:
	void SetK(double K_) { K = K_; }
	int GetInputData();
	double Payoff(double z);
};

class Put : public EurOption
{
private:
	double K; // strike price
public:
	void SetK(double K_) { K = K_; }
	int GetInputData();
	double Payoff(double z);
};

class Bull : public EurOption
{
private:
	double K1, K2;
public:
	int GetInputData();
	double Payoff(double z);
};

class Bear : public EurOption
{
private:
	double K1, K2;
public:
	int GetInputData();
	double Payoff(double z);
};
