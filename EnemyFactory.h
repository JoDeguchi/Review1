#pragma once
#include "CharaData.h"

class Enemy;

/// <summary>
/// 敵の生成を行うクラス
/// </summary>
class EnemyFactory
{
private:

	//	敵の種類のデータテーブル
	static const CharaData EnemyTable[];
	//	敵の種類の数
	static const int EnemyTableSize;

public:

	//	敵の生成
	static Enemy* CreateEnemy(int enemyID);

};