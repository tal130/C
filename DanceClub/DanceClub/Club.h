#pragma once 

#ifndef __CLUB_H
#define __CLUB_H

#include "Address.h"
#include "DanceLine.h"
#include "team.h"

class Club
{
	private: 
		Address address;
		DanceLine lines[10];
		Team* team;

	public:
		Club();
		Club(const Club&);
		~Club();		
};

#endif //__CLUB_H