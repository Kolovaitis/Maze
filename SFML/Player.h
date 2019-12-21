#pragma once
#include "Entity.h"
#include <ctime>
#define OXYGEN_SPEED 0.00007
//#define WIDTH 32
//#define HEIGHT 32
class Player :public Entity
{
	
public:	
	
	Player(float x, float y);
	static const int WIDTH = 32;
	static const int HEIGHT = 32;
	int index;
	void oxygenBehavior(int x, int y, GameObject* obj) override;
	void monsterBehavior(int x, int y, GameObject* obj) override;
	void playerBehavior(int x, int y, GameObject* obj)override;
	double oxygenLevel;
	void tick(clock_t deltaTime)override;
	void death();
	bool alive;
	};



