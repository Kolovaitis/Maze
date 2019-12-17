#pragma once
#define TYPE_PLAYER 0
#define TYPE_NOTHING -1
#define TYPE_WALL 2
#define TYPE_OXYGEN 3
#define TYPE_MONSTER 4
#include <cstdlib>
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
	GameObject(Position* p);
	bool checkCollision(GameObject* obj);
	bool checkCollision(Position* pos);
	int TYPE = TYPE_NOTHING;
	bool isEntity = false;

	
};

