#pragma warning(disable: 4996)

#include <iostream>
#include <string.h>
#include "Stadium.h"

using namespace std;

Stadium::Stadium(const string name, int numberOfSeats, const string location)
{
	this->name = name;
	this->numberOfSeats = numberOfSeats;
	this->location = location;
}

//getters
const string Stadium::getName() const
{
	return this->name;
}
int Stadium::getNumberOfSeats() const
{
	return this->numberOfSeats;
}
const string Stadium::getLocation() const
{
	return this->location;
}

//setters
void Stadium::setName(const string name)
{
	
	this->name = name;
}
void Stadium::setNumberOfSeats(int numberOfSeats)
{
	this->numberOfSeats = numberOfSeats;
}
void Stadium::setLocation(const string location)
{
	this->location = location;
}