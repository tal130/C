#pragma once 

#ifndef __TEAM_H
#define __TEAM_H

#include "Dancer.h"
#include "Teacher.h"

class Team
{

private:
	Dancer ** dancers;
	Teacher teacher;

public:
	Team(const Teacher& teacher,int numOfDancers=10);
	~Team();
	Team(const Team&);

	void addDancer(Dancer* dancer);
	friend ostream& operator<<(ostream& os, const Team& team);
};

#endif //__TEAM_H