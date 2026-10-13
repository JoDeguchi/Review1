#pragma once
#include "CharaData.h"

class Player;

/// <summary>
/// プレイヤーの生成
/// </summary>
class PlayerFactory
{
private:

	//	プレイヤー種類のデータテーブル
	static const CharaData PlayerTable[];
	//	プレイヤーの種類の数
	static const int PlayerTableSize;

public:

	//	プレイヤーの生成
	static Player* CreatePlayer(int enemyID);

};