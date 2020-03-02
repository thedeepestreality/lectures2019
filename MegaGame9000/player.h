#pragma once

class Enemy;

class Player
{
private:
	static bool _created;
	char _name[32];
	int _health = 100;
	int _strength = 20;
public:
	Player(const char* name);
	~Player() { _created = false; }
	bool alive() const;
	void hit(Enemy& enemy) const;
	void damage(int damage);
	const char* name() const;
	void status() const;
};