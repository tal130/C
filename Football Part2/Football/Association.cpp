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

Association::Association() : numberOfReferees(0), numberOfLeagues(0), leagues(NULL),referees(NULL){}
Association::~Association(){
	delete[] leagues;
	delete referees;
}

void Association::setNumOfLeagues(int num)
{
	delete[] leagues;
	MAXnumberOfLeagues = num;
	this->leagues = new const League*[MAXnumberOfLeagues];
}

void Association::setNumOfReferees(int num)
{
	delete referees;
	MAXnumberOfReferees = num;
	this->referees = new const Referee*[MAXnumberOfReferees];
}

void Association::start() const{
	for (int i = 0; i < numberOfLeagues; i++) {
		leagues[i]->start();
	}
}

void Association::addLeague(const League& league){ //problem- see document- also, do i need to throw error on maxoverlimit?
	if (numberOfLeagues + 1 < MAXnumberOfReferees)
		leagues[numberOfLeagues++] =  new League(league);
}
const League& Association::getLeague(const char* name) const{
	for (int i = 0; i < numberOfLeagues; i++)
	{
		if (strcmp(leagues[i]->getName(), name) == 0)
			return *leagues[i];
	}
		
}
void Association::removeLeague(const char* name){
	for (int i = 0; i < numberOfLeagues; i++)
	{
		if (strcmp(leagues[i]->getName(), name) == 0){
			delete leagues[i];
			numberOfLeagues--;
			for (int j = i ; j < numberOfLeagues; j++)
				leagues[i] = leagues[i + 1];		
		}
	}

}

void Association::addReferee(const Referee& referee){
	if (numberOfReferees +1 < MAXnumberOfReferees)
		referees[numberOfReferees++] = new Referee(referee);
}
const Referee& Association::getReferee(const char* name) const{
	for (int i = 0; i < numberOfReferees; i++)
	{
		if (strcmp(referees[i]->getName(), name) == 0)
			return *referees[i];
	}
}
void Association::removeReferee(const char* name){
	for (int i = 0; i < numberOfReferees; i++)
	{
		if (strcmp(referees[i]->getName(), name) == 0){
			delete referees[i];
			numberOfReferees--;
			for (int j = i; j < numberOfReferees; j++)
				referees[i] = referees[i + 1];
			//referees = (Referee**)realloc(referees, sizeof(Referee*)*numberOfReferees); -don't need cause you might want to add more
		}
	}

}
