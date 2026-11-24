#include "Title.h"
#include "GameManager.h"
#include "conio.h"
#include <cstdlib>





















int main()
{
	//	シングルトンパターンを使用してGameManagerのインスタンスを取得
	GameManager::GetInstance().ChangeState(std::make_unique<Title>());

	//	
	while (1) {
		//	シングルトン利用
		GameManager::GetInstance().Update(1.0f);
		
		std::cout << "ゲーム終了" << std::endl;

		system("pause");

		return 0;
		
	}
}