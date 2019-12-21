#include "Player.h"
Player::Player(float x, float y) {
	Entity::Entity();
	this->position->x = x;
	this->position->y = y;
	this->position->height = HEIGHT;
	this->position->width = WIDTH;
	animationIndex = 0;
	frameCount = 3;
	frameSpeed = 0.01;
	speed = 0.1;
	TYPE = TYPE_PLAYER;
	oxygenLevel = 1.0;
	alive = true;
}


void Player::oxygenBehavior(int x, int y, GameObject* obj)
{
	for(int i = 0; i<*this->characterView.objCount; i++)
	{
		if(this->characterView.positions[i] == obj)
		{
			delete obj;
			(*characterView.objCount)--;
			characterView.positions[i] = characterView.positions[*characterView.objCount];
			break;
		}
	}	
	
	
	this->oxygenLevel = 1.0;
}

void Player::monsterBehavior(int x, int y, GameObject* obj)
{
	this->death();
}

void Player::playerBehavior(int x, int y, GameObject* obj)
{
	barrierBehavior(x, y, obj);
}

void Player::tick(clock_t deltaTime)
{
	oxygenLevel -= deltaTime * OXYGEN_SPEED;
	if(oxygenLevel<0)
	{
		this->death();
	}
}
inline void Player::death()
{
	this->alive = false;
}
