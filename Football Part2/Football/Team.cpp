#pragma warning(disable: 4996)

#include <iostream>
#include <string.h>
#include "Team.h"

using namespace std;

Team::Team(const Stadium& stadium, int numberOfStaff, const string name) : stadium(stadium)
{
	this->numberOfStaff = numberOfStaff;
	this->name = name;
}

const Team& Team::operator+=(const StaffMember& staffMember)
{
	if (staffInTeam < numberOfStaff)
	{
		this->staff.push(&staffMember);
		this->staffInTeam++;
	}
	else
		throw std::out_of_range("no more place in the team");
	return *this;
}

const Team& Team::operator-=(const StaffMember& staffMember)
{
	for (int i = 0; i < staffInTeam; i++)
	{
		if (this->staff[i]->getName() == staffMember.getName() && this->staff[i]->getAge() == staffMember.getAge())
		{
			this->staff.DeleteElement(i);
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
		if (this->staff[i]->getName() == name)
			return this->staff[i];
	}
	return NULL;
}
void Team::removeStaffMember(const char* name)
{
	for (int i = 0; i < staffInTeam; i++)
	{
		if (this->staff[i]->getName() == name)
			*this -= *this->staff[i];
	}
}

//getters
const Stadium Team::getStadium() const
{
	return this->stadium;
}
const string Team::getName() const
{
	return this->name;
}

//setters
void Team::setName(const string name)
{
	this->name = name;
}
void Team::setStadium(const Stadium& stadium)
{
	this->stadium = stadium;
}