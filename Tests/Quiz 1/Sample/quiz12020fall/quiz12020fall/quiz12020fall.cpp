#include <iostream>
using namespace std;
class DefInt
{
protected:
    double a, b;
public:
    DefInt(double a_, double b_)
    {
        a = a_; b = b_;
    }
    virtual ~DefInt() {}
    double f(double x) { return x * x * x - x * x + 1; }
    virtual double calculateDefInt() { return 0; };
    DefInt() { a = 0; b = 0; }
};
class ByTrapezoid : public DefInt
{
private:
    int N;
public:
    ~ByTrapezoid() {}
    double calculateDefInt();

    ByTrapezoid(double a_, double b_, int N_)
    {
        a = a_;
        b = b_;
        N = N_;
    }
};
double ByTrapezoid::calculateDefInt()
{
    cout << "ByTrapezoid ";
    double h = (b - a) / N;
    double Result = 0.5 * f(a);
    for (int n = 1; n < N; n++) Result += f(a + n * h);
    Result += 0.5 * f(b);
    return Result * h;
}
class BySimpson : public DefInt
{
private:
    int N;
public:
    ~BySimpson() {}
    double calculateDefInt();

    BySimpson(double a_, double b_, int N_)
    {
        a = a_;
        b = b_;
        N = N_;
    }
};

double BySimpson::calculateDefInt()
{
    cout << "BySimpson ";
    double h = (b - a) / N;
    double Result = f(a);
    for (int n = 1; n < N; n++) Result += 4 * f(a + n * h - 0.5 * h) + 2 * f(a + n * h);
    Result += 4 * f(b - 0.5 * h) + f(b);
    return Result * h / 6;
}

double Quiz1(DefInt* ptr)
{
    return ptr->calculateDefInt();
}

int main()
{
    double a = 1.0;
    double b = 2.0;
    int N = 1000;

    ByTrapezoid* ptr1 = new ByTrapezoid(a, b, N);
    BySimpson* ptr2 = new BySimpson(a, b, N);

    cout << "Calculate DefInt: " << Quiz1(ptr1) << endl;
    cout << "Calculate DefInt: " << Quiz1(ptr2) << endl;









    return 0;
}

/*
ByTrapezoid Calculate DefInt: 2.41667
BySimpson Calculate DefInt: 2.41667
*/


