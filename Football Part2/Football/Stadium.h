#ifndef _STADIUM_H
#define _STADIUM_H

#include <iostream>
using namespace std;

class Stadium
{
public:
	Stadium(const char* name, int numberOfSeats,const char* location);
	Stadium(const Stadium& other);
	~Stadium();
	Stadium& operator=(const Stadium& other);

	const char* getName() const;
	void setName(const char* name);

	int getNumberOfSeats() const;
	void setNumberOfSeats(int numberOfSeats);

	const char* getLocation() const;
	void setLocation(const char* location);

	friend ostream& operator<<(ostream& os, const Stadium& stadium)
	{
		os << "Stadium:" << endl << "name: " << stadium.name << endl << "number of seats: " << stadium.numberOfSeats
			<< "location: " << stadium.location << endl;
		return os;
	}

private:
	char* name;
	int numberOfSeats;
	char* location;

};

#endif // !_STADIUM_H
