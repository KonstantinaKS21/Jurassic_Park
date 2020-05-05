#include "Cage.h"
#include <iostream>

Cage::Cage(size_t input_capacity, Dimensions input_dimensions, string input_climate, category_t input_category, era_t input_era): 
	capacity{ input_capacity },
	dimensions{ input_dimensions },
	climate{ input_climate },
	category{ input_category},
	era{ input_era }
{}

Cage::~Cage()
{}

Cage::Cage(const Cage& other) : capacity{ other.capacity }, 
								dimensions{ other.dimensions },
								climate{ other.climate },
								dinosaurs{ other.dinosaurs },
								category{ other.category },
								era{ other.era }
{}

void Cage::swap(Cage& other)
{
	std::swap(capacity, other.capacity);
	std::swap(climate, other.climate);
	std::swap(dinosaurs, other.dinosaurs);
	std::swap(category, other.category);
	std::swap(era, other.era);
}

Cage& Cage::operator=(const Cage& other)
{
	Cage temp{ other };
	swap(temp);
	return *this;
}

bool Cage::has_free_space()
{
	size_t dinosaurs_count = dinosaurs.size();
	if (capacity > dinosaurs_count) return true; //return capacity > dinosaurs.size();
	return false;
}

void Cage::add_new_dinosaur(Dinosaur dinosaur)
{
	dinosaurs.push_back(dinosaur);
}

category_t Cage::get_category() const
{
	return category;
}
era_t Cage::get_era() const
{
	return era;
}