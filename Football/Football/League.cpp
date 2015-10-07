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

	}
	delete[] this->games;
	for (int i = 0; i < numberOfTeams; i++){

	}
	delete[] this->teams;
}
League& League::operator=(const League& other){
	
	this->MAXnumberOfTeams = other.MAXnumberOfTeams;
	this->numberOfTeams = other.numberOfTeams;
	this->MAXnumberOfGames = other.MAXnumberOfGames;
	this->numberOfGames = other.numberOfGames;
	this->setName(other.name);
	this->teams = new const Team*[numberOfTeams];
	for (int i = 0; i < numberOfTeams; i++){
		this->teams[i] = other.teams[i];
	}
	this->games = new const Game*[numberOfGames];
	for (int i = 0; i < numberOfGames; i++){
		this->games[i] = other.games[i];
	}
	return *this;
}

void League::start() const{ 
	for (int i = 0; i < numberOfGames; i++){
		games[i]->start();
	}

} //Start all the games in the league 

const League& League::operator+=(const Team& team){
	if (numberOfTeams < MAXnumberOfTeams){
		teams[numberOfTeams] = &team;
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
		games[numberOfGames] = &game;
		numberOfGames++;
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
	throw "no such team exist";
}
void League::removeTeam(const char* name){
	for (int i = 0; i < numberOfTeams; i++){
		if (strcmp(name, teams[i]->getName()) == 0){
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