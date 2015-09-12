#ifndef __GUEST_H
#define __GUEST_H

#include "person.h"
#include "ticket.h"



class Guest : public Person
{
public:
	static const int AgeTypeSize = 3;
	enum AgeType
	{
		CHILD,
		ADULT,
		ELDER
	};

	enum Feel
	{
		HAPPY,
		AFRAID,
		THRILLED
	};

	Guest(const Person& person, AgeType type, Feel feel);
	
	//getters
	const Ticket& getTicket() const;
	AgeType getType() const;
	Feel getFeel() const;

	//setters
	void setFeel(Feel feel);

	//actions
	void haveFun() const; //print the guest feeling

	//print
	friend std::ostream& operator<<(std::ostream& os, const Guest& g)
	{
		os << "Guest: No Implementation, Impl Here" << std::endl;
		return os;
	}

private:
	Ticket ticket;
	AgeType type;
	Feel feel;
};

#endif