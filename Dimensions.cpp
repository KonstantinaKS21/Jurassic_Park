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
	return *this;
}
void Dimensions::print(ostream& out) const
{
	out <<"dimensions: "<< x << "x" << y << "x" << z << " ";
}
//10x20x30 -> 10, 20, 30  (delim: 'x')

/*ostream& operator<<(ostream& out, const Dimensions& dim)
{
	out << print();
	return out;
} */