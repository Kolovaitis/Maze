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
	void endGo(int x, int y) override;
	bool needChange;
	int route;
};

