#pragma once 

#ifndef __CLUBSNETWORK_H
#define __CLUBSNETWORK_H

#include "Club.h"

class ClubsNetwork
{
	static const int MAX_LENGTH= 5;
	private:
		Club* clubs[MAX_LENGTH];

	public:
		ClubsNetwork();
		//ClubsNetwork(const ClubsNetwork&);
		//~ClubsNetwork();
		
		void addClub(Club* club);
		static Club* biggestClub();

};
#endif //__CLUBSNETWORK_H