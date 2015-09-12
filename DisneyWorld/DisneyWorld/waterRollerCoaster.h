#ifndef __WATER_ROLLER_COASTER_H
#define __WATER_ROLLER_COASTER_H

#include "waterSlide.h"
#include "rollerCoaster.h"
#include "operator.h"

class WaterRollerCoaster : public WaterSlide,public RollerCoaster
{
public:
	WaterRollerCoaster(const WaterSlide& slide,const RollerCoaster& rollerCoaster);

	//print
	friend std::ostream& operator<<(std::ostream& os, const WaterRollerCoaster& wrc)
	{
		os << "WaterRollerCoaster: No Implementation, Impl Here" << std::endl;
		return os;
	}
};

#endif