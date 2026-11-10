#pragma once
#include <iostream>
#include "Enemy.h"

class EnemyView
{
public:
	static void ShowEnemyData(const Enemy& e)
	{
		std::cout << e.data.NAME << "‚ªŒ»‚ê‚½I" << std::endl;
		std::cout << e.data.NAME << " HP :" << e.data.HP << std::endl;
		std::cout << e.data.NAME << " ATK:" << e.data.ATK << std::endl;
		std::cout << e.data.NAME << " DEF:" << e.data.DEF << std::endl;
	}
};