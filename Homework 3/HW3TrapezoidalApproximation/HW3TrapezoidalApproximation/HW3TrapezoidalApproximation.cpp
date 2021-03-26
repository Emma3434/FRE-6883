// HW3TrapezoidalApproximation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "DefInt.h"
using namespace std;

double f(double x)
{
    return x * x * x - x * x + 1;
}

int main()
{
    double a = 1.0;
    double b = 2.0;
    int N = 0;
    DefInt MyInt(a, b, *f);

    cout << "Please input a valid N:" << endl;
    cin >> N;

    cout << "The results are as follows for N = "<< N << endl;
    cout << "Trapzoid approximation:" << MyInt.ByTrapzoid(N) << endl;
    cout << "Simpson approximation:" << MyInt.BySimpson(N) << endl;

    char exit;
    cout << "Enter e to exit" << endl;
    cin >> exit;
    if (exit == 'e')
    {
        return 0;
    }
    else return 1;

    /*
    Please input a valid N:
    100
    The results are as follows for N = 100
    Trapzoid approximation:2.41673
    Simpson approximation:2.41667
    */
}

