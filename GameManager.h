#pragma once
#include <memory>
#include "GameState.h"

/// <summary>
/// 管理クラス　ゲームの状態を管理する
/// </summary>
class GameManager
{
	std::unique_ptr<GameState> currentState;
	bool isRunning;
	float gametime;

	//	シングルトンにするためコンストラクタをprivate
	GameManager()
		: isRunning(true), gametime(0.0f), currentState(nullptr)
	{

	}
public:

	// 1個だけGameManagerを取得する（シングルトン）
	static GameManager& GetInstance()
	{
		static GameManager instance;
		return instance;
	}

	// コピー禁止
	GameManager(const GameManager&) = delete;
	GameManager& operator=(const GameManager&) = delete;


	void ChangeState(std::unique_ptr<GameState> newState);

	void Update(float deltaTime);

};

