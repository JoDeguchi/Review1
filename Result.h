#pragma once
#include "GameState.h"

class GameManager;

class Result : public GameState
{
public:
	void Enter() override;

	void Update(GameManager* manager, float deltaTime) override;

	void Exit() override;

	const std::string GetName() const override
	{
		return "Result";
	}
};