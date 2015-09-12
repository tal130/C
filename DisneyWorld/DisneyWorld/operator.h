#ifndef __OPERATOR_H
#define __OPERATOR_H

#include "person.h"
#include "ticket.h"

class Operator : public Person
{
public:
	Operator(const Person& person,int id);

	int getID() const;
	void setID(int id);

	//actions
	bool checkTicket(const Ticket& ticket) const; //check if ticket is relevant for the ride 
												  //(AgeTypeAvailable of a facility and if VipTicket required)

	//print
	friend std::ostream& operator<<(std::ostream& os, const Operator& o)
	{
		os << "Operator: No Implementation, Impl Here" << std::endl;
		return os;
	}

private:
	int id;
};

#endif