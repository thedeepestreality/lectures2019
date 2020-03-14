#pragma once
#include "Unit.h"

class Player : public Unit
{
private:
	static bool _created;
	char _name[32];
public:
	Player(const char* name);
	~Player() { _created = false; }
	const char* name() const;
	void status() const override;
	void roar() const override;
};