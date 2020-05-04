#pragma once
enum class food_t{PLANTS, MEAT, FISH};

class Food
{
private:
	food_t food;
	double quantity;

	void swap(Food& other);

public:
	Food(food_t, double);
	Food(const Food& other);
	Food& operator=(const Food& other);
};

