#pragma once
#include "Food.h"
#include <string>
using namespace std;

enum class era_t {TRIASSIC, JURASSIC, CRETACEOUS_PERIODS, UNKNOWN};
enum class category_t{HERBIVORE, CARNIVORE, PTEROSAUR, SPINOSAUR, UNKNOWN};
enum class sex_t {FEMALE, MALE, UNKNOWN};

const static char* eras[4] = {"triassic", "jurassic", "cretaceous_periods", "unknown" };
const static char* categories[5] = { "herbivore","carnivore", "pterosaur", "spinosaur", "unknown" };
const static char* sexes[3] = { "female", "male", "unknown" };

class Dinosaur
{
private:
	string name;
	sex_t sex;
	category_t category;
	era_t era;
	string climate;
	string type;
	food_t food;

	void swap(Dinosaur& other);

public:
	Dinosaur(string, sex_t, category_t, era_t, string, string, food_t);
	~Dinosaur();
	Dinosaur(const Dinosaur& other);
	Dinosaur& operator=(const Dinosaur& other);
	category_t get_category() const;
	era_t get_era() const;
	string get_climate() const;
	string get_name() const;
	void print(ostream& out) const;
};

