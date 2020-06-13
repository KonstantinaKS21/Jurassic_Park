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
	vector<Dinosaur> dinosaurs;
	category_t category;
	era_t era;
	string climate;

	void swap(Cage& other);

public:
	Cage(size_t, Dimensions, category_t, era_t, string);
	~Cage();
	Cage(const Cage& other);
	Cage& operator=(const Cage& other);
	bool has_free_space();
	void add_new_dinosaur(Dinosaur );
	category_t get_category() const;
	era_t get_era() const;
	string get_climate() const;
	int dinosaur_count() const;
	void remove_dinosaur(string);
	void list_dinosaurs(ostream& out) const;
	void print(ostream& out) const;
	void clear();
};

