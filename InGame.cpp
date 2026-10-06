#include "InGame.h"
#include "Result.h"
#include "GameManager.h"

void InGame::Enter()
{
	std::cout << "戦闘スタート" << std::endl;
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
