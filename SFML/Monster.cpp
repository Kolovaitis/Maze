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
void Monster::endGo(int x, int y)
{
	for (int i = 0; i < *characterView.objCount; i++)
	{
		if (checkCollision(characterView.positions[i]))
		{
			switch (characterView.positions[i]->TYPE) {

			
			case TYPE_WALL:
				needChange = true;
				switch (x)
				{
				case -1:
					this->position->x = characterView.positions[i]->position->x + characterView.positions[i]->position->width;
					break;
				case 1:
					this->position->x = characterView.positions[i]->position->x - this->position->width;
					break;

				}
				switch (y)
				{
				case -1:
					this->position->y = characterView.positions[i]->position->y + characterView.positions[i]->position->height;
					break;
				case 1:
					this->position->y = characterView.positions[i]->position->y - this->position->height;
					break;

				}
				break;
			case TYPE_PLAYER:
				((Player*)characterView.positions[i])->alive = false;
				break;
			}
		}
	}
}