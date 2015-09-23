#pragma warning(disable: 4996)

#include <iostream>
#include <string.h>
#include "Stadium.h"

using namespace std;

Stadium::Stadium(const char* name, int numberOfSeats, const char* location) : name(NULL), location(NULL)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->numberOfSeats = numberOfSeats;
	this->location = new char[strlen(location) + 1];
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
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);
	this->numberOfSeats = other.numberOfSeats;
	this->location = new char[strlen(other.location) + 1];
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
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
void Stadium::setNumberOfSeats(int numberOfSeats)
{
	this->numberOfSeats = numberOfSeats;
}
void Stadium::setLocation(const char* location)
{
	this->location = new char[strlen(location) + 1];
	strcpy(this->location, location);
}