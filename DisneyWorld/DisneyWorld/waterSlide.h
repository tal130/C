#ifndef __WATER_SLIDE_H
#define __WATER_SLIDE_H

#include "facility.h"

class WaterSlide : virtual public Facility
{
public:
	WaterSlide(const Facility& facility, int literOfWater);

	int getLiterOfWater() const;
	void setLiterOfWater(int literOfWater);

	//print
	friend std::ostream& operator<<(std::ostream& os, const WaterSlide& ws)
	{
		os << "WaterSlide: No Implementation, Impl Here" << std::endl;
		return os;
	}

private:
	int literOfWater;
};

#endif