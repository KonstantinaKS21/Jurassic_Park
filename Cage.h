#pragma once
#include "Dinosaur.h"
#include "Dimensions.h"
#include <vector>
using namespace std;

class Cage
{
private:
	size_t capacity; //max size for different types of cages(1, 3, 10 animals)
	Dimensions dimensions;
	string climate;
	category_t category;
	vector<Dinosaur> dinosaurs;
	era_t era;

	void swap(Cage& other);

public:
	Cage(size_t, Dimensions, string, category_t, era_t);
	~Cage();
	Cage(const Cage& other);
	Cage& operator=(const Cage& other);
	bool has_free_space();
	void add_new_dinosaur(Dinosaur );
	category_t get_category() const;
	era_t get_era() const;
	//void remove_dinosaur();
	void fill_food_storage();
};

