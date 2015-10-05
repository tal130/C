#pragma warning(disable: 4996)

#include <iostream>
#include <string.h>
#include "League.h"

using namespace std;

League::League(char* name, int numberOfTeams, int numberOfGames) :MAXnumberOfTeams(numberOfTeams), MAXnumberOfGames(numberOfGames), numberOfGames(0), numberOfTeams(0){
	this->setName(name);
}

void League::start() const{
	for (int i = 0; i < numberOfGames; i++){
		games[i]->start();
	}

} //Start all the games in the league

const League& League::operator+=(const Team& team){
	if (numberOfTeams < MAXnumberOfTeams){
		teams.push_back(&team);
		numberOfTeams++;
	}
	return *this;
}//Add team to the league

const League& League::operator-=(const Team& team){
	this->removeTeam(team.getName());
	return *this;
}//Remove team to the league

const League& League::operator+=(const Game& game){
	if (numberOfGames < MAXnumberOfGames){
		games.push_back(&game);
		numberOfGames++;
	}
	return *this;
}//Add game to the league

void League::addTeam(const Team& team){
	*this += team;
}//Use operator +=

const Team& League::getTeam(const string name) const{
	vector<const Team*>::const_iterator itr = teams.begin();
	vector<const Team*>::const_iterator itrEnd = teams.end();
	for (; itr != itrEnd; itr++){
		if (name == (*itr)->getName())
		{
			return *(*itr);
		}
	}
}
void League::removeTeam(const string name){
	vector<const Team*>::const_iterator itr = teams.begin();
	vector<const Team*>::const_iterator itrEnd = teams.end();
	for (; itr != itrEnd; itr++){
		if (name == (*itr)->getName()){
			teams.erase(itr);
			numberOfTeams--;
			return;
		}
	}
}

vector<const Team*> const League::getAllTeams() const{
	return teams;
}
vector<const Game*> const League::getAllGames() const{
	return games;
}

const string League::getName() const{
	return name;
}
void League::setName(const string name){
	this->name = name;
}