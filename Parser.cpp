#include "Parser.h"

era_t Parser::parse_era(string era_value)
{
	if (era_value == "triassic") return era_t::TRIASSIC; //returns enum value 
	if (era_value == "jurassic") return era_t::JURASSIC;
	if (era_value == "cretaceous_periods") return era_t::CRETACEOUS_PERIODS;
	else
	{
		std::cout << "Era unknown: " << era_value << endl;
		return era_t::UNKNOWN;
	}
}

sex_t Parser::parse_sex(string sex_value)
{
	if (sex_value == "male") return sex_t::MALE;
	if (sex_value == "female") return sex_t::FEMALE;
	else
	{
		std::cout << "Sex unknown: " << sex_value << endl;
		return sex_t::UNKNOWN;
	}
}

category_t Parser::parse_category(string category_value)
{
	if (category_value == "carnivore") return category_t::CARNIVORE;
	if (category_value == "herbivore") return category_t::HERBIVORE;
	if (category_value == "pterosaur") return category_t::PTEROSAUR;
	if (category_value == "spinosaur") return category_t::SPINOSAUR;
	else
	{
		std::cout << "Category unknown: " << category_value << endl;
		return category_t::UNKNOWN;
	}
}

food_t Parser::parse_food(string food_value)
{
	if (food_value == "plants") return food_t::PLANTS;
	if (food_value == "meat") return food_t::MEAT;
	if (food_value == "fish") return food_t::FISH;
	else
	{
		std::cout << "Food type unknown: " << food_value << endl;
		return food_t::UNKNOWN;
	}
}