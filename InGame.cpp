#include "InGame.h"
#include "Result.h"
#include "GameManager.h"
#include <random>

void InGame::Enter()
{
	// 3体のうちランダムに1体だけ生成して表示する
	int i = rand() % 3;  
	Enemy* enemy = EnemyFactory::CreateEnemy(i);
	//	敵の情報を表示
	if (enemy != nullptr)
	{
		std::cout << enemy->data.NAME << "が現れた！" << std::endl;
		std::cout << enemy->data.NAME << " HP :" << enemy->data.HP << std::endl;
		std::cout << enemy->data.NAME << " ATK:" << enemy->data.ATK << std::endl;
		std::cout << enemy->data.NAME << " DEF:" << enemy->data.DEF << std::endl;
		std::cout << "戦闘スタート" << std::endl;
		delete enemy;
	}
	else
	{
		std::cout << "敵の生成に失敗しました。" << std::endl;
	}
}

void InGame::Update(GameManager* manager, float deltaTime)
{
	std::cout << "戦闘中..." << std::endl;
	std::cin.get();
	manager->ChangeState(std::make_unique<Result>());
}

void InGame::Exit()
{
	std::cout << "戦闘終了" << std::endl;
}
