#pragma once
#include "Unit.h"

class Enemy : public Unit
{
private:
	static int _count;
	static const int MaxStrength = 40;
	static const int MaxHealth = 50;
	static const int MaxCount = 3;
	static const int MinStrength = 10;
	static const int MinHealth = 10;
public:
	Enemy();
	void status() const override;
	void roar() const override;
};