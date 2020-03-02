#include <iostream>
#include "player.h"
#include "enemy.h"

Enemy::Enemy() :
	_strength(MinStrength + rand() % MaxStrength),
	_health(MinHealth + rand() % MaxHealth)
{
	if (++_count > MaxCount)
		throw "too many enemies";
}

void Enemy::hit(Player& player) const
{
	player.damage(_strength);
}

void Enemy::damage(int damage)
{
	_health -= damage;
}

bool Enemy::alive() const
{
	return _health > 0;
}

void Enemy::status() const
{
	std::cout << "> Enemy health: " << _health << std::endl;
}

int Enemy::_count = 0;