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
		Dancer(int level, const Human& human);
		Dancer(const Dancer&);
		~Dancer();
		Dancer& operator=(const Dancer& other);
		
		void setStyle(const char*);
		const char* getStyle() const;
		void setLevel(const int);
		int getLevel() const;
		const Dancer operator<(const Dancer dancer) const;
		const Dancer operator>(const Dancer dancer) const;

		friend ostream& operator<<(ostream& os, const Dancer& d);

};
#endif //__DANCER_H