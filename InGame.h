#pragma once
#include "GameState.h"
#include "Enemy.h"
#include "EnemyFactory.h"

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