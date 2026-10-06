#include "Title.h"
#include "GameManager.h"

int main()
{
	GameManager manager;
	manager.ChangeState(std::make_unique<Title>());

	while (1) {
		manager.Update(1.0f);
	}
}