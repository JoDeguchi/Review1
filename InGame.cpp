#include "InGame.h"
#include "Result.h"
#include "GameManager.h"
#include <random>
#include <algorithm>
#include "PlayerView.h"
#include "EnemyView.h"
#include "BattleView.h"
#include "BattleController.h"

//	両者初期情報
void InGame::Enter()
{
	//----------------------------------------------
	// 敵
	// ---------------------------------------------
	int i = rand() % 3;  // 3体のうちランダムに1体だけ生成して表示する
	enemy_ = EnemyFactory::CreateEnemy(i);

	//	敵の情報を表示
	if (enemy_ != nullptr){
		EnemyView::ShowEnemyData(*enemy_);
	}
	else{
		BattleView::ShowError("敵の生成に失敗しました。");
	}

	//------------------------------------
	//	プレイヤー（永続）
	//------------------------------------
	player_ = PlayerFactory::CreatePlayer(0);

	if (player_ != nullptr)
	{
		//	プレイヤーの文字Viewを呼ぶと指示
		PlayerView::ShowPlayerData(*player_);
		BattleView::ShowBattleStart();
	}
	else
	{
		BattleView::ShowError("プレイヤーの生成に失敗しました。");
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

	BattleController battle(*player_, *enemy_, attackPool_);
	battle.Run();

	BattleView::PromptGoResult();
	std::cin.get();
	manager->ChangeState(std::make_unique<Result>());
}

//	戦闘終了
void InGame::Exit()
{
	std::cout << "戦闘終了" << std::endl;
}
