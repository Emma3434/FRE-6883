# include <iostream>
#include "PathDepOption.h"
using namespace std;

int main() {
    double S0 = 100., r = 0.03, sigma = 0.2;
    BSModel Model(S0, r, sigma);

    double T = 1.0 / 12.0, K = 100.0;
    int m = 30;
    ArthmAsianCall Option(T, K, m);

    long N = 30000;
    double epsilon = 0.001;
    Option.PriceByMC(Model, N, epsilon);
    cout << "Asian Call Price = " << Option.Price << endl
        << "   Pricing Error = " << Option.PricingError << endl
        << "           delta = " << Option.delta << endl
        << "           gamma = " << Option.gamma << endl;
}
/*Asian Call Price = 1.42989
   Pricing Error = 0.0120819
           delta = 0.523591
           gamma = 0.122154*/