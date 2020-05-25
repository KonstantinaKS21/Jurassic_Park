#include "Zoo.h"
#include <iostream>
using namespace std;

void static print_help() 
{
    cout << "============== Jurassic Park ===============\n\n";
    cout << "1. help                                                                   - print this help\n";
    cout << "2. create_dino <name> <sex> <category> <era> <climate> <type> <food>      - adds a dinosaur to the zoo\n";
    cout << "3. create_cage <capacity> <dimensions: x,y,z> <category> <era> <climate>  - creates a new cage\n";
    cout << "4. remove_dino  <name>                                                    - removes a dinosaur from the zoo\n";
    cout << "5. deliver_food  <food_type> <quantity>                                   - adds food to the storage\n";
    cout << "6. list                                                                   - prints info for the cage\n";
    cout << "7. hire_staff                                                             - adds new memeber to the staff\n";
    cout << "8. create_random_cages                                                    - creates a random number of random cages\n";
    cout << "9. save_as <filename>                                                     - saves data in file <filename>\n";
    cout << "10. load_from <filename>                                                  - reads data from file <filename>\n";
    cout << "11. exit                                                                   - exit program\n\n";
}

void run_program(Zoo& zoo)
{
    print_help();
    string command;
    bool in_action = true;
    while (in_action)
    {
        cout << "\n> ";
        cin >> command;
        if (command == "help") print_help();
        else if (command == "create_dino")
        {
            zoo.create_dinosaur();
            cout << "You have successfully added a dinosaur to the zoo.\n";
        }
        else if (command == "create_cage")
        {
            zoo.create_cage();
            cout << "You have successfully created a cage for your dinosaurs.\n";
        }
        else if (command == "remove_dino")
        {
            zoo.remove_dinosaur_by_name();
            cout << "You have successfully made a dinosaur homeless :( and freed space.\n";
        }
        else if (command == "deliver_food")
        {
            zoo.deliver_food_in_storage();
        }
        else if (command == "hire_staff")
        {
            zoo.hire_staff();
        }
        else if (command == "list")
        {
            zoo.list(cout);
        }
        else if (command == "create_random_cages")
        {
            zoo.create_random_cages();
        }
        else if (command == "save_as")
        {
            zoo.save_command();
            cout << "You have successfully saved your data in this file.\n";
        }
        else if (command == "load_from")
        {
            zoo.load_command();
        }
        else if (command == "exit")
        {
            cout << "Exiting zoo...\n" << "Goodbye!!!" << endl;
            in_action = false;
        }
        else
        {
            cout << "Wrong command.\n";
            print_help();
        }
    }
}

//TESTS:
void test_create_dino(Zoo& zoo)
{
    Dinosaur dino_1("ina", sex_t::FEMALE, category_t::CARNIVORE, era_t::JURASSIC, "polar", "type_1", food_t::PLANTS);
    Dinosaur dino_2("bobi", sex_t::MALE, category_t::CARNIVORE, era_t::JURASSIC, "polar", "type_2", food_t::MEAT);
    Dinosaur dino_3("kiki", sex_t::MALE, category_t::HERBIVORE, era_t::TRIASSIC, "polar", "type_3", food_t::FISH);
    zoo.add_dinosaur(dino_1);
    zoo.add_dinosaur(dino_2);
    zoo.add_dinosaur(dino_3);
    zoo.list(cout);
}

void test_remove_dino(Zoo& zoo)
{
    Dinosaur dino_1("ina", sex_t::FEMALE, category_t::CARNIVORE, era_t::JURASSIC, "polar", "type_1", food_t::MEAT);
    zoo.add_dinosaur(dino_1);
    cout << "ADDED\n";
    cout << "ENTER NAME\n";
    zoo.remove_dinosaur_by_name();
    cout << "REMOVED\n";
    zoo.list(cout);
}

void test_create_cage(Zoo& zoo)
{
    Dimensions dimensions_cage_1(2.4, 17, 23.6);
    Dimensions dimensions_cage_2(4.3, 19, 20.6);
    Cage cage_1(10, dimensions_cage_1, category_t::CARNIVORE, era_t::JURASSIC, "polar");
    Cage cage_2(2, dimensions_cage_2, category_t::SPINOSAUR, era_t::TRIASSIC, "sunny");
}

int main()
{
    Zoo zoo;
    //test_create_dino(zoo);
    // zoo.load_from_file("zoo.txt");
    // zoo.list(cout);

    run_program(zoo);

    //  zoo.save_in_file("zoo.txt");
    // test_remove_dino(zoo);
    //test_create_cage(zoo);

    return 0;
}