#pragma once 

#ifndef __DANCER_H
#define __DANCER_H

#include "Human.h"

class Dancer : virtual public Human
{
	protected:
		int level;
		char* style;

	public:
		Dancer(const int);
		Dancer(const Dancer&);
		~Dancer();
		
		void setStyle(const char*);
		const char* getStyle() const;
		void setLevel(const int);
		const int getLevel() const;
		const Dancer operator<(const Dancer dancer) const;
		const Dancer operator>(const Dancer dancer) const;

};
#endif //__DANCER_H