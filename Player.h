#pragma once
#include "CharaData.h"

/// <summary>
/// プレイヤークラス　プレイヤーの属性と状態をまとめたもの
/// </summary>
class Player
{
public:
	CharaData data;
	int level;

	Player(const CharaData& playerData, int initialLevel = 1)
		: data(playerData), level(initialLevel)
	{
	}

	//	プレイヤーはレベルアップするように
	void LevelUp()
	{
		++level;
		//	ステータスあげる
		data.HP = static_cast<int>(data.HP * 1.2f);
		data.ATK = static_cast<int>(data.ATK * 1.1f);
		data.DEF = static_cast<int>(data.DEF * 1.1f);

	}
};
	