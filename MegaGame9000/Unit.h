#pragma once
#include <iostream>
class Unit
{
protected:
	int _strength;
	int _health;
public:
	Unit(int strength, int health) : _strength(strength),
									 _health(health) {}
	void hit(Unit& player) const { player.damage(_strength); }
	void damage(int damage) { _health -= damage; };
	bool alive() const { return _health > 0; }
	virtual void status() const 
	{ 
		std::cout << "< Unit health: " << _health << std::endl; 
	}

	virtual void roar() const = 0;
};