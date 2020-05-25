#include "Cage.h"
#include <iostream>

Cage::Cage(size_t input_capacity, Dimensions input_dimensions, category_t input_category, era_t input_era, string input_climate):
	capacity{ input_capacity },
	dimensions{ input_dimensions },
	category{ input_category},
	era{ input_era },
	climate{ input_climate }
{}

Cage::~Cage()
{}

Cage::Cage(const Cage& other) : capacity{ other.capacity }, 
								dimensions{ other.dimensions },
								dinosaurs{ other.dinosaurs },
								category{ other.category },
								era{ other.era },
								climate{ other.climate }
{}

void Cage::swap(Cage& other)
{
	std::swap(capacity, other.capacity);
	std::swap(dinosaurs, other.dinosaurs);
	std::swap(category, other.category);
	std::swap(era, other.era);
	std::swap(climate, other.climate);
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

string Cage::get_climate() const
{
	return climate;
}

int Cage::dinosaur_count() const
{
	return dinosaurs.size();
}

void Cage::remove_dinosaur(string name)
{
	for (size_t i = 0; i < dinosaurs.size(); i++)
	{
		if (dinosaurs[i].get_name() == name)
		{
			dinosaurs.erase(dinosaurs.begin() + i);
			cout << "Removed dinosaur: " << name << endl;
			break;
		}
	}
}

void Cage::list_dinosaurs(ostream& out) const
{
	if (dinosaurs.size() > 0)
	{
		for (size_t i = 0; i < dinosaurs.size(); i++)
		{
			out << i + 1 << ". ";
			dinosaurs[i].print(out);
		}
	}
}

void Cage::print(ostream& out) const
{
	out << "capacity: " << capacity << " "; 
	dimensions.print(out); 
	out << categories[(int)category] << " " << eras[(int)era] << " " << climate << " " << "Dinosaurs in cage: " <<  dinosaurs.size() << endl;
	list_dinosaurs(out);
}

 