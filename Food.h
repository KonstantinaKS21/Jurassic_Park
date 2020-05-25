#pragma once
enum class food_t{PLANTS, MEAT, FISH, UNKNOWN};
const static char* foods[4] = { "plants", "meat", "fish" , "unknown"};

struct Food
{

	food_t food;
	double quantity;

	void swap(Food& other);

	Food(food_t, double);
	Food(const Food& other);
	Food& operator=(const Food& other);
};

//may not need this
//delete after