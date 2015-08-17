#pragma once 

#ifndef __CLUBMANAGER_H
#define __CLUBMANAGER_H

#include "Human.h"

class ClubManager : Human{
private:
	int expirienceYears;
	double income;

public:
	ClubManager(Human& Human, const int expirienceYears, const int income);
	ClubManager(const ClubManager&);
};

#endif //__CLUBMANAGER_H