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
	this->position->y -= speed * deltaTime;
	animationIndex = ANIMATION_FORWARD;
	renewFrameIndex(deltaTime);
	this->endGo(0, -1);
}
void Entity::goBackward(clock_t deltaTime) {
	this->position->y += speed * deltaTime;
	animationIndex = ANIMATION_BACKWARD;
	renewFrameIndex(deltaTime);
	this->endGo(0, 1);
}
void Entity::goLeft(clock_t deltaTime) {
	this->position->x -= speed * deltaTime;
	animationIndex = ANIMATION_LEFT;
	renewFrameIndex(deltaTime);
	this->endGo(-1, 0);
}
void Entity::goRight(clock_t deltaTime) {
	this->position->x += speed * deltaTime;
	animationIndex = ANIMATION_RIGHT;
	renewFrameIndex(deltaTime);
	this->endGo(1, 0);
}
void Entity::endGo(int x, int y)
{

}

void Entity::tick(clock_t deltaTime){

}




