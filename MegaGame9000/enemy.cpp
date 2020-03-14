#include <iostream>
#include "enemy.h"

Enemy::Enemy() :
	Unit(MinStrength + rand() % MaxStrength, MinHealth + rand() % MaxHealth)
{
	if (++_count > MaxCount)
		throw "too many enemies";
}

void Enemy::status() const
{
	std::cout << "> Enemy health: " << _health << std::endl;
}

void Enemy::roar() const
{
	std::cout << "DIE JEDI" << std::endl;
}

int Enemy::_count = 0;