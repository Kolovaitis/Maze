#pragma once
#include "Entity.h"
#include "Player.h"
class Monster :
	public Entity
{
public:
	Monster(float x, float y);
	static const int WIDTH = 32;
	static const int HEIGHT = 32;
	void tick(clock_t deltaTime)override;

	void wallBehavior(int x, int y, GameObject* obj) override;
	void playerBehavior(int x, int y, GameObject* obj) override;
	void monsterBehavior(int x, int y, GameObject* obj) override;
	bool needChange;
	int route;
};

