#pragma once
#include <ctime>
#include "GameObject.h"
#define ANIMATION_BACKWARD 0;
#define ANIMATION_LEFT 1;
#define ANIMATION_RIGHT 2;
#define ANIMATION_FORWARD 3;
#define STANDART_RANGE 128;
typedef struct CharacterView{
	GameObject** positions;
	float range;
	int* objCount;
} CharacterView;
class Entity: public GameObject
{
	
public:
	
	
	//Map* parent;
	float speed;
	
	CharacterView characterView;
	void goForward(clock_t deltaTime);
	void goBackward(clock_t deltaTime);
	void goLeft(clock_t deltaTime);
	void goRight(clock_t deltaTime);
	void stay();
	void renewFrameIndex(clock_t deltaTime);
	bool checkCollision(GameObject* obj);
	virtual void endGo(int x, int y);
	int animationIndex;
	int frameIndex;
	int frameCount;
	clock_t timeFromLastFrame;
	float frameSpeed;	
	Entity();
	Entity(float x, float y);
	static const int WIDTH =32;
	static const int HEIGHT =32;
	
	



};

