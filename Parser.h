#pragma once
#include "Dinosaur.h"
#include <iostream>

struct Parser
{
	static era_t parse_era(string );
	static sex_t parse_sex(string);
	static category_t parse_category(string);
	static food_t parse_food(string);
};

