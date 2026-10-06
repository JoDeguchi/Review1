#include "GameManager.h"

void GameManager::ChangeState(std::unique_ptr<GameState> newState)
{
	if (currentState)
	{
		currentState->Exit();
	}
	currentState = std::move(newState);
	if (currentState)
	{
		currentState->Enter();
	}
}

void GameManager::Update(float deltaTime)
{
	gametime += deltaTime;
	if (currentState)
	{
		currentState->Update(this,deltaTime);
	}
}