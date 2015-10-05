#ifndef _ASSOCIATION_H
#define _ASSOCIATION_H

#include <iostream>
using namespace std;

#include "League.h"
#include "Referee.h"

class Association
{
public:
	static Association* getInstance();

	void start() const;//Start all the leagues games (go to all the leagues and start them)

	void addLeague(const League& league);
	const League& getLeague(const string name) const;
	void removeLeague(const string name);

	void addReferee(const Referee& referee);
	const Referee& getReferee(const string name) const;
	void removeReferee(const string name);

	void setNumOfLeagues(int num);
	void setNumOfReferees(int num);

	friend ostream& operator<<(ostream& os, const Association& association)
	{
		os << "Association: " << std::endl;
		vector<const League*>::const_iterator itr = association.leagues.begin();
		vector<const League*>::const_iterator itrEnd = association.leagues.end();
		for (; itr != itrEnd; itr++)
			os << *(*itr) << std::endl;
		return os;
	}

private:
	vector<const League*> leagues;
	int numberOfLeagues;
	int MAXnumberOfLeagues;
	vector<const Referee*> referees;
	int numberOfReferees;
	int MAXnumberOfReferees;

	static Association theAssociation;

	Association();
};

#endif // !_ASSOCIATION_H
