#include "GameObject.h"
#include <cstdlib>

GameObject::GameObject() {
	position = (Position*)malloc(sizeof * position);
	
}
GameObject::GameObject(float x, float y, int width, int height)
{
	position = (Position*)malloc(sizeof * position);
	position->x = x;
	position->y = y;
	position->height = height;
	position->width = width;
}