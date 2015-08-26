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
		Producer(const Teacher& teacher, const Dancer& dancer, int years) : 
			Human(dancer.getName(), dancer.getAge()), Dancer(dancer.getLevel(),  Human( dancer.getName(), dancer.getAge() ) ), Teacher(teacher.getLevel()){}

		friend ostream& operator<<(ostream& os, const Producer& );

};

#endif //__PRODUCER_H