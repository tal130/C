#pragma warning(disable: 4996)

#include <iostream>
#include <string.h>
#include "Team.h"

using namespace std;

Team::Team(const Stadium& stadium, int numberOfStaff, const char* name) : stadium(stadium)
{
	this->numberOfStaff = numberOfStaff;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->staff = new const StaffMember*[numberOfStaff];
}
Team::Team(const Team& other) : stadium(other.stadium)
{
	*this = other;
}
Team::~Team()
{
	delete[] this->name;

	delete[] this->staff;
}


Team& Team::operator = (const Team& other)
{
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);
	this->numberOfStaff = other.numberOfStaff;
	this->stadium = other.stadium;
	this->staff = new const StaffMember*[other.numberOfStaff];
	for (int i = 0; i < other.staffInTeam; i++)
		this->staff[i] = other.staff[i];
	return *this;
}

const Team& Team::operator+=(const StaffMember& staffMember)
{
	if (staffInTeam < numberOfStaff)
	{
		this->staff[staffInTeam] = &staffMember;
	
		this->staffInTeam++;
	}
	else
		cout << "no more place in the team\n";
	return *this;
}

const Team& Team::operator-=(const StaffMember& staffMember)
{
	for (int i = 0; i < staffInTeam; i++)
	{
		if (strcmp(this->staff[i]->getName(), staffMember.getName()) == 0 && this->staff[i]->getAge() == staffMember.getAge())
		{
			this->staff[i] = this->staff[staffInTeam--];
		
			break;
		}
	}
	return *this;
}

void Team::addStaff(const StaffMember& staffmember)
{
	*this += staffmember;
}
const StaffMember* Team::getStaffMember(const char* name) const
{
	for (int i = 0; i < staffInTeam; i++)
	{
		if (strcmp(this->staff[i]->getName(), name) == 0)
			return this->staff[i];
	}
	return NULL;
}
void Team::removeStaffMember(const char* name)
{
	for (int i = 0; i < staffInTeam; i++)
	{
		if (strcmp(this->staff[i]->getName(), name) == 0)
			*this -= *this->staff[i];
	}
}

//getters
const Stadium Team::getStadium() const
{
	return this->stadium;
}
const char* Team::getName() const
{
	return this->name;
}

//setters
void Team::setName(const char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
void Team::setStadium(const Stadium& stadium)
{
	this->stadium = stadium;
}