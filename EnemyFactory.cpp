#include "EnemyFactory.h"
#include "Enemy.h"

const CharaData EnemyFactory::EnemyTable[] = {
	//	ID, 名前, HP, ATK, DEF, 属性
	{ 0, "スライム", 50	, 8	, 5	, ElementType::Water },
	{ 1, "ゴブリン", 100, 15, 10	, ElementType::Earth },
	{ 2, "ドラゴン", 200, 25, 20, ElementType::Fire }
};

const int EnemyFactory::EnemyTableSize = sizeof(EnemyTable) / sizeof(CharaData);

Enemy* EnemyFactory::CreateEnemy(int ID)
{
	for (int i = 0; i < EnemyTableSize; i++)
	{
		if (EnemyTable[i].ID == ID)
		{
			return new Enemy(EnemyTable[i]);
		}
	}
	//	IDが見つからなかった場合はnullptrを返す
	return nullptr;
}

