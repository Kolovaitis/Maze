#pragma once
#define TYPE_PLAYER 0
#define TYPE_NOTHING 2
#define TYPE_WALL 3

typedef struct Position
{
	float x, y;
	int width, height;
} Position;
class GameObject
{
public:
	Position* position;
	GameObject();
	GameObject(float x, float y, int width, int height);
	int TYPE = TYPE_NOTHING;
	bool isEntity = false; 
};

