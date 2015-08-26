#pragma once 
//#pragma warning(disable: 4996)

#ifndef __HUMAN_H
#define __HUMAN_H

#include "Address.h"

class Human
{
	protected:
		char* name;
		int age;
		Address address;

	public:
		Human(const char* name, int age);
		Human(const Human&);
		~Human();
		
		void setName(const char*);
		const char* getName() const;
		void setAge(const int);
		const int getAge() const;
		virtual friend ostream& operator<<(ostream& os, const Human&);

};
#endif //__HUMAN_H