#pragma once 

#ifndef __CLUB_H
#define __CLUB_H

class Club
{
	private: 
		int years;		//Years of experience

	public:
		Club();
		Club(const Club&);
		~Club();		// if its dosent have char* is it still need d'tor?
};

#endif //__CLUB_H