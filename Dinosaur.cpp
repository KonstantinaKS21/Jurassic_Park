#include "Dinosaur.h"
#include <iostream>

Dinosaur::Dinosaur(string input_name, sex_t input_sex, category_t input_category, era_t input_era,
	                string input_climate, string input_type, food_t input_food):
	name{ input_name }, sex{ input_sex }, category{ input_category },
	era{ input_era }, climate{ input_climate },
	type{ input_type }, food{ input_food }
{}

Dinosaur::~Dinosaur() {}

Dinosaur::Dinosaur(const Dinosaur& other): 
	name{ other.name }, sex{ other.sex }, category{ other.category }, era{ other.era }, 
	climate{ other.climate }, type{ other.type }, food{ other.food }
{}

void Dinosaur::swap(Dinosaur& other)
{
	std::swap(name, other.name);
	std::swap(sex, other.sex);
	std::swap(category, other.category);
	std::swap(era, other.era);
	std::swap(climate, other.climate);
	std::swap(type, other.type);
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

string Dinosaur::get_name() const
{
	return name;
}

void Dinosaur::print(ostream& out) const
{
	out << name << " " << sexes[(int)sex] /*cast to int*/ << " " << categories[(int)category]
		 << " " << eras[(int)era]  <<  " " << climate << " " << type << " " << foods[(int)food];
	out << endl; 
}
// {"(name)", "(sex)","(category)","(era)", "(climate)", "(type)", "(food)"}
