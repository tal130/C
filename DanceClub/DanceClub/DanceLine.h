#pragma once 

#ifndef __DANCELINE_H
#define __DANCELINE_H

#include "Producer.h"

class DanceLine
{
	private: 
		int startHour;
		int startday;
		Producer producer;

	public:
		DanceLine(int startHour, int startday, Producer producer);

		DanceLine operator+(const DanceLine& other) const;
		const DanceLine& operator--();
};

#endif //__DANCELINE_H