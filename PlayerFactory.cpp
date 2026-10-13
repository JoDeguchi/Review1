#include "PlayerFactory.h"
#include "Player.h"

const CharaData PlayerFactory::PlayerTable[] = {
	//	ID, –¼‘O, HP, ATK, DEF, ‘®«
	{ 0, "—EÒ", 200, 30, 20, ElementType::Fire },
};

const int PlayerFactory::PlayerTableSize = sizeof(PlayerTable) / sizeof(CharaData);

Player* PlayerFactory::CreatePlayer(int ID)
{
	for (int i = 0; i < PlayerTableSize; i++)
	{
		if (PlayerTable[i].ID == ID)
		{
			return new Player(PlayerTable[i]);
		}
	}
	//	ID‚ªŒ©‚Â‚©‚ç‚È‚©‚Á‚½ê‡‚Ínullptr‚ğ•Ô‚·
	return nullptr;
}

