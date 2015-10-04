#pragma warning(disable: 4996)

#include <iostream>
#include <string.h>
#include "Game.h"

using namespace std;
int Game::MaxNumberOfReferees = 4;
Game::Game(const Stadium& stadium, Team& team1, const Team& team2/*, const Referee referees[4]*/) : stadium(stadium), 
team1(team1), team2(team2), sizeOfReferees(0), referees(new Referee*[MaxNumberOfReferees])
{
	//for (int i = 0; i < 4; i++)
	//{
	//	this->referees[i] = new Referee(referees[i]);
	//} 
}

void Game::AddReferee(Referee& ref)
{
	if (sizeOfReferees > MaxNumberOfReferees)
		return;
	this->referees[sizeOfReferees++] = &ref;

}

void Game::start() const
{
	int score1 = rand() % 10;
	int score2 = rand() % 10;
	cout << "score is: " << score1 << " : " << score2 << endl << *this;
}