#pragma once
#include <iostream>
#include "Player.h"

class PlayerView
{
private:
public:

	static void ShowPlayerData(const Player& p)
	{
		std::cout << p.data.NAME << "“oêI" << std::endl;
		std::cout << p.data.NAME << " HP :" << p.data.HP << std::endl;
		std::cout << p.data.NAME << " ATK:" << p.data.ATK << std::endl;
		std::cout << p.data.NAME << " DEF:" << p.data.DEF << std::endl;
		std::cout << "Level: " << p.level << std::endl;
	}

	static void ShowLevelUp(const Player& p)
	{
		std::cout << p.data.NAME << " ‚ÍƒŒƒxƒ‹" << p.level << "‚Éã‚ª‚Á‚½I" << std::endl;
		std::cout << "HP:" << p.data.HP << " ATK:" << p.data.ATK << " DEF:" << p.data.DEF << std::endl;
	}

};