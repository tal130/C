#pragma once 

#ifndef __TEAM_H
#define __TEAM_H

#include "Dancer.h"
#include "Teacher.h"

class Team{
private:
	Dancer ** dancers;
	Teacher teacher;

public:
	Team(const Teacher& teacher, const Dancer ** const dancers = nullptr);
	~Team();
	Team(const Team&);
};

#endif //__TEAM_H