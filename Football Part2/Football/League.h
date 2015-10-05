#ifndef _LEAGUE_H
#define _LEAGUE_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Team.h"
#include "Game.h"

class League
{
public:
	League(char* name, int numberOfTeams, int numberOfGames);

	void start() const; //Start all the games in the league and remove them from the league

	const League& operator+=(const Team& team);//Add team to the league
	const League& operator-=(const Team& team);//Remove team to the league

	const League& operator+=(const Game& game);//Add game to the league

	void addTeam(const Team& team);//Use operator +=
	const Team& getTeam(const string name) const;
	void removeTeam(const string name);

	vector<const Team*> const getAllTeams() const;
	vector<const Game*> const getAllGames() const;

	const string getName() const;
	void setName(const string name);

	friend ostream& operator<<(ostream& os, const League& league)
	{
		os << "league name: " << league.name << "teams:\n" << std::endl;
		vector<const Team*>::const_iterator itr = league.teams.begin();
		vector<const Team*>::const_iterator itrEnd = league.teams.end();
		for (; itr != itrEnd ; itr++)
			os << *(*itr) << std::endl;
		return os;
	}

private:
	int MAXnumberOfTeams;
	int numberOfTeams;
	vector<const Team*> teams;
	int MAXnumberOfGames;
	int numberOfGames;
	vector<const Game*> games;
	string name;

};

#endif // !_LEAGUE_H
