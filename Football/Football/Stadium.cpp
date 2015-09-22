#pragma warning(disable: 4996)

#include <iostream>
#include <string.h>
#include "Stadium.h"

using namespace std;

Stadium::Stadium(const char* name, int numberOfSeats, const char* location)
{
	strcpy(this->name, name);
	this->numberOfSeats = numberOfSeats;
	strcpy(this->location, location);
}
Stadium::Stadium(const Stadium& other)
{
	*this = other;
}
Stadium::~Stadium()
{
	delete[] this->name;
	delete[] this->location;
}


Stadium& Stadium::operator=(const Stadium& other)
{
	strcpy(this->name, other.name);
	this->numberOfSeats = other.numberOfSeats;
	strcpy(this->location, other.location);
	return *this;
}


//getters
const char* Stadium::getName() const
{
	return this->name;
}
int Stadium::getNumberOfSeats() const
{
	return this->numberOfSeats;
}
const char* Stadium::getLocation() const
{
	return this->location;
}

//setters
void Stadium::setName(const char* name)
{
	strcpy(this->name, name);
}
void Stadium::setNumberOfSeats(int numberOfSeats)
{
	this->numberOfSeats = numberOfSeats;
}
void Stadium::setLocation(const char* location)
{
	strcpy(this->location, location);
}