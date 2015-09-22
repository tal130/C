#pragma warning(disable: 4996)

#include <iostream>
#include <string.h>
#include "Coach.h"

using namespace std;

Coach::Coach(const StaffMember& staffMember, Experties experties) : StaffMember(staffMember)
{
	this->experties = experties;
}

//getters
Coach::Experties Coach::getExperties() const
{
	return this->experties;
}

//setters
void Coach::setExperties(Experties experties)
{
	this->experties = experties;
}