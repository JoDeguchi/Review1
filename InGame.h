#pragma once
#include "GameState.h"

class GameManager;

/// <summary>
/// インゲームステート
/// </summary>
class InGame : public GameState
{
public:
	void Enter() override;

	void Update(GameManager* manager, float deltaTime) override;

	void Exit() override;

	const std::string GetName() const override
	{
		return "InGame";
	}
};