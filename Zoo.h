#pragma once
#include "Cage.h"
#include <vector>
#include <fstream>
#include <time.h> //std::random()
using namespace std;

class Zoo
{
private:
	vector<Cage> cages;
	Food plants;
	Food meat;
	Food fish;
	int staff_count = 0;

	bool is_food_category_compatible(food_t, category_t);

	Dinosaur load_dinosaur(ifstream& file);

public:
	Zoo();
	~Zoo();
	void load_command();
	void save_command();
	void load_from_file(string filename);
	void save_in_file(string filename);
	void create_random_cages();
	void create_dinosaur();
	int get_dinosaur_count();
	void add_dinosaur(Dinosaur);
	void create_cage();
	void remove_dinosaur_by_name();
	void deliver_food_in_storage();
	void print_food() const;
	void hire_staff();
	void list(ostream& out) const;
};

