#include <iostream>
using namespace std;
class DefInt
{
protected:
	double a, b;
	int N;
	double (*f)(double x);
public:
	DefInt(double a_, double b_, int N_, double (*f_)(double x))
	{
		a = a_; b = b_; N = N_, f = f_;
	}
	virtual double Approximation() = 0;
	virtual ~DefInt() {}
};

class ByTrapezoid : public DefInt
{
public:
	// Complete the implementation of the constructor with parameters for class ByTrapezoid. 
	// You are not allowed to create other member functions.
	ByTrapezoid(double a_, double b_, int N_, double(*f_)(double x)) :DefInt(a_, b_, N_, f_) {}



	double Approximation();
	~ByTrapezoid() {}
};
double ByTrapezoid::Approximation()
{
	cout << "ByTrapezoid: ";
	double h = (b - a) / N;
	double Result = 0.5 * f(a);
	for (int n = 1; n < N; n++) Result += f(a + n * h);
	Result += 0.5 * f(b);
	return Result * h;
}
class BySimpson : public DefInt
{
public:
	// Complete the implementation of the constructor with parameters for class BySimpson. 
	// You are not allowed to create other member functions.
	BySimpson(double a_, double b_, int N_, double(*f_)(double x)) :DefInt(a_, b_, N_, f_) {}


	double Approximation();
	~BySimpson() {}
};

double BySimpson::Approximation()
{
	cout << "BySimpson ";
	double h = (b - a) / N;
	double Result = f(a);
	for (int n = 1; n < N; n++) Result += 4 * f(a + n * h - 0.5 * h) + 2 * f(a + n * h);
	Result += 4 * f(b - 0.5 * h) + f(b);
	return Result * h / 6;
}
class Calculation
{
private:
	DefInt* ptr;
public:
	void SetPtr(DefInt* ptr_)
	{
		ptr = ptr_;
	}
	double Appximation()
	{
		return ptr->Approximation();
	}
};

double f(double x) { return x * x * x - x * x + 1; }

int main()
{
	double a = 1.0;
	double b = 2.0;
	int N = 1000;

	DefInt* ptr1 = new ByTrapezoid(a, b, N, f);
	DefInt* ptr2 = new BySimpson(a, b, N, f);

	Calculation cal1, cal2;

	// Complete the missing codes in main function. You must use cal1 and cal2 for your calculation.
	// You cannot use ptr1 or ptr2 directly for your calculation

	cal1.SetPtr(ptr1);
	cal2.SetPtr(ptr2);

	cout << cal1.Appximation() << endl;
	cout << cal2.Appximation() << endl;

	delete ptr1, ptr2;

	return 0;
}
/*
ByTrapezoid: 2.41667
BySimpson 2.41667
*/
