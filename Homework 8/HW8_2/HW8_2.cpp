#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include "Solver.h"
using namespace std;

class Bond {
private:
	/* Face value F and maturity T.*/
	double F, T;
	/* Fixed coupon C and time t. */
	vector<double> C, t;
public:
	Bond(double F_, double T_, vector<double>& C_, vector<double>& t_) { F = F_, T = T_, C = C_, t = t_; }
	double Value(double y) {
		double P = 0;
		for (unsigned int n = 0; n < C.size(); n++) {
			P += C[n] * exp(-y * t[n]);
		}
		P += F * exp(-y * T);
		return P;
	}
	double Deriv(double y) {
		double D = 0;
		for (unsigned int n = 0; n < C.size(); n++) {
			D += -C[n] * t[n] * exp(-y * t[n]);
		}
		D += -F * T * exp(-y * T);
		return D;
	}
};

int main() {
	cout << setiosflags(ios::fixed) << setprecision(4);
	double F = 100.0;
	double T = 3.0;
	vector<double> C, t;
	for (int i = 0; i < T; i++) {
		C.push_back(1.2);
		t.push_back(i + 1);
	}

	Bond MyBond(F, T, C, t);
	double P = 98.56;
	double Acc = 0.0001;
	double LEnd = 0.0;
	double REnd = 1.0;
	double Guess = 0.2;
	double y1, y2;

	cout << "F = " << F << endl;
	cout << "T = " << T << endl;
	cout << "coupons: " << endl;
	for (int n = 0; n < C.size(); n++) {
		cout << "C" << n << " = " << C[n] << " " << endl;
	}
	cout << "tenors: " << endl;
	for (int n = 0; n < t.size(); n++) {
		cout << "T" << n << " = " << t[n] << " " << endl;
	}
	cout << "P = " << P << endl << endl;

	y1 = SolveByBisect(&MyBond, P, LEnd, REnd, Acc);
	cout << "Yield by bisection method: " << y1 << endl;

	y2 = SolveByNR(&MyBond, P, Guess, Acc);
	cout << "Yield by Newton-Raphson method: " << y2 << endl;
	return 0;
}

/*
F = 100.0000
T = 3.0000
coupons:
C0 = 1.2000
C1 = 1.2000
C2 = 1.2000
tenors :
T0 = 1.0000
T1 = 2.0000
T2 = 3.0000
P = 98.5600

Yield by bisection method : 0.0168
Yield by Newton - Raphson method : 0.0168
*/

