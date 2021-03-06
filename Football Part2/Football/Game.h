#ifndef _GAME_H
#define _GAME_H

#include <iostream>
#include <vector>
using namespace std;

#include "Stadium.h"
#include "Team.h"
#include "Referee.h"

class Game
{
public:
	Game(const Stadium& stadium,const Team& team1 , const Team& team2);

	void start() const; //Show the result of the game (randomly show a score and print the names of the players who scored..)

	void AddReferee(Referee& ref);

	friend ostream& operator<<(ostream& os, const Game& game)
	{
		os << game.stadium << endl << game.team1 << endl << game.team2 << endl;
		for (int j = 0; j < 4; j++)
		os << *game.referees[j] << endl;
		return os;
	}

private:
	Stadium stadium;
	Team team1;
	Team team2;
	vector<const Referee*> referees;
	int sizeOfReferees;
	static int MaxNumberOfReferees;

};

#endif // !_GAME_H
