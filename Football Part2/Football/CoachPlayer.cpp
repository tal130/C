#pragma warning(disable: 4996)

#include <iostream>
#include <string.h>
#include "CoachPlayer.h"

using namespace std;

CoachPlayer::CoachPlayer(const Player& player, const Coach& coach) : Player(player), Coach(coach), 
			StaffMember(Person(player.getName(),player.getAge()),player.getSallary(),player.getYearsOfExperience()){}
