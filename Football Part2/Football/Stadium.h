#ifndef _STADIUM_H
#define _STADIUM_H

#include <iostream>
#include <string>
using namespace std;

class Stadium
{
public:
	Stadium(const string name, int numberOfSeats, const string location);

	const string getName() const;
	void setName(const string name);

	int getNumberOfSeats() const;
	void setNumberOfSeats(int numberOfSeats);

	const string getLocation() const;
	void setLocation(const string location);

	friend ostream& operator<<(ostream& os, const Stadium& stadium)
	{
		os << "Stadium:" << endl << "name: " << stadium.name << endl << "number of seats: " << stadium.numberOfSeats
			<< " location: " << stadium.location << endl;
		return os;
	}

private:
	string name;
	int numberOfSeats;
	string location;

};

#endif // !_STADIUM_H
