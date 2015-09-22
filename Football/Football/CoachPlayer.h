#ifndef _COACHPLAYER_H
#define _COACHPLAYER_H

#include "Coach.h"
#include "Player.h"

using namespace std;

class CoachPlayer:public Coach, public Player
{
public:
	CoachPlayer(const Player& player, const Coach& coach);

	friend ostream& operator<<(ostream& os, const CoachPlayer& coachPlayer)
	{
		os << "CoachPlayer name:" << coachPlayer.getName() << endl;
		return os;
	}

};

#endif //_COACHPLAYER_H