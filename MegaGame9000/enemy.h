#pragma once

class Player;

class Enemy
{
private:
	static int _count;
	static const int MaxStrength = 40;
	static const int MaxHealth = 50;
	static const int MaxCount = 3;
	static const int MinStrength = 10;
	static const int MinHealth = 10;
	int _strength;
	int _health;
public:
	Enemy();
	void hit(Player& player) const;
	void damage(int damage);
	bool alive() const;
	void status() const;
};