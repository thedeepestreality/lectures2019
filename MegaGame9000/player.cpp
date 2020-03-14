#include <iostream>
#include "player.h"

Player::Player(const char* name) : Unit(20, 50)
{
	if (_created)
		throw "player already exists!";
	_created = true;
	strcpy_s(_name, name);
}

const char* Player::name() const
{
	return _name;
}

void Player::status() const
{
	std::cout << "< Player health: " << _health << std::endl;
}

void Player::roar() const
{
	std::cout << "FOR MOTHER RUSSIA!" << std::endl;
}

bool Player::_created = false;