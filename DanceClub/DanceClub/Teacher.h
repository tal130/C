#pragma once 

#ifndef __TEACHER_H
#define __TEACHER_H

#include "Human.h"

class Teacher : virtual public Human
{
	static const int MAX_LENGTH= 10;

	protected: 
		int level;
		char style[MAX_LENGTH];

	public:
		Teacher(int level);
		void setStyle(char* style);
		char* getStyle();
		friend ostream& operator<<(ostream& os, const Teacher& t);

};

#endif //__TEACHER_H