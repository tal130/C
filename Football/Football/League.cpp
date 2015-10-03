#pragma warning(disable: 4996)

#include <iostream>
#include <string.h>
#include "League.h"

using namespace std;

League::League(char* name, int numberOfTeams, int numberOfGames) :MAXnumberOfTeams(numberOfTeams), MAXnumberOfGames(numberOfGames), numberOfGames(0), numberOfTeams(0), name(NULL), games(NULL), teams(NULL){
	this->setName(name);
	this->teams = new const Team*[MAXnumberOfTeams];
	this->games = new const Game*[MAXnumberOfGames];
}
League::League(const League& other) : name(NULL), games(NULL), teams(NULL){
	*this = other; // = operator
}
League::~League(){
	for (int i = 0; i < numberOfGames; i++){
//		delete this->games[i];
	}
	delete[] this->games;
	for (int i = 0; i < numberOfTeams; i++){
//		delete this->teams[i];
	}
	delete[] this->teams;
}
League& League::operator=(const League& other){
	
	this->MAXnumberOfTeams = other.MAXnumberOfTeams;
	this->numberOfTeams = other.numberOfTeams;
	this->MAXnumberOfGames = other.MAXnumberOfGames;
	this->numberOfGames = other.numberOfGames;
	this->setName(other.name);
<<<<<<< HEAD
	this->teams = new Team*[MAXnumberOfTeams];
	for (int i = 0; i < numberOfTeams; i++){
		this->teams[i] = other.teams[i];
	}
	this->games = new Game*[MAXnumberOfGames];
=======
	this->teams = new const Team*[numberOfTeams];
	for (int i = 0; i < numberOfTeams; i++){
		this->teams[i] = other.teams[i];
	}
	this->games = new const Game*[numberOfGames];
>>>>>>> origin/master
	for (int i = 0; i < numberOfGames; i++){
		this->games[i] = other.games[i];
	}
	return *this;
}

void League::start() const{ //can't be a const method since you want to remove all games from league!
	for (int i = 0; i < numberOfGames; i++){
		games[i]->start();
	}
	//this->numberOfGames = 0;
	//delete[] games;

} //Start all the games in the league and remove them from the league

const League& League::operator+=(const Team& team){
	if (numberOfTeams < MAXnumberOfTeams){
		//teams[numberOfTeams] = &team;
		teams[numberOfTeams] = &team;
		numberOfTeams++;
		//*teams[numberOfTeams++] = team;
	}
	return *this;
}//Add team to the league
const League& League::operator-=(const Team& team){ //problem you define team as object. not as pointer. can't find a way to compare between them
	//solution make == operator for team. or define team by name- i've made it by name
	this->removeTeam(team.getName());
	return *this;
}//Remove team to the league

const League& League::operator+=(const Game& game){
	if (numberOfGames < MAXnumberOfGames){
<<<<<<< HEAD
		*games[numberOfGames++] = game; //the problem was- no operator = in games! this game
=======
		games[numberOfGames] = &game;
		numberOfGames++;
>>>>>>> origin/master
	}
	return *this;
}//Add game to the league

void League::addTeam(const Team& team){
	*this += team;
}//Use operator +=
const Team& League::getTeam(const char* name) const{
	for (int i = 0; i < numberOfTeams; i++) {
		if (strcmp(teams[i]->getName(), name) == 0){
			return *teams[i];
		}
	}
	
}
void League::removeTeam(const char* name){
	for (int i = 0; i < numberOfTeams; i++){
		if (strcmp(name, teams[i]->getName()) == 0){
			//delete this->teams[i];
			//--numberOfTeams;
			//for (int j = i; j < numberOfTeams; j++)
			//	teams[i] = teams[i + 1];
			teams[i] = teams[numberOfTeams];
			numberOfTeams--;
		}
	}
}

const Team** const League::getAllTeams() const{
	return teams;
}
const Game** const League::getAllGames() const{
	return games;
}

const char* League::getName() const{
	return name;
}
void League::setName(const char* name){
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}