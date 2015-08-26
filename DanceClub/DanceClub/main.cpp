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

Dancer** getDancers(int num);
void addTeams(Club* club);
void addDanceLine(Club* club);
void printClub(Club* club);

void main()
{
	ClubsNetwork network;
	int num = 2;	//TODO get num of clubs in the netwok
	for(int i=0; i< num; i++)
	{
		//get club manager
		ClubManager manager(Human("tal",40), 15, 10000);
		Address address("Holon","No where",23,4444);
		Club* club = new Club(manager,address);
		addTeams(club);
	}
	
	Club* club = ClubsNetwork::biggestClub();
	addDanceLine(club);
	
	printClub(club);
}



Dancer** getDancers(int num)
{
	Dancer** dancers = new Dancer*[num];
	for(int i=0; i<num; i++)
	{
		//cin << "get number";
		dancers[i] = new Dancer(4, Human("ido",3));	//TODO get num from user
	}
	return dancers;
}


void addTeams(Club* club)
{
	//get number of teams from user
	//TODO
	int num = 2;
	for(int i=0;i<num; i++)
	{
		int level = 5;	//TODO get from user
		Teacher teacher(level);
		int numOfDancers= 10;	//get from user
		Team team(teacher, numOfDancers);
		for(int j=0; j<numOfDancers; j++)
		{
			Dancer* dancer = new Dancer(5 ,  Human("ido", 3));
			team.addDancer(dancer);
		}
	}
}


void addDanceLine(Club* club)
{
	//TODO get from user
	Producer* producer = new Producer( Teacher(5), Dancer(5, Human("ido", 3)) , 32);	
	DanceLine* danceLine= new DanceLine(22, 1, *producer);
	club->addDanceLine(*danceLine);
}


void printClub(Club* club)
{
	cout << club;
}