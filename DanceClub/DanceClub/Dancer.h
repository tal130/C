#pragma once 
//#pragma warning(disable: 4996)

#ifndef __DANCER_H
#define __DANCER_H

#include "Human.h"

class Dancer : public Human
{
	protected:
		int level;
		char* style;

	public:
		Dancer();
		~Dancer();
		
		void setStyle(const char*);
		const char* getStyle() const;

		void toString() const;
};
#endif //__DANCER_H