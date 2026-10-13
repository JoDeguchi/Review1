#pragma once
#include "CharaData.h"

/// <summary>
/// プレイヤークラス　プレイヤーの属性と状態をまとめたもの
/// </summary>
class Player
{
public:
	CharaData data;

	Player(const CharaData& playerData)
		: data(playerData)
	{
	}
};
