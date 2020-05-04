#pragma once
#include "Cage.h"
#include <vector>
using namespace std;

class Dinazoo
{
private:
	vector<Cage> cages;
	vector<Food> food;

public:

	void create_dinosaur();
	void create_cage();
	void deliver_food();
};

