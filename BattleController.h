#pragma once
#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "Damage.h"
#include "ObjectPool.h"
#include "BattleView.h"
#include "PlayerView.h"

class BattleController
{
private:
	Player& player_;
	Enemy& enemy_;
	ObjectPool<Attack>& attackPool_;

	// 1ターン分: 入力待ち → Modelでダメージ処理 → Viewで表示
	void Turn(CharaData& attacker, CharaData& defender, bool isPlayerSide)
	{
		BattleView::PromptTurn(isPlayerSide);
		std::cin.get();

		auto atk = attackPool_.Acquire();   // スコープを抜けると自動返却
		atk->Reset();
		atk->Execute(attacker, defender);
		BattleView::ShowAttack(attacker, defender, atk->damage);
	}

public:
	BattleController(Player& p, Enemy& e, ObjectPool<Attack>& pool)
		: player_(p), enemy_(e), attackPool_(pool) {
	}

	void Run()
	{
		while (true)
		{
			Turn(player_.data, enemy_.data, true);
			if (enemy_.data.HP <= 0)
			{
				BattleView::ShowBattleEnd(player_.data);
				player_.LevelUp();                  // Modelを更新
				PlayerView::ShowLevelUp(player_);   // Viewで表示
				return;
			}

			Turn(enemy_.data, player_.data, false);
			if (player_.data.HP <= 0)
			{
				BattleView::ShowBattleEnd(enemy_.data);
				return;
			}
		}
	}
};