#ifndef __ROLLER_COASTER_H
#define __ROLLER_COASTER_H

#include <iostream>
#include "facility.h"

class RollerCoaster : virtual public Facility
{
public:
	RollerCoaster(const Facility&  facility,int height,int numOfLoops);
	
	//getters
	int getHeight() const;
	int getNumOfLoops() const;

	//setters
	void setHeight(int height);
	void setNumOfLoops(int numOfLoops);

	//print
	friend std::ostream& operator<<(std::ostream& os, const RollerCoaster& rc)
	{
		os << "RollerCoaster: No Implementation, Impl Here" << std::endl;
		return os;
	}

private:
	int height;
	int numOfLoops;
};

#endif