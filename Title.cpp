#include "Title.h"
#include "InGame.h"
#include "GameManager.h"

void Title::Enter()
{
	std::cout << "RPG" << std::endl;
	std::cout << "Press any key to start..." << std::endl;
}

void Title::Update(GameManager* manager, float deltaTime)
{
	std::cin.get();
	manager->ChangeState(std::make_unique<InGame>());
}

void Title::Exit()
{
	std::cout << "ƒQ[ƒ€‰æ–Ê‚ÉˆÚs" << std::endl;
}