#ifndef _PERSON_H
#define _PERSON_H

#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
	Person(const string name, int age);

	const string getName() const;
	void setName(const string name);

	int getAge() const;
	void setAge(int age);

	friend ostream& operator<<(ostream& os, const Person& p)
	{
		os << "Person:" << endl << "name: " << p.name << endl << "age: " << p.age << endl;
		return os;
	}


private:
	string name;
	int age;


};


#endif // !_PERSON_H
