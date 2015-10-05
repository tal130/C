#ifndef _TEAM_H
#define _TEAM_H

#include <iostream>
using namespace std;

#include "StaffMember.h"
#include "Stadium.h"
#include "ArrayList.h"

class Team
{
public:
	Team(const Stadium& stadium, int numberOfStaff, const string name);

	const Team& operator+=(const StaffMember& staffMember);
	const Team& operator-=(const StaffMember& staffMember);

	void addStaff(const StaffMember& staffmember);
	const StaffMember* getStaffMember(const char* name) const;
	void removeStaffMember(const char* name);

	const Stadium getStadium() const;
	void setStadium(const Stadium& stadium);

	const string getName() const;
	void setName(const string name);

	friend ostream& operator<<(ostream& os, const Team& team)
	{
		os << "Team name: " << team.name << endl;
		return os;
	}

private:
	string name;
	int numberOfStaff;
	ArrayList<const StaffMember*> staff;
	Stadium stadium;
	int staffInTeam = 0;

};

#endif // !_TEAM_H
