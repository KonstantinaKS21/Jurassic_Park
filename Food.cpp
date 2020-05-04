#include "Food.h"
#include <iostream>

Food::Food(food_t input_food, double input_quantity): food { input_food }, quantity { input_quantity }
{}

Food::Food(const Food& other): food { other.food }, quantity { other.quantity }
{}

void Food::swap(Food& other)
{
	std::swap(food, other.food);
	std::swap(quantity, other.quantity);
}

Food& Food::operator=(const Food& other)
{
	Food temp{ other };
	swap(temp);
	return *this;
}
