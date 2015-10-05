#ifndef _STAFFMEMBER_H
#define _STAFFMEMBER_H

#include <iostream>
using namespace std;

#include "Person.h"

class StaffMember: public Person
{
public:
	StaffMember(const Person& person, int sallary, int yearsOfExperience);
	int getSallary() const;
	void setSallary(int sallary);

	int getYearsOfExperience() const;
	void setYearsOfExperience(int yearsOfExperience);

	friend ostream& operator<<(ostream& os, const StaffMember& member)
	{
		os << "salary: " << member.sallary << "yearsOfExperience: " << member.yearsOfExperience << std::endl;
		return os;
	}

private:
	int sallary;
	int yearsOfExperience;
};


#endif // !_STAFFMEMBER_H
