#pragma once
class DefInt
{
// 1. Private members to hold the values of the integration limits a and b and a pointer to the function f
private:
	double a, b;
	double (*f) (double x);
public:
// 2. A constructor function such that the integration limits a, b and the pointer to the function f can be initiated a the time of creating an object of  the class such as DefInt MyInt(a, b, f)
	DefInt(double _a, double _b, double (*_f) (double x));
// 3. A public function ByTrapzoid() taking N as an argument and returning the trapezoidal approximation to the integral when called by MyInt.ByTrapzoidal(N).
	double ByTrapzoid(int N);
// 4. You may also want to include another public function BySimpson() to compute the Simpson approximation to the integral (look it up in the literature).
	double BySimpson(int N);

};

