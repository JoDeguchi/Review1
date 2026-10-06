#include "Result.h"
#include "Title.h"
#include "GameManager.h"


void Result::Enter()
{
	std::cout << "í“¬Œ‹‰Ê" << std::endl;
	std::cout << "Press any key to return to title..." << std::endl;
}

void Result::Update(GameManager* manager, float deltaTime)
{
	std::cin.get();
	manager->ChangeState(std::make_unique<Title>());
}	

void Result::Exit()
{
	std::cout << "ƒŠƒUƒ‹ƒg‰æ–Ê‚ðI—¹" << std::endl;
}