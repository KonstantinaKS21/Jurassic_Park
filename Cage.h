#pragma once
#include "Dinosaur.h"
#include <vector>
using namespace std;

class Cage
{
private:
	size_t capacity;
	string climate;
	vector<Dinosaur> dinosaurs;
	size_t size; 
	era_t era;

	void swap(Cage& other);

public:

	~Cage();
	Cage(const Cage& other);
	Cage& operator=(const Cage& other);
	//void add_new_dinosaur();
	//void remove_dinosaur();
	void fill_food_storage();
};

