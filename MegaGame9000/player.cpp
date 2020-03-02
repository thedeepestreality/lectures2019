#include <iostream>
#include "player.h"
#include "enemy.h"

Player::Player(const char* name)
{
	if (_created)
		throw "player already exists!";
	_created = true;
	strcpy_s(_name, name);
}

bool Player::alive() const
{
	return _health > 0;
}

void Player::hit(Enemy& enemy) const
{
	enemy.damage(_strength);
}

void Player::damage(int damage)
{
	_health -= damage;
}

const char* Player::name() const
{
	return _name;
}

void Player::status() const
{
	std::cout << "< Player health: " << _health << std::endl;
}

bool Player::_created = false;