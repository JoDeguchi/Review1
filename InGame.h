#pragma once
#include "GameState.h"
#include "Enemy.h"
#include "EnemyFactory.h"
#include "Player.h"
#include "PlayerFactory.h"
#include "Damage.h"
#include "ObjectPool.h"

class GameManager;

/// <summary>
/// インゲームステート
/// </summary>
class InGame : public GameState
{
private:
	Enemy* enemy_;
	Player* player_;
	//	オブジェクトプール（ターンずつなので容量１）
	ObjectPool<Attack> attackPool_{ 1 };

public:
	InGame()
		: enemy_(nullptr), player_(nullptr)
	{
	}

	~InGame() override
	{
		delete enemy_;
		delete player_;
	}

	void Enter() override;

	void Update(GameManager* manager, float deltaTime) override;

	void Exit() override;

	const std::string GetName() const override
	{
		return "InGame";
	}


};