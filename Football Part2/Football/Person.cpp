#pragma warning(disable: 4996)

#include <iostream>
#include <string.h>
#include "Person.h"

using namespace std;

Person::Person(const string name, int age)
{
	this->name = name;
	this->age = age;
}

//getters
const string Person::getName() const
{
	return this->name;
}
int Person::getAge() const
{
	return this->age;
}

//setters
void Person::setName(const string name)
{
	this->name = name;
}
void Person::setAge(int age)
{
	this->age = age;
}