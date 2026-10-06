#pragma once
#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include <random>
#include <cstdlib>
#include <ctime>
#include <conio.h>

class GameManager;

/// <summary>
/// ステートそれぞれの状態を表す抽象クラス
/// </summary>
class GameState
{
public:
	virtual ~GameState() = default;
	virtual void Enter() = 0;
	virtual void Update(GameManager* manager, float deltaTime) = 0;
	virtual void Exit() = 0;
	virtual  const std::string GetName()const = 0;
};