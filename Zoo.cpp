#include "Zoo.h"
#include <iostream>

void Zoo::create_cage()
{
	size_t capacity; 
	double x, y, z;
	int category_value;
	int era_value;
	string climate;
	cin >> capacity >> x >> y >> z >> category_value >> era_value;
	getline(cin, climate);
	era_t era = static_cast <era_t> (era_value);
	category_t category = static_cast <category_t> (category_value);
	Dimensions dimensions(x, y, z);
	Cage cage(capacity, dimensions, climate, category, era); //empty cage created
	cages.push_back(cage); //adding a cage to the array of cages 
}

void Zoo::add_dinosaur(Dinosaur dinosaur)
{
	bool cage_found = false;
	for (size_t i = 0; i < cages.size(); i++)
	{
		if (cages[i].get_category() == dinosaur.get_category() && 
			cages[i].get_era() == dinosaur.get_era() &&
			cages[i].has_free_space())
		{
			cage_found = true;
			cages[i].add_new_dinosaur(dinosaur);
		}
	}
	if (!cage_found)
	{
		Dimensions dimensions(10, 10, 10);
		Cage cage(10, dimensions, dinosaur.get_climate(), dinosaur.get_category(), dinosaur.get_era()); //creating a cage for a specific dino
		cage.add_new_dinosaur(dinosaur); //adding it to the cage
	}
}

void Zoo::create_dinosaur()
{
	string name;
	sex_t sex;
	era_t era;
	category_t category;
	string type;
	string climate;
	food_t food;
	getline(cin, name);
	int sex_value, era_value, category_value, food_value;
	cin >> sex_value >> era_value >> category_value;
	getline(cin, type);
	getline(cin, climate);
	cin >> food_value;
	sex_t sex = static_cast <sex_t> (sex_value);
	era_t era = static_cast <era_t> (era_value);
	category_t category = static_cast <category_t> (category_value);
	food_t food = static_cast <food_t> (food_value);
	Dinosaur dinosaur(name, sex, era, category, type, climate, food);
	add_dinosaur(dinosaur);
}