#include "Title.h"
#include "GameManager.h"

int main()
{
	/*GameManager manager;
	manager.ChangeState(std::make_unique<Title>());*/

	//	シングルトンパターンを使用してGameManagerのインスタンスを取得
	GameManager::GetInstance().ChangeState(std::make_unique<Title>());


	while (1) {
		//manager.Update(1.0f);
		//	シングルトン利用
		GameManager::GetInstance().Update(1.0f);
	}
}