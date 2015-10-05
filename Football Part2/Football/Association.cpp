#pragma warning(disable: 4996)

#include <iostream>
#include <string.h>
#include "Association.h"

using namespace std;

Association Association::theAssociation;

Association* Association::getInstance()
{
	return &theAssociation;
}

Association::Association() : numberOfReferees(0), numberOfLeagues(0){}

void Association::setNumOfLeagues(int num)
{
	MAXnumberOfLeagues = num;
}

void Association::setNumOfReferees(int num)
{
	MAXnumberOfReferees = num;
}

void Association::start() const{
	for (int i = 0; i < numberOfLeagues; i++) {
		leagues[i]->start();
	}
}

void Association::addLeague(const League& league){
	if (numberOfLeagues + 1 < MAXnumberOfReferees)
		leagues.push_back(&league);
}

const League& Association::getLeague(const string name) const{
	vector<const League*>::const_iterator itr = leagues.begin();
	vector<const League*>::const_iterator itrEnd = leagues.end();
	for (; itr != itrEnd; itr++)
	{
		{
			if ((*itr)->getName() == name)
				return *(*itr);
		}
	}
}
void Association::removeLeague(const string name)
{
	vector<const League*>::const_iterator itr = leagues.begin();
	vector<const League*>::const_iterator itrEnd = leagues.end();
	for (; itr != itrEnd; itr++)
	{
		if ((*itr)->getName() == name)
		{
			leagues.erase(itr);
			numberOfLeagues--;
		}
	}
}

void Association::addReferee(const Referee& referee){
	if (numberOfReferees +1 < MAXnumberOfReferees)
		referees.push_back(&referee);
}
const Referee& Association::getReferee(const string name) const{
	vector<const Referee*>::const_iterator itr = referees.begin();
	vector<const Referee*>::const_iterator itrEnd = referees.end();
	for (; itr != itrEnd; itr++)
	{
		if ((*itr)->getName() == name)
			return *(*itr);
	}
}
void Association::removeReferee(const string name){
	vector<const Referee*>::const_iterator itr = referees.begin();
	vector<const Referee*>::const_iterator itrEnd = referees.end();
	for (; itr != itrEnd; itr++)
	{
		if ((*itr)->getName() == name)
		{
			referees.erase(itr);
			numberOfReferees--;
		}
	}

}
