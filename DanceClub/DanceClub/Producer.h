#pragma once 

#ifndef __PRODUCER_H
#define __PRODUCER_H

#include "Teacher.h"
#include "Dancer.h"
#include "Human.h"

class Producer : public Teacher, public Dancer
{
	private: 
		int years;		//Years of experience

	public:
		Producer(const Teacher& teacher, const Dancer& dancer, int years) : Human(dancer.getName(), dancer.getAge()), Dancer(dancer.getLevel()), Teacher(5){}
		Producer(const Producer&);
		~Producer();		// if its dosent have char* is it still need d'tor?
};

#endif //__PRODUCER_H