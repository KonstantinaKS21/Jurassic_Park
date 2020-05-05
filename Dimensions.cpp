#include "Dimensions.h"

Dimensions::Dimensions(double input_x = 0, double input_y = 0, double input_z = 0) : x{ input_x }, y{ input_y }, z{ input_z } 
{}

Dimensions::Dimensions(const Dimensions& other)
{
	x = other.x;
	y = other.y;
	z = other.z;
}

Dimensions& Dimensions::operator=(const Dimensions& other)
{
	x = other.x;
	y = other.y;
	z = other.z;
}