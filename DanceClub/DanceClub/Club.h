#pragma once 

#ifndef __CLUB_H
#define __CLUB_H

#include "Address.h"
#include "DanceLine.h"
#include "team.h"
#include "ClubManager.h"

class Club
{
	static const int MAXLINES= 7; 

	private: 
		int maxPeople;
		Address address;
		ClubManager manager;
		DanceLine lines[MAXLINES];
		Team** team;


	public:
		Club(ClubManager manager, Address address, int maxPeople = 300, Team** team = nullptr);
		Club(const Club&);
		~Club();	

		void setManager(const ClubManager manager);	//set manager to club
		void addTeam(const Team& team);		//add team to list of teams
		void addDanceLine(const DanceLine& line);	//according to the day of the line enter the line to the array in correct index
		const Club operator<(const Club club) const; //which club consist more dancers
		const Club operator>(const Club club) const;
		const Club operator==(const Club club) const;
};

#endif //__CLUB_H