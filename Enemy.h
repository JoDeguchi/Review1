#pragma once
#include "EnemyData.h"

/// <summary>
/// “GƒNƒ‰ƒX@“G‚Ìó‘Ô‚Æ‘®«‚ğ‚Ü‚Æ‚ß‚½‚à‚Ì
/// “G‚Ì¶¬‚ÍEnemyFactory‚ªs‚¤
/// </summary>
class Enemy
{
public:
	EnemyData data;

	Enemy(const EnemyData& enemyData)
		: data(enemyData)
	{
	}
};
