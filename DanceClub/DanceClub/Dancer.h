#pragma once 

#ifndef __DANCER_H
#define __DANCER_H

#include <iostream>
using namespace std;

#include "Human.h"

class Dancer : virtual public Human
{
	protected:
		int level;
		char* style;

	public:
		Dancer(int);	//TODO need to add human to constructor. its vitual so need to check how to do this
		Dancer(const Dancer&);
		~Dancer();
		
		void setStyle(const char*);
		const char* getStyle() const;
		void setLevel(const int);
		const int getLevel() const;
		const Dancer operator<(const Dancer dancer) const;
		const Dancer operator>(const Dancer dancer) const;

		friend ostream& operator<<(ostream& os, const Dancer& d);

};
#endif //__DANCER_H