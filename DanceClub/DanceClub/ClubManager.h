#pragma once 

#ifndef __CLUBMANAGER_H
#define __CLUBMANAGER_H

#include "Human.h"

class ClubManager : Human{
private:
	int expirienceYears;
	double income;

public:
	ClubManager(Human& Human, int expirienceYears, int income);

	friend ostream& operator<<(ostream& os, const ClubManager&);
};

#endif //__CLUBMANAGER_H