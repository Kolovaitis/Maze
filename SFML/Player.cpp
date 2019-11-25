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
void Player::endGo(int x, int y)
{
	for(int i = 0; i<*characterView.objCount;i++)
	{
		if(checkCollision(characterView.positions[i]))
		{
			switch (characterView.positions[i]->TYPE) {
				
			case TYPE_PLAYER:
				
			case TYPE_WALL:
				switch (x)
				{
				case -1:
					this->position->x = characterView.positions[i]->position->x+ characterView.positions[i]->position->width;
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
			case TYPE_OXYGEN:
				delete characterView.positions[i];
				(*characterView.objCount)--;
				characterView.positions[i] = characterView.positions[*characterView.objCount];
				this->oxygenLevel = 1.0;
				break;
			case TYPE_MONSTER:
				this->alive = false;
				break;
			}
		}
	}
}
void Player::tick(clock_t deltaTime)
{
	oxygenLevel -= deltaTime * OXYGEN_SPEED;
	if(oxygenLevel<0)
	{
		alive = false;
	}
}
