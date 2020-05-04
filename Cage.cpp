#include "Cage.h"
#include <iostream>


Cage::~Cage()
{}

Cage::Cage(const Cage& other) : capacity { other.capacity }, climate {other.climate}, dinosaurs {other.dinosaurs}, size { other.size }, era { other.era }
{}

void Cage::swap(Cage& other)
{
	std::swap(capacity, other.capacity);
	std::swap(climate, other.climate);
	std::swap(dinosaurs, other.dinosaurs);
	std::swap(size, other.size);
	std::swap(era, other.era);
}

Cage& Cage::operator=(const Cage& other)
{
	Cage temp{ other };
	swap(temp);
	return *this;
}



