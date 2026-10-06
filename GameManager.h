#pragma once
#include <memory>
#include "GameState.h"

class GameManager
{
	std::unique_ptr<GameState> currentState;
	bool isRunning;
	float gametime;
public:

	GameManager()
		: isRunning(true), gametime(0.0f), currentState(nullptr)
	{

	}

	GameManager(std::unique_ptr<GameState> initstate)
		: isRunning(true), gametime(0.0f), currentState(std::move(initstate))
	{
		if (currentState)
		{
			currentState->Enter();
		}
	}

	void ChangeState(std::unique_ptr<GameState> newState);

	void Update(float deltaTime);

};
