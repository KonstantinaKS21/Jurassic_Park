#pragma once
#include "Cage.h"
#include <vector>
using namespace std;

class Zoo
{
private:
	vector<Cage> cages;
	vector<Food> food;
	//void find_cage(Dinosaur );

public:
	void create_dinosaur();
	void add_dinosaur(Dinosaur);
	void create_cage();
	void deliver_food();
};

