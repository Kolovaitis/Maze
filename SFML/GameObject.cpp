#include "GameObject.h"


GameObject::GameObject() {
	position = new Position;
	
}
GameObject::GameObject(float x, float y, int width, int height)
{
	this->GameObject::GameObject();
	position->x = x;
	position->y = y;
	position->height = height;
	position->width = width;
}
GameObject::GameObject(Position* p)
{
	position = p;
}
bool GameObject::checkCollision(GameObject* obj) {
	if (this == obj)
	{
		return false;
	}
	float deltaX = this->position->x - obj->position->x;
	float deltaY = this->position->y - obj->position->y;
	if ((deltaX < 0 && (-deltaX) < this->position->width) || (deltaX >= 0 && (deltaX) < obj->position->width))
	{
		if ((deltaY < 0 && (-deltaY) < this->position->height) || (deltaY >= 0 && (deltaY) < obj->position->height))
		{
			return true;
		}
	}
	return false;
}
bool GameObject::checkCollision(Position* pos) {
	
	float deltaX = this->position->x -pos->x;
	float deltaY = this->position->y - pos->y;
	if ((deltaX < 0 && (-deltaX) < this->position->width) || (deltaX >= 0 && (deltaX) < pos->width))
	{
		if ((deltaY < 0 && (-deltaY) < this->position->height) || (deltaY >= 0 && (deltaY) < pos->height))
		{
			return true;
		}
	}
	return false;
}
