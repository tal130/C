#pragma warning(disable: 4996)

#include <iostream>
#include <string.h>
#include "Referee.h"

using namespace std;

Referee::Referee(const Person& person, Position position) : Person(person)
{
	this->position = position;
}

//getters
Referee::Position Referee::getPosition() const
{
	return this->position;
}

//setters
void Referee::setPosition(Position experties)
{
	this->position = position;
}