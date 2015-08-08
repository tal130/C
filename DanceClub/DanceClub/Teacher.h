#pragma once 

#ifndef __TEACHER_H
#define __TEACHER_H

#include "Human.h"

class Teacher : virtual public Human
{
	protected: 
		int level;
		char* style;

	public:
		Teacher();
		Teacher(const Teacher&);
		~Teacher();
};

#endif //__TEACHER_H