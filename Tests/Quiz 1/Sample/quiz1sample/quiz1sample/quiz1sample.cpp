#include <iostream>
using namespace std;
class DefInt
{
protected:
	double a, b;
	int N;
	double (*f)(double x);
public:
	DefInt(double a_, double b_, int N_,
		double (*f_)(double x)) : a(a_), b(b_), N(N_), f(f_) {}
	virtual ~DefInt() {}
	virtual double ByNumApprximation() = 0;
};

class Trapezoid : public DefInt
{
public:
	Trapezoid(double a_, double b_, int N_,
		double (*f_)(double x)) :DefInt(a_, b_, N_, f_) {}
	double ByNumApprximation();
};
class Simpson : public DefInt
{
public:
	Simpson(double a_, double b_, int N_,
		double (*f_)(double x)) :DefInt(a_, b_, N_, f_) {}
	double ByNumApprximation();
};
class Midpoint : public DefInt
{
public:
	Midpoint(double a_, double b_, int N_,
		double (*f_)(double x)) :DefInt(a_, b_, N_, f_) {}
	double ByNumApprximation();
};

double Trapezoid::ByNumApprximation(void)
{
	cout << "ByTrapezoid: ";
	double h = (b - a) / N;
	double Result = 0.5 * f(a);
	for (int n = 1; n < N; n++) Result += f(a + n * h);
	Result += 0.5 * f(b);
	return Result * h;
}
double Simpson::ByNumApprximation(void)
{
	cout << "BySimpson: ";
	double h = (b - a) / N;
	double Result = f(a);
	for (int n = 1; n < N; n++) Result += 4 * f(a + n * h - 0.5 * h) + 2 * f(a + n * h);
	Result += 4 * f(b - 0.5 * h) + f(b);
	return Result * h / 6;
}

double Midpoint::ByNumApprximation(void)
{
	cout << "ByMidpoint: ";
	double h = (b - a) / N;
	double Result = 0;
	for (int n = 0; n < N - 1; n++)
		Result += f(a + (0.5 + n) * h);
	Result = h * (Result + f(b));
	return Result;
}

double f(double x) { return x * x * x - x * x + 1; }

double Quiz1(DefInt &ob)
{
	return ob.ByNumApprximation();
}

int main()
{
	double a = 1.0;
	double b = 2.0;
	int N = 1000;
	Trapezoid MyTrapzoid(a, b, N, f);
	Simpson MySimpson(a, b, N, f);
	Midpoint MyMidpoint(a, b, N, f);

	cout << Quiz1(MyTrapzoid) << endl;
	cout << Quiz1(MySimpson) << endl;
	cout << Quiz1(MyMidpoint) << endl;

	return 0;
}



/*
ByTrapezoid: 2.41667
BySimpson: 2.41667
ByMidpoint: 2.41667
Press any key to continue . . .
*/
