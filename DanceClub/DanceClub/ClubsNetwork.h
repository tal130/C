#pragma once 

#ifndef __CLUBSNETWORK_H
#define __CLUBSNETWORK_H

#include "Club.h"

class ClubsNetwork
{
	private:
		Club** clubs;

	public:
		ClubsNetwork();
		ClubsNetwork(const ClubsNetwork&);
		~ClubsNetwork();
		
		void addClub(Club* club);
		static Club* biggestClub();

};
#endif //__CLUBSNETWORK_H