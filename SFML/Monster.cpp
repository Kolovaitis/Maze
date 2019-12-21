#include "Monster.h"


Monster::Monster(float x, float y)
{
	Entity();
	this->position->x = x;
	this->position->y = y;
	this->position->height = HEIGHT;
	this->position->width = WIDTH;
	animationIndex = 0;
	frameCount = 3;
	frameSpeed = 0.01;
	speed = 0.05;
	TYPE = TYPE_MONSTER;
	needChange = true;
	
}
void Monster::tick(clock_t deltaTime)
{
	if(needChange)
	{
		route = rand() % 4;
		needChange = false;
	}
	switch(route)
	{
		case 0:goForward(deltaTime);
		break;
		case 1:goBackward(deltaTime);
			break;
		case 2:goLeft(deltaTime);
			break;
		case 3:goRight(deltaTime);
			break;
	}
	
}


void Monster::wallBehavior(int x, int y, GameObject* obj)
{
	needChange = true;
	barrierBehavior(x, y, obj);
}

void Monster::playerBehavior(int x, int y, GameObject* obj)
{
	((Player*)obj)->death();
}

void Monster::monsterBehavior(int x, int y, GameObject* obj)
{
	needChange = true;
	barrierBehavior(x, y, obj);
}
