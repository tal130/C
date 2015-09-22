#ifndef _TEAM_H
#define _TEAM_H

#include <iostream>
using namespace std;

#include "StaffMember.h"
#include "Stadium.h"

class Team
{
public:
	Team(const Stadium& stadium, int numberOfStaff, const char* name);
	Team(const Team& other);
	~Team();
	Team& operator=(const Team& other);

	const Team& operator+=(const StaffMember& staffMember);
	const Team& operator-=(const StaffMember& staffMember);

	void addStaff(const StaffMember& staffmember);
	const StaffMember* getStaffMember(const char* name) const;
	void removeStaffMember(const char* name);

	const Stadium getStadium() const;
	void setStadium(const Stadium& stadium);

	const char* getName() const;
	void setName(const char* name);

	friend ostream& operator<<(ostream& os, const Team& team)
	{
		os << "Team name: " << team.name << endl;
		return os;
	}

private:
	char* name;
	int numberOfStaff;
	StaffMember** staff;
	Stadium stadium;
	int staffInTeam = 0;

};

#endif // !_TEAM_H
