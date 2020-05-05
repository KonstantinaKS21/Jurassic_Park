#include "Dinosaur.h"
#include <iostream>

Dinosaur::Dinosaur(string input_name, sex_t input_sex, era_t input_era, category_t input_category, 
					string input_type, string input_climate, food_t input_food):
	name{ input_name }, sex{ input_sex }, era{ input_era }, 
	category{ input_category }, type{ input_type }, 
	climate{input_climate}, food{ input_food }
{}

Dinosaur::~Dinosaur() {}

Dinosaur::Dinosaur(const Dinosaur& other): 
	name{ other.name }, sex{ other.sex }, era{ other.era }, category{ other.category }, 
	type{ other.type }, climate{ other.climate },food{ other.food }
{}

void Dinosaur::swap(Dinosaur& other)
{
	std::swap(name, other.name);
	std::swap(sex, other.sex);
	std::swap(era, other.era);
	std::swap(category, other.category);
	std::swap(type, other.type);
	std::swap(climate, other.climate);
	std::swap(food, other.food);
}

Dinosaur& Dinosaur::operator=(const Dinosaur& other)
{
	Dinosaur temp{ other };
	swap(temp);
	return *this;
}

category_t Dinosaur::get_category() const
{
	return category;
}

era_t Dinosaur::get_era() const
{
	return era;
}

string Dinosaur::get_climate() const
{
	return climate;
}