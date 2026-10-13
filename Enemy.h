#pragma once
#include "CharaData.h"

/// <summary>
/// “GƒNƒ‰ƒX@“G‚Ìó‘Ô‚Æ‘®«‚ğ‚Ü‚Æ‚ß‚½‚à‚Ì
/// “G‚Ì¶¬‚ÍEnemyFactory‚ªs‚¤
/// </summary>
class Enemy
{
public:
	CharaData data;

	Enemy(const CharaData& enemyData)
		: data(enemyData)
	{
	}
};
