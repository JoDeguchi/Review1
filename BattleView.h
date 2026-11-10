#pragma once
#include <iostream>
#include "CharaData.h"

class BattleView
{
public:

	static void ShowBattleStart()
	{
		std::cout << "\n戦闘スタート" << std::endl;
	}

	static void PromptTurn(bool isPlayerSide)
	{
		std::cout << (isPlayerSide ? "\nプレイヤーの攻撃！" : "\n敵の攻撃！")
			<< " (Enterで進行)" << std::endl;
	}

	static void ShowAttack(const CharaData& attacker, const CharaData& defender, int damage)
	{
		std::cout << attacker.NAME << " は " << defender.NAME << " に "
			<< damage << " のダメージを与えた！" << std::endl;
		std::cout << defender.NAME << " の残りHP: " << defender.HP << std::endl;
	}

	static void ShowBattleEnd(const CharaData& winner)
	{
		std::cout << "\n--- 戦闘終了 ---" << std::endl;
		std::cout << winner.NAME << " の勝利！" << std::endl;
	}

	static void PromptGoResult()
	{
		std::cout << "結果表示へ（Enter）" << std::endl;
	}

	static void ShowError(const char* msg)
	{
		std::cout << msg << std::endl;
	}
};