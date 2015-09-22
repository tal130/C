#pragma warning(disable: 4996)

#include <iostream>
#include <string.h>
#include "Team.h"

using namespace std;

Team::Team(const Stadium& stadium, int numberOfStaff, const char* name) : stadium(stadium)
{
	this->numberOfStaff = numberOfStaff;
	strcpy(this->name, name);
	this->staff = new StaffMember*[numberOfStaff];
}
Team::Team(const Team& other) : stadium(other.stadium)
{
	strcpy(this->name, other.name);
	this->numberOfStaff = other.numberOfStaff;
	this->staff = new StaffMember*[numberOfStaff];
	for (int i = 0; i < numberOfStaff;i++)
	{
		this->staff[i] = new StaffMember(*other.staff[i]);
	}
}
Team::~Team()
{
	delete[] this->name;
	for (int i = 0; i < numberOfStaff; i++)
	{
		delete this->staff[i];
	}
	delete[] this->staff;
}


Team& Team::operator = (const Team& other)
{
	strcpy(this->name, other.name);
	this->numberOfStaff = other.numberOfStaff;
	this->stadium = other.stadium;
	this->staff = other.staff;
	return *this;
}

const Team& Team::operator+=(const StaffMember& staffMember)
{
	if (staffInTeam < numberOfStaff)
	{
		*this->staff[staffInTeam] = staffMember;
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
		if (typeid(*this->staff[i]) == typeid(staffMember))
			*this->staff[i] = *this->staff[staffInTeam];
	}
	this->staffInTeam--;
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
	strcpy(this->name, name);
}
void Team::setStadium(const Stadium& stadium)
{
	this->stadium = stadium;
}