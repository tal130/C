#ifndef _ASSOCIATION_H
#define _ASSOCIATION_H

#include <iostream>
using namespace std;

#include "League.h"
#include "Referee.h"

class Association
{
public:
	Association(int numberOfLeagues, int numberOfReferees);
	~Association();

	void start() const;//Start all the leagues games (go to all the leagues and start them)

	void addLeague(const League& league);
	const League& getLeague(const char* name) const;
	void removeLeague(const char* name);

	void addReferee(const Referee& referee);
	const Referee& getReferee(const char* name) const;
	void removeReferee(const char* name);

	friend ostream& operator<<(ostream& os, const Association& association)
	{
		os << "Association: " << std::endl;
		for (int i = 0; i < association.numberOfLeagues; i++)
		{
			os << "league #" << i << ": " << association.leagues[i];
		}
		return os;
	}

private:
	const League** leagues;
	int numberOfLeagues;
	int MAXnumberOfLeagues;
	const Referee** referees;
	int numberOfReferees;
	int MAXnumberOfReferees;

	Association(const Association& other);//Cannot duplicate an association
	Association& operator=(const Association& other);
};

#endif // !_ASSOCIATION_H
