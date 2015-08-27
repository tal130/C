#pragma once 

#include <iostream>
using namespace std;

#include "Producer.h"
#include "Teacher.h"
#include "Dancer.h"
#include "Club.h"
#include "ClubManager.h"
#include "DanceLine.h"
#include "team.h"
#include "ClubsNetwork.h"

void addTeams(Club* club);
void addDanceLine(Club* club);
void printClub(Club* club);

void main()
{
	ClubsNetwork network;

	int num;	
	cout << "Enter number of clubs " << endl;
	cin >> num;
	for(int i=0; i< num; i++)
	{
		int expirience, income, age, streetnumber, postal;
		char	tmpName[21], tmpCity[21] ,tmpStreet[32];
		//get club manager
		cout << "Enter manager name of club number " +i << endl;
		cin.getline(tmpName, 21);
		cout << "Enter Manager Age  " << endl;
		cin >> age;
		cout << "Enter Manager Expirience  " << endl;
		cin >> expirience;
		cout << "Enter Manager Income  " << endl;
		cin >> income;
		ClubManager manager(Human(tmpName,age), expirience, income);

		cout << "Enter Club's city "  << endl;
		cin.getline(tmpCity, 21);
		cout << "Enter Club's Street " << endl;
		cin.getline(tmpStreet, 21);
		cout << "Enter Club's Street Number  " << endl;
		cin >> streetnumber;
		cout << "Enter Club's Postal Number" << endl;
		cin >> postal;

		Address address(tmpCity,tmpStreet,streetnumber,postal);
		Club* club = new Club(manager,address);
		addTeams(club);
	}
	
	Club* club = ClubsNetwork::biggestClub();
	addDanceLine(club);
	
	printClub(club);
}


void addTeams(Club* club)
{
	int NumOfTeams;
	int numOfDancers;
	char tmpName[21];
	int age, level;
	cout << "Enter Number of teams " << endl;
	cin >> NumOfTeams;

	
	
	for (int i = 0; i<NumOfTeams; i++)
	{
		cout << "Enter Teacher's name " << endl;
		cin.getline(tmpName, 21);
		cout << "Enter Teacher's  age  " << endl;
		cin >> age;
		cout << "Enter Teacher's level" << endl;
		cin >> level;
		Teacher teacher(level, Human(tmpName, age));
		cout << "Enter Number of teams " << endl;
		cin >> numOfDancers;

		int numOfDancer;
		cout << "get num of dancers for the team: " << endl;
		cin >> numOfDancer;

		Team team(teacher, numOfDancers);
		for(int j=0; j<numOfDancers; j++)
		{
			cout << "Enter Dancer's name " << endl;
			cin.getline(tmpName, 21);
			cout << "Enter Dancer's  age  " << endl;
			cin >> age;
			cout << "Enter Dancer's level" << endl;
			cin >> level;
			Dancer* dancer = new Dancer(level, Human(tmpName, age));
			team.addDancer(dancer);
		}
	}
}


void addDanceLine(Club* club)
{
	char tmpName[21];
	int age, level, years, StartHour, StartDay;
	cout << "Enter producer's name " << endl;
	cin.getline(tmpName, 21);
	cout << "Enter producer's  age  " << endl;
	cin >> age;
	cout << "Enter producer's level" << endl;
	cin >> level;
	cout << "Enter producer's years" << endl;
	cin >> years;
	Producer* producer = new Producer(Teacher(level, Human(tmpName, age)), Dancer(level, Human(tmpName, age)), years);
	cout << "Enter danceLine's StartHour" << endl;
	cin >> StartHour;
	cout << "Enter danceLine's Day[ 1- to sunday, 7 to saturday]" << endl;
	cin >> StartDay;

	DanceLine* danceLine = new DanceLine( StartHour, Day(StartDay), *producer);
	club->addDanceLine(*danceLine);
}


void printClub(Club* club)
{
	cout << club;
}