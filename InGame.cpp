#include "InGame.h"
#include "Result.h"
#include "GameManager.h"
#include <random>
#include <algorithm>

//	両者初期情報
void InGame::Enter()
{
	//----------------------------------------------
	// 敵
	// ---------------------------------------------
	int i = rand() % 3;  // 3体のうちランダムに1体だけ生成して表示する
	enemy_ = EnemyFactory::CreateEnemy(i);
	//	敵の情報を表示
	if (enemy_ != nullptr)
	{
		std::cout << enemy_->data.NAME << "が現れた！" << std::endl;
		std::cout << enemy_->data.NAME << " HP :" << enemy_->data.HP << std::endl;
		std::cout << enemy_->data.NAME << " ATK:" << enemy_->data.ATK << std::endl;
		std::cout << enemy_->data.NAME << " DEF:" << enemy_->data.DEF << std::endl;
	}
	else
	{
		std::cout << "敵の生成に失敗しました。" << std::endl;
	}

	//------------------------------------
	//	プレイヤー（永続）
	//------------------------------------
	player_ = PlayerFactory::CreatePlayer(0);

	if (player_ != nullptr)
	{
		std::cout << player_->data.NAME << "登場！" << std::endl;
		std::cout << player_->data.NAME << " HP :" << player_->data.HP << std::endl;
		std::cout << player_->data.NAME << " ATK:" << player_->data.ATK << std::endl;
		std::cout << player_->data.NAME << " DEF:" << player_->data.DEF << std::endl;
		std::cout << "Level: " << player_->level << std::endl;
		std::cout << "\n戦闘スタート" << std::endl;
	}
	else
	{
		std::cout << "プレイヤーの生成に失敗しました。" << std::endl;
	}
}

//	戦闘
void InGame::Update(GameManager* manager, float deltaTime)
{
	if (player_ == nullptr || enemy_ == nullptr)
	{
		// どちらか生成に失敗しているなら結果へ
		manager->ChangeState(std::make_unique<Result>());
		return;
	}

	while (player_->data.HP > 0 && enemy_->data.HP > 0)
	{
		// プレイヤーのターン
		std::cout << "\nプレイヤーの攻撃！ (Enterで進行)" << std::endl;
		std::cin.get();
		{
			int damage = std::max(1, player_->data.ATK - enemy_->data.DEF);
			enemy_->data.HP -= damage;
			if (enemy_->data.HP < 0) enemy_->data.HP = 0;
			std::cout << player_->data.NAME << " は " << enemy_->data.NAME << " に " << damage << " のダメージを与えた！" << std::endl;
			std::cout << enemy_->data.NAME << " の残りHP: " << enemy_->data.HP << std::endl;
		}

		if (enemy_->data.HP <= 0) break;

		// 敵のターン
		std::cout << "\n敵の攻撃！ (Enterで進行)" << std::endl;
		std::cin.get();
		{
			int damage = std::max(1, enemy_->data.ATK - player_->data.DEF);
			player_->data.HP -= damage;
			if (player_->data.HP < 0) player_->data.HP = 0;
			std::cout << enemy_->data.NAME << " は " << player_->data.NAME << " に " << damage << " のダメージを与えた！" << std::endl;
			std::cout << player_->data.NAME << " の残りHP: " << player_->data.HP << std::endl;
		}
	}

	// 勝敗表示
	std::cout << "\n--- 戦闘終了 ---" << std::endl;
	if (player_->data.HP <= 0 && enemy_->data.HP <= 0)
	{
		std::cout << "引き分けだ！" << std::endl;
	}
	else if (player_->data.HP <= 0)
	{
		std::cout << enemy_->data.NAME << " の勝利！" << std::endl;
	}
	else
	{
		std::cout << player_->data.NAME << " の勝利！" << std::endl;
		// プレイヤー勝利時にレベルアップ
		player_->LevelUp();
	}

	std::cout << "結果表示へ（Enter）" << std::endl;
	std::cin.get();
	manager->ChangeState(std::make_unique<Result>());
}

//	戦闘終了
void InGame::Exit()
{
	std::cout << "戦闘終了" << std::endl;
}
