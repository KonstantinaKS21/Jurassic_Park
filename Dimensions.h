#pragma once
#include <iostream>
using namespace std; 

struct Dimensions
{
	double x;
	double y;
	double z;

	Dimensions(double, double, double);
	Dimensions(const Dimensions& other);
	Dimensions& operator=(const Dimensions& other);
	void print(ostream& out) const;
};
