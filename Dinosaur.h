#pragma once
#include "Food.h"
#include <string>
using namespace std;

enum class era_t {TRIASSIC, JURASSIC, CRETACEOUS_PERIODS};
enum class category_t{HERBIVORES, CARNIVORES, PTEROSAURS, SPINOSAURUS};
enum class sex_t {FEMALE, MALE};

class Dinosaur
{
private:
	string name;
	sex_t sex;
	era_t era;
	category_t category;
	string type;
	string climate;
	food_t food;


	void swap(Dinosaur& other);
public:
	Dinosaur(string, sex_t, era_t, category_t, string, string, food_t);
	~Dinosaur();
	Dinosaur(const Dinosaur& other);
	Dinosaur& operator=(const Dinosaur& other);
	category_t get_category() const;
	era_t get_era() const;
	string get_climate() const;
};

