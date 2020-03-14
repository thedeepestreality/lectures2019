#include <iostream>
#include <time.h>
#include "enemy.h"
#include "player.h"

void fight(Unit& fighter, Unit& enemy)
{
	std::cout << "=====Fight!=====" << std::endl;
	fighter.status();
	enemy.status();
	while (fighter.alive() && enemy.alive())
	{
		bool coin = rand() % 2;
		if (coin)
			fighter.hit(enemy);
		else
			enemy.hit(fighter);
		fighter.status();
		enemy.status();
	}
}

int main()
{
	srand(time(0));

	Player player("Champion");
	Enemy* enemy;
	int enemyCount = rand() % 6;
	for (int i = 0; i < enemyCount; ++i)
	{
		try
		{
			enemy = new Enemy();
		}
		catch (...) 
		{ 
			break; 
		}
		fight(player, *enemy);
		if (!player.alive())
		{
			std::cout << "Game over" << std::endl;
			delete enemy;
			system("pause");
			return 0;
		}
		else
			std::cout << "Enemy defeated!" << std::endl;
		delete enemy;
	}

	std::cout << "Player " << player.name() 
		<< " wins the game!" << std::endl;

	system("pause");
	return 0;
}