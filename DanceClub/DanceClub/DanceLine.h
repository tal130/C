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
		DanceLine(int startHour, int startday, const Producer producer);

		const DanceLine operator+(const int days) const;	//startday + days
		const DanceLine& operator--();	//startday --
		void setProducer(const Producer producer);	//set producer to DanceLine
		friend ostream& operator<<(ostream& os, const Producer&);

};

#endif //__DANCELINE_H