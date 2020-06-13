#include "Zoo.h"
#include "Parser.h"
#include <iostream>
#include <cassert>
#include <sstream>

Zoo::Zoo(): plants(food_t::PLANTS, 0), meat(food_t::MEAT, 0), fish(food_t::FISH, 0)
{
	load_from_file("zoo.txt");
	create_random_cages();
}

Zoo::~Zoo()
{
	save_in_file("zoo.txt");
}

void Zoo::load_command() 
{
	string filename;
	cin >> filename;
	load_from_file(filename);
}

void Zoo::save_command()
{
	string filename;
	cin >> filename;
	save_in_file(filename);
}

vector<string> split_string(string& input_str, char delim) //all chars from ss into str until delim
{
	vector<string> result;
	stringstream ss(input_str);
	string str; //empty str; push into vector
	while (getline(ss, str, delim))
	{
		result.push_back(str);  
	}

	return result;
}

Dinosaur Zoo::load_dinosaur(ifstream& file)
{
	string line;
	getline(file, line);
	vector<string> dino_info = split_string(line, ' ');
	// {"(number in cage)", "(name)", "(sex)","(category)","(era)", "(climate)", "(type)", "(food)"}
	string name = dino_info[1];
	sex_t sex = Parser::parse_sex(dino_info[2]);
	category_t category = Parser::parse_category(dino_info[3]);
	era_t era = Parser::parse_era(dino_info[4]);
	string climate = dino_info[5];
	string type = dino_info[6];
	food_t food = Parser::parse_food(dino_info[7]);
	Dinosaur dinosaur(name, sex, category, era, climate, type, food);
	return dinosaur;
}

void Zoo::load_from_file(string filename) 
{
	ifstream input(filename);
	string line_str;
	while (getline(input, line_str))
	{
		vector<string> cage_info = split_string(line_str, ' ');
		//{"capacity:", "(int)capacity", "dimensions:", "doublexdoublexdouble", "(category)", "(era)", "(climate)", "(dino_count)"}
		size_t capacity = stoi(cage_info[1]);
		vector<string> dimensions_str = split_string(cage_info[3], 'x');
		double x = stod(dimensions_str[0]);
		double y = stod(dimensions_str[1]);
		double z = stod(dimensions_str[2]);
		category_t category = Parser::parse_category(cage_info[4]);
		era_t era = Parser::parse_era(cage_info[5]);
		string climate = cage_info[6];
		int dino_count_in_cage = stoi(cage_info[10]);
		Cage new_cage(capacity, Dimensions(x, y, z), category, era, climate);
		for (int i = 0; i < dino_count_in_cage; i++)
		{
			new_cage.add_new_dinosaur(load_dinosaur(input)); //directly adding a dino to the cage
		}
		cages.push_back(new_cage);
	}
	cout << "Successfully loaded from file: " << filename << "\n\n";
}

void Zoo::save_in_file(string filename)
{
	ofstream output(filename, ios::trunc);
	for (size_t i = 0; i < cages.size(); i++)
	{
		cages[i].print(output);
	}

}
void Zoo::create_cage()
{
	size_t capacity;
	string climate, category_str, era_str;
	double x, y, z;
	cin >> capacity >> x >> y >> z >> category_str >> era_str >> climate;
	while (capacity != 1 && capacity != 3 && capacity != 10)  //asserts the cage's capacity
	{
		cout << "Cage's capacity must be for 1(small), 3(medium) or 10(large) dinosaurs.\n";
		cout << "Enter a new capacity value: ";
		cin >> capacity;
	}

	era_t era = Parser::parse_era(era_str);
	category_t category = Parser::parse_category(category_str);
	Dimensions dimensions(x, y, z);
	Cage cage(capacity, dimensions, category, era, climate); //empty cage created
	cages.push_back(cage); //adding a cage to the array of cages 
}

void Zoo::create_random_cages()
{
	srand(time(0));
	int random_cages_count = std::rand() % 21;
	for (int i = 0; i < random_cages_count; i++)
	{
		size_t capacity = std::rand() % 3;//0 1 2
		if (capacity == 0) capacity = 3;
		if (capacity == 1) capacity = 7;
		if (capacity == 2) capacity = 10;
		double x = (std::rand() % 10000);
		x /= 100; //dividing by 100 for a double; capacity of dimensions up to 1000
		double y = (std::rand() % 10000);
		y /= 100;
		double z = (std::rand() % 10000);
		z /= 100;
		int category = std::rand() % 4;
		int era = std::rand() % 3;
		string climates[5]{ "tropical", "dry", "mild", "cold", "polar" };
		int climate = std::rand() % 5;
		Cage random_cage(capacity, Dimensions(x, y, z), (category_t)category, (era_t)era, climates[climate]);
		cages.push_back(random_cage);
	}
	cout << "Randomly created " << random_cages_count << " cages.\n";
}

int Zoo::get_dinosaur_count()
{
	int result = 0;
	for (size_t i = 0; i < cages.size(); i++)
	{
		result += cages[i].dinosaur_count();
	}

	return result;
}

void Zoo::add_dinosaur(Dinosaur dinosaur)
{
	bool cage_found = false;
	for (size_t i = 0; i < cages.size(); i++)
	{
		if (cages[i].get_category() == dinosaur.get_category() && 
			cages[i].get_era() == dinosaur.get_era() &&
			cages[i].get_climate() == dinosaur.get_climate() &&
			cages[i].has_free_space())
		{
			cage_found = true;
			cages[i].add_new_dinosaur(dinosaur);
		}
	}
	if (!cage_found)
	{
		Dimensions dimensions(10, 10, 10);
		Cage cage(10, dimensions, dinosaur.get_category(), dinosaur.get_era(), dinosaur.get_climate()); //creating a cage for a specific dino
		cage.add_new_dinosaur(dinosaur); //adding it to the cage
		cages.push_back(cage);
		cout << "No passing cage found for this dino, creating a new one." << endl;
	}
	if (get_dinosaur_count() > staff_count * 3) //one staff member takes care for no more than 3 dinos
	{
		cout << "Need more staff.\n";
	}

}

bool Zoo::is_food_category_compatible(food_t food, category_t category) //we don't want to give a herbivore dino meat
{
	if (food == food_t::MEAT && category == category_t::HERBIVORE)
	{
		cout << "You cannot give meat to a plant-eating dino.\n";
		return false;
	}

	else if (food == food_t::PLANTS && category == category_t::CARNIVORE)
	{
		cout << "Those dinos prefer meat :).\n";
		return false;
	}
	return true;
}

void Zoo::create_dinosaur()
{
	string name;
	string climate;
	string type;
	string sex_str, era_str, category_str, food_str;
	cin >> name >> sex_str >> category_str >> era_str >> climate >> type >> food_str;
	//assert(sex_str == "female" || sex_str == "male");
	sex_t sex = Parser::parse_sex(sex_str);
	era_t era = Parser::parse_era(era_str);
	category_t category = Parser::parse_category(category_str);
	food_t food = Parser::parse_food(food_str);

	if (!is_food_category_compatible(food, category))
	{
		cout << "Enter another food type: "; 
		cin >> food_str;
		food = Parser::parse_food(food_str);
	}

	Dinosaur dinosaur(name, sex, category, era, climate, type, food);
	
	if (food == food_t::PLANTS) //every dino eats one food of its type
	{
		plants.quantity--;
		if (plants.quantity <= 0)
		{
			cout << "We're running short on plants. Deliver more plants in storage.\n";
		}
	}
	if (food == food_t::MEAT)
	{
		meat.quantity--;
		if (meat.quantity <= 0)
		{
			cout << "We're running short on meat. Deliver more meat in storage.\n";
		}
	}
	if (food == food_t::FISH)
	{
		fish.quantity--;
		if (fish.quantity <= 0)
		{
			cout << "We're running short on fish. Deliver more fish in storage.\n";
		}
	}
	
	add_dinosaur(dinosaur);
}

void Zoo::remove_dinosaur_by_name()
{
	string dino_name;
	cin >> dino_name;
	if (dino_name.empty()) cout << "Enter dino's name.\n";
	for (size_t i = 0; i < cages.size(); i++)
	{
		cages[i].remove_dinosaur(dino_name);
	}
}

void Zoo::deliver_food_in_storage()
{
	string food_type;
	double quantity; //general
	cin >> food_type >> quantity;
	if (food_type == "plants")
	{
		plants.quantity += quantity;
		cout << quantity << " kg plants added to storage.\n";
		cout << "Total plants quantity in storage: " << plants.quantity;
		cout << endl;
	}
	else if (food_type == "meat")
	{
		meat.quantity += quantity;
		cout << quantity << " kg meat added to storage.\n";
		cout << "Total meat quantity in storage: " << meat.quantity;
		cout << endl;
	}
	else if (food_type == "fish")
	{
		fish.quantity += quantity;
		cout << quantity << " kg fish added to storage.\n";
		cout << "Total fish quantity in storage: " << fish.quantity;
		cout << endl;
	}
	else cout << "Dinosaurs don't eat " << food_type << "." << endl;
}

void Zoo::print_food() const
{
	cout << "Food in zoo: " << endl;
	plants.print();
	meat.print();
	fish.print();
}

void Zoo::hire_staff()
{
	staff_count++;
	cout << "A new staff member has arrived.\n";
}

void Zoo::list(ostream& out) const
{
	for (size_t i = 0; i < cages.size(); i++)
	{
		cout << "Cage " << i + 1 << ": " << endl;
		cages[i].print(out);
	}
	
}

void Zoo::clear()
{
	for (size_t i = 0; i < cages.size(); i++)
	{
		cages[i].clear();
	}
	cages.clear();
	cout << "A giant meteorite has suddenly landed on your zoo :( \n";
}
