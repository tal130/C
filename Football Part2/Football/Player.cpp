#pragma warning(disable: 4996)

#include <iostream>
#include <string.h>
#include "Player.h"

using namespace std;

Player::Player(const StaffMember& staffMember, Position position, int number) : StaffMember(staffMember)
{
	this->position = position;
	this->number = number;
}

//getters
Player::Position Player::getPosition() const
{
	return this->position;
}
int Player::getNumber() const
{
	return this->number;
}

//setters
void Player::setPosition(Position position)
{
	this->position = position;
}
void Player::setNumber(int number)
{
	this->number = number;
}