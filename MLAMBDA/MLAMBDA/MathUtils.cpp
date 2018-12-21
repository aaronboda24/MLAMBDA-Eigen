/*
* MathUtils.h
* Functions for custom math operations
* This altered file only includes operation for ARLAMBDA
* As described in GPStk : https://github.com/SGL-UT/GPSTk
* Created on: Aug 17, 2018
*      Author: Aaron
*/

#include "pch.h"
#include "MathUtils.h"

using namespace std;

const double PI = 3.1415926535898;

// Changing Sign
double sign(double x)
{
	return (x <= 0.0) ? -1.0 : 1.0;
}

// Rounding Values
double round(double x)
{
	return double(std::floor(x + 0.5));
}

// Swapping values
void swap(double& a, double& b)
{
	double t(a); a = b; b = t;
}
