#pragma warning(disable: 4996)

#include <iostream>
#include <string.h>
#include "Person.h"

using namespace std;

Person::Person(const char* name, int age)
{
	strcpy(this->name, name);
	this->age = age;
}
Person::Person(const Person& other)
{
	strcpy(this->name, other.name);
	this->age = other.age;
}
Person::~Person()
{
	delete[] this->name;
}


Person& Person::operator=(const Person& other)
{
	strcpy(this->name, other.name);
	this->age = other.age;
	return *this;
}


//getters
const char* Person::getName() const
{
	return this->name;
}
int Person::getAge() const
{
	return this->age;
}

//setters
void Person::setName(const char* name)
{
	strcpy(this->name, name);
}
void Person::setAge(int age)
{
	this->age = age;
}