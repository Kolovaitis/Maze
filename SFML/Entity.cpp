#include "Entity.h"
#include <cmath>

Entity::Entity() {
	GameObject::GameObject();
	animationIndex = 0;
	frameIndex = 0;
	timeFromLastFrame = 0;
	this->characterView.range = STANDART_RANGE;
	isEntity = true;
}
Entity::Entity(float x, float y) {
	GameObject::GameObject();
	Entity();
	this->position->x = x;
	this->position->y = y;
	this->position->height = HEIGHT;
	this->position->width = WIDTH;
}
void Entity::renewFrameIndex(clock_t deltaTime) {
	timeFromLastFrame += deltaTime;
	float deltaFrame = timeFromLastFrame * frameSpeed;
	frameIndex = (frameIndex + (int)floor(deltaFrame)) % frameCount;
	if (deltaFrame > 1) {
		timeFromLastFrame -= deltaFrame / frameSpeed;
	}
}
void Entity::stay() {

	animationIndex = ANIMATION_BACKWARD;
	frameIndex = 1;
}
void Entity::goForward(clock_t deltaTime) {	
	animationIndex = ANIMATION_FORWARD;
	this->endGo(0, -1, deltaTime);
}
void Entity::goBackward(clock_t deltaTime) {	
	animationIndex = ANIMATION_BACKWARD;
	this->endGo(0, 1, deltaTime);
}
void Entity::goLeft(clock_t deltaTime) {	
	animationIndex = ANIMATION_LEFT;
	this->endGo(-1, 0, deltaTime);
}
void Entity::goRight(clock_t deltaTime) {	
	animationIndex = ANIMATION_RIGHT;
	this->endGo(1, 0, deltaTime);
}
void Entity::endGo(int x, int y, clock_t delta_time)
{
	this->position->y += y*speed * delta_time;
	this->position->x += x*speed * delta_time;
	renewFrameIndex(delta_time);
	collisionAnalize(x, y);
}
void Entity::collisionAnalize(int x, int y)
{
	for (int i = 0; i < *characterView.objCount; i++)
	{
		if (checkCollision(characterView.positions[i]))
		{
			switch (characterView.positions[i]->TYPE) {
			case TYPE_PLAYER:
				playerBehavior(x, y, characterView.positions[i]);
				break;
			case TYPE_WALL:
				wallBehavior(x, y, characterView.positions[i]);
				break;
			case TYPE_OXYGEN:
				oxygenBehavior(x, y, characterView.positions[i]);				
				break;
			case TYPE_MONSTER:
				monsterBehavior(x, y, characterView.positions[i]);
				break;
			}
		}
	}
}
void Entity::wallBehavior(int x, int y, GameObject* obj)
{
	barrierBehavior(x, y, obj);
}
void Entity::playerBehavior(int x, int y, GameObject* obj)
{
}
void Entity::monsterBehavior(int x, int y, GameObject* obj)
{
}
void Entity::oxygenBehavior(int x, int y, GameObject* obj)
{
}
void Entity::tick(clock_t deltaTime) {

}
void Entity::barrierBehavior(int x, int y, GameObject* obj)
{
	switch (x)
	{
	case -1:
		this->position->x = obj->position->x + obj->position->width;
		break;
	case 1:
		this->position->x = obj->position->x - this->position->width;
		break;

	}
	switch (y)
	{
	case -1:
		this->position->y = obj->position->y + obj->position->height;
		break;
	case 1:
		this->position->y = obj->position->y - this->position->height;
		break;
	}
}






