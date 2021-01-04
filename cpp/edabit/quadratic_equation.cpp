/*
	Create a function to find only the root value
	of `x` in any quadratic equation `ax^2 + bx + c`.
	The function will take three arguments:
	- `a` as the coefficient of `x^2`
	- `b` as the coefficient of `x`
	- `c` as the constant term
*/

#include <iostream>
#include <cassert>
#include <cmath>

double quadraticEquation(double a, double b, double c)
{
	return (-b +  sqrt((b*b) - (4*a*c))) / (2 * a);
}

int main()
{

	assert(quadraticEquation(1,2,-3) == 1);
	assert(quadraticEquation(2,-7,3) == 3);
	assert(quadraticEquation(1,-12,-28) == 14);
	
	return 0;
}
