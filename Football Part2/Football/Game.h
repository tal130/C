#ifndef _GAME_H
#define _GAME_H

#include <iostream>
using namespace std;

#include "Stadium.h"
#include "Team.h"
#include "Referee.h"

class Game
{
public:
	Game(const Stadium& stadium, Team& team1 , const Team& team2 , const Referee referees[4]);

	void start() const; //Show the result of the game (randomly show a score and print the names of the players who scored..)

	friend ostream& operator<<(ostream& os, const Game& game)
	{
		os << game.stadium << endl << game.team1 << endl << game.team2 << endl;
		for (int i = 0; i < 4; i++)
			os << game.referees[i] << endl;
		return os;
	}

private:
	Stadium stadium;
	Team team1;
	Team team2;
	Referee* referees[4];

};

#endif // !_GAME_H