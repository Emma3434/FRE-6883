#pragma once
#include "BSModel.h"

class PathDepOption {
public:
    double T, Price, PricingError, delta;
    int m;
    virtual double Payoff(SamplePath& S) = 0;
    double PriceByMC(BSModel Model, long N, double epsilon);
    double PriceByVarRedMC(BSModel Model, long N, PathDepOption& CVOption, double epsilon);
    //cannot pure virtual because we need to calculate arthmAsianCall
    virtual double PriceByBSFormula(BSModel Model) { return 0.0; }
    virtual double DeltaByBSFormula(BSModel Model) { return 0.0; }
};

class DifferenceOfOptions : public PathDepOption {
public:
    PathDepOption* Ptr1;
    PathDepOption* Ptr2;
    DifferenceOfOptions(double T_, int m_, PathDepOption* Ptr1_, PathDepOption* Ptr2_)
    {
        T = T_; m = m_; Ptr1 = Ptr1_; Ptr2 = Ptr2_;
    }
    double Payoff(SamplePath& S)
    {
        return Ptr1->Payoff(S) - Ptr2->Payoff(S);
    }
};

class ArthmAsianCall : public PathDepOption {
public:
    double K;
    ArthmAsianCall(double T_, double K_, int m_)
    {
        T = T_; K = K_; m = m_;
    }
    double Payoff(SamplePath& S);
};



/*Arithmetic call price = 1.42616
Error = 0.000138881
delta = 0.520053

Price by direct MC = 1.42426
Error = 0.0120421
delta = 0.522061
*/