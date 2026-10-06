#include "EnemyFactory.h"
#include "Enemy.h"

const EnemyData EnemyFactory::EnemyTable[] = {
	//	ID, 名前, HP, ATK, DEF, 属性
	{ 0, "スライム", 10	, 2	, 1	, ElementType::Water },
	{ 1, "ゴブリン", 20	, 5	, 3	, ElementType::Earth },
	{ 2, "ドラゴン", 100, 20, 10, ElementType::Fire }
};

const int EnemyFactory::EnemyTableSize = sizeof(EnemyTable) / sizeof(EnemyData);

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

