#pragma warning(disable: 4996)

#include <iostream>
#include <string.h>
#include "Game.h"

using namespace std;
int Game::MaxNumberOfReferees = 4;

Game::Game(const Stadium& stadium,const Team& team1, const Team& team2) : stadium(stadium), 
team1(team1), team2(team2), sizeOfReferees(0){}

void Game::AddReferee(Referee& ref)
{
	if (sizeOfReferees > MaxNumberOfReferees)
		throw std::out_of_range("no more place for refrees");
	this->referees.push_back(&ref);
}

void Game::start() const
{
	int score1 = rand() % 10;
	int score2 = rand() % 10;
	cout << "score is: " << score1 << " : " << score2 << endl << *this;
}