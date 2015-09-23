#pragma warning(disable: 4996)

#include <iostream>
#include <string.h>
#include "StaffMember.h"

using namespace std;

StaffMember::StaffMember(const Person& person, int sallary, int yearsOfExperience) : Person(person)
{
	this->sallary = sallary;
	this->yearsOfExperience = yearsOfExperience;
}
//getters
int StaffMember::getSallary() const
{
	return this->sallary;
}
int StaffMember::getYearsOfExperience() const
{
	return this->yearsOfExperience;
}

//setters
void StaffMember::setSallary(int salary)
{
	this->sallary = salary;
}
void StaffMember::setYearsOfExperience(int yearsOfExperience)
{
	this->yearsOfExperience = yearsOfExperience;
}